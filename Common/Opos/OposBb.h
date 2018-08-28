/////////////////////////////////////////////////////////////////////
//
// OposBb.h
//
//   Bump Bar header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1998-03-06 OPOS Release 1.3                                   BB
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSBB_H)
#define      OPOSBB_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CurrentUnitID" and "UnitsOnline" Properties
//   and "Units" Parameter Constants
/////////////////////////////////////////////////////////////////////

#define BB_UID(Unit) (1 << (Unit-1))

const LONG BB_UID_1             = 0x00000001;
const LONG BB_UID_2             = 0x00000002;
const LONG BB_UID_3             = 0x00000004;
const LONG BB_UID_4             = 0x00000008;
const LONG BB_UID_5             = 0x00000010;
const LONG BB_UID_6             = 0x00000020;
const LONG BB_UID_7             = 0x00000040;
const LONG BB_UID_8             = 0x00000080;
const LONG BB_UID_9             = 0x00000100;
const LONG BB_UID_10            = 0x00000200;
const LONG BB_UID_11            = 0x00000400;
const LONG BB_UID_12            = 0x00000800;
const LONG BB_UID_13            = 0x00001000;
const LONG BB_UID_14            = 0x00002000;
const LONG BB_UID_15            = 0x00004000;
const LONG BB_UID_16            = 0x00008000;
const LONG BB_UID_17            = 0x00010000;
const LONG BB_UID_18            = 0x00020000;
const LONG BB_UID_19            = 0x00040000;
const LONG BB_UID_20            = 0x00080000;
const LONG BB_UID_21            = 0x00100000;
const LONG BB_UID_22            = 0x00200000;
const LONG BB_UID_23            = 0x00400000;
const LONG BB_UID_24            = 0x00800000;
const LONG BB_UID_25            = 0x01000000;
const LONG BB_UID_26            = 0x02000000;
const LONG BB_UID_27            = 0x04000000;
const LONG BB_UID_28            = 0x08000000;
const LONG BB_UID_29            = 0x10000000;
const LONG BB_UID_30            = 0x20000000;
const LONG BB_UID_31            = 0x40000000;
const LONG BB_UID_32            = 0x80000000;


/////////////////////////////////////////////////////////////////////
// "DataEvent" Event: "Status" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG BB_DE_KEY            = 0x01;


#endif                  // !defined(OPOSBB_H)
