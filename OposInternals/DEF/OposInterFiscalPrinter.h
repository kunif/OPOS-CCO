//*************************************************************************
//** OPOS FiscalPrinter Internals
//
//   Fiscal Printer header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS FiscalPrinter Internals")]
enum
{
    PIDXFptr_AmountDecimalPlaces = 16001,
    PIDXFptr_AsyncMode           = 16002,
    PIDXFptr_CheckTotal          = 16003,
    PIDXFptr_CountryCode         = 16004,
    PIDXFptr_CoverOpen           = 16005,
    PIDXFptr_DayOpened           = 16006,
    PIDXFptr_DescriptionLength   = 16007,
    PIDXFptr_DuplicateReceipt    = 16008,
    PIDXFptr_ErrorLevel          = 16009,
    PIDXFptr_ErrorOutID          = 16010,
    PIDXFptr_ErrorState          = 16011,
    PIDXFptr_ErrorStation        = 16012,
    PIDXFptr_FlagWhenIdle        = 16013,
    PIDXFptr_JrnEmpty            = 16014,
    PIDXFptr_JrnNearEnd          = 16015,
    PIDXFptr_MessageLength       = 16016,
    PIDXFptr_NumHeaderLines      = 16017,
    PIDXFptr_NumTrailerLines     = 16018,
    PIDXFptr_NumVatRates         = 16019,
    PIDXFptr_PrinterState        = 16020,
    PIDXFptr_QuantityDecimalPlaces=16021,
    PIDXFptr_QuantityLength      = 16022,
    PIDXFptr_RecEmpty            = 16023,
    PIDXFptr_RecNearEnd          = 16024,
    PIDXFptr_RemainingFiscalMemory=16025,
    PIDXFptr_SlpEmpty            = 16026,
    PIDXFptr_SlpNearEnd          = 16027,
    PIDXFptr_SlipSelection       = 16028,
    PIDXFptr_TrainingModeActive  = 16029,
    PIDXFptr_ActualCurrency      = 16030,
    PIDXFptr_ContractorId        = 16031,
    PIDXFptr_DateType            = 16032,
    PIDXFptr_FiscalReceiptStation= 16033,
    PIDXFptr_FiscalReceiptType   = 16034,
    PIDXFptr_MessageType         = 16035,
    PIDXFptr_TotalizerType       = 16036,

    PIDXFptr_CapAdditionalLines  = 16501,
    PIDXFptr_CapAmountAdjustment = 16502,
    PIDXFptr_CapAmountNotPaid    = 16503,
    PIDXFptr_CapCheckTotal       = 16504,
    PIDXFptr_CapCoverSensor      = 16505,
    PIDXFptr_CapDoubleWidth      = 16506,
    PIDXFptr_CapDuplicateReceipt = 16507,
    PIDXFptr_CapFixedOutput      = 16508,
    PIDXFptr_CapHasVatTable      = 16509,
    PIDXFptr_CapIndependentHeader= 16510,
    PIDXFptr_CapItemList         = 16511,
    PIDXFptr_CapJrnEmptySensor   = 16512,
    PIDXFptr_CapJrnNearEndSensor = 16513,
    PIDXFptr_CapJrnPresent       = 16514,
    PIDXFptr_CapNonFiscalMode    = 16515,
    PIDXFptr_CapOrderAdjustmentFirst
                                 = 16516,
    PIDXFptr_CapPercentAdjustment= 16517,
    PIDXFptr_CapPositiveAdjustment=16518,
    PIDXFptr_CapPowerLossReport  = 16519,
    PIDXFptr_CapPredefinedPaymentLines
                                 = 16520,
    PIDXFptr_CapReceiptNotPaid   = 16521,
    PIDXFptr_CapRecEmptySensor   = 16522,
    PIDXFptr_CapRecNearEndSensor = 16523,
    PIDXFptr_CapRecPresent       = 16524,
    PIDXFptr_CapRemainingFiscalMemory
                                 = 16525,
    PIDXFptr_CapReservedWord     = 16526,
    PIDXFptr_CapSetHeader        = 16527,
    PIDXFptr_CapSetPOSID         = 16528,
    PIDXFptr_CapSetStoreFiscalID = 16529,
    PIDXFptr_CapSetTrailer       = 16530,
    PIDXFptr_CapSetVatTable      = 16531,

    PIDXFptr_CapSlpEmptySensor   = 16532,
    PIDXFptr_CapSlpFiscalDocument= 16533,
    PIDXFptr_CapSlpFullSlip      = 16534,
    PIDXFptr_CapSlpNearEndSensor = 16535,
    PIDXFptr_CapSlpPresent       = 16536,
    PIDXFptr_CapSlpValidation    = 16537,
    PIDXFptr_CapSubAmountAdjustment
                                 = 16538,
    PIDXFptr_CapSubPercentAdjustment
                                 = 16539,
    PIDXFptr_CapSubtotal         = 16540,
    PIDXFptr_CapTrainingMode     = 16541,
    PIDXFptr_CapValidateJournal  = 16542,
    PIDXFptr_CapXReport          = 16543,
    PIDXFptr_CapAdditionalHeader = 16544,
    PIDXFptr_CapAdditionalTrailer= 16545,
    PIDXFptr_CapChangeDue        = 16546,
    PIDXFptr_CapEmptyReceiptIsVoidable
                                 = 16547,
    PIDXFptr_CapFiscalReceiptStation
                                 = 16548,
    PIDXFptr_CapFiscalReceiptType= 16549,
    PIDXFptr_CapMultiContractor  = 16550,
    PIDXFptr_CapOnlyVoidLastItem = 16551,
    PIDXFptr_CapPackageAdjustment= 16552,
    PIDXFptr_CapPostPreLine      = 16553,
    PIDXFptr_CapSetCurrency      = 16554,
    PIDXFptr_CapTotalizerType    = 16555,
    PIDXFptr_CapPositiveSubtotalAdjustment
                                 = 16556,

    PIDXFptr_ErrorString         = 16001,
    PIDXFptr_PredefinedPaymentLines
                                 = 116002,
    PIDXFptr_ReservedWord        = 116003,
    PIDXFptr_AdditionalHeader    = 116004,
    PIDXFptr_AdditionalTrailer   = 116005,
    PIDXFptr_ChangeDue           = 116006,
    PIDXFptr_PostLine            = 116007,
    PIDXFptr_PreLine             = 116008
} OPOSFiscalPrinterInternals;
