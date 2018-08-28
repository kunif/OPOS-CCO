/////////////////////////////////////////////////////////////////////
//
// OposPcrw.H
//
//   Point Card Reader Writer header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2000-09-24 OPOS Release 1.5                                   BKS
// 2004-10-26 Add "CharacterSet" ANSI constant (from 1.5).       CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSPCRW_H)
#define      OPOSPCRW_H


#include "opos.h"


/////////////////////////////////////////////////////////////////////
// "CapCharacterSet" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PCRW_CCS_ALPHA       = 1;
const LONG PCRW_CCS_ASCII       = 998;
const LONG PCRW_CCS_KANA        = 10;
const LONG PCRW_CCS_KANJI       = 11;
const LONG PCRW_CCS_UNICODE     = 997;


/////////////////////////////////////////////////////////////////////
// "CardState" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PCRW_STATE_NOCARD    = 1;
const LONG PCRW_STATE_REMAINING = 2;
const LONG PCRW_STATE_INRW      = 4;


/////////////////////////////////////////////////////////////////////
// CapTrackToRead and TrackToWrite Property constants
/////////////////////////////////////////////////////////////////////

const LONG PCRW_TRACK1          = 0x0001;
const LONG PCRW_TRACK2          = 0x0002;
const LONG PCRW_TRACK3          = 0x0004;
const LONG PCRW_TRACK4          = 0x0008;
const LONG PCRW_TRACK5          = 0x0010;
const LONG PCRW_TRACK6          = 0x0020;


/////////////////////////////////////////////////////////////////////
// "CharacterSet" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PCRW_CS_UNICODE      = 997;
const LONG PCRW_CS_ASCII        = 998;
const LONG PCRW_CS_WINDOWS      = 999;
const LONG PCRW_CS_ANSI         = 999;


/////////////////////////////////////////////////////////////////////
// "MappingMode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PCRW_MM_DOTS         = 1;
const LONG PCRW_MM_TWIPS        = 2;
const LONG PCRW_MM_ENGLISH      = 3;
const LONG PCRW_MM_METRIC       = 4;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EPCRW_READ      = 201;
const LONG OPOS_EPCRW_WRITE     = 202;
const LONG OPOS_EPCRW_JAM       = 203;
const LONG OPOS_EPCRW_MOTOR     = 204;
const LONG OPOS_EPCRW_COVER     = 205;
const LONG OPOS_EPCRW_PRINTER   = 206;
const LONG OPOS_EPCRW_RELEASE   = 207;
const LONG OPOS_EPCRW_DISPLAY   = 208;
const LONG OPOS_EPCRW_NOCARD    = 209;


/////////////////////////////////////////////////////////////////////
// Magnetic read/write status Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EPCRW_START     = 211;
const LONG OPOS_EPCRW_END       = 212;
const LONG OPOS_EPCRW_PARITY    = 213;
const LONG OPOS_EPCRW_ENCODE    = 214;
const LONG OPOS_EPCRW_LRC       = 215;
const LONG OPOS_EPCRW_VERIFY    = 216;


/////////////////////////////////////////////////////////////////////
// "RotatedPrint" Method: "Rotation" Parameter Constants
// "RotateSpecial" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PCRW_RP_NORMAL       = 0x0001;
const LONG PCRW_RP_RIGHT90      = 0x0101;
const LONG PCRW_RP_LEFT90       = 0x0102;
const LONG PCRW_RP_ROTATE180    = 0x0103;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" "Status" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG PCRW_SUE_NOCARD      = 1;
const LONG PCRW_SUE_REMAINING   = 2;
const LONG PCRW_SUE_INRW        = 4;


#endif                  // !defined(OPOSPCRW_H)
