/****************************************************************************
**
** CashDrawerEvent.h -- OPOS event firing support.
**
**    This file is included into the CashDrawer Control Object's main
**      implementation class.
**
**     Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  1999/03/20 Initial version.                                     C. Monroe
**  2004/03/22 Add significantly more tracing when Debug.
**  2004/10/26 Enhance Debug tracing of DirectIOEvent.
**  2008/01/15 Add more parameter and error checking.
**  2013/09/29 Update license section.
**  2015/02/07 Update license section.
**  2015/02/07 Version 1.14.001.
**  2020/06/01 Version 1.15.000.                                    K. Fukuchi
**             Changed include guard from #ifndef __XXXX_H__ to #pragma once.
**             Change long parameters and return values used in
**             both 32bit/64bit to appropriate types
**  2021/12/02 Version 1.16.000.
**
*****************************************************************************
**
{{Begin License}}

Copyright 2015 Monroe Consulting Services, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

{{End License}}
*/

/////////////////////////////////////////////////////////////////////////////
// Abstract:
//
// >> Application assumption:
//      The same app thread that creates the Control Object will be used for
//      releasing and closing the CO. This module will then ensure that event
//      firing is properly shut down during Release and Close processing.
//
// >> Service Object assumptions:
//  (1) The SO should only fire one event at a time.
//      However, it is permissible for up to one event per type to be in progress
//      simultaneously, such as StatusUpdate and Error.
//      (A mutex protects the necessary areas.)
//  (2) The SO's event handling thread will be terminated during Release, Close,
//      or SO destructor processing.
//      (Specifically, the thread must not be destroyed while setting
//      DeviceEnabled to FALSE.  Deadlock protection is only provided for Release
//      and Close.)
//  (3) No events will be fired after PreCloseRelease is called.
//      For exclusive use devices, this is called from both Release and Close.
//      For shared devices, this is called this only from Close.
//      (If an event method SO... is in progress when PreCloseRelease is called,
//      then the event firing is aborted.)
//
// >> General approach:
//  When the Service Object calls one of the event firing methods (SOData,
//  SOError, etc.), the Control Object must fire the event as soon as possible.
//  The CO must ensure that events are fired on the same thread that created it,
//  in order to adhere to apartment threading rules. Also, the CO must delay
//  firing the event if events have become frozen despite the SO's best efforts.
/////////////////////////////////////////////////////////////////////////////


#pragma once
/////////////////////////////////////////////////////////////////////////////
// Data used by event firing functions.
/////////////////////////////////////////////////////////////////////////////

    // ThreadID of thread that created this control.
    DWORD   _Event_ControlThreadID;
    // Have events been opened?
    bool    _Event_bOpen;
    // The following must be true after Open/Claim, and false after Release/Close.
    bool    _Event_bEventsLegal;
    // The following is true during the firing of the event.
    bool    _Event_bEventInProgress;
    // The following is true after an event is delivered.
    bool    _Event_bEventDelivered;
    // Used to synchronize event firing.
    HANDLE  _Event_FiringDoneEvent;
    // Used to serialize access to the DoEvent() function.
    HANDLE  _Event_DoEventMutex;
    // Event firing hidden window.
    HWND    _Event_hEventWnd;
    // Temporary holding place for DirectIO param that won't fit in msg params.
    BSTR*   _Event_DIO_pString;


