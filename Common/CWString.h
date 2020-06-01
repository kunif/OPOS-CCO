/****************************************************************************
**
** CWString.h -- Char/Widechar helper class and functions.
**
**    (Based loosely on ustring.h - Copyright 1997, Don Box)
**    (Signficant changes - 1998-2004, Curtiss Monroe)
**
**   In the following, "cw_char" may be replaced by either "char" or "wchar_t".
**
** Contains:
**
**  (1) Overloaded cw_memcpy and cw_memset that take either wchar_t or char
**      buffers.
**          int  cw_memcpy(cw_char* pTarget, const cw_char* pSrc, int nCount);
**            -> Returns the character count copied to pTarget.
**          void cw_memset(cw_char* p, cw_char cChar, int nCount);
**
**  (2) Overloaded cw_strlen, cw_strcpy, and cw_strcat that take either wchar_t
**      or char strings for any argument. These re
**          int cw_strlen(const cw_char* p);
**            -> Returns the string length (not including terminating NUL).
**          int cw_strcpy(cwchar* pTarget, const cw_char* pSrc);
**            -> Returns the character count copied to pTarget (not including terminating NUL).
**          int cw_strcat(cwchar* pTarget, const cw_char* pSrc);
**            -> Returns the character count appended to pTarget (not including terminating NUL).
**
**  (3) Prototypes for conversion routines that are used by the _CW class for
**      duplicating/converting strings on the fly.
**          void cw_dup( const char* pSrc, int& nSrcChars,
**                       wchar_t*& pTarget, int& nTargetChars );
**          void cw_dup( const wchar_t* pSrc, int& nSrcChars,
**                       char*& pTarget, int& nTargetChars );
**      On entry, if nChars = -1, then convert string through NUL and set nChars.
**      Else convert the specified length and append NUL.
**
**  (4) Class definitions for auto-conversion between "char*" / "unsigned char*"
**      and "wchar_t*" as needed:
**          _CW    - converts const cw_char* to const cw_char*
**          _CWNCC - converts const cw_char* to cw_char*
**              (needed for "non-const correct" code, that incorrectly omit
**               const on their cw_char*)
**
**  2020/06/01 Changed from RCSALIGNED to _M_IX86 / _M_X64.         K. Fukuchi
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

// Usage:
/*

void f(const OLECHAR* pWide, HWND hwnd)
{
    TCHAR sz[MAX_PATH];
    GUID guid;
    cw_strcpy(sz, pWide);               // overloads to correct copy/conversion routine
    SetWindowText(hwnd, _CW(pWide));    // _CW temporarily dups buffer if needed
    GetWindowText(hwnd, sz, MAX_PATH);
    CLSIDFromString(_CWNCC(sz), &guid); // _CWNCC needed because api non-const-correct
}

*/

#pragma once

#include <stdlib.h>
#include <string.h>

#if defined(_M_X64)
#pragma pack( push ) // Pack on default size.
#else
#pragma pack( push, 4 ) // Pack on double-word.
#endif

#if !defined( CM_API )
    #define CM_API __stdcall
#endif

//=============================================================================
//  (1) Overloaded cw_memcpy and cw_memset.

//    --- cw_memcpy ---

int CM_API cw_memcpy(           // Copy wide char array to char array.
    char* pTarget,                  // Char target (must be large enough);
                                    //   or NULL to just get count of chars required.
    const wchar_t* pSrc,            // Wide source.
    int nCount);                    // Source char length, or -1 to copy thru NUL.
    // - Returns number of narrow characters written, or to write.
int CM_API cw_memcpy(           // Copy char array to wide char array.
    wchar_t* pTarget,               // Wide target (must be large enough);
                                    //   or NULL to just get count of chars required.
    const char* pSrc,               // Char source.
    int nCount);                    // Source char length, or -1 to copy thru NUL.
    // - Returns number of wide characters written, or to write.

int CM_API cw_memcpy(                  // Copy char array to char array.
    char* pTarget,                  // Char target (must be large enough);
                                    //   or NULL to just get count of chars required.
    const char* pSrc,               // Char source.
    int nCount);                    // Source char length, or -1 to copy thru NUL.
    // - Returns number of narrow characters written, or to write.
int CM_API cw_memcpy(           // Copy wide array to wide array.
    wchar_t* pTarget,               // Wide target (must be large enough);
                                    //   or NULL to just get count of chars required.
    const wchar_t* pSrc,            // Wide source.
    int nCount);                    // Source char length, or -1 to copy thru NUL.
    // - Returns number of wide characters written, or to write.

//    --- cw_memset ---

void cw_memset(char* pTarget, char cChar, int nCount);        // Set char array.
void cw_memset(wchar_t* pTarget, wchar_t cChar, int nCount);  // Set wide char array.

//=============================================================================
//  (2) Overloaded cw_strlen, cw_strcpy, and cw_strcat.

//    --- cw_strlen ---

int cw_strlen(const char* pChar);     // String length.
int cw_strlen(const wchar_t* pChar);  // Wide string length.

//    --- cw_strcpy ---
//          Returns chars copied (not including NUL).

int cw_strcpy(char* pszTarget, const wchar_t* pszSrc);    // Copy wide to char string.
int cw_strcpy(wchar_t* pszTarget, const char* pszSrc);    // Copy char to wide string.
int cw_strcpy(char* pszTarget, const char* pszSrc);       // Copy char to char string.
int cw_strcpy(wchar_t* pszTarget, const wchar_t* pszSrc); // Copy wide to wide string.

