/////////////////////////////////////////////////////////////////////
//
// OposSrec.h
//
//   Sound Recorder header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2021-12-02 OPOS Release 1.16                                  KF
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSSREC_H)
#define      OPOSSREC_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapStorage", "Storage" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG SREC_CST_HOST_ONLY       = 1;
const LONG SREC_CST_HARDTOTALS_ONLY = 2;
const LONG SREC_CST_ALL             = 3;

const LONG SREC_ST_HOST             = 1;
const LONG SREC_ST_HARDTOTALS       = 2;
const LONG SREC_ST_HOST_HARDTOTALS  = 3;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG SREC_SUE_START_SOUND_RECORDING  = 11;
const LONG SREC_SUE_STOP_SOUND_RECORDING   = 12;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_ESREC_NOROOM        = 201;


#endif                  // !defined(OPOSSREC_H)