/////////////////////////////////////////////////////////////////////////////
// Functions.
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Function name    : EventInit
// Description      : Initialize for event firing. Called from constructor.
// Return type      : void
/////////////////////////////////////////////////////////////////////////////

    HRESULT EventInit()
    {
        _Event_bOpen = false;

        // This function must be called by the thread that creates the OCX.
        // Then these functions will ensure that events from the SO are fired
        //   on the thread that creates the OCX.
        _Event_ControlThreadID = ::GetCurrentThreadId();

        // Perform some initialization in case of a failure below,
        //   so that EventUninit will not fail.
        _Event_hEventWnd = 0;
        _Event_FiringDoneEvent = 0;
        _Event_DoEventMutex = 0;

        // If first instance of this CO being created, then
        //   register a class for our hidden window.
        if ( s_nInstances == 0 )
        {
            WNDCLASS WndClass =
            {
                0,                              // style
                s_EventWindowProc,              // lpfnWndProc
                0,                              // cbClsExtra
                sizeof( void* ),                // cbWndExtra
                _Module.GetModuleInstance(),    // hInstance
                NULL,                           // hIcon
                NULL,                           // hCursor
                NULL,                           // hbrBackground
                NULL,                           // lpszMenuName
                g_WindowName                    // lpszClassName
            };
            if ( 0 == ::RegisterClass( &WndClass ) )
            {
                DOTRACEERR( _T("  EventInit: Failed RegisterClass %lu\n    %s"), ::GetLastError() );
                return E_UNEXPECTED;
            }
        }

        // Create the hidden window for event handling.
        _Event_hEventWnd = CreateWindowEx(
            0,                              // extended window style
            g_WindowName,                   // pointer to registered class name
            g_WindowName,                   // pointer to window name
            0,                              // window style
            0,                              // horizontal position of window
            0,                              // vertical position of window
            0,                              // window width
            0,                              // window height
            NULL,                           // handle to parent or owner window
            0,                              // handle to menu, or child-window identifier
            _Module.GetModuleInstance(),    // handle to application instance
            this );                         // pointer to window-creation data
        if ( 0 == _Event_hEventWnd )
        {
            DOTRACEERR( _T("  EventInit: Failed CreateWindowEx %lu\n    %s"), ::GetLastError() );
            return E_UNEXPECTED;
        }

        // Create synchronization objects.
        if ( 0 == ( _Event_FiringDoneEvent = CreateEvent(
                        0,                  // pointer to security attributes
                        TRUE,               // flag for manual-reset event
                        FALSE,              // flag for initial state
                        0 ) ) ||            // pointer to event-object name
             0 == ( _Event_DoEventMutex = CreateMutex(
                        0,                  // pointer to security attributes
                        FALSE,              // flag for initial ownership
                        0 ) ) )             // pointer to mutex-object name
        {
            DOTRACEERR( _T("  EventInit: Failed CreateEvent/Mutex %lu\n    %s"), ::GetLastError() );
            return E_UNEXPECTED;
        }

        return S_OK;
    }

/////////////////////////////////////////////////////////////////////////////
// Function name    : EventOpen
// Description      : Called from the control object's Open method.
// Return type      : void
/////////////////////////////////////////////////////////////////////////////

    void EventOpen()
    {
        // Initialize so that events are allowed.
        _Event_bEventsLegal = true;
        _Event_bEventInProgress = false;
        _bFreezeState = false;
        _Event_bOpen = true;
    }

/////////////////////////////////////////////////////////////////////////////
// Function name    : EventPreClose
// Description      : Called from the control object's Close method.
// Return type      : void
/////////////////////////////////////////////////////////////////////////////

    void EventPreClose()
    {
        DOTRACEV( ( _T("*EventPreCloseRelease") ) );

        // The following two items must be in this order to avoid race
        //   condition for breaking out of "DoEvent":
        //  - Events are no longer legal.
        _Event_bEventsLegal = false;
        //  - In case an OPOS event is being fired, set Win32 event to cause
        //    "DoEvent" to break out of its wait.
        ::SetEvent( _Event_FiringDoneEvent );

        // If an event is in progress when this is called, flag an app bug.
        //   (This can only occur if the Close is called from a thread
        //    other than the main app thread, or if it is called from the
        //    event handler.)
        CMASSERT( ! _Event_bEventInProgress );
    }

/////////////////////////////////////////////////////////////////////////////
// Function name    : EventClose
// Description      : Called from the control object's Close method.
// Return type      : void
/////////////////////////////////////////////////////////////////////////////

    void EventClose()
    {
        DOTRACEV( ( _T("*EventClose") ) );

        _Event_bOpen = false;
        // Just in case any undelivered event messages are queued for our window, toss them.
        MSG msg;
        while ( 0 != ::PeekMessage(
                  &msg,                     // pointer to structure for message
                  _Event_hEventWnd,         // handle to window
                  WM_USER, 0x7FFF,          // message filtering: retrieve user messages
                  PM_REMOVE )               // removal flags
              )
            ;
    }

