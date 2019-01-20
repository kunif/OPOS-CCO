//*************************************************************************
//** OPOS RFIDScanner SO Interface
//*************************************************************************

[
    uuid(CCBE0370-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSRFIDScannerSO 1.15 Interface")
]
dispinterface IOPOSRFIDScannerSO
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
        [id(11)] LONG ClearInputProperties(void);
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
        [id(81)] LONG DisableTag([in] BSTR TagID, [in] LONG Timeout, [in] BSTR Password);
        [id(82)] LONG FirstTag(void);
        [id(83)] LONG LockTag([in] BSTR TagID, [in] LONG Timeout, [in] BSTR Password);
        [id(84)] LONG NextTag(void);
        [id(85)] LONG PreviousTag(void);
        [id(86)] LONG ReadTags([in] LONG Cmd, [in] BSTR FilterID, [in] BSTR Filtermask, [in] LONG Start, [in] LONG Length, [in] LONG Timeout, [in] BSTR Password);
        [id(87)] LONG StartReadTags([in] LONG Cmd, [in] BSTR FilterID, [in] BSTR Filtermask, [in] LONG Start, [in] LONG Length, [in] BSTR Password);
        [id(88)] LONG StopReadTags([in] BSTR Password);
        [id(89)] LONG WriteTagData([in] BSTR TagID, [in] BSTR Userdata, [in] LONG Start, [in] LONG Timeout, [in] BSTR Password);
        [id(90)] LONG WriteTagID([in] BSTR SourceID, [in] BSTR DestID, [in] LONG Timeout, [in] BSTR Password);
};
