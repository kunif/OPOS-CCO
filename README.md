# OpenPOS for OLE Common Control Objects Version 1.15 with Issue UPOS116-9  
This is OpenPOS for OLE(formerly OLE for Retail POS: abbreviated OPOS) Common Control Objects(Common CO) based on [UnifiedPOS Version 1.15][upos115] "Unified POS Retail Peripheral Architecture Version 1.15 formal/2020-01-05".  

## Changes  
The following correspondence is made to the original 1.14.001 version.  

- Added CAT device function to the ElectronicValueReader/Writer device.  
- Added ElectronicValueReader/Writer device ServiceType property define EVRW_ST_CAT. corresponding to [Issue UPOS116-9][UPOS1169]  
- Added CountryCode, DateType value to the FiscalPrinter device.  

In addition to the above, the following measures are taken.  

- Changed development environment from Visual Studio 2008 to Visual Studio Community 2019.  
  - Platform toolset is Visual Studio 2019 (v142).  
  - Windows SDK version 10.0.  
  - Change atlcom.h before remodeling to one in the folder of Visual Studio Community 2019.  
  - Include guard for .h files changed from #ifndef \_\_XXXX\_H\_\_ to #pragma once.  
  - Change the name of the type library to with OPOS at the beginning and leave it as a build result.  
  - .map, .pdb file also changed to leave it as a build result.  
- Change the number of supported versions to Windows 7 or later.  
  Windows 2000, XP, Vista are no longer supported.  
- Change the debug version tracing function from RCSTrace to \_FILETRACE.  
- Added support for Intel/AMD 64bit.  
- Add OPOS internal constant definition as dll.  
- Add interface definition example for OPOS ServiceObject as dll.  
- Add the initial of the modifier(KF) to the publisher initail(CRM/MCS).  
- The Opos_Interfaces definition for EVRWSO is divided into two for 1.14.1 and 1.15.0.  
- Add Primary Interop Assembly.  
- Add Install/Uninstall/ReRegister/UnRegister batch files.  


## Installation and others  
Please install according to the following procedure.  


- If there is already installed CCO(Common Control Objects), uninstall it.  
- Extract the separately prepared installation .zip file while keeping the folder structure.  
- If you install PIA, make sure .NET Framework 3.5 is installed.  
- Run one of the following batch files as an administrator to install and register CCO(and PIA).  
  - Install_CCOandPIA.bat  
  - Install_CCOonly.bat  

Others
- To re-register/un-register CCO (and PIA), execute the following batch file as an administrator.  
  - ReRegisterCCO.bat  
  - ReRegisterPIA.bat  
  - UnRegisterCCO.bat  
  - UnRegisterPIA.bat  
- To uninstall CCO (and PIA) and install/uninstall PIA only, execute the following batch file as an administrator.  
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

- The Primary Interop Assembly is not compatible with 1.14.001 and earlier OPOS for .NET Assemblies.  
- Since there is no way to include the definition name of OPOS device definition registry key name or device statistics item name in the DLL, only C# source is created.  
- OPOS device definition registry exists independently in 32bit/64bit environment, and there is no way to cooperate with them or handle them  collectively.  


## License  
Licensed under the [Apache License, Version 2.0](./LICENSE-2.0.txt).  

Original version stays in the master branch.  
All credits for the original code goes to Curtiss Monroe.  
Check the [official web site][opos] for the latest Common Control Objects information.  

[UPOS1169]: https://issues.omg.org/issues/spec/UPOS/1.15#issue-45536
[upos115]: https://www.omg.org/spec/UPOS/1.15/PDF
[opos]: http://monroecs.com/oposccos.htm
