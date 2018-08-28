//*************************************************************************
//** OPOS RFIDScanner Constants
//*************************************************************************

typedef [helpstring("OPOS RFIDScanner Constants")]
enum
{
    RFID_CWT_NONE                             = 0,
    RFID_CWT_ID                               = 1,
    RFID_CWT_USERDATA                         = 2,
    RFID_CWT_ALL                              = 3,
    RFID_PR_EPC0                              = 0x00000001,
    RFID_PR_0PLUS                             = 0x00000002,
    RFID_PR_EPC1                              = 0x00000004,
    RFID_PR_EPC1G2                            = 0x00000008,
    RFID_PR_EPC2                              = 0x00000010,
    RFID_PR_ISO14443A                         = 0x00001000,
    RFID_PR_ISO14443B                         = 0x00002000,
    RFID_PR_ISO15693                          = 0x00003000,
    RFID_PR_ISO180006B                        = 0x00004000,
    RFID_PR_OTHER                             = 0x01000000,
    RFID_PR_ALL                               = 0x40000000,
    RFID_RT_ID                                = 0x10,
    RFID_RT_FULLUSERDATA                      = 0x01,
    RFID_RT_PARTIALUSERDATA                   = 0x02,
    RFID_RT_ID_FULLUSERDATA                   = 0x11,
    RFID_RT_ID_PARTIALUSERDATA                = 0x12
} OPOSRFIDScannerConstants;
