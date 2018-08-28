//*
//* assert.c - Display a message and continue
//*   Based loosely on MS CRT module.
//*

#ifdef _DEBUG

#pragma warning(disable: 4514)  // unreferenced inline function has been removed
#pragma warning(disable: 4201)  // nonstandard extension used : nameless struct/union

#define NO_STRICT

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* Format of MessageBox for assertions:
*
*       Assertion Failed!
*       File: c:\test\mytest\bar.c
*       Line: 69
*       Expression: <expression>
*/

/***
*_assert() - Display a message and abort
*
*Purpose:
*       The assert macro calls this routine if the assert expression is
*       true.  By placing the assert code in a subroutine instead of within
*       the body of the macro, programs that call assert multiple times will
*       save space.
*
*Entry:
*
*Exit:
*
*Exceptions:
*
*******************************************************************************/

void __cdecl _assert(
    LPCTSTR expr,
    LPCTSTR filename,
    unsigned lineno )
{
    TCHAR buffer[1000]; // Hope this doesn't overflow...
    _stprintf( buffer,
        _T("Assertion Failed!\n")
        _T("File: %s\n")
        _T("Line: %u\n")
        _T("Expression: <%s>\n\n")
        _T("Press Abort to end program, Retry to debug, Ignore to continue"),
        filename, lineno, expr );

    int nCode = MessageBox( GetActiveWindow(), buffer,
        _T("Assertion within OPOS CCO"),
        MB_ABORTRETRYIGNORE | MB_ICONHAND | MB_SETFOREGROUND );

    /* Retry: call the debugger */
    if ( nCode == IDRETRY )
    {
        DebugBreak();
        return;
    }

    /* Ignore: continue execution */
    if ( nCode == IDIGNORE )
        return;

    /* Abort: abort the program */
    TerminateProcess( GetCurrentProcess(), 1 );

#pragma warning(disable: 4702)              // unreachable code

    for (;; )                               // Just in case...
        Sleep(100000);
}

#endif
