//*************************************************************************
//** OPOS SmartCardRW Constants
//*************************************************************************

typedef [helpstring("OPOS SmartCardRW Constants")]
enum
{
    SC_CMODE_TRANS                            = 1,
    SC_CMODE_BLOCK                            = 2,
    SC_CMODE_APDU                             = 4,
    SC_CMODE_XML                              = 8,
    SC_CMODE_ISO                              = 1,
    SC_CMODE_EMV                              = 2,
    SC_CTRANS_PROTOCOL_T0                     = 1,
    SC_CTRANS_PROTOCOL_T1                     = 2,
    SC_MODE_TRANS                             = 1,
    SC_MODE_BLOCK                             = 2,
    SC_MODE_APDU                              = 4,
    SC_MODE_XML                               = 8,
    SC_MODE_ISO                               = 1,
    SC_MODE_EMV                               = 2,
    SC_TRANS_PROTOCOL_T0                      = 1,
    SC_TRANS_PROTOCOL_T1                      = 2,
    SC_READ_DATA                              = 11,
    SC_READ_PROGRAM                           = 12,
    SC_EXECUTE_AND_READ_DATA                  = 13,
    SC_XML_READ_BLOCK_DATA                    = 14,
    SC_STORE_DATA                             = 21,
    SC_STORE_PROGRAM                          = 22,
    SC_EXECUTE_DATA                           = 23,
    SC_XML_BLOCK_DATA                         = 24,
    SC_SECURITY_FUSE                          = 25,
    SC_RESET                                  = 26,
    SC_SUE_NO_CARD                            = 1,
    SC_SUE_CARD_PRESENT                       = 2,
    OPOS_ESC_READ                             = 201,
    OPOS_ESC_WRITE                            = 202,
    OPOS_ESC_TORN                             = 203,
    OPOS_ESC_NO_CARD                          = 204
} OPOSSmartCardRWConstants;
