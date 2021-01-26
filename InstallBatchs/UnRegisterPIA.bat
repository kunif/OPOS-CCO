@ECHO OFF
REM ============================================================================
@ECHO Move to the drive / folder where the batch file exists
CHDIR /D %~dp0
IF "%ProgramW6432%" == "" GOTO ADMINCHECK
IF "%ProgramW6432%" == "%ProgramFiles%" GOTO ADMINCHECK
REM ============================================================================
@ECHO
@ECHO Unregistration is not supported in 32-bit mode on 64-bit OS.
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

@ECHO Unregistration of PIA files
CHDIR /D "%ProgramFiles%\OPOS\OpenPosFor.NET"
FOR %%F IN (OpenPOS*.dll) DO "%SystemRoot%\Microsoft.NET\Framework\v2.0.50727\RegAsm.exe" %%F /unregister /silent
FOR %%F IN (policy.*.dll) DO .\gacutil /u %%~nF /silent
FOR %%F IN (OpenPOS*.dll) DO .\gacutil /u %%~nF /silent

GOTO EOF

REM ============================================================================
REM Windows 64bit version
:X64

@ECHO Unregistration of PIA files
CHDIR /D "%ProgramFiles(x86)%\OPOS\OpenPosFor.NET"
FOR %%F IN (OpenPOS*.dll) DO "%SystemRoot%\Microsoft.NET\Framework64\v2.0.50727\RegAsm.exe" %%F /unregister /silent
FOR %%F IN (OpenPOS*.dll) DO "%SystemRoot%\Microsoft.NET\Framework\v2.0.50727\RegAsm.exe" %%F /unregister /silent
FOR %%F IN (policy.*.dll) DO .\gacutil /u %%~nF /silent
FOR %%F IN (OpenPOS*.dll) DO .\gacutil /u %%~nF /silent

:EOF
CHDIR /D %~dp0
