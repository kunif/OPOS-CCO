//*************************************************************************
//** OPOS VoiceRecognition Constants
//*************************************************************************

typedef [helpstring("OPOS VoiceRecognition Constants")]
enum
{
    VRCG_HRESULT_FREE                         = 11,
    VRCG_HRESULT_SENTENCE                     = 21,
    VRCG_HRESULT_WORD                         = 31,
    VRCG_HRESULT_YESNO_YES                    = 41,
    VRCG_HRESULT_YESNO_NO                     = 42,
    VRCG_HRESULT_YESNO_CANCEL                 = 43,
    VRCG_HSTATUS_NONE                         = 0,
    VRCG_HSTATUS_FREE                         = 10,
    VRCG_HSTATUS_SENTENCE                     = 20,
    VRCG_HSTATUS_WORD                         = 30,
    VRCG_HSTATUS_YESNO                        = 40,
    VRCG_SUE_STOP_HEARING                     =  0,
    VRCG_SUE_START_HEARING_FREE               = 10,
    VRCG_SUE_START_HEARING_SENTENCE           = 20,
    VRCG_SUE_START_HEARING_WORD               = 30,
    VRCG_SUE_START_HEARING_YESNO              = 40
} OPOSVoiceRecognitionConstants;
