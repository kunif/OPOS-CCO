//*************************************************************************
//** OPOS ImageScanner Constants
//*************************************************************************

typedef [helpstring("OPOS ImageScanner Constants")]
enum
{
    IMG_FRAME_STILL                           = 1,
    IMG_FRAME_VIDEO                           = 2,
    IMG_ALL                                   = 0xFF,
    IMG_DECODE_ONLY                           = 0x01,
    IMG_STILL_ONLY                            = 0x02,
    IMG_STILL_DECODE                          = 0x03,
    IMG_VIDEO_DECODE                          = 0x05,
    IMG_VIDEO_STILL                           = 0x06,
    IMG_QUAL_LOW                              = 0x01,
    IMG_QUAL_MED                              = 0x02,
    IMG_QUAL_HIGH                             = 0x03,
    IMG_TYP_BMP                               = 1,
    IMG_TYP_JPEG                              = 2,
    IMG_TYP_GIF                               = 3,
    IMG_TYP_PNG                               = 4,
    IMG_TYP_TIFF                              = 5
} OPOSImageScannerConstants;
