/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.9.0
*   Build Version        : SAF85_S32R41_RTD_0_9_0_D2207_ASR_REL_4_4_REV_0000_20220729
*
*   Copyright 2022 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "core.h"
#include "nvic.h"
#include "Mcal.h"

#if (MCAL_PLATFORM_ARM != MCAL_ARM_MARCH)
    #error M7-specific file included in compilation, but MCAL_PLATFORM_ARM != MCAL_ARM_MARCH. Double check the value of the Resource.ARM_CoreArchitecture configuration field.
#endif

#ifdef S32R41
#include "S32R41_SCB.h"
#include "S32R41_MPU.h"
#else
#include "SAF85XX_SCB.h"
#include "SAF85XX_MPU.h"
#endif

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define SVC_GoToSupervisor()                      ASM_KEYWORD("svc 0x0")
#define SVC_GoToUser()                            ASM_KEYWORD("svc 0x1")
#define SVC_ResumeInterrupts()                    ASM_KEYWORD("svc 0x2")
#define SVC_SuspendInterrupts()                   ASM_KEYWORD("svc 0x3")

#define S32_SCB_CPACR_CPx_SHIFT(CpNum)            (2U*((uint32)CpNum))
#define S32_SCB_CPACR_CPx_MASK(CpNum)             (0x3U << S32_SCB_CPACR_CPx_SHIFT(CpNum))
#define S32_SCB_CPACR_CPx(CpNum, x)               (((uint32)(((uint32)(x))<<S32_SCB_CPACR_CPx_SHIFT((CpNum))))&S32_SCB_CPACR_CPx_MASK((CpNum)))

#define SCB_CCSIDR_NUMSETS_Pos                    13U
#define SCB_CCSIDR_NUMSETS_Msk                    (0x7FFFUL << SCB_CCSIDR_NUMSETS_Pos)

#define SCB_CCSIDR_ASSOCIATIVITY_Pos              3U
#define SCB_CCSIDR_ASSOCIATIVITY_Msk              (0x3FFUL << SCB_CCSIDR_ASSOCIATIVITY_Pos)

#define CCSIDR_WAYS(x)                            (((x) & SCB_CCSIDR_ASSOCIATIVITY_Msk) >> SCB_CCSIDR_ASSOCIATIVITY_Pos)
#define CCSIDR_SETS(x)                            (((x) & SCB_CCSIDR_NUMSETS_Msk      ) >> SCB_CCSIDR_NUMSETS_Pos)

#define SCB_CCR_IC_Pos                            17U
#define SCB_CCR_IC_Msk                            (1UL << SCB_CCR_IC_Pos)

#define SCB_CCR_DC_Pos                            16U
#define SCB_CCR_DC_Msk                            (1UL << SCB_CCR_DC_Pos)

#define SCB_DCISW_WAY_Pos                         30U
#define SCB_DCISW_WAY_Msk                         (3UL << SCB_DCISW_WAY_Pos)

#define SCB_DCISW_SET_Pos                         5U
#define SCB_DCISW_SET_Msk                         (0x1FFUL << SCB_DCISW_SET_Pos)


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#ifndef MULTIPLE_IMAGE
/* Single ELF for one or all cores */

/* Number of entries in the memory tables */
#define CPU_MPU_MEMORY_COUNT (10U)

/*
  Region  Description            Start       End           Size[KB]  Type              Inner Cache Policy    Outer Cache Policy    Shareable    Executable    Privileged Access    Unprivileged Access
--------  ---------------------  ----------  ----------  ----------  ----------------  --------------------  --------------------  -----------  ------------  -------------------  ---------------------
       0  Whole memory map       0x0         0xFFFFFFFF     4194304  Strongly Ordered  None                  None                  Yes          No            No Access            No Access
       1  QSPI AHB               0x0         0x1FFFFFFF      524288  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
       2  DTCM                   0x20000000  0x2000FFFF          64  Strongly Ordered  None                  None                  Yes          No            Read/Write           Read/Write
       3  Application SRAM       0x33C00000  0x33FFFFFF        4096  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
       4  Realtime SRAM + STACK  0x34000000  0x343FFFFF        4096  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
       5  Realtime SRAM SHARE    0x34000000  0x34003FFF          16  Normal            None                  None                  Yes          No            Read/Write           Read/Write
       6  Realtime SRAM NC       0x34300000  0x343FFFFF        1024  Normal            None                  None                  Yes          Yes           Read/Write           Read/Write
       7  Retention SRAM         0x34400000  0x34403FFF          16  Normal            Write-Back/Allocate   Write-Back/Allocate   Yes          Yes           Read/Write           Read/Write
       8  Peripherals            0x40000000  0x5FFFFFFF      524288  Device            None                  None                  Yes          No            Read/Write           Read/Write
       9  PPB                    0xE0000000  0xE00FFFFF        1024  Strongly Ordered  None                  None                  Yes          No            Read/Write           Read/Write
*/

