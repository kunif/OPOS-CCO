/////////////////////////////////////////////////////////////////////
//
// Opos.h
//
//   General header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1995-12-08 OPOS Release 1.0                                   CRM
// 1997-06-04 OPOS Release 1.2                                   CRM
//   Add OPOS_FOREVER.
//   Add BinaryConversion constants.
// 1998-03-06 OPOS Release 1.3                                   CRM
//   Add CapPowerReporting, PowerState, and PowerNotify constants.
//   Add power reporting constants for StatusUpdateEvent.
// 2000-09-24 OPOS Release 1.5                                   CRM
//   Add OpenResult status constants.
// 2004-10-26 OPOS Release 1.8                                   CRM
//   Add "ResultCodeExtended" statistics constant.
// 2005-04-29 OPOS Release 1.9                                   CRM
//   Add CompareFirmwareVersion's Result constants.
//   Add StatusUpdateEvent and ResultCodeExtended constants
//     for firmware update.
// 2006-03-15 OPOS Release 1.10                                  CRM
//   Add another constant for firmware update.
// 2007-01-30 OPOS Release 1.11                                  CRM
//   Add ResultCode constant for deprecation.
// 2008-08-30 OPOS Release 1.12                                  CRM
//   Comment updates.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOS_H)
#define      OPOS_H


/////////////////////////////////////////////////////////////////////
// OPOS "State" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_S_CLOSED        = 1;
const LONG OPOS_S_IDLE          = 2;
const LONG OPOS_S_BUSY          = 3;
const LONG OPOS_S_ERROR         = 4;


/////////////////////////////////////////////////////////////////////
// OPOS "ResultCode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_SUCCESS         =   0;
const LONG OPOS_E_CLOSED        = 101;
const LONG OPOS_E_CLAIMED       = 102;
const LONG OPOS_E_NOTCLAIMED    = 103;
const LONG OPOS_E_NOSERVICE     = 104;
const LONG OPOS_E_DISABLED      = 105;
const LONG OPOS_E_ILLEGAL       = 106;
const LONG OPOS_E_NOHARDWARE    = 107;
const LONG OPOS_E_OFFLINE       = 108;
const LONG OPOS_E_NOEXIST       = 109;
const LONG OPOS_E_EXISTS        = 110;
const LONG OPOS_E_FAILURE       = 111;
const LONG OPOS_E_TIMEOUT       = 112;
const LONG OPOS_E_BUSY          = 113;
const LONG OPOS_E_EXTENDED      = 114;
const LONG OPOS_E_DEPRECATED    = 115; // (added in 1.11)

const LONG OPOSERR    = 100; // Base for ResultCode errors.
const LONG OPOSERREXT = 200; // Base for ResultCodeExtendedErrors.


/////////////////////////////////////////////////////////////////////
// OPOS "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

// The following applies to ResetStatistics and UpdateStatistics.
const LONG OPOS_ESTATS_ERROR       = 280; // (added in 1.8)
const LONG OPOS_ESTATS_DEPENDENCY  = 282; // (added in 1.10)
// The following applies to CompareFirmwareVersion and UpdateFirmware.
const LONG OPOS_EFIRMWARE_BAD_FILE = 281; // (added in 1.9)


/////////////////////////////////////////////////////////////////////
// OPOS "OpenResult" Property Constants (added in 1.5)
/////////////////////////////////////////////////////////////////////

// The following can be set by the control object.
//  - Control Object already open.
const LONG OPOS_OR_ALREADYOPEN  = 301;
//  - The registry does not contain a key for the specified device name.
const LONG OPOS_OR_REGBADNAME   = 302;
//  - Could not read the device name key's default value, or
//     could not convert this Prog ID to a valid Class ID.
const LONG OPOS_OR_REGPROGID    = 303;
//  - Could not create a service object instance, or
//     could not get its IDispatch interface.
const LONG OPOS_OR_CREATE       = 304;
//  - The service object does not support one or more of the
//     method required by its release.
const LONG OPOS_OR_BADIF        = 305;
//  - The service object returned a failure status from its
//     open call, but doesn't have a more specific failure code.
const LONG OPOS_OR_FAILEDOPEN   = 306;
//  - The service object major version number is not 1.
const LONG OPOS_OR_BADVERSION   = 307;

