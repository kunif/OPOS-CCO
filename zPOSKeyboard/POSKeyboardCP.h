/****************************************************************************
**
** POSKeyboardCP.h -- POSKeyboard connection point proxy, to actually fire the events.
**
**    This file was modified from an ATL generated connection point implementation.
**
**     Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  1999/03/20 Initial version.                                     C. Monroe
**  2005/12/14 Add Debug tracing of event delivery.
**  2008/01/15 Add more parameter and error checking.
**  2013/09/29 Update license section.
**  2019/01/20 Update year annotation of license.
**  2019/01/20 Version 1.15.000.
**             Changed include guard from #ifndef __XXXX_H__ to #pragma once.
**
*****************************************************************************
**
{{Begin License}}

Copyright 2019 Monroe Consulting Services, Inc.

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

#pragma once

#ifdef _DEBUG
    class COPOSPOSKeyboard;
    #define FEUNKNOWN (IUnknown*) sp,
#else
    #define FEUNKNOWN
#endif

template <class T>
class CProxy_IOPOSEvents : public IConnectionPointImpl<T, &DIID__IOPOSPOSKeyboardEvents, CComDynamicUnkArray>
{
public:

//===========================================================================

    VOID Fire_DataEvent(LONG Status)
    {
        T* pT = static_cast<T*>(this);
        OposVariant var;
        int nConnections = m_vec.GetSize();

        for (_nCOConnectionIndex = 0; _nCOConnectionIndex < nConnections; _nCOConnectionIndex++)
        {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(_nCOConnectionIndex);
            pT->Unlock();
            _pCPDispatch = reinterpret_cast<IDispatch*>(sp.p);
            if (_pCPDispatch != NULL)
            {
                var.SetLONG( Status );
                FireTheEvent( FEUNKNOWN &var, 1, _DIDData, L"DataEvent", 1 );
            }
        }
    }

//===========================================================================

    VOID Fire_DirectIOEvent(LONG EventNumber, LONG* pData, BSTR* pString)
    {
        T* pT = static_cast<T*>(this);
        OposVariant vars[3];
        int nConnections = m_vec.GetSize();

        for (_nCOConnectionIndex = 0; _nCOConnectionIndex < nConnections; _nCOConnectionIndex++)
        {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(_nCOConnectionIndex);
            pT->Unlock();
            _pCPDispatch = reinterpret_cast<IDispatch*>(sp.p);
            if (_pCPDispatch != NULL)
            {
                HRESULT hr;
                vars[2].SetLONG( EventNumber );
                vars[1].SetLONG_Ptr( pData, hr );
                vars[0].SetBSTR_InOutPtr( pString, hr );
                FireTheEvent( FEUNKNOWN vars, 3, _DIDDirectIO, L"DirectIOEvent", 2 );
            }
        }
    }

//===========================================================================

    VOID Fire_ErrorEvent(LONG ResultCode, LONG ResultCodeExtended, LONG ErrorLocus, LONG* pErrorResponse)
    {
        T* pT = static_cast<T*>(this);
        OposVariant vars[4];
        int nConnections = m_vec.GetSize();

        for (_nCOConnectionIndex = 0; _nCOConnectionIndex < nConnections; _nCOConnectionIndex++)
        {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(_nCOConnectionIndex);
            pT->Unlock();
            _pCPDispatch = reinterpret_cast<IDispatch*>(sp.p);
            if (_pCPDispatch != NULL)
            {
                HRESULT hr;
                vars[3].SetLONG( ResultCode );
                vars[2].SetLONG( ResultCodeExtended );
                vars[1].SetLONG( ErrorLocus );
                vars[0].SetLONG_Ptr( pErrorResponse, hr );
                FireTheEvent( FEUNKNOWN vars, 4, _DIDError, L"ErrorEvent", 3 );
            }
        }
    }

//===========================================================================

    VOID Fire_StatusUpdateEvent(LONG Data)
    {
        T* pT = static_cast<T*>(this);
        OposVariant var;
        int nConnections = m_vec.GetSize();

        for (_nCOConnectionIndex = 0; _nCOConnectionIndex < nConnections; _nCOConnectionIndex++)
        {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(_nCOConnectionIndex);
            pT->Unlock();
            _pCPDispatch = reinterpret_cast<IDispatch*>(sp.p);
            if (_pCPDispatch != NULL)
            {
                var.SetLONG( Data );
                FireTheEvent( FEUNKNOWN &var, 1, _DIDStatus, L"StatusUpdateEvent", 5 );
            }
        }
    }

//===========================================================================
// Constructor: Initialize cached dispatch IDs.
    CProxy_IOPOSEvents( IFDEBUG( COPOSPOSKeyboard* pOposControl ) )
    {
        _DIDData = -1;
        _DIDDirectIO = -1;
        _DIDError = -1;
        _DIDStatus = -1;
        IFDEBUG( _pOposControl = pOposControl );
    }

#ifdef _DEBUG
    STDMETHOD(Advise)(IUnknown* pUnkSink, DWORD* pdwCookie)
    {
        HRESULT hr = IConnectionPointImpl<T, &DIID__IOPOSPOSKeyboardEvents, CComDynamicUnkArray>::Advise( pUnkSink, pdwCookie );
        _pOposControl->DOTRACEV( ( _T("*Advise: Sink 0x%X; Cookie 0x%X"), pUnkSink, *pdwCookie ) );
        return hr;
    }

    STDMETHOD(Unadvise)(DWORD dwCookie)
    {
        _pOposControl->DOTRACEV( ( _T("*Unadvise: Cookie 0x%X"), dwCookie ) );
        return IConnectionPointImpl<T, &DIID__IOPOSPOSKeyboardEvents, CComDynamicUnkArray>::Unadvise(dwCookie);
    }
#endif

protected:
// Cached dispatch IDs for the first connection point.
    DISPID _DIDData;
    DISPID _DIDDirectIO;
    DISPID _DIDError;
    DISPID _DIDStatus;

// Fire an event.
#ifdef _DEBUG
    void FireTheEvent( IUnknown* pUnkSink, OposVariant* rgvarg, unsigned int cArgs, DISPID& FirstDispID, const OLECHAR* pName, DISPID MyDispID )
#else
    void FireTheEvent( OposVariant* rgvarg, unsigned int cArgs, DISPID& FirstDispID, const OLECHAR* pName, DISPID MyDispID )
#endif
    {
        IFDEBUG( const OLECHAR* pNameOrig = pName );

        // Declare and initialize the dispatch parameters and dispatch ID.
        OposDispParms DispParms( rgvarg, cArgs );
        DISPID DispID = FirstDispID;
        // If not first connection (not likely for our controls!) or first dispatch ID not yet looked up...
        if ( _nCOConnectionIndex != 0 || FirstDispID < 0 )
        {
            // Get the dispatch ID of the event we want to call.
            //   If not implemented, then assume that client used typelib to use our default DispIDs.
            //   If other failure, the can't fire.
            HRESULT hRC = _pCPDispatch->GetIDsOfNames( IID_NULL, const_cast<OLECHAR**>(&pName), 1, LOCALE_USER_DEFAULT, &DispID );
            if ( hRC == E_NOTIMPL )
                DispID = MyDispID;
            else if ( hRC != S_OK )
                return;
            // If first connection, then save in cache for next time.
            if ( _nCOConnectionIndex == 0 )
                FirstDispID = DispID;
        }
        // Call the event.
        IFDEBUG( _pOposControl->DOTRACEV( ( _T("*FireTheEvent: Delivering %ls; Sink 0x%X; DispID %d"), pNameOrig, pUnkSink, DispID ) ) );
        _pCPDispatch->Invoke( DispID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &DispParms, NULL, NULL, NULL );
    }

// Internal data.
//   Since we are apartment threaded, only one event will be fired at a time,
//   so that this data can be class level.
    int _nCOConnectionIndex;
    IDispatch* _pCPDispatch;
    IFDEBUG( COPOSPOSKeyboard* _pOposControl );
};

