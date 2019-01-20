//*************************************************************************
//** OPOS PointCardRW Internals
//
//   Point Card Reader Writer  header file for OPOS Controls and
//   Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS PointCardRW Internals")]
enum
{
    PIDXPcrw_CardState           = 20001,
    PIDXPcrw_CharacterSet        = 20002,
    PIDXPcrw_LineChars           = 20003,
    PIDXPcrw_LineHeight          = 20004,
    PIDXPcrw_LineSpacing         = 20005,
    PIDXPcrw_LineWidth           = 20006,
    PIDXPcrw_MapMode             = 20007,
    PIDXPcrw_MaxLine             = 20008,
    PIDXPcrw_PrintHeight         = 20009,
    PIDXPcrw_ReadState1          = 20010,
    PIDXPcrw_ReadState2          = 20011,
    PIDXPcrw_RecvLength1         = 20012,
    PIDXPcrw_RecvLength2         = 20013,
    PIDXPcrw_SidewaysMaxChars    = 20014,
    PIDXPcrw_SidewaysMaxLines    = 20015,
    PIDXPcrw_TracksToRead        = 20016,
    PIDXPcrw_TracksToWrite       = 20017,
    PIDXPcrw_WriteState1         = 20018,
    PIDXPcrw_WriteState2         = 20019,
    PIDXPcrw_MapCharacterSet     = 20020,

    PIDXPcrw_CapBold               = 20501,
    PIDXPcrw_CapCardEntranceSensor = 20502,
    PIDXPcrw_CapCharacterSet       = 20503,
    PIDXPcrw_CapCleanCard          = 20504,
    PIDXPcrw_CapClearPrint         = 20505,
    PIDXPcrw_CapDhigh              = 20506,
    PIDXPcrw_CapDwide              = 20507,
    PIDXPcrw_CapDwideDhigh         = 20508,
    PIDXPcrw_CapItalic             = 20509,
    PIDXPcrw_CapLeft90             = 20510,
    PIDXPcrw_CapPrint              = 20511,
    PIDXPcrw_CapPrintMode          = 20512,
    PIDXPcrw_CapRight90            = 20513,
    PIDXPcrw_CapRotate180          = 20514,
    PIDXPcrw_CapTracksToRead       = 20515,
    PIDXPcrw_CapTracksToWrite      = 20516,
    PIDXPcrw_CapMapCharacterSet    = 20517,

    PIDXPcrw_CharacterSetList    = 120001,
    PIDXPcrw_FontTypeFaceList    = 120002,
    PIDXPcrw_LineCharsList       = 120003,
    PIDXPcrw_Track1Data          = 120004,
    PIDXPcrw_Track2Data          = 120005,
    PIDXPcrw_Track3Data          = 120006,
    PIDXPcrw_Track4Data          = 120007,
    PIDXPcrw_Track5Data          = 120008,
    PIDXPcrw_Track6Data          = 120009,
    PIDXPcrw_Write1Data          = 120010,
    PIDXPcrw_Write2Data          = 120011,
    PIDXPcrw_Write3Data          = 120012,
    PIDXPcrw_Write4Data          = 120013,
    PIDXPcrw_Write5Data          = 120014,
    PIDXPcrw_Write6Data          = 120015
} OPOSPointCardRWInternals;
