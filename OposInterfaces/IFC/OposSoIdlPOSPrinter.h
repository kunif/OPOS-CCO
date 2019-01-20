//*************************************************************************
//** OPOS POSPrinter SO Interface
//*************************************************************************

[
    uuid(CCBE0150-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSPOSPrinterSO 1.15 Interface")
]
dispinterface IOPOSPOSPrinterSO
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
        [id(81)] LONG BeginInsertion([in] LONG Timeout);
        [id(82)] LONG BeginRemoval([in] LONG Timeout);
        [id(83)] LONG ChangePrintSide([in] LONG Side);
        [id(84)] LONG ClearPrintArea(void);
        [id(85)] LONG CutPaper([in] LONG Percentage);
        [id(86)] LONG DrawRuledLine([in] LONG Station, [in] BSTR PositionList, [in] LONG LineDirection, [in] LONG LineWidth, [in] LONG LineStyle, [in] LONG LineColor);
        [id(87)] LONG EndInsertion(void);
        [id(88)] LONG EndRemoval(void);
        [id(89)] LONG MarkFeed([in] LONG Type);
        [id(90)] LONG PageModePrint([in] LONG Control);
        [id(91)] LONG PrintBarCode([in] LONG Station, [in] BSTR Data, [in] LONG Symbology, [in] LONG Height, [in] LONG Width, [in] LONG Alignment, [in] LONG TextPosition);
        [id(92)] LONG PrintBitmap([in] LONG Station, [in] BSTR FileName, [in] LONG Width, [in] LONG Alignment);
        [id(93)] LONG PrintImmediate([in] LONG Station, [in] BSTR Data);
        [id(94)] LONG PrintMemoryBitmap([in] LONG Station, [in] BSTR Data, [in] LONG Type, [in] LONG Width, [in] LONG Alignment);
        [id(95)] LONG PrintNormal([in] LONG Station, [in] BSTR Data);
        [id(96)] LONG PrintTwoNormal([in] LONG Stations, [in] BSTR Data1, [in] BSTR Data2);
        [id(97)] LONG RotatePrint([in] LONG Station, [in] LONG Rotation);
        [id(98)] LONG SetBitmap([in] LONG BitmapNumber, [in] LONG Station, [in] BSTR FileName, [in] LONG Width, [in] LONG Alignment);
        [id(99)] LONG SetLogo([in] LONG Location, [in] BSTR Data);
        [id(100)] LONG TransactionPrint([in] LONG Station, [in] LONG Control);
        [id(101)] LONG ValidateData([in] LONG Station, [in] BSTR Data);
};
