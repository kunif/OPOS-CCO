/////////////////////////////////////////////////////////////////////
//
// OposSply.h
//
//   Sound Player header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2021-12-02 OPOS Release 1.16                                  KF
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSSPLY_H)
#define      OPOSSPLY_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapStorage", "Storage" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG SPLY_CST_HOST_ONLY           = 1;
const LONG SPLY_CST_HARDTOTALS_ONLY     = 2;
const LONG SPLY_CST_ALL                 = 3;

const LONG SPLY_ST_HOST                 = 1;
const LONG SPLY_ST_HARDTOTALS           = 2;
const LONG SPLY_ST_HOST_HARDTOTALS      = 3;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG SPLY_SUE_START_PLAY_SOUND          =11;
const LONG SPLY_SUE_STOP_PLAY_SOUND           =12;


#endif                  // !defined(OPOSSPLY_H)
