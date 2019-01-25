//*************************************************************************
//** OPOS CoinAcceptor Internals
//
//   Coin Acceptor header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS CoinAcceptor Internals")]
enum
{
    PIDXCacc_DepositAmount       = 29001,
    PIDXCacc_DepositStatus       = 29002,
    PIDXCacc_FullStatus          = 29003,
    PIDXCacc_RealTimeDataEnabled = 29004,

    PIDXCacc_CapDiscrepancy      = 29501,
    PIDXCacc_CapFullSensor       = 29502,
    PIDXCacc_CapJamSensor        = 29503,
    PIDXCacc_CapNearFullSensor   = 29504,
    PIDXCacc_CapPauseDeposit     = 29505,
    PIDXCacc_CapRealTimeData     = 29506,

    PIDXCacc_CurrencyCode        = 1029001,
    PIDXCacc_DepositCashList     = 1029002,
    PIDXCacc_DepositCodeList     = 1029003,
    PIDXCacc_DepositCounts       = 1029004
} OPOSCoinAcceptorInternals;
