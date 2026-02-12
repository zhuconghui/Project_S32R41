/**************************************************************************//**
 * @file     ARMCM7_SP.h
 * @brief    CMSIS Core Peripheral Access Layer Header File for
 *           ARMCM7 Device (configured for CM7 with single precision FPU)
 * @version  V5.3.1
 * @date     09. July 2018
 ******************************************************************************/
/*
 * Copyright 2009-2018 Arm
 * Copyright 2019-2022 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ARMCM7_SP_H
#define ARMCM7_SP_H

#ifdef __cplusplus
extern "C" {
#endif




#include "S32R41_COMMON.h"




/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#elif defined (__ghs__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __CM7_REV                 0x0000U   /* Core revision r0p0 */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __FPU_DP                  0U        /* single precision FPU */
#define __ECC_PRESENT             1U

#include "core_cm7.h"                       /* Processor and core peripherals */
#include "system_ARMCM7.h"                  /* System Header */



/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#elif defined (__ghs__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


#ifdef __cplusplus
}
#endif

#endif  /* ARMCM7_SP_H */
