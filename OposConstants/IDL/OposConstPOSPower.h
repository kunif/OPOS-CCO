//*************************************************************************
//** OPOS POSPower Constants
//*************************************************************************

typedef [helpstring("OPOS POSPower Constants")]
enum
{
    PWR_UPS_FULL                              = 1,
    PWR_UPS_WARNING                           = 2,
    PWR_UPS_LOW                               = 4,
    PWR_UPS_CRITICAL                          = 8,
    PWR_SOURCE_NA                             = 1,
    PWR_SOURCE_AC                             = 2,
    PWR_SOURCE_BATTERY                        = 3,
    PWR_SOURCE_BACKUP                         = 4,
    PWR_REASON_REQUEST                        = 1,
    PWR_REASON_ALLOW                          = 2,
    PWR_REASON_DENY                           = 3,
    PWR_SUE_UPS_FULL                          = 11,
    PWR_SUE_UPS_WARNING                       = 12,
    PWR_SUE_UPS_LOW                           = 13,
    PWR_SUE_UPS_CRITICAL                      = 14,
    PWR_SUE_FAN_STOPPED                       = 15,
    PWR_SUE_FAN_RUNNING                       = 16,
    PWR_SUE_TEMPERATURE_HIGH                  = 17,
    PWR_SUE_TEMPERATURE_OK                    = 18,
    PWR_SUE_SHUTDOWN                          = 19,
    PWR_SUE_BAT_LOW                           = 20,
    PWR_SUE_BAT_CRITICAL                      = 21,
    PWR_SUE_BAT_CAPACITY_REMAINING            = 22,
    PWR_SUE_RESTART                           = 23,
    PWR_SUE_STANDBY                           = 24,
    PWR_SUE_USER_STANDBY                      = 25,
    PWR_SUE_SUSPEND                           = 26,
    PWR_SUE_USER_SUSPEND                      = 27,
    PWR_SUE_PWR_SOURCE                        = 28
} OPOSPOSPowerConstants;
