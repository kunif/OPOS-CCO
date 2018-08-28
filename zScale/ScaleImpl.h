/****************************************************************************
**
** ScaleImpl.h -- Main control header file.
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

#ifndef __SCALEIMPL_H__
#define __SCALEIMPL_H__


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
        #pragma message("===>>> Debug Build: Slow tracing to C:\\OposCCO_Scale.log")
        #define DOTRACEV(x) WriteTrace x
        #define DODUMPV(x,y)            // Dump of non-ASCII data not implemented.
        #define TRACEINIT
        #define TRACEEXIT
    #else
        #pragma message("===>>> Debug Build: Fast tracing to OposCCO_Scale.log")
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
#include "ScaleDefs.h"

// Standard includes...
#include "Resource.h"

// Include our variant class.
#include "OposVariant.h"

// Include our connection point implementation.
#include "ScaleCP.h"


/////////////////////////////////////////////////////////////////////////////
// Data.
/////////////////////////////////////////////////////////////////////////////

#define SO_DISP_COUNT 30
// Hidden window class and window name.
extern TCHAR g_WindowName[];
// Control Object description.
extern char  g_ControlDescription[];


/////////////////////////////////////////////////////////////////////////////
// Control class declaration.
/////////////////////////////////////////////////////////////////////////////

// The class...
class ATL_NO_VTABLE COPOSScale :
    // Inherit from all these classes...
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IOPOSScale, &IID_IOPOSScale, &LIBID_OposScale_CCO>,
    public CComControl<COPOSScale>,
    public IPersistStreamInitImpl<COPOSScale>,
    public IOleControlImpl<COPOSScale>,
    public IOleObjectImpl<COPOSScale>,
    public IOleInPlaceActiveObjectImpl<COPOSScale>,
    public IViewObjectExImpl<COPOSScale>,
    public IOleInPlaceObjectWindowlessImpl<COPOSScale>,
    public IConnectionPointContainerImpl<COPOSScale>,
    public IPersistStorageImpl<COPOSScale>,
    public ISpecifyPropertyPagesImpl<COPOSScale>,
    public IQuickActivateImpl<COPOSScale>,
    public IDataObjectImpl<COPOSScale>,
    public IProvideClassInfo2Impl<&CLSID_OPOSScale, &DIID__IOPOSScaleEvents, &LIBID_OposScale_CCO>,
    public IObjectSafetyImpl<COPOSScale, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    public IPropertyNotifySinkCP<COPOSScale>,
    public CComCoClass<COPOSScale, &CLSID_OPOSScale>,
    public CProxy_IOPOSEvents< COPOSScale >
{
public:
// Constructor / FinalConstruct / Destructor.
    COPOSScale();
    HRESULT FinalConstruct();
    ~COPOSScale();

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
    LPCTSTR FormatCurrency( CY cyCurrency );
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
DECLARE_REGISTRY_RESOURCEID(IDR_OPOSSCALE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

    // Define supported interfaces.
BEGIN_COM_MAP(COPOSScale)
    //  Map COM dispatch to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IOPOSScale)
    //   Map each COM interface to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IOPOSScale, IOPOSScale)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSScale_1_14, IOPOSScale)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSScale_1_13, IOPOSScale)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSScale_1_13_zz, IOPOSScale)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSScale_1_9, IOPOSScale)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSScale_1_9_zz, IOPOSScale)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSScale_1_8, IOPOSScale)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSScale_1_5, IOPOSScale)

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
BEGIN_PROP_MAP(COPOSScale)
    PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
    PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

    // Define connection points.
BEGIN_CONNECTION_POINT_MAP(COPOSScale)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    CONNECTION_POINT_ENTRY(DIID__IOPOSScaleEvents)
END_CONNECTION_POINT_MAP()

    // Define message map.
BEGIN_MSG_MAP(COPOSScale)
    CHAIN_MSG_MAP(CComControl<COPOSScale>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

    // Define view status for IViewObjectEx to pass to container.
    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//===========================================================================
// Bring in all of the OPOS event firing code.
//===========================================================================

protected:
    #include "ScaleEvent.h"

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
    STDMETHOD(get_MaximumWeight)( /*[out, retval]*/ LONG* pMaximumWeight );
    STDMETHOD(get_WeightUnit)( /*[out, retval]*/ LONG* pWeightUnit );
    STDMETHOD(get_WeightUnits)( /*[out, retval]*/ LONG* pWeightUnits );
    STDMETHOD(ReadWeight)( 
        /*[out]*/ LONG* pWeightData, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
// Release 1.1
// Release 1.2
    STDMETHOD(get_BinaryConversion)( /*[out, retval]*/ LONG* pBinaryConversion );
    STDMETHOD(put_BinaryConversion)( /*[in]*/ LONG BinaryConversion );
    STDMETHOD(get_CapDisplay)( /*[out, retval]*/ VARIANT_BOOL* pCapDisplay );
// Release 1.3
    STDMETHOD(get_AutoDisable)( /*[out, retval]*/ VARIANT_BOOL* pAutoDisable );
    STDMETHOD(put_AutoDisable)( /*[in]*/ VARIANT_BOOL AutoDisable );
    STDMETHOD(get_CapPowerReporting)( /*[out, retval]*/ LONG* pCapPowerReporting );
    STDMETHOD(get_DataCount)( /*[out, retval]*/ LONG* pDataCount );
    STDMETHOD(get_DataEventEnabled)( /*[out, retval]*/ VARIANT_BOOL* pDataEventEnabled );
    STDMETHOD(put_DataEventEnabled)( /*[in]*/ VARIANT_BOOL DataEventEnabled );
    STDMETHOD(get_PowerNotify)( /*[out, retval]*/ LONG* pPowerNotify );
    STDMETHOD(put_PowerNotify)( /*[in]*/ LONG PowerNotify );
    STDMETHOD(get_PowerState)( /*[out, retval]*/ LONG* pPowerState );
    STDMETHOD(ClearInput)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(get_AsyncMode)( /*[out, retval]*/ VARIANT_BOOL* pAsyncMode );
    STDMETHOD(put_AsyncMode)( /*[in]*/ VARIANT_BOOL AsyncMode );
    STDMETHOD(get_CapDisplayText)( /*[out, retval]*/ VARIANT_BOOL* pCapDisplayText );
    STDMETHOD(get_CapPriceCalculating)( /*[out, retval]*/ VARIANT_BOOL* pCapPriceCalculating );
    STDMETHOD(get_CapTareWeight)( /*[out, retval]*/ VARIANT_BOOL* pCapTareWeight );
    STDMETHOD(get_CapZeroScale)( /*[out, retval]*/ VARIANT_BOOL* pCapZeroScale );
    STDMETHOD(get_MaxDisplayTextChars)( /*[out, retval]*/ LONG* pMaxDisplayTextChars );
    STDMETHOD(get_SalesPrice)( /*[out, retval]*/ CURRENCY* pSalesPrice );
    STDMETHOD(get_TareWeight)( /*[out, retval]*/ LONG* pTareWeight );
    STDMETHOD(put_TareWeight)( /*[in]*/ LONG TareWeight );
    STDMETHOD(get_UnitPrice)( /*[out, retval]*/ CURRENCY* pUnitPrice );
    STDMETHOD(put_UnitPrice)( /*[in]*/ CURRENCY UnitPrice );
    STDMETHOD(DisplayText)( 
        /*[in]*/ BSTR Data, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ZeroScale)( 
        /*[out, retval]*/ long* pRC );
// Release 1.4
// Release 1.5
// Release 1.6
// Release 1.7
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
    STDMETHOD(get_CapStatusUpdate)( /*[out, retval]*/ VARIANT_BOOL* pCapStatusUpdate );
    STDMETHOD(get_ScaleLiveWeight)( /*[out, retval]*/ LONG* pScaleLiveWeight );
    STDMETHOD(get_StatusNotify)( /*[out, retval]*/ LONG* pStatusNotify );
    STDMETHOD(put_StatusNotify)( /*[in]*/ LONG StatusNotify );
// Release 1.10
// Release 1.11
// Release 1.12
// Release 1.13
    STDMETHOD(get_ZeroValid)( /*[out, retval]*/ VARIANT_BOOL* pZeroValid );
    STDMETHOD(put_ZeroValid)( /*[in]*/ VARIANT_BOOL ZeroValid );
// Release 1.14
    STDMETHOD(get_CapFreezeValue)( /*[out, retval]*/ VARIANT_BOOL* pCapFreezeValue );
    STDMETHOD(get_CapReadLiveWeightWithTare)( /*[out, retval]*/ VARIANT_BOOL* pCapReadLiveWeightWithTare );
    STDMETHOD(get_CapSetPriceCalculationMode)( /*[out, retval]*/ VARIANT_BOOL* pCapSetPriceCalculationMode );
    STDMETHOD(get_CapSetUnitPriceWithWeightUnit)( /*[out, retval]*/ VARIANT_BOOL* pCapSetUnitPriceWithWeightUnit );
    STDMETHOD(get_CapSpecialTare)( /*[out, retval]*/ VARIANT_BOOL* pCapSpecialTare );
    STDMETHOD(get_CapTarePriority)( /*[out, retval]*/ VARIANT_BOOL* pCapTarePriority );
    STDMETHOD(get_MinimumWeight)( /*[out, retval]*/ LONG* pMinimumWeight );
    STDMETHOD(DoPriceCalculating)( 
        /*[out]*/ LONG* pWeightData, 
        /*[out]*/ LONG* pTare, 
        /*[out]*/ CURRENCY* pUnitPrice, 
        /*[out]*/ CURRENCY* pUnitPriceX, 
        /*[out]*/ LONG* pWeightUnitX, 
        /*[out]*/ LONG* pWeightNumeratorX, 
        /*[out]*/ LONG* pWeightDenominatorX, 
        /*[out]*/ CURRENCY* pPrice, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(FreezeValue)( 
        /*[in]*/ LONG Item, 
        /*[in]*/ VARIANT_BOOL Freeze, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ReadLiveWeightWithTare)( 
        /*[out]*/ LONG* pWeightData, 
        /*[out]*/ LONG* pTare, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetPriceCalculationMode)( 
        /*[in]*/ LONG Mode, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetSpecialTare)( 
        /*[in]*/ LONG Mode, 
        /*[in]*/ LONG Data, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetTarePriority)( 
        /*[in]*/ LONG Priority, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetUnitPriceWithWeightUnit)( 
        /*[in]*/ CURRENCY UnitPrice, 
        /*[in]*/ LONG WeightUnit, 
        /*[in]*/ LONG WeightNumerator, 
        /*[in]*/ LONG WeightDenominator, 
        /*[out, retval]*/ long* pRC );
};

#endif //__SCALEIMPL_H__

// End ScaleImpl.h
