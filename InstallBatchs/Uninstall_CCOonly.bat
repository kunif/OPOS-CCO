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

:w32SOCommon
IF NOT EXIST "%ProgramFiles%\OPOS\SOCommon" GOTO w32CommonCO
@ECHO Unregistration of SOCommon files
CHDIR /D "%ProgramFiles%\OPOS\SOCommon"
FOR %%F IN (Opos_*.dll) DO RegSvr32 /U /S %%F

:w32CommonCO
IF NOT EXIST "%ProgramFiles%\OPOS\CommonCO" GOTO w32Rmdir
@ECHO Unregistration CommonControlObjects files
CHDIR /D "%ProgramFiles%\OPOS\CommonCO"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /U /S %%F

:w32Rmdir
@ECHO Remove CommonControlObjects and Related files
CHDIR /D %~dp0
IF NOT EXIST "%ProgramFiles%\OPOS" GOTO EOF
IF EXIST "%ProgramFiles%\OPOS\Include" ATTRIB -R "%ProgramFiles%\OPOS\Include" /S /D
IF EXIST "%ProgramFiles%\OPOS\Include" RMDIR /S /Q "%ProgramFiles%\OPOS\Include"
IF EXIST "%ProgramFiles%\OPOS\CommonCO" ATTRIB -R "%ProgramFiles%\OPOS\CommonCO" /S /D
IF EXIST "%ProgramFiles%\OPOS\CommonCO" RMDIR /S /Q "%ProgramFiles%\OPOS\CommonCO"
IF EXIST "%ProgramFiles%\OPOS\SOCommon" ATTRIB -R "%ProgramFiles%\OPOS\SOCommon" /S /D
IF EXIST "%ProgramFiles%\OPOS\SOCommon" RMDIR /S /Q "%ProgramFiles%\OPOS\SOCommon"
DEL /F /Q "%ProgramFiles%\OPOS\??RegisterCCO.bat"
RMDIR "%ProgramFiles%\OPOS" >nul 2>&1

GOTO EOF

REM ============================================================================
REM Windows 64bit version
:X64
@ECHO Uninstallation on Windows 64-bit version

:x86SOCommon
IF NOT EXIST "%ProgramFiles(x86)%\OPOS\SOCommon" GOTO x86CommonCO
@ECHO Unregistration of 32-bit SOCommon files
CHDIR /D "%ProgramFiles(x86)%\OPOS\SOCommon"
FOR %%F IN (Opos_*.dll) DO RegSvr32 /U /S %%F

:x86CommonCO
IF NOT EXIST "%ProgramFiles(x86)%\OPOS\CommonCO" GOTO x86Rmdir
@ECHO Unregistration of 32-bit CommonControlObjects files
CHDIR /D "%ProgramFiles(x86)%\OPOS\CommonCO"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /U /S %%F

:x86Rmdir
@ECHO Remove 32-bit CommonControlObjects and Related files
CHDIR /D %~dp0
IF NOT EXIST "%ProgramFiles(x86)%\OPOS" GOTO x64SOCommon
IF EXIST "%ProgramFiles(x86)%\OPOS\Include" ATTRIB -R "%ProgramFiles(x86)%\OPOS\Include" /S /D
IF EXIST "%ProgramFiles(x86)%\OPOS\Include" RMDIR /S /Q "%ProgramFiles(x86)%\OPOS\Include"
IF EXIST "%ProgramFiles(x86)%\OPOS\CommonCO" ATTRIB -R "%ProgramFiles(x86)%\OPOS\CommonCO" /S /D
IF EXIST "%ProgramFiles(x86)%\OPOS\CommonCO" RMDIR /S /Q "%ProgramFiles(x86)%\OPOS\CommonCO"
IF EXIST "%ProgramFiles(x86)%\OPOS\SOCommon" ATTRIB -R "%ProgramFiles(x86)%\OPOS\SOCommon" /S /D
IF EXIST "%ProgramFiles(x86)%\OPOS\SOCommon" RMDIR /S /Q "%ProgramFiles(x86)%\OPOS\SOCommon"
DEL /F /Q "%ProgramFiles(x86)%\OPOS\??RegisterCCO.bat"
RMDIR "%ProgramFiles(x86)%\OPOS" >nul 2>&1

REM ----------------------------------------------------------------------------
:x64SOCommon
IF NOT EXIST "%ProgramW6432%\OPOS\SOCommon" GOTO x64CommonCO
@ECHO Unregistration of 64-bit SOCommon files
CHDIR /D "%ProgramW6432%\OPOS\SOCommon"
FOR %%F IN (Opos_*.dll) DO RegSvr32 /U /S %%F

:x64CommonCO
IF NOT EXIST "%ProgramW6432%\OPOS\CommonCO" GOTO x64Rmdir
@ECHO Unregistration of 64-bit CommonControlObjects files
CHDIR /D "%ProgramW6432%\OPOS\CommonCO"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /U /S %%F

:x64Rmdir
@ECHO Remove 64-bit CommonControlObjects and Related files
CHDIR /D %~dp0
IF NOT EXIST "%ProgramW6432%\OPOS" GOTO EOF
IF EXIST "%ProgramW6432%\OPOS\Include" ATTRIB -R "%ProgramW6432%\OPOS\Include" /S /D
IF EXIST "%ProgramW6432%\OPOS\Include" RMDIR /S /Q "%ProgramW6432%\OPOS\Include"
IF EXIST "%ProgramW6432%\OPOS\CommonCO" ATTRIB -R "%ProgramW6432%\OPOS\CommonCO" /S /D
IF EXIST "%ProgramW6432%\OPOS\CommonCO" RMDIR /S /Q "%ProgramW6432%\OPOS\CommonCO"
IF EXIST "%ProgramW6432%\OPOS\SOCommon" ATTRIB -R "%ProgramW6432%\OPOS\SOCommon" /S /D
IF EXIST "%ProgramW6432%\OPOS\SOCommon" RMDIR /S /Q "%ProgramW6432%\OPOS\SOCommon"
DEL /F /Q "%ProgramW6432%\OPOS\??RegisterCCO.bat"
RMDIR "%ProgramW6432%\OPOS" >nul 2>&1

:EOF
CHDIR /D %~dp0
