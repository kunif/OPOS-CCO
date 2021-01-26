//*************************************************************************
//** OPOS SoundPlayer Internals
//
//   SoundPlayer header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS SoundPlayer Internals")]
enum
{
    PIDXSply_Storage                          = 41001,
    PIDXSply_Volume                           = 41002,

    PIDXSply_CapMultiPlay                     = 41501,
    PIDXSply_CapStorage                       = 41502,
    PIDXSply_CapVolume                        = 41503,

    PIDXSply_DeviceSoundList                  = 1041001,
    PIDXSply_OutputIDList                     = 1041002,

    PIDXSply_CapAssociatedHardTotalsDevice    = 1041501,
    PIDXSply_CapSoundTypeList                 = 1041502
} OPOSSoundPlayerInternals;
