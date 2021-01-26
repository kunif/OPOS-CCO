//*************************************************************************
//** OPOS SpeechSynthesis Internals
//
//   SpeechSynthesis header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS SpeechSynthesis Internals")]
enum
{
    PIDXSpch_Pitch                = 43001,
    PIDXSpch_Speed                = 43002,
    PIDXSpch_Volume               = 43003,

    PIDXSpch_CapLanguage          = 43501,
    PIDXSpch_CapPitch             = 43502,
    PIDXSpch_CapSpeed             = 43503,
    PIDXSpch_CapVoice             = 43504,
    PIDXSpch_CapVolume            = 43505,

    PIDXSpch_Language             = 1043001,
    PIDXSpch_LanguageList         = 1043002,
    PIDXSpch_OutputIDList         = 1043003,
    PIDXSpch_Voice                = 1043004,
    PIDXSpch_VoiceList            = 1043005
} OPOSSpeechSynthesisInternals;
