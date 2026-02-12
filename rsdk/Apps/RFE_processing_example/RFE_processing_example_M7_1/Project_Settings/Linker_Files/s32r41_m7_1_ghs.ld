/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.0
*   Build Version        : S32R41_RTD_1_0_0_HF01_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   (c) Copyright 2021 - 2023 NXP Semiconductors
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
/*
* Target device: This linker is demo and it is using for device S32R41xxx only
* Target core: ARM cortex M7 core 1 (M7_1)
* Linker support for application running on M7_1 only. It need to align with MPU default setup in core.c as well.
* Linker option: -Wl,--defsym,<device>=1 where <device> is S32R418AA/S32R418AB/S32R416LB
* Memory setting: Realtime SRAM
*/

DEFAULTS {
HEAP_SIZE  = 0x00001000
SRAM_SIZE = 0x00400000 

RAM_M7_1_START_ADDR    = 0x34200000 /* Realtime SRAM */
RAM_M7_1_SIZE          = 0x001C0000 
RAM_M7_1_NO_CACHE_SIZE = 0x00020000 
RAM_SHARED_SIZE_RTD    = 0x00010000 /* 16K for RTD */
} /* DEFAULTS */

MEMORY
{
    int_itcm                   : ORIGIN = 0x00000000, LENGTH = 0x00000000 /* 0KB - Not Supported */
    int_dtcm                   : ORIGIN = 0x20000000, LENGTH = 0x0000E000 /* 56KB */
    int_dtcm_stack             : ORIGIN = 0x2000E000, LENGTH = 0x00002000 /* 8KB */
    
    int_sram_c1                : ORIGIN = RAM_M7_1_START_ADDR, LENGTH = RAM_M7_1_SIZE - RAM_M7_1_NO_CACHE_SIZE
    int_sram_no_cacheable_c1   : ORIGIN = RAM_M7_1_START_ADDR + RAM_M7_1_SIZE - RAM_M7_1_NO_CACHE_SIZE, LENGTH = RAM_M7_1_NO_CACHE_SIZE - RAM_SHARED_SIZE_RTD /* needs to include int_results  */
    int_sram_shareable         : ORIGIN = RAM_M7_1_START_ADDR + RAM_M7_1_SIZE - RAM_SHARED_SIZE_RTD, LENGTH = RAM_SHARED_SIZE_RTD
    ram_end_c1                 : ORIGIN = RAM_M7_1_START_ADDR + RAM_M7_1_SIZE, LENGTH = 0x00000000 /* End of core 1 ram */    
    ram_rsvd2                  : ORIGIN = RAM_M7_1_START_ADDR + RAM_M7_1_SIZE + RAM_M7_1_SIZE, LENGTH = 0 /* End of SRAM */
}

