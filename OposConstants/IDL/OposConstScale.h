//*************************************************************************
//** OPOS Scale Constants
//*************************************************************************

typedef [helpstring("OPOS Scale Constants")]
enum
{
    SCAL_WU_GRAM                              = 1,
    SCAL_WU_KILOGRAM                          = 2,
    SCAL_WU_OUNCE                             = 3,
    SCAL_WU_POUND                             = 4,
    SCAL_SN_DISABLED                          = 1,
    SCAL_SN_ENABLED                           = 2,
    SCAL_SFR_MANUAL_TARE                      = 0x00000001,
    SCAL_SFR_WEIGHTED_TARE                    = 0x00000002,
    SCAL_SFR_PERCENT_TARE                     = 0x00000004,
    SCAL_SFR_UNITPRICE                        = 0x00000008,
    SCAL_PCM_PRICE_LABELING                   = 1,
    SCAL_PCM_SELF_SERVICE                     = 2,
    SCAL_PCM_OPERATOR                         = 3,
    SCAL_SST_DEFAULT                          = 1,
    SCAL_SST_MANUAL                           = 2,
    SCAL_SST_PERCENT                          = 3,
    SCAL_SST_WEIGHTED                         = 4,
    SCAL_STP_FIRST                            = 1,
    SCAL_STP_NONE                             = 2,
    SCAL_SUE_STABLE_WEIGHT                    = 11,
    SCAL_SUE_WEIGHT_UNSTABLE                  = 12,
    SCAL_SUE_WEIGHT_ZERO                      = 13,
    SCAL_SUE_WEIGHT_OVERWEIGHT                = 14,
    SCAL_SUE_NOT_READY                        = 15,
    SCAL_SUE_WEIGHT_UNDER_ZERO                = 16,
    OPOS_ESCAL_OVERWEIGHT                     = 201,
    OPOS_ESCAL_UNDER_ZERO                     = 202,
    OPOS_ESCAL_SAME_WEIGHT                    = 203
} OPOSScaleConstants;
