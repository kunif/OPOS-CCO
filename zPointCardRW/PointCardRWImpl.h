/****************************************************************************
**
** PointCardRWImpl.h -- Main control header file.
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

#ifndef __POINTCARDRWIMPL_H__
#define __POINTCARDRWIMPL_H__


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
        #pragma message("===>>> Debug Build: Slow tracing to C:\\OposCCO_PointCardRW.log")
        #define DOTRACEV(x) WriteTrace x
        #define DODUMPV(x,y)            // Dump of non-ASCII data not implemented.
        #define TRACEINIT
        #define TRACEEXIT
    #else
        #pragma message("===>>> Debug Build: Fast tracing to OposCCO_PointCardRW.log")
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
#include "PointCardRWDefs.h"

// Standard includes...
#include "Resource.h"

// Include our variant class.
#include "OposVariant.h"

// Include our connection point implementation.
#include "PointCardRWCP.h"


/////////////////////////////////////////////////////////////////////////////
// Data.
/////////////////////////////////////////////////////////////////////////////

#define SO_DISP_COUNT 28
// Hidden window class and window name.
extern TCHAR g_WindowName[];
// Control Object description.
extern char  g_ControlDescription[];


/////////////////////////////////////////////////////////////////////////////
// Control class declaration.
/////////////////////////////////////////////////////////////////////////////

// The class...
class ATL_NO_VTABLE COPOSPointCardRW :
    // Inherit from all these classes...
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IOPOSPointCardRW, &IID_IOPOSPointCardRW, &LIBID_OposPointCardRW_CCO>,
    public CComControl<COPOSPointCardRW>,
    public IPersistStreamInitImpl<COPOSPointCardRW>,
    public IOleControlImpl<COPOSPointCardRW>,
    public IOleObjectImpl<COPOSPointCardRW>,
    public IOleInPlaceActiveObjectImpl<COPOSPointCardRW>,
    public IViewObjectExImpl<COPOSPointCardRW>,
    public IOleInPlaceObjectWindowlessImpl<COPOSPointCardRW>,
    public IConnectionPointContainerImpl<COPOSPointCardRW>,
    public IPersistStorageImpl<COPOSPointCardRW>,
    public ISpecifyPropertyPagesImpl<COPOSPointCardRW>,
    public IQuickActivateImpl<COPOSPointCardRW>,
    public IDataObjectImpl<COPOSPointCardRW>,
    public IProvideClassInfo2Impl<&CLSID_OPOSPointCardRW, &DIID__IOPOSPointCardRWEvents, &LIBID_OposPointCardRW_CCO>,
    public IObjectSafetyImpl<COPOSPointCardRW, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    public IPropertyNotifySinkCP<COPOSPointCardRW>,
    public CComCoClass<COPOSPointCardRW, &CLSID_OPOSPointCardRW>,
    public CProxy_IOPOSEvents< COPOSPointCardRW >
{
public:
// Constructor / FinalConstruct / Destructor.
    COPOSPointCardRW();
    HRESULT FinalConstruct();
    ~COPOSPointCardRW();

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
DECLARE_REGISTRY_RESOURCEID(IDR_OPOSPOINTCARDRW)

DECLARE_PROTECT_FINAL_CONSTRUCT()

    // Define supported interfaces.
BEGIN_COM_MAP(COPOSPointCardRW)
    //  Map COM dispatch to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IOPOSPointCardRW)
    //   Map each COM interface to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPointCardRW, IOPOSPointCardRW)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPointCardRW_1_10, IOPOSPointCardRW)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPointCardRW_1_9, IOPOSPointCardRW)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPointCardRW_1_8, IOPOSPointCardRW)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPointCardRW_1_7, IOPOSPointCardRW)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPointCardRW_1_5, IOPOSPointCardRW)

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
BEGIN_PROP_MAP(COPOSPointCardRW)
    PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
    PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

    // Define connection points.
BEGIN_CONNECTION_POINT_MAP(COPOSPointCardRW)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    CONNECTION_POINT_ENTRY(DIID__IOPOSPointCardRWEvents)
END_CONNECTION_POINT_MAP()

    // Define message map.
BEGIN_MSG_MAP(COPOSPointCardRW)
    CHAIN_MSG_MAP(CComControl<COPOSPointCardRW>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

    // Define view status for IViewObjectEx to pass to container.
    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//===========================================================================
// Bring in all of the OPOS event firing code.
//===========================================================================

protected:
    #include "PointCardRWEvent.h"

//===========================================================================
// Control methods and property declarations.
//===========================================================================

public:
    STDMETHOD(SOProcessID)( /*[out, retval]*/ long* pProcessID );

