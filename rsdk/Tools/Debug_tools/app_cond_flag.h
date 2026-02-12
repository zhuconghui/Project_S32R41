/*
 * Copyright 2018,2021-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef APP_COND_FLAG_H
#define APP_COND_FLAG_H

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <stdint.h>
#include "compiler_api.h"




#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define FLAG_WAIT_VALUE 0x5253444B
#define FLAG_INIT_VALUE 0x494E4954

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                          TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
struct appCondFlag_t{
	volatile uint32_t value;
	volatile uint32_t initialized;
};


typedef struct appCondFlag_t rsdkAppCondFlag_t;




void AppCondFlagInit(rsdkAppCondFlag_t *apFlag);
void AppCondFlagSignal(rsdkAppCondFlag_t *apFlag);
void AppCondFlagWait(rsdkAppCondFlag_t *apFlag);
void AppCondFlagDestroy(rsdkAppCondFlag_t *apFlag);

#ifdef __cplusplus
}
#endif

#endif  /* APP_COND_FLAG_H */
