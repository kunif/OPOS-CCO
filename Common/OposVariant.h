/****************************************************************************
**
** OposVariant.h -- Helper class for preparing and sending OPOS parameters
**                  as VARIANTS.
**
**      Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  1999/02/06 Initial version.                                     C. Monroe
**  1999/03/03 Revamp. No longer rely on CComVariant.
**  1999/03/22 Remove GetBstrLen.
**  2006/08/16 Add VARIANT support.
**  2008/01/15 Clarify usage. Set "hr" on Set or Change failure.
**               Make destructor "Clear" based on previous actions.
**  2015/02/07 Add OposVariantResult class, whose destructor
**               always calls "Clear".
**  2020/06/01                                                      K. Fukuchi
**             Changed include guard from #ifndef __XXXX_H__ to #pragma once.
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

    Usage:
     * Constructor: Initializes the structure to "empty".
     * Destructor: Clears data only if "_bNeedClear" is true.
     * Clear: Clears the data.
     * SetXxx: Call to set the variant's data.
     * ChangeXxx: Try to convert the variant (via VariantChangeType).
        Returns status; if successful, also returns value.
     * GetXxx: Try to convert the variant (via VariantChangeType).
        If successful, returns the value; else returns a default value.

    OposVariantResult is the same as OposVariant with one distinction:
    If its VARIANT is set, the destructor will always Clear it.
    It is intended for use when the value is returned from the SO, and
      will be converted if it needs to be returned to the app.

    OposDispParms is a wrapper class for the DISPPARMS structure.
    It is used to prepare for calling Invoke, given an array of OposVariants.
    (This is requires because OposVariant is bigger than VARIANT.)
*/

#pragma once

//****************************************************************************
//****************************************************************************


class OposVariant : public VARIANT
{
public :
    //===========================================================================
    // Constructor / Destructor and Clear.
    //===========================================================================

    OposVariant() { vt = VT_EMPTY; _bNeedClear = false; }
    ~OposVariant() { if (_bNeedClear) Clear(); }
    HRESULT Clear() { _bNeedClear = false; return VariantClear(this); }

    //===========================================================================
    // Boolean
    //===========================================================================

    void SetVARIANT_BOOL(VARIANT_BOOL bSrc);
    void SetVARIANT_BOOL_Ptr( VARIANT_BOOL* pbSrc, HRESULT& hr );

    //===========================================================================
    // Long
    //===========================================================================

    LONG GetLONG();
    void ChangeLONG( LONG* pLong, HRESULT& hr );
    void SetLONG(LONG nSrc);
    void SetLONG_Ptr( LONG* pnSrc, HRESULT& hr );

    //===========================================================================
    // Currency
    //===========================================================================

    void ChangeCURRENCY( CY* pcySrc, HRESULT& hr );
    void SetCURRENCY(CY cySrc);
    void SetCURRENCY_Ptr( CY* pcySrc, HRESULT& hr );

    //===========================================================================
    // BString
    //===========================================================================

    void ChangeBSTR( BSTR* pbstrSrc, HRESULT& hr );
    void SetBSTR( BSTR bstrSrc, HRESULT& hr );
    void SetBSTR_Copy( BSTR bstrSrc, HRESULT& hr );
    bool SetBSTR_OutPtr( BSTR* pbstrSrc, HRESULT& hr );
    bool SetBSTR_InOutPtr( BSTR* pbstrSrc, HRESULT& hr );

    //===========================================================================
    // VARIANT
    //===========================================================================

    void SetVARIANT( VARIANT& var, VARTYPE Type, HRESULT& hr );
    void SetVARIANT_Ptr( VARIANT*& pvar, VARTYPE Type, HRESULT& hr );

    //===========================================================================
    // Wide character string
    //===========================================================================

    void SetString( LPCOLESTR lpszSrc, HRESULT& hr );

    //===========================================================================
    // Dispatch pointer
    //===========================================================================

    void SetDispatch_Ptr( IDispatch* pSrc, HRESULT& hr );

public:
    bool _bNeedClear; // true if contains data that must be "Clear"ed; else false.
};


//****************************************************************************
//****************************************************************************


class OposVariantResult : public OposVariant
{
public :
    //===========================================================================
    // Destructor.
    //===========================================================================

    ~OposVariantResult() { Clear(); }
};


//****************************************************************************
//****************************************************************************


class OposDispParms : public DISPPARAMS
{
public :
    //===========================================================================
    // Constructor / Destructor.
    //===========================================================================

    OposDispParms( OposVariant* pVars, int nVars );
    ~OposDispParms();
};
