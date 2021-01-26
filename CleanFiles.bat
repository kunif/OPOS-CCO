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
call CleanFiles2.bat DeviceMonitor
call CleanFiles2.bat ElectronicJournal
call CleanFiles2.bat ElectronicValueRW
call CleanFiles2.bat FiscalPrinter
call CleanFiles2.bat Gate
call CleanFiles2.bat GestureControl
call CleanFiles2.bat GraphicDisplay
call CleanFiles2.bat ImageScanner
call CleanFiles2.bat IndividualRecognition
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
call CleanFiles2.bat SoundPlayer
call CleanFiles2.bat SoundRecorder
call CleanFiles2.bat SpeechSynthesis
call CleanFiles2.bat ToneIndicator
call CleanFiles2.bat Totals
call CleanFiles2.bat VideoCapture
call CleanFiles2.bat VoiceRecognition

if not exist OCX\* goto :NoOCX
cd ocx
del /q /s *.exp
del /q /s *.lib
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
rd /s /q Win32
rd /s /q x64
cd ..
:NoConstants

if not exist OposInternals\* goto :NoInternals
cd OposInternals
del OposInternals.aps
del OposInternals.h
del OposInternals_i.c
del OposInternals.plg
del OposInternals.tlb
del OposInternals.*.user
del OposInternals.*.vspscc
rd /s /q Win32
rd /s /q x64
cd ..
:NoInternals

if not exist OposInterfaces\* goto :NoInterfaces
cd OposInterfaces
del OposInterfaces.aps
del OposInterfaces.h
del OposInterfaces_i.c
del OposInterfaces.plg
del OposInterfaces.tlb
del OposInterfaces.*.user
del OposInterfaces.*.vspscc
rd /s /q Win32
rd /s /q x64
cd ..
:NoInterfaces

del /q Opos.Net\GAC.txt

del /q OposControls.ncb
attrib -h OposControls.suo 1>nul 2>nul
del /q OposControls.suo
