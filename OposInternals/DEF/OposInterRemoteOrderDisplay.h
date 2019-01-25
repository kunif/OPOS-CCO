//*************************************************************************
//** OPOS RemoteOrderDisplay Internals
//
//   Remote Order Display header file for OPOS Controls and
//     Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS RemoteOrderDisplay Internals")]
enum
{
    PIDXRod_AsyncMode            = 18001,
    PIDXRod_AutoToneDuration     = 18002,
    PIDXRod_AutoToneFrequency    = 18003,
    PIDXRod_CharacterSet         = 18004,
    PIDXRod_Clocks               = 18005,
    PIDXRod_CurrentUnitID        = 18006,
    PIDXRod_ErrorUnits           = 18007,
    PIDXRod_EventType            = 18008,
    PIDXRod_EventUnitID          = 18009,
    PIDXRod_EventUnits           = 18010,
    PIDXRod_SystemClocks         = 18011,
    PIDXRod_SystemVideoSaveBuffers=18012,
    PIDXRod_Timeout              = 18013,
    PIDXRod_UnitsOnline          = 18014,
    PIDXRod_VideoDataCount       = 18015,
    PIDXRod_VideoMode            = 18016,
    PIDXRod_VideoSaveBuffers     = 18017,
    PIDXRod_MapCharacterSet      = 18018,

    PIDXRod_CapSelectCharacterSet= 18501,
    PIDXRod_CapTone              = 18502,
    PIDXRod_CapTouch             = 18503,
    PIDXRod_CapTransaction       = 18504,
    PIDXRod_CapMapCharacterSet   = 18505,

    PIDXRod_CharacterSetList     = 1018001,
    PIDXRod_ErrorString          = 1018002,
    PIDXRod_EventString          = 1018003,
    PIDXRod_VideoModesList       = 1018004
} OPOSRemoteOrderDisplayInternals;
