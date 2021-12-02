/////////////////////////////////////////////////////////////////////
//
// OposDmon.h
//
//   Device Monitor header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2021-12-02 OPOS Release 1.16                                  KF
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSDMON_H)
#define      OPOSDMON_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "AddMonitoringDevice" Methods: "MonitoringMode" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG DMON_MMODE_UPDATE          = 1;
const LONG DMON_MMODE_STRADDLED       = 2;
const LONG DMON_MMODE_HIGH            = 3;
const LONG DMON_MMODE_LOW             = 4;
const LONG DMON_MMODE_WITHIN          = 5;
const LONG DMON_MMODE_OUTSIDE         = 6;
const LONG DMON_MMODE_POLLING         = 7;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG DMON_SUE_START_MONITORING  = 11;
const LONG DMON_SUE_STOP_MONITORING   = 12;


#endif                  // !defined(OPOSDMON_H)
