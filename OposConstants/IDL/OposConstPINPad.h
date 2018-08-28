//*************************************************************************
//** OPOS PINPad Constants
//*************************************************************************

typedef [helpstring("OPOS PINPad Constants")]
enum
{
    PPAD_DISP_UNRESTRICTED                    = 1,
    PPAD_DISP_PINRESTRICTED                   = 2,
    PPAD_DISP_RESTRICTED_LIST                 = 3,
    PPAD_DISP_RESTRICTED_ORDER                = 4,
    PPAD_DISP_NONE                            = 5,
    PPAD_MSG_ENTERPIN                         = 1,
    PPAD_MSG_PLEASEWAIT                       = 2,
    PPAD_MSG_ENTERVALIDPIN                    = 3,
    PPAD_MSG_RETRIESEXCEEDED                  = 4,
    PPAD_MSG_APPROVED                         = 5,
    PPAD_MSG_DECLINED                         = 6,
    PPAD_MSG_CANCELED                         = 7,
    PPAD_MSG_AMOUNTOK                         = 8,
    PPAD_MSG_NOTREADY                         = 9,
    PPAD_MSG_IDLE                             = 10,
    PPAD_MSG_SLIDE_CARD                       = 11,
    PPAD_MSG_INSERTCARD                       = 12,
    PPAD_MSG_SELECTCARDTYPE                   = 13,
    PPAD_LANG_NONE                            = 1,
    PPAD_LANG_ONE                             = 2,
    PPAD_LANG_PINRESTRICTED                   = 3,
    PPAD_LANG_UNRESTRICTED                    = 4,
    PPAD_TRANS_DEBIT                          = 1,
    PPAD_TRANS_CREDIT                         = 2,
    PPAD_TRANS_INQ                            = 3,
    PPAD_TRANS_RECONCILE                      = 4,
    PPAD_TRANS_ADMIN                          = 5,
    PPAD_EFT_NORMAL                           = 1,
    PPAD_EFT_ABNORMAL                         = 2,
    PPAD_SUCCESS                              = 1,
    PPAD_CANCEL                               = 2,
    OPOS_EPPAD_BAD_KEY                        = 201
} OPOSPINPadConstants;
