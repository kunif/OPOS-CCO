//*************************************************************************
//** OPOS GestureControl Internals
//
//   GestureControl header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS GestureControl Internals")]
enum
{
    PIDXGctl_PoseCreationMode                 = 38001,
    PIDXGctl_Storage                          = 38002,

    PIDXGctl_CapMotion                        = 38501,
    PIDXGctl_CapMotionCreation                = 38502,
    PIDXGctl_CapPose                          = 38503,
    PIDXGctl_CapPoseCreation                  = 38504,
    PIDXGctl_CapStorage                       = 38505,

    PIDXGctl_AutoMode                         = 1038001,
    PIDXGctl_AutoModeList                     = 1038002,
    PIDXGctl_JoinList                         = 1038003,
    PIDXGctl_MotionList                       = 1038004,
    PIDXGctl_PoseList                         = 1038005,

    PIDXGctl_CapAssociatedHardTotalsDevice    = 1038501
} OPOSGestureControlInternals;
