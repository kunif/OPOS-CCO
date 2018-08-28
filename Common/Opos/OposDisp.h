/////////////////////////////////////////////////////////////////////
//
// OposDisp.h
//
//   Line Display header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1995-12-08 OPOS Release 1.0                                   CRM
// 1996-03-18 OPOS Release 1.01                                  CRM
//   Add DISP_MT_INIT constant and MarqueeFormat constants.
// 1996-04-22 OPOS Release 1.1                                   CRM
//   Add CapCharacterSet constants for Kana and Kanji.
// 2000-09-24 OPOS Release 1.5                                   BKS
//   Add CapCharacterSet and CharacterSet constants for Unicode
// 2001-07-15 OPOS Release 1.6                                   BKS
//   Add CapCursorType, CapReadBack, CapReverse, CursorType
//     property constants.
//   Add DefineGlyph, DisplayText and DisplayTextAt parameter
//     constants.
// 2002-08-17 OPOS Release 1.7                                   CRM
//   Add DisplayBitmap and SetBitmap parameter constants.
// 2004-03-22 OPOS Release 1.8                                   CRM
//   Add more constants for CapCursorType and CursorType.
// 2004-10-26 Add "CharacterSet" ANSI constant (from 1.5).       CRM
//   Add ResultCodeExtended constants (from 1.7).
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSDISP_H)
#define      OPOSDISP_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapBlink" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG DISP_CB_NOBLINK      = 0;
const LONG DISP_CB_BLINKALL     = 1;
const LONG DISP_CB_BLINKEACH    = 2;


/////////////////////////////////////////////////////////////////////
// "CapCharacterSet" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG DISP_CCS_NUMERIC     =   0;
const LONG DISP_CCS_ALPHA       =   1;
const LONG DISP_CCS_ASCII       = 998;
const LONG DISP_CCS_KANA        =  10; // (added in 1.1)
const LONG DISP_CCS_KANJI       =  11; // (added in 1.1)
const LONG DISP_CCS_UNICODE     = 997; // (added in 1.5)


/////////////////////////////////////////////////////////////////////
// "CapCursorType" Property Constants (added in 1.6)
/////////////////////////////////////////////////////////////////////

const LONG DISP_CCT_NONE        =   0x00000000;
const LONG DISP_CCT_FIXED       =   0x00000001;
const LONG DISP_CCT_BLOCK       =   0x00000002;
const LONG DISP_CCT_HALFBLOCK   =   0x00000004;
const LONG DISP_CCT_UNDERLINE   =   0x00000008;
const LONG DISP_CCT_REVERSE     =   0x00000010;
const LONG DISP_CCT_OTHER       =   0x00000020;
const LONG DISP_CCT_BLINK       =   0x00000040;  // (added in 1.8)


/////////////////////////////////////////////////////////////////////
// "CapReadBack" Property Constants (added in 1.6)
/////////////////////////////////////////////////////////////////////

const LONG DISP_CRB_NONE        =   0x00000000;
const LONG DISP_CRB_SINGLE      =   0x00000001;


/////////////////////////////////////////////////////////////////////
// "CapReverse" Property Constants (added in 1.6)
/////////////////////////////////////////////////////////////////////

const LONG DISP_CR_NONE         =   0x00000000;
const LONG DISP_CR_REVERSEALL   =   0x00000001;
const LONG DISP_CR_REVERSEEACH  =   0x00000002;


/////////////////////////////////////////////////////////////////////
// "CharacterSet" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG DISP_CS_UNICODE      = 997; // (added in 1.5)
const LONG DISP_CS_ASCII        = 998;
const LONG DISP_CS_WINDOWS      = 999;
const LONG DISP_CS_ANSI         = 999; // (added in 1.5)


/////////////////////////////////////////////////////////////////////
// "CursorType" Property Constants (added in 1.6)
/////////////////////////////////////////////////////////////////////

const LONG DISP_CT_NONE         =   0;
const LONG DISP_CT_FIXED        =   1;
const LONG DISP_CT_BLOCK        =   2;
const LONG DISP_CT_HALFBLOCK    =   3;
const LONG DISP_CT_UNDERLINE    =   4;
const LONG DISP_CT_REVERSE      =   5;
const LONG DISP_CT_OTHER        =   6;
const LONG DISP_CT_BLINK        =   0x10000000;  // (added in 1.8)


/////////////////////////////////////////////////////////////////////
// "MarqueeType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG DISP_MT_NONE         = 0;
const LONG DISP_MT_UP           = 1;
const LONG DISP_MT_DOWN         = 2;
const LONG DISP_MT_LEFT         = 3;
const LONG DISP_MT_RIGHT        = 4;
const LONG DISP_MT_INIT         = 5; // (added in 1.01)


/////////////////////////////////////////////////////////////////////
// "MarqueeFormat" Property Constants (added in 1.01)
/////////////////////////////////////////////////////////////////////

const LONG DISP_MF_WALK         = 0;
const LONG DISP_MF_PLACE        = 1;


/////////////////////////////////////////////////////////////////////
// "DefineGlyph" Method: "GlyphType" Parameter Constants (added in 1.6)
/////////////////////////////////////////////////////////////////////

const LONG DISP_GT_SINGLE       = 1;


/////////////////////////////////////////////////////////////////////
// "DisplayText" Method: "Attribute" Property Constants (added in 1.6)
// "DisplayTextAt" Method: "Attribute" Property Constants (added in 1.6)
/////////////////////////////////////////////////////////////////////

const LONG DISP_DT_NORMAL        = 0;
const LONG DISP_DT_BLINK         = 1;
const LONG DISP_DT_REVERSE       = 2;
const LONG DISP_DT_BLINK_REVERSE = 3;


/////////////////////////////////////////////////////////////////////
// "ScrollText" Method: "Direction" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG DISP_ST_UP           = 1;
const LONG DISP_ST_DOWN         = 2;
const LONG DISP_ST_LEFT         = 3;
const LONG DISP_ST_RIGHT        = 4;


/////////////////////////////////////////////////////////////////////
// "SetDescriptor" Method: "Attribute" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG DISP_SD_OFF          = 0;
const LONG DISP_SD_ON           = 1;
const LONG DISP_SD_BLINK        = 2;


/////////////////////////////////////////////////////////////////////
// "DisplayBitmap" and "SetBitmap" Method Constants (added in 1.7)
/////////////////////////////////////////////////////////////////////

//   "Width" Parameter

const LONG DISP_BM_ASIS         = -11;

//   "AlignmentX" Parameter

const LONG DISP_BM_LEFT         = -1;
const LONG DISP_BM_CENTER       = -2;
const LONG DISP_BM_RIGHT        = -3;

//   "AlignmentY" Parameter

const LONG DISP_BM_TOP          = -1;
//const LONG DISP_BM_CENTER     = -2;
const LONG DISP_BM_BOTTOM       = -3;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EDISP_TOOBIG    = 201; // DisplayBitmap (added in 1.7)
const LONG OPOS_EDISP_BADFORMAT = 202; // DisplayBitmap (added in 1.7)


#endif                  // !defined(OPOSDISP_H)
