/////////////////////////////////////////////////////////////////////
//
// OposImg.h
//
//   Image Scanner header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2007-01-30 OPOS Release 1.11                                  CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSIMG_H)
#define      OPOSIMG_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "FrameType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG IMG_FRAME_STILL              = 1;
const LONG IMG_FRAME_VIDEO              = 2;


/////////////////////////////////////////////////////////////////////
// "ImageMode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG IMG_ALL                      = 0xFF;
const LONG IMG_DECODE_ONLY              = 0x01;
const LONG IMG_STILL_ONLY               = 0x02;
const LONG IMG_STILL_DECODE             = 0x03;
const LONG IMG_VIDEO_DECODE             = 0x05;
const LONG IMG_VIDEO_STILL              = 0x06;


/////////////////////////////////////////////////////////////////////
// "ImageQuality" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG IMG_QUAL_LOW                 = 0x01;
const LONG IMG_QUAL_MED                 = 0x02;
const LONG IMG_QUAL_HIGH                = 0x03;


/////////////////////////////////////////////////////////////////////
// "ImageType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG IMG_TYP_BMP                  = 1;
const LONG IMG_TYP_JPEG                 = 2;
const LONG IMG_TYP_GIF                  = 3;
const LONG IMG_TYP_PNG                  = 4;
const LONG IMG_TYP_TIFF                 = 5;


#endif                  // !defined(OPOSIMG_H)
