/****************************************************************************
**
** ElectronicValueRWImpl.cpp -- Main control implementation file.
**
**     Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  1999/03/20 Initial development.                                 C. Monroe
**  2003/05/29 On Debug builds, add tracing of Open and Close to
**               C:\OposCCO_ElectronicValueRW.log
**  2004/03/22 Add significantly more tracing when Debug.
**  2004/10/26 Minor enhancement of Debug tracing of strings.
**  2005/12/14 Add Debug tracing of event delivery.
**  2008/01/15 Add more parameter and error checking.
**  2013/09/29 Update license section.
**  2015/02/07 Update license section.
**             Use OposVariantResult for Invoke results.
**             Correct possible buffer overflow in Open.
**               Updates to copies and printf to remove any
**               potential buffer overflows.
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


/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

// Include the standard header.
#include "stdafx.h"

// Include the MIDL-generated header.
#include "ElectronicValueRW.h"

// Include this control's header.
#include "ElectronicValueRWImpl.h"

// Include character <--> wide conversions header.
#include "CWString.h"

// Include the OPOS header.
#include "OposEvrw.hi"

// TSIZEOF(x) returns characters in "x" bytes.
#define TSIZEOF(x)  (sizeof(x)/sizeof(TCHAR))

// Ensure that character array has NUL as last character.
#define NULTERMINATE(x) x[TSIZEOF(x) - 1] = '\0';


/////////////////////////////////////////////////////////////////////////////
// Data
/////////////////////////////////////////////////////////////////////////////

// Hidden window class and window name.
TCHAR g_WindowName[] = _T("HW_OPOSElectronicValueRW");

// Control Object description and version.
char g_ControlDescription[] = "OPOS ElectronicValueRW Control 1.15.100 [Public, by CRM/MCS]" IFDEBUG(" [With Tracing]");
LONG g_ControlVersion =
    1 * 1000000 +
    15 * 1000 +
    100;

// Count of instances within this process.
int COPOSElectronicValueRW::s_nInstances = 0;

//===========================================================================
// Method name table. Used to lookup methods in SO.
//===========================================================================

static char* s_SOMethodNames[SO_DISP_COUNT + 1] =
{
// Release 1.12 methods
    "COFreezeEvents",
        #define nDICOFreezeEvents 0
    "GetPropertyNumber",
        #define nDIGetPropertyNumber 1
    "SetPropertyNumber",
        #define nDISetPropertyNumber 2
    "GetPropertyString",
        #define nDIGetPropertyString 3
    "SetPropertyString",
        #define nDISetPropertyString 4
    "OpenService",
        #define nDIOpenService 5
    "CheckHealth",
        #define nDICheckHealth 6
    "ClaimDevice",
        #define nDIClaimDevice 7
    "ClearInput",
        #define nDIClearInput 8
    "ClearOutput",
        #define nDIClearOutput 9
    "CloseService",
        #define nDICloseService 10
    "DirectIO",
        #define nDIDirectIO 11
    "ReleaseDevice",
        #define nDIReleaseDevice 12
    "ResetStatistics",
        #define nDIResetStatistics 13
    "RetrieveStatistics",
        #define nDIRetrieveStatistics 14
    "UpdateStatistics",
        #define nDIUpdateStatistics 15
    "CompareFirmwareVersion",
        #define nDICompareFirmwareVersion 16
    "UpdateFirmware",
        #define nDIUpdateFirmware 17
    "ClearInputProperties",
        #define nDIClearInputProperties 18
    "GetAmount",
        #define nDIGetAmount 19
    "SetAmount",
        #define nDISetAmount 20
    "GetBalance",
        #define nDIGetBalance 21
    "GetBalanceOfPoint",
        #define nDIGetBalanceOfPoint 22
    "GetPoint",
        #define nDIGetPoint 23
    "SetPoint",
        #define nDISetPoint 24
    "GetSettledAmount",
        #define nDIGetSettledAmount 25
    "GetSettledPoint",
        #define nDIGetSettledPoint 26
    "AccessLog",
        #define nDIAccessLog 27
    "ActivateService",
        #define nDIActivateService 28
    "AddValue",
        #define nDIAddValue 29
    "BeginDetection",
        #define nDIBeginDetection 30
    "BeginRemoval",
        #define nDIBeginRemoval 31
    "CancelValue",
        #define nDICancelValue 32
    "CaptureCard",
        #define nDICaptureCard 33
    "EndDetection",
        #define nDIEndDetection 34
    "EndRemoval",
        #define nDIEndRemoval 35
    "EnumerateCardServices",
        #define nDIEnumerateCardServices 36
    "LockTerminal",
        #define nDILockTerminal 37
    "ReadValue",
        #define nDIReadValue 38
    "SubtractValue",
        #define nDISubtractValue 39
    "TransactionAccess",
        #define nDITransactionAccess 40
    "UnlockTerminal",
        #define nDIUnlockTerminal 41
    "UpdateKey",
        #define nDIUpdateKey 42
    "WriteValue",
        #define nDIWriteValue 43
// Release 1.13 methods
// Release 1.14 methods
    "ClearParameterInformation",
        #define nDIClearParameterInformation 44
    "QueryLastSuccessfulTransactionResult",
        #define nDIQueryLastSuccessfulTransactionResult 45
    "RetrieveResultInformation",
        #define nDIRetrieveResultInformation 46
    "SetParameterInformation",
        #define nDISetParameterInformation 47
// Release 1.15 methods
    "AccessData",
        #define nDIAccessData 48
    "ActivateEVService",
        #define nDIActivateEVService 49
    "CheckServiceRegistrationToMedium",
        #define nDICheckServiceRegistrationToMedium 50
    "CloseDailyEVService",
        #define nDICloseDailyEVService 51
    "DeactivateEVService",
        #define nDIDeactivateEVService 52
    "OpenDailyEVService",
        #define nDIOpenDailyEVService 53
    "RegisterServiceToMedium",
        #define nDIRegisterServiceToMedium 54
    "UnregisterServiceToMedium",
        #define nDIUnregisterServiceToMedium 55
    "UpdateData",
        #define nDIUpdateData 56
    0
};

//===========================================================================
// Required method count table.
//   Contains count of methods from table above that must be present
//   for each release.
// Followed by the initial minor release of the OPOS ElectronicValueRW.
//===========================================================================

static int s_RequiredMethodsPerRelease[] =
{
     44, // Release 1.12
     44, // Release 1.13
     48, // Release 1.14
     57  // Release 1.15
};

const int MinorReleaseInitial = 12;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// Constructor / Destructor
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

COPOSElectronicValueRW::COPOSElectronicValueRW()
    IFDEBUG( : CProxy_IOPOSEvents< COPOSElectronicValueRW >(this) )
{
}

//===========================================================================

HRESULT COPOSElectronicValueRW::FinalConstruct()
{
    TRACEINIT;
    DOTRACE( ( _T("") ) );
    DOTRACE( ( _T("*Constructing: %hs"), g_ControlDescription ) );

    _bOpened = false;
    _nOpenResult = 0;
    _nSOMajor = 0;
    _nSOMinor = 0;
    _nCOResultCode = -1;
    _nCOFreezeEventCount = 0;
    _bFreezeState = false;
    IFDEBUG( _nBinaryConversion = OPOS_BC_NONE );

    HRESULT hRC = EventInit();

    s_nInstances++; // Increment instance count at end of FinalConstruct.

    return hRC;
}

//===========================================================================

COPOSElectronicValueRW::~COPOSElectronicValueRW()
{
    DOTRACE( ( _T("*Destructing") ) );

    s_nInstances--; // Decrement instance count at start of destructor.
    long RC;
    if ( _bOpened )
        Close( &RC );
    EventUninit();

    DOTRACE( ( _T("") ) );
    TRACEEXIT;
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// Control handlers
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// Override the IOleControlImpl handler for container request to freeze/unfreeze events.
STDMETHODIMP COPOSElectronicValueRW::FreezeEvents( BOOL bFreeze )
{
    // If requesting events to be frozen...
    if ( bFreeze )
    {
        DOTRACEV( ( _T("*FreezeEvents: Freezing %d"), _nCOFreezeEventCount ) );
        if ( _nCOFreezeEventCount == 0 &&   // If events are not currently frozen and
             _bOpened )                     //   SO is opened,
            SetCOFreezeEvents( TRUE );      //   then freeze events in the SO.
        _nCOFreezeEventCount++;             // Increment freeze count. Must do after informing SO.
    }
    // Else requesting events to be unfrozen...
    else
    {
        _nCOFreezeEventCount--;             // Decrement freeze count. Must do before informing SO.
        DOTRACEV( ( _T("*FreezeEvents: Unfreezing %d"), _nCOFreezeEventCount ) );
        if ( _nCOFreezeEventCount == 0 &&   // If events have become unfrozen and
             _bOpened )                     //   SO is opened,
            SetCOFreezeEvents( FALSE );     //   then unfreeze events in the SO.
    }

    // Just in case anyone cares ... keep the CComControlBase one in sync.
    m_nFreezeEvents = _nCOFreezeEventCount;
    return S_OK;
}

//===========================================================================

// Implement the draw handler.
HRESULT COPOSElectronicValueRW::OnDraw( ATL_DRAWINFO& di )
{
    RECT& rc = *(RECT*)di.prcBounds;

    // Draw our bitmap...
    //  - Load bitmap and get info
    HBITMAP hBitmap = LoadBitmap(
        _Module.GetModuleInstance(),            // handle of the instance containing the image
        MAKEINTRESOURCE(IDB_OPOSELECTRONICVALUERW2) ); // bitmap resource name
    BITMAP bmp;
    GetObject(
        hBitmap,                                // handle to graphics object of interest
        sizeof(BITMAP),                         // size of buffer for object information
        &bmp );                                 // pointer to buffer for object information
    //  - Create a compatible memory DC and select bitmap into it
    HDC hMemDC = CreateCompatibleDC(
        di.hdcDraw );                           // handle to the device context
    HBITMAP hOldBitmap =
        (HBITMAP) SelectObject(
            hMemDC,                             // handle to device context
            hBitmap );                          // handle to object
    //  - Copy bitmap from memory DC to screen DC
    BitBlt(
      di.hdcDraw,                               // handle to destination device context
      rc.left,                                  // x-coordinate of destination rectangle's upper-left corner
      rc.top,                                   // y-coordinate of destination rectangle's upper-left corner
      min( bmp.bmWidth, rc.right - rc.left ),   // width of destination rectangle
      min( bmp.bmHeight, rc.bottom - rc.top ),  // height of destination rectangle
      hMemDC,                                   // handle to source device context
      0,                                        // x-coordinate of source rectangle's upper-left corner
      0,                                        // y-coordinate of source rectangle's upper-left corner
      SRCCOPY );                                // raster operation code

    // Cleanup
    SelectObject( hMemDC, hOldBitmap );
    DeleteObject( hMemDC );
    DeleteObject( hBitmap );

    return S_OK;
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// Property Access / Freeze Setting
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

HRESULT COPOSElectronicValueRW::GetOposProp( DEBUGPARAM(LPCSTR pPropName)
    long nIndex, long* pnValue, long nMinor )
{
    DOTRACEV( ( _T("+%hs [Get]"), pPropName ) );

    // Initialize return value.
    HRESULT hRC = S_OK;
    *pnValue = 0;

    // If open and SO version support's property...
    if ( _bOpened && _nSOMinor >= nMinor )
    {
        // Set up and call the SO's get property number method.
        OposVariant Var;
        OposVariantResult VarResult;
        Var.SetLONG( nIndex );
        DISPPARAMS Disp = { &Var, NULL, 1, 0 };
        hRC = _pService->Invoke(
                _DispIDs[nDIGetPropertyNumber], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );

        // If success, then set return result.
        if ( hRC == S_OK )
            VarResult.ChangeLONG( pnValue, hRC );
    }

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pszInfo = _T("");
    TCHAR szHR[50];
    if ( !_bOpened )
        pszInfo = _T(" -- Closed");
    else if ( _nSOMinor < nMinor )
        pszInfo = _T(" -- Not supported by SO");
    else if ( hRC != 0 )
    {
        _sntprintf( szHR, TSIZEOF(szHR), _T(" -- COM error: HR = 0x%X"), hRC );
        NULTERMINATE(szHR);
        pszInfo = szHR;
    }

    DOTRACEV( ( _T("-%hs [Get]: %d (0x%X)%s"), pPropName, *pnValue, *pnValue, pszInfo ) );
#endif

    return hRC;
}

//---------------------------------------------------------------------------

HRESULT COPOSElectronicValueRW::SetOposProp( DEBUGPARAM(LPCSTR pPropName)
    long nIndex, long nValue, long nMinor )
{
    DOTRACEV( ( _T("+%hs [Set]: %d (0x%X)"), pPropName, nValue, nValue ) );
    HRESULT hRC = S_OK;

    SetRC();                            // Clear COResultCode.

    // If open and SO version support's property...
    if ( _bOpened && _nSOMinor >= nMinor )
    {
        // Set up and call the SO's set property number method.
        OposVariant Vars[2];
        OposVariantResult VarResult;
        Vars[1].SetLONG( nIndex );
        Vars[0].SetLONG( nValue );
        OposDispParms Disp( Vars, 2 );
        hRC = _pService->Invoke(
                _DispIDs[nDISetPropertyNumber], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );
    }

    // Handle error.
    else if ( _bOpened )                // If open but not supported,
        SetRC( OPOS_E_NOSERVICE );      //   set COResultCode.

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pszInfo = _T("");
    TCHAR szHR[50];
    if ( !_bOpened )
        pszInfo = _T(" -- Closed");
    else if ( _nSOMinor < nMinor )
        pszInfo = _T(" -- Not supported by SO");
    else if ( hRC != 0 )
    {
        _sntprintf( szHR, TSIZEOF(szHR), _T(" -- COM error: HR = 0x%X"), hRC );
        NULTERMINATE(szHR);
        pszInfo = szHR;
    }

    DOTRACEV( ( _T("-%hs [Set]%s"), pPropName, pszInfo ) );
#endif

    return hRC;
}

//===========================================================================

HRESULT COPOSElectronicValueRW::GetOposProp( DEBUGPARAM(LPCSTR pPropName)
    long nIndex, VARIANT_BOOL* pnValue, long nMinor )
{
    // If getting a boolean, then force return value to proper VARIANT_BOOL value.
    long nValue;
    HRESULT hRC = GetOposProp( DEBUGPARAM(pPropName)
        nIndex, &nValue, nMinor );
    *pnValue = nValue ? VARIANT_TRUE : VARIANT_FALSE;
    return hRC;
}

//---------------------------------------------------------------------------

HRESULT COPOSElectronicValueRW::SetOposProp( DEBUGPARAM(LPCSTR pPropName)
    long nIndex, VARIANT_BOOL nValue, long nMinor )
{
    // If setting a boolean, then force to use VC++ TRUE or FALSE,
    //   since several vendors test specifically against TRUE (1)
    //   rather than non-zero.
    return SetOposProp( DEBUGPARAM(pPropName)
        nIndex, static_cast<long>(nValue ? TRUE : FALSE), nMinor );
}

//===========================================================================

HRESULT COPOSElectronicValueRW::GetOposProp( DEBUGPARAM(LPCSTR pPropName)
    long nIndex, BSTR* psValue, long nMinor )
{
    DOTRACEV( ( _T("+%hs [Get]"), pPropName ) );

    // Initialize return value.
    HRESULT hRC = S_OK;

    // If open and SO version support's property...
    if ( _bOpened && _nSOMinor >= nMinor )
    {
        // Set up and call the SO's get property number method.
        OposVariant Var;
        OposVariantResult VarResult;
        Var.SetLONG( nIndex );
        DISPPARAMS Disp = { &Var, NULL, 1, 0 };
        hRC = _pService->Invoke(
                _DispIDs[nDIGetPropertyString], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );

        // If succeeds, then return result.
        if ( hRC == S_OK )
            VarResult.ChangeBSTR( psValue, hRC );
    }
    // Else return default string.
    else
        *psValue = ::SysAllocString( L"[Error]" );

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pszFormat = _T("-%hs [Get].");
    if ( !_bOpened )
        pszFormat = _T("-%hs [Get] -- Closed.");
    else if ( _nSOMinor < nMinor )
        pszFormat = _T("-%hs [Get] -- Not supported by SO.");
    else if ( hRC != 0 )
        pszFormat = _T("-%hs [Get] -- COM error: HR = 0x%X");

    TCHAR szPrefix[100];
    _sntprintf( szPrefix, TSIZEOF(szPrefix), pszFormat, pPropName, hRC );
    NULTERMINATE(szPrefix);
    DOTRACESTRINGV( szPrefix, *psValue );
#endif

    return hRC;
}

//---------------------------------------------------------------------------

HRESULT COPOSElectronicValueRW::SetOposProp( DEBUGPARAM(LPCSTR pPropName)
    long nIndex, BSTR sValue, long nMinor )
{
#ifdef _DEBUG
    TCHAR szPrefix[100];
    _sntprintf( szPrefix, TSIZEOF(szPrefix), _T("+%hs [Set]."), pPropName );
    NULTERMINATE(szPrefix);
    DOTRACESTRINGV( szPrefix, sValue );
#endif
    HRESULT hRC = S_OK;

    SetRC();                            // Clear COResultCode.

    // If open and SO version support's property...
    if ( _bOpened && _nSOMinor >= nMinor )
    {
        // Set up and call the SO's set property number method.
        OposVariant Vars[2];
        OposVariantResult VarResult;
        Vars[1].SetLONG( nIndex );
        Vars[0].SetBSTR( sValue, hRC );
        OposDispParms Disp( Vars, 2 );
        if ( hRC == S_OK )
            hRC = _pService->Invoke(
                _DispIDs[nDISetPropertyString], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );
    }

    // Handle error.
    else if ( _bOpened )                // If open but not supported,
        SetRC( OPOS_E_NOSERVICE );      //   set COResultCode.

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pszInfo = _T("");
    TCHAR szHR[50];
    if ( !_bOpened )
        pszInfo = _T(" -- Closed");
    else if ( _nSOMinor < nMinor )
        pszInfo = _T(" -- Not supported by SO");
    else if ( hRC != 0 )
    {
        _sntprintf( szHR, TSIZEOF(szHR), _T(" -- COM error: HR = 0x%X"), hRC );
        NULTERMINATE(szHR);
        pszInfo = szHR;
    }

    DOTRACEV( ( _T("-%hs [Set]%s"), pPropName, pszInfo ) );
#endif

    return hRC;
}

//===========================================================================

HRESULT COPOSElectronicValueRW::DoInvoke( DEBUGPARAM(LPCSTR pFuncName)
    HRESULT hRC, OposVariant* pParms, unsigned nParms, int nDispIDIndex, long* pRC, bool bOpenCheck )
{
    // Trace incoming function and parameters.
#ifdef _DEBUG
    OposVariant* pVar;
    TCHAR szParmNum[20];
    TCHAR szPrefix[100];
    OposVariant* pStrRefs = new OposVariant[nParms];

    DOTRACEV( ( _T("+%hs [Function]  %u parameter%s"), pFuncName, nParms, nParms == 1 ? _T("") : _T("s") ) );
    unsigned u;
    for ( u = 0; ++u <= nParms; )
    {
        HRESULT hRCTmp;
        pVar = &pParms[ nParms - u ];
        _sntprintf( szParmNum, TSIZEOF(szParmNum), _T("    #%u: "), u );
        NULTERMINATE(szParmNum);
        switch ( pVar->vt )
        {
        case VT_EMPTY: DOTRACEV( ( _T("%sEMPTY"), szParmNum ) ); break;
        case VT_BOOL: DOTRACEV( ( _T("%sBOOL 0x%X"), szParmNum, pVar->boolVal ) ); break;
        case VT_BYREF|VT_BOOL: DOTRACEV( ( _T("%sBOOL* 0x%X"), szParmNum, *pVar->pboolVal ) ); break;
        case VT_I4: DOTRACEV( ( _T("%sLONG %d (0x%X)"), szParmNum, pVar->lVal, pVar->lVal ) ); break;
        case VT_BYREF|VT_I4: DOTRACEV( ( _T("%sLONG* %d (0x%X)"), szParmNum, *pVar->plVal, *pVar->plVal ) ); break;
        case VT_CY: DOTRACEV( ( _T("%sCURRENCY %s"), szParmNum, FormatCurrency(pVar->cyVal) ) ); break;
        case VT_BYREF|VT_CY: DOTRACEV( ( _T("%sCURRENCY* %s"), szParmNum, FormatCurrency(*pVar->pcyVal) ) ); break;
        case VT_DISPATCH: DOTRACEV( ( _T("%sDISPATCH 0x%X"), szParmNum, pVar->pdispVal ) ); break;
        case VT_BSTR:
            _sntprintf( szPrefix, TSIZEOF(szPrefix), _T("%sSTRING;"), szParmNum );
            NULTERMINATE(szPrefix);
            DOTRACESTRINGV( szPrefix, pVar->bstrVal );
            break;
        case VT_BYREF|VT_BSTR:
            pStrRefs[u-1].SetBSTR_Copy( *pVar->pbstrVal, hRCTmp );
            _sntprintf( szPrefix, TSIZEOF(szPrefix), _T("%sSTRING*;"), szParmNum );
            NULTERMINATE(szPrefix);
            DOTRACESTRINGV( szPrefix, *pVar->pbstrVal );
            break;
        default: DOTRACEV( ( _T("%sUnknown (VarType=0x%X)"), szParmNum, pVar->vt ) ); break;
        }
    }

    // If bad ResultCode pointer, then HRESULT.
    if ( pRC == 0 )
        hRC = E_POINTER;

    // If bad HRESULT (either due to incoming value or bad ResultCode pointer), then return now.
    if ( FAILED(hRC) )
    {
        DOTRACEERR( _T("-  Failed: Parameter error 0x%X\n    %s"), hRC );
        delete [] pStrRefs;
        return hRC;
    }
#endif

    hRC = -1;

    // Clear the CO result code.
    SetRC();

    // If the SO must be open...
    if ( bOpenCheck )
    {
        // If not opened, set error code and return....
        if ( ! _bOpened )
        {
            *pRC = OPOS_E_CLOSED;
            hRC = S_OK;
        }
        // If the SO's release level doesn't support this method, then return error.
        else if ( nDispIDIndex >= _nMaxMethod )
        {
            *pRC = SetRC( OPOS_E_NOSERVICE );
            hRC = S_OK;
        }
    }

    // Complete setup for Invoke call.
    if ( hRC == -1 )
    {
        OposVariantResult VarResult;
        OposDispParms Disp( pParms, nParms );

        // Invoke the SO method.
        hRC = _pService->Invoke(
                _DispIDs[nDispIDIndex], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );

        // Set OPOS result code to SO method value if Invoke succeeded,
        //   else flag that we failed to get to the SO.
        *pRC = (hRC == S_OK) ? VarResult.GetLONG() : SetRC( OPOS_E_NOSERVICE );
    }

    // Trace result and outgoing parameters.
#ifdef _DEBUG
    LPCTSTR pszInfo = _T("");
    TCHAR szHR[50];
    if ( !_bOpened )
        pszInfo = _T(" -- Closed");
    else if ( nDispIDIndex >= _nMaxMethod )
        pszInfo = _T(" -- Not supported by SO");
    else if ( hRC != 0 )
    {
        _sntprintf( szHR, TSIZEOF(szHR), _T(" -- COM error: HR = 0x%X"), hRC );
        NULTERMINATE(szHR);
        pszInfo = szHR;
    }

    DOTRACEV( ( _T("-%hs [Function]  RC=%d%s"), pFuncName, *pRC, pszInfo ) );
    for ( u = 0; ++u <= nParms; )
    {
        pVar = &pParms[ nParms - u ];
        _sntprintf( szParmNum, TSIZEOF(szParmNum), _T("    #%u: "), u );
        NULTERMINATE(szParmNum);
        switch ( pVar->vt )
        {
        case VT_BYREF|VT_BOOL: DOTRACEV( ( _T("%sBOOL* 0x%X"), szParmNum, *pVar->pboolVal ) ); break;
        case VT_BYREF|VT_I4: DOTRACEV( ( _T("%sLONG* %d (0x%X)"), szParmNum, *pVar->plVal, *pVar->plVal ) ); break;
        case VT_BYREF|VT_CY: DOTRACEV( ( _T("%sCURRENCY* %s"), szParmNum, FormatCurrency(*pVar->pcyVal) ) ); break;
        case VT_BYREF|VT_BSTR:
            {
                _sntprintf( szPrefix, TSIZEOF(szPrefix), _T("%sSTRING*;"), szParmNum );
                NULTERMINATE(szPrefix);
                UINT nStrRefLen;
                OposVariant* pStrRef = &pStrRefs[u-1];
                if ( pStrRef->vt == VT_BSTR &&
                     ( nStrRefLen = ::SysStringByteLen( pStrRef->bstrVal ) ) == ::SysStringByteLen( *pVar->pbstrVal ) &&
                      0 == ::memcmp( pStrRef->bstrVal, *pVar->pbstrVal, nStrRefLen ) )
                    DOTRACEV( ( _T("%s Unchanged"), szPrefix ) );
                else
                    DOTRACESTRINGV( szPrefix, *pVar->pbstrVal );
                break;
            }
        }
    }

    delete [] pStrRefs;
#endif

    return hRC;
}

//===========================================================================

void COPOSElectronicValueRW::SetCOFreezeEvents( VARIANT_BOOL bFreeze )
{
    // If open...
    if ( _bOpened )
    {
        DOTRACEV( ( _T("*SetCOFreezeEvents: 0x%X"), bFreeze ) );

        // Set up and call the method to inform the SO of container freeze/unfreeze.
        OposVariant Var;
        OposVariantResult VarResult;
        Var.SetVARIANT_BOOL( bFreeze );
        DISPPARAMS Disp = { &Var, NULL, 1, 0 };
        _pService->Invoke(
                _DispIDs[nDICOFreezeEvents], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );
    }
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// Methods
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Open, Close
/////////////////////////////////////////////////////////////////////////////

STDMETHODIMP COPOSElectronicValueRW::Open( BSTR DeviceName, long *pRC )
{
    HRESULT hRC;
    LONG nError;

    DOTRACE( ( _T("*Open [Function]: DeviceName <%ls>"), DeviceName ) );

    // If already open, return error.
    if ( _bOpened )
    {
        *pRC = SetRC( OPOS_E_ILLEGAL );
        _nOpenResult = OPOS_OR_ALREADYOPEN;
        DOTRACE( ( _T("-  Failed: CCO already open (%d/%d)"), *pRC, _nOpenResult ) );
        return S_OK;
    }

    // Initialize ResultCode and OpenResult for possible returns below.
    *pRC = SetRC( OPOS_E_NOEXIST );
    _nOpenResult = OPOS_OR_REGBADNAME;

    // Check the DeviceName length...
    UINT nDeviceNameLen = ::SysStringLen( DeviceName );

    //  - Ensure that the DeviceName is not an empty string.
    if ( nDeviceNameLen == 0 )
    {
        DOTRACE( ( _T("-  Failed: Empty device name (%d/%d)"), *pRC, _nOpenResult ) );
        return S_OK;
    }

    //  - Ensure that the DeviceName is not unreasonably long.
    //     Otherwise it may overrun this line below: wcscpy( szPhysicalDeviceName, DeviceName )
    if ( nDeviceNameLen >= MAX_REGBUFFER_SIZE )
    {
        DOTRACE( ( _T("-  Failed: Device name too big (%d/%d)"), *pRC, _nOpenResult ) );
        return S_OK;
    }

    // Form and open the base key.
    TCHAR szBaseKey[ MAX_REGBUFFER_SIZE ];
    HKEY hBaseKey;
    cw_strcpy( szBaseKey, OPOS_ROOTKEY "\\" OPOS_CLASSKEY_EVRW );
    nError = RegOpenKeyEx(
            HKEY_LOCAL_MACHINE,         // Handle to open key
            szBaseKey,                  // Address of name of subkey to open
            0,                          // Reserved
            KEY_READ,                   // Security access mask
            &hBaseKey );                // Address of handle to open key
    if ( ERROR_SUCCESS != nError )
    {
        DOTRACE( ( _T("-  Failed: Cannot open registry key <%s> (%d/%d)"), szBaseKey, *pRC, _nOpenResult ) );
        DOTRACEERR( _T("    RegOpenKeyEx error %d\n    %s"), nError );
        return S_OK;
    }
    DOTRACE( ( _T("    Opened registry key HKLM\\%s"), szBaseKey ) );

    // If the DeviceName parameter is a string value in the base key,
    //   then a logical name was specified:
    //   Use the value's data as the physical device name.
    // Else the name is the physical device name.
    TCHAR szPhysicalDeviceName[ MAX_REGBUFFER_SIZE ];
    DWORD dwType;
    DWORD dwSize = sizeof( szPhysicalDeviceName );
    if ( ERROR_SUCCESS !=
         RegQueryValueEx(
            hBaseKey,                   // Handle to key to query
            _CW(DeviceName),            // Address of name of value to query
            0,                          // Reserved
            &dwType,                    // Address of buffer for value type
            (LPBYTE) szPhysicalDeviceName, // Address of data buffer
            &dwSize ) ||                // Address of data buffer size
         dwType != REG_SZ
       )
    {
        wcscpy( szPhysicalDeviceName, DeviceName );
        DOTRACE( ( _T("    DeviceName is not a LogicalName; treating as PhysicalName") ) );
    }
    else
    {
        NULTERMINATE(szPhysicalDeviceName);
        DOTRACE( ( _T("    DeviceName is a LogicalName; converted to PhysicalName <%s>"), szPhysicalDeviceName ) );
    }

    // Open the physical registry entry. Close the base key.
    //   If fails, then return error.
    HKEY hServiceKey;
    LONG nRegStat = RegOpenKeyEx(
            hBaseKey,                   // handle to open key
            szPhysicalDeviceName,       // address of name of subkey to open
            0,                          // reserved
            KEY_READ,                   // security access mask
            &hServiceKey );             // address of handle to open key
    RegCloseKey( hBaseKey );
    if ( ERROR_SUCCESS != nRegStat )
    {
        DOTRACE( ( _T("-  Failed: Cannot open DeviceName subkey (%d/%d)"), *pRC, _nOpenResult ) );
        DOTRACEERR( _T("    RegOpenKeyEx error %d\n    %s"), nRegStat );
        return S_OK;
    }
    DOTRACE( ( _T("    Opened DeviceName subkey") ) );

    // Initialize ResultCode and OpenResult for possible returns below.
    *pRC = SetRC( OPOS_E_NOSERVICE );
    _nOpenResult = OPOS_OR_REGPROGID;

    // Now get the Service Object's ProgID, which is the default value's data for the device's key.
    //   If fails, then return error.
    TCHAR sSOProgID[ MAX_REGBUFFER_SIZE ];
    dwSize = sizeof( sSOProgID );
    nRegStat = RegQueryValueEx(
            hServiceKey,                // Handle to key to query
            0,                          // Address of name of value to query
            0,                          // Reserved
            &dwType,                    // Address of buffer for value type
            (LPBYTE) sSOProgID,         // Address of data buffer
            &dwSize );                  // Address of data buffer size
    RegCloseKey( hServiceKey );
    if ( ERROR_SUCCESS != nRegStat || dwType != REG_SZ )
    {
        DOTRACE( ( _T("-  Failed: Cannot get ProgID from registry (%d/%d)"), *pRC, _nOpenResult ) );
        DOTRACEERR( _T("    RegOpenKeyEx error %d\n    %s"), nRegStat );
        return S_OK;
    }
    NULTERMINATE(sSOProgID);
    DOTRACE( ( _T("    DeviceName mapped to ProgID <%s>"), sSOProgID ) );

    // Convert the ProgID to a CLSID.
    CLSID SOClassID;
    hRC = CLSIDFromProgID(
            _CW(sSOProgID),             // Pointer to the ProgID
            &SOClassID );               // Pointer to the CLSID
    if ( S_OK != hRC )
    {
        DOTRACE( ( _T("-  Failed: Cannot convert ProgID to ClassID (%d/%d)"), *pRC, _nOpenResult ) );
        DOTRACEERR( _T("    CLSIDFromProgID error 0x%X\n    %s"), hRC );
        return S_OK;
    }
    DOTRACE( ( _T("    ProgID mapped to ClassID") ) );

    // Make the connection to the Service Object.
    //   We create an instance, get the IDispatch pointer, then release the IUnknown pointer.
    IUnknown* pUnknown;
    hRC = CoCreateInstance(
            SOClassID,                  // Class identifier (CLSID) of the object
            0,                          // Pointer to whether object is or isn't part of an aggregate
            CLSCTX_ALL,                 // Context for running executable code
            IID_IUnknown,               // Reference to the identifier of the interface
            (void**) &pUnknown);        // Address of output variable that receives the interface pointer requested in riid
    if ( S_OK != hRC )
    {
        _nOpenResult = OPOS_OR_CREATE;
        DOTRACE( ( _T("-  Failed: Cannot create Service Object (%d/%d)"), *pRC, _nOpenResult ) );
        DOTRACEERR( _T("    CoCreateInstance error 0x%X\n    %s"), hRC );
        return S_OK;
    }
    DOTRACE( ( _T("    Created Service Object") ) );

    hRC = pUnknown->QueryInterface(
            IID_IDispatch,              // Identifier of the requested interface
            (void**) &_pService );      // Address of output variable that receives the interface pointer requested in iid
    pUnknown->Release();                // Done with original pointer.
    if ( S_OK != hRC )
    {
        _nOpenResult = OPOS_OR_CREATE;
        DOTRACE( ( _T("-  Failed: Cannot get Service Object's Dispatch pointer (%d/%d)"), *pRC, _nOpenResult ) );
        DOTRACEERR( _T("    QueryInterface error 0x%X\n    %s"), hRC );
        return S_OK;
    }
    DOTRACE( ( _T("    Acquired Service Object's dispatch pointer") ) );

    // Get the dispatch IDs for the methods supported by the Service Object.
    //   Stop when we can't get one or when all are acquired.
    int nMethodCount = 0;
    while ( s_SOMethodNames[nMethodCount] != 0 )
    {
        _CWNCC MN( s_SOMethodNames[nMethodCount] ); // Init for conversion.
        OLECHAR* pMN = MN;                          // Assign pointer, converting to wide if needed.
        if ( S_OK !=
             _pService->GetIDsOfNames(
                IID_NULL, &pMN, 1, LOCALE_SYSTEM_DEFAULT, &_DispIDs[nMethodCount] )
           )
        {
            // If failed, do special cases:
            //  - If we failed the newer CloseService, then try Close before failing.
            if ( nMethodCount == nDICloseService )
                pMN = L"Close";
            //  - If we failed the newer COM-friendly name ClaimDevice or ReleaseDevice,
            //    then try the original name Claim or Release before failing.
            else if ( nMethodCount == nDIClaimDevice )
                pMN = L"Claim";
            else if ( nMethodCount == nDIReleaseDevice )
                pMN = L"Release";
            else                        // If not special case,
                break;                  //   stop.
            if ( S_OK !=
                 _pService->GetIDsOfNames(
                    IID_NULL, &pMN, 1, LOCALE_SYSTEM_DEFAULT, &_DispIDs[nMethodCount] )
               )
                break;                  // If special case but still not found, stop.
        }
        nMethodCount++;
    }

    // When debug mode, repeat above trying to get all methods, for later tracing.
    #ifdef _DEBUG
    int nAllMethods = nMethodCount;
    while ( s_SOMethodNames[nAllMethods] != 0 )
    {
        _CWNCC MN( s_SOMethodNames[nAllMethods] );  // Init for conversion.
        OLECHAR* pMN = MN;                          // Assign pointer, converting to wide if needed.
        if ( S_OK !=
             _pService->GetIDsOfNames(
                IID_NULL, &pMN, 1, LOCALE_SYSTEM_DEFAULT, &_DispIDs[nAllMethods] )
           )
        {
            pMN = 0;
            // If failed, do special cases:
            //  - If we failed the newer CloseService, then try Close before failing.
            if ( nAllMethods == nDICloseService )
                pMN = L"Close";
            //  - If we failed the newer COM-friendly name ClaimDevice or ReleaseDevice,
            //    then try the original name Claim or Release before failing.
            else if ( nAllMethods == nDIClaimDevice )
                pMN = L"Claim";
            else if ( nAllMethods == nDIReleaseDevice )
                pMN = L"Release";
            else                                // If not special case,
                _DispIDs[nAllMethods] = -123;   //   mark.
            if ( pMN != 0 && S_OK !=
                 _pService->GetIDsOfNames(
                    IID_NULL, &pMN, 1, LOCALE_SYSTEM_DEFAULT, &_DispIDs[nAllMethods] )
               )
                _DispIDs[nAllMethods] = -123;   // If special case but still not found, mark.
        }
        nAllMethods++;
    }
    #endif

    // The SO must at least support all of the initial release's methods,
    //   or we won't continue.
    if ( nMethodCount < s_RequiredMethodsPerRelease[0] )
    {
        _nOpenResult = OPOS_OR_BADIF;
        _pService->Release();
        DOTRACE( ( _T("-  Failed: Doesn't support all of initial release's methods (%d/%d)"), *pRC, _nOpenResult ) );
        DOTRACEMETHODS( _DispIDs, s_RequiredMethodsPerRelease[0] );
        return S_OK;
    }

    // Get our own dispatch pointer.
    //   Immediately release it -- saves releasing later,
    //   since it is just another reference to us.
    IDispatch* pDispatch = 0;
    CMVERIFY( S_OK == QueryInterface( IID_IDispatch, (void**) &pDispatch ) );
    if ( pDispatch != 0 )
        pDispatch->Release();

    // Now call the Service Object's OpenService method.
    OposVariant Vars[3];
    Vars[2].SetString( _CW(OPOS_CLASSKEY_EVRW), hRC );
    Vars[1].SetString( _CW(szPhysicalDeviceName), hRC );
    Vars[0].SetDispatch_Ptr( pDispatch, hRC );
    if ( FAILED(hRC) )
    {
        _pService->Release();
        DOTRACEERR( _T("-  Failed: Setup for OpenService call 0x%X\n    %s"), hRC );
        return hRC;
    }
    hRC = DoInvoke( DEBUGPARAM("Open-OpenService") S_OK, Vars, 3, nDIOpenService, pRC, false );

    // If the OpenService fails, then set result code and return.
    if ( hRC != S_OK || *pRC != OPOS_SUCCESS )
    {
        // Set the default open result code.
        _nOpenResult = OPOS_OR_FAILEDOPEN;
        // If not a COM error, and the SO supports the GetOpenResult method,
        //   then call it to get the open result code.
        if ( hRC == S_OK )
        {
            // Try to get DispID of the method.
            OLECHAR* pMN = L"GetOpenResult";
            DISPID DispID;
            if ( S_OK ==
                 _pService->GetIDsOfNames(
                    IID_NULL, &pMN, 1, LOCALE_SYSTEM_DEFAULT, &DispID )
               )
            {
                // If method exists, set up and call the SO's get property open result method.
                OposVariantResult VarResult;
                DISPPARAMS Disp = { NULL, NULL, 0, 0 };
                if ( S_OK == _pService->Invoke(
                        DispID, IID_NULL, LOCALE_USER_DEFAULT,
                        DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL )
                   )
                {
                    // If method succeeds, convert (if needed) to long and set open result code.
                    HRESULT hRCTmp;
                    VarResult.ChangeLONG( &_nOpenResult, hRCTmp );
                }
            }
        }
        // Release the SO and return its OpenService HRESULT.
        _pService->Release();
        DOTRACE( ( _T("-  Failed: Service Object's OpenService reported failure (%d/%d)"), *pRC, _nOpenResult ) );
        DOTRACEERR( _T("    Invoke error 0x%X\n    %s"), hRC );
        return hRC;
    }
    DOTRACE( ( _T("    Service Object's OpenService succeeded") ) );

    // Prepare for events.
    EventOpen();

    // The CO and SO are now open.
    _bOpened = true;

    // Trace some service object information, and initialize debug data.
    #ifdef _DEBUG
    DOTRACE( ( _T("    <Start> Service Object Properties.") ) );
    BSTR bstrSOInfo;
    GetOposProp( DEBUGPARAM("Open-ServiceObjectDescription") PIDX_ServiceObjectDescription, &bstrSOInfo, 0 );
    SysFreeString(bstrSOInfo);
    GetOposProp( DEBUGPARAM("Open-DeviceDescription") PIDX_DeviceDescription, &bstrSOInfo, 0 );
    SysFreeString(bstrSOInfo);
    GetOposProp( DEBUGPARAM("Open-DeviceName") PIDX_DeviceName, &bstrSOInfo, 0 );
    SysFreeString(bstrSOInfo);
    DOTRACE( ( _T("    <End> Service Object Properties.") ) );
    #endif

    // Now do some versioning support checks...
    bool bBadSO = false;

    //  - Get the SO's version, and determine the major and minor version.
    long nSOVersion;
    GetOposProp( DEBUGPARAM("Open-ServiceObjectVersion") PIDX_ServiceObjectVersion, &nSOVersion, 0 );
    _nSOMajor = nSOVersion / 1000000;
    _nSOMinor = ( nSOVersion / 1000 ) % 1000;

    //  - If major version is not 1, then bad SO.
    if ( _nSOMajor != 1 )
    {
        _nOpenResult = OPOS_OR_BADVERSION;
        bBadSO = true;
        DOTRACE( ( _T("-  Failed: Service Object's major version is not 1 (%d/%d)"), OPOS_E_NOSERVICE, _nOpenResult ) );
    }

    //  - If SO doesn't support enough methods, then bad SO.
    else
    {
        long nReqMethodIndex = sizeof(s_RequiredMethodsPerRelease)/sizeof(int) - 1;
        // Shouldn't have SO with release below control's first release, but check anyway.
        if ( _nSOMinor < MinorReleaseInitial )
            nReqMethodIndex = 0;
        // If SO release is below that supported by this control, use its release's methods.
        else if ( nReqMethodIndex > _nSOMinor - MinorReleaseInitial )
            nReqMethodIndex = _nSOMinor - MinorReleaseInitial;
        // Set the maximum method index.
        _nMaxMethod = s_RequiredMethodsPerRelease[ nReqMethodIndex ];
        // Ensure that the SO supports the methods that it claims to support.
        if ( nMethodCount < _nMaxMethod )
        {
            _nOpenResult = OPOS_OR_BADIF;
            bBadSO = true;
            DOTRACE( ( _T("-  Failed: Doesn't support all of its release's methods (%d/%d)"), OPOS_E_NOSERVICE, _nOpenResult ) );
            DOTRACEMETHODS( _DispIDs, _nMaxMethod );
        }
    }

    // If bad SO, then fail the open.
    if ( bBadSO )
    {
        Close( pRC );
        *pRC = SetRC( OPOS_E_NOSERVICE );
        return S_OK;
    }

    // If CO OnFreezeEvents(TRUE) method has been called before open then freeze
    //   events in the SO at this time.
    if ( _nCOFreezeEventCount )
        SetCOFreezeEvents( TRUE );

    // Everything went okay, so return success.
    SetRC();
    *pRC = OPOS_SUCCESS;
    _nOpenResult = OPOS_SUCCESS;
    DOTRACE( ( _T("-  Success (0/0)") ) );
    return S_OK;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::Close( long *pRC )
{
    SetRC();

    // If not opened, set return code.
    if ( ! _bOpened )
    {
        *pRC = OPOS_E_CLOSED;
        DOTRACE( ( _T("*Close [Function]  RC=%d"), *pRC ) );
        return S_OK;
    }

    // Events are no longer legal.
    EventPreCloseRelease();

    // Call down into Service Object to close the control.
    HRESULT hRC = DoInvoke( DEBUGPARAM("Close-CloseService") S_OK, NULL, 0, nDICloseService, pRC, false );

    // Release the connection to the Service Object.
    _pService->Release();

    // Close down events.
    EventClose();

    // We are now closed.
    _bOpened = false;

    DOTRACE( ( _T("*Close [Function]  RC=%d"), *pRC ) );
    return hRC;
}

/////////////////////////////////////////////////////////////////////////////
// Claim, Release
/////////////////////////////////////////////////////////////////////////////

STDMETHODIMP COPOSElectronicValueRW::ClaimDevice( long Timeout, long *pRC )
{
    SetRC();

    // If not opened, set return code.
    if ( ! _bOpened )
    {
        *pRC = OPOS_E_CLOSED;
        DOTRACEV( ( _T("*ClaimDevice [Function] -- Closed") ) );
        return S_OK;
    }

    // Initialize so that events are allowed.
    EventClaim();

    // Call down into the Service Object to execute this method.
    OposVariant Var;
    Var.SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("ClaimDevice") S_OK, &Var, 1, nDIClaimDevice, pRC, false );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::ReleaseDevice( long *pRC )
{
    SetRC();

    // If not opened, set return code.
    if ( ! _bOpened )
    {
        *pRC = OPOS_E_CLOSED;
        DOTRACEV( ( _T("*ReleaseDevice [Function] -- Closed") ) );
        return S_OK;
    }

    // Events are no longer legal.
    EventPreCloseRelease();

    // Call down into the Service Object to execute this method.
    return DoInvoke( DEBUGPARAM("ReleaseDevice") S_OK, NULL, 0, nDIReleaseDevice, pRC, false );
}

/////////////////////////////////////////////////////////////////////////////
// SOProcessID
/////////////////////////////////////////////////////////////////////////////

STDMETHODIMP COPOSElectronicValueRW::SOProcessID( long *pProcessID )
{
    *pProcessID = GetCurrentProcessId();
    DOTRACEV( ( _T("*SOProcessID: 0x%X"), *pProcessID ) );
    return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
// The other methods.
/////////////////////////////////////////////////////////////////////////////

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!! Release 1.12
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

STDMETHODIMP COPOSElectronicValueRW::CheckHealth( 
    /*[in]*/ LONG Level, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Var;
    Var.SetLONG( Level );
    return DoInvoke( DEBUGPARAM("CheckHealth") S_OK, &Var, 1, nDICheckHealth, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::ClearInput( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("ClearInput") S_OK, NULL, 0, nDIClearInput, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::ClearOutput( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("ClearOutput") S_OK, NULL, 0, nDIClearOutput, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::DirectIO( 
    /*[in]*/ LONG Command, 
    /*[in, out]*/ LONG* pData, 
    /*[in, out]*/ BSTR* pString, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[3];
    HRESULT hRC = S_OK;
    Vars[2].SetLONG( Command );
    Vars[1].SetLONG_Ptr( pData, hRC );
    Vars[0].SetBSTR_InOutPtr( pString, hRC );
    return DoInvoke( DEBUGPARAM("DirectIO") hRC, Vars, 3, nDIDirectIO, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::ResetStatistics( 
    /*[in]*/ BSTR StatisticsBuffer, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Var;
    HRESULT hRC = S_OK;
    Var.SetBSTR( StatisticsBuffer, hRC );
    return DoInvoke( DEBUGPARAM("ResetStatistics") hRC, &Var, 1, nDIResetStatistics, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::RetrieveStatistics( 
    /*[in, out]*/ BSTR* pStatisticsBuffer, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Var;
    HRESULT hRC = S_OK;
    Var.SetBSTR_InOutPtr( pStatisticsBuffer, hRC );
    return DoInvoke( DEBUGPARAM("RetrieveStatistics") hRC, &Var, 1, nDIRetrieveStatistics, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::UpdateStatistics( 
    /*[in]*/ BSTR StatisticsBuffer, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Var;
    HRESULT hRC = S_OK;
    Var.SetBSTR( StatisticsBuffer, hRC );
    return DoInvoke( DEBUGPARAM("UpdateStatistics") hRC, &Var, 1, nDIUpdateStatistics, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::CompareFirmwareVersion( 
    /*[in]*/ BSTR FirmwareFileName, 
    /*[out]*/ LONG* pResult, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    HRESULT hRC = S_OK;
    Vars[1].SetBSTR( FirmwareFileName, hRC );
    Vars[0].SetLONG_Ptr( pResult, hRC );
    return DoInvoke( DEBUGPARAM("CompareFirmwareVersion") hRC, Vars, 2, nDICompareFirmwareVersion, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::UpdateFirmware( 
    /*[in]*/ BSTR FirmwareFileName, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Var;
    HRESULT hRC = S_OK;
    Var.SetBSTR( FirmwareFileName, hRC );
    return DoInvoke( DEBUGPARAM("UpdateFirmware") hRC, &Var, 1, nDIUpdateFirmware, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::ClearInputProperties( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("ClearInputProperties") S_OK, NULL, 0, nDIClearInputProperties, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::AccessLog( 
    /*[in]*/ LONG SequenceNumber, 
    /*[in]*/ LONG Type, 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[3];
    Vars[2].SetLONG( SequenceNumber );
    Vars[1].SetLONG( Type );
    Vars[0].SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("AccessLog") S_OK, Vars, 3, nDIAccessLog, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::ActivateService( 
    /*[in, out]*/ LONG* pData, 
    /*[in, out]*/ BSTR* pObj, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    HRESULT hRC = S_OK;
    Vars[1].SetLONG_Ptr( pData, hRC );
    Vars[0].SetBSTR_InOutPtr( pObj, hRC );
    return DoInvoke( DEBUGPARAM("ActivateService") hRC, Vars, 2, nDIActivateService, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::AddValue( 
    /*[in]*/ LONG SequenceNumber, 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    Vars[1].SetLONG( SequenceNumber );
    Vars[0].SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("AddValue") S_OK, Vars, 2, nDIAddValue, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::BeginDetection( 
    /*[in]*/ LONG Type, 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    Vars[1].SetLONG( Type );
    Vars[0].SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("BeginDetection") S_OK, Vars, 2, nDIBeginDetection, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::BeginRemoval( 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Var;
    Var.SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("BeginRemoval") S_OK, &Var, 1, nDIBeginRemoval, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::CancelValue( 
    /*[in]*/ LONG SequenceNumber, 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    Vars[1].SetLONG( SequenceNumber );
    Vars[0].SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("CancelValue") S_OK, Vars, 2, nDICancelValue, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::CaptureCard( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("CaptureCard") S_OK, NULL, 0, nDICaptureCard, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::EndDetection( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("EndDetection") S_OK, NULL, 0, nDIEndDetection, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::EndRemoval( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("EndRemoval") S_OK, NULL, 0, nDIEndRemoval, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::EnumerateCardServices( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("EnumerateCardServices") S_OK, NULL, 0, nDIEnumerateCardServices, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::LockTerminal( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("LockTerminal") S_OK, NULL, 0, nDILockTerminal, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::ReadValue( 
    /*[in]*/ LONG SequenceNumber, 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    Vars[1].SetLONG( SequenceNumber );
    Vars[0].SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("ReadValue") S_OK, Vars, 2, nDIReadValue, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::SubtractValue( 
    /*[in]*/ LONG SequenceNumber, 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    Vars[1].SetLONG( SequenceNumber );
    Vars[0].SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("SubtractValue") S_OK, Vars, 2, nDISubtractValue, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::TransactionAccess( 
    /*[in]*/ LONG Control, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Var;
    Var.SetLONG( Control );
    return DoInvoke( DEBUGPARAM("TransactionAccess") S_OK, &Var, 1, nDITransactionAccess, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::UnlockTerminal( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("UnlockTerminal") S_OK, NULL, 0, nDIUnlockTerminal, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::UpdateKey( 
    /*[in, out]*/ LONG* pData, 
    /*[in, out]*/ BSTR* pObj, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    HRESULT hRC = S_OK;
    Vars[1].SetLONG_Ptr( pData, hRC );
    Vars[0].SetBSTR_InOutPtr( pObj, hRC );
    return DoInvoke( DEBUGPARAM("UpdateKey") hRC, Vars, 2, nDIUpdateKey, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::WriteValue( 
    /*[in]*/ LONG SequenceNumber, 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    Vars[1].SetLONG( SequenceNumber );
    Vars[0].SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("WriteValue") S_OK, Vars, 2, nDIWriteValue, pRC );
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!! Release 1.13
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!! Release 1.14
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

STDMETHODIMP COPOSElectronicValueRW::ClearParameterInformation( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("ClearParameterInformation") S_OK, NULL, 0, nDIClearParameterInformation, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::QueryLastSuccessfulTransactionResult( 
    /*[out, retval]*/ long* pRC )
{
    return DoInvoke( DEBUGPARAM("QueryLastSuccessfulTransactionResult") S_OK, NULL, 0, nDIQueryLastSuccessfulTransactionResult, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::RetrieveResultInformation( 
    /*[in]*/ BSTR Name, 
    /*[in, out]*/ BSTR* pValue, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    HRESULT hRC = S_OK;
    Vars[1].SetBSTR( Name, hRC );
    Vars[0].SetBSTR_InOutPtr( pValue, hRC );
    return DoInvoke( DEBUGPARAM("RetrieveResultInformation") hRC, Vars, 2, nDIRetrieveResultInformation, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::SetParameterInformation( 
    /*[in]*/ BSTR Name, 
    /*[in]*/ BSTR Value, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    HRESULT hRC = S_OK;
    Vars[1].SetBSTR( Name, hRC );
    Vars[0].SetBSTR( Value, hRC );
    return DoInvoke( DEBUGPARAM("SetParameterInformation") hRC, Vars, 2, nDISetParameterInformation, pRC );
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!! Release 1.15
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

STDMETHODIMP COPOSElectronicValueRW::AccessData( 
    /*[in]*/ LONG DataType, 
    /*[in, out]*/ LONG* pData, 
    /*[in, out]*/ BSTR* pObj, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[3];
    HRESULT hRC = S_OK;
    Vars[2].SetLONG( DataType );
    Vars[1].SetLONG_Ptr( pData, hRC );
    Vars[0].SetBSTR_InOutPtr( pObj, hRC );
    return DoInvoke( DEBUGPARAM("AccessData") hRC, Vars, 3, nDIAccessData, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::ActivateEVService( 
    /*[in, out]*/ LONG* pData, 
    /*[in, out]*/ BSTR* pObj, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    HRESULT hRC = S_OK;
    Vars[1].SetLONG_Ptr( pData, hRC );
    Vars[0].SetBSTR_InOutPtr( pObj, hRC );
    return DoInvoke( DEBUGPARAM("ActivateEVService") hRC, Vars, 2, nDIActivateEVService, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::CheckServiceRegistrationToMedium( 
    /*[in]*/ LONG SequenceNumber, 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    Vars[1].SetLONG( SequenceNumber );
    Vars[0].SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("CheckServiceRegistrationToMedium") S_OK, Vars, 2, nDICheckServiceRegistrationToMedium, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::CloseDailyEVService( 
    /*[in, out]*/ LONG* pData, 
    /*[in, out]*/ BSTR* pObj, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    HRESULT hRC = S_OK;
    Vars[1].SetLONG_Ptr( pData, hRC );
    Vars[0].SetBSTR_InOutPtr( pObj, hRC );
    return DoInvoke( DEBUGPARAM("CloseDailyEVService") hRC, Vars, 2, nDICloseDailyEVService, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::DeactivateEVService( 
    /*[in, out]*/ LONG* pData, 
    /*[in, out]*/ BSTR* pObj, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    HRESULT hRC = S_OK;
    Vars[1].SetLONG_Ptr( pData, hRC );
    Vars[0].SetBSTR_InOutPtr( pObj, hRC );
    return DoInvoke( DEBUGPARAM("DeactivateEVService") hRC, Vars, 2, nDIDeactivateEVService, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::OpenDailyEVService( 
    /*[in, out]*/ LONG* pData, 
    /*[in, out]*/ BSTR* pObj, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    HRESULT hRC = S_OK;
    Vars[1].SetLONG_Ptr( pData, hRC );
    Vars[0].SetBSTR_InOutPtr( pObj, hRC );
    return DoInvoke( DEBUGPARAM("OpenDailyEVService") hRC, Vars, 2, nDIOpenDailyEVService, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::RegisterServiceToMedium( 
    /*[in]*/ LONG SequenceNumber, 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    Vars[1].SetLONG( SequenceNumber );
    Vars[0].SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("RegisterServiceToMedium") S_OK, Vars, 2, nDIRegisterServiceToMedium, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::UnregisterServiceToMedium( 
    /*[in]*/ LONG SequenceNumber, 
    /*[in]*/ LONG Timeout, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[2];
    Vars[1].SetLONG( SequenceNumber );
    Vars[0].SetLONG( Timeout );
    return DoInvoke( DEBUGPARAM("UnregisterServiceToMedium") S_OK, Vars, 2, nDIUnregisterServiceToMedium, pRC );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::UpdateData( 
    /*[in]*/ LONG DataType, 
    /*[in, out]*/ LONG* pData, 
    /*[in, out]*/ BSTR* pObj, 
    /*[out, retval]*/ long* pRC )
{
    OposVariant Vars[3];
    HRESULT hRC = S_OK;
    Vars[2].SetLONG( DataType );
    Vars[1].SetLONG_Ptr( pData, hRC );
    Vars[0].SetBSTR_InOutPtr( pObj, hRC );
    return DoInvoke( DEBUGPARAM("UpdateData") hRC, Vars, 3, nDIUpdateData, pRC );
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// Properties
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   FreezeEvents
//   ResultCode
//   State
//   ControlObjectDescription
//   ControlObjectVersion
//   OpenResult
/////////////////////////////////////////////////////////////////////////////

STDMETHODIMP COPOSElectronicValueRW::get_FreezeEvents( VARIANT_BOOL *pFreezeEvents )
{
    return GetOposProp( DEBUGPARAM("FreezeEvents") PIDX_FreezeEvents, pFreezeEvents );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::put_FreezeEvents( VARIANT_BOOL FreezeEvents )
{
    SetRC();

    // If not opened, do nothing.
    if ( ! _bOpened )
    {
        DOTRACEV( ( _T("*FreezeEvents [Set] -- Closed") ) );
        return S_OK;
    }

    if ( FreezeEvents )
    {
        // Call down into the Service Object first to set the property value.
        SetOposProp( DEBUGPARAM("FreezeEvents") PIDX_FreezeEvents, FreezeEvents ); // First tell the SO the new state.
        _bFreezeState = true;                           // Then update ours.
    }
    else
    {
        // Update our state first, then tell the SO.
        // This avoids a lockup in the event firing object's DoEvent() routine
        //   that would occur if the SO calls an event from its property update method.
        _bFreezeState = false;
        SetOposProp( DEBUGPARAM("FreezeEvents") PIDX_FreezeEvents, FreezeEvents );
    }

    return S_OK;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_ResultCode( long *pResultCode )
{
    if ( ! _bOpened )                               // If not open,
    {
        *pResultCode = OPOS_E_CLOSED;               //   then return "closed".
        DOTRACEV( ( _T("*ResultCode [Get] -- Closed") ) );
    }
    else if ( _nCOResultCode != -1 )                // If the control object has to report a status,
    {
        *pResultCode = _nCOResultCode;              //   then return it.
        DOTRACEV( ( _T("*ResultCode [Get]: %d -- from CO"), _nCOResultCode ) );
    }
    else
        GetOposProp( DEBUGPARAM("ResultCode") PIDX_ResultCode, pResultCode );// Otherwise go to SO.

    return S_OK;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_State( long *pState )
{
    if ( ! _bOpened )                           // If not open,
    {
        *pState = OPOS_S_CLOSED;                //   then return "closed".
        DOTRACEV( ( _T("*State [Get] -- Closed") ) );
    }
    else
        GetOposProp( DEBUGPARAM("State") PIDX_State, pState ); // Otherwise go to SO.

    return S_OK;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_ControlObjectDescription( BSTR *pControlObjectDescription )
{
    *pControlObjectDescription = ::SysAllocString( _CW(g_ControlDescription) );
    DOTRACEV( ( _T("*ControlObjectDescription [Get]: <%hs>"), g_ControlDescription ) );
    return S_OK;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_ControlObjectVersion( long *pControlObjectVersion )
{
    *pControlObjectVersion = g_ControlVersion;
    DOTRACEV( ( _T("*ControlObjectVersion [Get]: %d"), g_ControlVersion ) );
    return S_OK;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_OpenResult( long *pOpenResult )
{
    *pOpenResult = _nOpenResult;
    DOTRACEV( ( _T("*OpenResult [Get]: %d"), _nOpenResult ) );
    return S_OK;
}


/////////////////////////////////////////////////////////////////////////////
// The other properties.
/////////////////////////////////////////////////////////////////////////////

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!! Release 1.12
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

STDMETHODIMP COPOSElectronicValueRW::get_AutoDisable( /*[out, retval]*/ VARIANT_BOOL* pAutoDisable )
{
    return GetOposProp( DEBUGPARAM("AutoDisable") PIDX_AutoDisable, pAutoDisable, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_AutoDisable( /*[in]*/ VARIANT_BOOL AutoDisable )
{
    return SetOposProp( DEBUGPARAM("AutoDisable") PIDX_AutoDisable, AutoDisable, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_BinaryConversion( /*[out, retval]*/ LONG* pBinaryConversion )
{
    return GetOposProp( DEBUGPARAM("BinaryConversion") PIDX_BinaryConversion, pBinaryConversion, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_BinaryConversion( /*[in]*/ LONG BinaryConversion )
{
    IFDEBUG( _nBinaryConversion = BinaryConversion);
    return SetOposProp( DEBUGPARAM("BinaryConversion") PIDX_BinaryConversion, BinaryConversion, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapPowerReporting( /*[out, retval]*/ LONG* pCapPowerReporting )
{
    return GetOposProp( DEBUGPARAM("CapPowerReporting") PIDX_CapPowerReporting, pCapPowerReporting, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CheckHealthText( /*[out, retval]*/ BSTR* pCheckHealthText )
{
    return GetOposProp( DEBUGPARAM("CheckHealthText") PIDX_CheckHealthText, pCheckHealthText, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_Claimed( /*[out, retval]*/ VARIANT_BOOL* pClaimed )
{
    return GetOposProp( DEBUGPARAM("Claimed") PIDX_Claimed, pClaimed, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_DataCount( /*[out, retval]*/ LONG* pDataCount )
{
    return GetOposProp( DEBUGPARAM("DataCount") PIDX_DataCount, pDataCount, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_DataEventEnabled( /*[out, retval]*/ VARIANT_BOOL* pDataEventEnabled )
{
    return GetOposProp( DEBUGPARAM("DataEventEnabled") PIDX_DataEventEnabled, pDataEventEnabled, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_DataEventEnabled( /*[in]*/ VARIANT_BOOL DataEventEnabled )
{
    return SetOposProp( DEBUGPARAM("DataEventEnabled") PIDX_DataEventEnabled, DataEventEnabled, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_DeviceEnabled( /*[out, retval]*/ VARIANT_BOOL* pDeviceEnabled )
{
    return GetOposProp( DEBUGPARAM("DeviceEnabled") PIDX_DeviceEnabled, pDeviceEnabled, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_DeviceEnabled( /*[in]*/ VARIANT_BOOL DeviceEnabled )
{
    return SetOposProp( DEBUGPARAM("DeviceEnabled") PIDX_DeviceEnabled, DeviceEnabled, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_OutputID( /*[out, retval]*/ LONG* pOutputID )
{
    return GetOposProp( DEBUGPARAM("OutputID") PIDX_OutputID, pOutputID, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_PowerNotify( /*[out, retval]*/ LONG* pPowerNotify )
{
    return GetOposProp( DEBUGPARAM("PowerNotify") PIDX_PowerNotify, pPowerNotify, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_PowerNotify( /*[in]*/ LONG PowerNotify )
{
    return SetOposProp( DEBUGPARAM("PowerNotify") PIDX_PowerNotify, PowerNotify, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_PowerState( /*[out, retval]*/ LONG* pPowerState )
{
    return GetOposProp( DEBUGPARAM("PowerState") PIDX_PowerState, pPowerState, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_ResultCodeExtended( /*[out, retval]*/ LONG* pResultCodeExtended )
{
    return GetOposProp( DEBUGPARAM("ResultCodeExtended") PIDX_ResultCodeExtended, pResultCodeExtended, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_ServiceObjectDescription( /*[out, retval]*/ BSTR* pServiceObjectDescription )
{
    return GetOposProp( DEBUGPARAM("ServiceObjectDescription") PIDX_ServiceObjectDescription, pServiceObjectDescription, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_ServiceObjectVersion( /*[out, retval]*/ LONG* pServiceObjectVersion )
{
    return GetOposProp( DEBUGPARAM("ServiceObjectVersion") PIDX_ServiceObjectVersion, pServiceObjectVersion, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_DeviceDescription( /*[out, retval]*/ BSTR* pDeviceDescription )
{
    return GetOposProp( DEBUGPARAM("DeviceDescription") PIDX_DeviceDescription, pDeviceDescription, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_DeviceName( /*[out, retval]*/ BSTR* pDeviceName )
{
    return GetOposProp( DEBUGPARAM("DeviceName") PIDX_DeviceName, pDeviceName, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapStatisticsReporting( /*[out, retval]*/ VARIANT_BOOL* pCapStatisticsReporting )
{
    return GetOposProp( DEBUGPARAM("CapStatisticsReporting") PIDX_CapStatisticsReporting, pCapStatisticsReporting, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapUpdateStatistics( /*[out, retval]*/ VARIANT_BOOL* pCapUpdateStatistics )
{
    return GetOposProp( DEBUGPARAM("CapUpdateStatistics") PIDX_CapUpdateStatistics, pCapUpdateStatistics, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapCompareFirmwareVersion( /*[out, retval]*/ VARIANT_BOOL* pCapCompareFirmwareVersion )
{
    return GetOposProp( DEBUGPARAM("CapCompareFirmwareVersion") PIDX_CapCompareFirmwareVersion, pCapCompareFirmwareVersion, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapUpdateFirmware( /*[out, retval]*/ VARIANT_BOOL* pCapUpdateFirmware )
{
    return GetOposProp( DEBUGPARAM("CapUpdateFirmware") PIDX_CapUpdateFirmware, pCapUpdateFirmware, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_AccountNumber( /*[out, retval]*/ BSTR* pAccountNumber )
{
    return GetOposProp( DEBUGPARAM("AccountNumber") PIDXEvrw_AccountNumber, pAccountNumber, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_AdditionalSecurityInformation( /*[out, retval]*/ BSTR* pAdditionalSecurityInformation )
{
    return GetOposProp( DEBUGPARAM("AdditionalSecurityInformation") PIDXEvrw_AdditionalSecurityInformation, pAdditionalSecurityInformation, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_AdditionalSecurityInformation( /*[in]*/ BSTR AdditionalSecurityInformation )
{
    return SetOposProp( DEBUGPARAM("AdditionalSecurityInformation") PIDXEvrw_AdditionalSecurityInformation, AdditionalSecurityInformation, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_Amount( /*[out, retval]*/ CURRENCY* pAmount )
{
    DOTRACEV( ( _T("+Amount [Get]") ) );

    // Initialize return value.
    HRESULT hRC = 0;
    pAmount->int64 = 0;

    // If open...
    if ( _bOpened )
    {
        // Set up and call the SO method that gets the currency property.
        OposVariant VarResult;
        DISPPARAMS Disp = { NULL, NULL, 0, 0 };
        hRC = _pService->Invoke(
                _DispIDs[nDIGetAmount], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );

        // If success, then set return result.
        if ( hRC == S_OK )
            VarResult.ChangeCURRENCY( pAmount, hRC );
    }

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pInfo = _T("");
    TCHAR pszHR[50];
    if ( !_bOpened )
        pInfo = _T(" -- Closed");
    else if ( hRC != 0 )
    {
        pInfo = pszHR;
        _stprintf( pszHR, _T(" -- COM error: HR = 0x%X"), hRC );
    }

    DOTRACEV( ( _T("-Amount [Get]: %s%s"), FormatCurrency(*pAmount), pInfo ) );
#endif

    return hRC;
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_Amount( /*[in]*/ CURRENCY Amount )
{
    DOTRACEV( ( _T("+Amount [Set]: %s"), FormatCurrency(Amount) ) );
    HRESULT hRC = 0;

    SetRC();                            // Clear COResultCode.

    // If open...
    if ( _bOpened )
    {
        // Set up and call the SO method that sets the currency property.
        OposVariant VarResult;
        OposVariant Var;
        Var.SetCURRENCY( Amount );
        DISPPARAMS Disp = { &Var, NULL, 1, 0 };
        hRC = _pService->Invoke(
                _DispIDs[nDISetAmount], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );
    }

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pInfo = _T("");
    TCHAR pszHR[50];
    if ( !_bOpened )
        pInfo = _T(" -- Closed");
    else if ( hRC != 0 )
    {
        pInfo = pszHR;
        _stprintf( pszHR, _T(" -- COM error: HR = 0x%X"), hRC );
    }

    DOTRACEV( ( _T("-Amount [Set]%s"), pInfo ) );
#endif

    return hRC;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_ApprovalCode( /*[out, retval]*/ BSTR* pApprovalCode )
{
    return GetOposProp( DEBUGPARAM("ApprovalCode") PIDXEvrw_ApprovalCode, pApprovalCode, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_ApprovalCode( /*[in]*/ BSTR ApprovalCode )
{
    return SetOposProp( DEBUGPARAM("ApprovalCode") PIDXEvrw_ApprovalCode, ApprovalCode, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_AsyncMode( /*[out, retval]*/ VARIANT_BOOL* pAsyncMode )
{
    return GetOposProp( DEBUGPARAM("AsyncMode") PIDXEvrw_AsyncMode, pAsyncMode, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_AsyncMode( /*[in]*/ VARIANT_BOOL AsyncMode )
{
    return SetOposProp( DEBUGPARAM("AsyncMode") PIDXEvrw_AsyncMode, AsyncMode, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_Balance( /*[out, retval]*/ CURRENCY* pBalance )
{
    DOTRACEV( ( _T("+Balance [Get]") ) );

    // Initialize return value.
    HRESULT hRC = 0;
    pBalance->int64 = 0;

    // If open...
    if ( _bOpened )
    {
        // Set up and call the SO method that gets the currency property.
        OposVariant VarResult;
        DISPPARAMS Disp = { NULL, NULL, 0, 0 };
        hRC = _pService->Invoke(
                _DispIDs[nDIGetBalance], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );

        // If success, then set return result.
        if ( hRC == S_OK )
            VarResult.ChangeCURRENCY( pBalance, hRC );
    }

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pInfo = _T("");
    TCHAR pszHR[50];
    if ( !_bOpened )
        pInfo = _T(" -- Closed");
    else if ( hRC != 0 )
    {
        pInfo = pszHR;
        _stprintf( pszHR, _T(" -- COM error: HR = 0x%X"), hRC );
    }

    DOTRACEV( ( _T("-Balance [Get]: %s%s"), FormatCurrency(*pBalance), pInfo ) );
#endif

    return hRC;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_BalanceOfPoint( /*[out, retval]*/ CURRENCY* pBalanceOfPoint )
{
    DOTRACEV( ( _T("+BalanceOfPoint [Get]") ) );

    // Initialize return value.
    HRESULT hRC = 0;
    pBalanceOfPoint->int64 = 0;

    // If open...
    if ( _bOpened )
    {
        // Set up and call the SO method that gets the currency property.
        OposVariant VarResult;
        DISPPARAMS Disp = { NULL, NULL, 0, 0 };
        hRC = _pService->Invoke(
                _DispIDs[nDIGetBalanceOfPoint], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );

        // If success, then set return result.
        if ( hRC == S_OK )
            VarResult.ChangeCURRENCY( pBalanceOfPoint, hRC );
    }

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pInfo = _T("");
    TCHAR pszHR[50];
    if ( !_bOpened )
        pInfo = _T(" -- Closed");
    else if ( hRC != 0 )
    {
        pInfo = pszHR;
        _stprintf( pszHR, _T(" -- COM error: HR = 0x%X"), hRC );
    }

    DOTRACEV( ( _T("-BalanceOfPoint [Get]: %s%s"), FormatCurrency(*pBalanceOfPoint), pInfo ) );
#endif

    return hRC;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapActivateService( /*[out, retval]*/ VARIANT_BOOL* pCapActivateService )
{
    return GetOposProp( DEBUGPARAM("CapActivateService") PIDXEvrw_CapActivateService, pCapActivateService, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapAddValue( /*[out, retval]*/ VARIANT_BOOL* pCapAddValue )
{
    return GetOposProp( DEBUGPARAM("CapAddValue") PIDXEvrw_CapAddValue, pCapAddValue, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapCancelValue( /*[out, retval]*/ VARIANT_BOOL* pCapCancelValue )
{
    return GetOposProp( DEBUGPARAM("CapCancelValue") PIDXEvrw_CapCancelValue, pCapCancelValue, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapCardSensor( /*[out, retval]*/ LONG* pCapCardSensor )
{
    return GetOposProp( DEBUGPARAM("CapCardSensor") PIDXEvrw_CapCardSensor, pCapCardSensor, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapDetectionControl( /*[out, retval]*/ LONG* pCapDetectionControl )
{
    return GetOposProp( DEBUGPARAM("CapDetectionControl") PIDXEvrw_CapDetectionControl, pCapDetectionControl, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapElectronicMoney( /*[out, retval]*/ VARIANT_BOOL* pCapElectronicMoney )
{
    return GetOposProp( DEBUGPARAM("CapElectronicMoney") PIDXEvrw_CapElectronicMoney, pCapElectronicMoney, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapEnumerateCardServices( /*[out, retval]*/ VARIANT_BOOL* pCapEnumerateCardServices )
{
    return GetOposProp( DEBUGPARAM("CapEnumerateCardServices") PIDXEvrw_CapEnumerateCardServices, pCapEnumerateCardServices, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapIndirectTransactionLog( /*[out, retval]*/ VARIANT_BOOL* pCapIndirectTransactionLog )
{
    return GetOposProp( DEBUGPARAM("CapIndirectTransactionLog") PIDXEvrw_CapIndirectTransactionLog, pCapIndirectTransactionLog, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapLockTerminal( /*[out, retval]*/ VARIANT_BOOL* pCapLockTerminal )
{
    return GetOposProp( DEBUGPARAM("CapLockTerminal") PIDXEvrw_CapLockTerminal, pCapLockTerminal, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapLogStatus( /*[out, retval]*/ VARIANT_BOOL* pCapLogStatus )
{
    return GetOposProp( DEBUGPARAM("CapLogStatus") PIDXEvrw_CapLogStatus, pCapLogStatus, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapMediumID( /*[out, retval]*/ VARIANT_BOOL* pCapMediumID )
{
    return GetOposProp( DEBUGPARAM("CapMediumID") PIDXEvrw_CapMediumID, pCapMediumID, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapPoint( /*[out, retval]*/ VARIANT_BOOL* pCapPoint )
{
    return GetOposProp( DEBUGPARAM("CapPoint") PIDXEvrw_CapPoint, pCapPoint, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapSubtractValue( /*[out, retval]*/ VARIANT_BOOL* pCapSubtractValue )
{
    return GetOposProp( DEBUGPARAM("CapSubtractValue") PIDXEvrw_CapSubtractValue, pCapSubtractValue, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapTransaction( /*[out, retval]*/ VARIANT_BOOL* pCapTransaction )
{
    return GetOposProp( DEBUGPARAM("CapTransaction") PIDXEvrw_CapTransaction, pCapTransaction, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapTransactionLog( /*[out, retval]*/ VARIANT_BOOL* pCapTransactionLog )
{
    return GetOposProp( DEBUGPARAM("CapTransactionLog") PIDXEvrw_CapTransactionLog, pCapTransactionLog, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapUnlockTerminal( /*[out, retval]*/ VARIANT_BOOL* pCapUnlockTerminal )
{
    return GetOposProp( DEBUGPARAM("CapUnlockTerminal") PIDXEvrw_CapUnlockTerminal, pCapUnlockTerminal, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapUpdateKey( /*[out, retval]*/ VARIANT_BOOL* pCapUpdateKey )
{
    return GetOposProp( DEBUGPARAM("CapUpdateKey") PIDXEvrw_CapUpdateKey, pCapUpdateKey, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapVoucher( /*[out, retval]*/ VARIANT_BOOL* pCapVoucher )
{
    return GetOposProp( DEBUGPARAM("CapVoucher") PIDXEvrw_CapVoucher, pCapVoucher, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapWriteValue( /*[out, retval]*/ VARIANT_BOOL* pCapWriteValue )
{
    return GetOposProp( DEBUGPARAM("CapWriteValue") PIDXEvrw_CapWriteValue, pCapWriteValue, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CardServiceList( /*[out, retval]*/ BSTR* pCardServiceList )
{
    return GetOposProp( DEBUGPARAM("CardServiceList") PIDXEvrw_CardServiceList, pCardServiceList, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CurrentService( /*[out, retval]*/ BSTR* pCurrentService )
{
    return GetOposProp( DEBUGPARAM("CurrentService") PIDXEvrw_CurrentService, pCurrentService, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_CurrentService( /*[in]*/ BSTR CurrentService )
{
    return SetOposProp( DEBUGPARAM("CurrentService") PIDXEvrw_CurrentService, CurrentService, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_DetectionControl( /*[out, retval]*/ VARIANT_BOOL* pDetectionControl )
{
    return GetOposProp( DEBUGPARAM("DetectionControl") PIDXEvrw_DetectionControl, pDetectionControl, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_DetectionControl( /*[in]*/ VARIANT_BOOL DetectionControl )
{
    return SetOposProp( DEBUGPARAM("DetectionControl") PIDXEvrw_DetectionControl, DetectionControl, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_DetectionStatus( /*[out, retval]*/ LONG* pDetectionStatus )
{
    return GetOposProp( DEBUGPARAM("DetectionStatus") PIDXEvrw_DetectionStatus, pDetectionStatus, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_ExpirationDate( /*[out, retval]*/ BSTR* pExpirationDate )
{
    return GetOposProp( DEBUGPARAM("ExpirationDate") PIDXEvrw_ExpirationDate, pExpirationDate, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_LastUsedDate( /*[out, retval]*/ BSTR* pLastUsedDate )
{
    return GetOposProp( DEBUGPARAM("LastUsedDate") PIDXEvrw_LastUsedDate, pLastUsedDate, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_LogStatus( /*[out, retval]*/ LONG* pLogStatus )
{
    return GetOposProp( DEBUGPARAM("LogStatus") PIDXEvrw_LogStatus, pLogStatus, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_MediumID( /*[out, retval]*/ BSTR* pMediumID )
{
    return GetOposProp( DEBUGPARAM("MediumID") PIDXEvrw_MediumID, pMediumID, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_MediumID( /*[in]*/ BSTR MediumID )
{
    return SetOposProp( DEBUGPARAM("MediumID") PIDXEvrw_MediumID, MediumID, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_Point( /*[out, retval]*/ CURRENCY* pPoint )
{
    DOTRACEV( ( _T("+Point [Get]") ) );

    // Initialize return value.
    HRESULT hRC = 0;
    pPoint->int64 = 0;

    // If open...
    if ( _bOpened )
    {
        // Set up and call the SO method that gets the currency property.
        OposVariant VarResult;
        DISPPARAMS Disp = { NULL, NULL, 0, 0 };
        hRC = _pService->Invoke(
                _DispIDs[nDIGetPoint], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );

        // If success, then set return result.
        if ( hRC == S_OK )
            VarResult.ChangeCURRENCY( pPoint, hRC );
    }

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pInfo = _T("");
    TCHAR pszHR[50];
    if ( !_bOpened )
        pInfo = _T(" -- Closed");
    else if ( hRC != 0 )
    {
        pInfo = pszHR;
        _stprintf( pszHR, _T(" -- COM error: HR = 0x%X"), hRC );
    }

    DOTRACEV( ( _T("-Point [Get]: %s%s"), FormatCurrency(*pPoint), pInfo ) );
#endif

    return hRC;
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_Point( /*[in]*/ CURRENCY Point )
{
    DOTRACEV( ( _T("+Point [Set]: %s"), FormatCurrency(Point) ) );
    HRESULT hRC = 0;

    SetRC();                            // Clear COResultCode.

    // If open...
    if ( _bOpened )
    {
        // Set up and call the SO method that sets the currency property.
        OposVariant VarResult;
        OposVariant Var;
        Var.SetCURRENCY( Point );
        DISPPARAMS Disp = { &Var, NULL, 1, 0 };
        hRC = _pService->Invoke(
                _DispIDs[nDISetPoint], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );
    }

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pInfo = _T("");
    TCHAR pszHR[50];
    if ( !_bOpened )
        pInfo = _T(" -- Closed");
    else if ( hRC != 0 )
    {
        pInfo = pszHR;
        _stprintf( pszHR, _T(" -- COM error: HR = 0x%X"), hRC );
    }

    DOTRACEV( ( _T("-Point [Set]%s"), pInfo ) );
#endif

    return hRC;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_ReaderWriterServiceList( /*[out, retval]*/ BSTR* pReaderWriterServiceList )
{
    return GetOposProp( DEBUGPARAM("ReaderWriterServiceList") PIDXEvrw_ReaderWriterServiceList, pReaderWriterServiceList, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_SequenceNumber( /*[out, retval]*/ LONG* pSequenceNumber )
{
    return GetOposProp( DEBUGPARAM("SequenceNumber") PIDXEvrw_SequenceNumber, pSequenceNumber, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_SettledAmount( /*[out, retval]*/ CURRENCY* pSettledAmount )
{
    DOTRACEV( ( _T("+SettledAmount [Get]") ) );

    // Initialize return value.
    HRESULT hRC = 0;
    pSettledAmount->int64 = 0;

    // If open...
    if ( _bOpened )
    {
        // Set up and call the SO method that gets the currency property.
        OposVariant VarResult;
        DISPPARAMS Disp = { NULL, NULL, 0, 0 };
        hRC = _pService->Invoke(
                _DispIDs[nDIGetSettledAmount], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );

        // If success, then set return result.
        if ( hRC == S_OK )
            VarResult.ChangeCURRENCY( pSettledAmount, hRC );
    }

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pInfo = _T("");
    TCHAR pszHR[50];
    if ( !_bOpened )
        pInfo = _T(" -- Closed");
    else if ( hRC != 0 )
    {
        pInfo = pszHR;
        _stprintf( pszHR, _T(" -- COM error: HR = 0x%X"), hRC );
    }

    DOTRACEV( ( _T("-SettledAmount [Get]: %s%s"), FormatCurrency(*pSettledAmount), pInfo ) );
#endif

    return hRC;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_SettledPoint( /*[out, retval]*/ CURRENCY* pSettledPoint )
{
    DOTRACEV( ( _T("+SettledPoint [Get]") ) );

    // Initialize return value.
    HRESULT hRC = 0;
    pSettledPoint->int64 = 0;

    // If open...
    if ( _bOpened )
    {
        // Set up and call the SO method that gets the currency property.
        OposVariant VarResult;
        DISPPARAMS Disp = { NULL, NULL, 0, 0 };
        hRC = _pService->Invoke(
                _DispIDs[nDIGetSettledPoint], IID_NULL, LOCALE_USER_DEFAULT,
                DISPATCH_METHOD, &Disp, &VarResult, NULL, NULL );

        // If success, then set return result.
        if ( hRC == S_OK )
            VarResult.ChangeCURRENCY( pSettledPoint, hRC );
    }

    // Trace result.
#ifdef _DEBUG
    LPCTSTR pInfo = _T("");
    TCHAR pszHR[50];
    if ( !_bOpened )
        pInfo = _T(" -- Closed");
    else if ( hRC != 0 )
    {
        pInfo = pszHR;
        _stprintf( pszHR, _T(" -- COM error: HR = 0x%X"), hRC );
    }

    DOTRACEV( ( _T("-SettledPoint [Get]: %s%s"), FormatCurrency(*pSettledPoint), pInfo ) );
#endif

    return hRC;
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_TransactionLog( /*[out, retval]*/ BSTR* pTransactionLog )
{
    return GetOposProp( DEBUGPARAM("TransactionLog") PIDXEvrw_TransactionLog, pTransactionLog, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_VoucherID( /*[out, retval]*/ BSTR* pVoucherID )
{
    return GetOposProp( DEBUGPARAM("VoucherID") PIDXEvrw_VoucherID, pVoucherID, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_VoucherID( /*[in]*/ BSTR VoucherID )
{
    return SetOposProp( DEBUGPARAM("VoucherID") PIDXEvrw_VoucherID, VoucherID, 12 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_VoucherIDList( /*[out, retval]*/ BSTR* pVoucherIDList )
{
    return GetOposProp( DEBUGPARAM("VoucherIDList") PIDXEvrw_VoucherIDList, pVoucherIDList, 12 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_VoucherIDList( /*[in]*/ BSTR VoucherIDList )
{
    return SetOposProp( DEBUGPARAM("VoucherIDList") PIDXEvrw_VoucherIDList, VoucherIDList, 12 /*MinorVersion*/ );
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!! Release 1.13
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!! Release 1.14
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

STDMETHODIMP COPOSElectronicValueRW::get_CapPINDevice( /*[out, retval]*/ VARIANT_BOOL* pCapPINDevice )
{
    return GetOposProp( DEBUGPARAM("CapPINDevice") PIDXEvrw_CapPINDevice, pCapPINDevice, 14 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_CapTrainingMode( /*[out, retval]*/ VARIANT_BOOL* pCapTrainingMode )
{
    return GetOposProp( DEBUGPARAM("CapTrainingMode") PIDXEvrw_CapTrainingMode, pCapTrainingMode, 14 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_PINEntry( /*[out, retval]*/ LONG* pPINEntry )
{
    return GetOposProp( DEBUGPARAM("PINEntry") PIDXEvrw_PINEntry, pPINEntry, 14 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_PINEntry( /*[in]*/ LONG PINEntry )
{
    return SetOposProp( DEBUGPARAM("PINEntry") PIDXEvrw_PINEntry, PINEntry, 14 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_TrainingModeState( /*[out, retval]*/ LONG* pTrainingModeState )
{
    return GetOposProp( DEBUGPARAM("TrainingModeState") PIDXEvrw_TrainingModeState, pTrainingModeState, 14 /*MinorVersion*/ );
}

//---------------------------------------------------------------------------

STDMETHODIMP COPOSElectronicValueRW::put_TrainingModeState( /*[in]*/ LONG TrainingModeState )
{
    return SetOposProp( DEBUGPARAM("TrainingModeState") PIDXEvrw_TrainingModeState, TrainingModeState, 14 /*MinorVersion*/ );
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!! Release 1.15
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

STDMETHODIMP COPOSElectronicValueRW::get_CapMembershipCertificate( /*[out, retval]*/ VARIANT_BOOL* pCapMembershipCertificate )
{
    return GetOposProp( DEBUGPARAM("CapMembershipCertificate") PIDXEvrw_CapMembershipCertificate, pCapMembershipCertificate, 15 /*MinorVersion*/ );
}

//===========================================================================

STDMETHODIMP COPOSElectronicValueRW::get_ServiceType( /*[out, retval]*/ LONG* pServiceType )
{
    return GetOposProp( DEBUGPARAM("ServiceType") PIDXEvrw_ServiceType, pServiceType, 15 /*MinorVersion*/ );
}


/////////////////////////////////////////////////////////////////////////////
// Debug build tracing support.
/////////////////////////////////////////////////////////////////////////////

#ifdef _DEBUG

#include <stdio.h>
#include <tchar.h>
#include <stdarg.h>

//===========================================================================
// Simple built-in tracing to a file...

#ifdef _FILETRACE

void COPOSElectronicValueRW::WriteTrace( LPCTSTR pFormat, ... )
{
    static TCHAR s_TraceFile[] = _T("C:\\OposCCO_ElectronicValueRW.log");
    static BOOL s_bFirst = TRUE;
    if (s_bFirst)
    {
        ::DeleteFile(s_TraceFile);
        s_bFirst = FALSE;
    }
    FILE* fTrace = _tfopen( s_TraceFile, _T("a") );
    if (fTrace)
    {
        va_list marker;
        va_start(marker, pFormat);
        _vftprintf( fTrace, pFormat, marker );
        putc( '\n', fTrace );
        fclose(fTrace);
    }
}

//===========================================================================
// Higher performance tracing using RCS trace software...

#else

#define OPOSCCOCLASS COPOSElectronicValueRW
#define RCSTRACENAME "OposCCO_ElectronicValueRW"
#include "UseRCSTrace.h"

#endif

//===========================================================================
// Trace support functions...

//## If error value is non-zero, convert to message and display.
void COPOSElectronicValueRW::WriteTraceError( LPCTSTR pFormat, DWORD dwError )
{
    if ( dwError != 0 )
    {
        // Convert HRESULT to message and display.
        LPTSTR pMsgBuf;
        DWORD dwChars = ::FormatMessage(
                FORMAT_MESSAGE_ALLOCATE_BUFFER |
                FORMAT_MESSAGE_FROM_SYSTEM |
                FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL,
                dwError,
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
                (LPTSTR) &pMsgBuf,
                0,
                NULL );
        if ( dwChars == 0 )
            pMsgBuf = _T("[Unknown]");
        else if ( pMsgBuf[dwChars-1] == '\n' )
            pMsgBuf[dwChars-1] = '\0';
        WriteTrace( pFormat, dwError, pMsgBuf );
        if ( dwChars > 0 )
            ::LocalFree(pMsgBuf);
    }
}

//## Output methods that are not implemented in Service Object.
void COPOSElectronicValueRW::WriteTraceMethods( DISPID* pDispID, int nMethods )
{
    for ( int i = 0; i < nMethods; i++, pDispID++ )
        if ( *pDispID == -123 )
            WriteTrace( _T("    %hs"), s_SOMethodNames[i] );
}

//## Output string.
void COPOSElectronicValueRW::WriteTraceString( LPCTSTR pszPrefix, BSTR bstr )
{
    // Get string length.
    int nLen = ::SysStringLen(bstr);

    // If empty...
    if ( nLen == 0 )
        DOTRACEV( ( _T("%s Length 0 <>"), pszPrefix ) );

    // If not empty...
    else
    {
        // Check the BString for non-ascii characters, and output the string.
        int i;
        for ( i = 0; i < nLen; i++ )
            if ( bstr[i] < 0x20 || 0x7F < bstr[i] )
                break;
        WriteTraceString( bstr, nLen * 2, i == nLen, 2 /*wide string*/,
            _T("%s Length %u"), pszPrefix, nLen );

        // If binary conversion in effect...
        if ( _nBinaryConversion != OPOS_BC_NONE )
        {
            #define LONIBBLE(x) ((x) & 0x0F)
            #define HINIBBLE(x) ((x) & 0xF0)

            OLECHAR* pSource = bstr;                        // Get source pointer.
            LPBYTE pDest = new BYTE[ ( nLen + 1 ) / 2 + 1 ];// Create destination buffer.
            int nDestLen = nLen;
            i = 0;

            // If decimal binary conversion...
            if ( _nBinaryConversion == OPOS_BC_DECIMAL && nDestLen % 3 == 0 )
            {
                nDestLen /= 3;                              // Bytes to create.
                for ( ; i < nDestLen; i++ )                 // Loop through all data.
                {                                           //
                    if ( !isdigit(pSource[0]) || !isdigit(pSource[1]) || !isdigit(pSource[2]) )
                        break;
                    pDest[i] = (BYTE)                       //  - Set destination character to
                        ( ( LONIBBLE(pSource[0]) * 10 +     //      Hundreds digit * 100 +
                              LONIBBLE(pSource[1])          //      Tens     digit *  10 +
                            ) * 10 +                        //
                            LONIBBLE(pSource[2]) );         //      Units    digit.
                    pSource += 3;                           //  - Move on to next source pair.
                }
            }

            // If nibble binary conversion...
            else if ( nDestLen % 2 == 0 )
            {
                nDestLen /= 2;                              // Bytes to create.
                for ( ; i < nDestLen; i++ )                 // Loop through all data.
                {                                           //
                    if ( HINIBBLE(pSource[0]) != 0x30 || HINIBBLE(pSource[1]) != 0x30 )
                        break;
                    pDest[i] = (BYTE)                       //  - Set destination character to
                        ( ( LONIBBLE(pSource[0]) << 4 ) |   //      first char's bits 3-0 as bits 7-4 ORed with
                            LONIBBLE(pSource[1]) );         //      second char's bits 3-0 as bits 3-0.
                    pSource += 2;                           //  - Move on to next source pair.
                }
            }

            // If was a valid binary converted string...
            if ( i == nDestLen )
            {
                pDest[i] = '\0';                            // End the string with a NUL.

                // Check the converted buffer for non-ascii characters, and output the string.
                for ( i = 0; i < nDestLen; i++ )
                    if ( pDest[i] < 0x20 || 0x7F < pDest[i] )
                        break;
                WriteTraceString( pDest, nDestLen, i == nDestLen, 1 /*narrow string*/,
                    _T("%s Length %u [BinConv]"), pszPrefix, nLen );
            }

            delete [] pDest;                                // Delete the destination buffer.
        }
    }
}

//## Output string helper.
#define WTS_LINELEN_MAX 50
void COPOSElectronicValueRW::WriteTraceString( void* pString, int nLen, BOOL bAscii, int nCharSize,
    LPCTSTR pszFormat, ... )
{
    TCHAR szBuffer[100+10];
    LPCTSTR pszPrintfString = ( nCharSize == 1 ? _T("hs") : _T("ls") );

    // Use the "list of arguments" version of printf.
    va_list va;
    va_start( va, pszFormat );
    _vsntprintf( szBuffer, 100, pszFormat, va );
    va_end(va);
    NULTERMINATE(szBuffer);

    // If all ascii, then output.
    if (bAscii)
    {
        // If less or equal to the maximum length we put out per line, then output on single line.
        if ( nLen <= WTS_LINELEN_MAX * nCharSize )
        {
            _tcscat( szBuffer, _T(" <%") );
            _tcscat( szBuffer, pszPrintfString );
            _tcscat( szBuffer, _T(">") );
            DOTRACEV( ( szBuffer, pString ) );
        }
        // If greater than maximum line length, then break into multiple lines.
        else
        {
            DOTRACEV( ( szBuffer, pString ) );
            _sntprintf( szBuffer, TSIZEOF(szBuffer), _T("  <%%.%u%s>"), WTS_LINELEN_MAX, pszPrintfString );
            NULTERMINATE(szBuffer);
            for ( int i = 0; i < nLen; i += WTS_LINELEN_MAX * nCharSize )
                DOTRACEV( ( szBuffer, (LPBYTE) pString + i ) );
        }
    }

    // If non-ascii data, then output.
    else
    {
        DOTRACEV( ( _T("%s [Contains non-ASCII]"), szBuffer ) );
        DODUMPV( pString, nLen );
    }
}

//## Output currency helper. Don't use floating point.
//    Examples: -123456 => "-12.3456"
//              123     => "0.0123"
//              -1      => "-0.0001"
LPCTSTR COPOSElectronicValueRW::FormatCurrency( CY cyCurrency )
{
    static TCHAR s_pszCurrency[30];
    LONGLONG nn = cyCurrency.int64 >= 0 ? cyCurrency.int64 : -cyCurrency.int64;
    int i;
    for ( i = 29; i > 24 || nn != 0; )
    {
        if ( i == 24+1 )
            s_pszCurrency[--i] = '.';
        s_pszCurrency[--i] = (TCHAR)( nn % 10 ) + '0';
        nn /= 10;
    }
    if ( cyCurrency.int64 < 0 )
        s_pszCurrency[--i] = '-';
    return &s_pszCurrency[i];
}
#endif

// End ElectronicValueRWImpl.cpp
