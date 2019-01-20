//*************************************************************************
//** OPOS CoinDispenser Internals
//
//   Coin Dispenser header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS CoinDispenser Internals")]
enum
{
    PIDXCoin_DispenserStatus     =  2001,

    PIDXCoin_CapEmptySensor      =  2501,
    PIDXCoin_CapJamSensor        =  2502,
    PIDXCoin_CapNearEmptySensor  =  2503
} OPOSCoinDispenserInternals;
