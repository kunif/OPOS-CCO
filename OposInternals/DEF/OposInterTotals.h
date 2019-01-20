//*************************************************************************
//** OPOS HardTotals Internals
//
//   HardTotals header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS HardTotals Internals")]
enum
{
    PIDXTot_FreeData             =  3001,
    PIDXTot_NumberOfFiles        =  3002,
    PIDXTot_TotalsSize           =  3003,
    PIDXTot_TransactionInProgress=  3004,

    PIDXTot_CapErrorDetection    =  3501,
    PIDXTot_CapSingleFile        =  3502,
    PIDXTot_CapTransactions      =  3503
} OPOSTotalsInternals;
