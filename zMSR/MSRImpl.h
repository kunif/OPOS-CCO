/****************************************************************************
**
** MSRImpl.h -- Main control header file.
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

#ifndef __MSRIMPL_H__
#define __MSRIMPL_H__


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
        #pragma message("===>>> Debug Build: Slow tracing to C:\\OposCCO_MSR.log")
        #define DOTRACEV(x) WriteTrace x
        #define DODUMPV(x,y)            // Dump of non-ASCII data not implemented.
        #define TRACEINIT
        #define TRACEEXIT
    #else
        #pragma message("===>>> Debug Build: Fast tracing to OposCCO_MSR.log")
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
#include "MSRDefs.h"

// Standard includes...
#include "Resource.h"

// Include our variant class.
#include "OposVariant.h"

// Include our connection point implementation.
#include "MSRCP.h"


/////////////////////////////////////////////////////////////////////////////
// Data.
/////////////////////////////////////////////////////////////////////////////

#define SO_DISP_COUNT 24
// Hidden window class and window name.
extern TCHAR g_WindowName[];
// Control Object description.
extern char  g_ControlDescription[];


/////////////////////////////////////////////////////////////////////////////
// Control class declaration.
/////////////////////////////////////////////////////////////////////////////

// The class...
class ATL_NO_VTABLE COPOSMSR :
    // Inherit from all these classes...
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IOPOSMSR, &IID_IOPOSMSR, &LIBID_OposMSR_CCO>,
    public CComControl<COPOSMSR>,
    public IPersistStreamInitImpl<COPOSMSR>,
    public IOleControlImpl<COPOSMSR>,
    public IOleObjectImpl<COPOSMSR>,
    public IOleInPlaceActiveObjectImpl<COPOSMSR>,
    public IViewObjectExImpl<COPOSMSR>,
    public IOleInPlaceObjectWindowlessImpl<COPOSMSR>,
    public IConnectionPointContainerImpl<COPOSMSR>,
    public IPersistStorageImpl<COPOSMSR>,
    public ISpecifyPropertyPagesImpl<COPOSMSR>,
    public IQuickActivateImpl<COPOSMSR>,
    public IDataObjectImpl<COPOSMSR>,
    public IProvideClassInfo2Impl<&CLSID_OPOSMSR, &DIID__IOPOSMSREvents, &LIBID_OposMSR_CCO>,
    public IObjectSafetyImpl<COPOSMSR, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    public IPropertyNotifySinkCP<COPOSMSR>,
    public CComCoClass<COPOSMSR, &CLSID_OPOSMSR>,
    public CProxy_IOPOSEvents< COPOSMSR >
{
public:
// Constructor / FinalConstruct / Destructor.
    COPOSMSR();
    HRESULT FinalConstruct();
    ~COPOSMSR();

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
DECLARE_REGISTRY_RESOURCEID(IDR_OPOSMSR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

    // Define supported interfaces.
BEGIN_COM_MAP(COPOSMSR)
    //  Map COM dispatch to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IOPOSMSR)
    //   Map each COM interface to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IOPOSMSR, IOPOSMSR)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSMSR_1_12, IOPOSMSR)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSMSR_1_10, IOPOSMSR)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSMSR_1_9, IOPOSMSR)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSMSR_1_8, IOPOSMSR)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSMSR_1_5, IOPOSMSR)

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
BEGIN_PROP_MAP(COPOSMSR)
    PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
    PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

    // Define connection points.
BEGIN_CONNECTION_POINT_MAP(COPOSMSR)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    CONNECTION_POINT_ENTRY(DIID__IOPOSMSREvents)
END_CONNECTION_POINT_MAP()

    // Define message map.
BEGIN_MSG_MAP(COPOSMSR)
    CHAIN_MSG_MAP(CComControl<COPOSMSR>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

    // Define view status for IViewObjectEx to pass to container.
    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//===========================================================================
// Bring in all of the OPOS event firing code.
//===========================================================================

protected:
    #include "MSREvent.h"

//===========================================================================
// Control methods and property declarations.
//===========================================================================

public:
    STDMETHOD(SOProcessID)( /*[out, retval]*/ long* pProcessID );

