/****************************************************************************
**
** FiscalPrinterImpl.h -- Main control header file.
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

#ifndef __FISCALPRINTERIMPL_H__
#define __FISCALPRINTERIMPL_H__


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
        #pragma message("===>>> Debug Build: Slow tracing to C:\\OposCCO_FiscalPrinter.log")
        #define DOTRACEV(x) WriteTrace x
        #define DODUMPV(x,y)            // Dump of non-ASCII data not implemented.
        #define TRACEINIT
        #define TRACEEXIT
    #else
        #pragma message("===>>> Debug Build: Fast tracing to OposCCO_FiscalPrinter.log")
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
#include "FiscalPrinterDefs.h"

// Standard includes...
#include "Resource.h"

// Include our variant class.
#include "OposVariant.h"

// Include our connection point implementation.
#include "FiscalPrinterCP.h"


/////////////////////////////////////////////////////////////////////////////
// Data.
/////////////////////////////////////////////////////////////////////////////

#define SO_DISP_COUNT 79
// Hidden window class and window name.
extern TCHAR g_WindowName[];
// Control Object description.
extern char  g_ControlDescription[];


/////////////////////////////////////////////////////////////////////////////
// Control class declaration.
/////////////////////////////////////////////////////////////////////////////

// The class...
class ATL_NO_VTABLE COPOSFiscalPrinter :
    // Inherit from all these classes...
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IOPOSFiscalPrinter, &IID_IOPOSFiscalPrinter, &LIBID_OposFiscalPrinter_CCO>,
    public CComControl<COPOSFiscalPrinter>,
    public IPersistStreamInitImpl<COPOSFiscalPrinter>,
    public IOleControlImpl<COPOSFiscalPrinter>,
    public IOleObjectImpl<COPOSFiscalPrinter>,
    public IOleInPlaceActiveObjectImpl<COPOSFiscalPrinter>,
    public IViewObjectExImpl<COPOSFiscalPrinter>,
    public IOleInPlaceObjectWindowlessImpl<COPOSFiscalPrinter>,
    public IConnectionPointContainerImpl<COPOSFiscalPrinter>,
    public IPersistStorageImpl<COPOSFiscalPrinter>,
    public ISpecifyPropertyPagesImpl<COPOSFiscalPrinter>,
    public IQuickActivateImpl<COPOSFiscalPrinter>,
    public IDataObjectImpl<COPOSFiscalPrinter>,
    public IProvideClassInfo2Impl<&CLSID_OPOSFiscalPrinter, &DIID__IOPOSFiscalPrinterEvents, &LIBID_OposFiscalPrinter_CCO>,
    public IObjectSafetyImpl<COPOSFiscalPrinter, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    public IPropertyNotifySinkCP<COPOSFiscalPrinter>,
    public CComCoClass<COPOSFiscalPrinter, &CLSID_OPOSFiscalPrinter>,
    public CProxy_IOPOSEvents< COPOSFiscalPrinter >
{
public:
// Constructor / FinalConstruct / Destructor.
    COPOSFiscalPrinter();
    HRESULT FinalConstruct();
    ~COPOSFiscalPrinter();

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
DECLARE_REGISTRY_RESOURCEID(IDR_OPOSFISCALPRINTER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

    // Define supported interfaces.
BEGIN_COM_MAP(COPOSFiscalPrinter)
    //  Map COM dispatch to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IOPOSFiscalPrinter)
    //   Map each COM interface to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IOPOSFiscalPrinter, IOPOSFiscalPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSFiscalPrinter_1_12, IOPOSFiscalPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSFiscalPrinter_1_11, IOPOSFiscalPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSFiscalPrinter_1_9, IOPOSFiscalPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSFiscalPrinter_1_8, IOPOSFiscalPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSFiscalPrinter_1_6, IOPOSFiscalPrinter)

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
BEGIN_PROP_MAP(COPOSFiscalPrinter)
    PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
    PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

    // Define connection points.
BEGIN_CONNECTION_POINT_MAP(COPOSFiscalPrinter)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    CONNECTION_POINT_ENTRY(DIID__IOPOSFiscalPrinterEvents)
END_CONNECTION_POINT_MAP()

    // Define message map.
BEGIN_MSG_MAP(COPOSFiscalPrinter)
    CHAIN_MSG_MAP(CComControl<COPOSFiscalPrinter>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

    // Define view status for IViewObjectEx to pass to container.
    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//===========================================================================
// Bring in all of the OPOS event firing code.
//===========================================================================

protected:
    #include "FiscalPrinterEvent.h"

//===========================================================================
// Control methods and property declarations.
//===========================================================================

public:
    STDMETHOD(SOProcessID)( /*[out, retval]*/ long* pProcessID );

