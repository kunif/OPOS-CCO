//*************************************************************************
//** OPOS FiscalPrinter SO Interface
//*************************************************************************

[
    uuid(CCBE0070-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSFiscalPrinterSO 1.15 Interface")
]
dispinterface IOPOSFiscalPrinterSO
{
    properties:
    methods:
        // Device Common Method
        [id(1)] LONG GetPropertyNumber([in] LONG PropIndex);
        [id(2)] void SetPropertyNumber([in] LONG PropIndex, [in] LONG Number);
        [id(3)] BSTR GetPropertyString([in] LONG PropIndex);
        [id(4)] void SetPropertyString([in] LONG PropIndex, [in] BSTR String);
        [id(5)] LONG OpenService([in] BSTR DeviceClass, [in] BSTR DeviceName, [in] IDispatch* pDispatch);
        [id(6)] LONG CloseService(void);
        [id(7)] LONG ClaimDevice([in] LONG Timeout);
        [id(8)] LONG ReleaseDevice(void);
        [id(9)] LONG CheckHealth([in] LONG Level);
     // [id(10)] LONG ClearInput(void);
     // [id(11)] LONG ClearInputProperties(void);
        [id(12)] LONG ClearOutput(void);
        [id(13)] LONG DirectIO([in] LONG Command, [in, out] LONG* pData, [in, out] BSTR* pString);
        [id(14)] LONG CompareFirmwareVersion([in] BSTR FirmwareFileName, [out] LONG* pResult);
        [id(15)] LONG UpdateFirmware([in] BSTR FirmwareFileName);
        [id(16)] LONG ResetStatistics([in] BSTR StatisticsBuffer);
        [id(17)] LONG RetrieveStatistics([in, out] BSTR* pStatisticsBuffer);
        [id(18)] LONG UpdateStatistics([in] BSTR StatisticsBuffer);
        [id(19)] LONG COFreezeEvents([in] VARIANT_BOOL Freeze);
        [id(20)] LONG GetOpenResult(void);

        // Device Specific Method
        [id(81)] LONG BeginFiscalDocument([in] LONG DocumentAmount);
        [id(82)] LONG BeginFiscalReceipt([in] VARIANT_BOOL PrintHeader);
        [id(83)] LONG BeginFixedOutput([in] LONG Station, [in] LONG DocumentType);
        [id(84)] LONG BeginInsertion([in] LONG Timeout);
        [id(85)] LONG BeginItemList([in] LONG VatID);
        [id(86)] LONG BeginNonFiscal(void);
        [id(87)] LONG BeginRemoval([in] LONG Timeout);
        [id(88)] LONG BeginTraining(void);
        [id(89)] LONG ClearError(void);
        [id(90)] LONG EndFiscalDocument(void);
        [id(91)] LONG EndFiscalReceipt([in] VARIANT_BOOL PrintHeader);
        [id(92)] LONG EndFixedOutput(void);
        [id(93)] LONG EndInsertion(void);
        [id(94)] LONG EndItemList(void);
        [id(95)] LONG EndNonFiscal(void);
        [id(96)] LONG EndRemoval(void);
        [id(97)] LONG EndTraining(void);
        [id(98)] LONG GetData([in] LONG DataItem, [out] LONG* OptArgs, [out] BSTR* Data);
        [id(99)] LONG GetDate([out] BSTR* Date);
        [id(100)] LONG GetTotalizer([in] LONG VatID, [in] LONG OptArgs, [out] BSTR* Data);
        [id(101)] LONG GetVatEntry([in] LONG VatID, [in] LONG OptArgs, [out] LONG* VatRate);
        [id(102)] LONG PrintDuplicateReceipt(void);
        [id(103)] LONG PrintFiscalDocumentLine([in] BSTR DocumentLine);
        [id(104)] LONG PrintFixedOutput([in] LONG DocumentType, [in] LONG LineNumber, [in] BSTR Data);
        [id(105)] LONG PrintNormal([in] LONG Station, [in] BSTR Data);
        [id(106)] LONG PrintPeriodicTotalsReport([in] BSTR Date1, [in] BSTR Date2);
        [id(107)] LONG PrintPowerLossReport(void);
        [id(108)] LONG PrintRecCash([in] CURRENCY Amount);
        [id(109)] LONG PrintRecItem([in] BSTR Description, [in] CURRENCY Price, [in] LONG Quantity, [in] LONG VatInfo, [in] CURRENCY UnitPrice, [in] BSTR UnitName);
        [id(110)] LONG PrintRecItemAdjustment([in] LONG AdjustmentType, [in] BSTR Description, [in] CURRENCY Amount, [in] LONG VatInfo);
        [id(111)] LONG PrintRecItemAdjustmentVoid([in] LONG AdjustmentType, [in] BSTR Description, [in] CURRENCY Amount, [in] LONG VatInfo);
        [id(112)] LONG PrintRecItemFuel([in] BSTR Description, [in] CURRENCY Price, [in] LONG Quantity, [in] LONG VatInfo, [in] CURRENCY UnitPrice, [in] BSTR UnitName, [in] CURRENCY SpecialTax, [in] BSTR SpecialTaxName);
        [id(113)] LONG PrintRecItemFuelVoid([in] BSTR Description, [in] CURRENCY Price, [in] LONG VatInfo, [in] CURRENCY SpecialTax);
        [id(114)] LONG PrintRecItemRefund([in] BSTR Description, [in] CURRENCY Amount, [in] LONG Quantity, [in] LONG VatInfo, [in] CURRENCY UnitAmount, [in] BSTR UnitName);
        [id(115)] LONG PrintRecItemRefundVoid([in] BSTR Description, [in] CURRENCY Amount, [in] LONG Quantity, [in] LONG VatInfo, [in] CURRENCY UnitAmount, [in] BSTR UnitName);
        [id(116)] LONG PrintRecItemVoid([in] BSTR Description, [in] CURRENCY Price, [in] LONG Quantity, [in] LONG VatInfo, [in] CURRENCY UnitPrice, [in] BSTR UnitName);
        [id(117)] LONG PrintRecMessage([in] BSTR Message);
        [id(118)] LONG PrintRecNotPaid([in] BSTR Description, [in] CURRENCY Amount);
        [id(119)] LONG PrintRecPackageAdjustment([in] LONG AdjustmentType, [in] BSTR Description, [in] BSTR VatAdjustment);
        [id(120)] LONG PrintRecPackageAdjustVoid([in] LONG AdjustmentType, [in] BSTR VatAdjustment);
        [id(121)] LONG PrintRecRefund([in] BSTR Description, [in] CURRENCY Amount, [in] LONG VatInfo);
        [id(122)] LONG PrintRecRefundVoid([in] BSTR Description, [in] CURRENCY Amount, [in] LONG VatInfo);
        [id(123)] LONG PrintRecSubtotal([in] CURRENCY Amount);
        [id(124)] LONG PrintRecSubtotalAdjustment([in] LONG AdjustmentType, [in] BSTR Description, [in] CURRENCY Amount);
        [id(125)] LONG PrintRecSubtotalAdjustVoid([in] LONG AdjustmentType, [in] CURRENCY Amount);
        [id(126)] LONG PrintRecTaxID([in] BSTR TaxID);
        [id(127)] LONG PrintRecTotal([in] CURRENCY Total, [in] CURRENCY Payment, [in] BSTR Description);
        [id(128)] LONG PrintRecVoid([in] BSTR Description);
        [id(129)] LONG PrintRecVoidItem([in] BSTR Description, [in] CURRENCY Amount, [in] LONG Quantity, [in] LONG AdjustmentType, [in] CURRENCY Adjustment, [in] LONG VatInfo);
        [id(130)] LONG PrintReport([in] LONG ReportType, [in] BSTR StartNum, [in] BSTR EndNum);
        [id(131)] LONG PrintXReport(void);
        [id(132)] LONG PrintZReport(void);
        [id(133)] LONG ResetPrinter(void);
        [id(134)] LONG SetCurrency([in] LONG NewCurrency);
        [id(135)] LONG SetDate([in] BSTR Date);
        [id(136)] LONG SetHeaderLine([in] LONG LineNumber, [in] BSTR Text, [in] VARIANT_BOOL DoubleWidth);
        [id(137)] LONG SetPOSID([in] BSTR POSID, [in] BSTR CashierID);
        [id(138)] LONG SetStoreFiscalID([in] BSTR ID);
        [id(139)] LONG SetTrailerLine([in] LONG LineNumber, [in] BSTR Text, [in] VARIANT_BOOL DoubleWidth);
        [id(140)] LONG SetVatTable(void);
        [id(141)] LONG SetVatValue([in] LONG VatID, [in] BSTR VatValue);
        [id(142)] LONG VerifyItem([in] BSTR ItemName, [in] LONG VatID);
};
