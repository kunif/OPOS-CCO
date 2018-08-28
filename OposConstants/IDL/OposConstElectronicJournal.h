//*************************************************************************
//** OPOS ElectronicJournal Constants
//*************************************************************************

typedef [helpstring("OPOS ElectronicJournal Constants")]
enum
{
    EJ_S_RECEIPT                              = 0x00000001,
    EJ_S_SLIP                                 = 0x00000002,
    EJ_S_JOURNAL                              = 0x00000004,
    EJ_MT_SESSION_BEG                         = 1,
    EJ_MT_SESSION_END                         = 2,
    EJ_MT_DOCUMENT                            = 3,
    EJ_MT_HEAD                                = 4,
    EJ_MT_TAIL                                = 5,
    OPOS_EEJ_EXISTING                         = 201,
    OPOS_EEJ_MEDIUM_FULL                      = 202,
    OPOS_EEJ_MULTIPLE_MARKER                  = 203,
    OPOS_EEJ_UNINITIALIZED_MEDIUM             = 204,
    OPOS_EEJ_CORRUPTED_MEDIUM                 = 205,
    OPOS_EEJ_UNKNOWN_DATAFORMAT               = 206,
    OPOS_EEJ_NOT_ENOUGH_SPACE                 = 207,
    OPOS_EEJ_MULTIPLE_MARKERS                 = 208,
    EJ_SUE_MEDIUM_NEAR_FULL                   = 1,
    EJ_SUE_MEDIUM_FULL                        = 2,
    EJ_SUE_MEDIUM_REMOVED                     = 3,
    EJ_SUE_MEDIUM_INSERTED                    = 4,
    EJ_SUE_SUSPENDED                          = 5,
    EJ_SUE_IDLE                               = 1001
} OPOSElectronicJournalConstants;
