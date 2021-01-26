//*************************************************************************
//** OPOS CashChanger SO Interface
//*************************************************************************

[
    uuid(CCBE0030-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSCashChangerSO 1.16 Interface")
]
dispinterface IOPOSCashChangerSO
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
        [id(10)] LONG ClearInput(void);
     // [id(11)] LONG ClearInputProperties(void);
     // [id(12)] LONG ClearOutput(void);
        [id(13)] LONG DirectIO([in] LONG Command, [in, out] LONG* pData, [in, out] BSTR* pString);
        [id(14)] LONG CompareFirmwareVersion([in] BSTR FirmwareFileName, [out] LONG* pResult);
        [id(15)] LONG UpdateFirmware([in] BSTR FirmwareFileName);
        [id(16)] LONG ResetStatistics([in] BSTR StatisticsBuffer);
        [id(17)] LONG RetrieveStatistics([in, out] BSTR* pStatisticsBuffer);
        [id(18)] LONG UpdateStatistics([in] BSTR StatisticsBuffer);
        [id(19)] LONG COFreezeEvents([in] VARIANT_BOOL Freeze);
        [id(20)] LONG GetOpenResult(void);

        // Device Specific Method
        [id(81)] LONG AdjustCashCounts([in] BSTR CashCounts);
        [id(82)] LONG BeginDeposit(void);
        [id(83)] LONG DispenseCash([in] BSTR CashCounts);
        [id(84)] LONG DispenseChange([in] LONG Amount);
        [id(85)] LONG EndDeposit([in] LONG Success);
        [id(86)] LONG FixDeposit(void);
        [id(87)] LONG PauseDeposit([in] LONG Control);
        [id(88)] LONG ReadCashCounts([out] BSTR* pCashCounts, [out] VARIANT_BOOL* pDiscrepancy);
};
