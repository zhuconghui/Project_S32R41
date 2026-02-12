/*
* Copyright 2022 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RSDK_TOOLCHAIN_HELPER_H
#define RSDK_TOOLCHAIN_HELPER_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#if defined(RSDK_AUTOSAR)
#include "StandardTypes.h"
#include "rsdk_version.h"
#else
#include "typedefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(RSDK_AUTOSAR)
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RSDK_TOOLCHAIN_HELPER_VENDOR_ID                     43

#define RSDK_TOOLCHAIN_HELPER_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define RSDK_TOOLCHAIN_HELPER_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define RSDK_TOOLCHAIN_HELPER_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV

#define RSDK_TOOLCHAIN_HELPER_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define RSDK_TOOLCHAIN_HELPER_SW_MINOR_VERSION              RSDK_SW_MINOR
#define RSDK_TOOLCHAIN_HELPER_SW_PATCH_VERSION              RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Verify vendor ID and version numbers for included header file: StandardTypes.h */
#if (RSDK_TOOLCHAIN_HELPER_VENDOR_ID != STD_VENDOR_ID)
    #error "rsdk_toolchain_helper.h and StandardTypes.h have different vendor IDs"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((RSDK_TOOLCHAIN_HELPER_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
         (RSDK_TOOLCHAIN_HELPER_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION) || \
         (RSDK_TOOLCHAIN_HELPER_AR_RELEASE_REVISION_VERSION != STD_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of rsdk_toolchain_helper.h and StandardTypes.h are different"
    #endif
#endif

#endif /* RSDK_AUTOSAR */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define UNUSED_ARG(ARG) (void)(ARG)

#if defined(__GNUC__) || defined(__DCC__) || defined(__XCC__) || defined(__ghs__)

/* Helpers for accessing linker-command-file-defined symbols */
/*declare (in C) a symbol defined in .ld*/
#define RSDK_DECL_LNK_SYM(symName) extern char symName[]
/*get UNsigned value of a symbol defined in .ld; mind ld solves undefined symbols to value 0, see TEST_NOT_NULL_LNK_SYM*/
#define RSDK_GET_UL_LNK_SYM(symName) ((unsigned long int)(&symName))
/*get signed value of a symbol defined in .ld; mind ld solves undefined symbols to value 0, see TEST_NOT_NULL_LNK_SYM*/
#define RSDK_GET_L_LNK_SYM(symName) ((signed long int)(&symName))
/*As ld solves undefined symbols to value 0, and gcc optimizes out tests like if (&sym == 0)
 * this helper function REALLY verifies whether symbol is NULL (return value 0 if NULL, 1 otherwise)
 */
#define RSDK_TEST_NOT_NULL_LNK_SYM(symName) rsdk_test_not_null_lnk_sym(RSDK_GET_UL_LNK_SYM(symName))

/* A special macro is needed to check sizeof() at compile time, since sizeof is not evaluated by the preprocessor.
 * Multiple versions are possible. The concept is to construct invalid syntax expressions when the condition is false.
 * #define RSDK_COMPILER_ASSERT(cond) switch(0){case 0:case cond:;} can be an alternative. See also "#define BUILD_BUG_ON" in Linux kernel
 */
#define RSDK_COMPILER_ASSERT(cond) ((void)sizeof(char[-1 + (2*(!(!(cond))))]))


#else

#error Toolchain not supported

#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

static uint8 __attribute__((unused)) rsdk_test_not_null_lnk_sym(uintptr_t symName)
{
    uint8            retVal;
    volatile uintptr_t dummy_volatile;
    dummy_volatile = symName;
    if (dummy_volatile != 0UL)
    {
        retVal = 1U;
    }
    else
    {
        retVal = 0;
    }

    return retVal;
}

#ifdef __cplusplus
}
#endif

#endif /*RSDK_TOOLCHAIN_HELPER_H*/
