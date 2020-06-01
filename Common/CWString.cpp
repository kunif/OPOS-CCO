/****************************************************************************
**
** CWString.cpp
**
**  2020/06/01 Changed from RCSALIGNED to _M_IX86 / _M_X64.         K. Fukuchi
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

#if defined(_M_IX86)
#pragma message(">> Intel x86: Non-aligned data transfers are OK")
#elif defined(_M_X64)
#pragma message(">> Intel x64: Non-aligned data transfers are OK")
#else
#pragma message(">> Non-Intel x86, x64: Must not transfer non-aligned data")
#endif

#ifndef _CWString_cpp_
#define _CWString_cpp_

#define  WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <limits.h>

#include "CWString.h"


//////////////////////////////////////////////////////////////////////
// cw_memset :  Set character array.
//////////////////////////////////////////////////////////////////////

void cw_memset(char* pTarget, char cChar, int nCount)        // Set char array.
{
    // If Intel x86, resort to assembly...
#if defined(_M_IX86)
    _asm
    {
        mov ecx, nCount                 // Get count.
        jcxz L2                         //   If zero, then jump: Nothing to do.

        mov edi, pTarget                // Get pointer to destination.
        mov al, cChar                   // Get character to set.
        rep stosb                       // Set character for ECX times.

    L2:
    }

    // If not Intel, use tight loop.
#else
    if ( nCount > 0 )
    {
        int n = nCount;
        do {
            *pTarget++ = cChar;
        } while ( --n );
    }
#endif
}

void cw_memset(wchar_t* pTarget, wchar_t cChar, int nCount)  // Set wide char array.
{
    // If Intel x86, resort to assembly...
#if defined(_M_IX86)
    _asm
    {
        mov ecx, nCount                 // Get count.
        jcxz L2                         //   If zero, then jump: Nothing to do.

        mov edi, pTarget                // Get pointer to destination.
        mov ax, cChar                   // Get wide character to set.
        rep stosw                       // Set wide character for ECX times.

    L2:
    }

    // If not Intel or alignment required, then set low and high bytes separately.
#else
    if ( nCount > 0 )
    {
        int n = nCount;
        char* pCharTarget = (char*) pTarget;
        do {
            *pCharTarget++ = LOBYTE(cChar);
            *pCharTarget++ = HIBYTE(cChar);
        } while ( --n );
    }
#endif
}


//////////////////////////////////////////////////////////////////////
// cw_strlen :  Determine string length.
//////////////////////////////////////////////////////////////////////

int cw_strlen(const char* pChar)     // String length.
{
    int nCount = 0;
    if ( pChar && *pChar )
    {
        do nCount++;
        while (*++pChar);
    }
    return nCount;
}

int cw_strlen(const wchar_t* pChar)  // Wide string length.
{
#if defined(_M_IX86) || defined(_M_X64)
    int nCount = 0;
    if ( pChar && *pChar )
    {
        do nCount++;
        while (*++pChar);
    }
    return nCount;

#else
    int nCount = 0;
    const char* pNChar = (const char*) pChar;
    if ( pNChar && ( pNChar[0] | pNChar[1] ) != 0 )
    {
        do
        {
            nCount++;
            pNChar += 2;
        }
        while ( ( pNChar[0] | pNChar[1] ) != 0 );
    }
    return nCount;
#endif
}


//////////////////////////////////////////////////////////////////////
// cw_memcpy :  Copy character array.
//////////////////////////////////////////////////////////////////////

// Copy with convert from multibyte character string to wide character string.
int CM_API cw_memcpy(
    wchar_t*    pTarget,    // Target, or NULL to just get chars required.
    const char* pSrc,       // Source.
    int         nCount)     // Source char length, or -1 to copy thru NUL.
    // - Returns number of wide characters written.
{
    if ( nCount == 0 )
        return 0;
    if ( nCount < 0 )
        nCount = cw_strlen( pSrc ) + 1;

#if defined(_M_IX86) || defined(_M_X64)
    return MultiByteToWideChar(
        CP_ACP,         // code page
        0,              // character-type options
        pSrc,           // address of string to map
        nCount,         // number of characters in string
        pTarget,        // address of wide-character buffer
        nCount );       // size of buffer.
                        //   This is worst case (no multi-byte chars).
                        //   We assume that the caller passed a big enough buffer.

#else
    wchar_t* pWide = pTarget;
    if ( (DWORD) pWide & 1 )
        pWide = new wchar_t[nCount];
    nCount = MultiByteToWideChar(
        CP_ACP,         // code page
        0,              // character-type options
        pSrc,           // address of string to map
        nCount,         // number of characters in string
        pWide,          // address of wide-character buffer
        nCount );       // size of buffer.
                        //   This is worst case (no multi-byte chars).
                        //   We assume that the caller passed a big enough buffer.
    if ( pTarget != pWide )
    {
        cw_memcpy( (char*) pTarget, (const char*) pWide, nCount * sizeof(wchar_t) );
        delete [] pWide;
    }
    return nCount;
#endif
}

// Copy with convert from wide character string to multibyte character string.
int CM_API cw_memcpy(
    char*          pTarget, // Target, or NULL to just get chars required.
    const wchar_t* pSrc,    // Source.
    int            nCount)  // Source char length, or -1 to copy thru NUL.
    // - Returns number of characters written.
{
    if ( nCount == 0 )
        return 0;
    if ( nCount < 0 )
        nCount = cw_strlen( pSrc ) + 1;

#if defined(_M_IX86) || defined(_M_X64)
    return WideCharToMultiByte(
        CP_ACP,         // code page
        0,              // performance and mapping flags
        pSrc,           // address of wide character string
        nCount,         // number of characters in string
        pTarget,        // address of buffer for new string
        nCount*2,       // size of buffer
                        //   This is worst case (every wide -> multi-byte char).
                        //   We assume that the caller passed a big enough buffer.
        NULL,           // address of default for unmappable characters
        NULL );         // address of flag set when default char.

#else
    wchar_t* pWide = (wchar_t*) pSrc;
    if ( (DWORD) pWide & 1 )
    {
        pWide = new wchar_t[nCount];
        cw_memcpy( (char*) pWide, (const char*) pSrc, nCount * sizeof(wchar_t) );
    }
    nCount = WideCharToMultiByte(
        CP_ACP,         // code page
        0,              // performance and mapping flags
        pWide,          // address of wide character string
        nCount,         // number of characters in string
        pTarget,        // address of buffer for new string
        nCount*2,       // size of buffer
                        //   This is worst case (every wide -> multi-byte char).
                        //   We assume that the caller passed a big enough buffer.
        NULL,           // address of default for unmappable characters
        NULL );         // address of flag set when default char.
    if ( pSrc != pWide )
        delete [] pWide;
    return nCount;
#endif
}

// Copy from multibyte character string to multibyte character string.
int CM_API cw_memcpy(
    char*       pTarget,    // Char target (must be large enough);
                            //   or NULL to just get count of chars required.
    const char* pSrc,       // Char source.
    int         nCount)     // Source char length, or -1 to copy thru NUL.
    // - Returns number of characters written, or to write.
{
    if ( nCount < 0 )
        nCount = cw_strlen(pSrc) + 1;
    if ( pTarget && nCount )
    {
        // If Intel x86, resort to assembly...
#if defined(_M_IX86)
        _asm
        {
            mov ecx, nCount                 // Get count.
            jcxz L2                         //   If zero, then jump: Nothing to do.

            mov esi, pSrc                   // Get pointer to source.
            mov edi, pTarget                // Get pointer to destination.
            rep movsb                       // Move characters from ESI to EDI for ECX times.

        L2:
        }

        // If not Intel, use tight loop.
#else
        int n = nCount;
        do {
            *pTarget++ = *pSrc++;
        } while ( --n );
#endif
    }
    return nCount;
}

// Copy from wide character string to wide character string.
int CM_API cw_memcpy(
    wchar_t*       pTarget, // Wide target (must be large enough);
                            //   or NULL to just get count of chars required.
    const wchar_t* pSrc,    // Wide source.
    int            nCount)  // Source char length, or -1 to copy thru NUL.
    // - Returns number of characters written, or to write.
{
    if ( nCount < 0 )
        nCount = cw_strlen(pSrc) + 1;
    cw_memcpy( (char*) pTarget, (const char*) pSrc, nCount * sizeof(wchar_t) );
    return nCount;
}


//////////////////////////////////////////////////////////////////////
// cw_strcpy :  Copy string.
//////////////////////////////////////////////////////////////////////

int cw_strcpy(char* pszTarget, const wchar_t* pszSrc)       // Copy wide to char string.
{
    return cw_memcpy(pszTarget, pszSrc, -1) - 1;            //   Return chars copied (not including NUL).
}

int cw_strcpy(wchar_t* pszTarget, const char* pszSrc)       // Copy char to wide string.
{
    return cw_memcpy(pszTarget, pszSrc, -1) - 1;            //   Return chars copied (not including NUL).
}

int cw_strcpy(char* pszTarget, const char* pszSrc)          // Copy char to char string.
{
    return cw_memcpy(pszTarget, pszSrc, -1) - 1;            //   Return chars copied (not including NUL).
}

int cw_strcpy(wchar_t* pszTarget, const wchar_t* pszSrc)    // Copy wide to wide string.
{
    return cw_memcpy(pszTarget, pszSrc, -1) - 1;            //   Return chars copied (not including NUL).
}


//////////////////////////////////////////////////////////////////////
// cw_strcat :  Concatenatestring.
//////////////////////////////////////////////////////////////////////

int cw_strcat(char* pszTarget, const wchar_t* pszSrc)       // Concat wide to char string.
{
    return cw_memcpy(pszTarget + cw_strlen(pszTarget), pszSrc, -1) - 1;
}       //   Return chars copied (not including NUL).

int cw_strcat(wchar_t* pszTarget, const char* pszSrc)       // Concat char to wide string.
{
    return cw_memcpy(pszTarget + cw_strlen(pszTarget), pszSrc, -1) - 1;
}       //   Return chars copied (not including NUL).

int cw_strcat(char* pszTarget, const char* pszSrc)          // Concat char to char string.
{
    return cw_memcpy(pszTarget + cw_strlen(pszTarget), pszSrc, -1) - 1;
}       //   Return chars copied (not including NUL).

int cw_strcat(wchar_t* pszTarget, const wchar_t* pszSrc)    // Concat wide to wide string.
{
    return cw_memcpy(pszTarget + cw_strlen(pszTarget), pszSrc, -1) - 1;
}       //   Return chars copied (not including NUL).


//////////////////////////////////////////////////////////////////////
// cw_dup :  Duplicate and convert a character array.
//////////////////////////////////////////////////////////////////////

// Duplicate a multibyte character string to a wide character string.
void CM_API cw_dup( const char* pSrc, int& nSrcChars,
                    wchar_t*& pTarget, int& nTargetChars )
{
    if ( pSrc == 0 )
    {
        nSrcChars = nTargetChars = 0;
        pTarget = 0;
        return;
    }

    if ( nSrcChars < 0 )
        nSrcChars = cw_strlen( pSrc );
    pTarget = new wchar_t[nSrcChars+1];
        // We allow one wide char for each multibyte char;
        //   this may be too many for some countries, but no harm.
    if (pTarget)
    {
        nTargetChars = cw_memcpy( pTarget, pSrc, nSrcChars );
        pTarget[nTargetChars] = 0;
    }
}

// Duplicate a wide character string to a multibyte character string.
void CM_API cw_dup( const wchar_t* pSrc, int& nSrcChars,
                    char*& pTarget, int& nTargetChars )
{
    if ( pSrc == 0 )
    {
        nSrcChars = nTargetChars = 0;
        pTarget = 0;
        return;
    }

    if ( nSrcChars < 0 )
        nSrcChars = cw_strlen( pSrc );
    /* ==> Implementation one -- minimize memory.
    nTargetChars = cw_memcpy( (char*) NULL, pSrc, nSrcChars );
        // Determine how many characters are needed.
        //   Can't assume one-to-one (some wide chars may need 2 multibyte chars),
        //   but don't want to waste a bunch of bytes either.
    pTarget = new char[nTargetChars+1];
    */
    /* ==> Implementation two -- maximize speed, with side effect of allocating up
    **      to twice the memory needed (worst case when no multibyte chars needed).
    **     Chose this because most converted strings will be short-lived.
    */
    pTarget = new char[(nSrcChars+1)*2];
    if (pTarget)
    {
        nTargetChars = cw_memcpy( pTarget, pSrc, nSrcChars );
        pTarget[nTargetChars] = 0;
    }
}


//////////////////////////////////////////////////////////////////////
// Helper functions for _CW class.
//////////////////////////////////////////////////////////////////////

void _CW::DupChar()
{
    cw_dup(m_pWide, m_nCharsWide, m_pChar, m_nChars);
    m_nDupFlag = 'c';
}

void _CW::DupWide()
{
    cw_dup(m_pChar, m_nChars, m_pWide, m_nCharsWide);
    m_nDupFlag = 'w';
}

int _CW::GetCharsMbcs()
{
    if (m_pChar == (char*)-1)
        DupChar();
    else if ( m_nChars < 0 )
        m_nChars = cw_strlen( m_pChar );
    return m_nChars;
}

int _CW::GetCharsWide()
{
    if (m_pWide == (wchar_t*)-1)
        DupWide();
    else if ( m_nCharsWide < 0 )
        m_nCharsWide = cw_strlen( m_pWide );
    return m_nCharsWide;
}

#endif
