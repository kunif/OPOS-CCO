/////////////////////////////////////////////////////////////////////
//
// OposScan.h
//
//   Scanner header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1995-12-08 OPOS Release 1.0                                   CRM
// 1997-06-04 OPOS Release 1.2                                   CRM
// 2004-03-22 OPOS Release 1.8                                   CRM
// 2007-01-30 OPOS Release 1.11                                  CRM
// 2008-08-30 OPOS Release 1.12                                  CRM
//   Add more constants for ScanDataType property.
// 2013-10-03 OPOS Release 1.14                                  CRM
//   Add more constants for ScanDataType property.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSSCAN_H)
#define      OPOSSCAN_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "ScanDataType" Property Constants (added in 1.2)
/////////////////////////////////////////////////////////////////////

// - One dimensional symbologies
const LONG SCAN_SDT_UPCA                = 101;  // Digits
const LONG SCAN_SDT_UPCE                = 102;  // Digits
const LONG SCAN_SDT_JAN8                = 103;  // = EAN 8
const LONG SCAN_SDT_EAN8                = 103;  // = JAN 8 (added in 1.2)
const LONG SCAN_SDT_JAN13               = 104;  // = EAN 13
const LONG SCAN_SDT_EAN13               = 104;  // = JAN 13 (added in 1.2)
const LONG SCAN_SDT_TF                  = 105;  // (Discrete 2 of 5) Digits
const LONG SCAN_SDT_ITF                 = 106;  // (Interleaved 2 of 5) Digits
const LONG SCAN_SDT_Codabar             = 107;  // Digits, -, $, :, /, ., +; 4 start/stop characters (a, b, c, d)
const LONG SCAN_SDT_Code39              = 108;  // Alpha, Digits, Space, -, ., $, /, +, %; start/stop (*)
                                                //   Also has Full ASCII feature
const LONG SCAN_SDT_Code93              = 109;  // Same characters as Code 39
const LONG SCAN_SDT_Code128             = 110;  // 128 data characters

const LONG SCAN_SDT_UPCA_S              = 111;  // UPC-A with supplemental barcode
const LONG SCAN_SDT_UPCE_S              = 112;  // UPC-E with supplemental barcode
const LONG SCAN_SDT_UPCD1               = 113;  // UPC-D1
const LONG SCAN_SDT_UPCD2               = 114;  // UPC-D2
const LONG SCAN_SDT_UPCD3               = 115;  // UPC-D3
const LONG SCAN_SDT_UPCD4               = 116;  // UPC-D4
const LONG SCAN_SDT_UPCD5               = 117;  // UPC-D5
const LONG SCAN_SDT_EAN8_S              = 118;  // EAN 8 with supplemental barcode
const LONG SCAN_SDT_EAN13_S             = 119;  // EAN 13 with supplemental barcode
const LONG SCAN_SDT_EAN128              = 120;  // EAN 128
const LONG SCAN_SDT_OCRA                = 121;  // OCR "A"
const LONG SCAN_SDT_OCRB                = 122;  // OCR "B"

// - One dimensional symbologies (added in 1.8)
//        The following RSS constants deprecated in 1.12.
//        Instead use the GS1DATABAR constants below.
const LONG SCAN_SDT_RSS14               = 131;  // Reduced Space Symbology - 14 digit GTIN
const LONG SCAN_SDT_RSS_EXPANDED        = 132;  // RSS - 14 digit GTIN plus additional fields

// - One dimensional symbologies (added in 1.12)
const LONG SCAN_SDT_GS1DATABAR          = 131;  // GS1 DataBar Omnidirectional (normal or stacked)
const LONG SCAN_SDT_GS1DATABAR_E        = 132;  // GS1 DataBar Expanded (normal or stacked)

