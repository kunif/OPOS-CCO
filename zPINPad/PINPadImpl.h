/****************************************************************************
**
** PINPadImpl.h -- Main control header file.
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

#ifndef __PINPADIMPL_H__
#define __PINPADIMPL_H__


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
        #pragma message("===>>> Debug Build: Slow tracing to C:\\OposCCO_PINPad.log")
        #define DOTRACEV(x) WriteTrace x
        #define DODUMPV(x,y)            // Dump of non-ASCII data not implemented.
        #define TRACEINIT
        #define TRACEEXIT
    #else
        #pragma message("===>>> Debug Build: Fast tracing to OposCCO_PINPad.log")
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
#include "PINPadDefs.h"

// Standard includes...
#include "Resource.h"

// Include our variant class.
#include "OposVariant.h"

// Include our connection point implementation.
#include "PINPadCP.h"


/////////////////////////////////////////////////////////////////////////////
// Data.
/////////////////////////////////////////////////////////////////////////////

#define SO_DISP_COUNT 26
// Hidden window class and window name.
extern TCHAR g_WindowName[];
// Control Object description.
extern char  g_ControlDescription[];


/////////////////////////////////////////////////////////////////////////////
// Control class declaration.
/////////////////////////////////////////////////////////////////////////////

// The class...
class ATL_NO_VTABLE COPOSPINPad :
    // Inherit from all these classes...
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IOPOSPINPad, &IID_IOPOSPINPad, &LIBID_OposPINPad_CCO>,
    public CComControl<COPOSPINPad>,
    public IPersistStreamInitImpl<COPOSPINPad>,
    public IOleControlImpl<COPOSPINPad>,
    public IOleObjectImpl<COPOSPINPad>,
    public IOleInPlaceActiveObjectImpl<COPOSPINPad>,
    public IViewObjectExImpl<COPOSPINPad>,
    public IOleInPlaceObjectWindowlessImpl<COPOSPINPad>,
    public IConnectionPointContainerImpl<COPOSPINPad>,
    public IPersistStorageImpl<COPOSPINPad>,
    public ISpecifyPropertyPagesImpl<COPOSPINPad>,
    public IQuickActivateImpl<COPOSPINPad>,
    public IDataObjectImpl<COPOSPINPad>,
    public IProvideClassInfo2Impl<&CLSID_OPOSPINPad, &DIID__IOPOSPINPadEvents, &LIBID_OposPINPad_CCO>,
    public IObjectSafetyImpl<COPOSPINPad, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    public IPropertyNotifySinkCP<COPOSPINPad>,
    public CComCoClass<COPOSPINPad, &CLSID_OPOSPINPad>,
    public CProxy_IOPOSEvents< COPOSPINPad >
{
public:
// Constructor / FinalConstruct / Destructor.
    COPOSPINPad();
    HRESULT FinalConstruct();
    ~COPOSPINPad();

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
DECLARE_REGISTRY_RESOURCEID(IDR_OPOSPINPAD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

    // Define supported interfaces.
BEGIN_COM_MAP(COPOSPINPad)
    //  Map COM dispatch to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IOPOSPINPad)
    //   Map each COM interface to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPINPad, IOPOSPINPad)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPINPad_1_10, IOPOSPINPad)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPINPad_1_9, IOPOSPINPad)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPINPad_1_8, IOPOSPINPad)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPINPad_1_5, IOPOSPINPad)

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
BEGIN_PROP_MAP(COPOSPINPad)
    PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
    PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

    // Define connection points.
BEGIN_CONNECTION_POINT_MAP(COPOSPINPad)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    CONNECTION_POINT_ENTRY(DIID__IOPOSPINPadEvents)
END_CONNECTION_POINT_MAP()

    // Define message map.
BEGIN_MSG_MAP(COPOSPINPad)
    CHAIN_MSG_MAP(CComControl<COPOSPINPad>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

    // Define view status for IViewObjectEx to pass to container.
    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//===========================================================================
// Bring in all of the OPOS event firing code.
//===========================================================================

protected:
    #include "PINPadEvent.h"

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
    STDMETHOD(get_DataCount)( /*[out, retval]*/ LONG* pDataCount );
    STDMETHOD(get_DataEventEnabled)( /*[out, retval]*/ VARIANT_BOOL* pDataEventEnabled );
    STDMETHOD(put_DataEventEnabled)( /*[in]*/ VARIANT_BOOL DataEventEnabled );
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
    STDMETHOD(get_AccountNumber)( /*[out, retval]*/ BSTR* pAccountNumber );
    STDMETHOD(put_AccountNumber)( /*[in]*/ BSTR AccountNumber );
    STDMETHOD(get_AdditionalSecurityInformation)( /*[out, retval]*/ BSTR* pAdditionalSecurityInformation );
    STDMETHOD(get_Amount)( /*[out, retval]*/ CURRENCY* pAmount );
    STDMETHOD(put_Amount)( /*[in]*/ CURRENCY Amount );
    STDMETHOD(get_AvailableLanguagesList)( /*[out, retval]*/ BSTR* pAvailableLanguagesList );
    STDMETHOD(get_AvailablePromptsList)( /*[out, retval]*/ BSTR* pAvailablePromptsList );
    STDMETHOD(get_CapDisplay)( /*[out, retval]*/ LONG* pCapDisplay );
    STDMETHOD(get_CapKeyboard)( /*[out, retval]*/ VARIANT_BOOL* pCapKeyboard );
    STDMETHOD(get_CapLanguage)( /*[out, retval]*/ LONG* pCapLanguage );
    STDMETHOD(get_CapMACCalculation)( /*[out, retval]*/ VARIANT_BOOL* pCapMACCalculation );
    STDMETHOD(get_CapTone)( /*[out, retval]*/ VARIANT_BOOL* pCapTone );
    STDMETHOD(get_EncryptedPIN)( /*[out, retval]*/ BSTR* pEncryptedPIN );
    STDMETHOD(get_MaximumPINLength)( /*[out, retval]*/ LONG* pMaximumPINLength );
    STDMETHOD(put_MaximumPINLength)( /*[in]*/ LONG MaximumPINLength );
    STDMETHOD(get_MerchantID)( /*[out, retval]*/ BSTR* pMerchantID );
    STDMETHOD(put_MerchantID)( /*[in]*/ BSTR MerchantID );
    STDMETHOD(get_MinimumPINLength)( /*[out, retval]*/ LONG* pMinimumPINLength );
    STDMETHOD(put_MinimumPINLength)( /*[in]*/ LONG MinimumPINLength );
    STDMETHOD(get_PINEntryEnabled)( /*[out, retval]*/ VARIANT_BOOL* pPINEntryEnabled );
    STDMETHOD(get_Prompt)( /*[out, retval]*/ LONG* pPrompt );
    STDMETHOD(put_Prompt)( /*[in]*/ LONG Prompt );
    STDMETHOD(get_PromptLanguage)( /*[out, retval]*/ LONG* pPromptLanguage );
    STDMETHOD(put_PromptLanguage)( /*[in]*/ LONG PromptLanguage );
    STDMETHOD(get_TerminalID)( /*[out, retval]*/ BSTR* pTerminalID );
    STDMETHOD(put_TerminalID)( /*[in]*/ BSTR TerminalID );
    STDMETHOD(get_Track1Data)( /*[out, retval]*/ BSTR* pTrack1Data );
    STDMETHOD(put_Track1Data)( /*[in]*/ BSTR Track1Data );
    STDMETHOD(get_Track2Data)( /*[out, retval]*/ BSTR* pTrack2Data );
    STDMETHOD(put_Track2Data)( /*[in]*/ BSTR Track2Data );
    STDMETHOD(get_Track3Data)( /*[out, retval]*/ BSTR* pTrack3Data );
    STDMETHOD(put_Track3Data)( /*[in]*/ BSTR Track3Data );
    STDMETHOD(get_TransactionType)( /*[out, retval]*/ LONG* pTransactionType );
    STDMETHOD(put_TransactionType)( /*[in]*/ LONG TransactionType );
    STDMETHOD(BeginEFTTransaction)( 
        /*[in]*/ BSTR PINPadSystem, 
        /*[in]*/ LONG TransactionHost, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ComputeMAC)( 
        /*[in]*/ BSTR InMsg, 
        /*[out]*/ BSTR* pOutMsg, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EnablePINEntry)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndEFTTransaction)( 
        /*[in]*/ LONG CompletionCode, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UpdateKey)( 
        /*[in]*/ LONG KeyNum, 
        /*[in]*/ BSTR Key, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(VerifyMAC)( 
        /*[in]*/ BSTR Message, 
        /*[out, retval]*/ long* pRC );
// Release 1.4
// Release 1.5
    STDMETHOD(get_Track4Data)( /*[out, retval]*/ BSTR* pTrack4Data );
    STDMETHOD(put_Track4Data)( /*[in]*/ BSTR Track4Data );
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
// Release 1.10
    STDMETHOD(ClearInputProperties)( 
        /*[out, retval]*/ long* pRC );
// Release 1.11
// Release 1.12
// Release 1.13
// Release 1.14
};

#endif //__PINPADIMPL_H__

// End PINPadImpl.h
