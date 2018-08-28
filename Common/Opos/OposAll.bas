REM *///////////////////////////////////////////////////////////////////
REM *///////////////////////////////////////////////////////////////////
REM *///////////////////////////////////////////////////////////////////
REM *
REM * OPOSALL.BAS
REM *
REM *   Includes all OPOS Device Classes.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 96-03-18 OPOS Release 1.01                                    CRM
REM * 96-04-22 OPOS Release 1.1                                     CRM
REM * 97-06-04 OPOS Release 1.2                                     CRM
REM * 98-03-06 OPOS Release 1.3                                     CRM
REM * 99-06-18 OPOS Release 1.4 and 1.5                             CRM
REM * 00-09-24 OPOS Release 1.5                                     BKS
REM * 01-07-15 OPOS Release 1.6                                 THH/BKS
REM *
REM *  Note: This file is not actively maintained.
REM *        The recommended source of up-to-date constants is the
REM *          file Opos_Constants.dll. Add a reference to it, then
REM *          use VB's Object Browser to find the constants.
REM *
REM *///////////////////////////////////////////////////////////////////
REM *///////////////////////////////////////////////////////////////////
REM *///////////////////////////////////////////////////////////////////



REM *///////////////////////////////////////////////////////////////////
REM *
REM * Opos.h
REM *
REM *   General header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM * 97-06-04 OPOS Release 1.2               MtD                      CRM
REM *   Add OPOS_FOREVER.
REM *   Add BinaryConversion values.
REM * 98-03-06 OPOS Release 1.3                                     CRM
REM *   Add CapPowerReporting, PowerState, and PowerNotify values.
REM *   Add power reporting values for StatusUpdateEvent.
REM * 00-09-24 OPOS Release 1.5                                     CRM
REM *   Add OpenResult status values.
REM * 00-07-18 OPOS Release 1.5                                     BKS
REM *   Add many values and Point Card Reader Writer and
REM *   POS Power sections.
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * OPOS "State" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposSClosed&              = 1
Public Const OposSIdle&                = 2
Public Const OposSBusy&                = 3
Public Const OposSError&               = 4


REM *///////////////////////////////////////////////////////////////////
REM * OPOS "ResultCode" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposSuccess&              =   0
Public Const OposEClosed&              = 101
Public Const OposEClaimed&             = 102
Public Const OposENotclaimed&          = 103
Public Const OposENoservice&           = 104
Public Const OposEDisabled&            = 105
Public Const OposEIllegal&             = 106
Public Const OposENohardware&          = 107
Public Const OposEOffline&             = 108
Public Const OposENoexist&             = 109
Public Const OposEExists&              = 110
Public Const OposEFailure&             = 111
Public Const OposETimeout&             = 112
Public Const OposEBusy&                = 113
Public Const OposEExtended&            = 114


REM *///////////////////////////////////////////////////////////////////
REM * OPOS "OpenResult" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const Oposopenerr&              = 300

Public Const OposOrAlreadyopen&        = 301
Public Const OposOrRegbadname&         = 302
Public Const OposOrRegprogid&          = 303
Public Const OposOrCreate&             = 304
Public Const OposOrBadif&              = 305
Public Const OposOrFailedopen&         = 306
Public Const OposOrBadversion&         = 307

Public Const Oposopenerrso&            = 400

Public Const OposOrsNoport             = 401
Public Const OposOrsNotsupported       = 402
Public Const OposOrsConfig             = 403
Public Const OposOrsSpecific           = 450


REM *///////////////////////////////////////////////////////////////////
REM * OPOS "BinaryConversion" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposBcNone&               = 0
Public Const OposBcNibble&             = 1
Public Const OposBcDecimal&            = 2


REM *///////////////////////////////////////////////////////////////////
REM * "CheckHealth" Method: "Level" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposChInternal&           = 1
Public Const OposChExternal&           = 2
Public Const OposChInteractive&        = 3


REM *///////////////////////////////////////////////////////////////////
REM * OPOS "CapPowerReporting", "PowerState", "PowerNotify" Property
REM *   Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposPrNone&               = 0
Public Const OposPrStandard&           = 1
Public Const OposPrAdvanced&           = 2

Public Const OposPnDisabled&           = 0
Public Const OposPnEnabled&            = 1

Public Const OposPsUnknown&            = 2000
Public Const OposPsOnline&             = 2001
Public Const OposPsOff&                = 2002
Public Const OposPsOffline&            = 2003
Public Const OposPsOffOffline&         = 2004


REM *///////////////////////////////////////////////////////////////////
REM * "ErrorEvent" Event: "ErrorLocus" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposElOutput&             = 1
Public Const OposElInput&              = 2
Public Const OposElInputData&          = 3


REM *///////////////////////////////////////////////////////////////////
REM * "ErrorEvent" Event: "ErrorResponse" Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposErRetry&              = 11
Public Const OposErClear&              = 12
Public Const OposErContinueinput&      = 13


REM *///////////////////////////////////////////////////////////////////
REM * "StatusUpdateEvent" Event: Common "Status" Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposSuePowerOnline&       = 2001
Public Const OposSuePowerOff&          = 2002
Public Const OposSuePowerOffline&      = 2003
Public Const OposSuePowerOffOffline&   = 2004


REM *///////////////////////////////////////////////////////////////////
REM * General Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposForever&              = -1



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposBb.h
REM *
REM *   Bump Bar header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 98-03-06 OPOS Release 1.3                                     BB
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "CurrentUnitID" and "UnitsOnline" Properties
REM *  and "Units" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const BbUid1&                   = &H00000001
Public Const BbUid2&                   = &H00000002
Public Const BbUid3&                   = &H00000004
Public Const BbUid4&                   = &H00000008
Public Const BbUid5&                   = &H00000010
Public Const BbUid6&                   = &H00000020
Public Const BbUid7&                   = &H00000040
Public Const BbUid8&                   = &H00000080
Public Const BbUid9&                   = &H00000100
Public Const BbUid10&                  = &H00000200
Public Const BbUid11&                  = &H00000400
Public Const BbUid12&                  = &H00000800
Public Const BbUid13&                  = &H00001000
Public Const BbUid14&                  = &H00002000
Public Const BbUid15&                  = &H00004000
Public Const BbUid16&                  = &H00008000
Public Const BbUid17&                  = &H00010000
Public Const BbUid18&                  = &H00020000
Public Const BbUid19&                  = &H00040000
Public Const BbUid20&                  = &H00080000
Public Const BbUid21&                  = &H00100000
Public Const BbUid22&                  = &H00200000
Public Const BbUid23&                  = &H00400000
Public Const BbUid24&                  = &H00800000
Public Const BbUid25&                  = &H01000000
Public Const BbUid26&                  = &H02000000
Public Const BbUid27&                  = &H04000000
Public Const BbUid28&                  = &H08000000
Public Const BbUid29&                  = &H10000000
Public Const BbUid30&                  = &H20000000
Public Const BbUid31&                  = &H40000000
Public Const BbUid32&                  = &H80000000


REM *///////////////////////////////////////////////////////////////////
REM * "DataEvent" Event: "Status" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const BbDeKey&                  = &H01



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposCash.h
REM *
REM *   Cash Drawer header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM * 98-03-06 OPOS Release 1.3                                     CRM
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "StatusUpdateEvent" Event Constants
REM *///////////////////////////////////////////////////////////////////

Public Const CashSueDrawerclosed&      = 0
Public Const CashSueDraweropen&        = 1



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposCAT.h
REM *
REM *   CAT header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 98-09-23 OPOS Release 1.4                                 OPOS-J
REM * 00-09-24 OPOS Release 1.5                                    BKS
REM *   Add CAT_PAYMENT_DEBIT, CAT_MEDIA_UNSPECIFIED,
REM *   CAT_MEDIA_NONDEFINE, CAT_MEDIA_CREDIT, CAT_MEDIA_DEBIT
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * Payment Condition Constants
REM *///////////////////////////////////////////////////////////////////