SECTIONS
{

    .sram :
    {
        . = ALIGN(0x80);
        __interrupts_init_start = .;
        *(.intc_vector)
        . = ALIGN(4);
        __interrupts_init_end = .;
        *(.core_loop)
        . = ALIGN(4);
        *(.startup)
        . = ALIGN(4);
        *(.systeminit)
        . = ALIGN(4);
        *(.text.startup)
        . = ALIGN(4);
        *(.text)
        "*(.text*)"
        . = ALIGN(4);
        *(.mcal_text)
        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        KEEP(*(.fini))

        . = ALIGN(4);
        *(.rodata)
        "*(.rodata*)"
        . = ALIGN(4);
        *(.mcal_const_cfg)
        . = ALIGN(4);
        *(.mcal_const)

        . = ALIGN(4);
        __init_table = .;
        *(.init_table)
        . = ALIGN(4);
        __zero_table = .;
        *(.zero_table)
        . = ALIGN(4);
        *(.acfls_code_rom)
        . = ALIGN(4);
        *(.aceep_code_rom)
        . = ALIGN(4);
        *(.acmcu_code_rom)
        . = ALIGN(4);
        *(.ramcode)
        . = ALIGN(4);
        *(.data)
        "*(.data*)"
        "*(.RSDK_RFE_INTERNAL_MEMORY)"
        . = ALIGN(4);
        *(.mcal_data)
        . = ALIGN(16);
    } > int_sram_c1

    .bss:
    {
        . = ALIGN(16);
        __sram_bss_start = .;
        __bss_start__ = .;
        "*(.bss)"
        "*(.bss.*)"
        . = ALIGN(16);
        "*(.mcal_bss)"
        . = ALIGN(16);
        __sram_bss_end = .;
        __bss_end__ = .;
    } > int_sram_c1

	. = ALIGN(4);
    __ram_end = .;

    .non_cacheable :
    {
        . = ALIGN(4);
        KEEP(*(.int_results))
        . += 0x100;
        . = ALIGN(16);
        __non_cacheable_bss_start = .;
        *(.mcal_bss_no_cacheable)
        . = ALIGN(4);
        __non_cacheable_bss_end = .;
        . = ALIGN(4);
        *(.mcal_data_no_cacheable)
        . = ALIGN(4);
        *(.mcal_const_no_cacheable)
        HSE_LOOP_ADDR = .;
    } > int_sram_no_cacheable_c1

    /* heap section */
    .heap (NOLOAD):
    {
        . += ALIGN(4);
        _end = .;
        end = .;
        _heap_start = .;
        . += HEAP_SIZE;
        _heap_end = .;
    } > int_sram_no_cacheable_c1

    .shareable_ram_data (NOLOAD) :
    {
        . = ALIGN(16);
    __shareable_data_start = .;
        KEEP(*(.mcal_shared_data))
    . = ALIGN(4);
    __shareable_data_end = .;
    } > int_sram_shareable

    .shareable_ram_bss (NOLOAD):
    {
        . = ALIGN(16);
        __shareable_bss_start = .;
        KEEP(*(.mcal_shared_bss))
        . = ALIGN(4);
        __shareable_bss_end = .;
    } > int_sram_shareable

    .intc_vector_dtcm :
    {
        . = ALIGN(2048);
        __interrupts_ram_start = .;
        . += __interrupts_init_end - __interrupts_init_start;
        . = ALIGN(4);
        __interrupts_ram_end = .;
    } > int_dtcm

    __dtcm_data_rom = __ram_end;
    .dtcm_data : AT(__dtcm_data_rom)
    {
        . = ALIGN(16);
        __dtcm_data_start = .;
        *(.dtcm_data)
        . = ALIGN(4);
        __dtcm_data_end = .;
    } > int_dtcm
    __dtcm_data_rom_end = __dtcm_data_rom + (__dtcm_data_end - __dtcm_data_start);

    .dtcm_bss (NOLOAD) :
    {
        . = ALIGN(16);
        __dtcm_bss_start = .;
        *(.dtcm_bss)
        . = ALIGN(4);
        __dtcm_bss_end = .;
    } > int_dtcm

    __INT_SRAM_START         = addr(int_sram_c1);
    __INT_SRAM_END           = addr(ram_end_c1);

    __INT_ITCM_START         = addr(int_itcm);
    __INT_ITCM_END           = addr(int_itcm) + sizeof(int_itcm);

    __INT_DTCM_START         = addr(int_dtcm);
    __INT_DTCM_END           = addr(int_dtcm) + sizeof(int_dtcm) + sizeof(int_dtcm_stack);

    __RAM_SHAREABLE_START    = addr(int_sram_shareable);
    __RAM_SHAREABLE_END      = addr(int_sram_shareable) + sizeof(int_sram_shareable);
    __ROM_SHAREABLE_START    = 0;
    __ROM_SHAREABLE_END      = 0;
    __RAM_NO_CACHEABLE_START = addr(int_sram_no_cacheable_c1);
    __RAM_NO_CACHEABLE_END   = addr(int_sram_no_cacheable_c1) + sizeof(int_sram_no_cacheable_c1);
    __ROM_NO_CACHEABLE_START = 0;
    __ROM_NO_CACHEABLE_END   = 0;
    __RAM_CACHEABLE_START    = addr(int_sram_c1);
    __RAM_CACHEABLE_END      = addr(int_sram_c1) + sizeof(int_sram_c1);
    __ROM_CACHEABLE_START    = 0;
    __ROM_CACHEABLE_END      = 0;

    __BSS_SRAM_START         = __sram_bss_start;
    __BSS_SRAM_END           = __sram_bss_end;
    __BSS_SRAM_SIZE          = __sram_bss_end - __sram_bss_start;

    __BSS_SRAM_NC_START      = __non_cacheable_bss_start;
    __BSS_SRAM_NC_SIZE       = __non_cacheable_bss_end - __non_cacheable_bss_start;
    __BSS_SRAM_NC_END        = __non_cacheable_bss_end;

    __BSS_SRAM_SH_START       = __shareable_bss_start;
    __BSS_SRAM_SH_SIZE        = __shareable_bss_end - __shareable_bss_start;
    __BSS_SRAM_SH_END         = __BSS_SRAM_SH_START;

    __RAM_INTERRUPT_START    = __interrupts_ram_start;
    __ROM_INTERRUPT_START    = __interrupts_init_start;
    __ROM_INTERRUPT_END      = __interrupts_init_end;

    __INIT_TABLE             = __init_table;
    __ZERO_TABLE             = __zero_table;

    __RAM_INIT               = 0;
    __ITCM_INIT              = 0;
    __DTCM_INIT              = 1;

    __BSS_DTCM_START         = __dtcm_bss_start;
    __BSS_DTCM_SIZE          = __dtcm_bss_end - __dtcm_bss_start;
    __BSS_DTCM_END           = __dtcm_bss_end;

    __RAM_DTCM_START         = __dtcm_data_start;
    __RAM_DTCM_END           = __dtcm_data_end;
    __ROM_DTCM_START         = __dtcm_data_rom;
    __ROM_DTCM_END           = __dtcm_data_rom_end;

    __Stack_end              = addr(int_dtcm_stack);
    __Stack_start            = addr(int_dtcm_stack) + sizeof(int_dtcm_stack);

    __INDEX_COPY_CORE2       = 0;    /* This symbol is used to initialize data of ITCM/DTCM for secondary cores */

   /* Discard boot header in RAM */
   /DISCARD/ : { *(.boot_header) }

}

