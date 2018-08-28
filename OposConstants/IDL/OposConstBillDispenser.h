//*************************************************************************
//** OPOS BillDispenser Constants
//*************************************************************************

typedef [helpstring("OPOS BillDispenser Constants")]
enum
{
    BDSP_STATUS_OK                            = 0,
    BDSP_STATUS_EMPTY                         = 11,
    BDSP_STATUS_NEAREMPTY                     = 12,
    BDSP_STATUS_EMPTYOK                       = 13,
    BDSP_STATUS_JAM                           = 31,
    BDSP_STATUS_JAMOK                         = 32,
    BDSP_STATUS_ASYNC                         = 91,
    OPOS_EBDSP_OVERDISPENSE                   = 201
} OPOSBillDispenserConstants;