Public Const CatPaymentLump&                =  10
Public Const CatPaymentBonus1&              =  21
Public Const CatPaymentBonus2&              =  22
Public Const CatPaymentBonus3&              =  23
Public Const CatPaymentBonus4&              =  24
Public Const CatPaymentBonus5&              =  25
Public Const CatPaymentInstallment1&        =  61
Public Const CatPaymentInstallment2&        =  62
Public Const CatPaymentInstallment3&        =  63
Public Const CatPaymentBonusCombination1&   =  31
Public Const CatPaymentBonusCombination2&   =  32
Public Const CatPaymentBonusCombination3&   =  33
Public Const CatPaymentBonusCombination4&   =  34
Public Const CatPaymentRevolving&           =  80
Public Const CatPaymentDebit&               = 110


REM *///////////////////////////////////////////////////////////////////
REM * Transaction Type Constants
REM *///////////////////////////////////////////////////////////////////

Public Const CatTransactionSales&           = 10
Public Const CatTransactionVoid&            = 20
Public Const CatTransactionRefund&          = 21
Public Const CatTransactionVoidpresales&    = 29
Public Const CatTransactionCompletion&      = 30
Public Const CatTransactionPresales&        = 40
Public Const CatTransactionCheckcard&       = 41


REM *///////////////////////////////////////////////////////////////////
REM * "PaymentMedia" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const CatMediaUnspecified&           = 0
Public Const CatMediaNondefine&             = 0
Public Const CatMediaCredit&                = 1
Public Const CatMediaDebit&                 = 2


REM *///////////////////////////////////////////////////////////////////
REM * ResultCodeExtended Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposEcatCentererror&           = 01
Public Const OposEcatCommanderror&          = 90
Public Const OposEcatReset&                 = 91
Public Const OposEcatCommunicationerror&    = 92
Public Const OposEcatDailylogoverflow&      = 200


REM *///////////////////////////////////////////////////////////////////
REM * "Daily Log" Property  & Argument Constants
REM *///////////////////////////////////////////////////////////////////

Public Const CatDlNone&                     = 0             'None of them
Public Const CatDlReporting&                = 1             'Only Reporting
Public Const CatDlSettlement&               = 2             'Only Settlement
Public Const CatDlReportingSettlement&      = 3             'Both of them



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposChan.h
REM *
REM *   Cash Changer header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 97-06-04 OPOS Release 1.2                                     CRM
REM * 00-09-24 OPOS Release 1.5                                  OPOS-J
REM *   Add DepositStatus Constants.
REM *   Add EndDeposit Constants.
REM *   Add PauseDeposit Constants.
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "DeviceStatus" and "FullStatus" Property Constants
REM * "StatusUpdateEvent" Event Constants
REM *///////////////////////////////////////////////////////////////////

Public Const ChanStatusOk&             =  0            ' DeviceStatus, FullStatus

Public Const ChanStatusEmpty&          = 11            ' DeviceStatus, StatusUpdateEvent
Public Const ChanStatusNearempty&      = 12            ' DeviceStatus, StatusUpdateEvent
Public Const ChanStatusEmptyok&        = 13            ' StatusUpdateEvent

Public Const ChanStatusFull&           = 21            ' FullStatus, StatusUpdateEvent
Public Const ChanStatusNearfull&       = 22            ' FullStatus, StatusUpdateEvent
Public Const ChanStatusFullok&         = 23            ' StatusUpdateEvent

Public Const ChanStatusJam&            = 31            ' DeviceStatus, StatusUpdateEvent
Public Const ChanStatusJamok&          = 32            ' StatusUpdateEvent

Public Const ChanStatusAsync&          = 91            ' StatusUpdateEvent


REM *///////////////////////////////////////////////////////////////////
REM * "DepositStatus" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const ChanStatusDepositStart&      =  1
Public Const ChanStatusDepositEnd&        =  2
Public Const ChanStatusDepositNone&       =  3
Public Const ChanStatusDepositCount&      =  4
Public Const ChanStatusDepositJam&        =  5


REM *///////////////////////////////////////////////////////////////////
REM * "EndDeposit" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const ChanDepositChange&           =  1
Public Const ChanDepositNochange&         =  2
Public Const ChanDepositrepay&            =  3


REM *///////////////////////////////////////////////////////////////////
REM * "PauseDeposit" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const ChanDepositPause&            =  1
Public Const ChanDepositRestart&          =  2


REM *///////////////////////////////////////////////////////////////////
REM * "ResultCodeExtended" Property Constants for Cash Changer
REM *///////////////////////////////////////////////////////////////////

Public Const OposEchanOverdispense&    = 201



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposCoin.h
REM *
REM *   Coin Dispenser header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "DispenserStatus" Property Constants
REM * "StatusUpdateEvent" Event: "Data" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const CoinStatusOk&             = 1
Public Const CoinStatusEmpty&          = 2
Public Const CoinStatusNearempty&      = 3
Public Const CoinStatusJam&            = 4



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposDisp.h
REM *
REM *   Line Display header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM * 96-03-18 OPOS Release 1.01                                    CRM
REM *   Add DISP_MT_INIT constant and MarqueeFormat constants.
REM * 96-04-22 OPOS Release 1.1                                     CRM
REM *   Add CapCharacterSet values for Kana and Kanji.
REM * 00-09-24 OPOS Release 1.5                                     BKS
REM *   Add CapCharacterSet and CharacterSet constants for UNICODE
REM * 01-07-15 OPOS Release 1.6                                     BKS
REM *   Add CapCursorType, CapCustomGlyph, CapReadBack, CapReverse,
REM *     CursorType property constants.
REM *   Add DefineGlyph, DisplayText and DisplayTextAt parameter
REM *     constants.
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "CapBlink" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispCbNoblink&            = 0
Public Const DispCbBlinkall&           = 1
Public Const DispCbBlinkeach&          = 2


REM *///////////////////////////////////////////////////////////////////
REM * "CapCharacterSet" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispCcsNumeric&           =   0
Public Const DispCcsAlpha&             =   1
Public Const DispCcsAscii&             = 998
Public Const DispCcsKana&              =  10
Public Const DispCcsKanji&             =  11
Public Const DispCcsUnicode&           = 997


REM *///////////////////////////////////////////////////////////////////
REM * "CapCursorType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispCctNone&        = &H00000000
Public Const DispCctFixed&       = &H00000001
Public Const DispCctBlock&       = &H00000002
Public Const DispCctHalfblock&   = &H00000004
Public Const DispCctUnderline&   = &H00000008
Public Const DispCctReverse&     = &H00000010
Public Const DispCctOther&       = &H00000020


REM *///////////////////////////////////////////////////////////////////
REM * "CapReadBack" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispCrbNone&        = &H00000000
Public Const DispCrbSingle&      = &H00000001


REM *///////////////////////////////////////////////////////////////////
REM * "CapReverse" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispCrNone&         = &H00000000
Public Const DispCrReverseall&   = &H00000001
Public Const DispCrReverseeach&  = &H00000002


REM *///////////////////////////////////////////////////////////////////
REM * "CharacterSet" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispCsUnicode&            = 997
Public Const DispCsAscii&              = 998
Public Const DispCsWindows&            = 999


REM *///////////////////////////////////////////////////////////////////
REM * "CursorType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispCtNone&        =   0
Public Const DispCtFixed&       =   1
Public Const DispCtBlock&       =   2
Public Const DispCtHalfblock&   =   3
Public Const DispCtUnderline&   =   4
Public Const DispCtReverse&     =   5
Public Const DispCtOther&       =   6


REM *///////////////////////////////////////////////////////////////////
REM * "MarqueeType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispMtNone&               = 0
Public Const DispMtUp&                 = 1
Public Const DispMtDown&               = 2
Public Const DispMtLeft&               = 3
Public Const DispMtRight&              = 4
Public Const DispMtInit&               = 5


REM *///////////////////////////////////////////////////////////////////
REM * "MarqueeFormat" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispMfWalk&               = 0
Public Const DispMfPlace&              = 1


REM *///////////////////////////////////////////////////////////////////
REM * "DefineGlyph" Method: "GlyphType" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispGtSingle&             = 1


