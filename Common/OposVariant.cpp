/****************************************************************************
**
** OposVariant.cpp -- Helper class for preparing and sending OPOS parameters
**                    as VARIANTS.
**
**      Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  1999/02/06 Initial version.                                     C. Monroe
**  1999/03/03 Revamp. No longer rely on CComVariant.
**  1999/03/22 Initialize VARIANTs before use.
**  2004/10/21 Correct ChangeBSTR to clear temporary "vt".
**  2006/08/17 Add VARIANT support.
**  2008/01/15 Clarify usage. Set "hr" on Set or Change failure.
**  2008/08/30 Correct SetDispatch_Ptr so interface pointer is
**               released on destruction.
**  2015/02/07 Comments updated to better explain the
**               OposVariant::Change* functions and the
**               OposDispParms class.
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

/*
    OposVariant is a wrapper class for the VARIANT structure. It is _not_ a
    general purpose wrapper. Instead, it is optimized for use within the OPOS CCOs.

    OposDispParms is a wrapper class for the DISPPARMS structure.

    See OposVariant.h for usage details.
*/

#include "stdafx.h"
#include "OposVariant.h"


//****************************************************************************
//****************************************************************************


//===========================================================================
// Boolean
//===========================================================================

void OposVariant::SetVARIANT_BOOL(VARIANT_BOOL bSrc)
{
    Clear();
    vt = VT_BOOL;
    boolVal = bSrc ? VARIANT_TRUE : VARIANT_FALSE;
}

//-----------------------------------------------------------------------

void OposVariant::SetVARIANT_BOOL_Ptr( VARIANT_BOOL* pbSrc, HRESULT& hr )
{
    Clear();

    // Validate that the parameter is not NULL.
    if ( pbSrc == 0 )
        hr = E_POINTER;

    // Set the variant.
    else
    {
        vt = VT_BYREF | VT_BOOL;
        pboolVal = pbSrc;
    }
}

//===========================================================================
// Long
//===========================================================================

LONG OposVariant::GetLONG()
{
    LONG nLong = 0;
    HRESULT hr;
    ChangeLONG( &nLong, hr );
    return nLong;
}

//-----------------------------------------------------------------------

void OposVariant::ChangeLONG( LONG* pLong, HRESULT& hr )
{
    // Validate that the parameter is not NULL.
    if ( pLong == 0 )
        hr = E_POINTER;

    // If pointer OK, set it after trying to coerce variant.
    else
    {
        // Try to coerce variant to a new variant of type LONG (I4).
        VARIANT var;
        var.vt = VT_EMPTY;
        hr = VariantChangeType(
            &var, static_cast<VARIANT*>(this), 0, VT_I4 );
        // If coercion was successful, then update to the LONG; else set to zero.
        *pLong = ( hr == S_OK ) ? var.lVal : 0;
    }
}

//-----------------------------------------------------------------------

void OposVariant::SetLONG(LONG nSrc)
{
    Clear();
    vt = VT_I4;
    lVal = nSrc;
}

//-----------------------------------------------------------------------

void OposVariant::SetLONG_Ptr( LONG* pnSrc, HRESULT& hr )
{
    Clear();

    // Validate that the parameter is not NULL.
    if ( pnSrc == 0 )
        hr = E_POINTER;

    // Set the variant.
    else
    {
        vt = VT_BYREF | VT_I4;
        plVal = pnSrc;
    }
}

//===========================================================================
// Currency
//===========================================================================

void OposVariant::ChangeCURRENCY( CY* pcySrc, HRESULT& hr )
{
    // Validate that the parameter is not NULL.
    if ( pcySrc == 0 )
        hr = E_POINTER;

    // If pointer OK, set it after trying to coerce variant.
    else
    {
        // Try to coerce variant to a new variant of type CURRENCY (CY).
        VARIANT var;
        var.vt = VT_EMPTY;
        hr = VariantChangeType(
            &var, static_cast<VARIANT*>(this), 0, VT_CY );
        // If coercion was successful, then update to the CURRENCY; else set to zero.
        if ( hr == S_OK )
            *pcySrc = var.cyVal;
        else
            pcySrc->int64 = 0;
    }
}

