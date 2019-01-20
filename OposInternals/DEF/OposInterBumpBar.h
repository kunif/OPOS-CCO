//*************************************************************************
//** OPOS BumpBar Internals
//
//   Bump Bar header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS BumpBar Internals")]
enum
{
    PIDXBb_AsyncMode             = 15001,
    PIDXBb_AutoToneDuration      = 15002,
    PIDXBb_AutoToneFrequency     = 15003,
    PIDXBb_BumpBarDataCount      = 15004,
    PIDXBb_CurrentUnitID         = 15005,
    PIDXBb_ErrorUnits            = 15006,
    PIDXBb_EventUnitID           = 15007,
    PIDXBb_EventUnits            = 15008,
    PIDXBb_Keys                  = 15009,
    PIDXBb_Timeout               = 15010,
    PIDXBb_UnitsOnline           = 15011,

    PIDXBb_CapTone               = 15501,

    PIDXBb_ErrorString           = 115001,
    PIDXBb_EventString           = 115002
} OPOSBumpBarInternals;
