//*************************************************************************
//** OPOS BillAcceptor Internals
//
//   Bill Acceptor header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS BillAcceptor Internals")]
enum
{
    PIDXBacc_DepositAmount       = 27001,
    PIDXBacc_DepositStatus       = 27002,
    PIDXBacc_FullStatus          = 27003,
    PIDXBacc_RealTimeDataEnabled = 27004,

    PIDXBacc_CapDiscrepancy      = 27501,
    PIDXBacc_CapFullSensor       = 27502,
    PIDXBacc_CapJamSensor        = 27503,
    PIDXBacc_CapNearFullSensor   = 27504,
    PIDXBacc_CapPauseDeposit     = 27505,
    PIDXBacc_CapRealTimeData     = 27506,

    PIDXBacc_CurrencyCode        = 127001,
    PIDXBacc_DepositCashList     = 127002,
    PIDXBacc_DepositCodeList     = 127003,
    PIDXBacc_DepositCounts       = 127004
} OPOSBillAcceptorInternals;
