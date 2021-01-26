//*************************************************************************
//** OPOS GraphicDisplay Internals
//
//   GraphicDisplay header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS GraphicDisplay Internals")]
enum
{
    PIDXGdsp_Brightness                       = 39001,
    PIDXGdsp_DisplayMode                      = 39002,
    PIDXGdsp_LoadStatus                       = 39003,
    PIDXGdsp_Storage                          = 39004,
    PIDXGdsp_Volume                           = 39005,

    PIDXGdsp_CapBrightness                    = 39501,
    PIDXGdsp_CapImageType                     = 39502,
    PIDXGdsp_CapStorage                       = 39503,
    PIDXGdsp_CapURLBack                       = 39504,
    PIDXGdsp_CapURLForward                    = 39505,
    PIDXGdsp_CapVideoType                     = 39506,
    PIDXGdsp_CapVolume                        = 39507,

    PIDXGdsp_ImageType                        = 1039001,
    PIDXGdsp_ImageTypeList                    = 1039002,
    PIDXGdsp_URL                              = 1039003,
    PIDXGdsp_VideoType                        = 1039004,
    PIDXGdsp_VideoTypeList                    = 1039005,

    PIDXGdsp_CapAssociatedHardTotalsDevice    = 1039501
} OPOSGraphicDisplayInternals;
