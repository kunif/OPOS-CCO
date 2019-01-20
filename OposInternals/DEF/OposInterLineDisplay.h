//*************************************************************************
//** OPOS LineDisplay Internals
//
//   Line Display header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS LineDisplay Internals")]
enum
{
    PIDXDisp_CharacterSet        =  5001,
    PIDXDisp_Columns             =  5002,
    PIDXDisp_CurrentWindow       =  5003,
    PIDXDisp_CursorColumn        =  5004,
    PIDXDisp_CursorRow           =  5005,
    PIDXDisp_CursorUpdate        =  5006,
    PIDXDisp_DeviceBrightness    =  5007,
    PIDXDisp_DeviceColumns       =  5008,
    PIDXDisp_DeviceDescriptors   =  5009,
    PIDXDisp_DeviceRows          =  5010,
    PIDXDisp_DeviceWindows       =  5011,
    PIDXDisp_InterCharacterWait  =  5012,
    PIDXDisp_MarqueeRepeatWait   =  5013,
    PIDXDisp_MarqueeType         =  5014,
    PIDXDisp_MarqueeUnitWait     =  5015,
    PIDXDisp_Rows                =  5016,
    PIDXDisp_MarqueeFormat       =  5017,
    PIDXDisp_BlinkRate           =  5018,
    PIDXDisp_CursorType          =  5019,
    PIDXDisp_GlyphHeight         =  5020,
    PIDXDisp_GlyphWidth          =  5021,
    PIDXDisp_MapCharacterSet     =  5022,
    PIDXDisp_MaximumX            =  5023,
    PIDXDisp_MaximumY            =  5024,
    PIDXDisp_ScreenMode          =  5025,

    PIDXDisp_CapBlink            =  5501,
    PIDXDisp_CapBrightness       =  5502,
    PIDXDisp_CapCharacterSet     =  5503,
    PIDXDisp_CapDescriptors      =  5504,
    PIDXDisp_CapHMarquee         =  5505,
    PIDXDisp_CapICharWait        =  5506,
    PIDXDisp_CapVMarquee         =  5507,
    PIDXDisp_CapBlinkRate        =  5508,
    PIDXDisp_CapCursorType       =  5509,
    PIDXDisp_CapCustomGlyph      =  5510,
    PIDXDisp_CapReadBack         =  5511,
    PIDXDisp_CapReverse          =  5512,
    PIDXDisp_CapBitmap           =  5513,
    PIDXDisp_CapMapCharacterSet  =  5514,
    PIDXDisp_CapScreenMode       =  5515,

    PIDXDisp_CharacterSetList    = 105001,
    PIDXDisp_CustomGlyphList     = 105002,
    PIDXDisp_ScreenModeList      = 105003
} OPOSLineDisplayInternals;
