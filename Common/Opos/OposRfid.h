/////////////////////////////////////////////////////////////////////
//
// OposRfid.h
//
//   RFID Scanner header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2008-08-30 OPOS Release 1.12                                  CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSRFID_H)
#define      OPOSRFID_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "CapWriteTag" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG RFID_CWT_NONE                        = 0;
const LONG RFID_CWT_ID                          = 1;
const LONG RFID_CWT_USERDATA                    = 2;
const LONG RFID_CWT_ALL                         = 3;


/////////////////////////////////////////////////////////////////////
// "CapMultipleProtocols", "CurrentTagProtocol", and
// "ProtocolMask" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG RFID_PR_EPC0                         = 0x00000001;
const LONG RFID_PR_0PLUS                        = 0x00000002;
const LONG RFID_PR_EPC1                         = 0x00000004;
const LONG RFID_PR_EPC1G2                       = 0x00000008;
const LONG RFID_PR_EPC2                         = 0x00000010;
const LONG RFID_PR_ISO14443A                    = 0x00001000;
const LONG RFID_PR_ISO14443B                    = 0x00002000;
const LONG RFID_PR_ISO15693                     = 0x00003000;
const LONG RFID_PR_ISO180006B                   = 0x00004000;
const LONG RFID_PR_OTHER                        = 0x01000000;
const LONG RFID_PR_ALL                          = 0x40000000; // (ProtocolMask only)


/////////////////////////////////////////////////////////////////////
// "ReadTags" and "StartReadTags" Methods: "Cmd" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG RFID_RT_ID                           = 0x10;
const LONG RFID_RT_FULLUSERDATA                 = 0x01;
const LONG RFID_RT_PARTIALUSERDATA              = 0x02;
const LONG RFID_RT_ID_FULLUSERDATA              = 0x11;
const LONG RFID_RT_ID_PARTIALUSERDATA           = 0x12;


#endif                  // !defined(OPOSRFID_H)
