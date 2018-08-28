/////////////////////////////////////////////////////////////////////
//
// OposBdsp.h
//
//   Bill Dispenser header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2007-01-30 OPOS Release 1.11                                  CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSBDSP_H)
#define      OPOSBDSP_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "DeviceStatus" Property Constants
// "StatusUpdateEvent" Event Constants
/////////////////////////////////////////////////////////////////////

const LONG BDSP_STATUS_OK               = 0;    // DeviceStatus

const LONG BDSP_STATUS_EMPTY            = 11;   // DeviceStatus, StatusUpdateEvent
const LONG BDSP_STATUS_NEAREMPTY        = 12;   // DeviceStatus, StatusUpdateEvent
const LONG BDSP_STATUS_EMPTYOK          = 13;   // StatusUpdateEvent

const LONG BDSP_STATUS_JAM              = 31;   // DeviceStatus, StatusUpdateEvent
const LONG BDSP_STATUS_JAMOK            = 32;   // StatusUpdateEvent

const LONG BDSP_STATUS_ASYNC            = 91;   // StatusUpdateEvent


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EBDSP_OVERDISPENSE      = 201; // DispenseCash


#endif                  // !defined(OPOSBDSP_H)
