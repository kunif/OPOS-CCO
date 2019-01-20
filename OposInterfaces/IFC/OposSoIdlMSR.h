//*************************************************************************
//** OPOS MSR SO Interface
//*************************************************************************

[
    uuid(CCBE0120-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSMSRSO 1.15 Interface")
]
dispinterface IOPOSMSRSO
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
        [id(81)] LONG AuthenticateDevice([in] BSTR Response);
        [id(82)] LONG DeauthenticateDevice([in] BSTR Response);
        [id(83)] LONG RetrieveCardProperty([in] BSTR Name, [out] BSTR* pValue);
        [id(84)] LONG RetrieveDeviceAuthenticationData([in, out] BSTR* pChallenge);
        [id(85)] LONG UpdateKey([in]BSTR Key, [in] BSTR KeyName);
        [id(86)] LONG WriteTracks([in] VARIANT /*(SAFEARRAY of BSTR = Type VT_BSTR|VT_ARRAY)*/ Data, [in] LONG Timeout);
};
