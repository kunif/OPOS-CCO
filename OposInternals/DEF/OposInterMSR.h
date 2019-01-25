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

    PIDXMsr_AccountNumber                 = 1007001,
    PIDXMsr_ExpirationDate                = 1007002,
    PIDXMsr_FirstName                     = 1007003,
    PIDXMsr_MiddleInitial                 = 1007004,
    PIDXMsr_ServiceCode                   = 1007005,
    PIDXMsr_Suffix                        = 1007006,
    PIDXMsr_Surname                       = 1007007,
    PIDXMsr_Title                         = 1007008,
    PIDXMsr_Track1Data                    = 1007009,
    PIDXMsr_Track1DiscretionaryData       = 1007010,
    PIDXMsr_Track2Data                    = 1007011,
    PIDXMsr_Track2DiscretionaryData       = 1007012,
    PIDXMsr_Track3Data                    = 1007013,
    PIDXMsr_Track4Data                    = 1007014,
    PIDXMsr_AdditionalSecurityInformation = 1007015,
    PIDXMsr_CapCardAuthentication         = 1007016,
    PIDXMsr_CardAuthenticationData        = 1007017,
    PIDXMsr_CardPropertyList              = 1007018,
    PIDXMsr_CardType                      = 1007019,
    PIDXMsr_CardTypeList                  = 1007020,
    PIDXMsr_Track1EncryptedData           = 1007021,
    PIDXMsr_Track2EncryptedData           = 1007022,
    PIDXMsr_Track3EncryptedData           = 1007023,
    PIDXMsr_Track4EncryptedData           = 1007024,
    PIDXMsr_WriteCardType                 = 1007025
} OPOSMSRInternals;