//    --- cw_strcat ---
//          Returns chars copied (not including NUL).

int cw_strcat(char* pszTarget, const wchar_t* pszSrc);    // Concat wide to char string.
int cw_strcat(wchar_t* pszTarget, const char* pszSrc);    // Concat char to wide string.
int cw_strcat(char* pszTarget, const char* pszSrc);       // Concat char to char string.
int cw_strcat(wchar_t* pszTarget, const wchar_t* pszSrc); // Concat wide to wide string.

//=============================================================================
//  (3) Prototypes for conversion routines that are used by the _CW class for
//      duplicating/converting strings on the fly.
//      If nSrcChars = -1, then convert string through NUL.
//      Else convert the specified length and append NUL.

void CM_API cw_dup( const char* pSrc, int& nSrcChars,
                    wchar_t*& pTarget, int& nTargetChars );
void CM_API cw_dup( const wchar_t* pSrc, int& nSrcChars,
                    char*& pTarget, int& nTargetChars );

//=============================================================================
//  (4) Class definitions:
//      Map const wchar_t* and const char* to either const wchar_t* or
//      const char* depending on context.

class _CW
{
    char* m_pChar;      wchar_t* m_pWide;
    int   m_nChars;     int      m_nCharsWide;
    void  DupChar();    void     DupWide();
    char  m_nDupFlag;

public:
    _CW(const char* pChar)              // Construct from char string.
        : m_pChar((char*)pChar), m_nChars(-1),
          m_pWide((wchar_t*)-1), m_nDupFlag(0)          {}
    _CW(const char* pChar, int nChars)  // Construct from char array with length.
        : m_pChar((char*)pChar), m_nChars(nChars),
          m_pWide((wchar_t*)-1), m_nDupFlag(0)          {}

    _CW(const unsigned char* pChar)              // Construct from unsigned char string.
        : m_pChar((char*)pChar), m_nChars(-1),
          m_pWide((wchar_t*)-1), m_nDupFlag(0)          {}
    _CW(const unsigned char* pChar, int nChars)  // Construct from unsigned char array with length.
        : m_pChar((char*)pChar), m_nChars(nChars),
          m_pWide((wchar_t*)-1), m_nDupFlag(0)          {}

    _CW(const wchar_t* pWide)           // Construct from wide string.
      : m_pChar((char*)-1),       m_nDupFlag(0),
        m_pWide((wchar_t*)pWide), m_nCharsWide(-1)      {}
    _CW(const wchar_t* pWide, int nChars)// Construct from wide array with length.
      : m_pChar((char*)-1),       m_nDupFlag(0),
        m_pWide((wchar_t*)pWide), m_nCharsWide(nChars)  {}

    operator const char*()              // Cast to char*.
        {   // If pointer not init, then duplicate.
            if (m_pChar == (char*)-1) DupChar();
            return m_pChar;
        }
    operator const unsigned char*()     // Cast to unsigned char*.
        {   // If pointer not init, then duplicate.
            if (m_pChar == (char*)-1) DupChar();
            return (unsigned char*) m_pChar;
        }
    operator const wchar_t*()           // Cast to wide*.
        {   // If pointer not init, then duplicate.
            if (m_pWide == (wchar_t*)-1) DupWide();
            return m_pWide;
        }

    int GetCharsMbcs();                 // Get multibyte char count.
    int GetCharsWide();                 // Get wide char count.
    #if defined(UNICODE) || defined(_UNICODE)
        int GetCharsText() { return GetCharsWide(); }
    #else
        int GetCharsText() { return GetCharsMbcs(); }
    #endif

    ~_CW()                              // Destructor.
        {   if (m_nDupFlag == 'c')      delete [] m_pChar;
            else if (m_nDupFlag == 'w') delete [] m_pWide;
        }
};

//.............................................................................
//      class _CWNCC adds non-const conversion operators to _CW
//        Use when a function "forgets" to put "const" on an operand.
//        It still better not change the string.

class _CWNCC : public _CW
{
public:
    _CWNCC(const char* pChar)               // Construct from char string.
      : _CW(pChar)          {}
    _CWNCC(const char* pChar, int nChars)   // Construct from char array with length.
      : _CW(pChar, nChars)  {}

    _CWNCC(const unsigned char* pChar)               // Construct from char string.
      : _CW((const char*) pChar)          {}
    _CWNCC(const unsigned char* pChar, int nChars)   // Construct from char array with length.
      : _CW((const char*) pChar, nChars)  {}

    _CWNCC(const wchar_t* pWide)            // Construct from wide string.
      : _CW(pWide)          {}
    _CWNCC(const wchar_t* pWide, int nChars)// Construct from wide array with length.
      : _CW(pWide, nChars)  {}

    operator char*()                        // Cast to char*, without the const.
        { return (char*) operator const char*(); }
    operator unsigned char*()               // Cast to unsigned char*, without the const.
        { return (unsigned char*) operator const char*(); }
    operator wchar_t*()                     // Cast to wide*, without the const.
        { return (wchar_t*) operator const wchar_t*(); }
};

#pragma pack( pop ) // Restore caller's packing.
