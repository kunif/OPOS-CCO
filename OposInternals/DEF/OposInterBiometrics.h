//*************************************************************************
//** OPOS Biometrics Internals
//
//   Biometrics header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS Biometrics Internals")]
enum
{
    PIDXBio_Algorithm                = 25001,
    PIDXBio_RealTimeDataEnabled      = 25002,
    PIDXBio_SensorBPP                = 25003,
    PIDXBio_SensorColor              = 25004,
    PIDXBio_SensorHeight             = 25005,
    PIDXBio_SensorOrientation        = 25006,
    PIDXBio_SensorType               = 25007,
    PIDXBio_SensorWidth              = 25008,

    PIDXBio_CapPrematchData          = 25501,
    PIDXBio_CapRawSensorData         = 25502,
    PIDXBio_CapRealTimeData          = 25503,
    PIDXBio_CapSensorColor           = 25504,
    PIDXBio_CapSensorOrientation     = 25505,
    PIDXBio_CapSensorType            = 25506,
    PIDXBio_CapTemplateAdaptation    = 25507,

    PIDXBio_AlgorithmList            = 1025001,
    PIDXBio_BIR                      = 1025002,
    PIDXBio_RawSensorData            = 1025003
} OPOSBiometricsInternals;
