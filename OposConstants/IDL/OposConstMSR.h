//*************************************************************************
//** OPOS MSR Constants
//*************************************************************************

typedef [helpstring("OPOS MSR Constants")]
enum
{
    MSR_TR_NONE                               = 0,
    MSR_TR_1                                  = 1,
    MSR_TR_2                                  = 2,
    MSR_TR_3                                  = 4,
    MSR_TR_4                                  = 8,
    MSR_TR_1_2                                = 0x03,
    MSR_TR_1_3                                = 0x05,
    MSR_TR_1_4                                = 0x09,
    MSR_TR_2_3                                = 0x06,
    MSR_TR_2_4                                = 0x0A,
    MSR_TR_3_4                                = 0x0C,
    MSR_TR_1_2_3                              = 0x07,
    MSR_TR_1_2_4                              = 0x0B,
    MSR_TR_1_3_4                              = 0x0D,
    MSR_TR_2_3_4                              = 0x0E,
    MSR_TR_1_2_3_4                            = 0x0F,
    MSR_ERT_CARD                              = 0,
    MSR_ERT_TRACK                             = 1,
    MSR_DE_NONE                               = 0x00000001,
    MSR_DE_3DEA_DUKPT                         = 0x00000002,
    MSR_DA_NOT_SUPPORTED                      = 0,
    MSR_DA_OPTIONAL                           = 1,
    MSR_DA_REQUIRED                           = 2,
    MSR_AP_NONE                               = 0,
    MSR_AP_CHALLENGERESPONSE                  = 1,
    MSR_SUE_DEVICE_AUTHENTICATED              = 11,
    MSR_SUE_DEVICE_DEAUTHENTICATED            = 12,
    OPOS_EMSR_START                           = 201,
    OPOS_EMSR_END                             = 202,
    OPOS_EMSR_PARITY                          = 203,
    OPOS_EMSR_LRC                             = 204,
    OPOS_EMSR_DEVICE_AUTHENTICATION_FAILED    = 205,
    OPOS_EMSR_DEVICE_DEAUTHENTICATION_FAILED  = 206
} OPOSMSRConstants;
