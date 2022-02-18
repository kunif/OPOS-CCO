                     OPOS Common Control Objects
                               1.16.000 (Beta8)
                      Updated February 18, 2022

Contents of this file:
 * Features
 * Update history
 * Legal
 * Contact information

NOTE: The installation package does not install any system DLLs.
      It only puts files into the directories that you specify.

====================================================================
    Features
====================================================================

 * All 45 control objects of OPOS Release 1.16.000 (Beta) are supported.
    Also includes an object that declares all of the OPOS constants.
    To use these constants...
     - Visual Basic: Select the menu item Project / References, and check "OPOS
        1.16 Constants".
     - Visual C++: Add the line
            #import "path\Opos_Constants.dll" no_namespace
        to a source file, replacing path with the installed location of the file
        (or putting this location in the Include section under the Directories
        tab of the Tools / Options menu).
 * ATL-based, using dual interfaces so that the app can access them via
    IDispatch or COM interfaces (of the form IOPOSCashDrawer, etc).
 * Built using Microsoft Visual Studio Community 2022.
 * Backward compatible with all releases of service objects. This means that
    they check for older SOs, and return the proper errors to the app if it
    accesses unsupported properties or methods.
 * Event firing logic supports well-behaved service objects that fire events
    from the thread that created the control, plus other service objects that
    fire them from other threads.
 * Self-contained, requiring only standard OS DLLs. Specifically, they do not
    require MFC or ATL DLLs.
 * Only the Unicode versions are built and posted.
 * Source code for all control objects is available.
 * For future additions, it is easy to add new control objects or update old
    ones. A custom generator was developed that reads a data file for each
    control to be built. To add properties or methods, the procedure is update
    the data files, regenerate, and build the resulting projects.
 * Provides PIA(Primary Interop Assembly) created with .NET Framework 3.5 tools.

====================================================================
    Trace Details
====================================================================

The debug CCOs require the COM objects RCSTraceOut.exe and RCSTraceOutPS.dll to
be registered.

By default, the trace subsystem will try to write the trace files to:
    C:\Program Files\NCR\AdvancedStore\Logs
if this directory exists. If it does not exist, then they are written to C:\.
On Windows 7 (by default) these files will be virtualized to
%localappdata%\VirtualStore (C:\Users\%username%\AppData\Local\VirtualStore).

The file name format is:
    yyyymmdd-OposCCO_device.log
where yyyymmdd is the date and device is the OPOS device name, such as
POSPrinter. After the date changes and a trace file is written, then the
previous 4 days' files are ZIPped, with the name:
    yyyymmdd-OposCCO_device.zip

In order to change the directory of the trace files, create a configuration
file:
    C:\RCSTrace.ini
or, on Windows 7 with virtualization:
    %localappdata%\VirtualStore\RCSTrace.ini
containing the following lines, where "directory" is the trace directory:

[Default]
Dir=directory
RCSTraceLog=N

(The line "RCSTraceLog=N" inhibits the tracer from writing a file about its
activities, named RCSTrace.log.)

If you do not want the configuration file to be at "C:\RCSTrace.ini" or its
virtualized, user-specific location, then create or update the key:
    HKLM\SOFTWARE\Research Computer Services\RTE\Tracing\RCSTrace
Add a string value "Config" whose data is the configuration file name.
This key's permissions must allow at least read access.

====================================================================
    Update History
====================================================================

1.16.000 (Beta8) - February 18, 2022

 * Add SoundPlayer ErrorEvent constant to OposSply.h, Opos_Constants.dll.

1.16.000 (Beta7) - February 2, 2022

 * Correct GraphicDisplay device OCX/PIA/Policy, Opos_Interfaces.dll. becouse method name was incorrect.

1.16.000 (Beta6) - January 21, 2022

 * Correct Lights device OCX/PIA/Policy. becouse .idl source code was incorrect.

1.16.000 (Beta5) - January 18, 2022

 * Add POSPower StatusUpdateEvent constant to OposPwr.h, Opos_Constants.dll.

1.16.000 (Beta4) - December 28, 2021

 * Correct typo, GestureControl source code for Opos_Internals.dll.
 * Correct typo, some devices DataFiles.

1.16.000 (Beta3) - December 25, 2021

 * Correct Lights, POSPower devices OCX/PIA/Policy did not update for RCSD feature.

1.16.000 (Beta2) - December 22, 2021

 * Correct typo, VoiceRecognition source code for Opos_Internals.dll.

1.16.000 (Beta) - December 2, 2021

 * Apply OPOS Release 1.16.000 (Beta) API support:
    - Change VideoCapture StatusUpdateEvent define names.
 * Convert from VSC 2019 to VSC 2022.
    - Change the underlying atlcom.h to VSC 2022 file.
 * Adjust date information of include files and timestamp of all files

