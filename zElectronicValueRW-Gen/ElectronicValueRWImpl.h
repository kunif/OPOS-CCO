/****************************************************************************
**
** ElectronicValueRWImpl.h -- Main control header file.
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
**  2015/02/07 Version 1.15.100.
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

#ifndef __ELECTRONICVALUERWIMPL_H__
#define __ELECTRONICVALUERWIMPL_H__


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
        #pragma message("===>>> Debug Build: Slow tracing to C:\\OposCCO_ElectronicValueRW.log")
        #define DOTRACEV(x) WriteTrace x
        #define DODUMPV(x,y)            // Dump of non-ASCII data not implemented.
        #define TRACEINIT
        #define TRACEEXIT
    #else
        #pragma message("===>>> Debug Build: Fast tracing to OposCCO_ElectronicValueRW.log")
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
#include "ElectronicValueRWDefs.h"

// Standard includes...
#include "Resource.h"

// Include our variant class.
#include "OposVariant.h"

// Include our connection point implementation.
#include "ElectronicValueRWCP.h"


/////////////////////////////////////////////////////////////////////////////
// Data.
/////////////////////////////////////////////////////////////////////////////

#define SO_DISP_COUNT 57
// Hidden window class and window name.
extern TCHAR g_WindowName[];
// Control Object description.
extern char  g_ControlDescription[];


/////////////////////////////////////////////////////////////////////////////
// Control class declaration.
/////////////////////////////////////////////////////////////////////////////

// The class...
class ATL_NO_VTABLE COPOSElectronicValueRW :
    // Inherit from all these classes...
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IOPOSElectronicValueRW, &IID_IOPOSElectronicValueRW, &LIBID_OposElectronicValueRW_CCO>,
    public CComControl<COPOSElectronicValueRW>,
    public IPersistStreamInitImpl<COPOSElectronicValueRW>,
    public IOleControlImpl<COPOSElectronicValueRW>,
    public IOleObjectImpl<COPOSElectronicValueRW>,
    public IOleInPlaceActiveObjectImpl<COPOSElectronicValueRW>,
    public IViewObjectExImpl<COPOSElectronicValueRW>,
    public IOleInPlaceObjectWindowlessImpl<COPOSElectronicValueRW>,
    public IConnectionPointContainerImpl<COPOSElectronicValueRW>,
    public IPersistStorageImpl<COPOSElectronicValueRW>,
    public ISpecifyPropertyPagesImpl<COPOSElectronicValueRW>,
    public IQuickActivateImpl<COPOSElectronicValueRW>,
    public IDataObjectImpl<COPOSElectronicValueRW>,
    public IProvideClassInfo2Impl<&CLSID_OPOSElectronicValueRW, &DIID__IOPOSElectronicValueRWEvents, &LIBID_OposElectronicValueRW_CCO>,
    public IObjectSafetyImpl<COPOSElectronicValueRW, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    public IPropertyNotifySinkCP<COPOSElectronicValueRW>,
    public CComCoClass<COPOSElectronicValueRW, &CLSID_OPOSElectronicValueRW>,
    public CProxy_IOPOSEvents< COPOSElectronicValueRW >
{
public:
// Constructor / FinalConstruct / Destructor.
    COPOSElectronicValueRW();
    HRESULT FinalConstruct();
    ~COPOSElectronicValueRW();

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
DECLARE_REGISTRY_RESOURCEID(IDR_OPOSELECTRONICVALUERW)

DECLARE_PROTECT_FINAL_CONSTRUCT()

    // Define supported interfaces.
BEGIN_COM_MAP(COPOSElectronicValueRW)
    //  Map COM dispatch to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IOPOSElectronicValueRW)
    //   Map each COM interface to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IOPOSElectronicValueRW, IOPOSElectronicValueRW)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSElectronicValueRW_1_15, IOPOSElectronicValueRW)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSElectronicValueRW_1_14, IOPOSElectronicValueRW)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSElectronicValueRW_1_14_zz, IOPOSElectronicValueRW)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSElectronicValueRW_1_12, IOPOSElectronicValueRW)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSElectronicValueRW_1_12_zz, IOPOSElectronicValueRW)

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
BEGIN_PROP_MAP(COPOSElectronicValueRW)
    PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
    PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

    // Define connection points.
BEGIN_CONNECTION_POINT_MAP(COPOSElectronicValueRW)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    CONNECTION_POINT_ENTRY(DIID__IOPOSElectronicValueRWEvents)
END_CONNECTION_POINT_MAP()

    // Define message map.
BEGIN_MSG_MAP(COPOSElectronicValueRW)
    CHAIN_MSG_MAP(CComControl<COPOSElectronicValueRW>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

    // Define view status for IViewObjectEx to pass to container.
    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//===========================================================================
// Bring in all of the OPOS event firing code.
//===========================================================================

protected:
    #include "ElectronicValueRWEvent.h"

//===========================================================================
// Control methods and property declarations.
//===========================================================================

public:
    STDMETHOD(SOProcessID)( /*[out, retval]*/ long* pProcessID );

