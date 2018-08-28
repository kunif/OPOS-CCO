/////////////////////////////////////////////////////////////////////
//
// OposMsr.h
//
//   Magnetic Stripe Reader header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1995-12-08 OPOS Release 1.0                                   CRM
// 1997-06-04 OPOS Release 1.2                                   CRM
//   Add ErrorReportingType constants.
// 2000-09-24 OPOS Release 1.5                                   BKS
//   Add constants relating to Track 4 Data.
//   (01-07-15 Added omitted MSR_TR_1_3_4 property)
// 2006-03-15 OPOS Release 1.10                                  CRM
//   Add values for the following properties:
//     CapWritableTracks, EncodingMaxLength, TracksToWrite
// 2008-08-30 OPOS Release 1.12                                  CRM
//   Add values for new properties, plus SUE and RCExt values.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSMSR_H)
#define      OPOSMSR_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "TracksToRead", "CapWritableTracks", "TracksToWrite" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG MSR_TR_NONE          = 0;    // (added in 1.10)
                                        // "CapWritableTracks", "TracksToWrite"

const LONG MSR_TR_1             = 1;
const LONG MSR_TR_2             = 2;
const LONG MSR_TR_3             = 4;
const LONG MSR_TR_4             = 8;    // (added in 1.5)

const LONG MSR_TR_1_2           = 0x03;
const LONG MSR_TR_1_3           = 0x05;
const LONG MSR_TR_1_4           = 0x09; // (added in 1.5)
const LONG MSR_TR_2_3           = 0x06;
const LONG MSR_TR_2_4           = 0x0A; // (added in 1.5)
const LONG MSR_TR_3_4           = 0x0C; // (added in 1.5)

const LONG MSR_TR_1_2_3         = 0x07;
const LONG MSR_TR_1_2_4         = 0x0B; // (added in 1.5)
const LONG MSR_TR_1_3_4         = 0x0D; // (added in 1.5)
const LONG MSR_TR_2_3_4         = 0x0E; // (added in 1.5)

const LONG MSR_TR_1_2_3_4       = 0x0F; // (added in 1.5)


/////////////////////////////////////////////////////////////////////
// "ErrorReportingType" Property Constants (added in 1.2)
/////////////////////////////////////////////////////////////////////

const LONG MSR_ERT_CARD         = 0;
const LONG MSR_ERT_TRACK        = 1;


/////////////////////////////////////////////////////////////////////
// "CapDataEncryption", "DataEncryptionAlgorithm" Property Constants
//   (added in 1.12)
/////////////////////////////////////////////////////////////////////

const LONG MSR_DE_NONE          = 0x00000001;
const LONG MSR_DE_3DEA_DUKPT    = 0x00000002;
// Note: Service-specific values begin at 0x01000000.


/////////////////////////////////////////////////////////////////////
// "CapDeviceAuthentication" Property Constants (added in 1.12)
/////////////////////////////////////////////////////////////////////

const LONG MSR_DA_NOT_SUPPORTED = 0;
const LONG MSR_DA_OPTIONAL      = 1;
const LONG MSR_DA_REQUIRED      = 2;


/////////////////////////////////////////////////////////////////////
// "DeviceAuthenticationProtocol" Property Constants (added in 1.12)
/////////////////////////////////////////////////////////////////////

const LONG MSR_AP_NONE              = 0;
const LONG MSR_AP_CHALLENGERESPONSE = 1;


/////////////////////////////////////////////////////////////////////
// "CardType" Property Constants (added in 1.12)
/////////////////////////////////////////////////////////////////////

#define MSR_CT_AAMVA            "AAMVA"
#define MSR_CT_BANK             "BANK"


/////////////////////////////////////////////////////////////////////
// "RetrieveCardProperty" Method: "Name" Parameter Constants
//   (added in 1.12)
/////////////////////////////////////////////////////////////////////

#define MSR_RCP_AccountNumber   "AccountNumber"
#define MSR_RCP_Address         "Address"
#define MSR_RCP_BirthDate       "BirthDate"
#define MSR_RCP_City            "City"
#define MSR_RCP_Class           "Class"
#define MSR_RCP_Endorsements    "Endorsements"
#define MSR_RCP_ExpirationDate  "ExpirationDate"
#define MSR_RCP_EyeColor        "EyeColor"
#define MSR_RCP_FirstName       "FirstName"
#define MSR_RCP_Gender          "Gender"
#define MSR_RCP_HairColor       "HairColor"
#define MSR_RCP_Height          "Height"
#define MSR_RCP_LicenseNumber   "LicenseNumber"
#define MSR_RCP_MiddleInitial   "MiddleInitial"
#define MSR_RCP_PostalCode      "PostalCode"
#define MSR_RCP_Restrictions    "Restrictions"
#define MSR_RCP_ServiceCode     "ServiceCode"
#define MSR_RCP_State           "State"
#define MSR_RCP_Suffix          "Suffix"
#define MSR_RCP_Surname         "Surname"
#define MSR_RCP_Title           "Title"
#define MSR_RCP_Weight          "Weight"


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG MSR_SUE_DEVICE_AUTHENTICATED     =  11; // (added in 1.12)
const LONG MSR_SUE_DEVICE_DEAUTHENTICATED   =  12; // (added in 1.12)


/////////////////////////////////////////////////////////////////////
// "ErrorEvent" Event: "ResultCodeExtended" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EMSR_START      = 201;
const LONG OPOS_EMSR_END        = 202;
const LONG OPOS_EMSR_PARITY     = 203;
const LONG OPOS_EMSR_LRC        = 204;
const LONG OPOS_EMSR_DEVICE_AUTHENTICATION_FAILED   = 205; // (added in 1.12)
const LONG OPOS_EMSR_DEVICE_DEAUTHENTICATION_FAILED = 206; // (added in 1.12)

#endif                  // !defined(OPOSMSR_H)
