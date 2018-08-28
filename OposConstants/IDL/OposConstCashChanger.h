//*************************************************************************
//** OPOS CashChanger Constants
//*************************************************************************

typedef [helpstring("OPOS CashChanger Constants")]
enum
{
    CHAN_STATUS_OK                            = 0,
    CHAN_STATUS_EMPTY                         = 11,
    CHAN_STATUS_NEAREMPTY                     = 12,
    CHAN_STATUS_EMPTYOK                       = 13,
    CHAN_STATUS_FULL                          = 21,
    CHAN_STATUS_NEARFULL                      = 22,
    CHAN_STATUS_FULLOK                        = 23,
    CHAN_STATUS_JAM                           = 31,
    CHAN_STATUS_JAMOK                         = 32,
    CHAN_STATUS_ASYNC                         = 91,
    CHAN_STATUS_DEPOSIT_START                 = 1,
    CHAN_STATUS_DEPOSIT_END                   = 2,
    CHAN_STATUS_DEPOSIT_NONE                  = 3,
    CHAN_STATUS_DEPOSIT_COUNT                 = 4,
    CHAN_STATUS_DEPOSIT_JAM                   = 5,
    CHAN_DEPOSIT_CHANGE                       = 1,
    CHAN_DEPOSIT_NOCHANGE                     = 2,
    CHAN_DEPOSIT_REPAY                        = 3,
    CHAN_DEPOSIT_PAUSE                        = 11,
    CHAN_DEPOSIT_RESTART                      = 12,
    OPOS_ECHAN_OVERDISPENSE                   = 201
} OPOSCashChangerConstants;
