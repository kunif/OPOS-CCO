//*************************************************************************
//** OPOS BillAcceptor Constants
//*************************************************************************

typedef [helpstring("OPOS BillAcceptor Constants")]
enum
{
    BACC_STATUS_OK                            = 0,
    BACC_STATUS_FULL                          = 21,
    BACC_STATUS_NEARFULL                      = 22,
    BACC_STATUS_FULLOK                        = 23,
    BACC_STATUS_JAM                           = 31,
    BACC_STATUS_JAMOK                         = 32,
    BACC_STATUS_DEPOSIT_START                 = 1,
    BACC_STATUS_DEPOSIT_END                   = 2,
    BACC_STATUS_DEPOSIT_COUNT                 = 4,
    BACC_STATUS_DEPOSIT_JAM                   = 5,
    BACC_DEPOSIT_COMPLETE                     = 11,
    BACC_DEPOSIT_PAUSE                        = 11,
    BACC_DEPOSIT_RESTART                      = 12
} OPOSBillAcceptorConstants;
