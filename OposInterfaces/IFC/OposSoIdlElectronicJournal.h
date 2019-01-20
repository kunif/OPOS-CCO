//*************************************************************************
//** OPOS ElectronicJournal SO Interface
//*************************************************************************

[
    uuid(CCBE0270-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSElectronicJournalSO 1.15 Interface")
]
dispinterface IOPOSElectronicJournalSO
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

        // Device Specific Property
        [id(49)] CURRENCY GetMediumFreeSpace(void);
        [id(50)] CURRENCY GetMediumSize(void);

        // Device Specific Method
        [id(81)] LONG AddMarker([in] BSTR Marker);
        [id(82)] LONG CancelPrintContent(void);
        [id(83)] LONG CancelQueryContent(void);
        [id(84)] LONG EraseMedium(void);
        [id(85)] LONG InitializeMedium([in] BSTR MediumID);
        [id(86)] LONG PrintContent([in] BSTR FromMarker, [in] BSTR ToMarker);
        [id(87)] LONG PrintContentFile([in] BSTR FileName);
        [id(88)] LONG QueryContent([in] BSTR FileName, [in] BSTR FromMarker, [in] BSTR ToMarker);
        [id(89)] LONG ResumePrintContent(void);
        [id(90)] LONG ResumeQueryContent(void);
        [id(91)] LONG RetrieveCurrentMarker([in] LONG MarkerType, [out] BSTR* pMarker);
        [id(92)] LONG RetrieveMarker([in] LONG MarkerType, [in] LONG SessionNumber, [in] LONG DocumentNumber, [out] BSTR* pMarker);
        [id(93)] LONG RetrieveMarkerByDateTime([in] LONG MarkerType, [in] BSTR DateTime, [in] BSTR MarkerNumber, [out] BSTR* pMarker);
        [id(94)] LONG RetrieveMarkersDateTime([in] BSTR Marker, [out] BSTR* pDateTime);
        [id(95)] LONG SuspendPrintContent(void);
        [id(96)] LONG SuspendQueryContent(void);
};