1.16.000 (Alpha) - January 26, 2021

 * Apply OPOS Release 1.16.000 (Alpha) API support:
    - Addition 9 devices for Retail Communication Service Device(RCSD).
    - Addition to Lights, POSPower devices for RCSD feature.
 * Add Publisher Policy file for .NET applications created for CCO 1.15.000.

1.15.000 (Issue UPOS116-9) - June 1, 2020

 * Correct for alphabetical order of DispatchID of the property added in EVRW.
    - PaymentMedia, SlipNumber
 * Apply OPOS Release 1.15.000 (Issue UPOS116-9) API support:
    - Addition to EVRW ServiceType property define EVRW_ST_CAT.
 * Add PIA(Primary Interop Assembly) support:
    - Create using .NET Framework 3.5 tools and register to GAC.
    - Change the MCS code signing certificates to private strong name key pair.
      Due to this change, it is not compatible with PIA 1.14.001 or earlier.
 * Add Install/Uninstall/ReRegister/UnRegister batch files.

1.15.000 (Beta2 122018) - December 10, 2019

 * Add OPOS Release 1.15.000 (Beta2 122018) API support:
    - Additions to EVRW and FiscalPrinter.
 * Convert from VS 2008 to VSC 2019.
    - Change the Windows SDK Version to 10.0
    - Change the underlying atlcom.h to VSC 2019 file.
    - Change include guard from #ifndef __XXXX_H__ to #pragma once
    - Moved stdafx.h/cpp and added targetver.h to the Common folder
      and shared it.
    - Changed the name of the TypeLibrary file and leave the build result.
    - Also keep the .map and .pdb files of the build results.
 * Build and post for Windows 7 and later.
    Windows 2000, XP, Vista are no longer supported.
 * Change DEBUG Version Trace from RCSTrace to _FILETRACE
 * Add Intel/AMD 64bit support.
 * Add OPOS internal constants definition.
 * Add OPOS SO interfaces definition.
 * Add the initial of the modifier(KF) to the publisher initail(CRM/MCS).

1.14.001 - February 7, 2015

 * Add OPOS Release 1.14.1 API support: Additions to EVRW.
 * Correct memory leak due to mishandling of variants returned from SO.
    This was most common when getting string properties.
    Problem is present in releases 1.12, 1.13, and 1.14.
 * Correct potential buffer overrun in Open.
 * Correct EVRW TransitionEvent dispatch ID (from 2 to 6).
 * Update license information.

1.14.000 - October 3, 2013

 * Add OPOS Release 1.14 API support.
 * Update trace details above.

1.13.003 - Updated February 7, 2015

 * Correct memory leak due to mishandling of variants returned from SO.
    This was most common when getting string properties.
    Problem is present in earlier releases of 1.12, 1.13, and 1.14.
 * Correct potential buffer overrun in Open.
 * Update license information.

1.13.002 - December 3, 2012

 * Update debug version's RCSTrace to latest NCR release.
    Will work better with Windows 7, since tracing won't try to create or open
    keys in HKLM with write access.
    Added trace details above.

1.13.001 - March 1, 2010

 * Correction for backward compatibility.
    Was not registering all previous releases' interfaces.
    Caused marshaling problems when using across process boundaries, plus issues
    for some development environments.

1.13.000 - December 31, 2009

 * Add OPOS Release 1.13 API support.

1.12.000 - August 30, 2008

 * Build and post Unicode versions for Windows 2000 and later.
    Windows 95/98/ME are no longer supported.
    Windows NT 4 is no longer supported.
 * Convert from VC++ 6 to VS 2008.
    Use the standard ATL header files, except for atlcom.h, which was modified
    to support the legacy "Claim" and "Release" methods via IDispatch.
    Some preprocessor magic is used to work around issues with HardTotal's
    Create method and LineDisplay's CreateWindow method.
 * COM Interface IDs for versions prior to those used in OPOS 1.6 are no longer
    supported. Applications built against pre-1.6 CCOs that cached the old IIDs
    (instead of using the default IID) will either need to continue to use a
    previous CCO, or be rebuilt against these new ones.
 * Some significant changes were made to the code:
    - To conform to COM rules, previous release interfaces now include only
        their properties and methods, instead of all properties and methods.
        Previously, each interface change effectively extended all previous
        interfaces.
    - Variant variable handling has been reworked for safety and error
        detection: NULL pointers and memory failures are detected and cause an
        appropriate failure HRESULT to be returned, instead of assuming good
        pointers and successful allocation.
    - CCO initialization checks for critical failures and returns a failure
        HRESULT, instead of assuming success.
 * The library names have been stabilized to Opos***_CCO, where *** is the
    device name. Previously, the release number was included, which would cause
    development environments that cache the name to fail when loading new CCOs.
 * The names of the current interface continue to be IOPOS***, where *** is the
    device name. The names of previous interfaces now have the form
    IOPOS***_1_*, where *** is the device name and * is the release number.

