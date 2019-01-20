//*************************************************************************
//** OPOS MSR Internals
//
//   MSR header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS MSR Internals")]
enum
{
    PIDXMsr_DecodeData                    =  7001,
    PIDXMsr_ParseDecodeData               =  7002,
    PIDXMsr_TracksToRead                  =  7003,
    PIDXMsr_ParseDecodedData              =  7002,
    PIDXMsr_ErrorReportingType            =  7004,
    PIDXMsr_TransmitSentinels             =  7005,
    PIDXMsr_EncodingMaxLength             =  7006,
    PIDXMsr_TracksToWrite                 =  7007,
    PIDXMsr_CardAuthenticationDataLength  =  7008,
    PIDXMsr_DataEncryptionAlgorithm       =  7009,
    PIDXMsr_DeviceAuthenticated           =  7010,
    PIDXMsr_DeviceAuthenticationProtocol  =  7011,
    PIDXMsr_Track1EncryptedDataLength     =  7012,
    PIDXMsr_Track2EncryptedDataLength     =  7013,
    PIDXMsr_Track3EncryptedDataLength     =  7014,
    PIDXMsr_Track4EncryptedDataLength     =  7015,

    PIDXMsr_CapISO                        =  7501,
    PIDXMsr_CapJISOne                     =  7502,
    PIDXMsr_CapJISTwo                     =  7503,
    PIDXMsr_CapTransmitSentinels          =  7504,
    PIDXMsr_CapWritableTracks             =  7505,
    PIDXMsr_CapDataEncryption             =  7506,
    PIDXMsr_CapDeviceAuthentication       =  7507,
    PIDXMsr_CapTrackDataMasking           =  7508,

    PIDXMsr_AccountNumber                 = 107001,
    PIDXMsr_ExpirationDate                = 107002,
    PIDXMsr_FirstName                     = 107003,
    PIDXMsr_MiddleInitial                 = 107004,
    PIDXMsr_ServiceCode                   = 107005,
    PIDXMsr_Suffix                        = 107006,
    PIDXMsr_Surname                       = 107007,
    PIDXMsr_Title                         = 107008,
    PIDXMsr_Track1Data                    = 107009,
    PIDXMsr_Track1DiscretionaryData       = 107010,
    PIDXMsr_Track2Data                    = 107011,
    PIDXMsr_Track2DiscretionaryData       = 107012,
    PIDXMsr_Track3Data                    = 107013,
    PIDXMsr_Track4Data                    = 107014,
    PIDXMsr_AdditionalSecurityInformation = 107015,
    PIDXMsr_CapCardAuthentication         = 107016,
    PIDXMsr_CardAuthenticationData        = 107017,
    PIDXMsr_CardPropertyList              = 107018,
    PIDXMsr_CardType                      = 107019,
    PIDXMsr_CardTypeList                  = 107020,
    PIDXMsr_Track1EncryptedData           = 107021,
    PIDXMsr_Track2EncryptedData           = 107022,
    PIDXMsr_Track3EncryptedData           = 107023,
    PIDXMsr_Track4EncryptedData           = 107024,
    PIDXMsr_WriteCardType                 = 107025
} OPOSMSRInternals;
