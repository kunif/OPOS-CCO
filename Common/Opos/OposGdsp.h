/////////////////////////////////////////////////////////////////////
//
// OposGdsp.h
//
//   Graphic Display header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2021-12-02 OPOS Release 1.16                                  KF
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSGDSP_H)
#define      OPOSGDSP_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapStorage", "Storage" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG GDSP_CST_HOST_ONLY       = 1;
const LONG GDSP_CST_HARDTOTALS_ONLY = 2;
const LONG GDSP_CST_ALL             = 3;

const LONG GDSP_ST_HOST             = 1;
const LONG GDSP_ST_HARDTOTALS       = 2;
const LONG GDSP_ST_HOST_HARDTOTALS  = 3;


/////////////////////////////////////////////////////////////////////
// "DisplayMode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG GDSP_DMODE_HIDDEN        = 1;
const LONG GDSP_DMODE_IMAGE_FIT     = 2;
const LONG GDSP_DMODE_IMAGE_FILL    = 3;
const LONG GDSP_DMODE_IMAGE_CENTER  = 4;
const LONG GDSP_DMODE_VIDEO_NORMAL  = 5;
const LONG GDSP_DMODE_VIDEO_FULL    = 6;
const LONG GDSP_DMODE_WEB           = 7;


/////////////////////////////////////////////////////////////////////
// "LoadStatus" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG GDSP_LSTATUS_START       = 1;
const LONG GDSP_LSTATUS_FINISH      = 2;
const LONG GDSP_LSTATUS_CANCEL      = 3;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG GDSP_SUE_START_IMAGE_LOAD    = 11;
const LONG GDSP_SUE_END_IMAGE_LOAD      = 12;
const LONG GDSP_SUE_START_LOAD_WEBPAGE  = 21;
const LONG GDSP_SUE_FINISH_LOAD_WEBPAGE = 22;
const LONG GDSP_SUE_CANCEL_LOAD_WEBPAGE = 23;
const LONG GDSP_SUE_START_PLAY_VIDEO    = 31;
const LONG GDSP_SUE_STOP_PLAY_VIDEO     = 32;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EGDSP_NOROOM        = 201; // (Several)


#endif                  // !defined(OPOSGDSP_H)
