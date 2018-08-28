/////////////////////////////////////////////////////////////////////
//
// OposItem.h
//
//   Item Dispenser header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2008-08-30 OPOS Release 1.12                                  CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSITEM_H)
#define      OPOSITEM_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "DispenserStatus" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG ITEM_DS_OK                   = 1;
const LONG ITEM_DS_EMPTY                = 2;
const LONG ITEM_DS_NEAREMPTY            = 3;
const LONG ITEM_DS_JAM                  = 4;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG ITEM_SUE_OK                  = 11;
const LONG ITEM_SUE_EMPTY               = 12;
const LONG ITEM_SUE_NEAREMPTY           = 13;
const LONG ITEM_SUE_JAM                 = 14;


#endif                  // !defined(OPOSITEM_H)
