/////////////////////////////////////////////////////////////////////
//
// OposChan.h
//
//   Cash Changer header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1997-06-04 OPOS Release 1.2                                   CRM
// 2000-09-24 OPOS Release 1.5                                OPOS-J
//   Add DepositStatus constants.
//   Add EndDeposit constants.
//   Add PauseDeposit constants.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSCHAN_H)
#define      OPOSCHAN_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "DeviceStatus" and "FullStatus" Property Constants
// "StatusUpdateEvent" Event Constants
/////////////////////////////////////////////////////////////////////

const LONG CHAN_STATUS_OK       =  0; // DeviceStatus, FullStatus

const LONG CHAN_STATUS_EMPTY    = 11; // DeviceStatus, StatusUpdateEvent
const LONG CHAN_STATUS_NEAREMPTY= 12; // DeviceStatus, StatusUpdateEvent
const LONG CHAN_STATUS_EMPTYOK  = 13; // StatusUpdateEvent

const LONG CHAN_STATUS_FULL     = 21; // FullStatus, StatusUpdateEvent
const LONG CHAN_STATUS_NEARFULL = 22; // FullStatus, StatusUpdateEvent
const LONG CHAN_STATUS_FULLOK   = 23; // StatusUpdateEvent

const LONG CHAN_STATUS_JAM      = 31; // DeviceStatus, StatusUpdateEvent
const LONG CHAN_STATUS_JAMOK    = 32; // StatusUpdateEvent

const LONG CHAN_STATUS_ASYNC    = 91; // StatusUpdateEvent


/////////////////////////////////////////////////////////////////////
// "DepositStatus" Property Constants (added in 1.5)
/////////////////////////////////////////////////////////////////////

const LONG CHAN_STATUS_DEPOSIT_START= 1;
const LONG CHAN_STATUS_DEPOSIT_END  = 2;
const LONG CHAN_STATUS_DEPOSIT_NONE = 3;
const LONG CHAN_STATUS_DEPOSIT_COUNT= 4;
const LONG CHAN_STATUS_DEPOSIT_JAM  = 5;


/////////////////////////////////////////////////////////////////////
// "EndDeposit" Method: "Success" Parameter Constants (added in 1.5)
/////////////////////////////////////////////////////////////////////

const LONG CHAN_DEPOSIT_CHANGE  = 1;
const LONG CHAN_DEPOSIT_NOCHANGE= 2;
const LONG CHAN_DEPOSIT_REPAY   = 3;


/////////////////////////////////////////////////////////////////////
// "PauseDeposit" Method: "Control" Parameter Constants (added in 1.5)
/////////////////////////////////////////////////////////////////////

const LONG CHAN_DEPOSIT_PAUSE   = 11;
const LONG CHAN_DEPOSIT_RESTART = 12;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_ECHAN_OVERDISPENSE = 201;


#endif                  // !defined(OPOSCHAN_H)
