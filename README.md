# OpenPOS for OLE Common Control Objects Version 1.15 WIP 10/15/2018  
This is prototype of OpenPOS for OLE(formerly OLE for Retail POS: abbreviated OPOS) Common Control Objects(Common CO) based on under standardization work [UnifiedPOS Version 1.15][upos115] "UPOSVer.1.15 EVRW Revision Proposal(WIP Final)\_10152018.docx".

## Changes  
The following correspondence is made to the original 1.14.001 version.  

- Added CAT device function to the ElectronicValueReader/Writer device.  

In addition to the above, the following measures are taken.

- Changed development environment from Visual Studio 2008 to Visual Studio Community 2017.  
  - Platform toolset is Visual Studio 2017 (v141).  
  - Windows SDK version 8.1.  
  - Change atlcom.h before remodeling to one in the folder of Visual Studio Community 2017.  
  - Include guard for .h files changed from #ifndef \_\_XXXX\_H\_\_ to #pragma once.  
  - Change the name of the type library to with OPOS at the beginning and leave it as a build result.  
  - .map, .pdb file also changed to leave it as a build result.  
- Change the number of supported versions to Windows 7 or later.  
  Windows 2000, XP, Vista are no longer supported.  
- Change the debug version tracing function from RCSTrace to \_FILETRACE.  
- Added support for Intel/AMD 64bit.  
- Add OPOS internal constant definition as dll.  
- Add interface definition example for OPOS ServiceObject as dll.  
- Update annual notation of copyright statement.  


## Installation  
Please install according to the following procedure.  


- Create an appropriate folder (as below) for the target and copy the files.  
  - File copy source  
    - OPOS 32bit: \*.dll and \*.ocx in the OCX\\Win32\\Release folder  
    - OPOS 64bit: \*.dll and \*.ocx in the OCX\\x64\\Release folder  
  - OPOS 32bit copy destination  
    - 64bit OS: C:\\Program Files (x86)\\OPOS\\CommonCO115 folder  
    - 32bit OS: C:\\Program Files\\OPOS\\CommonCO115 folder  
  - OPOS 64bit files copy destination  
    - 64bit OS: C:\\Program Files\\OPOS\\CommonCO115 folder  


- Run RegSvr32.exe as an administrator and register the DLL as a registry.  
  - Prior processing at 64bit OS: Run C:\\Windows\\SysWOW64\\cmd.exe as administrator.  
  - Move to C:\\Program Files (x86)\\OPOS\\CommonCO115 folder.  
  - Run "For %I in (\*.dll,\*.ocx) do RegSvr32 /s %I".  
  - 32bit/64bit Both operating systems: Run C:\\Windows\\System32\\cmd.exe as administrator.  
  - Move to C:\\Program Files\\OPOS\\CommonCO115 folder.  
  - Run "For %I in (\*.dll,\*.ocx) do RegSvr32 /s %I".  
  - Check displayed both execution normally and close cmd.exe.  


## Known Issues  
The following issues are known.  

- It is better to be able to cooperate and synchronize with OPOS for .NET Assemblies, but I do not do anything related to it.  
- The interface definition dll for OPOS ServiceObject may have compatibility problems if there is an interface addition in the next 1.16 version etc. It may not be included in the official version.  
- Installer is not created.  
- Since there is no way to include the definition name of OPOS device definition registry key name or device statistics item name in the DLL, only C# source is created.  
- OPOS device definition registry exists independently in 32bit/64bit environment, and there is no way to cooperate with them or handle them  collectively.  


## License  
Licensed under the [Apache License, Version 2.0](./LICENSE-2.0.txt).  

Original version stays in the master branch.  
All credits for the original code goes to Curtiss Monroe.  
Check the [official web site][opos] for the latest Common Control Objects information.  

[upos115]: https://issues.omg.org/issues/lists/retail-up115-ftf?view=ALL
[opos]: http://monroecs.com/oposccos.htm
