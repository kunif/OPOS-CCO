/////////////////////////////////////////////////////////////////////
//
// OposScal.h
//
//   Scale header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 1995-12-08 OPOS Release 1.0                                   CRM
// 2005-04-29 OPOS Release 1.9                                   CRM
//   Add StatusNotify constants.
//   Add StatusUpdateEvent constants.
//   Add more ResultCodeExtended constants.
// 2006-03-15 OPOS Release 1.10                                  CRM
//   Corrected names of StatusUpdateEvent constants from 1.9.
// 2013-10-03 OPOS Release 1.14                                  CRM
//   Added FreezeValue's Item constants.
//   Added SetPriceCalculationMode's Mode constants.
//   Added SetSpecialTare's Priority constants.
//   Added SetTarePriority's Mode constants.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSSCAL_H)
#define      OPOSSCAL_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "WeightUnit" Property Constants
// "SetUnitPriceWithWeightUnit" Method "WeightUnit" Parameter
//   Constants (added in 1.14)
/////////////////////////////////////////////////////////////////////

const LONG SCAL_WU_GRAM                 = 1;
const LONG SCAL_WU_KILOGRAM             = 2;
const LONG SCAL_WU_OUNCE                = 3;
const LONG SCAL_WU_POUND                = 4;


/////////////////////////////////////////////////////////////////////
// "StatusNotify" Property Constants (added in 1.9)
/////////////////////////////////////////////////////////////////////

const LONG SCAL_SN_DISABLED             = 1;
const LONG SCAL_SN_ENABLED              = 2;


/////////////////////////////////////////////////////////////////////
// "FreezeValue" Method "Item" Parameter Constants (added in 1.14)
/////////////////////////////////////////////////////////////////////

const LONG SCAL_SFR_MANUAL_TARE         = 0x00000001;
const LONG SCAL_SFR_WEIGHTED_TARE       = 0x00000002;
const LONG SCAL_SFR_PERCENT_TARE        = 0x00000004;
const LONG SCAL_SFR_UNITPRICE           = 0x00000008;


/////////////////////////////////////////////////////////////////////
// "SetPriceCalculationMode" Method "Mode" Parameter Constants
//   (added in 1.14)
/////////////////////////////////////////////////////////////////////

const LONG SCAL_PCM_PRICE_LABELING      = 1;
const LONG SCAL_PCM_SELF_SERVICE        = 2;
const LONG SCAL_PCM_OPERATOR            = 3;


/////////////////////////////////////////////////////////////////////
// "SetSpecialTare" Method "Mode" Parameter Constants
//   (added in 1.14)
/////////////////////////////////////////////////////////////////////

const LONG SCAL_SST_DEFAULT             = 1;
const LONG SCAL_SST_MANUAL              = 2;
const LONG SCAL_SST_PERCENT             = 3;
const LONG SCAL_SST_WEIGHTED            = 4;


/////////////////////////////////////////////////////////////////////
// "SetTarePriority" Method "Priority" Parameter Constants
//   (added in 1.14)
/////////////////////////////////////////////////////////////////////

const LONG SCAL_STP_FIRST               = 1;
const LONG SCAL_STP_NONE                = 2;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Status" Constants (added in 1.9)
/////////////////////////////////////////////////////////////////////

const LONG SCAL_SUE_STABLE_WEIGHT       = 11;
const LONG SCAL_SUE_WEIGHT_UNSTABLE     = 12;
const LONG SCAL_SUE_WEIGHT_ZERO         = 13;
const LONG SCAL_SUE_WEIGHT_OVERWEIGHT   = 14;
const LONG SCAL_SUE_NOT_READY           = 15;
const LONG SCAL_SUE_WEIGHT_UNDER_ZERO   = 16;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_ESCAL_OVERWEIGHT        = 201; // ReadWeight
const LONG OPOS_ESCAL_UNDER_ZERO        = 202; // ReadWeight (added in 1.9)
const LONG OPOS_ESCAL_SAME_WEIGHT       = 203; // ReadWeight (added in 1.9)

#endif                  // !defined(OPOSSCAL_H)
