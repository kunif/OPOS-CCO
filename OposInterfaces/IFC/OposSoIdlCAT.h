//*************************************************************************
//** OPOS CAT SO Interface
//*************************************************************************

[
    uuid(CCBE0050-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSCATSO 1.16 Interface")
]
dispinterface IOPOSCATSO
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

        // Device Specific Property
        [id(49)] CURRENCY GetBalance(void);
        [id(50)] CURRENCY GetSettledAmount(void);

        // Device Specific Method
        [id(81)] LONG AccessDailyLog([in] LONG SequenceNumber, [in] LONG Type, [in] LONG Timeout);
        [id(82)] LONG AuthorizeCompletion([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(83)] LONG AuthorizePreSales([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(84)] LONG AuthorizeRefund([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(85)] LONG AuthorizeSales([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(86)] LONG AuthorizeVoid([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(87)] LONG AuthorizeVoidPreSales([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(88)] LONG CashDeposit([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] LONG Timeout);
        [id(89)] LONG CheckCard([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(90)] LONG LockTerminal(void);
        [id(91)] LONG UnlockTerminal(void);
};
