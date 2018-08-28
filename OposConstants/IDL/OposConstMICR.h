//*************************************************************************
//** OPOS MICR Constants
//*************************************************************************

typedef [helpstring("OPOS MICR Constants")]
enum
{
    MICR_CT_PERSONAL                          = 1,
    MICR_CT_BUSINESS                          = 2,
    MICR_CT_UNKNOWN                           = 99,
    MICR_CC_USA                               = 1,
    MICR_CC_CANADA                            = 2,
    MICR_CC_MEXICO                            = 3,
    MICR_CC_UNKNOWN                           = 99,
    MICR_CC_CMC7                              = 4,
    MICR_CC_OTHER                             = 5,
    OPOS_EMICR_NOCHECK                        = 201,
    OPOS_EMICR_CHECK                          = 202,
    OPOS_EMICR_BADDATA                        = 203,
    OPOS_EMICR_NODATA                         = 204,
    OPOS_EMICR_BADSIZE                        = 205,
    OPOS_EMICR_JAM                            = 206,
    OPOS_EMICR_CHECKDIGIT                     = 207,
    OPOS_EMICR_COVEROPEN                      = 208
} OPOSMICRConstants;