1.11.001 - December 4, 2007

 * Correct handling of CO methods that are not supported by the SO's version.
    Previously returned OPOS_SUCCESS status, instead of OPOS_E_NOSERVICE.

1.11.000 - January 30, 2007

 * Add OPOS Release 1.11 API support.

1.10.002 - December 4, 2007

 * Correct handling of CO methods that are not supported by the SO's version.
    Previously returned OPOS_SUCCESS status, instead of OPOS_E_NOSERVICE.
 * Update MSR's WriteTracks method to conform to the updated 1.11 parameters.
    (Since this is a new method in 1.10, the committee decided to correct the
    parameter retroactively.)

1.10.001 - September 22, 2006

 * Update Biometrics to match upcoming 1.11 specification.

1.10.000 - March 15, 2006

 * Add OPOS Release 1.10 API support.
 * Add initialization of [out] BSTR* parameters before calling the service
    object. This was added for safety: A COM object is supposed to assume that
    the value at the incoming pointer is invalid, and just write over any value.
    This addition ensures that the string pointer is NULL just in case the
    service incorrectly treats a non-NULL string pointer as valid.

1.9.003 - August 20, 2008

 * Correct debug CCOs. The 1.9.002 CCOs inadvertantly required a tracing COM
    object that is not distributed.

1.9.002 - December 4, 2007

 * Correct handling of CO methods that are not supported by the SO's version.
    Previously returned OPOS_SUCCESS status, instead of OPOS_E_NOSERVICE.
 * Add Debug tracing of event delivery.

1.9.000 - April 29, 2005

 * Add OPOS Release 1.9 API support.

1.8.001 - October 26, 2004

 * Correct memory leak when getting string property.
 * Update several header files with constants that were missed in previous
    releases.
 * Add new device statistics header file, OposStat.h.
 * Minor enhancement to Debug tracing of strings.

1.8.000 - March 22, 2004

 * Add OPOS Release 1.8 API support.
 * Add significantly more tracing when Debug.

1.7.002 - December 2, 2003

 * Rebuild after applying updates to some ATL files per Microsoft Knowledge Base
    Articles: ATLBASE.H (190686, 305746), ATLCOM.H (266713), ATLCONV.H (266713).
 * Changed the legal license language.

1.7.001 - May 29, 2003

 * On Debug builds, add tracing of Open and Close to C:\OposCCO_@DeviceName@.log
 * Update OposPtr.h with constants added in OPOS Release 1.7.

1.7.000 - August 17, 2002

 * Add OPOS Release 1.7 API support.

1.6.001 - March 7, 2002

 * Mark CCOs as safe for initialization and scripting.
 * Correct FiscalPrinter method name from PrintRecItemVoidFuel to
    PrintRecItemFuelVoid.

1.6.000 - July 19, 2001

 * Add OPOS Release 1.6 API support.

1.5.103 - July 9, 2001

 * Updated EventClose() to only discard user messages. Was causing some CE apps
    to hang due to bogus WinCE messages.

1.5.102 - June 23, 2001

 * Enhance (correct) to properly support multiple SOs per device type.
 * Includes PINPad built with updated OposPpad.hi (which corrected Track4Data
    property index).

1.5.101 - January 2, 2001

 * OPOS Release 1.5 API support.
 * Added OPOS Constants DLL (Opos_Constants.dll).

1.5.100 Alpha - September 18, 2000

 * Initial pre-Beta version with OPOS Release 1.5 API support.

1.5.3 Beta  -  December 7, 1999
1.5.2 Beta  -  August 23, 1999
1.5.1 Beta  -  July 28, 1999
1.5.0 Beta  -  June 18, 1999

1.4.994 Beta  -  March 25, 1999
1.4.993 Beta  -  March 22, 1999
1.4.992 Beta  -  March 20, 1999
1.4.991 Limited Beta  -  February 7, 1999

====================================================================
    Legal
====================================================================

The following lines appear in many of the source code files from which
the binary Control Objects are built, in the version resource's
"License" item, and in the binary Control Object files (following the
marker "~~License~~"):

Copyright 2015 Monroe Consulting Services, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

====================================================================

Curtiss Monroe
crmonroe@monroecs.com

Check the web site
    http://monroecs.com/oposccos.htm
for the latest Common Control Object information.
