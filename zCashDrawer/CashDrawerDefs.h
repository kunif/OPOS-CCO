/****************************************************************************
**
** CashDrawerDefs.h -- Constants and preprocessor macros.
**
**     Date                   Modification                          Author
** -----------|----------------------------------------------------|----------
**  1999/03/20 Initial version.                                     C. Monroe
**  2013/09/29 Update license section.
**  2015/02/07 Update license section.
**  2015/02/07 Version 1.14.001.
**  2020/06/01 Version 1.15.000.                                    K. Fukuchi
**             Changed include guard from #ifndef __XXXX_H__ to #pragma once.
**  2021/12/02 Version 1.16.000.
**
*****************************************************************************
**
{{Begin License}}

Copyright 2015 Monroe Consulting Services, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

{{End License}}
*/

#pragma once
// Define message numbers for our hidden event firing window.
const LONG WMU_DATA_EVENT           = WM_USER + 100;
const LONG WMU_DIRECT_IO_EVENT      = WM_USER + 101;
const LONG WMU_ERROR_EVENT          = WM_USER + 102;
const LONG WMU_OUTPUT_COMPLETE_EVENT= WM_USER + 103;
const LONG WMU_STATUS_UPDATE_EVENT  = WM_USER + 104;

// Define a reasonably large maximum for strings retrieved from the registry.
#define MAX_REGBUFFER_SIZE 256

// Define our debug assertion and verification macros.
#ifndef CMASSERT
#ifdef _DEBUG
#include <assert.h>
#define CMASSERT(x) assert(x)
#define CMVERIFY(x) assert(x)
#else
#define CMASSERT(x)
#define CMVERIFY(x) x
#endif
#endif


// End CashDrawerDefs.h
