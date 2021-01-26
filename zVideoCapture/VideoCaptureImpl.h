/****************************************************************************
**
** VideoCaptureImpl.h -- Main control header file.
**
**     Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  2021/01/26 Initial Version from similar sources.                K. Fukuchi
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
        #pragma message("===>>> Debug Build: Slow tracing to C:\\OposCCO_VideoCapture.log")
        #define DOTRACEV(x) WriteTrace x
        #define DODUMPV(x,y)            // Dump of non-ASCII data not implemented.
        #define TRACEINIT
        #define TRACEEXIT
    #else
        #pragma message("===>>> Debug Build: Fast tracing to OposCCO_VideoCapture.log")
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
#include "VideoCaptureDefs.h"

// Standard includes...
#include "Resource.h"

// Include our variant class.
#include "OposVariant.h"

// Include our connection point implementation.
#include "VideoCaptureCP.h"


/////////////////////////////////////////////////////////////////////////////
// Data.
/////////////////////////////////////////////////////////////////////////////

#define SO_DISP_COUNT 20
// Hidden window class and window name.
extern TCHAR g_WindowName[];
// Control Object description.
extern char  g_ControlDescription[];


/////////////////////////////////////////////////////////////////////////////
// Control class declaration.
/////////////////////////////////////////////////////////////////////////////

// The class...
class ATL_NO_VTABLE COPOSVideoCapture :
    // Inherit from all these classes...
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IOPOSVideoCapture, &IID_IOPOSVideoCapture, &LIBID_OposVideoCapture_CCO>,
    public CComControl<COPOSVideoCapture>,
    public IPersistStreamInitImpl<COPOSVideoCapture>,
    public IOleControlImpl<COPOSVideoCapture>,
    public IOleObjectImpl<COPOSVideoCapture>,
    public IOleInPlaceActiveObjectImpl<COPOSVideoCapture>,
    public IViewObjectExImpl<COPOSVideoCapture>,
    public IOleInPlaceObjectWindowlessImpl<COPOSVideoCapture>,
    public IConnectionPointContainerImpl<COPOSVideoCapture>,
    public IPersistStorageImpl<COPOSVideoCapture>,
    public ISpecifyPropertyPagesImpl<COPOSVideoCapture>,
    public IQuickActivateImpl<COPOSVideoCapture>,
    public IDataObjectImpl<COPOSVideoCapture>,
    public IProvideClassInfo2Impl<&CLSID_OPOSVideoCapture, &DIID__IOPOSVideoCaptureEvents, &LIBID_OposVideoCapture_CCO>,
    public IObjectSafetyImpl<COPOSVideoCapture, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    public IPropertyNotifySinkCP<COPOSVideoCapture>,
    public CComCoClass<COPOSVideoCapture, &CLSID_OPOSVideoCapture>,
    public CProxy_IOPOSEvents< COPOSVideoCapture >
{
public:
// Constructor / FinalConstruct / Destructor.
    COPOSVideoCapture();
    HRESULT FinalConstruct();
    ~COPOSVideoCapture();

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
DECLARE_REGISTRY_RESOURCEID(IDR_OPOSVIDEOCAPTURE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

    // Define supported interfaces.
BEGIN_COM_MAP(COPOSVideoCapture)
    //  Map COM dispatch to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IOPOSVideoCapture)
    //   Map each COM interface to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IOPOSVideoCapture, IOPOSVideoCapture)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSVideoCapture_1_16, IOPOSVideoCapture)

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
BEGIN_PROP_MAP(COPOSVideoCapture)
    PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
    PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

    // Define connection points.
BEGIN_CONNECTION_POINT_MAP(COPOSVideoCapture)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    CONNECTION_POINT_ENTRY(DIID__IOPOSVideoCaptureEvents)
END_CONNECTION_POINT_MAP()

    // Define message map.
BEGIN_MSG_MAP(COPOSVideoCapture)
    CHAIN_MSG_MAP(CComControl<COPOSVideoCapture>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

    // Define view status for IViewObjectEx to pass to container.
    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//===========================================================================
// Bring in all of the OPOS event firing code.
//===========================================================================

protected:
    #include "VideoCaptureEvent.h"

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
    STDMETHOD(ClearInput)( 
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
    STDMETHOD(get_AutoExposure)( /*[out, retval]*/ VARIANT_BOOL* pAutoExposure );
    STDMETHOD(put_AutoExposure)( /*[in]*/ VARIANT_BOOL AutoExposure );
    STDMETHOD(get_AutoFocus)( /*[out, retval]*/ VARIANT_BOOL* pAutoFocus );
    STDMETHOD(put_AutoFocus)( /*[in]*/ VARIANT_BOOL AutoFocus );
    STDMETHOD(get_AutoGain)( /*[out, retval]*/ VARIANT_BOOL* pAutoGain );
    STDMETHOD(put_AutoGain)( /*[in]*/ VARIANT_BOOL AutoGain );
    STDMETHOD(get_AutoWhiteBalance)( /*[out, retval]*/ VARIANT_BOOL* pAutoWhiteBalance );
    STDMETHOD(put_AutoWhiteBalance)( /*[in]*/ VARIANT_BOOL AutoWhiteBalance );
    STDMETHOD(get_Brightness)( /*[out, retval]*/ LONG* pBrightness );
    STDMETHOD(put_Brightness)( /*[in]*/ LONG Brightness );
    STDMETHOD(get_CapAssociatedHardTotalsDevice)( /*[out, retval]*/ BSTR* pCapAssociatedHardTotalsDevice );
    STDMETHOD(get_CapAutoExposure)( /*[out, retval]*/ VARIANT_BOOL* pCapAutoExposure );
    STDMETHOD(get_CapAutoFocus)( /*[out, retval]*/ VARIANT_BOOL* pCapAutoFocus );
    STDMETHOD(get_CapAutoGain)( /*[out, retval]*/ VARIANT_BOOL* pCapAutoGain );
    STDMETHOD(get_CapAutoWhiteBalance)( /*[out, retval]*/ VARIANT_BOOL* pCapAutoWhiteBalance );
    STDMETHOD(get_CapBrightness)( /*[out, retval]*/ VARIANT_BOOL* pCapBrightness );
    STDMETHOD(get_CapContrast)( /*[out, retval]*/ VARIANT_BOOL* pCapContrast );
    STDMETHOD(get_CapExposure)( /*[out, retval]*/ VARIANT_BOOL* pCapExposure );
    STDMETHOD(get_CapGain)( /*[out, retval]*/ VARIANT_BOOL* pCapGain );
    STDMETHOD(get_CapHorizontalFlip)( /*[out, retval]*/ VARIANT_BOOL* pCapHorizontalFlip );
    STDMETHOD(get_CapHue)( /*[out, retval]*/ VARIANT_BOOL* pCapHue );
    STDMETHOD(get_CapPhoto)( /*[out, retval]*/ VARIANT_BOOL* pCapPhoto );
    STDMETHOD(get_CapPhotoColorSpace)( /*[out, retval]*/ VARIANT_BOOL* pCapPhotoColorSpace );
    STDMETHOD(get_CapPhotoFrameRate)( /*[out, retval]*/ VARIANT_BOOL* pCapPhotoFrameRate );
    STDMETHOD(get_CapPhotoResolution)( /*[out, retval]*/ VARIANT_BOOL* pCapPhotoResolution );
    STDMETHOD(get_CapPhotoType)( /*[out, retval]*/ VARIANT_BOOL* pCapPhotoType );
    STDMETHOD(get_CapSaturation)( /*[out, retval]*/ VARIANT_BOOL* pCapSaturation );
    STDMETHOD(get_CapStorage)( /*[out, retval]*/ LONG* pCapStorage );
    STDMETHOD(get_CapVerticalFlip)( /*[out, retval]*/ VARIANT_BOOL* pCapVerticalFlip );
    STDMETHOD(get_CapVideo)( /*[out, retval]*/ VARIANT_BOOL* pCapVideo );
    STDMETHOD(get_CapVideoColorSpace)( /*[out, retval]*/ VARIANT_BOOL* pCapVideoColorSpace );
    STDMETHOD(get_CapVideoFrameRate)( /*[out, retval]*/ VARIANT_BOOL* pCapVideoFrameRate );
    STDMETHOD(get_CapVideoResolution)( /*[out, retval]*/ VARIANT_BOOL* pCapVideoResolution );
    STDMETHOD(get_CapVideoType)( /*[out, retval]*/ VARIANT_BOOL* pCapVideoType );
    STDMETHOD(get_Contrast)( /*[out, retval]*/ LONG* pContrast );
    STDMETHOD(put_Contrast)( /*[in]*/ LONG Contrast );
    STDMETHOD(get_Exposure)( /*[out, retval]*/ LONG* pExposure );
    STDMETHOD(put_Exposure)( /*[in]*/ LONG Exposure );
    STDMETHOD(get_Gain)( /*[out, retval]*/ LONG* pGain );
    STDMETHOD(put_Gain)( /*[in]*/ LONG Gain );
    STDMETHOD(get_HorizontalFlip)( /*[out, retval]*/ VARIANT_BOOL* pHorizontalFlip );
    STDMETHOD(put_HorizontalFlip)( /*[in]*/ VARIANT_BOOL HorizontalFlip );
    STDMETHOD(get_Hue)( /*[out, retval]*/ LONG* pHue );
    STDMETHOD(put_Hue)( /*[in]*/ LONG Hue );
    STDMETHOD(get_PhotoColorSpace)( /*[out, retval]*/ BSTR* pPhotoColorSpace );
    STDMETHOD(put_PhotoColorSpace)( /*[in]*/ BSTR PhotoColorSpace );
    STDMETHOD(get_PhotoColorSpaceList)( /*[out, retval]*/ BSTR* pPhotoColorSpaceList );
    STDMETHOD(get_PhotoFrameRate)( /*[out, retval]*/ LONG* pPhotoFrameRate );
    STDMETHOD(put_PhotoFrameRate)( /*[in]*/ LONG PhotoFrameRate );
    STDMETHOD(get_PhotoMaxFrameRate)( /*[out, retval]*/ LONG* pPhotoMaxFrameRate );
    STDMETHOD(get_PhotoResolution)( /*[out, retval]*/ BSTR* pPhotoResolution );
    STDMETHOD(put_PhotoResolution)( /*[in]*/ BSTR PhotoResolution );
    STDMETHOD(get_PhotoResolutionList)( /*[out, retval]*/ BSTR* pPhotoResolutionList );
    STDMETHOD(get_PhotoType)( /*[out, retval]*/ BSTR* pPhotoType );
    STDMETHOD(put_PhotoType)( /*[in]*/ BSTR PhotoType );
    STDMETHOD(get_PhotoTypeList)( /*[out, retval]*/ BSTR* pPhotoTypeList );
    STDMETHOD(get_RemainingRecordingTimeInSec)( /*[out, retval]*/ LONG* pRemainingRecordingTimeInSec );
    STDMETHOD(get_Saturation)( /*[out, retval]*/ LONG* pSaturation );
    STDMETHOD(put_Saturation)( /*[in]*/ LONG Saturation );
    STDMETHOD(get_Storage)( /*[out, retval]*/ LONG* pStorage );
    STDMETHOD(put_Storage)( /*[in]*/ LONG Storage );
    STDMETHOD(get_VerticalFlip)( /*[out, retval]*/ VARIANT_BOOL* pVerticalFlip );
    STDMETHOD(put_VerticalFlip)( /*[in]*/ VARIANT_BOOL VerticalFlip );
    STDMETHOD(get_VideoCaptureMode)( /*[out, retval]*/ LONG* pVideoCaptureMode );
    STDMETHOD(put_VideoCaptureMode)( /*[in]*/ LONG VideoCaptureMode );
    STDMETHOD(get_VideoColorSpace)( /*[out, retval]*/ BSTR* pVideoColorSpace );
    STDMETHOD(put_VideoColorSpace)( /*[in]*/ BSTR VideoColorSpace );
    STDMETHOD(get_VideoColorSpaceList)( /*[out, retval]*/ BSTR* pVideoColorSpaceList );
    STDMETHOD(get_VideoFrameRate)( /*[out, retval]*/ LONG* pVideoFrameRate );
    STDMETHOD(put_VideoFrameRate)( /*[in]*/ LONG VideoFrameRate );
    STDMETHOD(get_VideoMaxFrameRate)( /*[out, retval]*/ LONG* pVideoMaxFrameRate );
    STDMETHOD(get_VideoResolution)( /*[out, retval]*/ BSTR* pVideoResolution );
    STDMETHOD(put_VideoResolution)( /*[in]*/ BSTR VideoResolution );
    STDMETHOD(get_VideoResolutionList)( /*[out, retval]*/ BSTR* pVideoResolutionList );
    STDMETHOD(get_VideoType)( /*[out, retval]*/ BSTR* pVideoType );
    STDMETHOD(put_VideoType)( /*[in]*/ BSTR VideoType );
    STDMETHOD(get_VideoTypeList)( /*[out, retval]*/ BSTR* pVideoTypeList );
    STDMETHOD(StartVideo)( 
        /*[in]*/ BSTR FileName, 
        /*[in]*/ VARIANT_BOOL OverWrite, 
        /*[in]*/ LONG RecordingTime, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(StopVideo)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(TakePhoto)( 
        /*[in]*/ BSTR FileName, 
        /*[in]*/ VARIANT_BOOL OverWrite, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
};


// End VideoCaptureImpl.h
