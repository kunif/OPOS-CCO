//*************************************************************************
//** OPOS SmartCardRW Internals
//
//   Smart Card Reader Writer  header file for OPOS Controls and
//   Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS SmartCardRW Internals")]
enum
{
    PIDXScrw_InterfaceMode           = 24001,
    PIDXScrw_IsoEmvMode              = 24002,
    PIDXScrw_SCPresentSensor         = 24003,
    PIDXScrw_SCSlot                  = 24004,
    PIDXScrw_TransactionInProgress   = 24005,
    PIDXScrw_TransmissionProtocol    = 24006,

    PIDXScrw_CapCardErrorDetection   = 24501,
    PIDXScrw_CapInterfaceMode        = 24502,
    PIDXScrw_CapIsoEmvMode           = 24503,
    PIDXScrw_CapSCPresentSensor      = 24504,
    PIDXScrw_CapSCSlots              = 24505,
    PIDXScrw_CapTransmissionProtocol = 24506
} OPOSSmartCardRWInternals;
