/////////////////////////////////////////////////////////////////////
//
// OposChk.h
//
//   Check Scanner header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2002-08-17 OPOS Release 1.7                                   CRM
// 2005-04-29 OPOS Release 1.9                                   CRM
//   Added Constrast constants.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSCHK_H)
#define      OPOSCHK_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapColor" Capability Constants
/////////////////////////////////////////////////////////////////////

const LONG CHK_CCL_MONO                 = 0x00000001;
const LONG CHK_CCL_GRAYSCALE            = 0x00000002;
const LONG CHK_CCL_16                   = 0x00000004;
const LONG CHK_CCL_256                  = 0x00000008;
const LONG CHK_CCL_FULL                 = 0x00000010;


/////////////////////////////////////////////////////////////////////
// "CapImageFormat" Capability Constants
/////////////////////////////////////////////////////////////////////

const LONG CHK_CIF_NATIVE               = 0x00000001;
const LONG CHK_CIF_TIFF                 = 0x00000002;
const LONG CHK_CIF_BMP                  = 0x00000004;
const LONG CHK_CIF_JPEG                 = 0x00000008;
const LONG CHK_CIF_GIF                  = 0x00000010;


/////////////////////////////////////////////////////////////////////
// "Color" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG CHK_CL_MONO                  = 1;
const LONG CHK_CL_GRAYSCALE             = 2;
const LONG CHK_CL_16                    = 3;
const LONG CHK_CL_256                   = 4;
const LONG CHK_CL_FULL                  = 5;


/////////////////////////////////////////////////////////////////////
// "Constrast" Property Constants (added in 1.9)
/////////////////////////////////////////////////////////////////////

const LONG CHK_AUTOMATIC_CONTRAST       = -1;


/////////////////////////////////////////////////////////////////////
// "ImageFormat" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG CHK_IF_NATIVE                = 1;
const LONG CHK_IF_TIFF                  = 2;
const LONG CHK_IF_BMP                   = 3;
const LONG CHK_IF_JPEG                  = 4;
const LONG CHK_IF_GIF                   = 5;


/////////////////////////////////////////////////////////////////////
// "ImageMemoryStatus" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG CHK_IMS_EMPTY                = 1;
const LONG CHK_IMS_OK                   = 2;
const LONG CHK_IMS_FULL                 = 3;


/////////////////////////////////////////////////////////////////////
// "MapMode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG CHK_MM_DOTS                  = 1;
const LONG CHK_MM_TWIPS                 = 2;
const LONG CHK_MM_ENGLISH               = 3;
const LONG CHK_MM_METRIC                = 4;


/////////////////////////////////////////////////////////////////////
// "ClearImage" Method Constants:
/////////////////////////////////////////////////////////////////////

//   "By" Parameter
const LONG CHK_CLR_ALL                  = 1;
const LONG CHK_CLR_BY_FILEID            = 2;
const LONG CHK_CLR_BY_FILEINDEX         = 3;
const LONG CHK_CLR_BY_IMAGETAGDATA      = 4;


/////////////////////////////////////////////////////////////////////
// "DefineCropArea" Method Constants:
/////////////////////////////////////////////////////////////////////

// "CropAreaID" Parameter or index number
const LONG CHK_CROP_AREA_ENTIRE_IMAGE   = -1;
const LONG CHK_CROP_AREA_RESET_ALL      = -2;

// "CX" Parameter or integer width
const LONG CHK_CROP_AREA_RIGHT          = -1;

// "CY" Parameter or integer height
const LONG CHK_CROP_AREA_BOTTOM         = -1;


/////////////////////////////////////////////////////////////////////
// "RetrieveMemory" Method Constants:
/////////////////////////////////////////////////////////////////////

// "By" Parameter
const LONG CHK_LOCATE_BY_FILEID         = 1;
const LONG CHK_LOCATE_BY_FILEINDEX      = 2;
const LONG CHK_LOCATE_BY_IMAGETAGDATA   = 3;


/////////////////////////////////////////////////////////////////////
// "RetrieveImage" and "StoreImage" Method Constant:
/////////////////////////////////////////////////////////////////////

// "CropAreaID" Parameter or index number
//const LONG CHK_CROP_AREA_ENTIRE_IMAGE   = -1; //(Defined above)


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constant
/////////////////////////////////////////////////////////////////////

const LONG CHK_SUE_SCANCOMPLETE         = 11;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_ECHK_NOCHECK            = 201; // endInsertion
const LONG OPOS_ECHK_CHECK              = 202; // endRemoval
const LONG OPOS_ECHK_NOROOM             = 203; // storeImage


#endif                  // !defined(OPOSCHK_H)
