/****************************************************************************
**
** OposInter.h -- IDL source to define the OPOS Common Internals, from Opos.hi
**
//   General header file for OPOS Control Objects and Service Objects.
**
*****************************************************************************
*/

typedef [helpstring("OPOS Internals")]
enum
{
    PIDX_Claimed                 =   1,
    PIDX_DataEventEnabled        =   2,
    PIDX_DeviceEnabled           =   3,
    PIDX_FreezeEvents            =   4,
    PIDX_OutputID                =   5,
    PIDX_ResultCode              =   6,
    PIDX_ResultCodeExtended      =   7,
    PIDX_ServiceObjectVersion    =   8,
    PIDX_State                   =   9,
    PIDX_AutoDisable             =  10,
    PIDX_BinaryConversion        =  11,
    PIDX_DataCount               =  12,
    PIDX_PowerNotify             =  13,
    PIDX_PowerState              =  14,

    PIDX_CapPowerReporting       = 501,
    PIDX_CapStatisticsReporting  = 502,
    PIDX_CapUpdateStatistics     = 503,
    PIDX_CapCompareFirmwareVersion=504,
    PIDX_CapUpdateFirmware       = 505,

    PIDX_CheckHealthText         = 1000001,
    PIDX_DeviceDescription       = 1000002,
    PIDX_DeviceName              = 1000003,
    PIDX_ServiceObjectDescription= 1000004,

    PIDX_NUMBER  = 0,
    PIDX_STRING  = 1000000,

    PIDX_CASH    =  1000,
    PIDX_COIN    =  2000,
    PIDX_TOT     =  3000,
    PIDX_LOCK    =  4000,
    PIDX_DISP    =  5000,
    PIDX_MICR    =  6000,
    PIDX_MSR     =  7000,
    PIDX_PTR     =  8000,
    PIDX_SCAL    =  9000,
    PIDX_SCAN    = 10000,
    PIDX_SIG     = 11000,
    PIDX_KBD     = 12000,
    PIDX_CHAN    = 13000,
    PIDX_TONE    = 14000,
    PIDX_BB      = 15000,
    PIDX_FPTR    = 16000,
    PIDX_PPAD    = 17000,
    PIDX_ROD     = 18000,
    PIDX_CAT     = 19000,
    PIDX_PCRW    = 20000,
    PIDX_PWR     = 21000,
    PIDX_CHK     = 22000,
    PIDX_MOTION  = 23000,
    PIDX_SCRW    = 24000,
    PIDX_BIO     = 25000,
    PIDX_EJ      = 26000,
    PIDX_BACC    = 27000,
    PIDX_BDSP    = 28000,
    PIDX_CACC    = 29000,
    PIDX_IMG     = 30000,
    PIDX_BELT    = 31000,
    PIDX_EVRW    = 32000,
    PIDX_GATE    = 33000,
    PIDX_ITEM    = 34000,
    PIDX_LGT     = 35000,
    PIDX_RFID    = 36000
} OPOS_Internals;
