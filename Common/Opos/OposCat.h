/////////////////////////////////////////////////////////////////////
//
// OposCAT.h
//
//   CAT header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1998-06-01 OPOS Release 1.4                                OPOS-J
// 2000-09-24 OPOS Release 1.5                                   BKS
//   Added the following constants:
//     CAT_PAYMENT_DEBIT, CAT_MEDIA_...
// 2005-04-29 OPOS Release 1.9                                   CRM
//   Added constants to PaymentCondition, PaymentMedia,
//     TransactionType, and ResultCodeExtended.
//   Added LogStatus constants.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSCAT_H)
#define      OPOSCAT_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapDailyLog" Property and "AccessDailyLog" Type Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG CAT_DL_NONE                      = 0;
const LONG CAT_DL_REPORTING                 = 1;
const LONG CAT_DL_SETTLEMENT                = 2;
const LONG CAT_DL_REPORTING_SETTLEMENT      = 3;


/////////////////////////////////////////////////////////////////////
// "LogStatus" Property Constants (added in 1.9)
/////////////////////////////////////////////////////////////////////

const LONG CAT_LOGSTATUS_OK                 = 1;
const LONG CAT_LOGSTATUS_NEARFULL           = 2;
const LONG CAT_LOGSTATUS_FULL               = 3;


/////////////////////////////////////////////////////////////////////
// "PaymentCondition" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG CAT_PAYMENT_LUMP                 =  10;
const LONG CAT_PAYMENT_BONUS_1              =  21;
const LONG CAT_PAYMENT_BONUS_2              =  22;
const LONG CAT_PAYMENT_BONUS_3              =  23;
const LONG CAT_PAYMENT_BONUS_4              =  24;
const LONG CAT_PAYMENT_BONUS_5              =  25;
const LONG CAT_PAYMENT_INSTALLMENT_1        =  61;
const LONG CAT_PAYMENT_INSTALLMENT_2        =  62;
const LONG CAT_PAYMENT_INSTALLMENT_3        =  63;
const LONG CAT_PAYMENT_BONUS_COMBINATION_1  =  31;
const LONG CAT_PAYMENT_BONUS_COMBINATION_2  =  32;
const LONG CAT_PAYMENT_BONUS_COMBINATION_3  =  33;
const LONG CAT_PAYMENT_BONUS_COMBINATION_4  =  34;
const LONG CAT_PAYMENT_REVOLVING            =  80;
const LONG CAT_PAYMENT_DEBIT                = 110; // (added in 1.5)
const LONG CAT_PAYMENT_ELECTRONIC_MONEY     = 111; // (added in 1.9)


/////////////////////////////////////////////////////////////////////
// "PaymentMedia" Property Constants (added in 1.5)
/////////////////////////////////////////////////////////////////////

const LONG CAT_MEDIA_UNSPECIFIED            = 0;
const LONG CAT_MEDIA_NONDEFINE              = 0; // (deprecated)
const LONG CAT_MEDIA_CREDIT                 = 1;
const LONG CAT_MEDIA_DEBIT                  = 2;
const LONG CAT_MEDIA_ELECTRONIC_MONEY       = 3; // (added in 1.9)


/////////////////////////////////////////////////////////////////////
// "TransactionType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG CAT_TRANSACTION_SALES            = 10;
const LONG CAT_TRANSACTION_VOID             = 20;
const LONG CAT_TRANSACTION_REFUND           = 21;
const LONG CAT_TRANSACTION_VOIDPRESALES     = 29;
const LONG CAT_TRANSACTION_COMPLETION       = 30;
const LONG CAT_TRANSACTION_PRESALES         = 40;
const LONG CAT_TRANSACTION_CHECKCARD        = 41; // (deprecated?)
const LONG CAT_TRANSACTION_CASHDEPOSIT      = 50; // (added in 1.9)


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_ECAT_CENTERERROR            =  01;
const LONG OPOS_ECAT_COMMANDERROR           =  90;
const LONG OPOS_ECAT_RESET                  =  91;
const LONG OPOS_ECAT_COMMUNICATIONERROR     =  92;
const LONG OPOS_ECAT_DAILYLOGOVERFLOW       = 200;
const LONG OPOS_ECAT_DEFICIENT              = 201; // (added in 1.9)
const LONG OPOS_ECAT_OVERDEPOSIT            = 202; // (added in 1.9)

#endif                  // !defined(OPOSCAT_H)
