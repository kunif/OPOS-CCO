/////////////////////////////////////////////////////////////////////
//
// OposGctl.h
//
//   Gesture Control header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2021-12-02 OPOS Release 1.16                                  KF
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSGCTL_H)
#define      OPOSGCTL_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapStorage", "Storage" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG GCTL_CST_HOST_ONLY       = 1;
const LONG GCTL_CST_HARDTOTALS_ONLY = 2;
const LONG GCTL_CST_ALL             = 3;

const LONG GCTL_ST_HOST             = 1;
const LONG GCTL_ST_HARDTOTALS       = 2;
const LONG GCTL_ST_HOST_HARDTOTALS  = 3;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG GCTL_SUE_START_MOTION    = 11;
const LONG GCTL_SUE_STOP_MOTION     = 12;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EGCTL_NOROOM        = 201; // (Several)


#endif                  // !defined(OPOSGCTL_H)
