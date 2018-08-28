/////////////////////////////////////////////////////////////////////
//
// OposPpad.h
//
//   PIN Pad header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1998-03-06 OPOS Release 1.3                                   JDB
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSPPAD_H)
#define      OPOSPPAD_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapDisplay" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PPAD_DISP_UNRESTRICTED          = 1;
const LONG PPAD_DISP_PINRESTRICTED         = 2;
const LONG PPAD_DISP_RESTRICTED_LIST       = 3;
const LONG PPAD_DISP_RESTRICTED_ORDER      = 4;
const LONG PPAD_DISP_NONE                  = 5;


/////////////////////////////////////////////////////////////////////
// "AvailablePromptsList" and "Prompt" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PPAD_MSG_ENTERPIN               = 1;
const LONG PPAD_MSG_PLEASEWAIT             = 2;
const LONG PPAD_MSG_ENTERVALIDPIN          = 3;
const LONG PPAD_MSG_RETRIESEXCEEDED        = 4;
const LONG PPAD_MSG_APPROVED               = 5;
const LONG PPAD_MSG_DECLINED               = 6;
const LONG PPAD_MSG_CANCELED               = 7;
const LONG PPAD_MSG_AMOUNTOK               = 8;
const LONG PPAD_MSG_NOTREADY               = 9;
const LONG PPAD_MSG_IDLE                   = 10;
const LONG PPAD_MSG_SLIDE_CARD             = 11;
const LONG PPAD_MSG_INSERTCARD             = 12;
const LONG PPAD_MSG_SELECTCARDTYPE         = 13;


/////////////////////////////////////////////////////////////////////
// "CapLanguage" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PPAD_LANG_NONE                  = 1;
const LONG PPAD_LANG_ONE                   = 2;
const LONG PPAD_LANG_PINRESTRICTED         = 3;
const LONG PPAD_LANG_UNRESTRICTED          = 4;

/////////////////////////////////////////////////////////////////////
// "TransactionType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PPAD_TRANS_DEBIT                = 1;
const LONG PPAD_TRANS_CREDIT               = 2;
const LONG PPAD_TRANS_INQ                  = 3;
const LONG PPAD_TRANS_RECONCILE            = 4;
const LONG PPAD_TRANS_ADMIN                = 5;


/////////////////////////////////////////////////////////////////////
// "EndEFTTransaction" Method Completion Code Constants
/////////////////////////////////////////////////////////////////////

const LONG PPAD_EFT_NORMAL                 = 1;
const LONG PPAD_EFT_ABNORMAL               = 2;


/////////////////////////////////////////////////////////////////////
// "DataEvent" Event Status Constants
/////////////////////////////////////////////////////////////////////
const LONG PPAD_SUCCESS                    = 1;
const LONG PPAD_CANCEL                     = 2;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EPPAD_BAD_KEY              = 201;


#endif                  // !defined(OPOSPPAD_H)
