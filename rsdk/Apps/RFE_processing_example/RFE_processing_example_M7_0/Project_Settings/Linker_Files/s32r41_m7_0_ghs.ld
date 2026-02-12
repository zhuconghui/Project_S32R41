/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.8.0
*   Build Version        : S32R_RTD_0_8_0_D2203_ASR_REL_4_4_REV_0000_20220329
*
*   Copyright 2022-2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

DEFAULTS {
HEAP_SIZE  =  0x00003000

APP_RAM_START_ADDR = 0x33CC0000

/* Define SRAM Base Address for SPT usage*/
/* place everything in SRAM */
RSDK_SPT_SRAM_BASE_ADDR = APP_RAM_START_ADDR

/* Labels used by SPT driver and kernels */
RSDK_SPT_CUBE_BASE_ADDR = RSDK_SPT_SRAM_BASE_ADDR  
RSDK_SPT_OTHER_BASE_ADDR = RSDK_SPT_CUBE_BASE_ADDR /* same address for now */ 
/* Need to duplicate this definitions until SPT kernel sources are aligned with autosar code in SPT_internals.c*/
SPT_CUBE_BASE_ADDR = RSDK_SPT_CUBE_BASE_ADDR
SPT_OTHER_BASE_ADDR = RSDK_SPT_OTHER_BASE_ADDR

RSDK_DSPHD_MSG_BASE_ADDR = 0x34000000
RSDK_DSPHD_MSG_MEM_SIZE = 0x800

RFE_SW_MEM_BASE_ADDRESS = 0x343F0000
RFE_SW_MEM_SIZE = 0x10000
INT_SRAM_LEN = 0x1D0000
INT_SRAM_START_ADDR = 0x34000800

INT_SRAM_OS_LEN = 0x7000
INT_SRAM_OS_START_ADDR = INT_SRAM_START_ADDR + INT_SRAM_LEN

INT_SRAM_SHAREABLE_LEN = 0x4000
INT_SRAM_SHAREABLE_START_ADDR = INT_SRAM_OS_START_ADDR + INT_SRAM_OS_LEN

INT_SRAM_STACK_C0_LEN = 0x00002000
INT_SRAM_STACK_C0_START_ADDR = INT_SRAM_SHAREABLE_START_ADDR + INT_SRAM_SHAREABLE_LEN

INT_SRAM_NO_CACHE_LEN = 0x00008000
INT_SRAM_NO_CACHE_START_ADDR = INT_SRAM_STACK_C0_START_ADDR + INT_SRAM_STACK_C0_LEN

RSVD_START_ADDR = INT_SRAM_NO_CACHE_START_ADDR + INT_SRAM_NO_CACHE_LEN

RSDK_SPT_CODE_LEN = 0x10000 /* 64KiB */
RSDK_SPT_CODE_ADDR = INT_SRAM_START_ADDR - RSDK_DSPHD_MSG_MEM_SIZE - RSDK_SPT_CODE_LEN

BUFF_RAM_LEN = RSDK_SPT_CODE_ADDR - APP_RAM_START_ADDR /* remaining space for the buffers */

} /* DEFAULTS */

MEMORY 
{         
	BUFF_RAM (rw)           : ORIGIN = APP_RAM_START_ADDR, LENGTH = BUFF_RAM_LEN
	SPT_CODE (rx)			: ORIGIN = RSDK_SPT_CODE_ADDR, LENGTH = RSDK_SPT_CODE_LEN
	DSPHD_RAM (rw)          : ORIGIN = RSDK_DSPHD_MSG_BASE_ADDR, LENGTH = RSDK_DSPHD_MSG_MEM_SIZE    	/* Shared mem for DSP Host Driver */ 
																										/*!!! ATTENTION: It must not overlap with the sections defined in dsp_image_<PLATFORM>.c */
    RFE_SW_RAM (rw)         : ORIGIN = RFE_SW_MEM_BASE_ADDRESS, LENGTH = RFE_SW_MEM_SIZE    			/* Shared mem for RFE Firmware and Driver */ 
    
    int_sram                : ORIGIN = INT_SRAM_START_ADDR, LENGTH = INT_SRAM_LEN 						/* 428KB */
    OsInternalRAM (rwx)     : ORIGIN = INT_SRAM_OS_START_ADDR,  LENGTH = INT_SRAM_OS_LEN 				/* 28K */
    int_sram_shareable      : ORIGIN = INT_SRAM_SHAREABLE_START_ADDR, LENGTH = INT_SRAM_SHAREABLE_LEN 	/* 16KiB */

    int_sram_stack_c0       : ORIGIN = INT_SRAM_STACK_C0_START_ADDR, LENGTH = INT_SRAM_STACK_C0_LEN 	/* 8KiB  */
    int_sram_no_cacheable   : ORIGIN = INT_SRAM_NO_CACHE_START_ADDR, LENGTH = INT_SRAM_NO_CACHE_LEN 	/* 32KiB, needs to include int_results  */

    ram_rsvd2               : ORIGIN = RSVD_START_ADDR, LENGTH = 0         								/* End of RT-SRAM */
    
}


