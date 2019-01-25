//*************************************************************************
//** OPOS MICR Internals
//
//   MICR header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS MICR Internals")]
enum
{
    PIDXMicr_CheckType           =  6001,
    PIDXMicr_CountryCode         =  6002,

    PIDXMicr_CapValidationDevice =  6501,

    PIDXMicr_AccountNumber       = 1006001,
    PIDXMicr_Amount              = 1006002,
    PIDXMicr_BankNumber          = 1006003,
    PIDXMicr_EPC                 = 1006004,
    PIDXMicr_RawData             = 1006005,
    PIDXMicr_SerialNumber        = 1006006,
    PIDXMicr_TransitNumber       = 1006007
} OPOSMICRInternals;
