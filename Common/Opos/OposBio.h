/////////////////////////////////////////////////////////////////////
//
// OposBio.h
//
//   Biometrics header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2006-03-15 OPOS Release 1.10                                  CRM
// 2007-01-30 OPOS Release 1.11                                  CRM
//   Add constants to StatusUpdateEvent.
//   Corrected spelling of "keystroke dynamics" constants.
// 2008-08-30 OPOS Release 1.12                                  CRM
//   Add constant to StatusUpdateEvent.
// 2009-10-02 OPOS Release 1.13                                  CRM
//   Add constants to StatusUpdateEvent.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSBIO_H)
#define      OPOSBIO_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapSensorColor" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG BIO_CSC_MONO                 = 0x00000001;
const LONG BIO_CSC_GRAYSCALE            = 0x00000002;
const LONG BIO_CSC_16                   = 0x00000004;
const LONG BIO_CSC_256                  = 0x00000008;
const LONG BIO_CSC_FULL                 = 0x00000010;


/////////////////////////////////////////////////////////////////////
// "CapSensorOrientation" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG BIO_CSO_NORMAL               = 0x00000001;
const LONG BIO_CSO_RIGHT                = 0x00000002;
const LONG BIO_CSO_INVERTED             = 0x00000004;
const LONG BIO_CSO_LEFT                 = 0x00000008;


/////////////////////////////////////////////////////////////////////
// "CapSensorType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG BIO_CST_FACIAL_FEATURES      = 0x00000001;
const LONG BIO_CST_VOICE                = 0x00000002;
const LONG BIO_CST_FINGERPRINT          = 0x00000004;
const LONG BIO_CST_IRIS                 = 0x00000008;
const LONG BIO_CST_RETINA               = 0x00000010;
const LONG BIO_CST_HAND_GEOMETRY        = 0x00000020;
const LONG BIO_CST_SIGNATURE_DYNAMICS   = 0x00000040;
const LONG BIO_CST_KEYSTROKE_DYNAMICS   = 0x00000080;
const LONG BIO_CST_LIP_MOVEMENT         = 0x00000100;
const LONG BIO_CST_THERMAL_FACE_IMAGE   = 0x00000200;
const LONG BIO_CST_THERMAL_HAND_IMAGE   = 0x00000400;
const LONG BIO_CST_GAIT                 = 0x00000800;
const LONG BIO_CST_PASSWORD             = 0x00001000;


/////////////////////////////////////////////////////////////////////
// "SensorColor" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG BIO_SC_MONO                  = 1;
const LONG BIO_SC_GRAYSCALE             = 2;
const LONG BIO_SC_16                    = 3;
const LONG BIO_SC_256                   = 4;
const LONG BIO_SC_FULL                  = 5;


/////////////////////////////////////////////////////////////////////
// "SensorOrientation" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG BIO_SO_NORMAL                = 1;
const LONG BIO_SO_RIGHT                 = 2;
const LONG BIO_SO_INVERTED              = 3;
const LONG BIO_SO_LEFT                  = 4;


/////////////////////////////////////////////////////////////////////
// "SensorType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG BIO_ST_FACIAL_FEATURES       =  1;
const LONG BIO_ST_VOICE                 =  2;
const LONG BIO_ST_FINGERPRINT           =  3;
const LONG BIO_ST_IRIS                  =  4;
const LONG BIO_ST_RETINA                =  5;
const LONG BIO_ST_HAND_GEOMETRY         =  6;
const LONG BIO_ST_SIGNATURE_DYNAMICS    =  7;
const LONG BIO_ST_KEYSTROKE_DYNAMICS    =  8;
const LONG BIO_ST_LIP_MOVEMENT          =  9;
const LONG BIO_ST_THERMAL_FACE_IMAGE    = 10;
const LONG BIO_ST_THERMAL_HAND_IMAGE    = 11;
const LONG BIO_ST_GAIT                  = 12;
const LONG BIO_ST_PASSWORD              = 13;


/////////////////////////////////////////////////////////////////////
// "DataEvent" "Status" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG BIO_DATA_ENROLL              = 1;
const LONG BIO_DATA_VERIFY              = 2;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" "Status" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG BIO_SUE_RAW_DATA             = 1;
const LONG BIO_SUE_MOVE_LEFT            = 2;
const LONG BIO_SUE_MOVE_RIGHT           = 3;
const LONG BIO_SUE_MOVE_DOWN            = 4;
const LONG BIO_SUE_MOVE_UP              = 5;
const LONG BIO_SUE_MOVE_CLOSER          = 6;
const LONG BIO_SUE_MOVE_AWAY            = 7;
const LONG BIO_SUE_MOVE_BACKWARD        = 8;
const LONG BIO_SUE_MOVE_FORWARD         = 9;
const LONG BIO_SUE_MOVE_SLOWER          = 10; // (added in 1.11)
const LONG BIO_SUE_MOVE_FASTER          = 11; // (added in 1.11)
const LONG BIO_SUE_SENSOR_DIRTY         = 12; // (added in 1.11)
const LONG BIO_SUE_FAILED_READ          = 13; // (added in 1.12)
const LONG BIO_SUE_SENSOR_READY         = 14; // (added in 1.13)
const LONG BIO_SUE_SENSOR_COMPLETE      = 15; // (added in 1.13)


#endif                  // !defined(OPOSBIO_H)
