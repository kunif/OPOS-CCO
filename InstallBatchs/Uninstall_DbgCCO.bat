@ECHO OFF
REM ============================================================================
@ECHO Move to the drive / folder where the batch file exists
CHDIR /D %~dp0
IF "%ProgramW6432%" == "" GOTO ADMINCHECK
IF "%ProgramW6432%" == "%ProgramFiles%" GOTO ADMINCHECK
REM ============================================================================
@ECHO
@ECHO Uninstallation is not supported in 32-bit mode on 64-bit OS.
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
REM 
IF "%ProgramW6432%" == "" GOTO X86
IF "%ProgramW6432%" == "%ProgramFiles%" GOTO X64
GOTO EOF

REM ============================================================================
REM Windows 32bit version
:X86
@ECHO Uninstallation on Windows 32-bit version

:w32CommonCO
IF NOT EXIST "%ProgramFiles%\OPOS\CommonCODbg" GOTO w32Rmdir
@ECHO Unregistration CommonControlObjects files
CHDIR /D "%ProgramFiles%\OPOS\CommonCODbg"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /U /S %%F

:w32Rmdir
@ECHO Remove CommonControlObjects and Related files
CHDIR /D %~dp0
IF NOT EXIST "%ProgramFiles%\OPOS" GOTO EOF
IF EXIST "%ProgramFiles%\OPOS\CommonCODbg" ATTRIB -R "%ProgramFiles%\OPOS\CommonCODbg" /S /D
IF EXIST "%ProgramFiles%\OPOS\CommonCODbg" RMDIR /S /Q "%ProgramFiles%\OPOS\CommonCODbg"
DEL /F /Q "%ProgramFiles%\OPOS\??RegisterCCO.bat"

GOTO EOF

REM ============================================================================
REM Windows 64bit version
:X64
@ECHO Uninstallation on Windows 64-bit version

:x86CommonCO
IF NOT EXIST "%ProgramFiles(x86)%\OPOS\CommonCODbg" GOTO x86Rmdir
@ECHO Unregistration of 32-bit CommonControlObjects files
CHDIR /D "%ProgramFiles(x86)%\OPOS\CommonCODbg"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO "%SystemRoot%\SysWOW64\RegSvr32" /U /S %%F

:x86Rmdir
@ECHO Remove 32-bit CommonControlObjects and Related files
CHDIR /D %~dp0
IF NOT EXIST "%ProgramFiles(x86)%\OPOS" GOTO x64CommonCO
IF EXIST "%ProgramFiles(x86)%\OPOS\CommonCODbg" ATTRIB -R "%ProgramFiles(x86)%\OPOS\CommonCODbg" /S /D
IF EXIST "%ProgramFiles(x86)%\OPOS\CommonCODbg" RMDIR /S /Q "%ProgramFiles(x86)%\OPOS\CommonCODbg"
DEL /F /Q "%ProgramFiles(x86)%\OPOS\??RegisterCCO.bat"

REM ----------------------------------------------------------------------------
:x64CommonCO
IF NOT EXIST "%ProgramW6432%\OPOS\CommonCODbg" GOTO x64Rmdir
@ECHO Unregistration of 64-bit CommonControlObjects files
CHDIR /D "%ProgramW6432%\OPOS\CommonCODbg"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /U /S %%F

:x64Rmdir
@ECHO Remove 64-bit CommonControlObjects and Related files
CHDIR /D %~dp0
IF NOT EXIST "%ProgramW6432%\OPOS" GOTO EOF
IF EXIST "%ProgramW6432%\OPOS\CommonCODbg" ATTRIB -R "%ProgramW6432%\OPOS\CommonCODbg" /S /D
IF EXIST "%ProgramW6432%\OPOS\CommonCODbg" RMDIR /S /Q "%ProgramW6432%\OPOS\CommonCODbg"
DEL /F /Q "%ProgramW6432%\OPOS\??RegisterCCO.bat"

:EOF
CHDIR /D %~dp0
