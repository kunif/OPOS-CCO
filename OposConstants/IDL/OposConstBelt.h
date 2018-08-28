//*************************************************************************
//** OPOS Belt Constants
//*************************************************************************

typedef [helpstring("OPOS Belt Constants")]
enum
{
    BELT_MT_FORWARD                           = 1,
    BELT_MT_BACKWARD                          = 2,
    BELT_MT_STOPPED                           = 3,
    BELT_MT_EMERGENCY                         = 4,
    BELT_MT_MOTOR_FAULT                       = 5,
    BELT_AIC_BACKWARD                         = 1,
    BELT_AIC_FORWARD                          = 2,
    BELT_RIC_BACKWARD                         = 1,
    BELT_RIC_FORWARD                          = 2,
    BELT_SUE_AUTO_STOP                        = 11,
    BELT_SUE_EMERGENCY_STOP                   = 12,
    BELT_SUE_SAFETY_STOP                      = 13,
    BELT_SUE_TIMEOUT_STOP                     = 14,
    BELT_SUE_MOTOR_OVERHEATING                = 15,
    BELT_SUE_MOTOR_FUSE_DEFECT                = 16,
    BELT_SUE_LIGHT_BARRIER_BACKWARD_INTERRUPTED = 17,
    BELT_SUE_LIGHT_BARRIER_BACKWARD_OK        = 18,
    BELT_SUE_LIGHT_BARRIER_FORWARD_INTERRUPTED = 19,
    BELT_SUE_LIGHT_BARRIER_FORWARD_OK         = 20,
    BELT_SUE_SECURITY_FLAP_BACKWARD_OPENED    = 21,
    BELT_SUE_SECURITY_FLAP_BACKWARD_CLOSED    = 22,
    BELT_SUE_SECURITY_FLAP_FORWARD_OPENED     = 23,
    BELT_SUE_SECURITY_FLAP_FORWARD_CLOSED     = 24
} OPOSBeltConstants;
