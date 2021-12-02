//*************************************************************************
//** OPOS VideoCapture Constants
//*************************************************************************

typedef [helpstring("OPOS VideoCapture Constants")]
enum
{
    VCAP_CST_HOST_ONLY                        = 1,
    VCAP_CST_HARDTOTALS_ONLY                  = 2,
    VCAP_CST_ALL                              = 3,
    VCAP_ST_HOST                              = 1,
    VCAP_ST_HARDTOTALS                        = 2,
    VCAP_ST_HOST_HARDTOTALS                   = 3,
    VCAP_VCMODE_PHOTO                         = 1,
    VCAP_VCMODE_VIDEO                         = 2,
    VCAP_SUE_START_PHOTO                      = 11,
    VCAP_SUE_END_PHOTO                        = 12,
    VCAP_SUE_START_VIDEO                      = 21,
    VCAP_SUE_STOP_VIDEO                       = 22,
    OPOS_EVCAP_NOROOM                         = 201
} OPOSVideoCaptureConstants;