REM *///////////////////////////////////////////////////////////////////
REM * "DisplayText" Method: "Attribute" Property Constants
REM * "DisplayTextAt" Method: "Attribute" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispDtNormal&             = 0
Public Const DispDtBlink&              = 1
Public Const DispDtReverse&            = 2
Public Const DispDtBlinkReverse&       = 3


REM *///////////////////////////////////////////////////////////////////
REM * "ScrollText" Method: "Direction" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispStUp&                 = 1
Public Const DispStDown&               = 2
Public Const DispStLeft&               = 3
Public Const DispStRight&              = 4


REM *///////////////////////////////////////////////////////////////////
REM * "SetDescriptor" Method: "Attribute" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const DispSdOff&                = 0
Public Const DispSdOn&                 = 1
Public Const DispSdBlink&              = 2



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposFptr.h
REM *
REM *   Fiscal Printer header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 98-03-06 OPOS Release 1.3                                     PDU
REM * 00-09-24 OPOS Release 1.5                                     BKS
REM *   Change CountryCode constants and add code for Russia
REM * 01-07-15 OPOS Release 1.6                                     THH
REM *   Add values for all 1.6 added properties and method
REM *   parameters
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "ActualCurrency" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrAcBrc&                =   1
Public Const FptrAcBgl&                =   2
Public Const FptrAcEur&                =   3
Public Const FptrAcGrd&                =   4
Public Const FptrAcHuf&                =   5
Public Const FptrAcItl&                =   6
Public Const FptrAcPlz&                =   7
Public Const FptrAcRol&                =   8
Public Const FptrAcRur&                =   9
Public Const FptrAcTrl&                =  10


REM *///////////////////////////////////////////////////////////////////
REM * "ContractorId" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrCidFirst&             =  1
Public Const FptrCidSecond&            =  2
Public Const FptrCidSingle&            =  3


REM *///////////////////////////////////////////////////////////////////
REM * Fiscal Printer Station Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrSJournal&             = 1
Public Const FptrSReceipt&             = 2
Public Const FptrSSlip&                = 4

Public Const FptrSJournalReceipt&      = FptrSJournal OR FptrSReceipt


REM *///////////////////////////////////////////////////////////////////
REM * "CountryCode" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrCcBrazil&             =   1
Public Const FptrCcGreece&             =   2
Public Const FptrCcHungary&            =   4
Public Const FptrCcItaly&              =   8
Public Const FptrCcPoland&             =  16
Public Const FptrCcTurkey&             =  32
Public Const FptrCcRussia&             =  64
Public Const FptrCcBulgaria&           = 128
Public Const FptrCcRomania&            = 256


REM *///////////////////////////////////////////////////////////////////
REM * "DateType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrDtConf&               =  1
Public Const FptrDtEod&                =  2
Public Const FptrDtReset&              =  3
Public Const FptrDtRtc&                =  4
Public Const FptrDtVat&                =  5


REM *///////////////////////////////////////////////////////////////////
REM * "ErrorLevel" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrElNone&               =  1
Public Const FptrElRecoverable&        =  2
Public Const FptrElFatal&              =  3
Public Const FptrElBlocked&            =  4


REM *///////////////////////////////////////////////////////////////////
REM * "ErrorState", "PrinterState" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrPsMonitor&            =  1
Public Const FptrPsFiscalReceipt&      =  2
Public Const FptrPsFiscalReceiptTotal& =  3
Public Const FptrPsFiscalReceiptEnding& =  4
Public Const FptrPsFiscalDocument&     =  5
Public Const FptrPsFixedOutput&        =  6
Public Const FptrPsItemList&           =  7
Public Const FptrPsLocked&             =  8
Public Const FptrPsNonfiscal&          =  9
Public Const FptrPsReport&             = 10


REM *///////////////////////////////////////////////////////////////////
REM * "FiscalReceiptStation" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrRsReceipt&            =  1
Public Const FptrRsSlip&               =  2


REM *///////////////////////////////////////////////////////////////////
REM * "FiscalReceiptType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrRtCashIn&             =  1
Public Const FptrRtCashOut&            =  2
Public Const FptrRtGeneric&            =  3
Public Const FptrRtSales&              =  4
Public Const FptrRtService&            =  5
Public Const FptrRtSimpleInvoice&      =  6


REM *///////////////////////////////////////////////////////////////////
REM * "MessageType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrMtAdvance&                =   1
Public Const FptrMtAdvancePaid&            =   2
Public Const FptrMtAmountToBePaid&         =   3
Public Const FptrMtAmountToBePaidBack&     =   4
Public Const FptrMtCard&                   =   5
Public Const FptrMtCardNumber&             =   6
Public Const FptrMtCardType&               =   7
Public Const FptrMtCash&                   =   8
Public Const FptrMtCashier&                =   9
Public Const FptrMtCashRegisterNumber&     =  10
Public Const FptrMtChange&                 =  11
Public Const FptrMtCheque&                 =  12
Public Const FptrMtClientNumber&           =  13
Public Const FptrMtClientSignature&        =  14
Public Const FptrMtCounterState&           =  15
Public Const FptrMtCreditCard&             =  16
Public Const FptrMtCurrency&               =  17
Public Const FptrMtCurrencyValue&          =  18
Public Const FptrMtDeposit&                =  19
Public Const FptrMtDepositReturned&        =  20
Public Const FptrMtDotLine&                =  21
Public Const FptrMtDriverNumb&             =  22
Public Const FptrMtEmptyLine&              =  23
Public Const FptrMtFreeText&               =  24
Public Const FptrMtFreeTextWithDayLimit&   =  25
Public Const FptrMtGivenDiscount&          =  26
Public Const FptrMtLocalCredit&            =  27
Public Const FptrMtMileageKm&              =  28
Public Const FptrMtNote&                   =  29
Public Const FptrMtPaid&                   =  30
Public Const FptrMtPayIn&                  =  31
Public Const FptrMtPointGranted&           =  32
Public Const FptrMtPointsBonus&            =  33
Public Const FptrMtPointsReceipt&          =  34
Public Const FptrMtPointsTotal&            =  35
Public Const FptrMtProfited&               =  36
Public Const FptrMtRate&                   =  37
Public Const FptrMtRegisterNumb&           =  38
Public Const FptrMtShiftNumber&            =  39
Public Const FptrMtStateOfAnAccount&       =  40
Public Const FptrMtSubscription&           =  41
Public Const FptrMtTable&                  =  42
Public Const FptrMtThankYouForLoyalty&     =  43
Public Const FptrMtTransactionNumb&        =  44
Public Const FptrMtValidTo&                =  45
Public Const FptrMtVoucher&                =  46
Public Const FptrMtVoucherPaid&            =  47
Public Const FptrMtVoucherValue&           =  48
Public Const FptrMtWithDiscount&           =  49
Public Const FptrMtWithoutUplift&          =  50


REM *///////////////////////////////////////////////////////////////////
REM * "SlipSelection" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrSsFullLength&         =  1
Public Const FptrSsValidation&         =  2


REM *///////////////////////////////////////////////////////////////////
REM * "TotalizerType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrTtDocument&           =  1
Public Const FptrTtDay&                =  2
Public Const FptrTtReceipt&            =  3
Public Const FptrTtGrand&              =  4


REM *///////////////////////////////////////////////////////////////////
REM * "GetData" Method Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrGdCurrentTotal&       =  1
Public Const FptrGdDailyTotal&         =  2
Public Const FptrGdReceiptNumber&      =  3
Public Const FptrGdRefund&             =  4
Public Const FptrGdNotPaid&            =  5
Public Const FptrGdMidVoid&            =  6
Public Const FptrGdZReport&            =  7
Public Const FptrGdGrandTotal&         =  8
Public Const FptrGdPrinterId&          =  9
Public Const FptrGdFirmware&           = 10
Public Const FptrGdRestart&            = 11
Public Const FptrGdRefundVoid&         = 12
Public Const FptrGdNumbConfigBlock&    = 13
Public Const FptrGdNumbCurrencyBlock&  = 14
Public Const FptrGdNumbHdrBlock&       = 15
Public Const FptrGdNumbResetBlock&     = 16
Public Const FptrGdNumbVatBlock&       = 17
Public Const FptrGdFiscalDoc&          = 18
Public Const FptrGdFiscalDocVoid&      = 19
Public Const FptrGdFiscalRec&          = 20
Public Const FptrGdFiscalRecVoid&      = 21
Public Const FptrGdNonfiscalDoc&       = 22
Public Const FptrGdNonfiscalDocVoid&   = 23
Public Const FptrGdNonfiscalRec&       = 24
Public Const FptrGdSimpInvoice&        = 25
Public Const FptrGdTender&             = 26
Public Const FptrGdLinecount&          = 27
Public Const FptrGdDescriptionLength&  = 28

