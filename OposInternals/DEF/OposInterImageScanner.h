//*************************************************************************
//** OPOS ImageScanner Internals
//
//   Image Scanner header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS ImageScanner Internals")]
enum
{
    PIDXImg_AimMode              = 30001,
    PIDXImg_BitsPerPixel         = 30002,
    PIDXImg_FrameType            = 30003,
    PIDXImg_IlluminateMode       = 30004,
    PIDXImg_ImageHeight          = 30005,
    PIDXImg_ImageLength          = 30006,
    PIDXImg_ImageMode            = 30007,
    PIDXImg_ImageQuality         = 30008,
    PIDXImg_ImageType            = 30009,
    PIDXImg_ImageWidth           = 30010,
    PIDXImg_VideoCount           = 30011,
    PIDXImg_VideoRate            = 30012,

    PIDXImg_CapAim               = 30501,
    PIDXImg_CapDecodeData        = 30502,
    PIDXImg_CapHostTriggered     = 30503,
    PIDXImg_CapIlluminate        = 30504,
    PIDXImg_CapImageData         = 30505,
    PIDXImg_CapImageQuality      = 30506,
    PIDXImg_CapVideoData         = 30507,

    PIDXImg_FrameData            = 130001
} OPOSImageScannerInternals;
