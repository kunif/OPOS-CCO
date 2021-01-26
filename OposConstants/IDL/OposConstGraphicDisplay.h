//*************************************************************************
//** OPOS GraphicDisplay Constants
//*************************************************************************

typedef [helpstring("OPOS GraphicDisplay Constants")]
enum
{
    GDSP_CST_HOST_ONLY                        = 1,
    GDSP_CST_HARDTOTALS_ONLY                  = 2,
    GDSP_CST_ALL                              = 3,
    GDSP_ST_HOST                              = 1,
    GDSP_ST_HARDTOTALS                        = 2,
    GDSP_ST_HOST_HARDTOTALS                   = 3,
    GDSP_DMODE_HIDDEN                         = 1,
    GDSP_DMODE_IMAGE_FIT                      = 2,
    GDSP_DMODE_IMAGE_FILL                     = 3,
    GDSP_DMODE_IMAGE_CENTER                   = 4,
    GDSP_DMODE_VIDEO_NORMAL                   = 5,
    GDSP_DMODE_VIDEO_FULL                     = 6,
    GDSP_DMODE_WEB                            = 7,
    GDSP_LSTATUS_START                        = 1,
    GDSP_LSTATUS_FINISH                       = 2,
    GDSP_LSTATUS_CANCEL                       = 3,
    GDSP_SUE_START_IMAGE_LOAD                 = 11,
    GDSP_SUE_END_IMAGE_LOAD                   = 12,
    GDSP_SUE_START_LOAD_WEBPAGE               = 21,
    GDSP_SUE_FINISH_LOAD_WEBPAGE              = 22,
    GDSP_SUE_CANCEL_LOAD_WEBPAGE              = 23,
    GDSP_SUE_START_PLAY_VIDEO                 = 31,
    GDSP_SUE_STOP_PLAY_VIDEO                  = 32,
    OPOS_EGDSP_NOROOM                         = 201
} OPOSGraphicDisplayConstants;