Public Const FptrPdlCash&                 =  1
Public Const FptrPdlCheque&               =  2
Public Const FptrPdlChitty&               =  3
Public Const FptrPdlCoupon&               =  4
Public Const FptrPdlCurrency&             =  5
Public Const FptrPdlDrivenOff&            =  6
Public Const FptrPdlEftImprinter&         =  7
Public Const FptrPdlEftTerminal&          =  8
Public Const FptrPdlTerminalImprinter&    =  9
Public Const FptrPdlFreeGift&             = 10
Public Const FptrPdlGiro&                 = 11
Public Const FptrPdlHome&                 = 12
Public Const FptrPdlImprinterWithIssuer&  = 13
Public Const FptrPdlLocalAccount&         = 14
Public Const FptrPdlLocalAccountCard&     = 15
Public Const FptrPdlPayCard&              = 16
Public Const FptrPdlPayCardManual&        = 17
Public Const FptrPdlPrepay&               = 18
Public Const FptrPdlPumpTest&             = 19
Public Const FptrPdlShortCredit&          = 20
Public Const FptrPdlStaff&                = 21
Public Const FptrPdlVoucher&              = 22

Public Const FptrLcItem&                  =  1
Public Const FptrLcItemVoid&              =  2
Public Const FptrLcDiscount&              =  3
Public Const FptrLcDiscountVoid&          =  4
Public Const FptrLcSurcharge&             =  5
Public Const FptrLcSurchargeVoid&         =  6
Public Const FptrLcRefund&                =  7
Public Const FptrLcRefundVoid&            =  8
Public Const FptrLcSubtotalDiscount&      =  9
Public Const FptrLcSubtotalDiscountVoid&  = 10
Public Const FptrLcSubtotalSurcharge&     = 11
Public Const FptrLcSubtotalSurchargeVoid& = 12
Public Const FptrLcComment&               = 13
Public Const FptrLcSubtotal&              = 14
Public Const FptrLcTotal&                 = 15

Public Const FptrDlItem&                  =  1
Public Const FptrDlItemAdjustment&        =  2
Public Const FptrDlItemFuel&              =  3
Public Const FptrDlItemFuelVoid&          =  4
Public Const FptrDlNotPaid&               =  5
Public Const FptrDlPackageAdjustment&     =  6
Public Const FptrDlRefund&                =  7
Public Const FptrDlRefundVoid&            =  8
Public Const FptrDlSubtotalAdjustment&    =  9
Public Const FptrDlTotal&                 = 10
Public Const FptrDlVoid&                  = 11
Public Const FptrDlVoidItem&              = 12


REM *///////////////////////////////////////////////////////////////////
REM * "GetTotalizer" Method Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrGtGross&                   =  1
Public Const FptrGtNet&                     =  2
Public Const FptrGtDiscount&                =  3
Public Const FptrGtDiscountVoid&            =  4
Public Const FptrGtItem&                    =  5
Public Const FptrGtItemVoid&                =  6
Public Const FptrGtNotPaid&                 =  7
Public Const FptrGtRefund&                  =  8
Public Const FptrGtRefundVoid&              =  9
Public Const FptrGtSubtotalDiscount&        =  10
Public Const FptrGtSubtotalDiscountVoid&    =  11
Public Const FptrGtSubtotalSurcharges&      =  12
Public Const FptrGtSubtotalSurchargesVoid&  =  13
Public Const FptrGtSurcharges&              =  14
Public Const FptrGtSSurchargesVoid&         =  15
Public Const FptrGtVat&                     =  16
Public Const FptrGtVatCategory&             =  17


REM *///////////////////////////////////////////////////////////////////
REM * "AdjustmentType" arguments in diverse methods
REM *///////////////////////////////////////////////////////////////////

Public Const FptrAtAmountDiscount&      =  1
Public Const FptrAtAmountSurcharge&     =  2
Public Const FptrAtPercentageDiscount&  =  3
Public Const FptrAtPercentageSurcharge& =  4


REM *///////////////////////////////////////////////////////////////////
REM * "ReportType" argument in "PrintReport" method
REM *///////////////////////////////////////////////////////////////////

Public Const FptrRtOrdinal&            =  1
Public Const FptrRtDate&               =  2


REM *///////////////////////////////////////////////////////////////////
REM * "NewCurrency" argument in "SetCurrency" method
REM *///////////////////////////////////////////////////////////////////

Public Const FptrScEuro&               =  1


REM *///////////////////////////////////////////////////////////////////
REM * "StatusUpdateEvent" Event: "Data" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const FptrSueCoverOpen&         =  11
Public Const FptrSueCoverOk&           =  12

Public Const FptrSueJrnEmpty&          =  21
Public Const FptrSueJrnNearempty&      =  22
Public Const FptrSueJrnPaperok&        =  23

Public Const FptrSueRecEmpty&          =  24
Public Const FptrSueRecNearempty&      =  25
Public Const FptrSueRecPaperok&        =  26

Public Const FptrSueSlpEmpty&          =  27
Public Const FptrSueSlpNearempty&      =  28
Public Const FptrSueSlpPaperok&        =  29

Public Const FptrSueIdle&              =1001


REM *///////////////////////////////////////////////////////////////////
REM * "ResultCodeExtended" Property Constants for Fiscal Printer
REM *///////////////////////////////////////////////////////////////////

Public Const OposEfptrCoverOpen&                = 201 ' (Several)
Public Const OposEfptrJrnEmpty&                 = 202 ' (Several)
Public Const OposEfptrRecEmpty&                 = 203 ' (Several)
Public Const OposEfptrSlpEmpty&                 = 204 ' (Several)
Public Const OposEfptrSlpForm&                  = 205 ' EndRemoval
Public Const OposEfptrMissingDevices&           = 206 ' (Several)
Public Const OposEfptrWrongState&               = 207 ' (Several)
Public Const OposEfptrTechnicalAssistance&      = 208 ' (Several)
Public Const OposEfptrClockError&               = 209 ' (Several)
Public Const OposEfptrFiscalMemoryFull&         = 210 ' (Several)
Public Const OposEfptrFiscalMemoryDisconnected& = 211 ' (Several)
Public Const OposEfptrFiscalTotalsError&        = 212 ' (Several)
Public Const OposEfptrBadItemQuantity&          = 213 ' (Several)
Public Const OposEfptrBadItemAmount&            = 214 ' (Several)
Public Const OposEfptrBadItemDescription&       = 215 ' (Several)
Public Const OposEfptrReceiptTotalOverflow&     = 216 ' (Several)
Public Const OposEfptrBadVat&                   = 217 ' (Several)
Public Const OposEfptrBadPrice&                 = 218 ' (Several)
Public Const OposEfptrBadDate&                  = 219 ' (Several)
Public Const OposEfptrNegativeTotal&            = 220 ' (Several)
Public Const OposEfptrWordNotAllowed&           = 221 ' (Several)
Public Const OposEfptrBadLength&                = 222 ' (Several)
Public Const OposEfptrMissingSetCurrency&       = 223 ' (Several)




REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposKbd.h
REM *
REM *   POS Keyboard header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 96-04-22 OPOS Release 1.1                                     CRM
REM * 97-06-04 OPOS Release 1.2                                     CRM
REM *   Add "EventTypes" and "POSKeyEventType" values.
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "EventTypes" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const KbdEtDown&                =   1
Public Const KbdEtDownUp&              =   2