#ifdef S32R41
#ifdef S32R416LB
/* S32R416LB
       6  Realtime SRAM NC       0x34200000  0x342FFFFF        1024  Normal            None                  None                  Yes          Yes           Read/Write           Read/Write
*/
static const uint32 rbar[] = {0x00000000UL, 0x00000000UL, 0x20000000UL, 0x33C00000UL, 0x34000000UL, 0x34000000UL, 0x34200000UL, 0x34400000UL, 0x40000000UL, 0xE0000000UL};
static const uint32 rasr[] = {0x1004003FUL, 0x030B0039UL, 0x1304001FUL, 0x030B002BUL, 0x030B002BUL, 0x130C001BUL, 0x030C0027UL, 0x030F001BUL, 0x13050039UL, 0x13040027UL};
#else
static const uint32 rbar[] = {0x00000000UL, 0x00000000UL, 0x20000000UL, 0x33C00000UL, 0x34000000UL, 0x34000000UL, 0x34300000UL, 0x34400000UL, 0x40000000UL, 0xE0000000UL};
static const uint32 rasr[] = {0x1004003FUL, 0x030B0039UL, 0x1304001FUL, 0x030B002BUL, 0x030B002BUL, 0x130C001BUL, 0x030C0027UL, 0x030F001BUL, 0x13050039UL, 0x13040027UL};
#endif
#else
/* SAF85XX
       6  Realtime SRAM NC       0x34060000  0x3407FFFF         128  Normal            None                  None                  Yes          Yes           Read/Write           Read/Write
*/
static const uint32 rbar[] = {0x00000000UL, 0x00000000UL, 0x20000000UL, 0x33C00000UL, 0x34000000UL, 0x34000000UL, 0x34060000UL, 0x34400000UL, 0x40000000UL, 0xE0000000UL};
static const uint32 rasr[] = {0x1004003FUL, 0x030B0039UL, 0x1304001FUL, 0x030B002BUL, 0x030B002BUL, 0x130C001BUL, 0x030C0021UL, 0x030F001BUL, 0x13050039UL, 0x13040027UL};
#endif
#else
#if defined(CORE0)
/* Number of entries in the memory tables */
#define CPU_MPU_MEMORY_COUNT (10U)

/*
  Region  Description            Start       End           Size[KB]  Type              Inner Cache Policy    Outer Cache Policy    Shareable    Executable    Privileged Access    Unprivileged Access
--------  ---------------------  ----------  ----------  ----------  ----------------  --------------------  --------------------  -----------  ------------  -------------------  ---------------------
       0  Whole memory map       0x0         0xFFFFFFFF     4194304  Strongly Ordered  None                  None                  Yes          No            No Access            No Access
       1  QSPI AHB               0x0         0x1FFFFFFF      524288  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
       2  DTCM                   0x20000000  0x2000FFFF          64  Strongly Ordered  None                  None                  Yes          No            Read/Write           Read/Write
       3  Application SRAM       0x33C00000  0x33FFFFFF        4096  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
       4  Realtime SRAM + STACK  0x34000000  0x341FFFFF        2048  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
       5  Realtime SRAM SHARE    0x34000000  0x34003FFF          16  Normal            None                  None                  Yes          No            Read/Write           Read/Write
       6  Realtime SRAM NC       0x34180000  0x341FFFFF         512  Normal            None                  None                  Yes          Yes           Read/Write           Read/Write
       7  Retention SRAM         0x34400000  0x34403FFF          16  Normal            Write-Back/Allocate   Write-Back/Allocate   Yes          Yes           Read/Write           Read/Write
       8  Peripherals            0x40000000  0x5FFFFFFF      524288  Device            None                  None                  Yes          No            Read/Write           Read/Write
       9  PPB                    0xE0000000  0xE00FFFFF        1024  Strongly Ordered  None                  None                  Yes          No            Read/Write           Read/Write
*/

