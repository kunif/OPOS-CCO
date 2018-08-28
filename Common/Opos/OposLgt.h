/////////////////////////////////////////////////////////////////////
//
// OposLights.h
//
//   Lights header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2008-08-30 OPOS Release 1.12                                  CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSLGT_H)
#define      OPOSLGT_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapAlarm" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG LGT_ALARM_NOALARM                    = 0x00000001;
const LONG LGT_ALARM_SLOW                       = 0x00000010;
const LONG LGT_ALARM_MEDIUM                     = 0x00000020;
const LONG LGT_ALARM_FAST                       = 0x00000040;
const LONG LGT_ALARM_CUSTOM1                    = 0x00010000;
const LONG LGT_ALARM_CUSTOM2                    = 0x00020000;


/////////////////////////////////////////////////////////////////////
// "CapColor" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG LGT_COLOR_PRIMARY                    = 0x00000001;
const LONG LGT_COLOR_CUSTOM1                    = 0x00010000;
const LONG LGT_COLOR_CUSTOM2                    = 0x00020000;
const LONG LGT_COLOR_CUSTOM3                    = 0x00040000;
const LONG LGT_COLOR_CUSTOM4                    = 0x00080000;
const LONG LGT_COLOR_CUSTOM5                    = 0x00100000;


#endif                  // !defined(OPOSLGT_H)
