/****************************************************************************
**
** StdAfx.h -- Include file used for generating precompiled header.
**
*****************************************************************************
*/

#ifndef __STDAFX_H__
#define __STDAFX_H__

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500 // Windows 2000 or later
#endif

#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>

#endif //__STDAFX_H__
