//*************************************************************************
//** OPOS PINPad Internals
//
//   PIN Pad header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS PINPad Internals")]
enum
{
    PIDXPpad_MaximumPINLength    = 17001,
    PIDXPpad_MinimumPINLength    = 17002,
    PIDXPpad_PINEntryEnabled     = 17003,
    PIDXPpad_Prompt              = 17004,
    PIDXPpad_PromptLanguage      = 17005,
    PIDXPpad_TransactionType     = 17006,

    PIDXPpad_CapDisplay          = 17501,
    PIDXPpad_CapKeyboard         = 17502,
    PIDXPpad_CapLanguage         = 17503,
    PIDXPpad_CapMACCalculation   = 17504,
    PIDXPpad_CapTone             = 17505,

    PIDXPpad_AccountNumber       = 117001,
    PIDXPpad_AdditionalSecurityInformation
                                 = 117002,
    PIDXPpad_AvailableLanguagesList
                                 = 117003,
    PIDXPpad_AvailablePromptsList= 117005,
    PIDXPpad_EncryptedPIN        = 117006,
    PIDXPpad_MerchantID          = 117007,
    PIDXPpad_TerminalID          = 117008,
    PIDXPpad_Track1Data          = 117009,
    PIDXPpad_Track2Data          = 117010,
    PIDXPpad_Track3Data          = 117011,
    PIDXPpad_Track4Data          = 117012
} OPOSPINPadInternals;
