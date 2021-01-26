//*************************************************************************
//** OPOS Scale SO Interface
//*************************************************************************

[
    uuid(CCBE0170-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSScaleSO 1.16 Interface")
]
dispinterface IOPOSScaleSO
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

        // Device Specific Property
        [id(49)] CURRENCY GetSalesPrice(void);
        [id(50)] CURRENCY GetUnitPrice(void);
        [id(51)] void SetUnitPrice([in] CURRENCY UnitPrice);

        // Device Specific Method
        [id(81)] LONG DisplayText([in] BSTR Data);
        [id(82)] LONG DoPriceCalculating([out] LONG* pWeightData, [out] LONG* pTare, [out] CURRENCY* pUnitPrice, [out] CURRENCY* pUnitPriceX, [out] LONG* pWeightUnitX, [out] LONG* pWeightNumeratorX, [out] LONG* pWeightDenominatorX, [out] CURRENCY* pPrice, [in] LONG Timeout);
        [id(83)] LONG FreezeValue([in] LONG Item, [in] VARIANT_BOOL Freeze);
        [id(84)] LONG ReadLiveWeightWithTare([out] LONG* pWeightData, [out] LONG* pTare, [in] LONG Timeout);
        [id(85)] LONG ReadWeight([out] LONG* pWeightData, [in] LONG Timeout);
        [id(86)] LONG SetPriceCalculationMode([in] LONG Mode);
        [id(87)] LONG SetSpecialTare([in] LONG Mode, [in] LONG Data);
        [id(88)] LONG SetTarePriority([in] LONG Priority);
        [id(89)] LONG SetUnitPriceWithWeightUnit([in] CURRENCY UnitPrice, [in] LONG WeightUnit, [in] LONG WeightNumerator, [in] LONG WeightDenominator);
        [id(90)] LONG ZeroScale(void);
};
