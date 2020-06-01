/////////////////////////////////////////////////////////////////////
//
// OposEvrw.h
//
//   Electronic Value Reader Writer header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2008-08-30 OPOS Release 1.12                                  CRM
// 2013-10-03 OPOS Release 1.14                                  CRM
//   Added PINEntry constants.
//   Added TrainingModeState constants.
//   Added RetrieveResultInformation's Value constants.
//   Added TransitionEvent's EventNumber constants.
// 2015-02-07 OPOS Release 1.14.1                                CRM
//   Added ServiceType constants.
//   Added AccessData's DataType constants.
//   Additional RetrieveResultInformation's Value constants.
//   Additional TransitionEvent's EventNumber constants.
// 2020-06-01 OPOS Release 1.15                                  KF
//   Added CapDailyLog and AccessDailyLog constants.
//   Added PaymentCondition constants.
//   Added PaymentMedia constants.
//   Added TransactionType constants.
//   Additional RetrieveResultInformation's Value constants.
//   Additional ServiceType's Value constants.
//   Additional TransitionEvent's EventNumber constants.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSEVRW_H)
#define      OPOSEVRW_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapCardSensor" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG EVRW_CCS_ENTRY               = 0x00000001;
const LONG EVRW_CCS_DETECT              = 0x00000002;
const LONG EVRW_CCS_CAPTURE             = 0x00000004;


/////////////////////////////////////////////////////////////////////
// "CapDetectionControl" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG EVRW_CDC_RWCONTROL           = 0x00000001;
const LONG EVRW_CDC_APPLICATIONCONTROL  = 0x00000002;


/////////////////////////////////////////////////////////////////////
// "DetectionStatus" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG EVRW_DS_NOCARD               = 1;
const LONG EVRW_DS_DETECTED             = 2;
const LONG EVRW_DS_ENTERED              = 3;
const LONG EVRW_DS_CAPTURED             = 4;


/////////////////////////////////////////////////////////////////////
// "CapDailyLog" Property and "AccessDailyLog" Type Parameter Constants
// (added in 1.15)
/////////////////////////////////////////////////////////////////////

const LONG EVRW_DL_NONE                 = 0;
const LONG EVRW_DL_REPORTING            = 1;
const LONG EVRW_DL_SETTLEMENT           = 2;
const LONG EVRW_DL_REPORTING_SETTLEMENT = 3;


/////////////////////////////////////////////////////////////////////
// "LogStatus" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG EVRW_LS_OK                   = 1;
const LONG EVRW_LS_NEARFULL             = 2;
const LONG EVRW_LS_FULL                 = 3;


/////////////////////////////////////////////////////////////////////
// "PaymentCondition" Property Constants (added in 1.15)
/////////////////////////////////////////////////////////////////////

const LONG EVRW_PAYMENT_LUMP                =  10;
const LONG EVRW_PAYMENT_BONUS_1             =  21;
const LONG EVRW_PAYMENT_BONUS_2             =  22;
const LONG EVRW_PAYMENT_BONUS_3             =  23;
const LONG EVRW_PAYMENT_BONUS_4             =  24;
const LONG EVRW_PAYMENT_BONUS_5             =  25;
const LONG EVRW_PAYMENT_INSTALLMENT_1       =  61;
const LONG EVRW_PAYMENT_INSTALLMENT_2       =  62;
const LONG EVRW_PAYMENT_INSTALLMENT_3       =  63;
const LONG EVRW_PAYMENT_BONUS_COMBINATION_1 =  31;
const LONG EVRW_PAYMENT_BONUS_COMBINATION_2 =  32;
const LONG EVRW_PAYMENT_BONUS_COMBINATION_3 =  33;
const LONG EVRW_PAYMENT_BONUS_COMBINATION_4 =  34;
const LONG EVRW_PAYMENT_REVOLVING           =  80;
const LONG EVRW_PAYMENT_DEBIT               = 110;
const LONG EVRW_PAYMENT_ELECTRONIC_MONEY    = 111;


/////////////////////////////////////////////////////////////////////
// "PaymentMedia" Property Constants (added in 1.15)
/////////////////////////////////////////////////////////////////////

const LONG EVRW_MEDIA_UNSPECIFIED           = 0;
const LONG EVRW_MEDIA_CREDIT                = 1;
const LONG EVRW_MEDIA_DEBIT                 = 2;
const LONG EVRW_MEDIA_ELECTRONIC_MONEY      = 3;


/////////////////////////////////////////////////////////////////////
// "TransactionType" Property Constants (added in 1.15)
/////////////////////////////////////////////////////////////////////

const LONG EVRW_TRANSACTION_SALES           = 10;
const LONG EVRW_TRANSACTION_VOID            = 20;
const LONG EVRW_TRANSACTION_REFUND          = 21;
const LONG EVRW_TRANSACTION_VOIDPRESALES    = 29;
const LONG EVRW_TRANSACTION_COMPLETION      = 30;
const LONG EVRW_TRANSACTION_PRESALES        = 40;
const LONG EVRW_TRANSACTION_CHECKCARD       = 41;
const LONG EVRW_TRANSACTION_CASHDEPOSIT     = 50;