// Release 1.0
    STDMETHOD(get_OpenResult)( /*[out, retval]*/ LONG* pOpenResult );
    STDMETHOD(get_CheckHealthText)( /*[out, retval]*/ BSTR* pCheckHealthText );
    STDMETHOD(get_Claimed)( /*[out, retval]*/ VARIANT_BOOL* pClaimed );
    STDMETHOD(get_DataEventEnabled)( /*[out, retval]*/ VARIANT_BOOL* pDataEventEnabled );
    STDMETHOD(put_DataEventEnabled)( /*[in]*/ VARIANT_BOOL DataEventEnabled );
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
    STDMETHOD(get_CapISO)( /*[out, retval]*/ VARIANT_BOOL* pCapISO );
    STDMETHOD(get_CapJISOne)( /*[out, retval]*/ VARIANT_BOOL* pCapJISOne );
    STDMETHOD(get_CapJISTwo)( /*[out, retval]*/ VARIANT_BOOL* pCapJISTwo );
    STDMETHOD(get_DecodeData)( /*[out, retval]*/ VARIANT_BOOL* pDecodeData );
    STDMETHOD(put_DecodeData)( /*[in]*/ VARIANT_BOOL DecodeData );
    STDMETHOD(get_ExpirationDate)( /*[out, retval]*/ BSTR* pExpirationDate );
    STDMETHOD(get_FirstName)( /*[out, retval]*/ BSTR* pFirstName );
    STDMETHOD(get_MiddleInitial)( /*[out, retval]*/ BSTR* pMiddleInitial );
    STDMETHOD(get_ParseDecodeData)( /*[out, retval]*/ VARIANT_BOOL* pParseDecodeData );
    STDMETHOD(put_ParseDecodeData)( /*[in]*/ VARIANT_BOOL ParseDecodeData );
    STDMETHOD(get_ParseDecodedData)( /*[out, retval]*/ VARIANT_BOOL* pParseDecodedData );
    STDMETHOD(put_ParseDecodedData)( /*[in]*/ VARIANT_BOOL ParseDecodedData );
    STDMETHOD(get_ServiceCode)( /*[out, retval]*/ BSTR* pServiceCode );
    STDMETHOD(get_Suffix)( /*[out, retval]*/ BSTR* pSuffix );
    STDMETHOD(get_Surname)( /*[out, retval]*/ BSTR* pSurname );
    STDMETHOD(get_Title)( /*[out, retval]*/ BSTR* pTitle );
    STDMETHOD(get_Track1Data)( /*[out, retval]*/ BSTR* pTrack1Data );
    STDMETHOD(get_Track1DiscretionaryData)( /*[out, retval]*/ BSTR* pTrack1DiscretionaryData );
    STDMETHOD(get_Track2Data)( /*[out, retval]*/ BSTR* pTrack2Data );
    STDMETHOD(get_Track2DiscretionaryData)( /*[out, retval]*/ BSTR* pTrack2DiscretionaryData );
    STDMETHOD(get_Track3Data)( /*[out, retval]*/ BSTR* pTrack3Data );
    STDMETHOD(get_TracksToRead)( /*[out, retval]*/ LONG* pTracksToRead );
    STDMETHOD(put_TracksToRead)( /*[in]*/ LONG TracksToRead );
// Release 1.1
// Release 1.2
    STDMETHOD(get_AutoDisable)( /*[out, retval]*/ VARIANT_BOOL* pAutoDisable );
    STDMETHOD(put_AutoDisable)( /*[in]*/ VARIANT_BOOL AutoDisable );
    STDMETHOD(get_BinaryConversion)( /*[out, retval]*/ LONG* pBinaryConversion );
    STDMETHOD(put_BinaryConversion)( /*[in]*/ LONG BinaryConversion );
    STDMETHOD(get_DataCount)( /*[out, retval]*/ LONG* pDataCount );
    STDMETHOD(get_ErrorReportingType)( /*[out, retval]*/ LONG* pErrorReportingType );
    STDMETHOD(put_ErrorReportingType)( /*[in]*/ LONG ErrorReportingType );
// Release 1.3
    STDMETHOD(get_CapPowerReporting)( /*[out, retval]*/ LONG* pCapPowerReporting );
    STDMETHOD(get_PowerNotify)( /*[out, retval]*/ LONG* pPowerNotify );
    STDMETHOD(put_PowerNotify)( /*[in]*/ LONG PowerNotify );
    STDMETHOD(get_PowerState)( /*[out, retval]*/ LONG* pPowerState );
