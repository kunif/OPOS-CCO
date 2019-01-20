//*************************************************************************
//** OPOS Keylock Internals
//
//   Keylock header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS Keylock Internals")]
enum
{
    PIDXLock_KeyPosition         =  4001,
    PIDXLock_PositionCount       =  4002,

    PIDXLock_CapKeylockType      =  4501,

    PIDXLock_ElectronicKeyValue  = 104001
} OPOSKeylockInternals;
