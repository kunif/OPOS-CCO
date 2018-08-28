/****************************************************************************
**
** LineDisplayImpl.h -- Main control header file.
**
**     Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  1999/03/20 Initial version.                                     C. Monroe
**  2004/03/22 Add significantly more tracing when Debug.
**  2005/12/14 Add Debug tracing of event delivery.
**  2008/01/15 Enhance handling of interfaces/vtables.
**               Add more parameter and error checking.
**  2008/08/30 More interface updates.
**  2013/09/29 Update license section.
**  2015/02/07 Update license section.
**  2015/02/07 Version 1.14.001.
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

#ifndef __LINEDISPLAYIMPL_H__
#define __LINEDISPLAYIMPL_H__


/////////////////////////////////////////////////////////////////////////////
// Debug build tracing macros.
/////////////////////////////////////////////////////////////////////////////

//~~~~ When Debug, will perform some tracing ~~~~
#ifdef _DEBUG
// Default is to use writes using RCS Trace components.
//   Source code does not include the files to recompile to use them.
//#define _FILETRACE // Uncomment to use C runtime writes to a file.
    #define DEBUGPARAM(x) x,
    #define IFDEBUG(x) x
    #define DOTRACE(x) WriteTrace x
    #define DOTRACESTRINGV(x,y) WriteTraceString(x,y)
    #define DOTRACEERR(x,y) WriteTraceError(x,y)
    #define DOTRACEMETHODS(x,y) WriteTraceMethods(x,y)

    #ifdef _FILETRACE
        #pragma message("===>>> Debug Build: Slow tracing to C:\\OposCCO_LineDisplay.log")
        #define DOTRACEV(x) WriteTrace x
        #define DODUMPV(x,y)            // Dump of non-ASCII data not implemented.
        #define TRACEINIT
        #define TRACEEXIT
    #else
        #pragma message("===>>> Debug Build: Fast tracing to OposCCO_LineDisplay.log")
        #define DOTRACEV(x) WriteTraceV x
        #define DODUMPV(x,y) WriteDumpV(x,y)
        #define TRACEINIT TraceInit()
        #define TRACEEXIT TraceExit()
    #endif

//~~~~ When Release mode, all trace calls between no-ops ~~~~
#else
    #define DEBUGPARAM(x)
    #define IFDEBUG(x)
    #define DOTRACE(x)
    #define DOTRACEV(x)
    #define DOTRACESTRINGV(x,y)
    #define DOTRACEERR(x,y)
    #define DOTRACEMETHODS(x,y)
    #define TRACEINIT
    #define TRACEEXIT
#endif


/////////////////////////////////////////////////////////////////////////////
// Includes.
/////////////////////////////////////////////////////////////////////////////

// Include various definitions.
#include "LineDisplayDefs.h"

// Standard includes...
#include "Resource.h"

// Include our variant class.
#include "OposVariant.h"

// Include our connection point implementation.
#include "LineDisplayCP.h"


/////////////////////////////////////////////////////////////////////////////
// Data.
/////////////////////////////////////////////////////////////////////////////

#define SO_DISP_COUNT 29
// Hidden window class and window name.
extern TCHAR g_WindowName[];
// Control Object description.
extern char  g_ControlDescription[];


/////////////////////////////////////////////////////////////////////////////
// Control class declaration.
/////////////////////////////////////////////////////////////////////////////

// The class...
class ATL_NO_VTABLE COPOSLineDisplay :
    // Inherit from all these classes...
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IOPOSLineDisplay, &IID_IOPOSLineDisplay, &LIBID_OposLineDisplay_CCO>,
    public CComControl<COPOSLineDisplay>,
    public IPersistStreamInitImpl<COPOSLineDisplay>,
    public IOleControlImpl<COPOSLineDisplay>,
    public IOleObjectImpl<COPOSLineDisplay>,
    public IOleInPlaceActiveObjectImpl<COPOSLineDisplay>,
    public IViewObjectExImpl<COPOSLineDisplay>,
    public IOleInPlaceObjectWindowlessImpl<COPOSLineDisplay>,
    public IConnectionPointContainerImpl<COPOSLineDisplay>,
    public IPersistStorageImpl<COPOSLineDisplay>,
    public ISpecifyPropertyPagesImpl<COPOSLineDisplay>,
    public IQuickActivateImpl<COPOSLineDisplay>,
    public IDataObjectImpl<COPOSLineDisplay>,
    public IProvideClassInfo2Impl<&CLSID_OPOSLineDisplay, &DIID__IOPOSLineDisplayEvents, &LIBID_OposLineDisplay_CCO>,
    public IObjectSafetyImpl<COPOSLineDisplay, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    public IPropertyNotifySinkCP<COPOSLineDisplay>,
    public CComCoClass<COPOSLineDisplay, &CLSID_OPOSLineDisplay>,
    public CProxy_IOPOSEvents< COPOSLineDisplay >
{
public:
// Constructor / FinalConstruct / Destructor.
    COPOSLineDisplay();
    HRESULT FinalConstruct();
    ~COPOSLineDisplay();

//===========================================================================
// Data.
//===========================================================================

protected:
    // Are we open?  And what is the status text of our last open?
    bool _bOpened;
    long _nOpenResult;

    // Service Object's version numbers. Set during Open.
    long _nSOMajor;                     // Service Object major version.
    long _nSOMinor;                     // Service Object minor version.

    // Special-case Control Object maintained result code. Use for:
    //  - Open result code.
    //  - Tried to access SO method or property not supported by its version.
    long _nCOResultCode;                // CO-maintained result code.
    long SetRC( long nRC = -1 )
        { return _nCOResultCode = nRC; }

    // Dispatch pointer to the Service Object. Valid while open.
    IDispatch* _pService;

    // Event freeze control.
    int _nCOFreezeEventCount;   // Depth of container freeze requests. Zero = not frozen.
    bool _bFreezeState;         // State of OPOS FreezeEvents property.

    // Maximum method index.
    long _nMaxMethod;

    // Service Object Dispatch IDs.
    DISPID _DispIDs[SO_DISP_COUNT];

    // Count of active instances.
    static int s_nInstances;

//===========================================================================
// Data and functions for tracing when Debug.
//===========================================================================

#ifdef _DEBUG
public:
    void* _pTrace;
    LONG _nBinaryConversion;
    void TraceInit();
    void TraceExit();
    void WriteTrace( LPCTSTR pFormat, ... );
    void WriteTraceV( LPCTSTR pFormat, ... );
    void WriteDumpV( void* pData, int nLen );
    void WriteTraceString( LPCTSTR pszPrefix, BSTR bstr );
    void WriteTraceString( void* pString, int nLen, BOOL bAscii, int nCharSize,
        LPCTSTR pszFormat, ... );
    void WriteTraceError( LPCTSTR pFormat, DWORD dwError );
    void WriteTraceMethods( DISPID* pDispID, int nMethods );
#endif

//===========================================================================
// Functions (Internal use).
//===========================================================================

protected:
    // Get or set properties.
    HRESULT GetOposProp( DEBUGPARAM(LPCSTR pPropName) long nIndex, long*         pnValue, long nMinor = 0 );
    HRESULT SetOposProp( DEBUGPARAM(LPCSTR pPropName) long nIndex, long          nValue,  long nMinor = 0 );
    HRESULT GetOposProp( DEBUGPARAM(LPCSTR pPropName) long nIndex, VARIANT_BOOL* pnValue, long nMinor = 0 );
    HRESULT SetOposProp( DEBUGPARAM(LPCSTR pPropName) long nIndex, VARIANT_BOOL  nValue,  long nMinor = 0 );
    HRESULT GetOposProp( DEBUGPARAM(LPCSTR pPropName) long nIndex, BSTR*         psValue, long nMinor = 0 );
    HRESULT SetOposProp( DEBUGPARAM(LPCSTR pPropName) long nIndex, BSTR          sValue,  long nMinor = 0 );

    // Call SO's Invoke method.
    HRESULT DoInvoke( DEBUGPARAM(LPCSTR pFuncName) HRESULT hRC, OposVariant* pParms, unsigned nParms, int nDispIDIndex,
        long* pRC, bool bOpenCheck = true );

    // Set the SO's event freeze state. Based on control container's freeze requests.
    void SetCOFreezeEvents( VARIANT_BOOL bFreeze );

    // Override the IOleControlImpl handler for container request to freeze/unfreeze events.
    STDMETHOD(FreezeEvents)(BOOL bFreeze);

    // Declare the draw handler.
    HRESULT OnDraw(ATL_DRAWINFO& di);

//===========================================================================
// Various ATL-generated macros.
//===========================================================================

public:
    // Registry resource.
DECLARE_REGISTRY_RESOURCEID(IDR_OPOSLINEDISPLAY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

    // Define supported interfaces.
BEGIN_COM_MAP(COPOSLineDisplay)
    //  Map COM dispatch to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IOPOSLineDisplay)
    //   Map each COM interface to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IOPOSLineDisplay, IOPOSLineDisplay)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSLineDisplay_1_9, IOPOSLineDisplay)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSLineDisplay_1_8, IOPOSLineDisplay)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSLineDisplay_1_7, IOPOSLineDisplay)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSLineDisplay_1_6, IOPOSLineDisplay)

    COM_INTERFACE_ENTRY(IViewObjectEx)
    COM_INTERFACE_ENTRY(IViewObject2)
    COM_INTERFACE_ENTRY(IViewObject)
    COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
    COM_INTERFACE_ENTRY(IOleInPlaceObject)
    COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
    COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
    COM_INTERFACE_ENTRY(IOleControl)
    COM_INTERFACE_ENTRY(IOleObject)
    COM_INTERFACE_ENTRY(IPersistStreamInit)
    COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
    COM_INTERFACE_ENTRY(IConnectionPointContainer)
    COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
    COM_INTERFACE_ENTRY(IQuickActivate)
    COM_INTERFACE_ENTRY(IPersistStorage)
    COM_INTERFACE_ENTRY(IDataObject)
    COM_INTERFACE_ENTRY(IProvideClassInfo)
    COM_INTERFACE_ENTRY(IProvideClassInfo2)
    COM_INTERFACE_ENTRY(IObjectSafety)
    COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

    // Define property map.
BEGIN_PROP_MAP(COPOSLineDisplay)
    PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
    PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

    // Define connection points.
BEGIN_CONNECTION_POINT_MAP(COPOSLineDisplay)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    CONNECTION_POINT_ENTRY(DIID__IOPOSLineDisplayEvents)
END_CONNECTION_POINT_MAP()

    // Define message map.
BEGIN_MSG_MAP(COPOSLineDisplay)
    CHAIN_MSG_MAP(CComControl<COPOSLineDisplay>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

    // Define view status for IViewObjectEx to pass to container.
    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//===========================================================================
// Bring in all of the OPOS event firing code.
//===========================================================================

protected:
    #include "LineDisplayEvent.h"

//===========================================================================
// Control methods and property declarations.
//===========================================================================

public:
    STDMETHOD(SOProcessID)( /*[out, retval]*/ long* pProcessID );

