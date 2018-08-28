/////////////////////////////////////////////////////////////////////
//
// OposBelt.h
//
//   Belt Drawer file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2008-08-30 OPOS Release 1.12                                  CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSBELT_H)
#define      OPOSBELT_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "MotionStatus" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG BELT_MT_FORWARD              = 1;
const LONG BELT_MT_BACKWARD             = 2;
const LONG BELT_MT_STOPPED              = 3;
const LONG BELT_MT_EMERGENCY            = 4;
const LONG BELT_MT_MOTOR_FAULT          = 5;


/////////////////////////////////////////////////////////////////////
// "AdjustItemCount" Method: "Direction" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG BELT_AIC_BACKWARD            = 1;
const LONG BELT_AIC_FORWARD             = 2;


/////////////////////////////////////////////////////////////////////
// "ResetItemCount" Method: "Direction" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG BELT_RIC_BACKWARD            = 1;
const LONG BELT_RIC_FORWARD             = 2;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG BELT_SUE_AUTO_STOP                           = 11;
const LONG BELT_SUE_EMERGENCY_STOP                      = 12;
const LONG BELT_SUE_SAFETY_STOP                         = 13;
const LONG BELT_SUE_TIMEOUT_STOP                        = 14;
const LONG BELT_SUE_MOTOR_OVERHEATING                   = 15;
const LONG BELT_SUE_MOTOR_FUSE_DEFECT                   = 16;
const LONG BELT_SUE_LIGHT_BARRIER_BACKWARD_INTERRUPTED  = 17;
const LONG BELT_SUE_LIGHT_BARRIER_BACKWARD_OK           = 18;
const LONG BELT_SUE_LIGHT_BARRIER_FORWARD_INTERRUPTED   = 19;
const LONG BELT_SUE_LIGHT_BARRIER_FORWARD_OK            = 20;
const LONG BELT_SUE_SECURITY_FLAP_BACKWARD_OPENED       = 21;
const LONG BELT_SUE_SECURITY_FLAP_BACKWARD_CLOSED       = 22;
const LONG BELT_SUE_SECURITY_FLAP_FORWARD_OPENED        = 23;
const LONG BELT_SUE_SECURITY_FLAP_FORWARD_CLOSED        = 24;


#endif                  // !defined(OPOSBELT_H)
