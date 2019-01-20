using System.Runtime.InteropServices;

[ComVisible(false)]
internal static class OposStat
{
    /////////////////////////////////////////////////////////////////////
    //
    // OposStat.h
    //
    //   Statistic names header file for OPOS Applications.
    //
    /////////////////////////////////////////////////////////////////////

    // Common Statistics for all Device Categories.
    internal const string OPOS_STAT_HoursPoweredCount = "HoursPoweredCount";
    internal const string OPOS_STAT_CommunicationErrorCount = "CommunicationErrorCount";

    // Statistics for one or more Device Categories.
    internal const string OPOS_STAT_AverageFAR = "AverageFAR";
    internal const string OPOS_STAT_AverageFRR = "AverageFRR";
    internal const string OPOS_STAT_BarcodePrintedCount = "BarcodePrintedCount";
    internal const string OPOS_STAT_BumpCount = "BumpCount";
    internal const string OPOS_STAT_ChallengeRequestCount = "ChallengeRequestCount";
    internal const string OPOS_STAT_ChecksScannedCount = "ChecksScannedCount";
    internal const string OPOS_STAT_DrawerFailedOpenCount = "DrawerFailedOpenCount";
    internal const string OPOS_STAT_DrawerGoodOpenCount = "DrawerGoodOpenCount";
    internal const string OPOS_STAT_EraseCount = "EraseCount";
    internal const string OPOS_STAT_FailedCardAuthenticationDataCount = "FailedCardAuthenticationDataCount";
    internal const string OPOS_STAT_FailedDataParseCount = "FailedDataParseCount";
    internal const string OPOS_STAT_FailedDeviceAuthenticationCount = "FailedDeviceAuthenticationCount";
    internal const string OPOS_STAT_FailedPaperCutCount = "FailedPaperCutCount";
    internal const string OPOS_STAT_FailedPrintSideChangeCount = "FailedPrintSideChangeCount";
    internal const string OPOS_STAT_FailedReadCount = "FailedReadCount";
    internal const string OPOS_STAT_FailedSignatureReadCount = "FailedSignatureReadCount";
    internal const string OPOS_STAT_FailedTagDisableCount = "FailedTagDisableCount";
    internal const string OPOS_STAT_FailedTagLockCount = "FailedTagLockCount";
    internal const string OPOS_STAT_FailedTagWriteCount = "FailedTagWriteCount";
    internal const string OPOS_STAT_FailedWriteCount = "FailedWriteCount";
    internal const string OPOS_STAT_FormInsertionCount = "FormInsertionCount";
    internal const string OPOS_STAT_GoodCardAuthenticationDataCount = "GoodCardAuthenticationDataCount";
    internal const string OPOS_STAT_GoodDeviceAuthenticationCount = "GoodDeviceAuthenticationCount";
    internal const string OPOS_STAT_GoodReadCount = "GoodReadCount";
    internal const string OPOS_STAT_GoodScanCount = "GoodScanCount";
    internal const string OPOS_STAT_GoodSignatureReadCount = "GoodSignatureReadCount";
    internal const string OPOS_STAT_GoodTagDisableCount = "GoodTagDisableCount";
    internal const string OPOS_STAT_GoodTagLockCount = "GoodTagLockCount";
    internal const string OPOS_STAT_GoodTagWriteCount = "GoodTagWriteCount";
    internal const string OPOS_STAT_GoodWeightReadCount = "GoodWeightReadCount";
    internal const string OPOS_STAT_GoodWriteCount = "GoodWriteCount";
    internal const string OPOS_STAT_HomeErrorCount = "HomeErrorCount";
    internal const string OPOS_STAT_InvalidPINEntryCount = "InvalidPINEntryCount";
    internal const string OPOS_STAT_JournalCharacterPrintedCount = "JournalCharacterPrintedCount";
    internal const string OPOS_STAT_JournalLinePrintedCount = "JournalLinePrintedCount";
    internal const string OPOS_STAT_KeyPressedCount = "KeyPressedCount";
    internal const string OPOS_STAT_LockPositionChangeCount = "LockPositionChangeCount";
    internal const string OPOS_STAT_MaximumTempReachedCount = "MaximumTempReachedCount";
    internal const string OPOS_STAT_MediumFreeSpace = "MediumFreeSpace";
    internal const string OPOS_STAT_MediumRemovedCount = "MediumRemovedCount";
    internal const string OPOS_STAT_MediumSize = "MediumSize";
    internal const string OPOS_STAT_MissingStartSentinelTrack1Count = "MissingStartSentinelTrack1Count";
    internal const string OPOS_STAT_MissingStartSentinelTrack2Count = "MissingStartSentinelTrack2Count";
    internal const string OPOS_STAT_MissingStartSentinelTrack3Count = "MissingStartSentinelTrack3Count";
    internal const string OPOS_STAT_MissingStartSentinelTrack4Count = "MissingStartSentinelTrack4Count";
    internal const string OPOS_STAT_MotionEventCount = "MotionEventCount";
    internal const string OPOS_STAT_NoReadCount = "NoReadCount";
    internal const string OPOS_STAT_NVRAMWriteCount = "NVRAMWriteCount";
    internal const string OPOS_STAT_OnlineTransitionCount = "OnlineTransitionCount";
    internal const string OPOS_STAT_PaperCutCount = "PaperCutCount";
    internal const string OPOS_STAT_ParityLRCErrorTrack1Count = "ParityLRCErrorTrack1Count";
    internal const string OPOS_STAT_ParityLRCErrorTrack2Count = "ParityLRCErrorTrack2Count";
    internal const string OPOS_STAT_ParityLRCErrorTrack3Count = "ParityLRCErrorTrack3Count";
    internal const string OPOS_STAT_ParityLRCErrorTrack4Count = "ParityLRCErrorTrack4Count";
    internal const string OPOS_STAT_PrinterFaultCount = "PrinterFaultCount";
    internal const string OPOS_STAT_PrintSideChangeCount = "PrintSideChangeCount";
    internal const string OPOS_STAT_ReceiptCharacterPrintedCount = "ReceiptCharacterPrintedCount";
    internal const string OPOS_STAT_ReceiptCoverOpenCount = "ReceiptCoverOpenCount";
    internal const string OPOS_STAT_ReceiptLineFeedCount = "ReceiptLineFeedCount";
    internal const string OPOS_STAT_ReceiptLinePrintedCount = "ReceiptLinePrintedCount";
    internal const string OPOS_STAT_SessionCount = "SessionCount";
    internal const string OPOS_STAT_SlipCharacterPrintedCount = "SlipCharacterPrintedCount";
    internal const string OPOS_STAT_SlipCoverOpenCount = "SlipCoverOpenCount";
    internal const string OPOS_STAT_SlipLineFeedCount = "SlipLineFeedCount";
    internal const string OPOS_STAT_SlipLinePrintedCount = "SlipLinePrintedCount";
    internal const string OPOS_STAT_StampFiredCount = "StampFiredCount";
    internal const string OPOS_STAT_SuccessfulMatchCount = "SuccessfulMatchCount";
    internal const string OPOS_STAT_TagReadCount = "TagReadCount";
    internal const string OPOS_STAT_ToneSoundedCount = "ToneSoundedCount";
    internal const string OPOS_STAT_UnreadableCardCount = "UnreadableCardCount";
    internal const string OPOS_STAT_UnsuccessfulMatchCount = "UnsuccessfulMatchCount";
    internal const string OPOS_STAT_ValidPINEntryCount = "ValidPINEntryCount";
    internal const string OPOS_STAT_WriteCount = "WriteCount";
}
