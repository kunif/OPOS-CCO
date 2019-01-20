//*************************************************************************
//** OPOS Scale Internals
//
//   Scale header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS Scale Internals")]
enum
{
    PIDXScal_MaximumWeight       =  9001,
    PIDXScal_WeightUnits         =  9002,
    PIDXScal_WeightUnit          =  9002,
    PIDXScal_AsyncMode           =  9003,
    PIDXScal_MaxDisplayTextChars =  9004,
    PIDXScal_TareWeight          =  9005,
    PIDXScal_ScaleLiveWeight     =  9006,
    PIDXScal_StatusNotify        =  9007,
    PIDXScal_ZeroValid           =  9008,
    PIDXScal_MinimumWeight       =  9009,

    PIDXScal_CapDisplay          =  9501,
    PIDXScal_CapDisplayText      =  9502,
    PIDXScal_CapPriceCalculating =  9503,
    PIDXScal_CapTareWeight       =  9504,
    PIDXScal_CapZeroScale        =  9505,
    PIDXScal_CapStatusUpdate     =  9506,
    PIDXScal_CapFreezeValue                  =  9507,
    PIDXScal_CapReadLiveWeightWithTare       =  9508,
    PIDXScal_CapSetPriceCalculationMode      =  9509,
    PIDXScal_CapSetUnitPriceWithWeightUnit   =  9510,
    PIDXScal_CapSpecialTare                  =  9511,
    PIDXScal_CapTarePriority                 =  9512
} OPOSScaleInternals;
