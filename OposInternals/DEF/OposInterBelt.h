//*************************************************************************
//** OPOS Belt Internals
//
//   Belt header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS Belt Internals")]
enum
{
    PIDXBelt_AutoStopBackward                = 31001,
    PIDXBelt_AutoStopBackwardDelayTime       = 31002,
    PIDXBelt_AutoStopBackwardItemCount       = 31003,
    PIDXBelt_AutoStopForward                 = 31004,
    PIDXBelt_AutoStopForwardDelayTime        = 31005,
    PIDXBelt_AutoStopForwardItemCount        = 31006,
    PIDXBelt_LightBarrierBackwardInterrupted = 31007,
    PIDXBelt_LightBarrierForwardInterrupted  = 31008,
    PIDXBelt_MotionStatus                    = 31009,
    PIDXBelt_SecurityFlapBackwardOpened      = 31010,
    PIDXBelt_SecurityFlapForwardOpened       = 31011,

    PIDXBelt_CapAutoStopBackward             = 31501,
    PIDXBelt_CapAutoStopBackwardItemCount    = 31502,
    PIDXBelt_CapAutoStopForward              = 31503,
    PIDXBelt_CapAutoStopForwardItemCount     = 31504,
    PIDXBelt_CapLightBarrierBackward         = 31505,
    PIDXBelt_CapLightBarrierForward          = 31506,
    PIDXBelt_CapMoveBackward                 = 31507,
    PIDXBelt_CapSecurityFlapBackward         = 31508,
    PIDXBelt_CapSecurityFlapForward          = 31509,
    PIDXBelt_CapSpeedStepsBackward           = 31510,
    PIDXBelt_CapSpeedStepsForward            = 31511
} OPOSBeltInternals;
