//*************************************************************************
//** OPOS RFIDScanner Internals
//
//   RFID Scanner header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS RFIDScanner Internals")]
enum
{
    PIDXRfid_ContinuousReadMode              = 36001,
    PIDXRfid_CurrentTagProtocol              = 36002,
    PIDXRfid_ProtocolMask                    = 36003,
    PIDXRfid_ReadTimerInterval               = 36004,
    PIDXRfid_TagCount                        = 36005,

    PIDXRfid_CapContinuousRead               = 36501,
    PIDXRfid_CapDisableTag                   = 36502,
    PIDXRfid_CapLockTag                      = 36503,
    PIDXRfid_CapMultipleProtocols            = 36504,
    PIDXRfid_CapReadTimer                    = 36505,
    PIDXRfid_CapWriteTag                     = 36506,

    PIDXRfid_CurrentTagID                    = 136001,
    PIDXRfid_CurrentTagUserData              = 136002
} OPOSRFIDScannerInternals;
