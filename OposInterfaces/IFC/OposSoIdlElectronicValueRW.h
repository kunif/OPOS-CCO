//*************************************************************************
//** OPOS ElectronicValueRW SO Interface
//*************************************************************************

[
    uuid(CCBE0330-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSElectronicValueRWSO 1.14.1 Interface")
]
dispinterface IOPOSElectronicValueRWSO
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

        // Device Specific Property
        [id(49)] CURRENCY GetAmount(void);
        [id(50)] void SetAmount([in] CURRENCY Amount);
        [id(51)] CURRENCY GetBalance(void);
        [id(52)] CURRENCY GetBalanceOfPoint(void);
        [id(53)] CURRENCY GetPoint(void);
        [id(54)] void SetPoint([in] CURRENCY Point);
        [id(55)] CURRENCY GetSettledAmount(void);
        [id(56)] CURRENCY GetSettledPoint(void);

        // Device Specific Method
        [id(81)] LONG AccessData([in] LONG DataType, [in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(82)] LONG AccessLog([in] LONG SequenceNumber, [in] LONG Type, [in] LONG Timeout);
        [id(83)] LONG ActivateEVService([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(84)] LONG ActivateService([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(85)] LONG AddValue([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(86)] LONG BeginDetection([in] LONG Type, [in] LONG Timeout);
        [id(87)] LONG BeginRemoval([in] LONG Timeout);
        [id(88)] LONG CancelValue([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(89)] LONG CaptureCard(void);
        [id(90)] LONG CheckServiceRegistrationToMedium([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(91)] LONG ClearParameterInformation(void);
        [id(92)] LONG CloseDailyEVService([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(93)] LONG DeactivateEVService([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(94)] LONG EndDetection(void);
        [id(95)] LONG EndRemoval(void);
        [id(96)] LONG EnumerateCardServices(void);
        [id(97)] LONG LockTerminal(void);
        [id(98)] LONG OpenDailyEVService([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(99)] LONG QueryLastSuccessfulTransactionResult(void);
        [id(100)] LONG ReadValue([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(101)] LONG RegisterServiceToMedium([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(102)] LONG RetrieveResultInformation([in] BSTR Name, [in, out] BSTR* pValue);
        [id(103)] LONG SetParameterInformation([in] BSTR Name, [in] BSTR Value);
        [id(104)] LONG SubtractValue([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(105)] LONG TransactionAccess([in] LONG Control);
        [id(106)] LONG UnlockTerminal(void);
        [id(107)] LONG UnregisterServiceToMedium([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(108)] LONG UpdateData([in] LONG DataType, [in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(109)] LONG UpdateKey([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(110)] LONG WriteValue([in] LONG SequenceNumber, [in] LONG Timeout);
};

[
    uuid(CCBE0331-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSElectronicValueRWSO 1.16 Interface")
]
dispinterface IOPOSElectronicValueRWSO_1_15
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

        // Device Specific Property
        [id(49)] CURRENCY GetAmount(void);
        [id(50)] void SetAmount([in] CURRENCY Amount);
        [id(51)] CURRENCY GetBalance(void);
        [id(52)] CURRENCY GetBalanceOfPoint(void);
        [id(53)] CURRENCY GetPoint(void);
        [id(54)] void SetPoint([in] CURRENCY Point);
        [id(55)] CURRENCY GetSettledAmount(void);
        [id(56)] CURRENCY GetSettledPoint(void);

        // Device Specific Method
        [id(81)] LONG AccessData([in] LONG DataType, [in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(82)] LONG AccessLog([in] LONG SequenceNumber, [in] LONG Type, [in] LONG Timeout);
        [id(83)] LONG ActivateEVService([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(84)] LONG ActivateService([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(85)] LONG AddValue([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(86)] LONG BeginDetection([in] LONG Type, [in] LONG Timeout);
        [id(87)] LONG BeginRemoval([in] LONG Timeout);
        [id(88)] LONG CancelValue([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(89)] LONG CaptureCard(void);
        [id(90)] LONG CheckServiceRegistrationToMedium([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(91)] LONG ClearParameterInformation(void);
        [id(92)] LONG CloseDailyEVService([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(93)] LONG DeactivateEVService([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(94)] LONG EndDetection(void);
        [id(95)] LONG EndRemoval(void);
        [id(96)] LONG EnumerateCardServices(void);
        [id(97)] LONG LockTerminal(void);
        [id(98)] LONG OpenDailyEVService([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(99)] LONG QueryLastSuccessfulTransactionResult(void);
        [id(100)] LONG ReadValue([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(101)] LONG RegisterServiceToMedium([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(102)] LONG RetrieveResultInformation([in] BSTR Name, [in, out] BSTR* pValue);
        [id(103)] LONG SetParameterInformation([in] BSTR Name, [in] BSTR Value);
        [id(104)] LONG SubtractValue([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(105)] LONG TransactionAccess([in] LONG Control);
        [id(106)] LONG UnlockTerminal(void);
        [id(107)] LONG UnregisterServiceToMedium([in] LONG SequenceNumber, [in] LONG Timeout);
        [id(108)] LONG UpdateData([in] LONG DataType, [in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(109)] LONG UpdateKey([in, out] LONG* pData, [in, out] BSTR* pObj);
        [id(110)] LONG WriteValue([in] LONG SequenceNumber, [in] LONG Timeout);
        // added 1.15
        [id(111)] LONG AccessDailyLog([in] LONG SequenceNumber, [in] LONG Type, [in] LONG Timeout);
        [id(112)] LONG AuthorizeCompletion([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(113)] LONG AuthorizePreSales([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(114)] LONG AuthorizeRefund([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(115)] LONG AuthorizeSales([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(116)] LONG AuthorizeVoid([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(117)] LONG AuthorizeVoidPreSales([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] CURRENCY TaxOthers, [in] LONG Timeout);
        [id(118)] LONG CashDeposit([in] LONG SequenceNumber, [in] CURRENCY Amount, [in] LONG Timeout);
        [id(119)] LONG CheckCard([in] LONG SequenceNumber, [in] LONG Timeout);
};
