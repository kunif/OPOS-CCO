/****************************************************************************
**
** GraphicDisplayImpl.h -- Main control header file.
**
**     Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  2022/02/02 Initial Version from similar sources.                K. Fukuchi
**             Changed include guard from #ifndef __XXXX_H__ to #pragma once.
**
*****************************************************************************
**
{{Begin License}}

Copyright 2021 Kunio Fukuchi

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
        #pragma message("===>>> Debug Build: Slow tracing to C:\\OposCCO_GraphicDisplay.log")
        #define DOTRACEV(x) WriteTrace x
        #define DODUMPV(x,y)            // Dump of non-ASCII data not implemented.
        #define TRACEINIT
        #define TRACEEXIT
    #else
        #pragma message("===>>> Debug Build: Fast tracing to OposCCO_GraphicDisplay.log")
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
#include "GraphicDisplayDefs.h"

// Standard includes...
#include "Resource.h"

// Include our variant class.
#include "OposVariant.h"

// Include our connection point implementation.
#include "GraphicDisplayCP.h"


/////////////////////////////////////////////////////////////////////////////
// Data.
/////////////////////////////////////////////////////////////////////////////

#define SO_DISP_COUNT 25
// Hidden window class and window name.
extern TCHAR g_WindowName[];
// Control Object description.
extern char  g_ControlDescription[];


/////////////////////////////////////////////////////////////////////////////
// Control class declaration.
/////////////////////////////////////////////////////////////////////////////

// The class...
class ATL_NO_VTABLE COPOSGraphicDisplay :
    // Inherit from all these classes...
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IOPOSGraphicDisplay, &IID_IOPOSGraphicDisplay, &LIBID_OposGraphicDisplay_CCO>,
    public CComControl<COPOSGraphicDisplay>,
    public IPersistStreamInitImpl<COPOSGraphicDisplay>,
    public IOleControlImpl<COPOSGraphicDisplay>,
    public IOleObjectImpl<COPOSGraphicDisplay>,
    public IOleInPlaceActiveObjectImpl<COPOSGraphicDisplay>,
    public IViewObjectExImpl<COPOSGraphicDisplay>,
    public IOleInPlaceObjectWindowlessImpl<COPOSGraphicDisplay>,
    public IConnectionPointContainerImpl<COPOSGraphicDisplay>,
    public IPersistStorageImpl<COPOSGraphicDisplay>,
    public ISpecifyPropertyPagesImpl<COPOSGraphicDisplay>,
    public IQuickActivateImpl<COPOSGraphicDisplay>,
    public IDataObjectImpl<COPOSGraphicDisplay>,
    public IProvideClassInfo2Impl<&CLSID_OPOSGraphicDisplay, &DIID__IOPOSGraphicDisplayEvents, &LIBID_OposGraphicDisplay_CCO>,
    public IObjectSafetyImpl<COPOSGraphicDisplay, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    public IPropertyNotifySinkCP<COPOSGraphicDisplay>,
    public CComCoClass<COPOSGraphicDisplay, &CLSID_OPOSGraphicDisplay>,
    public CProxy_IOPOSEvents< COPOSGraphicDisplay >
{
public:
// Constructor / FinalConstruct / Destructor.
    COPOSGraphicDisplay();
    HRESULT FinalConstruct();
    ~COPOSGraphicDisplay();

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
DECLARE_REGISTRY_RESOURCEID(IDR_OPOSGRAPHICDISPLAY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

    // Define supported interfaces.
BEGIN_COM_MAP(COPOSGraphicDisplay)
    //  Map COM dispatch to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IOPOSGraphicDisplay)
    //   Map each COM interface to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IOPOSGraphicDisplay, IOPOSGraphicDisplay)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSGraphicDisplay_1_16, IOPOSGraphicDisplay)

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
BEGIN_PROP_MAP(COPOSGraphicDisplay)
    PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
    PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

    // Define connection points.
BEGIN_CONNECTION_POINT_MAP(COPOSGraphicDisplay)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    CONNECTION_POINT_ENTRY(DIID__IOPOSGraphicDisplayEvents)
END_CONNECTION_POINT_MAP()

    // Define message map.
BEGIN_MSG_MAP(COPOSGraphicDisplay)
    CHAIN_MSG_MAP(CComControl<COPOSGraphicDisplay>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

    // Define view status for IViewObjectEx to pass to container.
    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//===========================================================================
// Bring in all of the OPOS event firing code.
//===========================================================================

protected:
    #include "GraphicDisplayEvent.h"

//===========================================================================
// Control methods and property declarations.
//===========================================================================

public:
    STDMETHOD(SOProcessID)( /*[out, retval]*/ long* pProcessID );

