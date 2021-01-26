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
IF NOT EXIST "%ProgramFiles%\OPOS\OpenPosFor.NET" MKDIR "%ProgramFiles%\OPOS\OpenPosFor.NET"

@ECHO Copy of include and batch files
XCOPY ??RegisterPIA.bat "%ProgramFiles%\OPOS" /S/V/H/R/Y

@ECHO Copy of CommonControlObjects and other dll files
CHDIR x86
XCOPY OpenPosFor.NET "%ProgramFiles%\OPOS\OpenPosFor.NET" /S/V/H/R/Y

@ECHO Registration of PIA files
CHDIR  /D "%ProgramFiles%\OPOS\OpenPosFor.NET"
FOR %%F IN (OpenPOS*.dll) DO .\gacutil /i %%F /f /silent
FOR %%F IN (policy.*.dll) DO .\gacutil /i %%F /f /silent
FOR %%F IN (OpenPOS*.dll) DO "%SystemRoot%\Microsoft.NET\Framework\v2.0.50727\RegAsm.exe" %%F /silent

GOTO EOF

REM ============================================================================
REM Windows 64bit version
:X64
@ECHO Installation on Windows 64-bit version
@ECHO Existence check and creation of target folder
IF NOT EXIST "%ProgramFiles(x86)%\OPOS" MKDIR "%ProgramFiles(x86)%\OPOS"
IF NOT EXIST "%ProgramFiles(x86)%\OPOS\OpenPosFor.NET" MKDIR "%ProgramFiles(x86)%\OPOS\OpenPosFor.NET"

@ECHO Copy of batch files
XCOPY ??RegisterPIA.bat "%ProgramFiles(x86)%\OPOS" /S/V/H/R/Y

@ECHO Copy of 32-bit CommonControlObjects and other dll files
CHDIR x86
XCOPY OpenPosFor.NET "%ProgramFiles(x86)%\OPOS\OpenPosFor.NET" /S/V/H/R/Y

@ECHO Registration of PIA files
CHDIR /D "%ProgramFiles(x86)%\OPOS\OpenPosFor.NET"
FOR %%F IN (OpenPOS*.dll) DO .\gacutil /i %%F /f /silent
FOR %%F IN (policy.*.dll) DO .\gacutil /i %%F /f /silent
FOR %%F IN (OpenPOS*.dll) DO "%SystemRoot%\Microsoft.NET\Framework\v2.0.50727\RegAsm.exe" %%F /silent
FOR %%F IN (OpenPOS*.dll) DO "%SystemRoot%\Microsoft.NET\Framework64\v2.0.50727\RegAsm.exe" %%F /silent

:EOF
CHDIR /D %~dp0
