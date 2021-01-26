@ECHO OFF
SETLOCAL
REM ============================================================================
@ECHO Move to the drive / folder where the batch file exists
CHDIR /D %~dp0
IF "%ProgramW6432%" == "" GOTO ADMINCHECK
IF "%ProgramW6432%" == "%ProgramFiles%" GOTO ADMINCHECK
REM ============================================================================
@ECHO
@ECHO Reregistration is not supported in 32-bit mode on 64-bit OS.
@ECHO Please execute in 64-bit mode.
@ECHO
GOTO EOF

:ADMINCHECK
@ECHO Check if running with administrator privileges
openfiles > NUL 2>&1
IF NOT %ERRORLEVEL% EQU 0 (
    @ECHO Because there is no administrator privileges, grant privileges with start-process -verb runas
    REM powershell start-process Batch file to start -ArgumentList "argument1","argument2" -verb runas
    powershell start-process %0 -verb runas
    GOTO EOF
)

REM ============================================================================
REM **Important** Necessary preparation
REM 
REM All PIA from 1.15 version to the latest version must be installed in GAC.
REM 

REM ============================================================================
REM Set Location of the program to use
SET ALEXE="C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\bin\al.exe"

REM ============================================================================
REM 
IF "%ProgramW6432%" == "" GOTO X86
IF "%ProgramW6432%" == "%ProgramFiles%" GOTO X64
GOTO EOF

REM ============================================================================
REM Windows 32bit version
:X86
REM ----------------------------------------------------------------------------
@ECHO Create a Publisher Policy files and Copy .config to Win32\Release folder
FOR /D %%D IN (1.*) DO CD %%D && FOR %%F IN (policy.1.*.config) DO %ALEXE% /link:%%F /out:..\..\Win32\Release\%%~nF.dll /version:1.16.0.0 /productversion:1.16.0.0 /keyfile:..\..\keypare.snk /platform:anycpu && COPY %%F ..\..\Win32\Release

GOTO EOF

REM ============================================================================
REM Windows 64bit version
:X64
REM ----------------------------------------------------------------------------
@ECHO Create a Publisher Policy files and Copy .config to Win32\Release folder
FOR /D %%D IN (1.*) DO CD %%D && FOR %%F IN (policy.1.*.config) DO %ALEXE% /link:%%F /out:..\..\Win32\Release\%%~nF.dll /version:1.16.0.0 /productversion:1.16.0.0 /keyfile:..\..\keypare.snk /platform:anycpu && COPY %%F ..\..\Win32\Release

:EOF
ENDLOCAL
CHDIR /D %~dp0
