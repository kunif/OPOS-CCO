//*************************************************************************
//** OPOS CAT Internals
//
//   CAT header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS CAT Internals")]
enum
{
    PIDXCat_AsyncMode            = 19001,
    PIDXCat_TrainingMode         = 19002,
    PIDXCat_TransactionType      = 19003,
    PIDXCat_PaymentMedia         = 19004,
    PIDXCat_LogStatus            = 19005,

    PIDXCat_CapAdditionalSecurityInformation = 19501,
    PIDXCat_CapAuthorizeCompletion           = 19502,
    PIDXCat_CapAuthorizePreSales = 19503,
    PIDXCat_CapAuthorizeRefund   = 19504,
    PIDXCat_CapAuthorizeVoid     = 19505,
    PIDXCat_CapAuthorizeVoidPreSales         = 19506,
    PIDXCat_CapCenterResultCode  = 19507,
    PIDXCat_CapCheckCard         = 19508,
    PIDXCat_CapDailyLog          = 19509,
    PIDXCat_CapInstallments      = 19510,
    PIDXCat_CapPaymentDetail     = 19511,
    PIDXCat_CapTaxOthers         = 19512,
    PIDXCat_CapTransactionNumber = 19513,
    PIDXCat_CapTrainingMode      = 19514,
    PIDXCat_CapCashDeposit       = 19515,
    PIDXCat_CapLockTerminal      = 19516,
    PIDXCat_CapLogStatus         = 19517,
    PIDXCat_CapUnlockTerminal    = 19518,

    PIDXCat_AccountNumber        = 1019001,
    PIDXCat_AdditionalSecurityInformation = 1019002,
    PIDXCat_ApprovalCode         = 1019003,
    PIDXCat_CardCompanyID        = 1019004,
    PIDXCat_CenterResultCode     = 1019005,
    PIDXCat_DailyLog             = 1019006,
    PIDXCat_PaymentCondition     = 1019007,
    PIDXCat_PaymentDetail        = 1019008,
    PIDXCat_SequenceNumber       = 1019009,
    PIDXCat_SlipNumber           = 1019010,
    PIDXCat_TransactionNumber    = 1019011
} OPOSCATInternals;