//-----------------------------------------------------------------------

void OposVariant::SetCURRENCY(CY cySrc)
{
    Clear();
    vt = VT_CY;
    cyVal = cySrc;
}

//-----------------------------------------------------------------------

void OposVariant::SetCURRENCY_Ptr( CY* pcySrc, HRESULT& hr )
{
    Clear();

    // Validate that the parameter is not NULL.
    if ( pcySrc == 0 )
        hr = E_POINTER;

    // Set the variant.
    else
    {
        vt = VT_BYREF | VT_CY;
        pcyVal = pcySrc;
    }
}

//===========================================================================
// BString
//===========================================================================

// Note: The caller must free the current string at pbstrSrc, if needed.
void OposVariant::ChangeBSTR( BSTR* pbstrSrc, HRESULT& hr )
{
    // Validate that the parameter is not NULL.
    if ( pbstrSrc == 0 )
        hr = E_POINTER;

    // If pointer OK, set it after trying to coerce variant.
    else
    {
        // Try to coerce variant to a new variant of type BSTR.
        VARIANT var;
        var.vt = VT_EMPTY;
        hr = VariantChangeType(
            &var, static_cast<VARIANT*>(this), 0, VT_BSTR );
        // If coercion was successful, then update to the BSTR; else set to NULL.
        *pbstrSrc = ( hr == S_OK ) ? var.bstrVal : 0;
    }
}

//-----------------------------------------------------------------------

void OposVariant::SetBSTR(BSTR bstrSrc, HRESULT& hr )
{
    // If non-NULL BSTR, then just pass BSTR in the variant.
    //   _bNeedClear flag remains off because we are not responsible
    //   for deleting the BSTR.
    if ( bstrSrc != 0 )
    {
        Clear();
        vt = VT_BSTR;
        bstrVal = bstrSrc;
    }

    // If NULL BSTR, call function so that zero-length BSTR is passed.
    //   This may prevent a lazy/bad service objects from causing GPF,
    //   in case they don't check each BSTR for NULL.
    else
        SetBSTR_Copy( 0, hr );
}

//-----------------------------------------------------------------------

void OposVariant::SetBSTR_Copy( BSTR bstrSrc, HRESULT& hr )
{
    Clear();

    // Allocate a BSTR and copy source BSTR into it.
    bstrVal = SysAllocStringLen(
           bstrSrc ? bstrSrc : L"",     // Source string, or empty string if NULL.
           SysStringLen(bstrSrc) );     // Length of string; will return zero if NULL.

    // Set HRESULT if failed.
    if ( NULL == bstrVal )
        hr = E_OUTOFMEMORY;
    // Otherwise set variant type, plus set flag so that the BSTR is deleted by destructor.
    else
    {
        vt = VT_BSTR;
        _bNeedClear = true;
    }
}

//-----------------------------------------------------------------------

bool OposVariant::SetBSTR_OutPtr( BSTR* pbstrSrc, HRESULT& hr )
{
    // Perform the in/out work first.
    bool bRC = SetBSTR_InOutPtr( pbstrSrc, hr );

    // If succeeded, then ensure that the BSTR* points to zero:
    //   This relieves subsequent code from needing to know out vs. in/out,
    //   so that they won't wrongly try to reallocate an out.
    if (bRC)
        *pbstrSrc = 0;

    return bRC;
}

bool OposVariant::SetBSTR_InOutPtr( BSTR* pbstrSrc, HRESULT& hr )
{
    Clear();

    // Validate that the parameter is not NULL.
    if ( pbstrSrc == 0 )
    {
        hr = E_POINTER;
        return false;
    }

    // Set the variant.
    vt = VT_BYREF | VT_BSTR;
    pbstrVal = pbstrSrc;
    return true;
}

//===========================================================================
// VARIANT
//===========================================================================

