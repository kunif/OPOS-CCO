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
IF NOT EXIST "%ProgramFiles%\OPOS\Include" MKDIR "%ProgramFiles%\OPOS\Include"
IF NOT EXIST "%ProgramFiles%\OPOS\CommonCO" MKDIR "%ProgramFiles%\OPOS\CommonCO"
IF NOT EXIST "%ProgramFiles%\OPOS\SOCommon" MKDIR "%ProgramFiles%\OPOS\SOCommon"
IF NOT EXIST "%ProgramFiles%\OPOS\OpenPosFor.NET" MKDIR "%ProgramFiles%\OPOS\OpenPosFor.NET"

@ECHO Copy of include and batch files
XCOPY Include "%ProgramFiles%\OPOS\Include" /S/V/H/R/Y
XCOPY ??Register???.bat "%ProgramFiles%\OPOS" /S/V/H/R/Y

@ECHO Copy of CommonControlObjects and other dll files
CHDIR x86
XCOPY CommonCO "%ProgramFiles%\OPOS\CommonCO" /S/V/H/R/Y
XCOPY SOCommon "%ProgramFiles%\OPOS\SOCommon" /S/V/H/R/Y
XCOPY OpenPosFor.NET "%ProgramFiles%\OPOS\OpenPosFor.NET" /S/V/H/R/Y

@ECHO Registration CommonControlObjects files
CHDIR /D "%ProgramFiles%\OPOS\CommonCO"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /S %%F

@ECHO Registration of SOCommon files
CHDIR ..\SOCommon
FOR %%F IN (Opos_*.dll) DO RegSvr32 /S %%F

REM ----------------------------------------------------------------------------
@ECHO Registration of PIA files
CHDIR ..\OpenPosFor.NET
FOR %%F IN (OpenPOS*.dll) DO .\gacutil /i %%F /f /silent
FOR %%F IN (OpenPOS*.dll) DO "%SystemRoot%\Microsoft.NET\Framework\v2.0.50727\RegAsm.exe" %%F /silent

GOTO EOF

REM ============================================================================
REM Windows 64bit version
:X64
@ECHO Installation on Windows 64-bit version
@ECHO Existence check and creation of target folder
IF NOT EXIST "%ProgramW6432%\OPOS" MKDIR "%ProgramW6432%\OPOS"
IF NOT EXIST "%ProgramW6432%\OPOS\Include" MKDIR "%ProgramW6432%\OPOS\Include"
IF NOT EXIST "%ProgramW6432%\OPOS\CommonCO" MKDIR "%ProgramW6432%\OPOS\CommonCO"
IF NOT EXIST "%ProgramW6432%\OPOS\SOCommon" MKDIR "%ProgramW6432%\OPOS\SOCommon"
IF NOT EXIST "%ProgramFiles(x86)%\OPOS" MKDIR "%ProgramFiles(x86)%\OPOS"
IF NOT EXIST "%ProgramFiles(x86)%\OPOS\Include" MKDIR "%ProgramFiles(x86)%\OPOS\Include"
IF NOT EXIST "%ProgramFiles(x86)%\OPOS\CommonCO" MKDIR "%ProgramFiles(x86)%\OPOS\CommonCO"
IF NOT EXIST "%ProgramFiles(x86)%\OPOS\SOCommon" MKDIR "%ProgramFiles(x86)%\OPOS\SOCommon"
IF NOT EXIST "%ProgramFiles(x86)%\OPOS\OpenPosFor.NET" MKDIR "%ProgramFiles(x86)%\OPOS\OpenPosFor.NET"

@ECHO Copy of include and batch files
XCOPY Include "%ProgramW6432%\OPOS\Include" /S/V/H/R/Y
XCOPY Include "%ProgramFiles(x86)%\OPOS\Include" /S/V/H/R/Y
XCOPY ??Register???.bat "%ProgramW6432%\OPOS" /S/V/H/R/Y
XCOPY ??Register???.bat "%ProgramFiles(x86)%\OPOS" /S/V/H/R/Y

@ECHO Copy of 32-bit CommonControlObjects and other dll files
PUSHD x86
XCOPY CommonCO "%ProgramFiles(x86)%\OPOS\CommonCO" /S/V/H/R/Y
XCOPY SOCommon "%ProgramFiles(x86)%\OPOS\SOCommon" /S/V/H/R/Y
XCOPY OpenPosFor.NET "%ProgramFiles(x86)%\OPOS\OpenPosFor.NET" /S/V/H/R/Y

@ECHO Registration of 32-bit CommonControlObjects files
CHDIR /D "%ProgramFiles(x86)%\OPOS\CommonCO"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO "%SystemRoot%\SysWOW64\RegSvr32" /S %%F

@ECHO Registration of 32-bit SOCommon files
CHDIR ..\SOCommon
FOR %%F IN (Opos_*.dll) DO "%SystemRoot%\SysWOW64\RegSvr32" /S %%F

POPD

REM ----------------------------------------------------------------------------
@ECHO Copy of 64-bit CommonControlObjects and other dll files
CHDIR x64
XCOPY CommonCO "%ProgramW6432%\OPOS\CommonCO" /S/V/H/R/Y
XCOPY SOCommon "%ProgramW6432%\OPOS\SOCommon" /S/V/H/R/Y

@ECHO Registration of 64-bit CommonControlObjects files
CHDIR /D "%ProgramW6432%\OPOS\CommonCO"
FOR %%F IN (Opos_*.dll,OPOS*.ocx) DO RegSvr32 /S %%F

@ECHO Registration of 64-bit SOCommon files
CHDIR ..\SOCommon
FOR %%F IN (Opos_*.dll) DO RegSvr32 /S %%F

REM ----------------------------------------------------------------------------
@ECHO Registration of PIA files
CHDIR /D "%ProgramFiles(x86)%\OPOS\OpenPosFor.NET"
FOR %%F IN (OpenPOS*.dll) DO .\gacutil /i %%F /f /silent
FOR %%F IN (OpenPOS*.dll) DO "%SystemRoot%\Microsoft.NET\Framework\v2.0.50727\RegAsm.exe" %%F /silent
FOR %%F IN (OpenPOS*.dll) DO "%SystemRoot%\Microsoft.NET\Framework64\v2.0.50727\RegAsm.exe" %%F /silent

:EOF
CHDIR /D %~dp0
