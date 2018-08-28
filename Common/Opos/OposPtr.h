/////////////////////////////////////////////////////////////////////
//
// OposPtr.h
//
//   POS Printer header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1995-12-08 OPOS Release 1.0                                   CRM
// 1996-04-22 OPOS Release 1.1                                   CRM
//   Add CapCharacterSet constants.
//   Add ErrorLevel constants.
//   Add TransactionPrint's Control constants.
// 1997-06-04 OPOS Release 1.2                                   CRM
//   Remove PTR_RP_NORMAL_ASYNC.
//   Add more barcode symbologies.
// 1998-03-06 OPOS Release 1.3                                   CRM
//   Add more PrintTwoNormal constants.
// 2000-09-24 OPOS Release 1.5                             EPSON/BKS
//   Add CapRecMarkFeed and MarkFeed's Type constants.
//   Add ChangePrintSide constants.
//   Add StatusUpdateEvent constants.
//   Add ResultCodeExtended constants.
//   Add CapXxxCartridgeSensor and XxxCartridgeState constants.
//   Add CartridgeNotify constants.
//   Add CapCharacterset and CharacterSet constants for UNICODE.
// 2003-05-29 OPOS Release 1.7                                   CRM
//   Add more RotatePrint's Rotation PTR_RP_* constants.
// 2004-03-22 OPOS Release 1.8                                   CRM
//   Add more constants for PrintBarCode method and StatusUpdateEvent.
// 2004-10-26 Add "CharacterSet" ANSI constant (from 1.5).       CRM
// 2005-04-29 OPOS Release 1.9                                   CRM
//   Add PageModeDescriptor and PageModePrintDirection constants.
//   Add PageModePrint's Control constants.
// 2006-03-15 OPOS Release 1.10                                  CRM
//   Add PrintMemoryBitmap constants.
// 2008-08-30 OPOS Release 1.12                                  CRM
//   Add more constants for PrintBarCode method.
// 2009-10-02 OPOS Release 1.13                                  CRM
//   Add CapRecRuledLine and CapSlpRuledLine constants.
//   Add DrawRuledLine constants.
//   Add more constants for PrintBarCode method.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSPTR_H)
#define      OPOSPTR_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// Printer Station Constants
/////////////////////////////////////////////////////////////////////

const LONG PTR_S_JOURNAL        = 1;
const LONG PTR_S_RECEIPT        = 2;
const LONG PTR_S_SLIP           = 4;

const LONG PTR_S_JOURNAL_RECEIPT    = 0x0003;
const LONG PTR_S_JOURNAL_SLIP       = 0x0005;
const LONG PTR_S_RECEIPT_SLIP       = 0x0006;

const LONG PTR_TWO_RECEIPT_JOURNAL  = 0x8003; // (added in 1.3)
const LONG PTR_TWO_SLIP_JOURNAL     = 0x8005; // (added in 1.3)
const LONG PTR_TWO_SLIP_RECEIPT     = 0x8006; // (added in 1.3)


/////////////////////////////////////////////////////////////////////
// "CapCharacterSet" Property Constants (added in 1.1)
/////////////////////////////////////////////////////////////////////

const LONG PTR_CCS_ALPHA        =   1;
const LONG PTR_CCS_ASCII        = 998;
const LONG PTR_CCS_KANA         =  10;
const LONG PTR_CCS_KANJI        =  11;
const LONG PTR_CCS_UNICODE      = 997; // (added in 1.5)


/////////////////////////////////////////////////////////////////////
// "CharacterSet" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PTR_CS_UNICODE       = 997; // (added in 1.5)
const LONG PTR_CS_ASCII         = 998;
const LONG PTR_CS_WINDOWS       = 999;
const LONG PTR_CS_ANSI          = 999;


/////////////////////////////////////////////////////////////////////
// "ErrorLevel" Property Constants (added in 1.1)
/////////////////////////////////////////////////////////////////////

const LONG PTR_EL_NONE          = 1;
const LONG PTR_EL_RECOVERABLE   = 2;
const LONG PTR_EL_FATAL         = 3;


