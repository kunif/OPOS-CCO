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

    PIDXPpad_AccountNumber       = 1017001,
    PIDXPpad_AdditionalSecurityInformation
                                 = 1017002,
    PIDXPpad_AvailableLanguagesList
                                 = 1017003,
    PIDXPpad_AvailablePromptsList= 1017005,
    PIDXPpad_EncryptedPIN        = 1017006,
    PIDXPpad_MerchantID          = 1017007,
    PIDXPpad_TerminalID          = 1017008,
    PIDXPpad_Track1Data          = 1017009,
    PIDXPpad_Track2Data          = 1017010,
    PIDXPpad_Track3Data          = 1017011,
    PIDXPpad_Track4Data          = 1017012
} OPOSPINPadInternals;
