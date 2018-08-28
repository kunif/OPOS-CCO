/////////////////////////////////////////////////////////////////////
//
// OposGate.h
//
//   Gate header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2008-08-30 OPOS Release 1.12                                  CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSGATE_H)
#define      OPOSGATE_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "GateStatus" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG GATE_GS_CLOSED               = 1;
const LONG GATE_GS_OPEN                 = 2;
const LONG GATE_GS_BLOCKED              = 3;
const LONG GATE_GS_MALFUNCTION          = 4;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG GATE_SUE_CLOSED              = 11;
const LONG GATE_SUE_OPEN                = 12;
const LONG GATE_SUE_BLOCKED             = 13;
const LONG GATE_SUE_MALFUNCTION         = 14;


#endif                  // !defined(OPOSGATE_H)
