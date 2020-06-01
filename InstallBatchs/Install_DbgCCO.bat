@ECHO OFF
REM ============================================================================
@ECHO Move to the drive / folder where the batch file exists
CHDIR /D %~dp0
IF "%ProgramW6432%" == "" GOTO ADMINCHECK
IF "%ProgramW6432%" == "%ProgramFiles%" GOTO ADMINCHECK
REM ============================================================================
@ECHO
@ECHO Installation is not supported in 32-bit mode on 64-bit OS.
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
@ECHO Installation on Windows 32-bit version
@ECHO Existence check and creation of target folder
IF NOT EXIST "%ProgramFiles%\OPOS" MKDIR "%ProgramFiles%\OPOS"
IF NOT EXIST "%ProgramFiles%\OPOS\CommonCODbg" MKDIR "%ProgramFiles%\OPOS\CommonCODbg"

@ECHO Copy of batch files
XCOPY Dbg??RegisterCommonCO.bat "%ProgramFiles%\OPOS" /S/V/H/R/Y

@ECHO Copy of CommonControlObjects files
CHDIR x86
XCOPY CommonCODbg "%ProgramFiles%\OPOS\CommonCODbg" /S/V/H/R/Y

@ECHO Registration CommonControlObjects files
CHDIR /D "%ProgramFiles%\OPOS\CommonCODbg"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /S %%F

GOTO EOF

REM ============================================================================
REM Windows 64bit version
:X64
@ECHO Installation on Windows 64-bit version
@ECHO Existence check and creation of target folder
IF NOT EXIST "%ProgramW6432%\OPOS" MKDIR "%ProgramW6432%\OPOS"
IF NOT EXIST "%ProgramW6432%\OPOS\CommonCODbg" MKDIR "%ProgramW6432%\OPOS\CommonCODbg"
IF NOT EXIST "%ProgramFiles(x86)%\OPOS" MKDIR "%ProgramFiles(x86)%\OPOS"
IF NOT EXIST "%ProgramFiles(x86)%\OPOS\CommonCODbg" MKDIR "%ProgramFiles(x86)%\OPOS\CommonCODbg"

@ECHO Copy of batch files
XCOPY Dbg??RegisterCCO.bat "%ProgramW6432%\OPOS" /S/V/H/R/Y
XCOPY Dbg??RegisterCCO.bat "%ProgramFiles(x86)%\OPOS" /S/V/H/R/Y

@ECHO Copy of 32-bit CommonControlObjects and other dll files
PUSHD x86
XCOPY CommonCODbg "%ProgramFiles(x86)%\OPOS\CommonCODbg" /S/V/H/R/Y

@ECHO Register 32-bit CommonControlObjects file
CHDIR /D "%ProgramFiles(x86)%\OPOS\CommonCODbg"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO "%SystemRoot%\SysWOW64\RegSvr32" /S %%F

POPD

REM ----------------------------------------------------------------------------
@ECHO Copy of 64-bit CommonControlObjects and other dll files
CHDIR x64
XCOPY CommonCODbg "%ProgramW6432%\OPOS\CommonCODbg" /S/V/H/R/Y

@ECHO Registration 64-bit CommonControlObjects files
CHDIR /D "%ProgramW6432%\OPOS\CommonCODbg"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /S %%F

:EOF
CHDIR /D %~dp0