/////////////////////////////////////////////////////////////////////////////
// Function name    : EventUninit
// Description      : Uninitialize event firing. Called from destructor.
// Return type      : void
/////////////////////////////////////////////////////////////////////////////

    void EventUninit()
    {
        if ( _Event_hEventWnd != 0 )
            CMVERIFY( ::DestroyWindow( _Event_hEventWnd ) != 0 );

        // If last instance of this CO being destroyed, then
        //   unregister the hidden window class.
        if ( s_nInstances == 0 )
            CMVERIFY( ::UnregisterClass( g_WindowName, _Module.GetModuleInstance() ) != 0 );

        if ( _Event_FiringDoneEvent != 0 )
            CMVERIFY( ::CloseHandle( _Event_FiringDoneEvent ) != 0 );
        if ( _Event_DoEventMutex != 0 )
            CMVERIFY( ::CloseHandle( _Event_DoEventMutex ) != 0 );
    }

/////////////////////////////////////////////////////////////////////////////
// Description      : The following functions are called directly by the
//                      Service Object to cause an event to be fired.
//         For each method, do the following:
//          - If the method is called on the Control apartment's thread,
//              fire the event directly.
//          - Else we must do extra work to fire on that thread:
//             - Save event parameters if they won't fit in wParam and lParam.
//             - Call the "DoEvent" function, with appropriate hidden window
//                  user message and parameters.
// Return type      : Standard COM result code
/////////////////////////////////////////////////////////////////////////////

    STDMETHOD( SODataDummy )(long Status)
    {
        return E_NOTIMPL;
    }

//===========================================================================

    STDMETHOD( SODirectIO )(long EventNumber, long* pData, BSTR* pString)
    {
    #ifdef _DEBUG
        DOTRACEV( ( _T("+DirectIOEvent: Event %d (0x%X), Data %d (0x%X)"), \
            EventNumber, EventNumber, *pData, *pData ) );
        DOTRACESTRINGV( _T("    String."), *pString );
        HRESULT hr;
        OposVariant DIOStr;
        DIOStr.SetBSTR_Copy( *pString, hr );
    #endif

        if ( _Event_ControlThreadID == GetCurrentThreadId() )
            CProxy_IOPOSEvents< COPOSCashDrawer >::Fire_DirectIOEvent( EventNumber, pData, pString );
        else
        {
            _Event_DIO_pString = pString;
            DoEvent( WMU_DIRECT_IO_EVENT, EventNumber, (LPARAM) pData );
        }

    #ifdef _DEBUG
        UINT nStrLen = ::SysStringByteLen( DIOStr.bstrVal );
        if ( nStrLen == ::SysStringByteLen( *pString ) &&
             0 == ::memcmp( DIOStr.bstrVal, *pString, nStrLen ) )
            DOTRACEV( ( _T("-DirectIOEvent: Data %d (0x%X); String Unchanged"), *pData, *pData ) );
        else
        {
            DOTRACEV( ( _T("-DirectIOEvent: Data %d (0x%X)"), *pData, *pData ) );
            DOTRACESTRINGV( _T("    String."), *pString );
        }
    #endif
        return S_OK;
    }

//===========================================================================

    STDMETHOD( SOErrorDummy )(long ResultCode, long ResultCodeExtended,
                long ErrorLocus, long* pErrorResponse)
    {
        return E_NOTIMPL;
    }

//===========================================================================

    STDMETHOD( SOOutputCompleteDummy )(long OutputID)
    {
        return E_NOTIMPL;
    }

//===========================================================================

    STDMETHOD( SOStatusUpdate)(long Data)
    {
        DOTRACEV( ( _T("+StatusUpdateEvent: Data %d"), Data ) );

        if ( _Event_ControlThreadID == GetCurrentThreadId() )
            CProxy_IOPOSEvents< COPOSCashDrawer >::Fire_StatusUpdateEvent( Data );
        else
            DoEvent( WMU_STATUS_UPDATE_EVENT, Data, 0 );

        DOTRACEV( ( _T("-StatusUpdateEvent") ) );
        return S_OK;
    }


