//*************************************************************************
//** OPOS POSPower Internals
//
//   POS Power header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS POSPower Internals")]
enum
{
    PIDXPwr_EnforcedShutdownDelayTime        = 21001,
    PIDXPwr_PowerFailDelayTime               = 21002,
    PIDXPwr_QuickChargeMode                  = 21003,
    PIDXPwr_QuickChargeTime                  = 21004,
    PIDXPwr_UPSChargeState                   = 21005,
    PIDXPwr_BatteryCapacityRemaining         = 21006,
    PIDXPwr_BatteryCriticallyLowThreshold    = 21007,
    PIDXPwr_BatteryLowThreshold              = 21008,
    PIDXPwr_PowerSource                      = 21009,

    PIDXPwr_CapFanAlarm                              = 21501,
    PIDXPwr_CapHeatAlarm                             = 21502,
    PIDXPwr_CapQuickCharge                           = 21503,
    PIDXPwr_CapShutdownPOS                           = 21504,
    PIDXPwr_CapUPSChargeState                        = 21505,
    PIDXPwr_CapBatteryCapacityRemaining              = 21506,
    PIDXPwr_CapRestartPOS                            = 21507,
    PIDXPwr_CapStandbyPOS                            = 21508,
    PIDXPwr_CapSuspendPOS                            = 21509,
    PIDXPwr_CapVariableBatteryCriticallyLowThreshold = 21510,
    PIDXPwr_CapVariableBatteryLowThreshold           = 21511
} OPOSPOSPowerInternals;
