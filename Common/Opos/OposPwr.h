/////////////////////////////////////////////////////////////////////
//
// OposPwr.h
//
//   POSPower header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2000-09-24 OPOS Release 1.5                                   TH
// 2005-04-29 OPOS Release 1.9                                   CRM
//   Add PowerSource constants.
//   Add Reason constants for RestartPOS, StandbyPOS, SuspendPOS.
//   Add StatusUpdateEvent constants for battery support.
// 2022-01-18 OPOS Release 1.16                                  KF
//   Add StatusUpdateEvent constants for battery support by in seconds.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSPOWER_H)
#define      OPOSPOWER_H

/////////////////////////////////////////////////////////////////////
// "UPSChargeState" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PWR_UPS_FULL         = 1;
const LONG PWR_UPS_WARNING      = 2;
const LONG PWR_UPS_LOW          = 4;
const LONG PWR_UPS_CRITICAL     = 8;


/////////////////////////////////////////////////////////////////////
// "PowerSource" Property Constants (added in 1.9)
/////////////////////////////////////////////////////////////////////

const LONG PWR_SOURCE_NA        = 1;
const LONG PWR_SOURCE_AC        = 2;
const LONG PWR_SOURCE_BATTERY   = 3;
const LONG PWR_SOURCE_BACKUP    = 4;


/////////////////////////////////////////////////////////////////////
// "RestartPOS", "StandbyPOS", "SuspendPOS" Methods:
//   "Reason" Parameter Constants (added in 1.9)
/////////////////////////////////////////////////////////////////////

const LONG PWR_REASON_REQUEST   = 1;
const LONG PWR_REASON_ALLOW     = 2;
const LONG PWR_REASON_DENY      = 3;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Status" Constants
/////////////////////////////////////////////////////////////////////

const LONG PWR_SUE_UPS_FULL                 = 11;
const LONG PWR_SUE_UPS_WARNING              = 12;
const LONG PWR_SUE_UPS_LOW                  = 13;
const LONG PWR_SUE_UPS_CRITICAL             = 14;
const LONG PWR_SUE_FAN_STOPPED              = 15;
const LONG PWR_SUE_FAN_RUNNING              = 16;
const LONG PWR_SUE_TEMPERATURE_HIGH         = 17;
const LONG PWR_SUE_TEMPERATURE_OK           = 18;
const LONG PWR_SUE_SHUTDOWN                 = 19;
const LONG PWR_SUE_BAT_LOW                  = 20; // (added in 1.9)
const LONG PWR_SUE_BAT_CRITICAL             = 21; // (added in 1.9)
const LONG PWR_SUE_BAT_CAPACITY_REMAINING   = 22; // (added in 1.9)
const LONG PWR_SUE_RESTART                  = 23; // (added in 1.9)
const LONG PWR_SUE_STANDBY                  = 24; // (added in 1.9)
const LONG PWR_SUE_USER_STANDBY             = 25; // (added in 1.9)
const LONG PWR_SUE_SUSPEND                  = 26; // (added in 1.9)
const LONG PWR_SUE_USER_SUSPEND             = 27; // (added in 1.9)
const LONG PWR_SUE_PWR_SOURCE               = 28; // (added in 1.9)
const LONG PWR_SUE_BAT_CAPACITY_REMAINING_IN_SECONDS = 29; // (added in 1.16)

#endif                  // !defined(OPOSPOWER_H)