REM *///////////////////////////////////////////////////////////////////
REM * "POSKeyEventType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const KbdKetKeydown&            =   1
Public Const KbdKetKeyup&              =   2



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposLock.h
REM *
REM *   Keylock header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "KeyPosition" Property Constants
REM * "WaitForKeylockChange" Method: "KeyPosition" Parameter
REM * "StatusUpdateEvent" Event: "Data" Parameter
REM *///////////////////////////////////////////////////////////////////

Public Const LockKpAny&                = 0             ' WaitForKeylockChange Only
Public Const LockKpLock&               = 1
Public Const LockKpNorm&               = 2
Public Const LockKpSupr&               = 3



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposMicr.h
REM *
REM *   MICR header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "CheckType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const MicrCtPersonal&           =  1
Public Const MicrCtBusiness&           =  2
Public Const MicrCtUnknown&            = 99


REM *///////////////////////////////////////////////////////////////////
REM * "CountryCode" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const MicrCcUsa&                =  1
Public Const MicrCcCanada&             =  2
Public Const MicrCcMexico&             =  3
Public Const MicrCcUnknown&            = 99


REM *///////////////////////////////////////////////////////////////////
REM * "ResultCodeExtended" Property Constants for MICR
REM *///////////////////////////////////////////////////////////////////

Public Const OposEmicrNocheck&         = 201 ' EndInsertion
Public Const OposEmicrCheck&           = 202 ' EndRemoval



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposMsr.h
REM *
REM *   Magnetic Stripe Reader header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM * 97-06-04 OPOS Release 1.2                                     CRM
REM *   Add ErrorReportingType values.
REM * 00-09-24 OPOS Release 1.5                                     BKS
REM *   Add constants relating to Track 4 Data
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "TracksToRead" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const MsrTr1&            = 1
Public Const MsrTr2&            = 2
Public Const MsrTr3&            = 4
Public Const MsrTr4&            = 8

Public Const MsrTr12&           = MsrTr1 OR MsrTr2
Public Const MsrTr13&           = MsrTr1 OR MsrTr3
Public Const MsrTr14&           = MsrTr1 OR MsrTr4
Public Const MsrTr23&           = MsrTr2 OR MsrTr3
Public Const MsrTr24&           = MsrTr2 OR MsrTr4
Public Const MsrTr34&           = MsrTr3 OR MsrTr4

Public Const MsrTr123&          = MsrTr1 OR MsrTr2 OR MsrTr3
Public Const MsrTr124&          = MsrTr1 OR MsrTr2 OR MsrTr4
Public Const MsrTr134&          = MsrTr1 OR MsrTr3 OR MsrTr4
Public Const MsrTr234&          = MsrTr2 OR MsrTr3 OR MsrTr4

Public Const MsrTr1234&         = MsrTr1 OR MsrTr2 OR MsrTr3 OR MsrTr4


REM *///////////////////////////////////////////////////////////////////
REM * "ErrorReportingType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const MsrErtCard&               = 0
Public Const MsrErtTrack&              = 1


REM *///////////////////////////////////////////////////////////////////
REM * "ErrorEvent" Event: "ResultCodeExtended" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposEmsrStart&            = 201
Public Const OposEmsrEnd&              = 202
Public Const OposEmsrParity&           = 203
Public Const OposEmsrLrc&              = 204


REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposPcrw.H
REM *
REM *   Point Card Reader Writer header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 00-09-24 OPOS Release 1.5                                     BKS
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "CapCharacterSet" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PcrwCcsAlpha&         = 1
Public Const PcrwCcsAscii&         = 998
Public Const PcrwCcsKana&          = 10
Public Const PcrwCcsKanji&         = 11
Public Const PcrwCcsUnicode&       = 997


REM *///////////////////////////////////////////////////////////////////
REM * "CardState" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PcrwStateNocard&      = 1
Public Const PcrwStateRemaining&   = 2
Public Const PcrwStateInrw&        = 4


REM *///////////////////////////////////////////////////////////////////
REM * CapTrackToRead and TrackToWrite Property constants
REM *///////////////////////////////////////////////////////////////////

Public Const PcrwTrack1&           = &H0001
Public Const PcrwTrack2&           = &H0002
Public Const PcrwTrack3&           = &H0004
Public Const PcrwTrack4&           = &H0008
Public Const PcrwTrack5&           = &H0010
Public Const PcrwTrack6&           = &H0020


REM *///////////////////////////////////////////////////////////////////
REM * "CharacterSet" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PcrwCsUnicode&        = 997
Public Const PcrwCsAscii&          = 998
Public Const PcrwCsWindows&        = 999


REM *///////////////////////////////////////////////////////////////////
REM * "MappingMode" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PcrwMmDots&           = 1
Public Const PcrwMmTwips&          = 2
Public Const PcrwMmEnglish&        = 3
Public Const PcrwMmMetric&         = 4


REM *///////////////////////////////////////////////////////////////////
REM * "ResultCodeExtended" Property Constants for PoinrCardR/W
REM *///////////////////////////////////////////////////////////////////

Public Const OposEpcrwRead&        = 201
Public Const OposEpcrwWrite&       = 202
Public Const OposEpcrwJam&         = 203
Public Const OposEpcrwMotor&       = 204
Public Const OposEpcrwCover&       = 205
Public Const OposEpcrwPrinter&     = 206
Public Const OposEpcrwRelease&     = 207
Public Const OposEpcrwDisplay&     = 208
Public Const OposEpcrwNocard&      = 209


REM *///////////////////////////////////////////////////////////////////
REM * Magnetic read/write status Property Constants for PoinrCardR/W
REM *///////////////////////////////////////////////////////////////////

Public Const OposEpcrwStart&       = 211
Public Const OposEpcrwEnd&         = 212
Public Const OposEpcrwParity&      = 213
Public Const OposEpcrwEncode&      = 214
Public Const OposEpcrwLrc&         = 215
Public Const OposEpcrwVerify&      = 216


REM *///////////////////////////////////////////////////////////////////
REM * "RotatedPrint" Method: "Rotation" Parameter Constants
REM * "RotateSpecial" Property Constants (PCRWRPNORMALASYNC not legal)
REM *///////////////////////////////////////////////////////////////////

Public Const PcrwRpNormal&         = &H0001
Public Const PcrwRpNormalasync&    = &H0002

Public Const PcrwRpRight90&        = &H0101
Public Const PcrwRpLeft90&         = &H0102
Public Const PcrwRpRotate180&      = &H0103


REM *///////////////////////////////////////////////////////////////////
REM * "StatusUpdateEvent" "Status" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PcrwSueNocard&        = 1
Public Const PcrwSueRemaining&     = 2
Public Const PcrwSueInrw&          = 4


REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposPpad.h
REM *
REM *   PIN Pad header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 98-03-06 OPOS Release 1.3                                     JDB
REM * 00-09-24 OPOS Release 1.5                                     BKS
REM *   Add PpadDispNone for devices with no display
REM *   Add OposEppadBadKey extended result code
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "CapDisplay" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PpadDispUnrestricted&     = 1
Public Const PpadDispPinrestricted&    = 2
Public Const PpadDispRestrictedList&   = 3
Public Const PpadDispRestrictedOrder&  = 4
Public Const PpadDispNone&             = 5


REM *///////////////////////////////////////////////////////////////////
REM * "AvailablePromptsList" and "Prompt" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PpadMsgEnterpin&          = 1
Public Const PpadMsgPleasewait&        = 2
Public Const PpadMsgEntervalidpin&     = 3
Public Const PpadMsgRetriesexceeded&   = 4
Public Const PpadMsgApproved&          = 5
Public Const PpadMsgDeclined&          = 6
Public Const PpadMsgCanceled&          = 7
Public Const PpadMsgAmountok&          = 8
Public Const PpadMsgNotready&          = 9
Public Const PpadMsgIdle&              = 10
Public Const PpadMsgSlideCard&         = 11
Public Const PpadMsgInsertcard&        = 12
Public Const PpadMsgSelectcardtype&    = 13


