/////////////////////////////////////////////////////////////////////
//
// OposLights.h
//
//   Lights header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2008-08-30 OPOS Release 1.12                                  CRM
// 2021-12-02 OPOS Release 1.16                                  KF
//   Added CapPattern, Pattern constants.
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


/////////////////////////////////////////////////////////////////////
// "CapPattern" Property Constants
// "SwitchOnPattern" Method: "Pattern" Paremeter Constants
/////////////////////////////////////////////////////////////////////

const LONG LGT_PATTERN_NOPATTERN                = 0x00000000;
const LONG LGT_PATTERN_CUSTOM1                  = 0x00000001;
const LONG LGT_PATTERN_CUSTOM2                  = 0x00000002;
const LONG LGT_PATTERN_CUSTOM3                  = 0x00000004;
const LONG LGT_PATTERN_CUSTOM4                  = 0x00000008;
const LONG LGT_PATTERN_CUSTOM5                  = 0x00000010;
const LONG LGT_PATTERN_CUSTOM6                  = 0x00000020;
const LONG LGT_PATTERN_CUSTOM7                  = 0x00000040;
const LONG LGT_PATTERN_CUSTOM8                  = 0x00000080;
const LONG LGT_PATTERN_CUSTOM9                  = 0x00000100;
const LONG LGT_PATTERN_CUSTOM10                 = 0x00000200;
const LONG LGT_PATTERN_CUSTOM11                 = 0x00000400;
const LONG LGT_PATTERN_CUSTOM12                 = 0x00000800;
const LONG LGT_PATTERN_CUSTOM13                 = 0x00001000;
const LONG LGT_PATTERN_CUSTOM14                 = 0x00002000;
const LONG LGT_PATTERN_CUSTOM15                 = 0x00004000;
const LONG LGT_PATTERN_CUSTOM16                 = 0x00008000;
const LONG LGT_PATTERN_CUSTOM17                 = 0x00010000;
const LONG LGT_PATTERN_CUSTOM18                 = 0x00020000;
const LONG LGT_PATTERN_CUSTOM19                 = 0x00040000;
const LONG LGT_PATTERN_CUSTOM20                 = 0x00080000;
const LONG LGT_PATTERN_CUSTOM21                 = 0x00100000;
const LONG LGT_PATTERN_CUSTOM22                 = 0x00200000;
const LONG LGT_PATTERN_CUSTOM23                 = 0x00400000;
const LONG LGT_PATTERN_CUSTOM24                 = 0x00800000;
const LONG LGT_PATTERN_CUSTOM25                 = 0x01000000;
const LONG LGT_PATTERN_CUSTOM26                 = 0x02000000;
const LONG LGT_PATTERN_CUSTOM27                 = 0x04000000;
const LONG LGT_PATTERN_CUSTOM28                 = 0x08000000;
const LONG LGT_PATTERN_CUSTOM29                 = 0x10000000;
const LONG LGT_PATTERN_CUSTOM30                 = 0x20000000;
const LONG LGT_PATTERN_CUSTOM31                 = 0x40000000;
const LONG LGT_PATTERN_CUSTOM32                 = 0x80000000;


#endif                  // !defined(OPOSLGT_H)