/////////////////////////////////////////////////////////////////////
// "MapMode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PTR_MM_DOTS          = 1;
const LONG PTR_MM_TWIPS         = 2;
const LONG PTR_MM_ENGLISH       = 3;
const LONG PTR_MM_METRIC        = 4;


/////////////////////////////////////////////////////////////////////
// "CapXxxColor" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PTR_COLOR_PRIMARY      = 0x00000001;
const LONG PTR_COLOR_CUSTOM1      = 0x00000002;
const LONG PTR_COLOR_CUSTOM2      = 0x00000004;
const LONG PTR_COLOR_CUSTOM3      = 0x00000008;
const LONG PTR_COLOR_CUSTOM4      = 0x00000010;
const LONG PTR_COLOR_CUSTOM5      = 0x00000020;
const LONG PTR_COLOR_CUSTOM6      = 0x00000040;
const LONG PTR_COLOR_CYAN         = 0x00000100;
const LONG PTR_COLOR_MAGENTA      = 0x00000200;
const LONG PTR_COLOR_YELLOW       = 0x00000400;
const LONG PTR_COLOR_FULL         = 0x80000000;


/////////////////////////////////////////////////////////////////////
// "CapXxxCartridgeSensor" and  "XxxCartridgeState" Property Constants
//   (added in 1.5)
/////////////////////////////////////////////////////////////////////

const LONG PTR_CART_UNKNOWN         = 0x10000000;
const LONG PTR_CART_OK              = 0x00000000;
const LONG PTR_CART_REMOVED         = 0x00000001;
const LONG PTR_CART_EMPTY           = 0x00000002;
const LONG PTR_CART_NEAREND         = 0x00000004;
const LONG PTR_CART_CLEANING        = 0x00000008;


/////////////////////////////////////////////////////////////////////
// "CartridgeNotify" Property Constants (added in 1.5)
/////////////////////////////////////////////////////////////////////

const LONG PTR_CN_DISABLED        = 0x00000000;
const LONG PTR_CN_ENABLED         = 0x00000001;


/////////////////////////////////////////////////////////////////////
// "PageModeDescriptor" Property Constants (added in 1.9)
/////////////////////////////////////////////////////////////////////

const LONG PTR_PM_BITMAP         = 0x00000001;
const LONG PTR_PM_BARCODE        = 0x00000002;
const LONG PTR_PM_BM_ROTATE      = 0x00000004;
const LONG PTR_PM_BC_ROTATE      = 0x00000008;
const LONG PTR_PM_OPAQUE         = 0x00000010;


/////////////////////////////////////////////////////////////////////
// "PageModePrintDirection" Property Constants (added in 1.9)
/////////////////////////////////////////////////////////////////////

const LONG PTR_PD_LEFT_TO_RIGHT = 1;
const LONG PTR_PD_BOTTOM_TO_TOP = 2;
const LONG PTR_PD_RIGHT_TO_LEFT = 3;
const LONG PTR_PD_TOP_TO_BOTTOM = 4;


/////////////////////////////////////////////////////////////////////
// "CutPaper" Method Constant
/////////////////////////////////////////////////////////////////////

const LONG PTR_CP_FULLCUT       = 100;


/////////////////////////////////////////////////////////////////////
// "PageModePrint" Method: "Control" Parameter Constants (added in 1.9)
/////////////////////////////////////////////////////////////////////

const LONG PTR_PM_PAGE_MODE      = 1;
const LONG PTR_PM_PRINT_SAVE     = 2;
const LONG PTR_PM_NORMAL         = 3;
const LONG PTR_PM_CANCEL         = 4;


/////////////////////////////////////////////////////////////////////
// "PrintBarCode" Method Constants:
/////////////////////////////////////////////////////////////////////

//** "Alignment" Parameter
//     Either the distance from the left-most print column to the start
//     of the bar code, or one of the following:

const LONG PTR_BC_LEFT          = -1;
const LONG PTR_BC_CENTER        = -2;
const LONG PTR_BC_RIGHT         = -3;

//** "TextPosition" Parameter

const LONG PTR_BC_TEXT_NONE     = -11;
const LONG PTR_BC_TEXT_ABOVE    = -12;
const LONG PTR_BC_TEXT_BELOW    = -13;

