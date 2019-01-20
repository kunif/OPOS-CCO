//*************************************************************************
//** OPOS CheckScanner Internals
//
//   Check Scanner header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS CheckScanner Internals")]
enum
{
    PIDXChk_Color                = 22001,
    PIDXChk_ConcurrentMICR       = 22002,
    PIDXChk_CropAreaCount        = 22003,
    PIDXChk_DocumentHeight       = 22004,
    PIDXChk_DocumentWidth        = 22005,
    PIDXChk_FileIndex            = 22006,
    PIDXChk_ImageFormat          = 22007,
    PIDXChk_ImageMemoryStatus    = 22008,
    PIDXChk_MapMode              = 22009,
    PIDXChk_MaxCropAreas         = 22010,
    PIDXChk_Quality              = 22011,
    PIDXChk_RemainingImagesEstimate  = 22012,
    PIDXChk_Contrast             = 22013,

    PIDXChk_CapAutoGenerateFileID= 22501,
    PIDXChk_CapAutoGenerateImageTagData = 22502,
    PIDXChk_CapAutoSize          = 22503,
    PIDXChk_CapColor             = 22504,
    PIDXChk_CapConcurrentMICR    = 22505,
    PIDXChk_CapDefineCropArea    = 22506,
    PIDXChk_CapImageFormat       = 22507,
    PIDXChk_CapImageTagData      = 22508,
    PIDXChk_CapMICRDevice        = 22509,
    PIDXChk_CapStoreImageFiles   = 22510,
    PIDXChk_CapValidationDevice  = 22511,
    PIDXChk_CapAutoContrast      = 22512,
    PIDXChk_CapContrast          = 22513,

    PIDXChk_FileID               = 122001,
    PIDXChk_ImageData            = 122002,
    PIDXChk_ImageTagData         = 122003,
    PIDXChk_QualityList          = 122004
} OPOSCheckScannerInternals;