// Release 1.4
// Release 1.5
    STDMETHOD(get_CapTransmitSentinels)( /*[out, retval]*/ VARIANT_BOOL* pCapTransmitSentinels );
    STDMETHOD(get_Track4Data)( /*[out, retval]*/ BSTR* pTrack4Data );
    STDMETHOD(get_TransmitSentinels)( /*[out, retval]*/ VARIANT_BOOL* pTransmitSentinels );
    STDMETHOD(put_TransmitSentinels)( /*[in]*/ VARIANT_BOOL TransmitSentinels );
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
    STDMETHOD(get_CapWritableTracks)( /*[out, retval]*/ LONG* pCapWritableTracks );
    STDMETHOD(get_EncodingMaxLength)( /*[out, retval]*/ LONG* pEncodingMaxLength );
    STDMETHOD(get_TracksToWrite)( /*[out, retval]*/ LONG* pTracksToWrite );
    STDMETHOD(put_TracksToWrite)( /*[in]*/ LONG TracksToWrite );
    STDMETHOD(WriteTracks)( 
        /*[in]*/ VARIANT /*(SAFEARRAY of BSTR = Type VT_BSTR|VT_ARRAY)*/ Data, 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
// Release 1.11
// Release 1.12
    STDMETHOD(get_AdditionalSecurityInformation)( /*[out, retval]*/ BSTR* pAdditionalSecurityInformation );
    STDMETHOD(get_CapCardAuthentication)( /*[out, retval]*/ BSTR* pCapCardAuthentication );
    STDMETHOD(get_CapDataEncryption)( /*[out, retval]*/ LONG* pCapDataEncryption );
    STDMETHOD(get_CapDeviceAuthentication)( /*[out, retval]*/ LONG* pCapDeviceAuthentication );
    STDMETHOD(get_CapTrackDataMasking)( /*[out, retval]*/ VARIANT_BOOL* pCapTrackDataMasking );
    STDMETHOD(get_CardAuthenticationData)( /*[out, retval]*/ BSTR* pCardAuthenticationData );
    STDMETHOD(get_CardAuthenticationDataLength)( /*[out, retval]*/ LONG* pCardAuthenticationDataLength );
    STDMETHOD(get_CardPropertyList)( /*[out, retval]*/ BSTR* pCardPropertyList );
    STDMETHOD(get_CardType)( /*[out, retval]*/ BSTR* pCardType );
    STDMETHOD(get_CardTypeList)( /*[out, retval]*/ BSTR* pCardTypeList );
    STDMETHOD(get_DataEncryptionAlgorithm)( /*[out, retval]*/ LONG* pDataEncryptionAlgorithm );
    STDMETHOD(put_DataEncryptionAlgorithm)( /*[in]*/ LONG DataEncryptionAlgorithm );
    STDMETHOD(get_DeviceAuthenticated)( /*[out, retval]*/ VARIANT_BOOL* pDeviceAuthenticated );
    STDMETHOD(get_DeviceAuthenticationProtocol)( /*[out, retval]*/ LONG* pDeviceAuthenticationProtocol );
    STDMETHOD(get_Track1EncryptedData)( /*[out, retval]*/ BSTR* pTrack1EncryptedData );
    STDMETHOD(get_Track1EncryptedDataLength)( /*[out, retval]*/ LONG* pTrack1EncryptedDataLength );
    STDMETHOD(get_Track2EncryptedData)( /*[out, retval]*/ BSTR* pTrack2EncryptedData );
    STDMETHOD(get_Track2EncryptedDataLength)( /*[out, retval]*/ LONG* pTrack2EncryptedDataLength );
    STDMETHOD(get_Track3EncryptedData)( /*[out, retval]*/ BSTR* pTrack3EncryptedData );
    STDMETHOD(get_Track3EncryptedDataLength)( /*[out, retval]*/ LONG* pTrack3EncryptedDataLength );
    STDMETHOD(get_Track4EncryptedData)( /*[out, retval]*/ BSTR* pTrack4EncryptedData );
    STDMETHOD(get_Track4EncryptedDataLength)( /*[out, retval]*/ LONG* pTrack4EncryptedDataLength );
    STDMETHOD(get_WriteCardType)( /*[out, retval]*/ BSTR* pWriteCardType );
    STDMETHOD(put_WriteCardType)( /*[in]*/ BSTR WriteCardType );
    STDMETHOD(AuthenticateDevice)( 
        /*[in]*/ BSTR Response, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(DeauthenticateDevice)( 
        /*[in]*/ BSTR Response, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(RetrieveCardProperty)( 
        /*[in]*/ BSTR Name, 
        /*[out]*/ BSTR* pValue, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(RetrieveDeviceAuthenticationData)( 
        /*[in, out]*/ BSTR* pChallenge, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(UpdateKey)( 
        /*[in]*/ BSTR Key, 
        /*[in]*/ BSTR KeyName, 
        /*[out, retval]*/ long* pRC );
// Release 1.13
// Release 1.14
};

#endif //__MSRIMPL_H__

// End MSRImpl.h