#ifdef S32R416LB
/* S32R416LB
       6  Realtime SRAM NC       0x34100000  0x3417FFFF         512  Normal            None                  None                  Yes          Yes           Read/Write           Read/Write
*/
static const uint32 rbar[] = {0x00000000UL, 0x00000000UL, 0x20000000UL, 0x33C00000UL, 0x34000000UL, 0x34000000UL, 0x34100000UL, 0x34400000UL, 0x40000000UL, 0xE0000000UL};
static const uint32 rasr[] = {0x1004003FUL, 0x030B0039UL, 0x1304001FUL, 0x030B002BUL, 0x030B0029UL, 0x130C001BUL, 0x030C0025UL, 0x030F001BUL, 0x13050039UL, 0x13040027UL};
#else
static const uint32 rbar[] = {0x00000000UL, 0x00000000UL, 0x20000000UL, 0x33C00000UL, 0x34000000UL, 0x34000000UL, 0x34180000UL, 0x34400000UL, 0x40000000UL, 0xE0000000UL};
static const uint32 rasr[] = {0x1004003FUL, 0x030B0039UL, 0x1304001FUL, 0x030B002BUL, 0x030B0029UL, 0x130C001BUL, 0x030C0025UL, 0x030F001BUL, 0x13050039UL, 0x13040027UL};
#endif
#elif defined(CORE1)
/* Number of entries in the memory tables */
#define CPU_MPU_MEMORY_COUNT (10U)

/*
  Region  Description            Start       End           Size[KB]  Type              Inner Cache Policy    Outer Cache Policy    Shareable    Executable    Privileged Access    Unprivileged Access
--------  ---------------------  ----------  ----------  ----------  ----------------  --------------------  --------------------  -----------  ------------  -------------------  ---------------------
       0  Whole memory map       0x0         0xFFFFFFFF     4194304  Strongly Ordered  None                  None                  Yes          No            No Access            No Access
       1  QSPI AHB               0x0         0x1FFFFFFF      524288  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
       2  DTCM                   0x20000000  0x2000FFFF          64  Strongly Ordered  None                  None                  Yes          No            Read/Write           Read/Write
       3  Application SRAM       0x33C00000  0x33FFFFFF        4096  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
       4  Realtime SRAM SHARE    0x34000000  0x34003FFF          16  Normal            None                  None                  Yes          No            Read/Write           Read/Write
       5  Realtime SRAM + STACK  0x34200000  0x343FFFFF        2048  Normal            Write-Back/Allocate   Write-Back/Allocate   No           Yes           Read/Write           Read/Write
       6  Realtime SRAM NC       0x34380000  0x343FFFFF         512  Normal            None                  None                  Yes          Yes           Read/Write           Read/Write
       7  Retention SRAM         0x34400000  0x34403FFF          16  Normal            Write-Back/Allocate   Write-Back/Allocate   Yes          Yes           Read/Write           Read/Write
       8  Peripherals            0x40000000  0x5FFFFFFF      524288  Device            None                  None                  Yes          No            Read/Write           Read/Write
       9  PPB                    0xE0000000  0xE00FFFFF        1024  Strongly Ordered  None                  None                  Yes          No            Read/Write           Read/Write
*/

#ifdef S32R416LB
/* S32R416LB
       6  Realtime SRAM NC       0x34280000  0x342FFFFF         512  Normal            None                  None                  Yes          Yes           Read/Write           Read/Write
*/
static const uint32 rbar[] = {0x00000000UL, 0x00000000UL, 0x20000000UL, 0x33C00000UL, 0x34000000UL, 0x34200000UL, 0x34280000UL, 0x34400000UL, 0x40000000UL, 0xE0000000UL};
static const uint32 rasr[] = {0x1004003FUL, 0x030B0039UL, 0x1304001FUL, 0x030B002BUL, 0x130C001BUL, 0x030B0029UL, 0x030C0025UL, 0x030F001BUL, 0x13050039UL, 0x13040027UL};
#else
static const uint32 rbar[] = {0x00000000UL, 0x00000000UL, 0x20000000UL, 0x33C00000UL, 0x34000000UL, 0x34200000UL, 0x34380000UL, 0x34400000UL, 0x40000000UL, 0xE0000000UL};
static const uint32 rasr[] = {0x1004003FUL, 0x030B0039UL, 0x1304001FUL, 0x030B002BUL, 0x130C001BUL, 0x030B0029UL, 0x030C0025UL, 0x030F001BUL, 0x13050039UL, 0x13040027UL};
#endif
#endif
#endif /* MULTIPLE_IMAGE */
/*==================================================================================================-
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
LOCAL_INLINE void Direct_GoToUser(void);
LOCAL_INLINE void Direct_GoToUser(void)
{
    ASM_KEYWORD("push {r0}");
    ASM_KEYWORD("ldr r0, =0x1");
    ASM_KEYWORD("msr CONTROL, r0");
    ASM_KEYWORD("pop {r0}");
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT  
extern uint32 startup_getControlRegisterValue(void);
extern uint32 startup_getAipsRegisterValue(void);
extern void Suspend_Interrupts(void);
extern void Resume_Interrupts(void);

uint32 Core_GoToSupervisor(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;
    uint32 u32SwitchToSupervisor;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    /* if core is already in supervisor mode for Thread mode, or running form Handler mode, there is no need to make the switch */
    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        u32SwitchToSupervisor = 0U;
    }
    else
    {
        u32SwitchToSupervisor = 1U;
        SVC_GoToSupervisor();
    }

    return u32SwitchToSupervisor;
}

