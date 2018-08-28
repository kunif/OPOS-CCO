//*************************************************************************
//** OPOS Lights Constants
//*************************************************************************

typedef [helpstring("OPOS Lights Constants")]
enum
{
    LGT_ALARM_NOALARM                         = 0x00000001,
    LGT_ALARM_SLOW                            = 0x00000010,
    LGT_ALARM_MEDIUM                          = 0x00000020,
    LGT_ALARM_FAST                            = 0x00000040,
    LGT_ALARM_CUSTOM1                         = 0x00010000,
    LGT_ALARM_CUSTOM2                         = 0x00020000,
    LGT_COLOR_PRIMARY                         = 0x00000001,
    LGT_COLOR_CUSTOM1                         = 0x00010000,
    LGT_COLOR_CUSTOM2                         = 0x00020000,
    LGT_COLOR_CUSTOM3                         = 0x00040000,
    LGT_COLOR_CUSTOM4                         = 0x00080000,
    LGT_COLOR_CUSTOM5                         = 0x00100000
} OPOSLightsConstants;
