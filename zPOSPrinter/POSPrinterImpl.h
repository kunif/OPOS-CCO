/****************************************************************************
**
** POSPrinterImpl.h -- Main control header file.
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
**  2020/06/01 Version 1.15.000.                                    K. Fukuchi
**             Changed include guard from #ifndef __XXXX_H__ to #pragma once.
**  2021/12/02 Version 1.16.000.
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
        #pragma message("===>>> Debug Build: Slow tracing to C:\\OposCCO_POSPrinter.log")
        #define DOTRACEV(x) WriteTrace x
        #define DODUMPV(x,y)            // Dump of non-ASCII data not implemented.
        #define TRACEINIT
        #define TRACEEXIT
    #else
        #pragma message("===>>> Debug Build: Fast tracing to OposCCO_POSPrinter.log")
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
#include "POSPrinterDefs.h"

// Standard includes...
#include "Resource.h"

// Include our variant class.
#include "OposVariant.h"

// Include our connection point implementation.
#include "POSPrinterCP.h"


/////////////////////////////////////////////////////////////////////////////
// Data.
/////////////////////////////////////////////////////////////////////////////

#define SO_DISP_COUNT 38
// Hidden window class and window name.
extern TCHAR g_WindowName[];
// Control Object description.
extern char  g_ControlDescription[];


/////////////////////////////////////////////////////////////////////////////
// Control class declaration.
/////////////////////////////////////////////////////////////////////////////

// The class...
class ATL_NO_VTABLE COPOSPOSPrinter :
    // Inherit from all these classes...
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IOPOSPOSPrinter, &IID_IOPOSPOSPrinter, &LIBID_OposPOSPrinter_CCO>,
    public CComControl<COPOSPOSPrinter>,
    public IPersistStreamInitImpl<COPOSPOSPrinter>,
    public IOleControlImpl<COPOSPOSPrinter>,
    public IOleObjectImpl<COPOSPOSPrinter>,
    public IOleInPlaceActiveObjectImpl<COPOSPOSPrinter>,
    public IViewObjectExImpl<COPOSPOSPrinter>,
    public IOleInPlaceObjectWindowlessImpl<COPOSPOSPrinter>,
    public IConnectionPointContainerImpl<COPOSPOSPrinter>,
    public IPersistStorageImpl<COPOSPOSPrinter>,
    public ISpecifyPropertyPagesImpl<COPOSPOSPrinter>,
    public IQuickActivateImpl<COPOSPOSPrinter>,
    public IDataObjectImpl<COPOSPOSPrinter>,
    public IProvideClassInfo2Impl<&CLSID_OPOSPOSPrinter, &DIID__IOPOSPOSPrinterEvents, &LIBID_OposPOSPrinter_CCO>,
    public IObjectSafetyImpl<COPOSPOSPrinter, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    public IPropertyNotifySinkCP<COPOSPOSPrinter>,
    public CComCoClass<COPOSPOSPrinter, &CLSID_OPOSPOSPrinter>,
    public CProxy_IOPOSEvents< COPOSPOSPrinter >
{
public:
// Constructor / FinalConstruct / Destructor.
    COPOSPOSPrinter();
    HRESULT FinalConstruct();
    ~COPOSPOSPrinter();

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
DECLARE_REGISTRY_RESOURCEID(IDR_OPOSPOSPRINTER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

    // Define supported interfaces.
BEGIN_COM_MAP(COPOSPOSPrinter)
    //  Map COM dispatch to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IOPOSPOSPrinter)
    //   Map each COM interface to the current interface implementation.
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPOSPrinter, IOPOSPOSPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPOSPrinter_1_13, IOPOSPOSPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPOSPrinter_1_10, IOPOSPOSPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPOSPrinter_1_10_zz, IOPOSPOSPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPOSPrinter_1_9, IOPOSPOSPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPOSPrinter_1_8, IOPOSPOSPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPOSPrinter_1_7, IOPOSPOSPrinter)
    COM_INTERFACE_ENTRY_IID(IID_IOPOSPOSPrinter_1_5, IOPOSPOSPrinter)

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
BEGIN_PROP_MAP(COPOSPOSPrinter)
    PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
    PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

    // Define connection points.
BEGIN_CONNECTION_POINT_MAP(COPOSPOSPrinter)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    CONNECTION_POINT_ENTRY(DIID__IOPOSPOSPrinterEvents)
END_CONNECTION_POINT_MAP()

    // Define message map.
BEGIN_MSG_MAP(COPOSPOSPrinter)
    CHAIN_MSG_MAP(CComControl<COPOSPOSPrinter>)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

    // Define view status for IViewObjectEx to pass to container.
    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

//===========================================================================
// Bring in all of the OPOS event firing code.
//===========================================================================

protected:
    #include "POSPrinterEvent.h"

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
    STDMETHOD(get_OutputID)( /*[out, retval]*/ LONG* pOutputID );
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
    STDMETHOD(get_AsyncMode)( /*[out, retval]*/ VARIANT_BOOL* pAsyncMode );
    STDMETHOD(put_AsyncMode)( /*[in]*/ VARIANT_BOOL AsyncMode );
    STDMETHOD(get_CapConcurrentJrnRec)( /*[out, retval]*/ VARIANT_BOOL* pCapConcurrentJrnRec );
    STDMETHOD(get_CapConcurrentJrnSlp)( /*[out, retval]*/ VARIANT_BOOL* pCapConcurrentJrnSlp );
    STDMETHOD(get_CapConcurrentRecSlp)( /*[out, retval]*/ VARIANT_BOOL* pCapConcurrentRecSlp );
    STDMETHOD(get_CapCoverSensor)( /*[out, retval]*/ VARIANT_BOOL* pCapCoverSensor );
    STDMETHOD(get_CapJrn2Color)( /*[out, retval]*/ VARIANT_BOOL* pCapJrn2Color );
    STDMETHOD(get_CapJrnBold)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnBold );
    STDMETHOD(get_CapJrnDhigh)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnDhigh );
    STDMETHOD(get_CapJrnDwide)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnDwide );
    STDMETHOD(get_CapJrnDwideDhigh)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnDwideDhigh );
    STDMETHOD(get_CapJrnEmptySensor)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnEmptySensor );
    STDMETHOD(get_CapJrnItalic)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnItalic );
    STDMETHOD(get_CapJrnNearEndSensor)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnNearEndSensor );
    STDMETHOD(get_CapJrnPresent)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnPresent );
    STDMETHOD(get_CapJrnUnderline)( /*[out, retval]*/ VARIANT_BOOL* pCapJrnUnderline );
    STDMETHOD(get_CapRec2Color)( /*[out, retval]*/ VARIANT_BOOL* pCapRec2Color );
    STDMETHOD(get_CapRecBarCode)( /*[out, retval]*/ VARIANT_BOOL* pCapRecBarCode );
    STDMETHOD(get_CapRecBitmap)( /*[out, retval]*/ VARIANT_BOOL* pCapRecBitmap );
    STDMETHOD(get_CapRecBold)( /*[out, retval]*/ VARIANT_BOOL* pCapRecBold );
    STDMETHOD(get_CapRecDhigh)( /*[out, retval]*/ VARIANT_BOOL* pCapRecDhigh );
    STDMETHOD(get_CapRecDwide)( /*[out, retval]*/ VARIANT_BOOL* pCapRecDwide );
    STDMETHOD(get_CapRecDwideDhigh)( /*[out, retval]*/ VARIANT_BOOL* pCapRecDwideDhigh );
    STDMETHOD(get_CapRecEmptySensor)( /*[out, retval]*/ VARIANT_BOOL* pCapRecEmptySensor );
    STDMETHOD(get_CapRecItalic)( /*[out, retval]*/ VARIANT_BOOL* pCapRecItalic );
    STDMETHOD(get_CapRecLeft90)( /*[out, retval]*/ VARIANT_BOOL* pCapRecLeft90 );
    STDMETHOD(get_CapRecNearEndSensor)( /*[out, retval]*/ VARIANT_BOOL* pCapRecNearEndSensor );
    STDMETHOD(get_CapRecPapercut)( /*[out, retval]*/ VARIANT_BOOL* pCapRecPapercut );
    STDMETHOD(get_CapRecPresent)( /*[out, retval]*/ VARIANT_BOOL* pCapRecPresent );
    STDMETHOD(get_CapRecRight90)( /*[out, retval]*/ VARIANT_BOOL* pCapRecRight90 );
    STDMETHOD(get_CapRecRotate180)( /*[out, retval]*/ VARIANT_BOOL* pCapRecRotate180 );
    STDMETHOD(get_CapRecStamp)( /*[out, retval]*/ VARIANT_BOOL* pCapRecStamp );
    STDMETHOD(get_CapRecUnderline)( /*[out, retval]*/ VARIANT_BOOL* pCapRecUnderline );
    STDMETHOD(get_CapSlp2Color)( /*[out, retval]*/ VARIANT_BOOL* pCapSlp2Color );
    STDMETHOD(get_CapSlpBarCode)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpBarCode );
    STDMETHOD(get_CapSlpBitmap)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpBitmap );
    STDMETHOD(get_CapSlpBold)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpBold );
    STDMETHOD(get_CapSlpDhigh)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpDhigh );
    STDMETHOD(get_CapSlpDwide)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpDwide );
    STDMETHOD(get_CapSlpDwideDhigh)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpDwideDhigh );
    STDMETHOD(get_CapSlpEmptySensor)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpEmptySensor );
    STDMETHOD(get_CapSlpFullslip)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpFullslip );
    STDMETHOD(get_CapSlpItalic)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpItalic );
    STDMETHOD(get_CapSlpLeft90)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpLeft90 );
    STDMETHOD(get_CapSlpNearEndSensor)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpNearEndSensor );
    STDMETHOD(get_CapSlpPresent)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpPresent );
    STDMETHOD(get_CapSlpRight90)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpRight90 );
    STDMETHOD(get_CapSlpRotate180)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpRotate180 );
    STDMETHOD(get_CapSlpUnderline)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpUnderline );
    STDMETHOD(get_CharacterSet)( /*[out, retval]*/ LONG* pCharacterSet );
    STDMETHOD(put_CharacterSet)( /*[in]*/ LONG CharacterSet );
    STDMETHOD(get_CharacterSetList)( /*[out, retval]*/ BSTR* pCharacterSetList );
    STDMETHOD(get_CoverOpen)( /*[out, retval]*/ VARIANT_BOOL* pCoverOpen );
    STDMETHOD(get_ErrorStation)( /*[out, retval]*/ LONG* pErrorStation );
    STDMETHOD(get_FlagWhenIdle)( /*[out, retval]*/ VARIANT_BOOL* pFlagWhenIdle );
    STDMETHOD(put_FlagWhenIdle)( /*[in]*/ VARIANT_BOOL FlagWhenIdle );
    STDMETHOD(get_JrnEmpty)( /*[out, retval]*/ VARIANT_BOOL* pJrnEmpty );
    STDMETHOD(get_JrnLetterQuality)( /*[out, retval]*/ VARIANT_BOOL* pJrnLetterQuality );
    STDMETHOD(put_JrnLetterQuality)( /*[in]*/ VARIANT_BOOL JrnLetterQuality );
    STDMETHOD(get_JrnLineChars)( /*[out, retval]*/ LONG* pJrnLineChars );
    STDMETHOD(put_JrnLineChars)( /*[in]*/ LONG JrnLineChars );
    STDMETHOD(get_JrnLineCharsList)( /*[out, retval]*/ BSTR* pJrnLineCharsList );
    STDMETHOD(get_JrnLineHeight)( /*[out, retval]*/ LONG* pJrnLineHeight );
    STDMETHOD(put_JrnLineHeight)( /*[in]*/ LONG JrnLineHeight );
    STDMETHOD(get_JrnLineSpacing)( /*[out, retval]*/ LONG* pJrnLineSpacing );
    STDMETHOD(put_JrnLineSpacing)( /*[in]*/ LONG JrnLineSpacing );
    STDMETHOD(get_JrnLineWidth)( /*[out, retval]*/ LONG* pJrnLineWidth );
    STDMETHOD(get_JrnNearEnd)( /*[out, retval]*/ VARIANT_BOOL* pJrnNearEnd );
    STDMETHOD(get_MapMode)( /*[out, retval]*/ LONG* pMapMode );
    STDMETHOD(put_MapMode)( /*[in]*/ LONG MapMode );
    STDMETHOD(get_RecEmpty)( /*[out, retval]*/ VARIANT_BOOL* pRecEmpty );
    STDMETHOD(get_RecLetterQuality)( /*[out, retval]*/ VARIANT_BOOL* pRecLetterQuality );
    STDMETHOD(put_RecLetterQuality)( /*[in]*/ VARIANT_BOOL RecLetterQuality );
    STDMETHOD(get_RecLineChars)( /*[out, retval]*/ LONG* pRecLineChars );
    STDMETHOD(put_RecLineChars)( /*[in]*/ LONG RecLineChars );
    STDMETHOD(get_RecLineCharsList)( /*[out, retval]*/ BSTR* pRecLineCharsList );
    STDMETHOD(get_RecLineHeight)( /*[out, retval]*/ LONG* pRecLineHeight );
    STDMETHOD(put_RecLineHeight)( /*[in]*/ LONG RecLineHeight );
    STDMETHOD(get_RecLineSpacing)( /*[out, retval]*/ LONG* pRecLineSpacing );
    STDMETHOD(put_RecLineSpacing)( /*[in]*/ LONG RecLineSpacing );
    STDMETHOD(get_RecLinesToPaperCut)( /*[out, retval]*/ LONG* pRecLinesToPaperCut );
    STDMETHOD(get_RecLineWidth)( /*[out, retval]*/ LONG* pRecLineWidth );
    STDMETHOD(get_RecNearEnd)( /*[out, retval]*/ VARIANT_BOOL* pRecNearEnd );
    STDMETHOD(get_RecSidewaysMaxChars)( /*[out, retval]*/ LONG* pRecSidewaysMaxChars );
    STDMETHOD(get_RecSidewaysMaxLines)( /*[out, retval]*/ LONG* pRecSidewaysMaxLines );
    STDMETHOD(get_SlpEmpty)( /*[out, retval]*/ VARIANT_BOOL* pSlpEmpty );
    STDMETHOD(get_SlpLetterQuality)( /*[out, retval]*/ VARIANT_BOOL* pSlpLetterQuality );
    STDMETHOD(put_SlpLetterQuality)( /*[in]*/ VARIANT_BOOL SlpLetterQuality );
    STDMETHOD(get_SlpLineChars)( /*[out, retval]*/ LONG* pSlpLineChars );
    STDMETHOD(put_SlpLineChars)( /*[in]*/ LONG SlpLineChars );
    STDMETHOD(get_SlpLineCharsList)( /*[out, retval]*/ BSTR* pSlpLineCharsList );
    STDMETHOD(get_SlpLineHeight)( /*[out, retval]*/ LONG* pSlpLineHeight );
    STDMETHOD(put_SlpLineHeight)( /*[in]*/ LONG SlpLineHeight );
    STDMETHOD(get_SlpLinesNearEndToEnd)( /*[out, retval]*/ LONG* pSlpLinesNearEndToEnd );
    STDMETHOD(get_SlpLineSpacing)( /*[out, retval]*/ LONG* pSlpLineSpacing );
    STDMETHOD(put_SlpLineSpacing)( /*[in]*/ LONG SlpLineSpacing );
    STDMETHOD(get_SlpLineWidth)( /*[out, retval]*/ LONG* pSlpLineWidth );
    STDMETHOD(get_SlpMaxLines)( /*[out, retval]*/ LONG* pSlpMaxLines );
    STDMETHOD(get_SlpNearEnd)( /*[out, retval]*/ VARIANT_BOOL* pSlpNearEnd );
    STDMETHOD(get_SlpSidewaysMaxChars)( /*[out, retval]*/ LONG* pSlpSidewaysMaxChars );
    STDMETHOD(get_SlpSidewaysMaxLines)( /*[out, retval]*/ LONG* pSlpSidewaysMaxLines );
    STDMETHOD(BeginInsertion)( 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(BeginRemoval)( 
        /*[in]*/ LONG Timeout, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(CutPaper)( 
        /*[in]*/ LONG Percentage, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndInsertion)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(EndRemoval)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintBarCode)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ BSTR Data, 
        /*[in]*/ LONG Symbology, 
        /*[in]*/ LONG Height, 
        /*[in]*/ LONG Width, 
        /*[in]*/ LONG Alignment, 
        /*[in]*/ LONG TextPosition, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintBitmap)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ BSTR FileName, 
        /*[in]*/ LONG Width, 
        /*[in]*/ LONG Alignment, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintImmediate)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ BSTR Data, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintNormal)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ BSTR Data, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PrintTwoNormal)( 
        /*[in]*/ LONG Stations, 
        /*[in]*/ BSTR Data1, 
        /*[in]*/ BSTR Data2, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(RotatePrint)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ LONG Rotation, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetBitmap)( 
        /*[in]*/ LONG BitmapNumber, 
        /*[in]*/ LONG Station, 
        /*[in]*/ BSTR FileName, 
        /*[in]*/ LONG Width, 
        /*[in]*/ LONG Alignment, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(SetLogo)( 
        /*[in]*/ LONG Location, 
        /*[in]*/ BSTR Data, 
        /*[out, retval]*/ long* pRC );
// Release 1.1
    STDMETHOD(get_CapCharacterSet)( /*[out, retval]*/ LONG* pCapCharacterSet );
    STDMETHOD(get_CapTransaction)( /*[out, retval]*/ VARIANT_BOOL* pCapTransaction );
    STDMETHOD(get_ErrorLevel)( /*[out, retval]*/ LONG* pErrorLevel );
    STDMETHOD(get_ErrorString)( /*[out, retval]*/ BSTR* pErrorString );
    STDMETHOD(get_FontTypefaceList)( /*[out, retval]*/ BSTR* pFontTypefaceList );
    STDMETHOD(get_RecBarCodeRotationList)( /*[out, retval]*/ BSTR* pRecBarCodeRotationList );
    STDMETHOD(get_RotateSpecial)( /*[out, retval]*/ LONG* pRotateSpecial );
    STDMETHOD(put_RotateSpecial)( /*[in]*/ LONG RotateSpecial );
    STDMETHOD(get_SlpBarCodeRotationList)( /*[out, retval]*/ BSTR* pSlpBarCodeRotationList );
    STDMETHOD(TransactionPrint)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ LONG Control, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(ValidateData)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ BSTR Data, 
        /*[out, retval]*/ long* pRC );
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
    STDMETHOD(get_CapJrnCartridgeSensor)( /*[out, retval]*/ LONG* pCapJrnCartridgeSensor );
    STDMETHOD(get_CapJrnColor)( /*[out, retval]*/ LONG* pCapJrnColor );
    STDMETHOD(get_CapRecCartridgeSensor)( /*[out, retval]*/ LONG* pCapRecCartridgeSensor );
    STDMETHOD(get_CapRecColor)( /*[out, retval]*/ LONG* pCapRecColor );
    STDMETHOD(get_CapRecMarkFeed)( /*[out, retval]*/ LONG* pCapRecMarkFeed );
    STDMETHOD(get_CapSlpBothSidesPrint)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpBothSidesPrint );
    STDMETHOD(get_CapSlpCartridgeSensor)( /*[out, retval]*/ LONG* pCapSlpCartridgeSensor );
    STDMETHOD(get_CapSlpColor)( /*[out, retval]*/ LONG* pCapSlpColor );
    STDMETHOD(get_CartridgeNotify)( /*[out, retval]*/ LONG* pCartridgeNotify );
    STDMETHOD(put_CartridgeNotify)( /*[in]*/ LONG CartridgeNotify );
    STDMETHOD(get_JrnCartridgeState)( /*[out, retval]*/ LONG* pJrnCartridgeState );
    STDMETHOD(get_JrnCurrentCartridge)( /*[out, retval]*/ LONG* pJrnCurrentCartridge );
    STDMETHOD(put_JrnCurrentCartridge)( /*[in]*/ LONG JrnCurrentCartridge );
    STDMETHOD(get_RecCartridgeState)( /*[out, retval]*/ LONG* pRecCartridgeState );
    STDMETHOD(get_RecCurrentCartridge)( /*[out, retval]*/ LONG* pRecCurrentCartridge );
    STDMETHOD(put_RecCurrentCartridge)( /*[in]*/ LONG RecCurrentCartridge );
    STDMETHOD(get_SlpCartridgeState)( /*[out, retval]*/ LONG* pSlpCartridgeState );
    STDMETHOD(get_SlpCurrentCartridge)( /*[out, retval]*/ LONG* pSlpCurrentCartridge );
    STDMETHOD(put_SlpCurrentCartridge)( /*[in]*/ LONG SlpCurrentCartridge );
    STDMETHOD(get_SlpPrintSide)( /*[out, retval]*/ LONG* pSlpPrintSide );
    STDMETHOD(ChangePrintSide)( 
        /*[in]*/ LONG Side, 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(MarkFeed)( 
        /*[in]*/ LONG Type, 
        /*[out, retval]*/ long* pRC );
// Release 1.6
// Release 1.7
    STDMETHOD(get_CapMapCharacterSet)( /*[out, retval]*/ VARIANT_BOOL* pCapMapCharacterSet );
    STDMETHOD(get_MapCharacterSet)( /*[out, retval]*/ VARIANT_BOOL* pMapCharacterSet );
    STDMETHOD(put_MapCharacterSet)( /*[in]*/ VARIANT_BOOL MapCharacterSet );
    STDMETHOD(get_RecBitmapRotationList)( /*[out, retval]*/ BSTR* pRecBitmapRotationList );
    STDMETHOD(get_SlpBitmapRotationList)( /*[out, retval]*/ BSTR* pSlpBitmapRotationList );
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
    STDMETHOD(get_CapConcurrentPageMode)( /*[out, retval]*/ VARIANT_BOOL* pCapConcurrentPageMode );
    STDMETHOD(get_CapRecPageMode)( /*[out, retval]*/ VARIANT_BOOL* pCapRecPageMode );
    STDMETHOD(get_CapSlpPageMode)( /*[out, retval]*/ VARIANT_BOOL* pCapSlpPageMode );
    STDMETHOD(get_PageModeArea)( /*[out, retval]*/ BSTR* pPageModeArea );
    STDMETHOD(get_PageModeDescriptor)( /*[out, retval]*/ LONG* pPageModeDescriptor );
    STDMETHOD(get_PageModeHorizontalPosition)( /*[out, retval]*/ LONG* pPageModeHorizontalPosition );
    STDMETHOD(put_PageModeHorizontalPosition)( /*[in]*/ LONG PageModeHorizontalPosition );
    STDMETHOD(get_PageModePrintArea)( /*[out, retval]*/ BSTR* pPageModePrintArea );
    STDMETHOD(put_PageModePrintArea)( /*[in]*/ BSTR PageModePrintArea );
    STDMETHOD(get_PageModePrintDirection)( /*[out, retval]*/ LONG* pPageModePrintDirection );
    STDMETHOD(put_PageModePrintDirection)( /*[in]*/ LONG PageModePrintDirection );
    STDMETHOD(get_PageModeStation)( /*[out, retval]*/ LONG* pPageModeStation );
    STDMETHOD(put_PageModeStation)( /*[in]*/ LONG PageModeStation );
    STDMETHOD(get_PageModeVerticalPosition)( /*[out, retval]*/ LONG* pPageModeVerticalPosition );
    STDMETHOD(put_PageModeVerticalPosition)( /*[in]*/ LONG PageModeVerticalPosition );
    STDMETHOD(ClearPrintArea)( 
        /*[out, retval]*/ long* pRC );
    STDMETHOD(PageModePrint)( 
        /*[in]*/ LONG Control, 
        /*[out, retval]*/ long* pRC );
// Release 1.10
    STDMETHOD(PrintMemoryBitmap)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ BSTR Data, 
        /*[in]*/ LONG Type, 
        /*[in]*/ LONG Width, 
        /*[in]*/ LONG Alignment, 
        /*[out, retval]*/ long* pRC );
// Release 1.11
// Release 1.12
// Release 1.13
    STDMETHOD(get_CapRecRuledLine)( /*[out, retval]*/ LONG* pCapRecRuledLine );
    STDMETHOD(get_CapSlpRuledLine)( /*[out, retval]*/ LONG* pCapSlpRuledLine );
    STDMETHOD(DrawRuledLine)( 
        /*[in]*/ LONG Station, 
        /*[in]*/ BSTR PositionList, 
        /*[in]*/ LONG LineDirection, 
        /*[in]*/ LONG LineWidth, 
        /*[in]*/ LONG LineStyle, 
        /*[in]*/ LONG LineColor, 
        /*[out, retval]*/ long* pRC );
// Release 1.14
// Release 1.15
};


// End POSPrinterImpl.h