REM *///////////////////////////////////////////////////////////////////
REM * "CapLanguage" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PpadLangNone&             = 1
Public Const PpadLangOne&              = 2
Public Const PpadLangPinrestricted&    = 3
Public Const PpadLangUnrestricted&     = 4


REM *///////////////////////////////////////////////////////////////////
REM * "TransactionType" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PpadTransDebit&           = 1
Public Const PpadTransCredit&          = 2
Public Const PpadTransInq&             = 3
Public Const PpadTransReconcile&       = 4
Public Const PpadTransAdmin&           = 5


REM *///////////////////////////////////////////////////////////////////
REM * "EndEFTTransaction" Method Completion Code Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PpadEftNormal&            = 1
Public Const PpadEftAbnormal&          = 2


REM *///////////////////////////////////////////////////////////////////
REM * "DataEvent" Event Status Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PpadSuccess&              = 1
Public Const PpadCancel&               = 2


REM *///////////////////////////////////////////////////////////////////
REM * "ResultCodeExtended" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const OposEppadBadKey           = 201


REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposPtr.h
REM *
REM *   POS Printer header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM * 96-04-22 OPOS Release 1.1                                     CRM
REM *   Add CapCharacterSet values.
REM *   Add ErrorLevel values.
REM *   Add TransactionPrint Control values.
REM * 97-06-04 OPOS Release 1.2                                     CRM
REM *   Remove PTR_RP_NORMAL_ASYNC.
REM *   Add more barcode symbologies.
REM * 98-03-06 OPOS Release 1.3                                     CRM
REM *   Add more PrintTwoNormal constants.
REM * 00-09-24 OPOS Release 1.5                                   EPSON
REM *   Add CapRecMarkFeed values and MarkFeed constants.
REM *   Add ChangePrintSide constants.
REM *   Add StatusUpdateEvent constants.
REM *   Add ResultCodeExtended values.
REM *   Add CapXxxCartridgeSensor and XxxCartridgeState values.
REM *   Add CartridgeNotify values.
REM * 00-09-24 OPOS Release 1.5                                     BKS
REM *   Add CapCharacterset and CharacterSet values for UNICODE.
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * Printer Station Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrSJournal&              = 1
Public Const PtrSReceipt&              = 2
Public Const PtrSSlip&                 = 4

Public Const PtrSJournalReceipt&       = PtrSJournal OR PtrSReceipt
Public Const PtrSJournalSlip&          = PtrSJournal OR PtrSSlip
Public Const PtrSReceiptSlip&          = PtrSReceipt OR PtrSSlip

Public Const PtrTwoReceiptJournal&     = &H8000& + PtrSJournalReceipt
Public Const PtrTwoSlipJournal&        = &H8000& + PtrSJournalSlip
Public Const PtrTwoSlipReceipt&        = &H8000& + PtrSReceiptSlip


REM *///////////////////////////////////////////////////////////////////
REM * "CapCharacterSet" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrCcsAlpha&              =   1
Public Const PtrCcsAscii&              = 998
Public Const PtrCcsKana&               =  10
Public Const PtrCcsKanji&              =  11
Public Const PtrCcsUnicode&            = 997


REM *///////////////////////////////////////////////////////////////////
REM * "CharacterSet" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrCsUnicode&             = 997
Public Const PtrCsAscii&               = 998
Public Const PtrCsWindows&             = 999


REM *///////////////////////////////////////////////////////////////////
REM * "ErrorLevel" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrElNone&                = 1
Public Const PtrElRecoverable&         = 2
Public Const PtrElFatal&               = 3


REM *///////////////////////////////////////////////////////////////////
REM * "MapMode" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrMmDots&                = 1
Public Const PtrMmTwips&               = 2
Public Const PtrMmEnglish&             = 3
Public Const PtrMmMetric&              = 4


REM *///////////////////////////////////////////////////////////////////
REM * "CapXxxColor" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrColorPrimary           = &H00000001
Public Const PtrColorCustom1           = &H00000002
Public Const PtrColorCustom2           = &H00000004
Public Const PtrColorCustom3           = &H00000008
Public Const PtrColorCustom4           = &H00000010
Public Const PtrColorCustom5           = &H00000020
Public Const PtrColorCustom6           = &H00000040
Public Const PtrColorCyan              = &H00000100
Public Const PtrColorMagenta           = &H00000200
Public Const PtrColorYellow            = &H00000400
Public Const PtrColorFull              = &H80000000

REM *///////////////////////////////////////////////////////////////////
REM * "CapXxxCartridgeSensor" and  "XxxCartridgeState" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrCartUnknown            = &H10000000
Public Const PtrCartOk                 = &H00000000
Public Const PtrCartRemoved            = &H00000001
Public Const PtrCartEmpty              = &H00000002
Public Const PtrCartNearend            = &H00000004
Public Const PtrCartCleaning           = &H00000008

REM *///////////////////////////////////////////////////////////////////
REM * "CartridgeNotify"  Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrCnDisabled             = &H00000000
Public Const PtrCnEnabled              = &H00000001


REM *///////////////////////////////////////////////////////////////////
REM * "CutPaper" Method Constant
REM *///////////////////////////////////////////////////////////////////

Public Const PtrCpFullcut&             = 100


REM *///////////////////////////////////////////////////////////////////
REM * "PrintBarCode" Method Constants:
REM *///////////////////////////////////////////////////////////////////

REM *   "Alignment" Parameter
REM *     Either the distance from the left-most print column to the start
REM *     of the bar code, or one of the following:

Public Const PtrBcLeft&                = -1
Public Const PtrBcCenter&              = -2
Public Const PtrBcRight&               = -3

REM *   "TextPosition" Parameter

Public Const PtrBcTextNone&            = -11
Public Const PtrBcTextAbove&           = -12
Public Const PtrBcTextBelow&           = -13

REM *   "Symbology" Parameter:

REM *     One dimensional symbologies
Public Const PtrBcsUpca&               = 101           ' Digits
Public Const PtrBcsUpce&               = 102           ' Digits
Public Const PtrBcsJan8&               = 103           ' = EAN 8
Public Const PtrBcsEan8&               = 103           ' = JAN 8 (added in 1.2)
Public Const PtrBcsJan13&              = 104           ' = EAN 13
Public Const PtrBcsEan13&              = 104           ' = JAN 13 (added in 1.2)
Public Const PtrBcsTf&                 = 105           ' (Discrete 2 of 5) Digits
Public Const PtrBcsItf&                = 106           ' (Interleaved 2 of 5) Digits
Public Const PtrBcsCodabar&            = 107           ' Digits, -, $, :, /, ., +;
                                                       '   4 start/stop characters
                                                       '   (a, b, c, d)
Public Const PtrBcsCode39&             = 108           ' Alpha, Digits, Space, -, .,
                                                       '   $, /, +, %; start/stop (*)
                                                       ' Also has Full ASCII feature
Public Const PtrBcsCode93&             = 109           ' Same characters as Code 39
Public Const PtrBcsCode128&            = 110           ' 128 data characters
REM *        (The following were added in Release 1.2)
Public Const PtrBcsUpcaS&              = 111           ' UPC-A with supplemental
                                                       '   barcode
Public Const PtrBcsUpceS&              = 112           ' UPC-E with supplemental
                                                       '   barcode
Public Const PtrBcsUpcd1&              = 113           ' UPC-D1
Public Const PtrBcsUpcd2&              = 114           ' UPC-D2
Public Const PtrBcsUpcd3&              = 115           ' UPC-D3
Public Const PtrBcsUpcd4&              = 116           ' UPC-D4
Public Const PtrBcsUpcd5&              = 117           ' UPC-D5
Public Const PtrBcsEan8S&              = 118           ' EAN 8 with supplemental
                                                       '   barcode
Public Const PtrBcsEan13S&             = 119           ' EAN 13 with supplemental
                                                       '   barcode
Public Const PtrBcsEan128&             = 120           ' EAN 128
Public Const PtrBcsOcra&               = 121           ' OCR "A"
Public Const PtrBcsOcrb&               = 122           ' OCR "B"


REM *     Two dimensional symbologies
Public Const PtrBcsPdf417&             = 201
Public Const PtrBcsMaxicode&           = 202

