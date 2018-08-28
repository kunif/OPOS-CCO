/////////////////////////////////////////////////////////////////////
//
// OposStat.h
//
//   Statistic names header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2004-07-14 OPOS Release 1.8.1                                  CRM
//   New file to define constants for Device Statistic names.
// 2007-01-30 OPOS Release 1.11 (Add 1.10 and 1.11 constants)     CRM
// 2008-08-30 OPOS Release 1.12 (Add 1.12 constants)              CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSSTAT_H)
#define      OPOSSTAT_H

// Common Statistics for all Device Categories.
#define OPOS_STAT_HoursPoweredCount                 _T("HoursPoweredCount")
#define OPOS_STAT_CommunicationErrorCount           _T("CommunicationErrorCount")

// Statistics for one or more Device Categories.
#define OPOS_STAT_AverageFAR                        _T("AverageFAR")
#define OPOS_STAT_AverageFRR                        _T("AverageFRR")
#define OPOS_STAT_BarcodePrintedCount               _T("BarcodePrintedCount")
#define OPOS_STAT_BumpCount                         _T("BumpCount")
#define OPOS_STAT_ChallengeRequestCount             _T("ChallengeRequestCount")
#define OPOS_STAT_ChecksScannedCount                _T("ChecksScannedCount")
#define OPOS_STAT_DrawerFailedOpenCount             _T("DrawerFailedOpenCount")
#define OPOS_STAT_DrawerGoodOpenCount               _T("DrawerGoodOpenCount")
#define OPOS_STAT_EraseCount                        _T("EraseCount")
#define OPOS_STAT_FailedCardAuthenticationDataCount _T("FailedCardAuthenticationDataCount")
#define OPOS_STAT_FailedDataParseCount              _T("FailedDataParseCount")
#define OPOS_STAT_FailedDeviceAuthenticationCount   _T("FailedDeviceAuthenticationCount")
#define OPOS_STAT_FailedPaperCutCount               _T("FailedPaperCutCount")
#define OPOS_STAT_FailedPrintSideChangeCount        _T("FailedPrintSideChangeCount")
#define OPOS_STAT_FailedReadCount                   _T("FailedReadCount")
#define OPOS_STAT_FailedSignatureReadCount          _T("FailedSignatureReadCount")
#define OPOS_STAT_FailedTagDisableCount             _T("FailedTagDisableCount")
#define OPOS_STAT_FailedTagLockCount                _T("FailedTagLockCount")
#define OPOS_STAT_FailedTagWriteCount               _T("FailedTagWriteCount")
#define OPOS_STAT_FailedWriteCount                  _T("FailedWriteCount")
#define OPOS_STAT_FormInsertionCount                _T("FormInsertionCount")
#define OPOS_STAT_GoodCardAuthenticationDataCount   _T("GoodCardAuthenticationDataCount")
#define OPOS_STAT_GoodDeviceAuthenticationCount     _T("GoodDeviceAuthenticationCount")
#define OPOS_STAT_GoodReadCount                     _T("GoodReadCount")
#define OPOS_STAT_GoodScanCount                     _T("GoodScanCount")
#define OPOS_STAT_GoodSignatureReadCount            _T("GoodSignatureReadCount")
#define OPOS_STAT_GoodTagDisableCount               _T("GoodTagDisableCount")
#define OPOS_STAT_GoodTagLockCount                  _T("GoodTagLockCount")
#define OPOS_STAT_GoodTagWriteCount                 _T("GoodTagWriteCount")
#define OPOS_STAT_GoodWeightReadCount               _T("GoodWeightReadCount")
#define OPOS_STAT_GoodWriteCount                    _T("GoodWriteCount")
#define OPOS_STAT_HomeErrorCount                    _T("HomeErrorCount")
#define OPOS_STAT_InvalidPINEntryCount              _T("InvalidPINEntryCount")
#define OPOS_STAT_JournalCharacterPrintedCount      _T("JournalCharacterPrintedCount")
#define OPOS_STAT_JournalLinePrintedCount           _T("JournalLinePrintedCount")
#define OPOS_STAT_KeyPressedCount                   _T("KeyPressedCount")
#define OPOS_STAT_LockPositionChangeCount           _T("LockPositionChangeCount")
#define OPOS_STAT_MaximumTempReachedCount           _T("MaximumTempReachedCount")
#define OPOS_STAT_MediumFreeSpace                   _T("MediumFreeSpace")
#define OPOS_STAT_MediumRemovedCount                _T("MediumRemovedCount")
#define OPOS_STAT_MediumSize                        _T("MediumSize")
#define OPOS_STAT_MissingStartSentinelTrack1Count   _T("MissingStartSentinelTrack1Count")
#define OPOS_STAT_MissingStartSentinelTrack2Count   _T("MissingStartSentinelTrack2Count")
#define OPOS_STAT_MissingStartSentinelTrack3Count   _T("MissingStartSentinelTrack3Count")
#define OPOS_STAT_MissingStartSentinelTrack4Count   _T("MissingStartSentinelTrack4Count")
#define OPOS_STAT_MotionEventCount                  _T("MotionEventCount")
#define OPOS_STAT_NoReadCount                       _T("NoReadCount")
#define OPOS_STAT_NVRAMWriteCount                   _T("NVRAMWriteCount")
#define OPOS_STAT_OnlineTransitionCount             _T("OnlineTransitionCount")
#define OPOS_STAT_PaperCutCount                     _T("PaperCutCount")
#define OPOS_STAT_ParityLRCErrorTrack1Count         _T("ParityLRCErrorTrack1Count")
#define OPOS_STAT_ParityLRCErrorTrack2Count         _T("ParityLRCErrorTrack2Count")
#define OPOS_STAT_ParityLRCErrorTrack3Count         _T("ParityLRCErrorTrack3Count")
#define OPOS_STAT_ParityLRCErrorTrack4Count         _T("ParityLRCErrorTrack4Count")
#define OPOS_STAT_PrinterFaultCount                 _T("PrinterFaultCount")
#define OPOS_STAT_PrintSideChangeCount              _T("PrintSideChangeCount")
#define OPOS_STAT_ReceiptCharacterPrintedCount      _T("ReceiptCharacterPrintedCount")
#define OPOS_STAT_ReceiptCoverOpenCount             _T("ReceiptCoverOpenCount")
#define OPOS_STAT_ReceiptLineFeedCount              _T("ReceiptLineFeedCount")
#define OPOS_STAT_ReceiptLinePrintedCount           _T("ReceiptLinePrintedCount")
#define OPOS_STAT_SessionCount                      _T("SessionCount")
#define OPOS_STAT_SlipCharacterPrintedCount         _T("SlipCharacterPrintedCount")
#define OPOS_STAT_SlipCoverOpenCount                _T("SlipCoverOpenCount")
#define OPOS_STAT_SlipLineFeedCount                 _T("SlipLineFeedCount")
#define OPOS_STAT_SlipLinePrintedCount              _T("SlipLinePrintedCount")
#define OPOS_STAT_StampFiredCount                   _T("StampFiredCount")
#define OPOS_STAT_SuccessfulMatchCount              _T("SuccessfulMatchCount")
#define OPOS_STAT_TagReadCount                      _T("TagReadCount")
#define OPOS_STAT_ToneSoundedCount                  _T("ToneSoundedCount")
#define OPOS_STAT_UnreadableCardCount               _T("UnreadableCardCount")
#define OPOS_STAT_UnsuccessfulMatchCount            _T("UnsuccessfulMatchCount")
#define OPOS_STAT_ValidPINEntryCount                _T("ValidPINEntryCount")
#define OPOS_STAT_WriteCount                        _T("WriteCount")

#endif                  // !defined(OPOSSTAT_H)