/////////////////////////////////////////////////////////////////////////////
// Function name    : DoEvent
// Description      : Called from one of the SO... event firing methods when
//                      not on the thread that created this control.
//
//         The logic in this function plus the event firing functions removes
//         these potential deadlocks:
//
//         (1) During Release or Close, if the following conditions occur...
//             (a) The SO Close or Release logic is written in typical fashion:
//                   It flags its event firing thread and waits for it to shut
//                   down.
//             (b) The SO is firing an event from its event thread, while...
//             (c) The app's main thread is busy (that is, not waiting in its
//                   message pump when the SO calls the "SO..." function, and
//                   call's the Close or Release function.
//             If the CO uses a SendMessage to get to the main thread for firing
//             the event to the app, then deadlock occurs:  The SendMessage can't
//             complete until the Close or Release is done and returns back to the
//             app's message loop, but Close or Release can't finish until the SO
//             has shut down the event thread.
//
//         (2) Due to freezing of events, if the following conditions occur...
//             (a) The SO's event firing thread ensures that events are not frozen
//                   before calling an SO... method, then calls the method.
//             (b) The app thread is busy when the SO calls SO..., so the event
//                   can't be delivered immediately.
//             (c) The app thread freezes events before processing the event
//             message that will fire the event. A freeze can occur via the
//             FreezeEvents property or the container's freeze method.
//             >> Solution: A rudimentary loop is used until events are unfrozen.
//
// Return type      : void
// Argument         : UINT Msg      - User message to specify event to fire.
// Argument         : long wParam   - Event parameter.
// Argument         : long lParam   - Event parameter (optional).
/////////////////////////////////////////////////////////////////////////////

    void DoEvent( UINT Msg, WPARAM wParam, LPARAM lParam )
    {
        // Restrict access of the following code to one thread at a time.
        ::WaitForSingleObject( _Event_DoEventMutex, INFINITE );
        DOTRACEV( ( _T("+DoEvent: Msg 0x%X"), Msg ) );

        // Clear the delivered flag.
        _Event_bEventDelivered = false;

        // Loop until delivered or events become illegal.
        //   Can only execute more than once if events are frozen.
        for (;;)
        {
            // The following two items must be in this order to avoid race
            //   condition with "PreCloseRelease":
            //  - Reset the event that the event function will use to tell us it is done.
            ::ResetEvent( _Event_FiringDoneEvent );
            // If events are not legal (release/close has been done),
            //   then break out.
            if ( ! _Event_bEventsLegal )
                break;

            // Post an event message to the event window.
            DOTRACEV( ( _T("*DoEvent: Posting event firing message") ) );
            ::PostMessage( _Event_hEventWnd, Msg, wParam, lParam );

            // Wait for the event handler to finish (or for the exception case of
            //   Release or Close called).
            ::WaitForSingleObject( _Event_FiringDoneEvent, INFINITE );

            // If the message was delivered, then break out: done!
            //
            // If events are now illegal, then Close or Release occurred during the
            // event firing, so bail out -- the delivery may or may not have occurred.
            // Either the Close or Release function was called by the event handler
            // (in which case we generated an exception), or Close or Release was
            // called before our event function message handler got control.
            //
            if ( _Event_bEventDelivered || ! _Event_bEventsLegal )
                break;

            // If events legal but not delivered, then either the container or app
            //   has frozen them.  Could have used events to trigger when to retry,
            //   but since this should be an uncommon situation, we'll just sleep
            //   for a short while, then retry.
            Sleep( 100 );                   // Wait 1/10 second.
        }

        // Allow other threads.
        DOTRACEV( ( _T("-DoEvent: Msg 0x%X"), Msg ) );
        ::ReleaseMutex( _Event_DoEventMutex );
    }