REM *     Start of Printer-Specific bar code symbologies
Public Const PtrBcsOther&              = 501


REM *///////////////////////////////////////////////////////////////////
REM * "PrintBitmap" Method Constants:
REM *///////////////////////////////////////////////////////////////////

REM *   "Width" Parameter
REM *     Either bitmap width or:

Public Const PtrBmAsis&                = -11           ' One pixel per printer dot

REM *   "Alignment" Parameter
REM *     Either the distance from the left-most print column to the start
REM *     of the bitmap, or one of the following:

Public Const PtrBmLeft&                = -1
Public Const PtrBmCenter&              = -2
Public Const PtrBmRight&               = -3


REM *///////////////////////////////////////////////////////////////////
REM * "RotatePrint" Method: "Rotation" Parameter Constants
REM * "RotateSpecial" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrRpNormal&              = &H0001
Public Const PtrRpRight90&             = &H0101
Public Const PtrRpLeft90&              = &H0102
Public Const PtrRpRotate180&           = &H0103


REM *///////////////////////////////////////////////////////////////////
REM * "SetLogo" Method: "Location" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrLTop&                  = 1
Public Const PtrLBottom&               = 2


REM *///////////////////////////////////////////////////////////////////
REM * "TransactionPrint" Method: "Control" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrTpTransaction&         = 11
Public Const PtrTpNormal&              = 12


REM *///////////////////////////////////////////////////////////////////
REM * "MarkFeed" Method: "Type" Parameter Constants
REM * "CapRecMarkFeed" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrMfToTakeup             = 1
Public Const PtrMfToCutter             = 2
Public Const PtrMfToCurrentTof         = 4
Public Const PtrMfToNextTof            = 8

REM *///////////////////////////////////////////////////////////////////
REM * "ChangePrintSide" Method: "Side" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrPsUnknown              = 0
Public Const PtrPsSide1                = 1
Public Const PtrPsSide2                = 2
Public Const PtrPsOpposite             = 3


REM *///////////////////////////////////////////////////////////////////
REM * "StatusUpdateEvent" Event: "Data" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PtrSueCoverOpen&          =   11
Public Const PtrSueCoverOk&            =   12

Public Const PtrSueJrnEmpty&           =   21
Public Const PtrSueJrnNearempty&       =   22
Public Const PtrSueJrnPaperok&         =   23

Public Const PtrSueRecEmpty&           =   24
Public Const PtrSueRecNearempty&       =   25
Public Const PtrSueRecPaperok&         =   26

Public Const PtrSueSlpEmpty&           =   27
Public Const PtrSueSlpNearempty&       =   28
Public Const PtrSueSlpPaperok&         =   29

Public Const PtrSueJrnCartridgeEmpty     = 41
Public Const PtrSueJrnCartridgeNearempty = 42
Public Const PtrSueJrnHeadCleaning       = 43
Public Const PtrSueJrnCartridgeOk        = 44

Public Const PtrSueRecCartridgeEmpty     = 45
Public Const PtrSueRecCartridgeNearempty = 46
Public Const PtrSueRecHeadCleaning       = 47
Public Const PtrSueRecCartridgeOk        = 48

Public Const PtrSueSlpCartridgeEmpty     = 49
Public Const PtrSueSlpCartridgeNearempty = 50
Public Const PtrSueSlpHeadCleaning       = 51
Public Const PtrSueSlpCartridgeOk        = 52

Public Const PtrSueIdle&               = 1001


REM *///////////////////////////////////////////////////////////////////
REM * "ResultCodeExtended" Property Constants for Printer
REM *///////////////////////////////////////////////////////////////////

Public Const OposEptrCoverOpen&          = 201 ' (Several)
Public Const OposEptrJrnEmpty&           = 202 ' (Several)
Public Const OposEptrRecEmpty&           = 203 ' (Several)
Public Const OposEptrSlpEmpty&           = 204 ' (Several)
Public Const OposEptrSlpForm&            = 205 ' EndRemoval
Public Const OposEptrToobig&             = 206 ' PrintBitmap
Public Const OposEptrBadformat&          = 207 ' PrintBitmap
Public Const OposEptrJrnCartridgeRemoved = 208 ' (Several)
Public Const OposEptrJrnCartridgeEmpty   = 209 ' (Several)
Public Const OposEptrJrnHeadCleaning     = 210 ' (Several)
Public Const OposEptrRecCartridgeRemoved = 211 ' (Several)
Public Const OposEptrRecCartridgeEmpty   = 212 ' (Several)
Public Const OposEptrRecHeadCleaning     = 213 ' (Several)
Public Const OposEptrSlpCartridgeRemoved = 214 ' (Several)
Public Const OposEptrSlpCartridgeEmpty   = 215 ' (Several)
Public Const OposEptrSlpHeadCleaning     = 216 ' (Several)



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposPwr.h
REM *
REM *   POSPower header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 99-02-22 OPOS Release 1.x                                     AL
REM * 99-09-13 OPOS Release 1.x                                     TH
REM *            ACCU -> UPS, FAN_ALARM and HEAT_ALARM added
REM * 99-12-06 OPOS Release 1.x                                     TH
REM *            FAN_ALARM and HEAT_ALARM changed to FAN_STOPPED,
REM *          FAN_RUNNING, TEMPERATURE_HIGH and TEMPERATURE_OK
REM * 00-09-24 OPOS Release 1.5                                     TH
REM *          SHUTDOWN added
REM *
REM *///////////////////////////////////////////////////////////////////

REM *///////////////////////////////////////////////////////////////////
REM * "UPSChargeState" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const PwrUpsFull        = 1
Public Const PwrUpsWarning     = 2
Public Const PwrUpsLow         = 4
Public Const PwrUpsCritical    = 8


REM *///////////////////////////////////////////////////////////////////
REM * "StatusUpdateEvent" Event: "Status" Parameter
REM *///////////////////////////////////////////////////////////////////

Public Const PwrSueUpsFull            = 11
Public Const PwrSueUpsWarning         = 12
Public Const PwrSueUpsLow             = 13
Public Const PwrSueUpsCritical        = 14
Public Const PwrSueFanStopped         = 15
Public Const PwrSueFanRunning         = 16
Public Const PwrSueTemperatureHigh    = 17
Public Const PwrSueTemperatureOk      = 18
Public Const PwrSueShutdown           = 19



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposRod.h
REM *
REM *   Remote Order Display header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 98-03-06 OPOS Release 1.3                                     BB
REM * 00-09-24 OPOS Release 1.5                                    BKS
REM *   Added CharacterSet value for UNICODE.
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "CurrentUnitID" and "UnitsOnline" Properties
REM *  and "Units" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const RodUid1&                  = &H00000001
Public Const RodUid2&                  = &H00000002
Public Const RodUid3&                  = &H00000004
Public Const RodUid4&                  = &H00000008
Public Const RodUid5&                  = &H00000010
Public Const RodUid6&                  = &H00000020
Public Const RodUid7&                  = &H00000040
Public Const RodUid8&                  = &H00000080
Public Const RodUid9&                  = &H00000100
Public Const RodUid10&                 = &H00000200
Public Const RodUid11&                 = &H00000400
Public Const RodUid12&                 = &H00000800
Public Const RodUid13&                 = &H00001000
Public Const RodUid14&                 = &H00002000
Public Const RodUid15&                 = &H00004000
Public Const RodUid16&                 = &H00008000
Public Const RodUid17&                 = &H00010000
Public Const RodUid18&                 = &H00020000
Public Const RodUid19&                 = &H00040000
Public Const RodUid20&                 = &H00080000
Public Const RodUid21&                 = &H00100000
Public Const RodUid22&                 = &H00200000
Public Const RodUid23&                 = &H00400000
Public Const RodUid24&                 = &H00800000
Public Const RodUid25&                 = &H01000000
Public Const RodUid26&                 = &H02000000
Public Const RodUid27&                 = &H04000000
Public Const RodUid28&                 = &H08000000
Public Const RodUid29&                 = &H10000000
Public Const RodUid30&                 = &H20000000
Public Const RodUid31&                 = &H40000000
Public Const RodUid32&                 = &H80000000


