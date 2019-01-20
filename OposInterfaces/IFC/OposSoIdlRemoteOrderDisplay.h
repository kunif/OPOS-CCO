//*************************************************************************
//** OPOS RemoteOrderDisplay SO Interface
//*************************************************************************

[
    uuid(CCBE0160-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSRemoteOrderDisplaySO 1.15 Interface")
]
dispinterface IOPOSRemoteOrderDisplaySO
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
        [id(81)] LONG ClearVideo([in] LONG Units, [in] LONG Attribute);
        [id(82)] LONG ClearVideoRegion([in] LONG Units, [in] LONG Row, [in] LONG Column, [in] LONG Height, [in] LONG Width, [in] LONG Attribute);
        [id(83)] LONG ControlClock([in] LONG Units, [in] LONG Function, [in] LONG ClockId, [in] LONG Hour, [in] LONG Min, [in] LONG Sec, [in] LONG Row, [in] LONG Column, [in] LONG Attribute, [in] LONG Mode);
        [id(84)] LONG ControlCursor([in] LONG Units, [in] LONG Function);
        [id(85)] LONG CopyVideoRegion([in] LONG Units, [in] LONG Row, [in] LONG Column, [in] LONG Height, [in] LONG Width, [in] LONG TargetRow, [in] LONG TargetColumn);
        [id(86)] LONG DisplayData([in] LONG Units, [in] LONG Row, [in] LONG Column, [in] LONG Attribute, [in] BSTR Data);
        [id(87)] LONG DrawBox([in] LONG Units, [in] LONG Row, [in] LONG Column, [in] LONG Height, [in] LONG Width, [in] LONG Attribute, [in] LONG BorderType);
        [id(88)] LONG FreeVideoRegion([in] LONG Units, [in] LONG BufferId);
        [id(89)] LONG ResetVideo([in] LONG Units);
        [id(90)] LONG RestoreVideoRegion([in] LONG Units, [in] LONG TargetRow, [in] LONG TargetColumn, [in] LONG BufferId);
        [id(91)] LONG SaveVideoRegion([in] LONG Units, [in] LONG Row, [in] LONG Column, [in] LONG Height, [in] LONG Width, [in] LONG BufferId);
        [id(92)] LONG SelectCharacterSet([in] LONG Units, [in] LONG CharacterSet);
        [id(93)] LONG SetCursor([in] LONG Units, [in] LONG Row, [in] LONG Column);
        [id(94)] LONG TransactionDisplay([in] LONG Units, [in] LONG Function);
        [id(95)] LONG UpdateVideoRegionAttribute([in] LONG Units, [in] LONG Function, [in] LONG Row, [in] LONG Column, [in] LONG Height, [in] LONG Width, [in] LONG Attribute);
        [id(96)] LONG VideoSound([in] LONG Units, [in] LONG Frequency, [in] LONG Duration, [in] LONG NumberOfCycles, [in] LONG InterSoundWait);
};