// Release 1.5
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
    STDMETHOD(get_CapBold)( /*[out, retval]*/ VARIANT_BOOL* pCapBold );
    STDMETHOD(get_CapCardEntranceSensor)( /*[out, retval]*/ VARIANT_BOOL* pCapCardEntranceSensor );
    STDMETHOD(get_CapCharacterSet)( /*[out, retval]*/ LONG* pCapCharacterSet );
    STDMETHOD(get_CapCleanCard)( /*[out, retval]*/ VARIANT_BOOL* pCapCleanCard );
    STDMETHOD(get_CapClearPrint)( /*[out, retval]*/ VARIANT_BOOL* pCapClearPrint );
    STDMETHOD(get_CapDhigh)( /*[out, retval]*/ VARIANT_BOOL* pCapDhigh );
    STDMETHOD(get_CapDwide)( /*[out, retval]*/ VARIANT_BOOL* pCapDwide );
    STDMETHOD(get_CapDwideDhigh)( /*[out, retval]*/ VARIANT_BOOL* pCapDwideDhigh );
    STDMETHOD(get_CapItalic)( /*[out, retval]*/ VARIANT_BOOL* pCapItalic );
    STDMETHOD(get_CapLeft90)( /*[out, retval]*/ VARIANT_BOOL* pCapLeft90 );
    STDMETHOD(get_CapPrint)( /*[out, retval]*/ VARIANT_BOOL* pCapPrint );
    STDMETHOD(get_CapPrintMode)( /*[out, retval]*/ VARIANT_BOOL* pCapPrintMode );
    STDMETHOD(get_CapRight90)( /*[out, retval]*/ VARIANT_BOOL* pCapRight90 );
    STDMETHOD(get_CapRotate180)( /*[out, retval]*/ VARIANT_BOOL* pCapRotate180 );
    STDMETHOD(get_CapTracksToRead)( /*[out, retval]*/ LONG* pCapTracksToRead );
    STDMETHOD(get_CapTracksToWrite)( /*[out, retval]*/ LONG* pCapTracksToWrite );
    STDMETHOD(get_CardState)( /*[out, retval]*/ LONG* pCardState );
    STDMETHOD(get_CharacterSet)( /*[out, retval]*/ LONG* pCharacterSet );
    STDMETHOD(put_CharacterSet)( /*[in]*/ LONG CharacterSet );
    STDMETHOD(get_CharacterSetList)( /*[out, retval]*/ BSTR* pCharacterSetList );
    STDMETHOD(get_FontTypeFaceList)( /*[out, retval]*/ BSTR* pFontTypeFaceList );
    STDMETHOD(get_LineChars)( /*[out, retval]*/ LONG* pLineChars );
    STDMETHOD(put_LineChars)( /*[in]*/ LONG LineChars );
    STDMETHOD(get_LineCharsList)( /*[out, retval]*/ BSTR* pLineCharsList );
    STDMETHOD(get_LineHeight)( /*[out, retval]*/ LONG* pLineHeight );
    STDMETHOD(put_LineHeight)( /*[in]*/ LONG LineHeight );
    STDMETHOD(get_LineSpacing)( /*[out, retval]*/ LONG* pLineSpacing );
    STDMETHOD(put_LineSpacing)( /*[in]*/ LONG LineSpacing );
    STDMETHOD(get_LineWidth)( /*[out, retval]*/ LONG* pLineWidth );
    STDMETHOD(get_MapMode)( /*[out, retval]*/ LONG* pMapMode );
    STDMETHOD(put_MapMode)( /*[in]*/ LONG MapMode );
    STDMETHOD(get_MaxLine)( /*[out, retval]*/ LONG* pMaxLine );
    STDMETHOD(get_PrintHeight)( /*[out, retval]*/ LONG* pPrintHeight );
    STDMETHOD(get_ReadState1)( /*[out, retval]*/ LONG* pReadState1 );
    STDMETHOD(get_ReadState2)( /*[out, retval]*/ LONG* pReadState2 );
    STDMETHOD(get_RecvLength1)( /*[out, retval]*/ LONG* pRecvLength1 );
    STDMETHOD(get_RecvLength2)( /*[out, retval]*/ LONG* pRecvLength2 );
    STDMETHOD(get_SidewaysMaxChars)( /*[out, retval]*/ LONG* pSidewaysMaxChars );
    STDMETHOD(get_SidewaysMaxLines)( /*[out, retval]*/ LONG* pSidewaysMaxLines );
    STDMETHOD(get_Track1Data)( /*[out, retval]*/ BSTR* pTrack1Data );
    STDMETHOD(get_Track2Data)( /*[out, retval]*/ BSTR* pTrack2Data );
    STDMETHOD(get_Track3Data)( /*[out, retval]*/ BSTR* pTrack3Data );
    STDMETHOD(get_Track4Data)( /*[out, retval]*/ BSTR* pTrack4Data );
    STDMETHOD(get_Track5Data)( /*[out, retval]*/ BSTR* pTrack5Data );
    STDMETHOD(get_Track6Data)( /*[out, retval]*/ BSTR* pTrack6Data );
    STDMETHOD(get_TracksToRead)( /*[out, retval]*/ LONG* pTracksToRead );
    STDMETHOD(put_TracksToRead)( /*[in]*/ LONG TracksToRead );
    STDMETHOD(get_TracksToWrite)( /*[out, retval]*/ LONG* pTracksToWrite );
    STDMETHOD(put_TracksToWrite)( /*[in]*/ LONG TracksToWrite );
    STDMETHOD(get_Write1Data)( /*[out, retval]*/ BSTR* pWrite1Data );
    STDMETHOD(put_Write1Data)( /*[in]*/ BSTR Write1Data );
    STDMETHOD(get_Write2Data)( /*[out, retval]*/ BSTR* pWrite2Data );
    STDMETHOD(put_Write2Data)( /*[in]*/ BSTR Write2Data );
    STDMETHOD(get_Write3Data)( /*[out, retval]*/ BSTR* pWrite3Data );
    STDMETHOD(put_Write3Data)( /*[in]*/ BSTR Write3Data );
    STDMETHOD(get_Write4Data)( /*[out, retval]*/ BSTR* pWrite4Data );
    STDMETHOD(put_Write4Data)( /*[in]*/ BSTR Write4Data );
    STDMETHOD(get_Write5Data)( /*[out, retval]*/ BSTR* pWrite5Data );
    STDMETHOD(put_Write5Data)( /*[in]*/ BSTR Write5Data );
    STDMETHOD(get_Write6Data)( /*[out, retval]*/ BSTR* pWrite6Data );
    STDMETHOD(put_Write6Data)( /*[in]*/ BSTR Write6Data );
    STDMETHOD(get_WriteState1)( /*[out, retval]*/ LONG* pWriteState1 );
    STDMETHOD(get_WriteState2)( /*[out, retval]*/ LONG* pWriteState2 );
    STDMETHOD(BeginInsertion)( 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginRemoval)( 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(CleanCard)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ClearPrintWrite)( 
        /*[in]*/ LONG Kind, 
        /*[in]*/ LONG Hposition, 
        /*[in]*/ LONG Vposition, 
        /*[in]*/ LONG Width, 
        /*[in]*/ LONG Height, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndInsertion)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndRemoval)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintWrite)( 
        /*[in]*/ LONG Kind, 
        /*[in]*/ LONG Hposition, 
        /*[in]*/ LONG Vposition, 
        /*[in]*/ BSTR Data, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(RotatePrint)( 
        /*[in]*/ LONG Rotation, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ValidateData)( 
        /*[in]*/ BSTR Data, 
        /*[out, retval]*/ long* pRC );
// Release 1.6
// Release 1.7
    STDMETHOD(get_CapMapCharacterSet)( /*[out, retval]*/ VARIANT_BOOL* pCapMapCharacterSet );
    STDMETHOD(get_MapCharacterSet)( /*[out, retval]*/ VARIANT_BOOL* pMapCharacterSet );
    STDMETHOD(put_MapCharacterSet)( /*[in]*/ VARIANT_BOOL MapCharacterSet );
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

#endif //__POINTCARDRWIMPL_H__

// End PointCardRWImpl.h
