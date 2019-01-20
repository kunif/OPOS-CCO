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

    PIDXMicr_AccountNumber       = 106001,
    PIDXMicr_Amount              = 106002,
    PIDXMicr_BankNumber          = 106003,
    PIDXMicr_EPC                 = 106004,
    PIDXMicr_RawData             = 106005,
    PIDXMicr_SerialNumber        = 106006,
    PIDXMicr_TransitNumber       = 106007
} OPOSMICRInternals;