//** "Symbology" Parameter:

//    - One dimensional symbologies
const LONG PTR_BCS_UPCA         = 101;  // Digits
const LONG PTR_BCS_UPCE         = 102;  // Digits
const LONG PTR_BCS_JAN8         = 103;  // = EAN 8
const LONG PTR_BCS_EAN8         = 103;  // = JAN 8 (added in 1.2)
const LONG PTR_BCS_JAN13        = 104;  // = EAN 13
const LONG PTR_BCS_EAN13        = 104;  // = JAN 13 (added in 1.2)
const LONG PTR_BCS_TF           = 105;  // (Discrete 2 of 5) Digits
const LONG PTR_BCS_ITF          = 106;  // (Interleaved 2 of 5) Digits
const LONG PTR_BCS_Codabar      = 107;  // Digits, -, $, :, /, ., +;
                                        //   4 start/stop characters
                                        //   (a, b, c, d)
const LONG PTR_BCS_Code39       = 108;  // Alpha, Digits, Space, -, .,
                                        //   $, /, +, %; start/stop (*)
                                        // Also has Full ASCII feature
const LONG PTR_BCS_Code93       = 109;  // Same characters as Code 39
const LONG PTR_BCS_Code128      = 110;  // 128 data characters

//    - One dimensional symbologies (added in 1.2)
const LONG PTR_BCS_UPCA_S       = 111;  // UPC-A with supplemental
                                        //   barcode
const LONG PTR_BCS_UPCE_S       = 112;  // UPC-E with supplemental
                                        //   barcode
const LONG PTR_BCS_UPCD1        = 113;  // UPC-D1
const LONG PTR_BCS_UPCD2        = 114;  // UPC-D2
const LONG PTR_BCS_UPCD3        = 115;  // UPC-D3
const LONG PTR_BCS_UPCD4        = 116;  // UPC-D4
const LONG PTR_BCS_UPCD5        = 117;  // UPC-D5
const LONG PTR_BCS_EAN8_S       = 118;  // EAN 8 with supplemental
                                        //   barcode
const LONG PTR_BCS_EAN13_S      = 119;  // EAN 13 with supplemental
                                        //   barcode
const LONG PTR_BCS_EAN128       = 120;  // EAN 128
const LONG PTR_BCS_OCRA         = 121;  // OCR "A"
const LONG PTR_BCS_OCRB         = 122;  // OCR "B"

//    - One dimensional symbologies (added in 1.8)
const LONG PTR_BCS_Code128_Parsed=123;  // Code 128 with parsing
//        The following RSS constants deprecated in 1.12.
//        Instead use the GS1DATABAR constants below.
const LONG PTR_BCS_RSS14        = 131;  // Reduced Space Symbology - 14 digit GTIN
const LONG PTR_BCS_RSS_EXPANDED = 132;  // RSS - 14 digit GTIN plus additional fields

//    - One dimensional symbologies (added in 1.12)
const LONG PTR_BCS_GS1DATABAR    =131;  // GS1 DataBar Omnidirectional
const LONG PTR_BCS_GS1DATABAR_E  =132;  // GS1 DataBar Expanded
const LONG PTR_BCS_GS1DATABAR_S  =133;  // GS1 DataBar Stacked Omnidirectional
const LONG PTR_BCS_GS1DATABAR_E_S=134;  // GS1 DataBar Expanded Stacked

//    - Two dimensional symbologies
const LONG PTR_BCS_PDF417       = 201;
const LONG PTR_BCS_MAXICODE     = 202;

//    - Two dimensional symbologies (added in 1.13)
const LONG PTR_BCS_DATAMATRIX   = 203;  // Data Matrix
const LONG PTR_BCS_QRCODE       = 204;  // QR Code
const LONG PTR_BCS_UQRCODE      = 205;  // Micro QR Code
const LONG PTR_BCS_AZTEC        = 206;  // Aztec
const LONG PTR_BCS_UPDF417      = 207;  // Micro PDF 417

//    - Start of Printer-Specific bar code symbologies
const LONG PTR_BCS_OTHER        = 501;


