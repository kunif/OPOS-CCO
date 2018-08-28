/****************************************************************************
**
** OposConst.h -- IDL source to define the OPOS Common Constants, from Opos.h
**
**     Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  2001/01/02 Initial version.                                     C. Monroe
**  2004/10/26 OPOS Release 1.8                                     C. Monroe
**    Add "ResultCodeExtended" statistics constant.
**  2005/04/29 OPOS Release 1.9                                     C. Monroe
**    Add CompareFirmwareVersion's Result constants.
**    Add StatusUpdateEvent and ResultCodeExtended constants
**    for firmware update.
**  2006/03/15 OPOS Release 1.10                                    C. Monroe
**    Add another constant for firmware update.
**  2007/01/30 Additions for 1.11.                                  C. Monroe
**    Add ResultCode constant for deprecation.
**
*****************************************************************************
*/

typedef [helpstring("OPOS Constants")]
enum
{
    OPOS_S_CLOSED                         = 1,
    OPOS_S_IDLE                           = 2,
    OPOS_S_BUSY                           = 3,
    OPOS_S_ERROR                          = 4,

    OPOS_SUCCESS                          =   0,
    OPOS_E_CLOSED                         = 101,
    OPOS_E_CLAIMED                        = 102,
    OPOS_E_NOTCLAIMED                     = 103,
    OPOS_E_NOSERVICE                      = 104,
    OPOS_E_DISABLED                       = 105,
    OPOS_E_ILLEGAL                        = 106,
    OPOS_E_NOHARDWARE                     = 107,
    OPOS_E_OFFLINE                        = 108,
    OPOS_E_NOEXIST                        = 109,
    OPOS_E_EXISTS                         = 110,
    OPOS_E_FAILURE                        = 111,
    OPOS_E_TIMEOUT                        = 112,
    OPOS_E_BUSY                           = 113,
    OPOS_E_EXTENDED                       = 114,
    OPOS_E_DEPRECATED                     = 115,

    OPOS_ESTATS_ERROR                     = 280,
    OPOS_ESTATS_DEPENDENCY                = 282,
    OPOS_EFIRMWARE_BAD_FILE               = 281,

    OPOS_OR_ALREADYOPEN                   = 301,
    OPOS_OR_REGBADNAME                    = 302,
    OPOS_OR_REGPROGID                     = 303,
    OPOS_OR_CREATE                        = 304,
    OPOS_OR_BADIF                         = 305,
    OPOS_OR_FAILEDOPEN                    = 306,
    OPOS_OR_BADVERSION                    = 307,

    OPOS_ORS_NOPORT                       = 401,
    OPOS_ORS_NOTSUPPORTED                 = 402,
    OPOS_ORS_CONFIG                       = 403,
    OPOS_ORS_SPECIFIC                     = 450,

    OPOS_BC_NONE                          = 0,
    OPOS_BC_NIBBLE                        = 1,
    OPOS_BC_DECIMAL                       = 2,

    OPOS_CH_INTERNAL                      = 1,
    OPOS_CH_EXTERNAL                      = 2,
    OPOS_CH_INTERACTIVE                   = 3,

    OPOS_PR_NONE                          = 0,
    OPOS_PR_STANDARD                      = 1,
    OPOS_PR_ADVANCED                      = 2,

    OPOS_PN_DISABLED                      = 0,
    OPOS_PN_ENABLED                       = 1,

    OPOS_PS_UNKNOWN                       = 2000,
    OPOS_PS_ONLINE                        = 2001,
    OPOS_PS_OFF                           = 2002,
    OPOS_PS_OFFLINE                       = 2003,
    OPOS_PS_OFF_OFFLINE                   = 2004,

    OPOS_CFV_FIRMWARE_OLDER               = 1,
    OPOS_CFV_FIRMWARE_SAME                = 2,
    OPOS_CFV_FIRMWARE_NEWER               = 3,
    OPOS_CFV_FIRMWARE_DIFFERENT           = 4,
    OPOS_CFV_FIRMWARE_UNKNOWN             = 5,

    OPOS_EL_OUTPUT                        = 1,
    OPOS_EL_INPUT                         = 2,
    OPOS_EL_INPUT_DATA                    = 3,

    OPOS_ER_RETRY                         = 11,
    OPOS_ER_CLEAR                         = 12,
    OPOS_ER_CONTINUEINPUT                 = 13,

    OPOS_SUE_POWER_ONLINE                 = 2001,
    OPOS_SUE_POWER_OFF                    = 2002,
    OPOS_SUE_POWER_OFFLINE                = 2003,
    OPOS_SUE_POWER_OFF_OFFLINE            = 2004,
    OPOS_SUE_UF_PROGRESS                  = 2100,
    OPOS_SUE_UF_COMPLETE                  = 2200,
    OPOS_SUE_UF_COMPLETE_DEV_NOT_RESTORED = 2205,
    OPOS_SUE_UF_FAILED_DEV_OK             = 2201,
    OPOS_SUE_UF_FAILED_DEV_UNRECOVERABLE  = 2202,
    OPOS_SUE_UF_FAILED_DEV_NEEDS_FIRMWARE = 2203,
    OPOS_SUE_UF_FAILED_DEV_UNKNOWN        = 2204,

    OPOS_FOREVER                          = -1
} OPOS_Constants;