// The following can be returned by the service object if it
// returns a failure status from its open call.
//  - Port access required at open, but configured port
//     is invalid or inaccessible.
const LONG OPOS_ORS_NOPORT      = 401;
//  - Service Object does not support the specified device.
const LONG OPOS_ORS_NOTSUPPORTED= 402;
//  - Configuration information error.
const LONG OPOS_ORS_CONFIG      = 403;
//  - Errors greater than this value are SO-specific.
const LONG OPOS_ORS_SPECIFIC    = 450;


/////////////////////////////////////////////////////////////////////
// OPOS "BinaryConversion" Property Constants (added in 1.2)
/////////////////////////////////////////////////////////////////////

const LONG OPOS_BC_NONE         = 0;
const LONG OPOS_BC_NIBBLE       = 1;
const LONG OPOS_BC_DECIMAL      = 2;


/////////////////////////////////////////////////////////////////////
// "CheckHealth" Method: "Level" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_CH_INTERNAL     = 1;
const LONG OPOS_CH_EXTERNAL     = 2;
const LONG OPOS_CH_INTERACTIVE  = 3;


/////////////////////////////////////////////////////////////////////
// OPOS "CapPowerReporting", "PowerState", "PowerNotify" Property
//   Constants (added in 1.3)
/////////////////////////////////////////////////////////////////////

const LONG OPOS_PR_NONE         = 0;
const LONG OPOS_PR_STANDARD     = 1;
const LONG OPOS_PR_ADVANCED     = 2;

const LONG OPOS_PN_DISABLED     = 0;
const LONG OPOS_PN_ENABLED      = 1;

const LONG OPOS_PS_UNKNOWN      = 2000;
const LONG OPOS_PS_ONLINE       = 2001;
const LONG OPOS_PS_OFF          = 2002;
const LONG OPOS_PS_OFFLINE      = 2003;
const LONG OPOS_PS_OFF_OFFLINE  = 2004;


/////////////////////////////////////////////////////////////////////
// "CompareFirmwareVersion" Method: "Result" Parameter Constants
//   (added in 1.9)
/////////////////////////////////////////////////////////////////////

const LONG OPOS_CFV_FIRMWARE_OLDER      = 1;
const LONG OPOS_CFV_FIRMWARE_SAME       = 2;
const LONG OPOS_CFV_FIRMWARE_NEWER      = 3;
const LONG OPOS_CFV_FIRMWARE_DIFFERENT  = 4;
const LONG OPOS_CFV_FIRMWARE_UNKNOWN    = 5;


/////////////////////////////////////////////////////////////////////
// "ErrorEvent" Event: "ErrorLocus" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EL_OUTPUT       = 1;
const LONG OPOS_EL_INPUT        = 2;
const LONG OPOS_EL_INPUT_DATA   = 3;


/////////////////////////////////////////////////////////////////////
// "ErrorEvent" Event: "ErrorResponse" Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_ER_RETRY        = 11;
const LONG OPOS_ER_CLEAR        = 12;
const LONG OPOS_ER_CONTINUEINPUT= 13;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: Common "Status" Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_SUE_POWER_ONLINE                    = 2001; // (added in 1.3)
const LONG OPOS_SUE_POWER_OFF                       = 2002; // (added in 1.3)
const LONG OPOS_SUE_POWER_OFFLINE                   = 2003; // (added in 1.3)
const LONG OPOS_SUE_POWER_OFF_OFFLINE               = 2004; // (added in 1.3)

const LONG OPOS_SUE_UF_PROGRESS                     = 2100; // (added in 1.9)
const LONG OPOS_SUE_UF_COMPLETE                     = 2200; // (added in 1.9)
const LONG OPOS_SUE_UF_COMPLETE_DEV_NOT_RESTORED    = 2205; // (added in 1.9)
const LONG OPOS_SUE_UF_FAILED_DEV_OK                = 2201; // (added in 1.9)
const LONG OPOS_SUE_UF_FAILED_DEV_UNRECOVERABLE     = 2202; // (added in 1.9)
const LONG OPOS_SUE_UF_FAILED_DEV_NEEDS_FIRMWARE    = 2203; // (added in 1.9)
const LONG OPOS_SUE_UF_FAILED_DEV_UNKNOWN           = 2204; // (added in 1.9)


/////////////////////////////////////////////////////////////////////
// General Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_FOREVER         = -1; // (added in 1.2)


#endif                  // !defined(OPOS_H)
