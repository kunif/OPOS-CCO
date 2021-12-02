/////////////////////////////////////////////////////////////////////
//
// OposVcap.h
//
//   Video Capture header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2021-12-02 OPOS Release 1.16                                  KF
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSVCAP_H)
#define      OPOSVCAP_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapStorage", "Storage" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG VCAP_CST_HOST_ONLY       = 1;
const LONG VCAP_CST_HARDTOTALS_ONLY = 2;
const LONG VCAP_CST_ALL             = 3;

const LONG VCAP_ST_HOST             = 1;
const LONG VCAP_ST_HARDTOTALS       = 2;
const LONG VCAP_ST_HOST_HARDTOTALS  = 3;


/////////////////////////////////////////////////////////////////////
// "VideoCaptureMode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG VCAP_VCMODE_PHOTO        = 1;
const LONG VCAP_VCMODE_VIDEO        = 2;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG VCAP_SUE_START_PHOTO            = 11;
const LONG VCAP_SUE_END_PHOTO              = 12;

const LONG VCAP_SUE_START_VIDEO            = 21;
const LONG VCAP_SUE_STOP_VIDEO             = 22;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EVCAP_NOROOM        = 201; // (Several)


#endif                  // !defined(OPOSVCAP_H)
