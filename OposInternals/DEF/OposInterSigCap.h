//*************************************************************************
//** OPOS SigCap Internals
//
//   Signature Capture header file for OPOS Controls and
//     Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS SigCap Internals")]
enum
{
    PIDXSig_MaximumX             = 11001,
    PIDXSig_MaximumY             = 11002,
    PIDXSig_TotalPoints          = 11003,
    PIDXSig_RealTimeDataEnabled  = 11004,

    PIDXSig_CapDisplay           = 11501,
    PIDXSig_CapUserTerminated    = 11502,
    PIDXSig_CapRealTimeData      = 11503,

    PIDXSig_RawData              = 1011001,
    PIDXSig_PointArray           = 1011002
} OPOSSigCapInternals;
