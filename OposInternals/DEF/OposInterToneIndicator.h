//*************************************************************************
//** OPOS ToneIndicator Internals
//
//   Tone Indicator header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS ToneIndicator Internals")]
enum
{
    PIDXTone_AsyncMode           = 14001,
    PIDXTone_Tone1Pitch          = 14002,
    PIDXTone_Tone1Volume         = 14003,
    PIDXTone_Tone1Duration       = 14004,
    PIDXTone_Tone2Pitch          = 14005,
    PIDXTone_Tone2Volume         = 14006,
    PIDXTone_Tone2Duration       = 14007,
    PIDXTone_InterToneWait       = 14008,
    PIDXTone_MelodyType          = 14009,
    PIDXTone_MelodyVolume        = 14010,

    PIDXTone_CapPitch            = 14501,
    PIDXTone_CapVolume           = 14502,
    PIDXTone_CapMelody           = 14503
} OPOSToneIndicatorInternals;
