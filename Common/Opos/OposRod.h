/////////////////////////////////////////////////////////////////////
//
// OposRod.h
//
//   Remote Order Display header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1998-03-06 OPOS Release 1.3                                   BB
// 2000-09-24 OPOS Release 1.5                                   BKS
//   Added CharacterSet constant for UNICODE.
// 2004-10-26 Add "CharacterSet" ANSI constant (from 1.5).       CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSROD_H)
#define      OPOSROD_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CurrentUnitID" and "UnitsOnline" Properties
//   and "Units" Parameter Constants
/////////////////////////////////////////////////////////////////////

#define ROD_UID(Unit) (1 << (Unit-1))

const LONG ROD_UID_1        = 0x00000001;
const LONG ROD_UID_2        = 0x00000002;
const LONG ROD_UID_3        = 0x00000004;
const LONG ROD_UID_4        = 0x00000008;
const LONG ROD_UID_5        = 0x00000010;
const LONG ROD_UID_6        = 0x00000020;
const LONG ROD_UID_7        = 0x00000040;
const LONG ROD_UID_8        = 0x00000080;
const LONG ROD_UID_9        = 0x00000100;
const LONG ROD_UID_10       = 0x00000200;
const LONG ROD_UID_11       = 0x00000400;
const LONG ROD_UID_12       = 0x00000800;
const LONG ROD_UID_13       = 0x00001000;
const LONG ROD_UID_14       = 0x00002000;
const LONG ROD_UID_15       = 0x00004000;
const LONG ROD_UID_16       = 0x00008000;
const LONG ROD_UID_17       = 0x00010000;
const LONG ROD_UID_18       = 0x00020000;
const LONG ROD_UID_19       = 0x00040000;
const LONG ROD_UID_20       = 0x00080000;
const LONG ROD_UID_21       = 0x00100000;
const LONG ROD_UID_22       = 0x00200000;
const LONG ROD_UID_23       = 0x00400000;
const LONG ROD_UID_24       = 0x00800000;
const LONG ROD_UID_25       = 0x01000000;
const LONG ROD_UID_26       = 0x02000000;
const LONG ROD_UID_27       = 0x04000000;
const LONG ROD_UID_28       = 0x08000000;
const LONG ROD_UID_29       = 0x10000000;
const LONG ROD_UID_30       = 0x20000000;
const LONG ROD_UID_31       = 0x40000000;
const LONG ROD_UID_32       = 0x80000000;


/////////////////////////////////////////////////////////////////////
// Broadcast Methods: "Attribute" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG ROD_ATTR_BLINK       = 0x80;

const LONG ROD_ATTR_BG_BLACK    = 0x00;
const LONG ROD_ATTR_BG_BLUE     = 0x10;
const LONG ROD_ATTR_BG_GREEN    = 0x20;
const LONG ROD_ATTR_BG_CYAN     = 0x30;
const LONG ROD_ATTR_BG_RED      = 0x40;
const LONG ROD_ATTR_BG_MAGENTA  = 0x50;
const LONG ROD_ATTR_BG_BROWN    = 0x60;
const LONG ROD_ATTR_BG_GRAY     = 0x70;

const LONG ROD_ATTR_INTENSITY   = 0x08;

const LONG ROD_ATTR_FG_BLACK    = 0x00;
const LONG ROD_ATTR_FG_BLUE     = 0x01;
const LONG ROD_ATTR_FG_GREEN    = 0x02;
const LONG ROD_ATTR_FG_CYAN     = 0x03;
const LONG ROD_ATTR_FG_RED      = 0x04;
const LONG ROD_ATTR_FG_MAGENTA  = 0x05;
const LONG ROD_ATTR_FG_BROWN    = 0x06;
const LONG ROD_ATTR_FG_GRAY     = 0x07;


/////////////////////////////////////////////////////////////////////
// "DrawBox" Method: "BorderType" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG ROD_BDR_SINGLE       = 1;
const LONG ROD_BDR_DOUBLE       = 2;
const LONG ROD_BDR_SOLID        = 3;


/////////////////////////////////////////////////////////////////////
// "ControlClock" Method: "Function" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG ROD_CLK_START        = 1;
const LONG ROD_CLK_PAUSE        = 2;
const LONG ROD_CLK_RESUME       = 3;
const LONG ROD_CLK_MOVE         = 4;
const LONG ROD_CLK_STOP         = 5;


/////////////////////////////////////////////////////////////////////
// "ControlCursor" Method: "Function" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG ROD_CRS_LINE         = 1;
const LONG ROD_CRS_LINE_BLINK   = 2;
const LONG ROD_CRS_BLOCK        = 3;
const LONG ROD_CRS_BLOCK_BLINK  = 4;
const LONG ROD_CRS_OFF          = 5;


/////////////////////////////////////////////////////////////////////
// "SelectCharacterSet" Method: "CharacterSet" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG ROD_CS_UNICODE       = 997; // (added in 1.5)
const LONG ROD_CS_ASCII         = 998;
const LONG ROD_CS_WINDOWS       = 999;
const LONG ROD_CS_ANSI          = 999; // (added in 1.5)


/////////////////////////////////////////////////////////////////////
// "TransactionDisplay" Method: "Function" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG ROD_TD_TRANSACTION   = 11;
const LONG ROD_TD_NORMAL        = 12;


/////////////////////////////////////////////////////////////////////
// "UpdateVideoRegionAttribute" Method: "Function" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG ROD_UA_SET           = 1;
const LONG ROD_UA_INTENSITY_ON  = 2;
const LONG ROD_UA_INTENSITY_OFF = 3;
const LONG ROD_UA_REVERSE_ON    = 4;
const LONG ROD_UA_REVERSE_OFF   = 5;
const LONG ROD_UA_BLINK_ON      = 6;
const LONG ROD_UA_BLINK_OFF     = 7;


/////////////////////////////////////////////////////////////////////
// "EventTypes" Property and "DataEvent" Event: "Status" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG ROD_DE_TOUCH_UP      = 0x01;
const LONG ROD_DE_TOUCH_DOWN    = 0x02;
const LONG ROD_DE_TOUCH_MOVE    = 0x04;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants for Remote Order Display
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EROD_BADCLK     = 201; // ControlClock
const LONG OPOS_EROD_NOCLOCKS   = 202; // ControlClock
const LONG OPOS_EROD_NOREGION   = 203; // RestoreVideo Region
const LONG OPOS_EROD_NOBUFFERS  = 204; // SaveVideoRegion
const LONG OPOS_EROD_NOROOM     = 205; // SaveVideoRegion


#endif                  // !defined(OPOSROD_H)
