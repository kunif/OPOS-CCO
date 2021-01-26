//*************************************************************************
//** OPOS SoundRecorder Internals
//
//   SoundRecorder header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS SoundRecorder Internals")]
enum
{
    PIDXSrec_RecordingLevel                   = 42001,
    PIDXSrec_RemainingRecordingTimeInSec      = 42002,
    PIDXSrec_Storage                          = 42003,

    PIDXSrec_CapChannel                       = 42501,
    PIDXSrec_CapRecordingLevel                = 42503,
    PIDXSrec_CapSamplingRate                  = 42502,
    PIDXSrec_CapSoundType                     = 42504,
    PIDXSrec_CapStorage                       = 42505,

    PIDXSrec_Channel                          = 1042001,
    PIDXSrec_ChannelList                      = 1042002,
    PIDXSrec_SamplingRate                     = 1042003,
    PIDXSrec_SamplingRateList                 = 1042004,
    PIDXSrec_SoundData                        = 1042005,
    PIDXSrec_SoundType                        = 1042006,
    PIDXSrec_SoundTypeList                    = 1042007,

    PIDXSrec_CapAssociatedHardTotalsDevice    = 1042501
} OPOSSoundRecorderInternals;
