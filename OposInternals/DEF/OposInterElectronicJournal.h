//*************************************************************************
//** OPOS ElectronicJournal Internals
//
//   Electronic Journal header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS ElectronicJournal Internals")]
enum
{
    PIDXEj_AsyncMode                 = 26001,
    PIDXEj_FlagWhenIdle              = 26002,
    PIDXEj_MediumIsAvailable         = 26003,
    PIDXEj_Station                   = 26004,
    PIDXEj_StorageEnabled            = 26005,
    PIDXEj_Suspended                 = 26006,
    PIDXEj_WaterMark                 = 26007,

    PIDXEj_CapAddMarker              = 26501,
    PIDXEj_CapErasableMedium         = 26502,
    PIDXEj_CapInitializeMedium       = 26503,
    PIDXEj_CapMediumIsAvailable      = 26504,
    PIDXEj_CapPrintContent           = 26505,
    PIDXEj_CapPrintContentFile       = 26506,
    PIDXEj_CapRetrieveCurrentMarker  = 26507,
    PIDXEj_CapRetrieveMarker         = 26508,
    PIDXEj_CapRetrieveMarkerByDateTime=26509,
    PIDXEj_CapRetrieveMarkersDateTime= 26510,
    PIDXEj_CapStation                = 26511,
    PIDXEj_CapStorageEnabled         = 26512,
    PIDXEj_CapSuspendPrintContent    = 26513,
    PIDXEj_CapSuspendQueryContent    = 26514,
    PIDXEj_CapWaterMark              = 26515,

    PIDXEj_MediumID                  = 126001
} OPOSElectronicJournalInternals;