/////////////////////////////////////////////////////////////////////
// "PINEntry" Property Constants (added in 1.14)
/////////////////////////////////////////////////////////////////////

const LONG EVRW_PIN_ENTRY_NONE          = 1;
const LONG EVRW_PIN_ENTRY_EXTERNAL      = 2;
const LONG EVRW_PIN_ENTRY_INTERNAL      = 3;
const LONG EVRW_PIN_ENTRY_UNKNOWN       = 4;


/////////////////////////////////////////////////////////////////////
// "ServiceType" Property Constants (added in 1.14.1)
/////////////////////////////////////////////////////////////////////

const LONG EVRW_ST_UNSPECIFIED          = 0;
const LONG EVRW_ST_ELECTRONIC_MONEY     = 1;
const LONG EVRW_ST_POINT                = 2;
const LONG EVRW_ST_VOUCHER              = 3;
const LONG EVRW_ST_MEMBERSHIP           = 4;
const LONG EVRW_ST_CAT                  = 5; // (added in 1.15 Issue)

/////////////////////////////////////////////////////////////////////
// "TrainingModeState" Property Constants (added in 1.14)
/////////////////////////////////////////////////////////////////////

const LONG EVRW_TM_FALSE                = 1;
const LONG EVRW_TM_TRUE                 = 2;
const LONG EVRW_TM_UNKNOWN              = 3;


/////////////////////////////////////////////////////////////////////
// "AccessData" Method: "DataType" Parameter Constants
//    (added in 1.14.1)
/////////////////////////////////////////////////////////////////////

const LONG EVRW_AD_KEY                  = 1;
const LONG EVRW_AD_NEGATIVE_LIST        = 2;
const LONG EVRW_AD_OTHERS               = 3;


/////////////////////////////////////////////////////////////////////
// "AccessLog" Method: "Type" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG EVRW_AL_REPORTING            = 1;
const LONG EVRW_AL_SETTLEMENT           = 2;


/////////////////////////////////////////////////////////////////////
// "BeginDetection" Method: "Type" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG EVRW_BD_ANY                  = 1;
const LONG EVRW_BD_SPECIFIC             = 2;


/////////////////////////////////////////////////////////////////////
// "RetrieveResultInformation" Method: "Value" Parameter Constants
//   (added in 1.14)
/////////////////////////////////////////////////////////////////////

const LONG EVRW_TAG_AS_AUTHENTICATED    = 1;
const LONG EVRW_TAG_AS_UNAUTHENTICATED  = 2;

const LONG EVRW_TAG_CTT_CANCEL          = 1;
const LONG EVRW_TAG_CTT_CHARGE          = 2;
const LONG EVRW_TAG_CTT_RETURN          = 3;
const LONG EVRW_TAG_CTT_SALES           = 4;

const LONG EVRW_TAG_CM_CASH             = 1;
const LONG EVRW_TAG_CM_CREDIT           = 2;
const LONG EVRW_TAG_CM_POINT            = 3;

const LONG EVRW_TAG_NIT_ALL             = 1; // (added in 1.14)
const LONG EVRW_TAG_NIT_UPDATED         = 2; // (added in 1.14)

const LONG EVRW_TAG_PC_INSTALLMENT_1       =  1;
const LONG EVRW_TAG_PC_INSTALLMENT_2       =  2;
const LONG EVRW_TAG_PC_INSTALLMENT_3       =  3;
const LONG EVRW_TAG_PC_BONUS_1             =  4;
const LONG EVRW_TAG_PC_BONUS_2             =  5;
const LONG EVRW_TAG_PC_BONUS_3             =  6;
const LONG EVRW_TAG_PC_BONUS_4             =  7;
const LONG EVRW_TAG_PC_BONUS_5             =  8;
const LONG EVRW_TAG_PC_BONUS_COMBINATION_1 =  9;
const LONG EVRW_TAG_PC_BONUS_COMBINATION_2 = 10;
const LONG EVRW_TAG_PC_BONUS_COMBINATION_3 = 11;
const LONG EVRW_TAG_PC_BONUS_COMBINATION_4 = 12;
const LONG EVRW_TAG_PC_LUMP                = 13;
const LONG EVRW_TAG_PC_REVOLVING           = 14;

const LONG EVRW_TAG_PM_COMBINED         = 1;
const LONG EVRW_TAG_PM_FULL_SETTLEMENT  = 2;

const LONG EVRW_TAG_PMFP_CASH           = 1;
const LONG EVRW_TAG_PMFP_CREDIT         = 2;
const LONG EVRW_TAG_PMFP_EM             = 3;
const LONG EVRW_TAG_PMFP_OTHER          = 4;

const LONG EVRW_TAG_ROS_NG              = 1;
const LONG EVRW_TAG_ROS_OK              = 2;
const LONG EVRW_TAG_ROS_UNKNOWN         = 3;

const LONG EVRW_TAG_STT_1               = 1;
const LONG EVRW_TAG_STT_2               = 2;
const LONG EVRW_TAG_STT_3               = 3;