void OposVariant::SetVARIANT( VARIANT& var, VARTYPE Type, HRESULT& hr )
{
    Clear();

    // If type matches (ignoring the BYREF flag), then copy the variant.
    //   Strips the BYREF if present.
    if ( ( var.vt & ~VT_BYREF ) == Type )
    {
        HRESULT hrTmp = VariantCopyInd( this, &var );
        if ( FAILED(hrTmp) )
            hr = hrTmp;
        _bNeedClear = true;
    }
    // If type doesn't match, then return failure.
    else
        hr = E_INVALIDARG;
}

void OposVariant::SetVARIANT_Ptr( VARIANT*& pvar, VARTYPE Type, HRESULT& hr )
{
    Clear();

    // If type is EMPTY, then allow. Callee may set it.
    if ( pvar->vt == VT_EMPTY )
        ;

    // If type matches (ignoring the BYREF flag), then copy the variant.
    //   Strips the BYREF if present.
    else if ( ( pvar->vt & ~VT_BYREF ) == Type )
    {
        HRESULT hrTmp = VariantCopyInd( this, pvar );
        if ( FAILED(hrTmp) )
            hr = hrTmp;
        _bNeedClear = true;
    }

    // If type doesn't match, then return failure.
    else
        hr = E_INVALIDARG;
}

//===========================================================================
// Wide character string
//===========================================================================

void OposVariant::SetString( LPCOLESTR lpszSrc, HRESULT& hr )
{
    Clear();

    // Allocate a BSTR and copy source string into it.
    bstrVal = SysAllocString(
        lpszSrc ? lpszSrc : L"" );  // Source string, or empty string if NULL.

    // Set HRESULT if failed.
    if ( NULL == bstrVal )
        hr = E_OUTOFMEMORY;
    // Otherwise set variant type, plus set flag so that the BSTR is deleted by destructor.
    else
    {
        vt = VT_BSTR;
        _bNeedClear = true;
    }
}

//===========================================================================
// Dispatch pointer
//===========================================================================

void OposVariant::SetDispatch_Ptr( IDispatch* pSrc, HRESULT& hr )
{
    Clear();

    // Validate that the parameter is not NULL.
    if ( pSrc == 0 )
        hr = E_POINTER;

    // Set the variant, plus set flag so that the pointer is released by destructor.
    else
    {
        vt = VT_DISPATCH;
        pdispVal = pSrc;
        pSrc->AddRef();
        _bNeedClear = true;
    }
}


//****************************************************************************
//****************************************************************************


OposDispParms::OposDispParms( OposVariant* pVars, int nVars )
{
    // Initialize the DISPPARAMS to empty.
    rgvarg = 0;
    rgdispidNamedArgs = 0;
    cArgs = 0;
    cNamedArgs = 0;

    // If some variables and we successfully allocate memory...
    if ( nVars != 0 && ( rgvarg = new VARIANT[nVars] ) != 0 )
    {
        // Set variable count.
        cArgs = nVars;
        // Copy OposVariant array elements to the VARIANT array.
        //  - For [in] arguments, this will copy the type (VT_BOOL, VT_I4, VT_CY, VT_BSTR) and
        //      its corresponding data. Note that for VT_BSTR, the data is a system string pointer.
        //  - For [out] or [in,out] arguments, this will copy the type (VT_BYREF ORed with one
        //      of the above 4 types) and the corresponding pointer to data.
        //       * For VT_BYREF|VT_BOOL, VT_BYREF|VT_I4, and VT_BYREF|VT_CY, the pointer is to a primitive type.
        //       * For VT_BYREF|VT_BSTR, the pointer is to a system string pointer.
        //      If the function that is called (in a SO method or App event) changes the VARIANT,
        //      it does so by updating the data that is pointed to -- which is the pointer that
        //      was set by the OposVariant::Set...Ptr call.
        // Because of the above, we must not call VariantClear on destruction of our class instance,
        //   since that would delete the original OposVariant's data for VT_BSTR ([in]) and for
        //   the VT_BYREF types ([out] and [in,out]).
        while ( --nVars >= 0 )
            rgvarg[nVars] = pVars[nVars];
    }
}

OposDispParms::~OposDispParms()
{
    // If we allocated some variables, delete them.
    if (rgvarg)
        delete [] rgvarg;
}

// end OposVariant.cpp