// Release 1.0
    STDMETHOD(get_OpenResult)( /*[out, retval]*/ LONG* pOpenResult );
    STDMETHOD(get_CheckHealthText)( /*[out, retval]*/ BSTR* pCheckHealthText );
    STDMETHOD(get_Claimed)( /*[out, retval]*/ VARIANT_BOOL* pClaimed );
    STDMETHOD(get_DeviceEnabled)( /*[out, retval]*/ VARIANT_BOOL* pDeviceEnabled );
    STDMETHOD(put_DeviceEnabled)( /*[in]*/ VARIANT_BOOL DeviceEnabled );
    STDMETHOD(get_FreezeEvents)( /*[out, retval]*/ VARIANT_BOOL* pFreezeEvents );
    STDMETHOD(put_FreezeEvents)( /*[in]*/ VARIANT_BOOL FreezeEvents );
    STDMETHOD(get_ResultCode)( /*[out, retval]*/ LONG* pResultCode );
    STDMETHOD(get_ResultCodeExtended)( /*[out, retval]*/ LONG* pResultCodeExtended );
    STDMETHOD(get_State)( /*[out, retval]*/ LONG* pState );
    STDMETHOD(get_ControlObjectDescription)( /*[out, retval]*/ BSTR* pControlObjectDescription );
    STDMETHOD(get_ControlObjectVersion)( /*[out, retval]*/ LONG* pControlObjectVersion );
    STDMETHOD(get_ServiceObjectDescription)( /*[out, retval]*/ BSTR* pServiceObjectDescription );
    STDMETHOD(get_ServiceObjectVersion)( /*[out, retval]*/ LONG* pServiceObjectVersion );
    STDMETHOD(get_DeviceDescription)( /*[out, retval]*/ BSTR* pDeviceDescription );
    STDMETHOD(get_DeviceName)( /*[out, retval]*/ BSTR* pDeviceName );
    STDMETHOD(CheckHealth)( 
        /*[in]*/ LONG Level, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ClaimDevice)( 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(Close)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(DirectIO)( 
        /*[in]*/ LONG Command, 
        /*[in, out]*/ LONG* pData, 
        /*[in, out]*/ BSTR* pString, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(Open)( 
        /*[in]*/ BSTR DeviceName, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ReleaseDevice)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(get_CapBlink)( /*[out, retval]*/ LONG* pCapBlink );
    STDMETHOD(get_CapBrightness)( /*[out, retval]*/ VARIANT_BOOL* pCapBrightness );
    STDMETHOD(get_CapCharacterSet)( /*[out, retval]*/ LONG* pCapCharacterSet );
    STDMETHOD(get_CapDescriptors)( /*[out, retval]*/ VARIANT_BOOL* pCapDescriptors );
    STDMETHOD(get_CapHMarquee)( /*[out, retval]*/ VARIANT_BOOL* pCapHMarquee );
    STDMETHOD(get_CapICharWait)( /*[out, retval]*/ VARIANT_BOOL* pCapICharWait );
    STDMETHOD(get_CapVMarquee)( /*[out, retval]*/ VARIANT_BOOL* pCapVMarquee );
    STDMETHOD(get_CharacterSet)( /*[out, retval]*/ LONG* pCharacterSet );
    STDMETHOD(put_CharacterSet)( /*[in]*/ LONG CharacterSet );
    STDMETHOD(get_CharacterSetList)( /*[out, retval]*/ BSTR* pCharacterSetList );
    STDMETHOD(get_Columns)( /*[out, retval]*/ LONG* pColumns );
    STDMETHOD(get_CurrentWindow)( /*[out, retval]*/ LONG* pCurrentWindow );
    STDMETHOD(put_CurrentWindow)( /*[in]*/ LONG CurrentWindow );
    STDMETHOD(get_CursorColumn)( /*[out, retval]*/ LONG* pCursorColumn );
    STDMETHOD(put_CursorColumn)( /*[in]*/ LONG CursorColumn );
    STDMETHOD(get_CursorRow)( /*[out, retval]*/ LONG* pCursorRow );
    STDMETHOD(put_CursorRow)( /*[in]*/ LONG CursorRow );
    STDMETHOD(get_CursorUpdate)( /*[out, retval]*/ VARIANT_BOOL* pCursorUpdate );
    STDMETHOD(put_CursorUpdate)( /*[in]*/ VARIANT_BOOL CursorUpdate );
    STDMETHOD(get_DeviceBrightness)( /*[out, retval]*/ LONG* pDeviceBrightness );
    STDMETHOD(put_DeviceBrightness)( /*[in]*/ LONG DeviceBrightness );
    STDMETHOD(get_DeviceColumns)( /*[out, retval]*/ LONG* pDeviceColumns );
    STDMETHOD(get_DeviceDescriptors)( /*[out, retval]*/ LONG* pDeviceDescriptors );
    STDMETHOD(get_DeviceRows)( /*[out, retval]*/ LONG* pDeviceRows );
    STDMETHOD(get_DeviceWindows)( /*[out, retval]*/ LONG* pDeviceWindows );
    STDMETHOD(get_InterCharacterWait)( /*[out, retval]*/ LONG* pInterCharacterWait );
    STDMETHOD(put_InterCharacterWait)( /*[in]*/ LONG InterCharacterWait );
    STDMETHOD(get_MarqueeFormat)( /*[out, retval]*/ LONG* pMarqueeFormat );
    STDMETHOD(put_MarqueeFormat)( /*[in]*/ LONG MarqueeFormat );
    STDMETHOD(get_MarqueeRepeatWait)( /*[out, retval]*/ LONG* pMarqueeRepeatWait );
    STDMETHOD(put_MarqueeRepeatWait)( /*[in]*/ LONG MarqueeRepeatWait );
    STDMETHOD(get_MarqueeType)( /*[out, retval]*/ LONG* pMarqueeType );
    STDMETHOD(put_MarqueeType)( /*[in]*/ LONG MarqueeType );
    STDMETHOD(get_MarqueeUnitWait)( /*[out, retval]*/ LONG* pMarqueeUnitWait );
    STDMETHOD(put_MarqueeUnitWait)( /*[in]*/ LONG MarqueeUnitWait );
    STDMETHOD(get_Rows)( /*[out, retval]*/ LONG* pRows );
    STDMETHOD(ClearDescriptors)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ClearText)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(CreateWindow)( 
        /*[in]*/ LONG ViewportRow, 
        /*[in]*/ LONG ViewportColumn, 
        /*[in]*/ LONG ViewportHeight, 
        /*[in]*/ LONG ViewportWidth, 
        /*[in]*/ LONG WindowHeight, 
        /*[in]*/ LONG WindowWidth, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(DestroyWindow)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(DisplayText)( 
        /*[in]*/ BSTR Data, 
        /*[in]*/ LONG Attribute, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(DisplayTextAt)( 
        /*[in]*/ LONG Row, 
        /*[in]*/ LONG Column, 
        /*[in]*/ BSTR Data, 
        /*[in]*/ LONG Attribute, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(RefreshWindow)( 
        /*[in]*/ LONG Window, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ScrollText)( 
        /*[in]*/ LONG Direction, 
        /*[in]*/ LONG Units, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetDescriptor)( 
        /*[in]*/ LONG Descriptor, 
        /*[in]*/ LONG Attribute, 
        /*[out, retval]*/ long* pRC );
// Release 1.1
// Release 1.2
    STDMETHOD(get_BinaryConversion)( /*[out, retval]*/ LONG* pBinaryConversion );
    STDMETHOD(put_BinaryConversion)( /*[in]*/ LONG BinaryConversion );
// Release 1.3
    STDMETHOD(get_CapPowerReporting)( /*[out, retval]*/ LONG* pCapPowerReporting );
    STDMETHOD(get_PowerNotify)( /*[out, retval]*/ LONG* pPowerNotify );
    STDMETHOD(put_PowerNotify)( /*[in]*/ LONG PowerNotify );
    STDMETHOD(get_PowerState)( /*[out, retval]*/ LONG* pPowerState );
// Release 1.4
// Release 1.5
// Release 1.6
    STDMETHOD(get_BlinkRate)( /*[out, retval]*/ LONG* pBlinkRate );
    STDMETHOD(put_BlinkRate)( /*[in]*/ LONG BlinkRate );
    STDMETHOD(get_CapBlinkRate)( /*[out, retval]*/ VARIANT_BOOL* pCapBlinkRate );
    STDMETHOD(get_CapCursorType)( /*[out, retval]*/ LONG* pCapCursorType );
    STDMETHOD(get_CapCustomGlyph)( /*[out, retval]*/ VARIANT_BOOL* pCapCustomGlyph );
    STDMETHOD(get_CapReadBack)( /*[out, retval]*/ LONG* pCapReadBack );
    STDMETHOD(get_CapReverse)( /*[out, retval]*/ LONG* pCapReverse );
    STDMETHOD(get_CursorType)( /*[out, retval]*/ LONG* pCursorType );
    STDMETHOD(put_CursorType)( /*[in]*/ LONG CursorType );
    STDMETHOD(get_CustomGlyphList)( /*[out, retval]*/ BSTR* pCustomGlyphList );
    STDMETHOD(get_GlyphHeight)( /*[out, retval]*/ LONG* pGlyphHeight );
    STDMETHOD(get_GlyphWidth)( /*[out, retval]*/ LONG* pGlyphWidth );
    STDMETHOD(DefineGlyph)( 
        /*[in]*/ LONG GlyphCode, 
        /*[in]*/ BSTR Glyph, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ReadCharacterAtCursor)( 
        /*[out]*/ LONG* pChar, 
        /*[out, retval]*/ long* pRC );
// Release 1.7
    STDMETHOD(get_CapBitmap)( /*[out, retval]*/ VARIANT_BOOL* pCapBitmap );
    STDMETHOD(get_CapMapCharacterSet)( /*[out, retval]*/ VARIANT_BOOL* pCapMapCharacterSet );
    STDMETHOD(get_CapScreenMode)( /*[out, retval]*/ VARIANT_BOOL* pCapScreenMode );
    STDMETHOD(get_MapCharacterSet)( /*[out, retval]*/ VARIANT_BOOL* pMapCharacterSet );
    STDMETHOD(put_MapCharacterSet)( /*[in]*/ VARIANT_BOOL MapCharacterSet );
    STDMETHOD(get_MaximumX)( /*[out, retval]*/ LONG* pMaximumX );
    STDMETHOD(get_MaximumY)( /*[out, retval]*/ LONG* pMaximumY );
    STDMETHOD(get_ScreenMode)( /*[out, retval]*/ LONG* pScreenMode );
    STDMETHOD(put_ScreenMode)( /*[in]*/ LONG ScreenMode );
    STDMETHOD(get_ScreenModeList)( /*[out, retval]*/ BSTR* pScreenModeList );
    STDMETHOD(DisplayBitmap)( 
        /*[in]*/ BSTR FileName, 
        /*[in]*/ LONG Width, 
        /*[in]*/ LONG AlignmentX, 
        /*[in]*/ LONG AlignmentY, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetBitmap)( 
        /*[in]*/ LONG BitmapNumber, 
        /*[in]*/ BSTR FileName, 
        /*[in]*/ LONG Width, 
        /*[in]*/ LONG AlignmentX, 
        /*[in]*/ LONG AlignmentY, 
        /*[out, retval]*/ long* pRC );
// Release 1.8
    STDMETHOD(get_CapStatisticsReporting)( /*[out, retval]*/ VARIANT_BOOL* pCapStatisticsReporting );
    STDMETHOD(get_CapUpdateStatistics)( /*[out, retval]*/ VARIANT_BOOL* pCapUpdateStatistics );
    STDMETHOD(ResetStatistics)( 
        /*[in]*/ BSTR StatisticsBuffer, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(RetrieveStatistics)( 
        /*[in, out]*/ BSTR* pStatisticsBuffer, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UpdateStatistics)( 
        /*[in]*/ BSTR StatisticsBuffer, 
        /*[out, retval]*/ long* pRC );
// Release 1.9
    STDMETHOD(get_CapCompareFirmwareVersion)( /*[out, retval]*/ VARIANT_BOOL* pCapCompareFirmwareVersion );
    STDMETHOD(get_CapUpdateFirmware)( /*[out, retval]*/ VARIANT_BOOL* pCapUpdateFirmware );
    STDMETHOD(CompareFirmwareVersion)( 
        /*[in]*/ BSTR FirmwareFileName, 
        /*[out]*/ LONG* pResult, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UpdateFirmware)( 
        /*[in]*/ BSTR FirmwareFileName, 
        /*[out, retval]*/ long* pRC );
// Release 1.10
// Release 1.11
// Release 1.12
// Release 1.13
// Release 1.14
};

#endif //__LINEDISPLAYIMPL_H__

// End LineDisplayImpl.h
