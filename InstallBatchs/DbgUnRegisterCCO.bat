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
@ECHO Unregister CommonControlObjects file
CHDIR /D "%ProgramFiles%\OPOS\CommonCODbg"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /S /U %%F

GOTO EOF

REM ============================================================================
REM Windows 64bit version
:X64
@ECHO Unregister 32-bit CommonControlObjects file
CHDIR /D "%ProgramFiles(x86)%\OPOS\CommonCODbg"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO "%SystemRoot%\SysWOW64\RegSvr32" /S /U %%F

@ECHO Unregister 64-bit CommonControlObjects file
CHDIR /D "%ProgramW6432%\OPOS\CommonCODbg"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /S /U %%F

:EOF
CHDIR /D %~dp0