/////////////////////////////////////////////////////////////////////
// "PrintBitmap" and "PrintMemoryBitmap" Method Constants:
/////////////////////////////////////////////////////////////////////

//** "Width" Parameter
//     Either bitmap width or:

const LONG PTR_BM_ASIS          = -11;  // One pixel per printer dot

//** "Alignment" Parameter
//     Either the distance from the left-most print column to the start
//     of the bitmap, or one of the following:

const LONG PTR_BM_LEFT          = -1;
const LONG PTR_BM_CENTER        = -2;
const LONG PTR_BM_RIGHT         = -3;

//** "Type" Parameter ("PrintMemoryBitmap" only)
const LONG PTR_BMT_BMP          = 1;
const LONG PTR_BMT_JPEG         = 2;
const LONG PTR_BMT_GIF          = 3;


/////////////////////////////////////////////////////////////////////
// "RotatePrint" Method: "Rotation" Parameter Constants
// "RotateSpecial" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG PTR_RP_NORMAL        = 0x0001;
const LONG PTR_RP_RIGHT90       = 0x0101;
const LONG PTR_RP_LEFT90        = 0x0102;
const LONG PTR_RP_ROTATE180     = 0x0103;

// For "RotatePrint", one or both of the following values may be
// ORed with one of the above values.
const LONG PTR_RP_BARCODE       = 0x1000; // (added in 1.7)
const LONG PTR_RP_BITMAP        = 0x2000; // (added in 1.7)


/////////////////////////////////////////////////////////////////////
// "SetLogo" Method: "Location" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG PTR_L_TOP            = 1;
const LONG PTR_L_BOTTOM         = 2;


/////////////////////////////////////////////////////////////////////
// "TransactionPrint" Method: "Control" Parameter Constants (added in 1.1)
/////////////////////////////////////////////////////////////////////

const LONG PTR_TP_TRANSACTION   = 11;
const LONG PTR_TP_NORMAL        = 12;


/////////////////////////////////////////////////////////////////////
// "MarkFeed" Method: "Type" Parameter Constants (added in 1.5)
// "CapRecMarkFeed" Property Constants (added in 1.5)
/////////////////////////////////////////////////////////////////////

const LONG PTR_MF_TO_TAKEUP     = 1;
const LONG PTR_MF_TO_CUTTER     = 2;
const LONG PTR_MF_TO_CURRENT_TOF= 4;
const LONG PTR_MF_TO_NEXT_TOF   = 8;


/////////////////////////////////////////////////////////////////////
// "ChangePrintSide" Method: "Side" Parameter Constants (added in 1.5)
/////////////////////////////////////////////////////////////////////

const LONG PTR_PS_UNKNOWN       = 0;
const LONG PTR_PS_SIDE1         = 1;
const LONG PTR_PS_SIDE2         = 2;
const LONG PTR_PS_OPPOSITE      = 3;


/////////////////////////////////////////////////////////////////////
// "CapRecRuledLine" and "CapSlpRuledLine" Property Constants
// "DrawRuledLine" Method: "LineDirection" Parameter Constants
// (added in 1.13)
/////////////////////////////////////////////////////////////////////

const LONG PTR_RL_HORIZONTAL = 1;
const LONG PTR_RL_VERTICAL   = 2;


/////////////////////////////////////////////////////////////////////
// "DrawRuledLine" Method: "LineStyle" Parameter Constants
// (added in 1.13)
/////////////////////////////////////////////////////////////////////

const LONG PTR_LS_SINGLE_SOLID_LINE = 1;
const LONG PTR_LS_DOUBLE_SOLID_LINE = 2;
const LONG PTR_LS_BROKEN_LINE       = 3;
const LONG PTR_LS_CHAIN_LINE        = 4;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG PTR_SUE_COVER_OPEN              = 11;
const LONG PTR_SUE_COVER_OK                = 12;
const LONG PTR_SUE_JRN_COVER_OPEN          = 60;  // (added in 1.8)
const LONG PTR_SUE_JRN_COVER_OK            = 61;  // (added in 1.8)
const LONG PTR_SUE_REC_COVER_OPEN          = 62;  // (added in 1.8)
const LONG PTR_SUE_REC_COVER_OK            = 63;  // (added in 1.8)
const LONG PTR_SUE_SLP_COVER_OPEN          = 64;  // (added in 1.8)
const LONG PTR_SUE_SLP_COVER_OK            = 65;  // (added in 1.8)

