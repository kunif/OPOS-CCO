//*************************************************************************
//** OPOS Scanner Internals
//
//   Scanner header file for OPOS Controls and Service Objects.
//
//*************************************************************************

typedef [helpstring("OPOS Scanner Internals")]
enum
{
    PIDXScan_DecodeData         = 10001,
    PIDXScan_ScanDataType       = 10002,

    PIDXScan_ScanData           = 1010001,
    PIDXScan_ScanDataLabel      = 1010002
} OPOSScannerInternals;