/////////////////////////////////////////////////////////////////////////////
// Function name    : s_EventWindowProc
// Description      : Hidden event firing window procedure.
//         The function will always run in the context of the thread that
//         created the Control Object, since its window was created during
//         the CO's constructor call.
//         Messages are posted to the window by DoEvent when an event is to
//         be fired.
// Return type      : LRESULT
// Argument         : HWND hwnd     - handle to window
// Argument         : UINT uMsg     - message id
// Argument         : WPARAM wParam - first param
// Argument         : LPARAM lParam - second param
/////////////////////////////////////////////////////////////////////////////

    static LRESULT CALLBACK s_EventWindowProc(
        HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
    {
        COPOSCashDrawer* pThis;

        // On window creation, save our window instance into user window space.
        if ( uMsg == WM_CREATE )
        {
            pThis = (COPOSCashDrawer*) ((LPCREATESTRUCT) lParam)->lpCreateParams;
            ::SetWindowLongPtr( hwnd, 0, (LONG_PTR) pThis );
        }

        // If other message, give our class a chance to handle.
        else
        {
            pThis = (COPOSCashDrawer*) ::GetWindowLongPtr( hwnd, 0 );
            if ( pThis != 0 &&
                 pThis->EventWindowProc( uMsg, wParam, lParam ) )
                    return 0;
        }

        // Unless handled by our class method, pass on to default processing.
        return ::DefWindowProc( hwnd, uMsg, wParam, lParam );
    }

/////////////////////////////////////////////////////////////////////////////
// Function name    : EventWindowProc
// Description      : Handle event firing request messages.
//         For each of the request messages, do the following:
//          - Call the event setup function.
//          - If successful:
//             - Fire the event to the app.
//             - Call the event cleanup function.
// Return type      : LRESULT CALLBACK
// Argument         :  UINT uMsg
// Argument         : WPARAM wParam
// Argument         : LPARAM lParam
/////////////////////////////////////////////////////////////////////////////

    LRESULT CALLBACK EventWindowProc(
        UINT uMsg, WPARAM wParam, LPARAM lParam )
    {
        bool bProcessed = true;

        switch ( uMsg )
        {
        case WMU_DIRECT_IO_EVENT:
            {
                if ( FireEventSetup() )
                {
                    DOTRACEV( ( _T("*EventWindowProc: Firing DirectIOEvent") ) );
                    CProxy_IOPOSEvents< COPOSCashDrawer >::Fire_DirectIOEvent(
                        (long) wParam, (long*) lParam, _Event_DIO_pString );
                    FireEventCleanup();
                }
                break;
            }

        case WMU_STATUS_UPDATE_EVENT:
            {
                if ( FireEventSetup() )
                {
                    DOTRACEV( ( _T("*EventWindowProc: Firing StatusUpdateEvent") ) );
                    CProxy_IOPOSEvents< COPOSCashDrawer >::Fire_StatusUpdateEvent(
                        (long) wParam );
                    FireEventCleanup();
                }
                break;
            }

        default:
            {
                bProcessed = false;
                break;
            }
        }

        return bProcessed;
    }

/////////////////////////////////////////////////////////////////////////////
// Function name    : FireEventSetup
// Description      : Prepare for event firing. Called from window message handler.
// Return type      : bool - true if ready to fire; false if not.
/////////////////////////////////////////////////////////////////////////////

    bool FireEventSetup()
    {
        // If events are not legal (open/claim not done for exclusive, or open
        //   not done for shared device), then return without firing.
        if ( ! _Event_bEventsLegal ||
        // If events are frozen, then return without firing.
             _bFreezeState || _nCOFreezeEventCount != 0 )
        {
            ::SetEvent( _Event_FiringDoneEvent );
            return false;
        }

        // If events are legal and not frozen,
        //   set event in progress flag, and return true.
        _Event_bEventInProgress = true;
        return true;
    }

/////////////////////////////////////////////////////////////////////////////
// Function name    : FireEventCleanup
// Description      : Finish up after event firing. Called from window message handler.
// Return type      : void
/////////////////////////////////////////////////////////////////////////////

    void FireEventCleanup()
    {
        // Clear event in progress flag, set delivered flag, and set completion event.
        _Event_bEventInProgress = false;
        _Event_bEventDelivered = true;
        ::SetEvent( _Event_FiringDoneEvent );
    }


// end CashDrawerEvent.h