const LONG PTR_SUE_JRN_EMPTY               = 21;
const LONG PTR_SUE_JRN_NEAREMPTY           = 22;
const LONG PTR_SUE_JRN_PAPEROK             = 23;

const LONG PTR_SUE_REC_EMPTY               = 24;
const LONG PTR_SUE_REC_NEAREMPTY           = 25;
const LONG PTR_SUE_REC_PAPEROK             = 26;

const LONG PTR_SUE_SLP_EMPTY               = 27;
const LONG PTR_SUE_SLP_NEAREMPTY           = 28;
const LONG PTR_SUE_SLP_PAPEROK             = 29;

const LONG PTR_SUE_JRN_CARTRIDGE_EMPTY     = 41; // (added in 1.5)
const LONG PTR_SUE_JRN_CARTRIDGE_NEAREMPTY = 42; // (added in 1.5)
const LONG PTR_SUE_JRN_HEAD_CLEANING       = 43; // (added in 1.5)
const LONG PTR_SUE_JRN_CARTRIDGE_OK        = 44; // (added in 1.5)

const LONG PTR_SUE_REC_CARTRIDGE_EMPTY     = 45; // (added in 1.5)
const LONG PTR_SUE_REC_CARTRIDGE_NEAREMPTY = 46; // (added in 1.5)
const LONG PTR_SUE_REC_HEAD_CLEANING       = 47; // (added in 1.5)
const LONG PTR_SUE_REC_CARTRIDGE_OK        = 48; // (added in 1.5)

const LONG PTR_SUE_SLP_CARTRIDGE_EMPTY     = 49; // (added in 1.5)
const LONG PTR_SUE_SLP_CARTRIDGE_NEAREMPTY = 50; // (added in 1.5)
const LONG PTR_SUE_SLP_HEAD_CLEANING       = 51; // (added in 1.5)
const LONG PTR_SUE_SLP_CARTRIDGE_OK        = 52; // (added in 1.5)

const LONG PTR_SUE_IDLE                    = 1001;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EPTR_COVER_OPEN            = 201; // (Several)
const LONG OPOS_EPTR_JRN_EMPTY             = 202; // (Several)
const LONG OPOS_EPTR_REC_EMPTY             = 203; // (Several)
const LONG OPOS_EPTR_SLP_EMPTY             = 204; // (Several)
const LONG OPOS_EPTR_SLP_FORM              = 205; // EndRemoval
const LONG OPOS_EPTR_TOOBIG                = 206; // PrintBitmap
const LONG OPOS_EPTR_BADFORMAT             = 207; // PrintBitmap
const LONG OPOS_EPTR_JRN_CARTRIDGE_REMOVED = 208; // (Several) (added in 1.5)
const LONG OPOS_EPTR_JRN_CARTRIDGE_EMPTY   = 209; // (Several) (added in 1.5)
const LONG OPOS_EPTR_JRN_HEAD_CLEANING     = 210; // (Several) (added in 1.5)
const LONG OPOS_EPTR_REC_CARTRIDGE_REMOVED = 211; // (Several) (added in 1.5)
const LONG OPOS_EPTR_REC_CARTRIDGE_EMPTY   = 212; // (Several) (added in 1.5)
const LONG OPOS_EPTR_REC_HEAD_CLEANING     = 213; // (Several) (added in 1.5)
const LONG OPOS_EPTR_SLP_CARTRIDGE_REMOVED = 214; // (Several) (added in 1.5)
const LONG OPOS_EPTR_SLP_CARTRIDGE_EMPTY   = 215; // (Several) (added in 1.5)
const LONG OPOS_EPTR_SLP_HEAD_CLEANING     = 216; // (Several) (added in 1.5)


#endif                  // !defined(OPOSPTR_H)
