//*************************************************************************
//** OPOS ItemDispenser Internals
//
//   Item Dispenser header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS ItemDispenser Internals")]
enum
{
    PIDXItem_DispenserStatus                 = 34001,
    PIDXItem_MaxSlots                        = 34002,

    PIDXItem_CapEmptySensor                  = 34501,
    PIDXItem_CapIndividualSlotStatus         = 34502,
    PIDXItem_CapJamSensor                    = 34503,
    PIDXItem_CapNearEmptySensor              = 34504
} OPOSItemDispenserInternals;
