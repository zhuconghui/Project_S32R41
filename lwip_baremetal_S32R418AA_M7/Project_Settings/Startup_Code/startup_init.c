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
*   (c) Copyright 2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @implements startup.c_Artifact
*/

#include "Std_Types.h"

/*******************************************************************************
 * Definitions
 *******************************************************************************/
#if (CPU_TYPE == CPU_TYPE_64)
    typedef uint64 uintptr;
#elif (CPU_TYPE == CPU_TYPE_32)
    typedef uint32 uintptr;
#elif (CPU_TYPE == CPU_TYPE_16)
    typedef uint16 uintptr;
#else
    typedef uint8 uintptr;
#endif

 /*!
 * @brief Defines the init table layout
 */
typedef struct
{
    uint8 * ram_start; /*!< Start address of section in RAM */
    uint8 * rom_start; /*!< Start address of section in ROM */
    uint8 * rom_end;   /*!< End address of section in ROM */
} Sys_CopyLayoutType;

/*!
 * @brief Defines the zero table layout
 */
typedef struct
{
    uint8 * ram_start; /*!< Start address of section in RAM */
    uint8 * ram_end;   /*!< End address of section in RAM */
} Sys_ZeroLayoutType;

extern uintptr __INIT_TABLE[1U];
extern uintptr __ZERO_TABLE[1U];
#if (defined(__ARMCC_VERSION))
    extern uintptr __VECTOR_RAM;
#else
    extern uintptr __VECTOR_RAM[1U];
#endif

/*******************************************************************************
 * Static Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : init_data_bss
 * Description   : Make necessary initializations for RAM.
 * - Copy the vector table from ROM to RAM.
 * - Copy initialized data from ROM to RAM.
 * - Copy code that should reside in RAM from ROM
 * - Clear the zero-initialized data section.
 *
 * Tool Chains:
 *   __GNUC__           : GNU Compiler Collection
 *   __ghs__            : Green Hills ARM Compiler
 *   __ICCARM__         : IAR ARM Compiler
 *   __DCC__            : Wind River Diab Compiler
 *   __ARMCC_VERSION    : ARMC Compiler
 *
 * Implements    : init_data_bss_Activity
 *END**************************************************************************/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
 
void init_data_bss(void);

void init_data_bss(void)
{
    const Sys_CopyLayoutType * copy_layout;
    const Sys_ZeroLayoutType * zero_layout;
    const uint8 * rom;
    uint8 * ram;
    uint32 len = 0U;
    uintptr size = 0U;
    uint32 i = 0U;
    uint32 j = 0U;

    const uintptr * initTable_Ptr = (uintptr*)__INIT_TABLE;
    const uintptr * zeroTable_Ptr = (uintptr*)__ZERO_TABLE;

    /* Copy initialized table */
    len = *initTable_Ptr;
    initTable_Ptr++;
    copy_layout = (const Sys_CopyLayoutType *)initTable_Ptr;
    for(i = 0; i < len; i++)
    {
        rom = copy_layout[i].rom_start;
        ram = copy_layout[i].ram_start;
        size = (uintptr)(copy_layout[i].rom_end - copy_layout[i].rom_start);

        for(j = 0UL; j < size; j++)
        {
            ram[j] = rom[j];
        }
    }

    /* Clear zero table */
    len = *zeroTable_Ptr;
    zeroTable_Ptr++;
    zero_layout = (const Sys_ZeroLayoutType *)zeroTable_Ptr;
    for(i = 0; i < len; i++)
    {
        ram = zero_layout[i].ram_start;
        size = (uintptr)(zero_layout[i].ram_end - zero_layout[i].ram_start);

        for(j = 0UL; j < size; j++)
        {
            ram[j] = 0U;
        }
    }
}
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/*******************************************************************************
 * EOF
 ******************************************************************************/