uint32 Core_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue)
{
    if (1UL == u32SwitchToSupervisor)
    {
        Direct_GoToUser();
    }

    return u32returnValue;
}

uint32 Core_GoToUser(void)
{
    Direct_GoToUser();
    return 0UL;
}

/*================================================================================================*/
/**
* @brief Core_SuspendInterrupts
* @details Suspend Interrupts
*/
/*================================================================================================*/
void Core_SuspendInterrupts(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        Suspend_Interrupts();
    }
    else
    {
        SVC_SuspendInterrupts();
    }
}
/*================================================================================================*/
/**
* @brief Core_ResumeInterrupts
* @details Resume Interrupts
*/
/*================================================================================================*/
void Core_ResumeInterrupts(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        Resume_Interrupts();
    }
    else
    {
        SVC_ResumeInterrupts();
    }
}
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */

/*================================================================================================*/
void Core_disableIsrSource(uint16 id)
{
    NVIC_DisableIRQ(id);
}

void Core_enableIsrSource(uint16 id, uint8 prio)
{
    NVIC_SetPriority(id, prio);
    NVIC_EnableIRQ(id);
}

void Core_clearPendingIsrSource(uint16 id)
{
    /* Not implemented */
    (void)id;
}

void Core_registerIsrHandler(uint16 irq_id, void (*isr_handler)(void))
{
    *(volatile uint32*)((*(volatile uint32*)(0xE000ED08)) + ((16 + irq_id) << 2)) = (uint32)isr_handler;
}

/*================================================================================================*/
#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 
void Core_IC_Init(void)
{
    NVIC_SetPriorityGrouping(0); /* 0 means 7 bits for prio, 1 for sub-prio */
    S32_SCB->CCR |=  1;          /* processor can enter Thread mode from any level under the
                                    control of an EXC_RETURN value, PendSV priority set to 0 */
    S32_SCB->SHPR3 = 0;
}

#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 
void Core_FPU_Init(void)
{
#ifdef ENABLE_FPU
    /* Enable CP10 and CP11 coprocessors */
    S32_SCB->CPACR |= (S32_SCB_CPACR_CPx(10U, 3U) | S32_SCB_CPACR_CPx(11U, 3U)); 

    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
#endif
}

#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 
void Core_MPU_Init(void)
{
    uint32 regionNum;

    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");

    /* Set default memory regions */
    for (regionNum = 0U; regionNum < CPU_MPU_MEMORY_COUNT; regionNum++)
    {
        S32_MPU->RNR  = regionNum;
        S32_MPU->RBAR = rbar[regionNum];
        S32_MPU->RASR = rasr[regionNum];
    }

    /* Enable MPU */
    S32_MPU->CTRL |= S32_MPU_CTRL_ENABLE_MASK;
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
}

#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 
void Core_Cache_Init(void)
{
    uint32 ccsidr = 0U;
    uint32 sets = 0U;
    uint32 ways = 0U;

#ifdef D_CACHE_ENABLE    
    /*init Data caches*/
    S32_SCB->CSSELR = 0U;                       /* select Level 1 data cache */

    ASM_KEYWORD("dsb");
    ccsidr = S32_SCB->CCSIDR;
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    do {
      ways = (uint32)(CCSIDR_WAYS(ccsidr));
      do {
        S32_SCB->DCISW = (((sets << SCB_DCISW_SET_Pos) & SCB_DCISW_SET_Msk) |
                          ((ways << SCB_DCISW_WAY_Pos) & SCB_DCISW_WAY_Msk));
      } while (ways-- != 0U);
    } while(sets-- != 0U);
    ASM_KEYWORD("dsb");
    S32_SCB->CCR |= (uint32)SCB_CCR_DC_Msk;  /* enable D-Cache */
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
#endif

#ifdef I_CACHE_ENABLE  
    /*init Code caches*/
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
    S32_SCB->ICIALLU = 0UL;                     /* invalidate I-Cache */
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
    S32_SCB->CCR |=  (uint32)SCB_CCR_IC_Msk;  /* enable I-Cache */
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
#endif
}


#ifdef __cplusplus
}
#endif