// Release 1.16
    STDMETHOD(get_OpenResult)( /*[out, retval]*/ LONG* pOpenResult );
    STDMETHOD(get_BinaryConversion)( /*[out, retval]*/ LONG* pBinaryConversion );
    STDMETHOD(put_BinaryConversion)( /*[in]*/ LONG BinaryConversion );
    STDMETHOD(get_CapPowerReporting)( /*[out, retval]*/ LONG* pCapPowerReporting );
    STDMETHOD(get_CheckHealthText)( /*[out, retval]*/ BSTR* pCheckHealthText );
    STDMETHOD(get_Claimed)( /*[out, retval]*/ VARIANT_BOOL* pClaimed );
    STDMETHOD(get_DeviceEnabled)( /*[out, retval]*/ VARIANT_BOOL* pDeviceEnabled );
    STDMETHOD(put_DeviceEnabled)( /*[in]*/ VARIANT_BOOL DeviceEnabled );
    STDMETHOD(get_FreezeEvents)( /*[out, retval]*/ VARIANT_BOOL* pFreezeEvents );
    STDMETHOD(put_FreezeEvents)( /*[in]*/ VARIANT_BOOL FreezeEvents );
    STDMETHOD(get_OutputID)( /*[out, retval]*/ LONG* pOutputID );
    STDMETHOD(get_PowerNotify)( /*[out, retval]*/ LONG* pPowerNotify );
    STDMETHOD(put_PowerNotify)( /*[in]*/ LONG PowerNotify );
    STDMETHOD(get_PowerState)( /*[out, retval]*/ LONG* pPowerState );
    STDMETHOD(get_ResultCode)( /*[out, retval]*/ LONG* pResultCode );
    STDMETHOD(get_ResultCodeExtended)( /*[out, retval]*/ LONG* pResultCodeExtended );
    STDMETHOD(get_State)( /*[out, retval]*/ LONG* pState );
    STDMETHOD(get_ControlObjectDescription)( /*[out, retval]*/ BSTR* pControlObjectDescription );
    STDMETHOD(get_ControlObjectVersion)( /*[out, retval]*/ LONG* pControlObjectVersion );
    STDMETHOD(get_ServiceObjectDescription)( /*[out, retval]*/ BSTR* pServiceObjectDescription );
    STDMETHOD(get_ServiceObjectVersion)( /*[out, retval]*/ LONG* pServiceObjectVersion );
    STDMETHOD(get_DeviceDescription)( /*[out, retval]*/ BSTR* pDeviceDescription );
    STDMETHOD(get_DeviceName)( /*[out, retval]*/ BSTR* pDeviceName );
    STDMETHOD(get_CapStatisticsReporting)( /*[out, retval]*/ VARIANT_BOOL* pCapStatisticsReporting );
    STDMETHOD(get_CapUpdateStatistics)( /*[out, retval]*/ VARIANT_BOOL* pCapUpdateStatistics );
    STDMETHOD(get_CapCompareFirmwareVersion)( /*[out, retval]*/ VARIANT_BOOL* pCapCompareFirmwareVersion );
    STDMETHOD(get_CapUpdateFirmware)( /*[out, retval]*/ VARIANT_BOOL* pCapUpdateFirmware );
    STDMETHOD(CheckHealth)( 
        /*[in]*/ LONG Level, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ClaimDevice)( 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ClearOutput)( 
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
    STDMETHOD(ResetStatistics)( 
        /*[in]*/ BSTR StatisticsBuffer, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(RetrieveStatistics)( 
        /*[in, out]*/ BSTR* pStatisticsBuffer, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UpdateStatistics)( 
        /*[in]*/ BSTR StatisticsBuffer, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(CompareFirmwareVersion)( 
        /*[in]*/ BSTR FirmwareFileName, 
        /*[out]*/ LONG* pResult, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UpdateFirmware)( 
        /*[in]*/ BSTR FirmwareFileName, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(get_Brightness)( /*[out, retval]*/ LONG* pBrightness );
    STDMETHOD(put_Brightness)( /*[in]*/ LONG Brightness );
    STDMETHOD(get_CapAssociatedHardTotalsDevice)( /*[out, retval]*/ BSTR* pCapAssociatedHardTotalsDevice );
    STDMETHOD(get_CapBrightness)( /*[out, retval]*/ VARIANT_BOOL* pCapBrightness );
    STDMETHOD(get_CapImageType)( /*[out, retval]*/ VARIANT_BOOL* pCapImageType );
    STDMETHOD(get_CapStorage)( /*[out, retval]*/ LONG* pCapStorage );
    STDMETHOD(get_CapURLBack)( /*[out, retval]*/ VARIANT_BOOL* pCapURLBack );
    STDMETHOD(get_CapURLForward)( /*[out, retval]*/ VARIANT_BOOL* pCapURLForward );
    STDMETHOD(get_CapVideoType)( /*[out, retval]*/ VARIANT_BOOL* pCapVideoType );
    STDMETHOD(get_CapVolume)( /*[out, retval]*/ VARIANT_BOOL* pCapVolume );
    STDMETHOD(get_DisplayMode)( /*[out, retval]*/ LONG* pDisplayMode );
    STDMETHOD(put_DisplayMode)( /*[in]*/ LONG DisplayMode );
    STDMETHOD(get_ImageType)( /*[out, retval]*/ BSTR* pImageType );
    STDMETHOD(put_ImageType)( /*[in]*/ BSTR ImageType );
    STDMETHOD(get_ImageTypeList)( /*[out, retval]*/ BSTR* pImageTypeList );
    STDMETHOD(get_LoadStatus)( /*[out, retval]*/ LONG* pLoadStatus );
    STDMETHOD(get_Storage)( /*[out, retval]*/ LONG* pStorage );
    STDMETHOD(put_Storage)( /*[in]*/ LONG Storage );
    STDMETHOD(get_URL)( /*[out, retval]*/ BSTR* pURL );
    STDMETHOD(get_VideoType)( /*[out, retval]*/ BSTR* pVideoType );
    STDMETHOD(put_VideoType)( /*[in]*/ BSTR VideoType );
    STDMETHOD(get_VideoTypeList)( /*[out, retval]*/ BSTR* pVideoTypeList );
    STDMETHOD(get_Volume)( /*[out, retval]*/ LONG* pVolume );
    STDMETHOD(put_Volume)( /*[in]*/ LONG Volume );
    STDMETHOD(CancelURLLoading)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(GoURLBack)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(GoURLForward)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(LoadImage)( 
        /*[in]*/ BSTR FileName, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(LoadURL)( 
        /*[in]*/ BSTR URL, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PlayVideo)( 
        /*[in]*/ BSTR FileName, 
        /*[in]*/ VARIANT_BOOL Loop, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(StopVideo)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UpdatePage)( 
        /*[out, retval]*/ long* pRC );
};


// End GraphicDisplayImpl.h