// - One dimensional symbologies (added in Release 1.14)
const LONG SCAN_SDT_ITF_CK              = 133;  // Interleaved 2 of 5 check digit verified and transmitted
const LONG SCAN_SDT_GS1DATABAR_TYPE2    = 134;  // GS1 DataBar Limited
const LONG SCAN_SDT_AMES                = 135;  // Ames Code
const LONG SCAN_SDT_TFMAT               = 136;  // Matrix 2 of 5
const LONG SCAN_SDT_Code39_CK           = 137;  // Code 39 with check character verified and transmitted
const LONG SCAN_SDT_Code32              = 138;  // Code 39 with Mod 32 check character
const LONG SCAN_SDT_CodeCIP             = 139;  // Code 39 CIP
const LONG SCAN_SDT_TRIOPTIC39          = 140;  // Tri-Optic Code 39
const LONG SCAN_SDT_ISBT128             = 141;  // ISBT-128
const LONG SCAN_SDT_Code11              = 142;  // Code 11
const LONG SCAN_SDT_MSI                 = 143;  // MSI Code
const LONG SCAN_SDT_PLESSEY             = 144;  // Plessey Code
const LONG SCAN_SDT_TELEPEN             = 145;  // Telepen

// - Composite Symbologies (added in 1.8)
const LONG SCAN_SDT_CCA                 = 151;  // Composite Component A.
const LONG SCAN_SDT_CCB                 = 152;  // Composite Component B.
const LONG SCAN_SDT_CCC                 = 153;  // Composite Component C.

// - Composite Symbologies (Added in Release 1.14)
const LONG SCAN_SDT_TLC39               = 154;  // TLC-39

// - Two dimensional symbologies
const LONG SCAN_SDT_PDF417              = 201;  // PDF 417
const LONG SCAN_SDT_MAXICODE            = 202;  // Maxicode

// - Two dimensional symbologies (added in 1.11)
const LONG SCAN_SDT_DATAMATRIX          = 203;  // Data Matrix
const LONG SCAN_SDT_QRCODE              = 204;  // QR Code
const LONG SCAN_SDT_UQRCODE             = 205;  // Micro QR Code
const LONG SCAN_SDT_AZTEC               = 206;  // Aztec
const LONG SCAN_SDT_UPDF417             = 207;  // Micro PDF 417

// - Two dimensional symbologies (Added in Release 1.14)
const LONG SCAN_SDT_GS1DATAMATRIX       = 208;  // GS1 DataMatrix
const LONG SCAN_SDT_GS1QRCODE           = 209;  // GS1 QR Code
const LONG SCAN_SDT_Code49              = 210;  // Code 49
const LONG SCAN_SDT_Code16k             = 211;  // Code 16K
const LONG SCAN_SDT_CodablockA          = 212;  // Codablock A
const LONG SCAN_SDT_CodablockF          = 213;  // Codablock F
const LONG SCAN_SDT_Codablock256        = 214;  // Codablock 256
const LONG SCAN_SDT_HANXIN              = 215;  // Han Xin Code

// - Postal Code Symbologies (Added in Release 1.14)
const LONG SCAN_SDT_AusPost             = 301;  // Australian Post
const LONG SCAN_SDT_CanPost             = 302;  // Canada Post
const LONG SCAN_SDT_ChinaPost           = 303;  // China Post
const LONG SCAN_SDT_DutchKix            = 304;  // Dutch Post
const LONG SCAN_SDT_InfoMail            = 305;  // InfoMail
const LONG SCAN_SDT_JapanPost           = 306;  // Japan Post
const LONG SCAN_SDT_KoreanPost          = 307;  // Korean Post
const LONG SCAN_SDT_SwedenPost          = 308;  // Sweden Post
const LONG SCAN_SDT_UkPost              = 309;  // UK Post BPO
const LONG SCAN_SDT_UsIntelligent       = 310;  // US Intelligent Mail
const LONG SCAN_SDT_UsPlanet            = 311;  // US Planet Code
const LONG SCAN_SDT_PostNet             = 312;  // US Postnet

// - Special cases
const LONG SCAN_SDT_OTHER               = 501;  // Start of Scanner-Specific bar code symbologies
const LONG SCAN_SDT_UNKNOWN             =   0;  // Cannot determine the barcode symbology.


#endif                  // !defined(OPOSSCAN_H)
