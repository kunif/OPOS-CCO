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

    PIDXScan_ScanData           = 110001,
    PIDXScan_ScanDataLabel      = 110002
} OPOSScannerInternals;
