//*************************************************************************
//** OPOS CashChanger Internals
//
//   Cash Changer header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS CashChanger Internals")]
enum
{
    PIDXChan_AsyncMode               = 13001,
    PIDXChan_AsyncResultCode         = 13002,
    PIDXChan_AsyncResultCodeExtended = 13003,
    PIDXChan_CurrentExit             = 13004,
    PIDXChan_DeviceExits             = 13005,
    PIDXChan_DeviceStatus            = 13006,
    PIDXChan_FullStatus              = 13007,
    PIDXChan_DepositAmount           = 13008,
    PIDXChan_DepositStatus           = 13009,
    PIDXChan_CurrentService          = 13010,
    PIDXChan_RealTimeDataEnabled     = 13011,
    PIDXChan_ServiceCount            = 13012,
    PIDXChan_ServiceIndex            = 13013,

    PIDXChan_CapDiscrepancy      = 13501,
    PIDXChan_CapEmptySensor      = 13502,
    PIDXChan_CapFullSensor       = 13503,
    PIDXChan_CapNearEmptySensor  = 13504,
    PIDXChan_CapNearFullSensor   = 13505,
    PIDXChan_CapDeposit          = 13506,
    PIDXChan_CapDepositDataEvent = 13507,
    PIDXChan_CapPauseDeposit     = 13508,
    PIDXChan_CapRepayDeposit     = 13509,
    PIDXChan_CapJamSensor        = 13510,
    PIDXChan_CapRealTimeData     = 13511,

    PIDXChan_CurrencyCashList    = 1013001,
    PIDXChan_CurrencyCode        = 1013002,
    PIDXChan_CurrencyCodeList    = 1013003,
    PIDXChan_ExitCashList        = 1013004,
    PIDXChan_DepositCashList     = 1013005,
    PIDXChan_DepositCodeList     = 1013006,
    PIDXChan_DepositCounts       = 1013007
} OPOSCashChangerInternals;
