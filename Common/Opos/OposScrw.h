/////////////////////////////////////////////////////////////////////
//
// OposScrw.H
//
//   Smart Card Reader Writer header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 2004-03-22 OPOS Release 1.8                                   CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSSCRW_H)
#define      OPOSSCRW_H


#include "opos.h"


/////////////////////////////////////////////////////////////////////
// "CapInterfaceMode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG SC_CMODE_TRANS       =   1;  // Simple Transaction Command and Data Mode.
const LONG SC_CMODE_BLOCK       =   2;  // Block Data Mode.
const LONG SC_CMODE_APDU        =   4;  // Same as Block Data Mode except APDU Standard Commands are used.
const LONG SC_CMODE_XML         =   8;  // XML Block Data Mode.


/////////////////////////////////////////////////////////////////////
// "CapIsoEmvMode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG SC_CMODE_ISO         =   1;  // APDU messaging format conforms to the ISO standard.
const LONG SC_CMODE_EMV         =   2;  // APDU messaging format conforms to the EMV standard.


/////////////////////////////////////////////////////////////////////
// "CapTransmissionProtocol" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG SC_CTRANS_PROTOCOL_T0=   1;  // Asynchronous, Half Duplex, Character, Transmission Protocol Mode.
const LONG SC_CTRANS_PROTOCOL_T1=   2;  // Asynchronous, Half Duplex, Block Transmission Protocol Mode.


/////////////////////////////////////////////////////////////////////
// "InterfaceMode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG SC_MODE_TRANS        =   1;  // Simple Transaction Command and Data Mode.
const LONG SC_MODE_BLOCK        =   2;  // Block Data Mode.
const LONG SC_MODE_APDU         =   4;  // Same as Block Data Mode except APDU Standard Defines the Commands and data.
const LONG SC_MODE_XML          =   8;  // XML Block Data Mode.


/////////////////////////////////////////////////////////////////////
// "IsoEmvMode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG SC_MODE_ISO          =   1;  // APDU messaging format currently in use conforms to the ISO standard.
const LONG SC_MODE_EMV          =   2;  // APDU messaging format currently in use conforms to the EMV standard.


/////////////////////////////////////////////////////////////////////
// "TransmissionProtocol" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG SC_TRANS_PROTOCOL_T0 =   1;  // Asynchronous, Half Duplex, Character, Transmission Protocol Mode.
const LONG SC_TRANS_PROTOCOL_T1 =   2;  // Asynchronous, Half Duplex, Block Transmission Protocol Mode.


/////////////////////////////////////////////////////////////////////
// "ReadData" Method: "Action" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG SC_READ_DATA             =  11;
const LONG SC_READ_PROGRAM          =  12;
const LONG SC_EXECUTE_AND_READ_DATA =  13;
const LONG SC_XML_READ_BLOCK_DATA   =  14;


/////////////////////////////////////////////////////////////////////
// "WriteData" Method: "Action" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG SC_STORE_DATA        =  21;
const LONG SC_STORE_PROGRAM     =  22;
const LONG SC_EXECUTE_DATA      =  23;
const LONG SC_XML_BLOCK_DATA    =  24;
const LONG SC_SECURITY_FUSE     =  25;
const LONG SC_RESET             =  26;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constant
/////////////////////////////////////////////////////////////////////

const LONG SC_SUE_NO_CARD       =   1;  // No card detected in the SCR/W Device.
const LONG SC_SUE_CARD_PRESENT  =   2;  // There is a card in the device.


/////////////////////////////////////////////////////////////////////
// "ErrorEvent" Event: "ResultCodeExtended" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_ESC_READ        = 201;  // There was a read error.
const LONG OPOS_ESC_WRITE       = 202;  // There was a write error.
const LONG OPOS_ESC_TORN        = 203;  // The smart card was prematurely removed from the SCR/W unexpectedly. Note: CapCardErrorDetection capability must be true before this can be set.
const LONG OPOS_ESC_NO_CARD     = 204;  // There is no card detected in the SCR/W but a card was expected.


#endif                  // !defined(OPOSSCRW_H)
