/////////////////////////////////////////////////////////////////////
//
// OposMicr.h
//
//   MICR header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1995-12-08 OPOS Release 1.0                                   CRM
// 2002-08-17 OPOS Release 1.7                                   CRM
//   Add new ResultCodeExtended constants.
// 2009-10-02 OPOS Release 1.13                                  CRM
//   Add CountryCode constants.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSMICR_H)
#define      OPOSMICR_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CheckType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG MICR_CT_PERSONAL     =  1;
const LONG MICR_CT_BUSINESS     =  2;
const LONG MICR_CT_UNKNOWN      = 99;


/////////////////////////////////////////////////////////////////////
// "CountryCode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG MICR_CC_USA          =  1;
const LONG MICR_CC_CANADA       =  2;
const LONG MICR_CC_MEXICO       =  3;
const LONG MICR_CC_UNKNOWN      = 99;
const LONG MICR_CC_CMC7         =  4; // Added in 1.13
const LONG MICR_CC_OTHER        =  5; // Added in 1.13


//////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EMICR_NOCHECK       = 201; // EndInsertion
const LONG OPOS_EMICR_CHECK         = 202; // EndRemoval

// The following were added in 1.7
const LONG OPOS_EMICR_BADDATA       = 203;
const LONG OPOS_EMICR_NODATA        = 204;
const LONG OPOS_EMICR_BADSIZE       = 205;
const LONG OPOS_EMICR_JAM           = 206;
const LONG OPOS_EMICR_CHECKDIGIT    = 207;
const LONG OPOS_EMICR_COVEROPEN     = 208;

#endif                  // !defined(OPOSMICR_H)
