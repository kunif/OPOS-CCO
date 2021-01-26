//*************************************************************************
//** OPOS VideoCapture Internals
//
//   VideoCapture header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS VideoCapture Internals")]
enum
{
    PIDXVcap_AutoExposure                     = 44001,
    PIDXVcap_AutoFocus                        = 44002,
    PIDXVcap_AutoGain                         = 44003,
    PIDXVcap_AutoWhiteBalance                 = 44004,
    PIDXVcap_Brightness                       = 44005,
    PIDXVcap_Contrast                         = 44006,
    PIDXVcap_Exposure                         = 44007,
    PIDXVcap_Gain                             = 44008,
    PIDXVcap_HorizontalFlip                   = 44009,
    PIDXVcap_Hue                              = 44010,
    PIDXVcap_PhotoFrameRate                   = 44011,
    PIDXVcap_PhotoMaxFrameRate                = 44012,
    PIDXVcap_RemainingRecordingTimeInSec      = 44013,
    PIDXVcap_Saturation                       = 44014,
    PIDXVcap_Storage                          = 44015,
    PIDXVcap_VerticalFlip                     = 44016,
    PIDXVcap_VideoCaptureMode                 = 44017,
    PIDXVcap_VideoFrameRate                   = 44018,
    PIDXVcap_VideoMaxFrameRate                = 44019,

    PIDXVcap_CapAutoExposure                  = 44501,
    PIDXVcap_CapAutoFocus                     = 44502,
    PIDXVcap_CapAutoGain                      = 44503,
    PIDXVcap_CapAutoWhiteBalance              = 44504,
    PIDXVcap_CapBrightness                    = 44505,
    PIDXVcap_CapContrast                      = 44506,
    PIDXVcap_CapExposure                      = 44507,
    PIDXVcap_CapGain                          = 44508,
    PIDXVcap_CapHorizontalFlip                = 44509,
    PIDXVcap_CapHue                           = 44510,
    PIDXVcap_CapPhoto                         = 44511,
    PIDXVcap_CapPhotoColorSpace               = 44512,
    PIDXVcap_CapPhotoFrameRate                = 44513,
    PIDXVcap_CapPhotoResolution               = 44514,
    PIDXVcap_CapPhotoType                     = 44515,
    PIDXVcap_CapSaturation                    = 44516,
    PIDXVcap_CapStorage                       = 44517,
    PIDXVcap_CapVerticalFlip                  = 44518,
    PIDXVcap_CapVideo                         = 44519,
    PIDXVcap_CapVideoColorSpace               = 44520,
    PIDXVcap_CapVideoFrameRate                = 44521,
    PIDXVcap_CapVideoResolution               = 44522,
    PIDXVcap_CapVideoType                     = 44523,

    PIDXVcap_PhotoColorSpace                  = 1044001,
    PIDXVcap_PhotoColorSpaceList              = 1044002,
    PIDXVcap_PhotoResolution                  = 1044003,
    PIDXVcap_PhotoResolutionList              = 1044004,
    PIDXVcap_PhotoType                        = 1044005,
    PIDXVcap_PhotoTypeList                    = 1044006,
    PIDXVcap_VideoColorSpace                  = 1044007,
    PIDXVcap_VideoColorSpaceList              = 1044008,
    PIDXVcap_VideoResolution                  = 1044009,
    PIDXVcap_VideoResolutionList              = 1044010,
    PIDXVcap_VideoType                        = 1044011,
    PIDXVcap_VideoTypeList                    = 1044012,

    PIDXVcap_CapAssociatedHardTotalsDevice    = 1044501
} OPOSVideoCaptureInternals;
