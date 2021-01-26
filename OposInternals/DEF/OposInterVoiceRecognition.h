//*************************************************************************
//** OPOS VrcgRecognition Internals
//
//   VrcgRecognition header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS VrcgRecognition Internals")]
enum
{
    PIDXVrcg_HearingResult        = 45001,
    PIDXVrcg_HearingStatus        = 45002,

    PIDXVrcg_CapLanguage          = 45501,

    PIDXVrcg_HearingDataPattern   = 1045001,
    PIDXVrcg_HearingDataWord      = 1045002,
    PIDXVrcg_HearingDataWordList  = 1045003,
    PIDXVrcg_LanguageList         = 1045004
} OPOSVrcgRecognitionInternals;
