/*
 * Copyright 2020-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef HW_DEFS_H
#define HW_DEFS_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <xtensa/tie/radar24.h>
#include "rsdk_status.h"
#ifdef TRACE_ENABLE
#include "dsp_trace.h"
#include "trace_internals.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define ADDR_DSP_ERR_INFO_REG (0x9C)

#define ADDR_DSP_DEBUG1_REG (0xA8)
#define ADDR_DSP_DEBUG2_REG (0xAC)
#define ADDR_DSP_DEBUG3_REG (0xB0)
#define ADDR_DSP_DEBUG4_REG (0xB4)
#define ADDR_DSP_DEBUG5_REG (0xB8)
#define ADDR_DSP_DEBUG6_REG (0xBC)

#define ADDR_DSP_WR_R0_RE (0x198)
#define ADDR_DSP_WR_R0_IM (0x19C)












#ifndef TRACE_ENABLE
#define RsdkTraceLogEvent(event, extra1, extra2)
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
static inline void __attribute ((optimize("-O0"))) SetDspError(rsdkStatus_t errInfo)
{

    int32_t dspErrorReg = BBX_LCRLU(ADDR_DSP_ERR_INFO_REG);

    //writing to DSP_ERR_INFO_REG triggeres an SPT "DSP" interrupt to the application core:
    BBX_SCRLU((int32_t)((uint32_t)dspErrorReg | (1UL << ((uint32_t)errInfo - (uint32_t)RSDK_DSP_STATUS_BASE))), ADDR_DSP_ERR_INFO_REG);







#ifdef TRACE_ENABLE
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_ERR, (uint32_t)errInfo);
#endif
}


#ifdef __cplusplus
}
#endif

#endif /*HW_DEFS_H*/