// Release 1.12
    STDMETHOD(get_OpenResult)( /*[out, retval]*/ LONG* pOpenResult );
    STDMETHOD(get_AutoDisable)( /*[out, retval]*/ VARIANT_BOOL* pAutoDisable );
    STDMETHOD(put_AutoDisable)( /*[in]*/ VARIANT_BOOL AutoDisable );
    STDMETHOD(get_BinaryConversion)( /*[out, retval]*/ LONG* pBinaryConversion );
    STDMETHOD(put_BinaryConversion)( /*[in]*/ LONG BinaryConversion );
    STDMETHOD(get_CapPowerReporting)( /*[out, retval]*/ LONG* pCapPowerReporting );
    STDMETHOD(get_CheckHealthText)( /*[out, retval]*/ BSTR* pCheckHealthText );
    STDMETHOD(get_Claimed)( /*[out, retval]*/ VARIANT_BOOL* pClaimed );
    STDMETHOD(get_DataCount)( /*[out, retval]*/ LONG* pDataCount );
    STDMETHOD(get_DataEventEnabled)( /*[out, retval]*/ VARIANT_BOOL* pDataEventEnabled );
    STDMETHOD(put_DataEventEnabled)( /*[in]*/ VARIANT_BOOL DataEventEnabled );
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
    STDMETHOD(ClearInput)( 
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
    STDMETHOD(ClearInputProperties)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(get_AccountNumber)( /*[out, retval]*/ BSTR* pAccountNumber );
    STDMETHOD(get_AdditionalSecurityInformation)( /*[out, retval]*/ BSTR* pAdditionalSecurityInformation );
    STDMETHOD(put_AdditionalSecurityInformation)( /*[in]*/ BSTR AdditionalSecurityInformation );
    STDMETHOD(get_Amount)( /*[out, retval]*/ CURRENCY* pAmount );
    STDMETHOD(put_Amount)( /*[in]*/ CURRENCY Amount );
    STDMETHOD(get_ApprovalCode)( /*[out, retval]*/ BSTR* pApprovalCode );
    STDMETHOD(put_ApprovalCode)( /*[in]*/ BSTR ApprovalCode );
    STDMETHOD(get_AsyncMode)( /*[out, retval]*/ VARIANT_BOOL* pAsyncMode );
    STDMETHOD(put_AsyncMode)( /*[in]*/ VARIANT_BOOL AsyncMode );
    STDMETHOD(get_Balance)( /*[out, retval]*/ CURRENCY* pBalance );
    STDMETHOD(get_BalanceOfPoint)( /*[out, retval]*/ CURRENCY* pBalanceOfPoint );
    STDMETHOD(get_CapActivateService)( /*[out, retval]*/ VARIANT_BOOL* pCapActivateService );
    STDMETHOD(get_CapAddValue)( /*[out, retval]*/ VARIANT_BOOL* pCapAddValue );
    STDMETHOD(get_CapCancelValue)( /*[out, retval]*/ VARIANT_BOOL* pCapCancelValue );
    STDMETHOD(get_CapCardSensor)( /*[out, retval]*/ LONG* pCapCardSensor );
    STDMETHOD(get_CapDetectionControl)( /*[out, retval]*/ LONG* pCapDetectionControl );
    STDMETHOD(get_CapElectronicMoney)( /*[out, retval]*/ VARIANT_BOOL* pCapElectronicMoney );
    STDMETHOD(get_CapEnumerateCardServices)( /*[out, retval]*/ VARIANT_BOOL* pCapEnumerateCardServices );
    STDMETHOD(get_CapIndirectTransactionLog)( /*[out, retval]*/ VARIANT_BOOL* pCapIndirectTransactionLog );
    STDMETHOD(get_CapLockTerminal)( /*[out, retval]*/ VARIANT_BOOL* pCapLockTerminal );
    STDMETHOD(get_CapLogStatus)( /*[out, retval]*/ VARIANT_BOOL* pCapLogStatus );
    STDMETHOD(get_CapMediumID)( /*[out, retval]*/ VARIANT_BOOL* pCapMediumID );
    STDMETHOD(get_CapPoint)( /*[out, retval]*/ VARIANT_BOOL* pCapPoint );
    STDMETHOD(get_CapSubtractValue)( /*[out, retval]*/ VARIANT_BOOL* pCapSubtractValue );
    STDMETHOD(get_CapTransaction)( /*[out, retval]*/ VARIANT_BOOL* pCapTransaction );
    STDMETHOD(get_CapTransactionLog)( /*[out, retval]*/ VARIANT_BOOL* pCapTransactionLog );
    STDMETHOD(get_CapUnlockTerminal)( /*[out, retval]*/ VARIANT_BOOL* pCapUnlockTerminal );
    STDMETHOD(get_CapUpdateKey)( /*[out, retval]*/ VARIANT_BOOL* pCapUpdateKey );
    STDMETHOD(get_CapVoucher)( /*[out, retval]*/ VARIANT_BOOL* pCapVoucher );
    STDMETHOD(get_CapWriteValue)( /*[out, retval]*/ VARIANT_BOOL* pCapWriteValue );
    STDMETHOD(get_CardServiceList)( /*[out, retval]*/ BSTR* pCardServiceList );
    STDMETHOD(get_CurrentService)( /*[out, retval]*/ BSTR* pCurrentService );
    STDMETHOD(put_CurrentService)( /*[in]*/ BSTR CurrentService );
    STDMETHOD(get_DetectionControl)( /*[out, retval]*/ VARIANT_BOOL* pDetectionControl );
    STDMETHOD(put_DetectionControl)( /*[in]*/ VARIANT_BOOL DetectionControl );
    STDMETHOD(get_DetectionStatus)( /*[out, retval]*/ LONG* pDetectionStatus );
    STDMETHOD(get_ExpirationDate)( /*[out, retval]*/ BSTR* pExpirationDate );
    STDMETHOD(get_LastUsedDate)( /*[out, retval]*/ BSTR* pLastUsedDate );
    STDMETHOD(get_LogStatus)( /*[out, retval]*/ LONG* pLogStatus );
    STDMETHOD(get_MediumID)( /*[out, retval]*/ BSTR* pMediumID );
    STDMETHOD(put_MediumID)( /*[in]*/ BSTR MediumID );
    STDMETHOD(get_Point)( /*[out, retval]*/ CURRENCY* pPoint );
    STDMETHOD(put_Point)( /*[in]*/ CURRENCY Point );
    STDMETHOD(get_ReaderWriterServiceList)( /*[out, retval]*/ BSTR* pReaderWriterServiceList );
    STDMETHOD(get_SequenceNumber)( /*[out, retval]*/ LONG* pSequenceNumber );
    STDMETHOD(get_SettledAmount)( /*[out, retval]*/ CURRENCY* pSettledAmount );
    STDMETHOD(get_SettledPoint)( /*[out, retval]*/ CURRENCY* pSettledPoint );
    STDMETHOD(get_TransactionLog)( /*[out, retval]*/ BSTR* pTransactionLog );
    STDMETHOD(get_VoucherID)( /*[out, retval]*/ BSTR* pVoucherID );
    STDMETHOD(put_VoucherID)( /*[in]*/ BSTR VoucherID );
    STDMETHOD(get_VoucherIDList)( /*[out, retval]*/ BSTR* pVoucherIDList );
    STDMETHOD(put_VoucherIDList)( /*[in]*/ BSTR VoucherIDList );
    STDMETHOD(AccessLog)( 
        /*[in]*/ LONG SequenceNumber, 
        /*[in]*/ LONG Type, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ActivateService)( 
        /*[in, out]*/ LONG* pData, 
        /*[in, out]*/ BSTR* pObj, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(AddValue)( 
        /*[in]*/ LONG SequenceNumber, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginDetection)( 
        /*[in]*/ LONG Type, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginRemoval)( 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(CancelValue)( 
        /*[in]*/ LONG SequenceNumber, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(CaptureCard)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndDetection)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndRemoval)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EnumerateCardServices)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(LockTerminal)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ReadValue)( 
        /*[in]*/ LONG SequenceNumber, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SubtractValue)( 
        /*[in]*/ LONG SequenceNumber, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(TransactionAccess)( 
        /*[in]*/ LONG Control, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UnlockTerminal)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UpdateKey)( 
        /*[in, out]*/ LONG* pData, 
        /*[in, out]*/ BSTR* pObj, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(WriteValue)( 
        /*[in]*/ LONG SequenceNumber, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
// Release 1.13
// Release 1.14
    STDMETHOD(get_CapPINDevice)( /*[out, retval]*/ VARIANT_BOOL* pCapPINDevice );
    STDMETHOD(get_CapTrainingMode)( /*[out, retval]*/ VARIANT_BOOL* pCapTrainingMode );
    STDMETHOD(get_PINEntry)( /*[out, retval]*/ LONG* pPINEntry );
    STDMETHOD(put_PINEntry)( /*[in]*/ LONG PINEntry );
    STDMETHOD(get_TrainingModeState)( /*[out, retval]*/ LONG* pTrainingModeState );
    STDMETHOD(put_TrainingModeState)( /*[in]*/ LONG TrainingModeState );
    STDMETHOD(ClearParameterInformation)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(QueryLastSuccessfulTransactionResult)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(RetrieveResultInformation)( 
        /*[in]*/ BSTR Name, 
        /*[in, out]*/ BSTR* pValue, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetParameterInformation)( 
        /*[in]*/ BSTR Name, 
        /*[in]*/ BSTR Value, 
        /*[out, retval]*/ long* pRC );
// Release 1.15
    STDMETHOD(get_CapMembershipCertificate)( /*[out, retval]*/ VARIANT_BOOL* pCapMembershipCertificate );
    STDMETHOD(get_ServiceType)( /*[out, retval]*/ LONG* pServiceType );
    STDMETHOD(AccessData)( 
        /*[in]*/ LONG DataType, 
        /*[in, out]*/ LONG* pData, 
        /*[in, out]*/ BSTR* pObj, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ActivateEVService)( 
        /*[in, out]*/ LONG* pData, 
        /*[in, out]*/ BSTR* pObj, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(CheckServiceRegistrationToMedium)( 
        /*[in]*/ LONG SequenceNumber, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(CloseDailyEVService)( 
        /*[in, out]*/ LONG* pData, 
        /*[in, out]*/ BSTR* pObj, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(DeactivateEVService)( 
        /*[in, out]*/ LONG* pData, 
        /*[in, out]*/ BSTR* pObj, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(OpenDailyEVService)( 
        /*[in, out]*/ LONG* pData, 
        /*[in, out]*/ BSTR* pObj, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(RegisterServiceToMedium)( 
        /*[in]*/ LONG SequenceNumber, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UnregisterServiceToMedium)( 
        /*[in]*/ LONG SequenceNumber, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UpdateData)( 
        /*[in]*/ LONG DataType, 
        /*[in, out]*/ LONG* pData, 
        /*[in, out]*/ BSTR* pObj, 
        /*[out, retval]*/ long* pRC );
};

#endif //__ELECTRONICVALUERWIMPL_H__

// End ElectronicValueRWImpl.h
