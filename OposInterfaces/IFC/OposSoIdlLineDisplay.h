//*************************************************************************
//** OPOS LineDisplay SO Interface
//*************************************************************************

[
    uuid(CCBE0100-B81E-11D2-AB74-0040054C3719),
    helpstring("IOPOSLineDisplaySO 1.16 Interface")
]
dispinterface IOPOSLineDisplaySO
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
        [id(81)] LONG ClearDescriptors(void);
        [id(82)] LONG ClearText(void);
        [id(83)] LONG CreateWindow([in] LONG ViewportRow, [in] LONG ViewportColumn, [in] LONG ViewportHeight, [in] LONG ViewportWidth, [in] LONG WindowHeight, [in] LONG WindowWidth);
        [id(84)] LONG DefineGlyph([in] LONG GlyphCode, [in] BSTR Glyph);
        [id(85)] LONG DestroyWindow(void);
        [id(86)] LONG DisplayBitmap([in] BSTR FileName, [in] LONG Width, [in] LONG AlignmentX, [in] LONG AlignmentY);
        [id(87)] LONG DisplayText([in] BSTR Data, [in] LONG Attribute);
        [id(88)] LONG DisplayTextAt([in] LONG Row, [in] LONG Column, [in] BSTR Data, [in] LONG Attribute);
        [id(89)] LONG ReadCharacterAtCursor([out] LONG* pChar);
        [id(90)] LONG RefreshWindow([in] LONG Window);
        [id(91)] LONG ScrollText([in] LONG Direction, [in] LONG Units);
        [id(92)] LONG SetBitmap([in] LONG BitmapNumber, [in] BSTR FileName, [in] LONG Width, [in] LONG AlignmentX, [in] LONG AlignmentY);
        [id(93)] LONG SetDescriptor([in] LONG Descriptor, [in] LONG Attribute);
};
