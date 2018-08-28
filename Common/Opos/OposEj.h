/////////////////////////////////////////////////////////////////////
//
// OposEj.h
//
//   Electronic Journal header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2006-03-15 OPOS Release 1.10                                  CRM
// 2008-08-30 OPOS Release 1.12                                  CRM
//   Add constant to StatusUpdateEvent.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSEJ_H)
#define      OPOSEJ_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapStation", "Station" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG EJ_S_RECEIPT                 = 0x00000001;
const LONG EJ_S_SLIP                    = 0x00000002;
const LONG EJ_S_JOURNAL                 = 0x00000004;


/////////////////////////////////////////////////////////////////////
// "retrieveCurrentMarker" Method, "markerType" Parameter Constants
// "retrieveMarker" Method, "markerType" Parameter Constants
// "retrieveMarkerByDateTime" Method, "markerType" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG EJ_MT_SESSION_BEG            = 1;
const LONG EJ_MT_SESSION_END            = 2;
const LONG EJ_MT_DOCUMENT               = 3;
const LONG EJ_MT_HEAD                   = 4;
const LONG EJ_MT_TAIL                   = 5;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property and "ErrorEvent" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EEJ_EXISTING            = 201;
const LONG OPOS_EEJ_MEDIUM_FULL         = 202;
const LONG OPOS_EEJ_MULTIPLE_MARKER     = 203;
const LONG OPOS_EEJ_UNINITIALIZED_MEDIUM= 204;
const LONG OPOS_EEJ_CORRUPTED_MEDIUM    = 205;
const LONG OPOS_EEJ_UNKNOWN_DATAFORMAT  = 206;
const LONG OPOS_EEJ_NOT_ENOUGH_SPACE    = 207;
const LONG OPOS_EEJ_MULTIPLE_MARKERS    = 208;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" "Status" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG EJ_SUE_MEDIUM_NEAR_FULL      = 1;
const LONG EJ_SUE_MEDIUM_FULL           = 2;
const LONG EJ_SUE_MEDIUM_REMOVED        = 3;
const LONG EJ_SUE_MEDIUM_INSERTED       = 4;
const LONG EJ_SUE_SUSPENDED             = 5;
const LONG EJ_SUE_IDLE                  = 1001; // (added in 1.12)


#endif                  // !defined(OPOSEJ_H)
