/////////////////////////////////////////////////////////////////////
//
// OposCoin.h
//
//   Coin Dispenser header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1995-12-08 OPOS Release 1.0                                   CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSCOIN_H)
#define      OPOSCOIN_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "DispenserStatus" Property Constants
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG COIN_STATUS_OK       = 1;
const LONG COIN_STATUS_EMPTY    = 2;
const LONG COIN_STATUS_NEAREMPTY= 3;
const LONG COIN_STATUS_JAM      = 4;


#endif                  // !defined(OPOSCOIN_H)
