//*************************************************************************
//** OPOS HardTotals SO Interface
//*************************************************************************

[
    uuid(CCBE0080-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSHardTotalsSO 1.15 Interface")
]
dispinterface IOPOSHardTotalsSO
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
        [id(81)] LONG BeginTrans(void);
        [id(82)] LONG ClaimFile([in] LONG HTotalsFile, [in] LONG Timeout);
        [id(83)] LONG CommitTrans(void);
        [id(84)] LONG Create([in] BSTR FileName, [out] LONG* pHTotalsFile, [in] LONG Size, [in] VARIANT_BOOL ErrorDetection);
        [id(85)] LONG Delete([in] BSTR FileName);
        [id(86)] LONG Find([in] BSTR FileName, [out] LONG* pHTotalsFile, [out] LONG* pSize);
        [id(87)] LONG FindByIndex([in] LONG Index, [out] BSTR* pFileName);
        [id(88)] LONG Read([in] LONG HTotalsFile, [out] BSTR* pData, [in] LONG Offset, [in] LONG Count);
        [id(89)] LONG RecalculateValidationData([in] LONG HTotalsFile);
        [id(90)] LONG ReleaseFile([in] LONG HTotalsFile);
        [id(91)] LONG Rename([in] LONG HTotalsFile, [in] BSTR FileName);
        [id(92)] LONG Rollback(void);
        [id(93)] LONG SetAll([in] LONG HTotalsFile, [in] LONG Value);
        [id(94)] LONG ValidateData([in] LONG HTotalsFile);
        [id(95)] LONG Write([in] LONG HTotalsFile, [in] BSTR Data, [in] LONG Offset, [in] LONG Count);
};