SECTIONS
{
  
      .ecc.table:
    {
        . = ALIGN(4);
        __ecc_table_start__ = .;
        /* ECC memory for .data section is initialized during copying of application image
        */
        "*(.ecc_tables)"
        __ecc_table_end__ = .;
    } > int_sram

    .copy.table:
    {
        . = ALIGN(4);
        __copy_table_start__ = .;
        "*(.copy_tables)"
        /* Add each additional data section here */
        __copy_table_end__ = .;
    } > int_sram

    .zero.table:
    {
        . = ALIGN(4);
        __zero_table_start__ = .;
        "*(.zero_tables)"
        /* Add each additional bss section here */
        __zero_table_end__ = .;
    } > int_sram
  
    .sram :
    {
        . = ALIGN(4);
        KEEP(*(.core_loop)) 
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
        KEEP(*(.init_table))  
        . = ALIGN(4);
        __zero_table = .;
        KEEP(*(.zero_table))
        
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
        . = ALIGN(4);
        *(.mcal_data)  
        . = ALIGN(16);
        . = ALIGN(16);
    } > int_sram

    /* Due ECC initialization sequence __bss_start__ and __bss_end__ should be aligned on 8 bytes */
    .bss:
    {
        . = ALIGN(16);
        __sram_bss_start = .;
        __bss_start__ = .;
        "*(.bss)"
        "*(.bss.*)"
        "*(.mcal_bss)"
        . = ALIGN(16);
        __sram_bss_end = .;
        __bss_end__ = .;
    } > int_sram
    
	. = ALIGN(4);
	__sram_shareable_rom = .;
	

    .non_cacheable :
    {
        . = ALIGN(4);
        KEEP(*(.int_results))  
        . += 0x100;
        . = ALIGN(4096);
        __interrupts_ram_start = .;
        KEEP(*(.intc_vector))    
        . = ALIGN(4);
        __interrupts_ram_end = .;
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
    } > int_sram_no_cacheable

    /* heap section */        
    .heap (COPY):
    {
    	. += ALIGN(8);
	    _end = .;
	    end = .;
        _heap_start = .;
        . += HEAP_SIZE;
        _heap_end = .;
    } > int_sram

    .shareable_ram_bss (NOLOAD):
    {
    	. = ALIGN(16);
    	__shareable_bss_start = .;
    	KEEP(*(.mcal_shared_bss))
    	. = ALIGN(4);
    	__shareable_bss_end = .;
    } > int_sram_shareable

    .shareable_ram_data : AT(__sram_shareable_rom)
    {
        . = ALIGN(16);
	__shareable_data_start = .;
    	KEEP(*(.mcal_shared_data))
	. = ALIGN(4);
	__shareable_data_end = .;
    } > int_sram_shareable
	
    __sram_shareable_rom_end = __sram_shareable_rom + (__shareable_data_end - __shareable_data_start);

    __Stack_end_c0           = addr(int_sram_stack_c0);
    __Stack_start_c0         = addr(int_sram_stack_c0) + sizeof(int_sram_stack_c0);

    __INT_SRAM_START         = addr(int_sram);
    __INT_SRAM_END           = addr(ram_rsvd2);
        
    __RAM_SHAREABLE_START    = addr(int_sram_shareable);
    __RAM_SHAREABLE_END      = addr(int_sram_shareable) + sizeof(int_sram_shareable) - 1;
    __ROM_SHAREABLE_START    = __sram_shareable_rom;
    __ROM_SHAREABLE_END      = __sram_shareable_rom_end;
    __RAM_NO_CACHEABLE_START = addr(int_sram_no_cacheable);
    __RAM_NO_CACHEABLE_END   = addr(int_sram_no_cacheable) + sizeof(int_sram_no_cacheable) - 1;
    __ROM_NO_CACHEABLE_START = 0;
    __ROM_NO_CACHEABLE_END   = 0;
    __RAM_CACHEABLE_START    = addr(int_sram);
    __RAM_CACHEABLE_END      = addr(int_sram) + sizeof(int_sram) - 1;
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
    __BSS_SRAM_SH_END         = __shareable_bss_end;

    __RAM_INTERRUPT_START    = __interrupts_ram_start;
    __ROM_INTERRUPT_START    = 0;
    __ROM_INTERRUPT_END      = 0;

    __INIT_TABLE             = __init_table;
    __ZERO_TABLE             = __zero_table;
    
    __RAM_INIT               = 0;

   /* Discard boot header in RAM */
   /DISCARD/ : { *(.boot_header) }

    /* To calculate the address of the interrupt vectors for the secondary cores
     * we assume that the offset from the int_sram_no_cacheable region is the 
     * same for all cores 
     */

	.data_radar :
    {
        . = ALIGN(8);
		*(.radar)
    } > BUFF_RAM
	
	.code_spt :
	{
	 	. = ALIGN(16);
	 	"*(.RsdkSpt3*)"
	 	. = ALIGN(8);
	} > SPT_CODE
	
	    .data_dsphd :
    {
        __dspmsg = .;
 		*(.dsphd)
		*(.dsphd_jobs)
	} > DSPHD_RAM
	
	   .data_rfesw :
    {
		*(.rfe_fw)
	} > RFE_SW_RAM

    .os_stacks :
    {
    /* ------------------------------------ OS stack area ------------------------------------ */
    . = ALIGN(0x20);
    *(.osstack)

    . = ALIGN(0x20);
    *(.osstack2)

    /* ------------------------------------ main stacks section ------------------------------------ */
    . = ALIGN(16);
    _Stack_end  = .;
    OS_MAIN_STACK_MIN = .;

    *(.stack_main)

    _Stack_start = .; /* stack grows downward */
    OS_MAIN_STACK_MAX  = .;

    . = ALIGN(16);
    _Stack2_end  = .;
    OS2_MAIN_STACK_MIN = .;

    *(.stack2_main)

    _Stack2_start = .; /* stack2 grows downward */
    OS2_MAIN_STACK_MAX  = .;

	} > OsInternalRAM
    
	.all_os_data :
    {
    OS_NONCACHE_BSS_START  = . ;
    . = ALIGN(0x20);
    *(.osbeginnoncache)
    *(.osnoncacheablebss)
    . = ALIGN(0x20);
    *(.osendnoncache)
    OS_NONCACHE_BSS_END    = . ;


    /* -------------------------------------- Default data/bss --------------------------------- */
    *(.osdata)                           /* it is empty */
    *(.ossdata)

    . = ALIGN(0x20);
    *(.sapp_v32_data)
    *(.sapp_v16_data)
    *(.sapp_vU_data)
    *(.sapp_v8_data)

    /* ------------------------------------ BSS sections ------------------------------------ */
    _bss_start = .;
    *(.osbss)
    *(.ossbss)

    . = ALIGN(0x20);
    *(.sapp_v32_bss)
    *(.sapp_v16_bss)
    *(.sapp_vU_bss)
    *(.sapp_v8_bss)

    _bss_end = .;


    } >OsInternalRAM

    .all_os_text :
    {
    . = ALIGN(0x80);	/* required alignment to match the startup code in startup_ghs.s - look for "relocate vector table to RAM" */
	*(.vector)

    /* Code and constant area (all code and constant sections shall be placed between .osbegincode and .osendcode sections). */
    . = ALIGN(0x20);
    *(.osbegincode)  /* for mem protection only */
    *(.ostext)

    *(.oshook)
    *(.syscall)
    *(.secinfo)
    *(.sapp_c32)
    *(.sapp_c16)
    *(.sapp_cU)
    *(.sapp_c8)
    *(.appcode)

    *(.osrodata)
    *(.ossrodata)
    *(.ROM.data)

    *(.osendcode)    /* for mem protection only */
    
	} > OsInternalRAM

	RSDK_SPT_CUBE_BASE_ADDR = addr(BUFF_RAM);  
	RSDK_SPT_OTHER_BASE_ADDR = addr(BUFF_RAM); 
	RSDK_DSPHD_MSG_BASE_ADDR = addr(DSPHD_RAM);

}

