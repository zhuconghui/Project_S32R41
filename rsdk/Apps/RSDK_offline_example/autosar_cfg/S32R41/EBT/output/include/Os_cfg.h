/******************************************************************************
*
*       NXP(TM) and the NXP logo are trademarks of NXP.
*       All other product or service names are the property of their respective owners.
*       (C) Freescale Semiconductor, Inc. 2013-2016
*       Copyright 2024 NXP
*
*       THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
*       BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF NXP.
*
*       Description: Configuration Header file
*
*       Note: The implementation that was used is: AUTOSAR_S32R41
*       System Generator for AUTOSAR OS/S32R41 - Version: 4.7 Build 4.7.160
*
********************************************************************************/
#ifndef OSCFG_H
#define OSCFG_H
#define APP_START_SEC_CODE
#include    "Os_memmap.h"


/* Applications */

/* Spinlock */

/* Application modes */
#define OsAppMode_0 ((AppModeType)0U)      /* AppMode ID */

/* Common stack */

/* Task definitions */
#define RSDK_Main ((TaskType)OS_MKOBJID(OBJECT_TASK, 0U)) /* Task ID */
extern void FuncRSDK_Main(void); /* Task entry point */

/* ISR functions */
#define OS_isr_Bbe32_RxHandler ipc_shm_hardirq
#define OS_isr_Spt_DspHandler Spt_DspIsr
#define OS_isr_Spt_EcsHandler Spt_EcsIsr
#define OS_isr_Spt_EvtHandler Spt_EvtIsr

/* ISRs definition */
#define OSISRBbe32_RxHandler() OSISR1DISP(Bbe32_RxHandler) /* IrqChannel is EXTERNAL */
extern void OS_isr_Bbe32_RxHandler(void); /* irq: Bbe32_RxHandler; channel: EXTERNAL; category: 1 */
#define Bbe32_RxHandlerLEVEL 4U            /* interrupt level of Bbe32_RxHandler */
#define Bbe32_RxHandlerPRIORITY 4U         /* priority of Bbe32_RxHandler */
#define OSISRSpt_DspHandler() OSISR1DISP(Spt_DspHandler) /* IrqChannel is EXTERNAL */
extern void OS_isr_Spt_DspHandler(void); /* irq: Spt_DspHandler; channel: EXTERNAL; category: 1 */
#define Spt_DspHandlerLEVEL 4U             /* interrupt level of Spt_DspHandler */
#define Spt_DspHandlerPRIORITY 4U          /* priority of Spt_DspHandler */
#define OSISRSpt_EcsHandler() OSISR1DISP(Spt_EcsHandler) /* IrqChannel is EXTERNAL */
extern void OS_isr_Spt_EcsHandler(void); /* irq: Spt_EcsHandler; channel: EXTERNAL; category: 1 */
#define Spt_EcsHandlerLEVEL 4U             /* interrupt level of Spt_EcsHandler */
#define Spt_EcsHandlerPRIORITY 4U          /* priority of Spt_EcsHandler */
#define OSISRSpt_EvtHandler() OSISR1DISP(Spt_EvtHandler) /* IrqChannel is EXTERNAL */
extern void OS_isr_Spt_EvtHandler(void); /* irq: Spt_EvtHandler; channel: EXTERNAL; category: 1 */
#define Spt_EvtHandlerLEVEL 4U             /* interrupt level of Spt_EvtHandler */
#define Spt_EvtHandlerPRIORITY 4U          /* priority of Spt_EvtHandler */

/* ISR1 id */
#define Bbe32_RxHandler ((ISRType)OS_MKOBJID(OBJECT_ISR, 0U)) /* ISR ID */
#define Spt_DspHandler ((ISRType)OS_MKOBJID(OBJECT_ISR, 1U)) /* ISR ID */
#define Spt_EcsHandler ((ISRType)OS_MKOBJID(OBJECT_ISR, 2U)) /* ISR ID */
#define Spt_EvtHandler ((ISRType)OS_MKOBJID(OBJECT_ISR, 3U)) /* ISR ID */

/* Resources definitions */
#define RES_SCHEDULER ((ResourceType)OS_MKOBJID(OBJECT_RESOURCE, 0U)) /* Resource ID */

/* Events definition */

/* Alarms identification */

/* Counters identification */

/* Messages identification */

/* Flags identification */

/* Message callback prototypes */

/* scheduletable */
#define APP_STOP_SEC_CODE
#include    "Os_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif /* OSCFG_H */