// Release 1.3
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
    STDMETHOD(get_AmountDecimalPlaces)( /*[out, retval]*/ LONG* pAmountDecimalPlaces );
    STDMETHOD(get_AsyncMode)( /*[out, retval]*/ VARIANT_BOOL* pAsyncMode );
    STDMETHOD(put_AsyncMode)( /*[in]*/ VARIANT_BOOL AsyncMode );
    STDMETHOD(get_CapAdditionalLines)( /*[out, retval]*/ VARIANT_BOOL* pCapAdditionalLines );
    STDMETHOD(get_CapAmountAdjustment)( /*[out, retval]*/ VARIANT_BOOL* pCapAmountAdjustment );
    STDMETHOD(get_CapAmountNotPaid)( /*[out, retval]*/ VARIANT_BOOL* pCapAmountNotPaid );
    STDMETHOD(get_CapCheckTotal)( /*[out, retval]*/ VARIANT_BOOL* pCapCheckTotal );
    STDMETHOD(get_CapCoverSensor)( /*[out, retval]*/ VARIANT_BOOL* pCapCoverSensor );
    STDMETHOD(get_CapDoubleWidth)( /*[out, retval]*/ VARIANT_BOOL* pCapDoubleWidth );
    STDMETHOD(get_CapDuplicateReceipt)( /*[out, retval]*/ VARIANT_BOOL* pCapDuplicateReceipt );
    STDMETHOD(get_CapFixedOutput)( /*[out, retval]*/ VARIANT_BOOL* pCapFixedOutput );
    STDMETHOD(get_CapHasVatTable)( /*[out, retval]*/ VARIANT_BOOL* pCapHasVatTable );
    STDMETHOD(get_CapIndependentHeader)( /*[out, retval]*/ VARIANT_BOOL* pCapIndependentHeader );
    STDMETHOD(get_CapItemList)( /*[out, retval]*/ VARIANT_BOOL* pCapItemList );
    STDMETHOD(get_CapJrnEmptySensor)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnEmptySensor );
    STDMETHOD(get_CapJrnNearEndSensor)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnNearEndSensor );
    STDMETHOD(get_CapJrnPresent)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnPresent );
    STDMETHOD(get_CapNonFiscalMode)( /*[out, retval]*/ VARIANT_BOOL* pCapNonFiscalMode );
    STDMETHOD(get_CapOrderAdjustmentFirst)( /*[out, retval]*/ VARIANT_BOOL* pCapOrderAdjustmentFirst );
    STDMETHOD(get_CapPercentAdjustment)( /*[out, retval]*/ VARIANT_BOOL* pCapPercentAdjustment );
    STDMETHOD(get_CapPositiveAdjustment)( /*[out, retval]*/ VARIANT_BOOL* pCapPositiveAdjustment );
    STDMETHOD(get_CapPowerLossReport)( /*[out, retval]*/ VARIANT_BOOL* pCapPowerLossReport );
    STDMETHOD(get_CapPredefinedPaymentLines)( /*[out, retval]*/ VARIANT_BOOL* pCapPredefinedPaymentLines );
    STDMETHOD(get_CapReceiptNotPaid)( /*[out, retval]*/ VARIANT_BOOL* pCapReceiptNotPaid );
    STDMETHOD(get_CapRecEmptySensor)( /*[out, retval]*/ VARIANT_BOOL* pCapRecEmptySensor );
    STDMETHOD(get_CapRecNearEndSensor)( /*[out, retval]*/ VARIANT_BOOL* pCapRecNearEndSensor );
    STDMETHOD(get_CapRecPresent)( /*[out, retval]*/ VARIANT_BOOL* pCapRecPresent );
    STDMETHOD(get_CapRemainingFiscalMemory)( /*[out, retval]*/ VARIANT_BOOL* pCapRemainingFiscalMemory );
    STDMETHOD(get_CapReservedWord)( /*[out, retval]*/ VARIANT_BOOL* pCapReservedWord );
    STDMETHOD(get_CapSetHeader)( /*[out, retval]*/ VARIANT_BOOL* pCapSetHeader );
    STDMETHOD(get_CapSetPOSID)( /*[out, retval]*/ VARIANT_BOOL* pCapSetPOSID );
    STDMETHOD(get_CapSetStoreFiscalID)( /*[out, retval]*/ VARIANT_BOOL* pCapSetStoreFiscalID );
    STDMETHOD(get_CapSetTrailer)( /*[out, retval]*/ VARIANT_BOOL* pCapSetTrailer );
    STDMETHOD(get_CapSetVatTable)( /*[out, retval]*/ VARIANT_BOOL* pCapSetVatTable );
    STDMETHOD(get_CapSlpEmptySensor)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpEmptySensor );
    STDMETHOD(get_CapSlpFiscalDocument)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpFiscalDocument );
    STDMETHOD(get_CapSlpFullSlip)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpFullSlip );
    STDMETHOD(get_CapSlpNearEndSensor)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpNearEndSensor );
    STDMETHOD(get_CapSlpPresent)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpPresent );
    STDMETHOD(get_CapSlpValidation)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpValidation );
    STDMETHOD(get_CapSubAmountAdjustment)( /*[out, retval]*/ VARIANT_BOOL* pCapSubAmountAdjustment );
    STDMETHOD(get_CapSubPercentAdjustment)( /*[out, retval]*/ VARIANT_BOOL* pCapSubPercentAdjustment );
    STDMETHOD(get_CapSubtotal)( /*[out, retval]*/ VARIANT_BOOL* pCapSubtotal );
    STDMETHOD(get_CapTrainingMode)( /*[out, retval]*/ VARIANT_BOOL* pCapTrainingMode );
    STDMETHOD(get_CapValidateJournal)( /*[out, retval]*/ VARIANT_BOOL* pCapValidateJournal );
    STDMETHOD(get_CapXReport)( /*[out, retval]*/ VARIANT_BOOL* pCapXReport );
    STDMETHOD(get_CheckTotal)( /*[out, retval]*/ VARIANT_BOOL* pCheckTotal );
    STDMETHOD(put_CheckTotal)( /*[in]*/ VARIANT_BOOL CheckTotal );
    STDMETHOD(get_CountryCode)( /*[out, retval]*/ LONG* pCountryCode );
    STDMETHOD(get_CoverOpen)( /*[out, retval]*/ VARIANT_BOOL* pCoverOpen );
    STDMETHOD(get_DayOpened)( /*[out, retval]*/ VARIANT_BOOL* pDayOpened );
    STDMETHOD(get_DescriptionLength)( /*[out, retval]*/ LONG* pDescriptionLength );
    STDMETHOD(get_DuplicateReceipt)( /*[out, retval]*/ VARIANT_BOOL* pDuplicateReceipt );
    STDMETHOD(put_DuplicateReceipt)( /*[in]*/ VARIANT_BOOL DuplicateReceipt );
    STDMETHOD(get_ErrorLevel)( /*[out, retval]*/ LONG* pErrorLevel );
    STDMETHOD(get_ErrorOutID)( /*[out, retval]*/ LONG* pErrorOutID );
    STDMETHOD(get_ErrorState)( /*[out, retval]*/ LONG* pErrorState );
    STDMETHOD(get_ErrorStation)( /*[out, retval]*/ LONG* pErrorStation );
    STDMETHOD(get_ErrorString)( /*[out, retval]*/ BSTR* pErrorString );
    STDMETHOD(get_FlagWhenIdle)( /*[out, retval]*/ VARIANT_BOOL* pFlagWhenIdle );
    STDMETHOD(put_FlagWhenIdle)( /*[in]*/ VARIANT_BOOL FlagWhenIdle );
    STDMETHOD(get_JrnEmpty)( /*[out, retval]*/ VARIANT_BOOL* pJrnEmpty );
    STDMETHOD(get_JrnNearEnd)( /*[out, retval]*/ VARIANT_BOOL* pJrnNearEnd );
    STDMETHOD(get_MessageLength)( /*[out, retval]*/ LONG* pMessageLength );
    STDMETHOD(get_NumHeaderLines)( /*[out, retval]*/ LONG* pNumHeaderLines );
    STDMETHOD(get_NumTrailerLines)( /*[out, retval]*/ LONG* pNumTrailerLines );
    STDMETHOD(get_NumVatRates)( /*[out, retval]*/ LONG* pNumVatRates );
    STDMETHOD(get_PredefinedPaymentLines)( /*[out, retval]*/ BSTR* pPredefinedPaymentLines );
    STDMETHOD(get_PrinterState)( /*[out, retval]*/ LONG* pPrinterState );
    STDMETHOD(get_QuantityDecimalPlaces)( /*[out, retval]*/ LONG* pQuantityDecimalPlaces );
    STDMETHOD(get_QuantityLength)( /*[out, retval]*/ LONG* pQuantityLength );
    STDMETHOD(get_RecEmpty)( /*[out, retval]*/ VARIANT_BOOL* pRecEmpty );
    STDMETHOD(get_RecNearEnd)( /*[out, retval]*/ VARIANT_BOOL* pRecNearEnd );
    STDMETHOD(get_RemainingFiscalMemory)( /*[out, retval]*/ LONG* pRemainingFiscalMemory );
    STDMETHOD(get_ReservedWord)( /*[out, retval]*/ BSTR* pReservedWord );
    STDMETHOD(get_SlipSelection)( /*[out, retval]*/ LONG* pSlipSelection );
    STDMETHOD(put_SlipSelection)( /*[in]*/ LONG SlipSelection );
    STDMETHOD(get_SlpEmpty)( /*[out, retval]*/ VARIANT_BOOL* pSlpEmpty );
    STDMETHOD(get_SlpNearEnd)( /*[out, retval]*/ VARIANT_BOOL* pSlpNearEnd );
    STDMETHOD(get_TrainingModeActive)( /*[out, retval]*/ VARIANT_BOOL* pTrainingModeActive );
    STDMETHOD(BeginFiscalDocument)( 
        /*[in]*/ LONG DocumentAmount, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginFiscalReceipt)( 
        /*[in]*/ VARIANT_BOOL PrintHeader, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginFixedOutput)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ LONG DocumentType, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginInsertion)( 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginItemList)( 
        /*[in]*/ LONG VatID, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginNonFiscal)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginRemoval)( 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginTraining)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ClearError)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndFiscalDocument)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndFiscalReceipt)( 
        /*[in]*/ VARIANT_BOOL PrintHeader, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndFixedOutput)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndInsertion)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndItemList)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndNonFiscal)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndRemoval)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndTraining)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(GetData)( 
        /*[in]*/ LONG DataItem, 
        /*[out]*/ LONG* OptArgs, 
        /*[out]*/ BSTR* Data, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(GetDate)( 
        /*[out]*/ BSTR* Date, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(GetTotalizer)( 
        /*[in]*/ LONG VatID, 
        /*[in]*/ LONG OptArgs, 
        /*[out]*/ BSTR* Data, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(GetVatEntry)( 
        /*[in]*/ LONG VatID, 
        /*[in]*/ LONG OptArgs, 
        /*[out]*/ LONG* VatRate, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintDuplicateReceipt)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintFiscalDocumentLine)( 
        /*[in]*/ BSTR DocumentLine, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintFixedOutput)( 
        /*[in]*/ LONG DocumentType, 
        /*[in]*/ LONG LineNumber, 
        /*[in]*/ BSTR Data, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintNormal)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ BSTR Data, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintPeriodicTotalsReport)( 
        /*[in]*/ BSTR Date1, 
        /*[in]*/ BSTR Date2, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintPowerLossReport)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecItem)( 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Price, 
        /*[in]*/ LONG Quantity, 
        /*[in]*/ LONG VatInfo, 
        /*[in]*/ CURRENCY UnitPrice, 
        /*[in]*/ BSTR UnitName, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecItemAdjustment)( 
        /*[in]*/ LONG AdjustmentType, 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Amount, 
        /*[in]*/ LONG VatInfo, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecMessage)( 
        /*[in]*/ BSTR Message, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecNotPaid)( 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Amount, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecRefund)( 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Amount, 
        /*[in]*/ LONG VatInfo, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecSubtotal)( 
        /*[in]*/ CURRENCY Amount, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecSubtotalAdjustment)( 
        /*[in]*/ LONG AdjustmentType, 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Amount, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecTotal)( 
        /*[in]*/ CURRENCY Total, 
        /*[in]*/ CURRENCY Payment, 
        /*[in]*/ BSTR Description, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecVoid)( 
        /*[in]*/ BSTR Description, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecVoidItem)( 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Amount, 
        /*[in]*/ LONG Quantity, 
        /*[in]*/ LONG AdjustmentType, 
        /*[in]*/ CURRENCY Adjustment, 
        /*[in]*/ LONG VatInfo, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintReport)( 
        /*[in]*/ LONG ReportType, 
        /*[in]*/ BSTR StartNum, 
        /*[in]*/ BSTR EndNum, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintXReport)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintZReport)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ResetPrinter)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetDate)( 
        /*[in]*/ BSTR Date, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetHeaderLine)( 
        /*[in]*/ LONG LineNumber, 
        /*[in]*/ BSTR Text, 
        /*[in]*/ VARIANT_BOOL DoubleWidth, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetPOSID)( 
        /*[in]*/ BSTR POSID, 
        /*[in]*/ BSTR CashierID, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetStoreFiscalID)( 
        /*[in]*/ BSTR ID, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetTrailerLine)( 
        /*[in]*/ LONG LineNumber, 
        /*[in]*/ BSTR Text, 
        /*[in]*/ VARIANT_BOOL DoubleWidth, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetVatTable)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetVatValue)( 
        /*[in]*/ LONG VatID, 
        /*[in]*/ BSTR VatValue, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(VerifyItem)( 
        /*[in]*/ BSTR ItemName, 
        /*[in]*/ LONG VatID, 
        /*[out, retval]*/ long* pRC );
// Release 1.4
// Release 1.5
// Release 1.6
    STDMETHOD(get_ActualCurrency)( /*[out, retval]*/ LONG* pActualCurrency );
    STDMETHOD(get_AdditionalHeader)( /*[out, retval]*/ BSTR* pAdditionalHeader );
    STDMETHOD(put_AdditionalHeader)( /*[in]*/ BSTR AdditionalHeader );
    STDMETHOD(get_AdditionalTrailer)( /*[out, retval]*/ BSTR* pAdditionalTrailer );
    STDMETHOD(put_AdditionalTrailer)( /*[in]*/ BSTR AdditionalTrailer );
    STDMETHOD(get_CapAdditionalHeader)( /*[out, retval]*/ VARIANT_BOOL* pCapAdditionalHeader );
    STDMETHOD(get_CapAdditionalTrailer)( /*[out, retval]*/ VARIANT_BOOL* pCapAdditionalTrailer );
    STDMETHOD(get_CapChangeDue)( /*[out, retval]*/ VARIANT_BOOL* pCapChangeDue );
    STDMETHOD(get_CapEmptyReceiptIsVoidable)( /*[out, retval]*/ VARIANT_BOOL* pCapEmptyReceiptIsVoidable );
    STDMETHOD(get_CapFiscalReceiptStation)( /*[out, retval]*/ VARIANT_BOOL* pCapFiscalReceiptStation );
    STDMETHOD(get_CapFiscalReceiptType)( /*[out, retval]*/ VARIANT_BOOL* pCapFiscalReceiptType );
    STDMETHOD(get_CapMultiContractor)( /*[out, retval]*/ VARIANT_BOOL* pCapMultiContractor );
    STDMETHOD(get_CapOnlyVoidLastItem)( /*[out, retval]*/ VARIANT_BOOL* pCapOnlyVoidLastItem );
    STDMETHOD(get_CapPackageAdjustment)( /*[out, retval]*/ VARIANT_BOOL* pCapPackageAdjustment );
    STDMETHOD(get_CapPostPreLine)( /*[out, retval]*/ VARIANT_BOOL* pCapPostPreLine );
    STDMETHOD(get_CapSetCurrency)( /*[out, retval]*/ VARIANT_BOOL* pCapSetCurrency );
    STDMETHOD(get_CapTotalizerType)( /*[out, retval]*/ VARIANT_BOOL* pCapTotalizerType );
    STDMETHOD(get_ChangeDue)( /*[out, retval]*/ BSTR* pChangeDue );
    STDMETHOD(put_ChangeDue)( /*[in]*/ BSTR ChangeDue );
    STDMETHOD(get_ContractorId)( /*[out, retval]*/ LONG* pContractorId );
    STDMETHOD(put_ContractorId)( /*[in]*/ LONG ContractorId );
    STDMETHOD(get_DateType)( /*[out, retval]*/ LONG* pDateType );
    STDMETHOD(put_DateType)( /*[in]*/ LONG DateType );
    STDMETHOD(get_FiscalReceiptStation)( /*[out, retval]*/ LONG* pFiscalReceiptStation );
    STDMETHOD(put_FiscalReceiptStation)( /*[in]*/ LONG FiscalReceiptStation );
    STDMETHOD(get_FiscalReceiptType)( /*[out, retval]*/ LONG* pFiscalReceiptType );
    STDMETHOD(put_FiscalReceiptType)( /*[in]*/ LONG FiscalReceiptType );
    STDMETHOD(get_MessageType)( /*[out, retval]*/ LONG* pMessageType );
    STDMETHOD(put_MessageType)( /*[in]*/ LONG MessageType );
    STDMETHOD(get_PostLine)( /*[out, retval]*/ BSTR* pPostLine );
    STDMETHOD(put_PostLine)( /*[in]*/ BSTR PostLine );
    STDMETHOD(get_PreLine)( /*[out, retval]*/ BSTR* pPreLine );
    STDMETHOD(put_PreLine)( /*[in]*/ BSTR PreLine );
    STDMETHOD(get_TotalizerType)( /*[out, retval]*/ LONG* pTotalizerType );
    STDMETHOD(put_TotalizerType)( /*[in]*/ LONG TotalizerType );
    STDMETHOD(PrintRecCash)( 
        /*[in]*/ CURRENCY Amount, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecItemFuel)( 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Price, 
        /*[in]*/ LONG Quantity, 
        /*[in]*/ LONG VatInfo, 
        /*[in]*/ CURRENCY UnitPrice, 
        /*[in]*/ BSTR UnitName, 
        /*[in]*/ CURRENCY SpecialTax, 
        /*[in]*/ BSTR SpecialTaxName, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecItemFuelVoid)( 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Price, 
        /*[in]*/ LONG VatInfo, 
        /*[in]*/ CURRENCY SpecialTax, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecPackageAdjustment)( 
        /*[in]*/ LONG AdjustmentType, 
        /*[in]*/ BSTR Description, 
        /*[in]*/ BSTR VatAdjustment, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecPackageAdjustVoid)( 
        /*[in]*/ LONG AdjustmentType, 
        /*[in]*/ BSTR VatAdjustment, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecRefundVoid)( 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Amount, 
        /*[in]*/ LONG VatInfo, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecSubtotalAdjustVoid)( 
        /*[in]*/ LONG AdjustmentType, 
        /*[in]*/ CURRENCY Amount, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecTaxID)( 
        /*[in]*/ BSTR TaxID, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetCurrency)( 
        /*[in]*/ LONG NewCurrency, 
        /*[out, retval]*/ long* pRC );
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
// Release 1.10
// Release 1.11
    STDMETHOD(get_CapPositiveSubtotalAdjustment)( /*[out, retval]*/ VARIANT_BOOL* pCapPositiveSubtotalAdjustment );
    STDMETHOD(PrintRecItemAdjustmentVoid)( 
        /*[in]*/ LONG AdjustmentType, 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Amount, 
        /*[in]*/ LONG VatInfo, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecItemVoid)( 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Price, 
        /*[in]*/ LONG Quantity, 
        /*[in]*/ LONG VatInfo, 
        /*[in]*/ CURRENCY UnitPrice, 
        /*[in]*/ BSTR UnitName, 
        /*[out, retval]*/ long* pRC );
// Release 1.12
    STDMETHOD(PrintRecItemRefund)( 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Amount, 
        /*[in]*/ LONG Quantity, 
        /*[in]*/ LONG VatInfo, 
        /*[in]*/ CURRENCY UnitAmount, 
        /*[in]*/ BSTR UnitName, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintRecItemRefundVoid)( 
        /*[in]*/ BSTR Description, 
        /*[in]*/ CURRENCY Amount, 
        /*[in]*/ LONG Quantity, 
        /*[in]*/ LONG VatInfo, 
        /*[in]*/ CURRENCY UnitAmount, 
        /*[in]*/ BSTR UnitName, 
        /*[out, retval]*/ long* pRC );
// Release 1.13
// Release 1.14
};

#endif //__FISCALPRINTERIMPL_H__

// End FiscalPrinterImpl.h
