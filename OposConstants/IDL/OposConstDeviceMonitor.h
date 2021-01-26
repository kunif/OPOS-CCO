//*************************************************************************
//** OPOS DeviceMonitor Constants
//*************************************************************************

typedef [helpstring("OPOS DeviceMonitor Constants")]
enum
{
    DMON_MMODE_UPDATE                         = 1,
    DMON_MMODE_STRADDLED                      = 2,
    DMON_MMODE_HIGH                           = 3,
    DMON_MMODE_LOW                            = 4,
    DMON_MMODE_WITHIN                         = 5,
    DMON_MMODE_OUTSIDE                        = 6,
    DMON_MMODE_POLLING                        = 7,
    DMON_SUE_START_MONITORING                 = 11,
    DMON_SUE_STOP_MONITORING                  = 12
} OPOSDeviceMonitorConstants;