REM *///////////////////////////////////////////////////////////////////
REM * Broadcast Methods: "Attribute" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const RodAttrBlink&             = &H80

Public Const RodAttrBgBlack&           = &H00
Public Const RodAttrBgBlue&            = &H10
Public Const RodAttrBgGreen&           = &H20
Public Const RodAttrBgCyan&            = &H30
Public Const RodAttrBgRed&             = &H40
Public Const RodAttrBgMagenta&         = &H50
Public Const RodAttrBgBrown&           = &H60
Public Const RodAttrBgGray&            = &H70

Public Const RodAttrIntensity&         = &H08

Public Const RodAttrFgBlack&           = &H00
Public Const RodAttrFgBlue&            = &H01
Public Const RodAttrFgGreen&           = &H02
Public Const RodAttrFgCyan&            = &H03
Public Const RodAttrFgRed&             = &H04
Public Const RodAttrFgMagenta&         = &H05
Public Const RodAttrFgBrown&           = &H06
Public Const RodAttrFgGray&            = &H07


REM *///////////////////////////////////////////////////////////////////
REM * "DrawBox" Method: "BorderType" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const RodBdrSingle&             = 1
Public Const RodBdrDouble&             = 2
Public Const RodBdrSolid&              = 3


REM *///////////////////////////////////////////////////////////////////
REM * "ControlClock" Method: "Function" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const RodClkStart&              = 1
Public Const RodClkPause&              = 2
Public Const RodClkResume&             = 3
Public Const RodClkMove&               = 4
Public Const RodClkStop&               = 5


REM *///////////////////////////////////////////////////////////////////
REM * "ControlCursor" Method: "Function" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const RodCrsLine&               = 1
Public Const RodCrsLineBlink&          = 2
Public Const RodCrsBlock&              = 3
Public Const RodCrsBlockBlink&         = 4
Public Const RodCrsOff&                = 5


REM *///////////////////////////////////////////////////////////////////
REM * "SelectCharacterSet" Method: "CharacterSet" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const RodCsUnicode&             = 997
Public Const RodCsAscii&               = 998
Public Const RodCsWindows&             = 999


REM *///////////////////////////////////////////////////////////////////
REM * "TransactionDisplay" Method: "Function" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const RodTdTransaction&         = 11
Public Const RodTdNormal&              = 12


REM *///////////////////////////////////////////////////////////////////
REM * "UpdateVideoRegionAttribute" Method: "Function" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const RodUaSet&                 = 1
Public Const RodUaIntensityOn&         = 2
Public Const RodUaIntensityOff&        = 3
Public Const RodUaReverseOn&           = 4
Public Const RodUaReverseOff&          = 5
Public Const RodUaBlinkOn&             = 6
Public Const RodUaBlinkOff&            = 7


REM *///////////////////////////////////////////////////////////////////
REM * "EventTypes" Property and "DataEvent" Event: "Status" Parameter Constants
REM *///////////////////////////////////////////////////////////////////

Public Const RodDeTouchUp&             = &H01
Public Const RodDeTouchDown&           = &H02
Public Const RodDeTouchMove&           = &H04


REM *///////////////////////////////////////////////////////////////////
REM * "ResultCodeExtended" Property Constants for Remote Order Display
REM *///////////////////////////////////////////////////////////////////

Public Const OposErodBadclk&           = 201 ' ControlClock
Public Const OposErodNoclocks&         = 202 ' ControlClock
Public Const OposErodNoregion&         = 203 ' RestoreVideoRegion
Public Const OposErodNobuffers&        = 204 ' SaveVideoRegion
Public Const OposErodNoroom&           = 205 ' SaveVideoRegion



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposScal.h
REM *
REM *   Scale header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "WeightUnit" Property Constants
REM *///////////////////////////////////////////////////////////////////

Public Const ScalWuGram&               = 1
Public Const ScalWuKilogram&           = 2
Public Const ScalWuOunce&              = 3
Public Const ScalWuPound&              = 4


REM *///////////////////////////////////////////////////////////////////
REM * "ResultCodeExtended" Property Constants for Scale
REM *///////////////////////////////////////////////////////////////////

Public Const OposEscalOverweight&      = 201 ' ReadWeight



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposScan.h
REM *
REM *   Scanner header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM * 97-06-04 OPOS Release 1.2                                     CRM
REM *   Add "ScanDataType" values.
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "ScanDataType" Property Constants
REM *///////////////////////////////////////////////////////////////////

REM * One dimensional symbologies
Public Const ScanSdtUpca&              = 101           ' Digits
Public Const ScanSdtUpce&              = 102           ' Digits
Public Const ScanSdtJan8&              = 103           ' = EAN 8
Public Const ScanSdtEan8&              = 103           ' = JAN 8 (added in 1.2)
Public Const ScanSdtJan13&             = 104           ' = EAN 13
Public Const ScanSdtEan13&             = 104           ' = JAN 13 (added in 1.2)
Public Const ScanSdtTf&                = 105           ' (Discrete 2 of 5) Digits
Public Const ScanSdtItf&               = 106           ' (Interleaved 2 of 5) Digits
Public Const ScanSdtCodabar&           = 107           ' Digits, -, $, :, /, ., +;
                                                       '   4 start/stop characters
                                                       '   (a, b, c, d)
Public Const ScanSdtCode39&            = 108           ' Alpha, Digits, Space, -, .,
                                                       '   $, /, +, %; start/stop (*)
                                                       ' Also has Full ASCII feature
Public Const ScanSdtCode93&            = 109           ' Same characters as Code 39
Public Const ScanSdtCode128&           = 110           ' 128 data characters

Public Const ScanSdtUpcaS&             = 111           ' UPC-A with supplemental
                                                       '   barcode
Public Const ScanSdtUpceS&             = 112           ' UPC-E with supplemental
                                                       '   barcode
Public Const ScanSdtUpcd1&             = 113           ' UPC-D1
Public Const ScanSdtUpcd2&             = 114           ' UPC-D2
Public Const ScanSdtUpcd3&             = 115           ' UPC-D3
Public Const ScanSdtUpcd4&             = 116           ' UPC-D4
Public Const ScanSdtUpcd5&             = 117           ' UPC-D5
Public Const ScanSdtEan8S&             = 118           ' EAN 8 with supplemental
                                                       '   barcode
Public Const ScanSdtEan13S&            = 119           ' EAN 13 with supplemental
                                                       '   barcode
Public Const ScanSdtEan128&            = 120           ' EAN 128
Public Const ScanSdtOcra&              = 121           ' OCR "A"
Public Const ScanSdtOcrb&              = 122           ' OCR "B"

REM * Two dimensional symbologies
Public Const ScanSdtPdf417&            = 201
Public Const ScanSdtMaxicode&          = 202

REM * Special cases
Public Const ScanSdtOther&             = 501           ' Start of Scanner-Specific bar
                                                       '   code symbologies
Public Const ScanSdtUnknown&           =   0           ' Cannot determine the barcode
                                                       '   symbology.



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposSig.h
REM *
REM *   Signature Capture header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM *
REM *///////////////////////////////////////////////////////////////////


REM * No definitions required for this version.



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposTone.h
REM *
REM *   Tone Indicator header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 97-06-04 OPOS Release 1.2                                     CRM
REM *
REM *///////////////////////////////////////////////////////////////////


REM * No definitions required for this version.



REM *///////////////////////////////////////////////////////////////////
REM *
REM * OposTot.h
REM *
REM *   Hard Totals header file for OPOS Applications.
REM *
REM * Modification history
REM * ------------------------------------------------------------------
REM * 95-12-08 OPOS Release 1.0                                     CRM
REM *
REM *///////////////////////////////////////////////////////////////////


REM *///////////////////////////////////////////////////////////////////
REM * "ResultCodeExtended" Property Constants for Hard Totals
REM *///////////////////////////////////////////////////////////////////

Public Const OposEtotNoroom&           = 201 ' Create, Write
Public Const OposEtotValidation&       = 202 ' Read, Write



REM *End of OPOSALL.BAS*
