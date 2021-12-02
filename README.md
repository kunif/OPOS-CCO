# OpenPOS for OLE Common Control Objects Version 1.16  
This is OpenPOS for OLE(formerly OLE for Retail POS: abbreviated OPOS) Common Control Objects(Common CO) based on [UnifiedPOS Version 1.16][upos116] "Unified POS Retail Peripheral Architecture Version 1.16".  

## Changes  
The following correspondence is made to the 1.15.000 version.  

- Added functions for Retail Communication Service Device to Lights device and POSPower device.  
- Added 9 new device categories for Retail Communication Service Device.  
  - DeviceMonitor  
  - GestureControl  
  - GraphicDisplay  
  - IndividualRecognition  
  - SoundPlayer  
  - SoundRecorder  
  - SpeechSynthesis  
  - VideoCapture  
  - VoiceRecognition  
- Added Publisher Policy file for .NET applications created for Common CO 1.15.000.  
- Changed development environment from Visual Studio Community 2019 to Visual Studio Community 2022.  
  - Platform toolset is Visual Studio 2022 (v143).  
  - Windows SDK version 10.0.  
  - Change atlcom.h before remodeling to one in the folder of Visual Studio Community 2022.  
- The Opos_Interfaces definitions for SO for Lights and POSPower have been split into two, 1.15.0 and 1.16.0.  

## Installation and others  
Please install according to the following procedure.  


- If there is already installed CCO(Common Control Objects), uninstall it.  
- Extract the separately prepared installation .zip file while keeping the folder structure.  
- If you install PIA, make sure .NET Framework 3.5 is installed.  
- Run one of the following batch files as an administrator to install and register CCO(and PIA with Publisher Policy).  
  - Install_CCOandPIA.bat  
  - Install_CCOonly.bat  

Others
- To re-register/un-register CCO (and PIA with Publisher Policy), execute the following batch file as an administrator.  
  - ReRegisterCCO.bat  
  - ReRegisterPIA.bat  
  - UnRegisterCCO.bat  
  - UnRegisterPIA.bat  
- To uninstall CCO (and PIA with Publisher Policy) and install/uninstall PIA with Publisher Policy only, execute the following batch file as an administrator.  
  - Uninstall_CCOandPIA.bat  
  - Uninstall_CCOonly.bat  
  - Install_PIAonly.bat  
  - Uninstall_PIAonly.bat  
- To install/uninstall/re-register/unregister the debug version of CCO, execute the following batch file as an administrator.  
  - Install_DbgCCO.bat  
  - Uninstall_DbgCCO.bat  
  - DbgReRegisterCCO.bat  
  - DbgUnRegisterCCO.bat  


## Known Issues  
The following issues are known.  

- The Primary Interop Assembly with Publisher Policy are not compatible with 1.14.001 and earlier OPOS for .NET Assemblies.  
- Since there is no way to include the definition name of OPOS device definition registry key name or device statistics item name in the DLL, only C# source is created.  
- OPOS device definition registry exists independently in 32bit/64bit environment, and there is no way to cooperate with them or handle them  collectively.  


## License  
Licensed under the [Apache License, Version 2.0](./LICENSE-2.0.txt).  

Original version stays in the master branch.  
All credits for the original code goes to Curtiss Monroe.  
Check the [official web site][opos] for the latest Common Control Objects information.  

[upos116]: https://www.omg.org/spec/UPOS/1.16/Beta1/PDF
[opos]: http://monroecs.com/oposccos.htm
