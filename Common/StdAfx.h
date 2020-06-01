/****************************************************************************
**
** StdAfx.h -- Include file used for generating precompiled header.
**
**     Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  1999/02/06 Initial version.                                     C. Monroe
**  2001/05/18 Updated to support Windows CE.                       C. Monroe
**  2008/01/15 Updated for building with VS2005.                    C. Monroe
**  2020/06/01 Updated for building with VSC2019.                   K. Fukuchi
**
*****************************************************************************
*/

#pragma once

#ifndef STRICT
#define STRICT
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601 // Windows 7 or later
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED

// Since the Totals method "Create" conflicts with a base class in ATL,
//   use preprocessor magic to rename all "Create" within ATL to "atlCreate"
#define Create atlCreate

#include <atlbase.h>
extern CComModule _Module;
#include "atlcom.h"
#include <atlctl.h>

// Revert to standard "Create".
#undef Create

// Disable warnings issued on CMVERIFY macros: "operator has no effect..."
#pragma warning( disable : 4552 4553 )

// Disable warnings "unreferenced formal parameter"
#pragma warning( disable : 4100 )

// Include Windows header file.
#include <windows.h>

// Since the CreateWindow preprocessor macro conflicts with the LineDisplay,
//   undefine it.
#undef CreateWindow
