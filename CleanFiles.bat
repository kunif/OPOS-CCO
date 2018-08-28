call CleanFiles2.bat Belt
call CleanFiles2.bat BillAcceptor
call CleanFiles2.bat BillDispenser
call CleanFiles2.bat Biometrics
call CleanFiles2.bat BumpBar
call CleanFiles2.bat CashChanger
call CleanFiles2.bat CashDrawer
call CleanFiles2.bat CAT
call CleanFiles2.bat CheckScanner
call CleanFiles2.bat CoinAcceptor
call CleanFiles2.bat CoinDispenser
call CleanFiles2.bat ElectronicJournal
call CleanFiles2.bat ElectronicValueRW
call CleanFiles2.bat FiscalPrinter
call CleanFiles2.bat Gate
call CleanFiles2.bat ImageScanner
call CleanFiles2.bat ItemDispenser
call CleanFiles2.bat Keylock
call CleanFiles2.bat Lights
call CleanFiles2.bat LineDisplay
call CleanFiles2.bat MICR
call CleanFiles2.bat MotionSensor
call CleanFiles2.bat MSR
call CleanFiles2.bat PINPad
call CleanFiles2.bat PointCardRW
call CleanFiles2.bat POSKeyboard
call CleanFiles2.bat POSPower
call CleanFiles2.bat POSPrinter
call CleanFiles2.bat RemoteOrderDisplay
call CleanFiles2.bat RFIDScanner
call CleanFiles2.bat Scale
call CleanFiles2.bat Scanner
call CleanFiles2.bat SigCap
call CleanFiles2.bat SmartCardRW
call CleanFiles2.bat ToneIndicator
call CleanFiles2.bat Totals

if not exist OCX\* goto :NoOCX
cd ocx
del /q /s *.exp
del /q /s *.lib
del /q /s *.map
cd ..
:NoOCX

if not exist OposConstants\* goto :NoConstants
cd OposConstants
del OposConstants.aps
del OposConstants.h
del OposConstants_i.c
del OposConstants.plg
del OposConstants.tlb
del OposConstants.*.user
del OposConstants.*.vspscc
rd /s /q Release
rd /s /q Debug
cd ..
:NoConstants

del /q Opos.Net\GAC.txt

del /q OposControls.ncb
attrib -h OposControls.suo 1>nul 2>nul
del /q OposControls.suo
