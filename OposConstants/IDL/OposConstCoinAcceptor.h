//*************************************************************************
//** OPOS CoinAcceptor Constants
//*************************************************************************

typedef [helpstring("OPOS CoinAcceptor Constants")]
enum
{
    CACC_STATUS_OK                            = 0,
    CACC_STATUS_FULL                          = 21,
    CACC_STATUS_NEARFULL                      = 22,
    CACC_STATUS_FULLOK                        = 23,
    CACC_STATUS_JAM                           = 31,
    CACC_STATUS_JAMOK                         = 32,
    CACC_STATUS_DEPOSIT_START                 = 1,
    CACC_STATUS_DEPOSIT_END                   = 2,
    CACC_STATUS_DEPOSIT_COUNT                 = 4,
    CACC_STATUS_DEPOSIT_JAM                   = 5,
    CACC_DEPOSIT_COMPLETE                     = 11,
    CACC_DEPOSIT_PAUSE                        = 11,
    CACC_DEPOSIT_RESTART                      = 12
} OPOSCoinAcceptorConstants;