const LONG EVRW_TAG_TT_ADD              = 1;
const LONG EVRW_TAG_TT_CANCEL_CHARGE    = 2;
const LONG EVRW_TAG_TT_CANCEL_RETURN    = 3;
const LONG EVRW_TAG_TT_CANCEL_SALES     = 4;
const LONG EVRW_TAG_TT_GET_LOG          = 5;
const LONG EVRW_TAG_TT_READ             = 6;
const LONG EVRW_TAG_TT_RETURN           = 7;
const LONG EVRW_TAG_TT_SUBTRACT         = 8;
const LONG EVRW_TAG_TT_WRITE            = 9;
const LONG EVRW_TAG_TT_COMPLETION       = 10; // (added in 1.15)
const LONG EVRW_TAG_TT_PRE_SALES        = 11; // (added in 1.15)


/////////////////////////////////////////////////////////////////////
// "TransactionAccess" Method: "Control" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG EVRW_TA_TRANSACTION          = 11;
const LONG EVRW_TA_NORMAL               = 12;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG EVRW_SUE_LS_OK               = 11;
const LONG EVRW_SUE_LS_NEARFULL         = 12;
const LONG EVRW_SUE_LS_FULL             = 13;
const LONG EVRW_SUE_DS_NOCARD           = 21;
const LONG EVRW_SUE_DS_DETECTED         = 22;
const LONG EVRW_SUE_DS_ENTERED          = 23;
const LONG EVRW_SUE_DS_CAPTURED         = 24;


/////////////////////////////////////////////////////////////////////
// "TransitionEvent" Event: "EventNumber" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG EVRW_TE_NOTIFY_TOUCH_RETRY                =  1;
const LONG EVRW_TE_NOTIFY_TOUCH_RETRY_CANCELABLE     =  2;
const LONG EVRW_TE_CONFIRM_TOUCH_RETRY               =  3;
const LONG EVRW_TE_CONFIRM_CANCEL                    =  4;
const LONG EVRW_TE_NOTIFY_INVALID_OPERATION          =  5;
const LONG EVRW_TE_CONFIRM_INVALID_OPERATION         =  6;
const LONG EVRW_TE_CONFIRM_REMAINDER_SUBTRACTION     =  7;
const LONG EVRW_TE_CONFIRM_CENTER_CHECK              =  8;
const LONG EVRW_TE_CONFIRM_TOUCH_TIMEOUT             =  9;
const LONG EVRW_TE_CONFIRM_AUTO_CHARGE               = 10;
const LONG EVRW_TE_NOTIFY_CAPTURE_CARD               = 11;
const LONG EVRW_TE_NOTIFY_PIN                        = 12;
const LONG EVRW_TE_NOTIFY_CENTER_CHECK               = 13;
const LONG EVRW_TE_NOTIFY_COMPLETE                   = 14;
const LONG EVRW_TE_NOTIFY_TOUCH                      = 15;
const LONG EVRW_TE_NOTIFY_BUSY                       = 16;
const LONG EVRW_TE_CONFIRM_CENTER_CHECK_COMPLETE     = 17;
const LONG EVRW_TE_CONFIRM_SELECT                    = 18;
const LONG EVRW_TE_NOTIFY_LOCK                       = 19;
const LONG EVRW_TE_NOTIFY_CENTER_CHECK_COMPLETE      = 20;
const LONG EVRW_TE_CONFIRM_PIN_ENTRY_BY_OUTER_PINPAD = 21;
const LONG EVRW_TE_NOTIFY_PROGRESS_1_TO_100          = 22; // (added in 1.14.1)
const LONG EVRW_TE_CONFIRM_DEVICE_DATA               = 23; // (added in 1.14.1)
const LONG EVRW_TE_CONFIRM_SEARCH_TABLE              = 24; // (added in 1.15)
const LONG EVRW_TE_CONFIRM_PAYMENT_CONDITION         = 25; // (added in 1.15)
const LONG EVRW_TE_CONFIRM_AUTHORIZE                 = 26; // (added in 1.15)
const LONG EVRW_TE_NOTIFY_CHECK_CARD                 = 27; // (added in 1.15)
const LONG EVRW_TE_NOTIFY_SELECT_PAYMENT_CONDITION   = 28; // (added in 1.15)


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EVRW_NOCARD             = 201;
const LONG OPOS_EVRW_RELEASE            = 202;
const LONG OPOS_EVRW_CENTERERROR        = 203;
const LONG OPOS_EVRW_COMMANDERROR       = 204;
const LONG OPOS_EVRW_RESET              = 205;
const LONG OPOS_EVRW_COMMUNICATIONERROR = 206;
const LONG OPOS_EVRW_LOGOVERFLOW        = 207;
const LONG OPOS_EVRW_DAILYLOGOVERFLOW   = 208;
const LONG OPOS_EVRW_DEFICIENT          = 209;
const LONG OPOS_EVRW_OVERDEPOSIT        = 210;


#endif                  // !defined(OPOSEVRW_H)
