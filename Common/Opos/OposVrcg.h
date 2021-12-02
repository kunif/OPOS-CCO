/////////////////////////////////////////////////////////////////////
//
// OposVrcg.h
//
//   Voice Recognition header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2021-12-02 OPOS Release 1.16                                  KF
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSVRCG_H)
#define      OPOSVRCG_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "HearingResult" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG VRCG_HRESULT_FREE                   = 11;
const LONG VRCG_HRESULT_SENTENCE               = 21;
const LONG VRCG_HRESULT_WORD                   = 31;
const LONG VRCG_HRESULT_YESNO_YES              = 41;
const LONG VRCG_HRESULT_YESNO_NO               = 42;
const LONG VRCG_HRESULT_YESNO_CANCEL           = 43;


/////////////////////////////////////////////////////////////////////
// "HearingStatus" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG VRCG_HSTATUS_NONE                   =  0;
const LONG VRCG_HSTATUS_FREE                   = 10;
const LONG VRCG_HSTATUS_SENTENCE               = 20;
const LONG VRCG_HSTATUS_WORD                   = 30;
const LONG VRCG_HSTATUS_YESNO                  = 40;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG VRCG_SUE_STOP_HEARING               =  0;
const LONG VRCG_SUE_START_HEARING_FREE         = 10;
const LONG VRCG_SUE_START_HEARING_SENTENCE     = 20;
const LONG VRCG_SUE_START_HEARING_WORD         = 30;
const LONG VRCG_SUE_START_HEARING_YESNO        = 40;


#endif                  // !defined(OPOSVRCG_H)
