/*
 * Copyright 2018-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#include "rsdk_dsp_dispatcher.h"
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define SPT_EVT_INTERRUPT_ALL_BITS_MASK (0x7FFCu)
#define NUM_EVT_INTS (13u)


#define XCHAL_EXTINT_CSI2_LINE_DONE XCHAL_EXTINT19_NUM
#define XCHAL_EXTINT_CSI2_VSYNC XCHAL_EXTINT20_NUM
#define XCHAL_EXTINT_ARM XCHAL_EXTINT23_NUM






/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct {
    rsdkDspIsrCb_t cb;
    uint32_t evtIntID;
} dspEvtIsrArg_t;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
rsdkStatus_t ConfigureInterrupts(uint16_t sptEvtIntEnBitmap, rsdkDspIsrCb_t sptEvtIsrCb);
void DspExceptionHandler(XosExcFrame * frame);

void EnableAllInterruptsAfterChirpsDone(void);

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*INTERRUPTS_H*/
