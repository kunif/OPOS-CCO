//*
//* assert.h - define the assert macro
//*

#ifndef __ASSERT_H__
#define __ASSERT_H__

#undef  assert

#ifndef _DEBUG

#define assert(exp)     ((void)0)

#else

#include <tchar.h>
void __cdecl _assert(LPCTSTR, LPCTSTR, unsigned);
#define assert(exp) (void)( (exp) || (_assert(_T(#exp), _T(__FILE__), __LINE__), 0) )

#endif

#endif
