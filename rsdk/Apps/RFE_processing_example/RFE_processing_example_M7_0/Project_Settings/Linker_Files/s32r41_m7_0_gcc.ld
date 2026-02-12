/*****************************************************************************
 *
 * Copyright 2019 - 2021 NXP
 * All Rights Reserved
 *
 *****************************************************************************
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/
HEAP_SIZE  = DEFINED(__heap_size__)  ? __heap_size__  : 0x00003000;

APP_RAM_START_ADDR = 0x33CC0000;

/* Define SRAM Base Address for SPT usage*/
/* place everything in SRAM */
RSDK_SPT_SRAM_BASE_ADDR = APP_RAM_START_ADDR;

/* Labels used by SPT driver and kernels */
RSDK_SPT_CUBE_BASE_ADDR = RSDK_SPT_SRAM_BASE_ADDR;  
RSDK_SPT_OTHER_BASE_ADDR = RSDK_SPT_CUBE_BASE_ADDR; /* same address for now */ 
/* Need to duplicate this definitions until SPT kernel sources are aligned with autosar code in SPT_internals.c*/
SPT_CUBE_BASE_ADDR = RSDK_SPT_CUBE_BASE_ADDR;
SPT_OTHER_BASE_ADDR = RSDK_SPT_OTHER_BASE_ADDR;

RSDK_DSPHD_MSG_BASE_ADDR = 0x34000000;
RSDK_DSPHD_MSG_MEM_SIZE = 0x800;

RFE_SW_MEM_BASE_ADDRESS = 0x343F0000;
RFE_SW_MEM_SIZE = 0x11000;

INT_SRAM_LEN = 0x1D0000;
INT_SRAM_START_ADDR = 0x34000800;

INT_SRAM_OS_LEN = 0x7000;
INT_SRAM_OS_START_ADDR = INT_SRAM_START_ADDR + INT_SRAM_LEN;

INT_SRAM_SHAREABLE_LEN = 0x4000;
INT_SRAM_SHAREABLE_START_ADDR = INT_SRAM_OS_START_ADDR + INT_SRAM_OS_LEN;

INT_SRAM_STACK_C0_LEN = 0x2000;
INT_SRAM_STACK_C0_START_ADDR = INT_SRAM_SHAREABLE_START_ADDR + INT_SRAM_SHAREABLE_LEN;

INT_SRAM_NO_CACHE_LEN = 0x8000;
INT_SRAM_NO_CACHE_START_ADDR = INT_SRAM_STACK_C0_START_ADDR + INT_SRAM_STACK_C0_LEN;

RSVD_START_ADDR = INT_SRAM_NO_CACHE_START_ADDR + INT_SRAM_NO_CACHE_LEN;

RSDK_SPT_CODE_LEN = 0x10000; /* 64KiB */
RSDK_SPT_CODE_ADDR = INT_SRAM_START_ADDR - RSDK_DSPHD_MSG_MEM_SIZE - RSDK_SPT_CODE_LEN;

BUFF_RAM_LEN = RSDK_SPT_CODE_ADDR - APP_RAM_START_ADDR; /* remaining space for the buffers */

ENTRY(Reset_Handler)

MEMORY 
{         
    BUFF_RAM (rw)           : ORIGIN = APP_RAM_START_ADDR, LENGTH = BUFF_RAM_LEN
    SPT_CODE (rx)           : ORIGIN = RSDK_SPT_CODE_ADDR, LENGTH = RSDK_SPT_CODE_LEN
    DSPHD_RAM (rw)          : ORIGIN = RSDK_DSPHD_MSG_BASE_ADDR, LENGTH = RSDK_DSPHD_MSG_MEM_SIZE       /* Shared mem for DSP Host Driver */ 
                                                                                                        /*!!! ATTENTION: It must not overlap with the sections defined in dsp_image_<PLATFORM>.c */    
    RFE_SW_RAM (rw)         : ORIGIN = RFE_SW_MEM_BASE_ADDRESS, LENGTH = RFE_SW_MEM_SIZE    			/* Shared mem for RFE Firmware and Driver */ 
    
    int_sram                : ORIGIN = INT_SRAM_START_ADDR, LENGTH = INT_SRAM_LEN                       /* 428KB */
    OsInternalRAM (rwx)     : ORIGIN = INT_SRAM_OS_START_ADDR,  LENGTH = INT_SRAM_OS_LEN                /* 28KiB of memory */
    int_sram_shareable      : ORIGIN = INT_SRAM_SHAREABLE_START_ADDR, LENGTH = INT_SRAM_SHAREABLE_LEN   /* 16KiB */
    
    int_sram_stack_c0       : ORIGIN = INT_SRAM_STACK_C0_START_ADDR, LENGTH = INT_SRAM_STACK_C0_LEN     /* 8KiB  */
    int_sram_no_cacheable   : ORIGIN = INT_SRAM_NO_CACHE_START_ADDR, LENGTH = INT_SRAM_NO_CACHE_LEN     /* 32KiB, needs to include int_results  */
	
    ram_rsvd2               : ORIGIN = RSVD_START_ADDR, LENGTH = 0                                      /* End of RT-SRAM */
    
}


SECTIONS
{
    
    .sram :
    {
        . = ALIGN(4);
        *(.startup) 
        . = ALIGN(4);
        *(.systeminit) 
        . = ALIGN(4);
        *(.text.startup) 
        . = ALIGN(4);
        *(.text)
        *(.text*) 
        . = ALIGN(4);
        *(.mcal_text) 
        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        KEEP(*(.fini)) 
         
        . = ALIGN(4);
        *(.rodata)  
        *(.rodata*)  
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
        *(.data*)
        . = ALIGN(4);
        *(.mcal_data)  
        . = ALIGN(16);
        __sram_bss_start = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(16);
        *(.mcal_bss)
        . = ALIGN(4);
        __sram_bss_end = .;
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
        LONG(0x0);
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

    __Stack_end_c0           = ORIGIN(int_sram_stack_c0);
    __Stack_start_c0         = ORIGIN(int_sram_stack_c0) + LENGTH(int_sram_stack_c0);

    __INT_SRAM_START         = ORIGIN(int_sram);
    __INT_SRAM_END           = ORIGIN(ram_rsvd2);
        
    __RAM_SHAREABLE_START    = ORIGIN(int_sram_shareable);
    __RAM_SHAREABLE_END      = ORIGIN(int_sram_shareable) + LENGTH(int_sram_shareable) - 1;
    __ROM_SHAREABLE_START    = __sram_shareable_rom;
    __ROM_SHAREABLE_END      = __sram_shareable_rom_end;
    __RAM_NO_CACHEABLE_START = ORIGIN(int_sram_no_cacheable);
    __RAM_NO_CACHEABLE_END   = ORIGIN(int_sram_no_cacheable) + LENGTH(int_sram_no_cacheable) - 1;
    __ROM_NO_CACHEABLE_START = 0;
    __ROM_NO_CACHEABLE_END   = 0;
    __RAM_CACHEABLE_START    = ORIGIN(int_sram);
    __RAM_CACHEABLE_END      = ORIGIN(int_sram) + LENGTH(int_sram) - 1;
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
        KEEP(*(.radar));
    } > BUFF_RAM
    
    .code_spt :
    {
        . = ALIGN(16);
        *(.RsdkSpt3*);
        . = ALIGN(8);
    } > SPT_CODE
    
    .data_dsphd :
    {
        __dspmsg = .;
        KEEP(*(.dsphd))
        *(.dsphd_jobs)
    } > DSPHD_RAM

   .data_rfesw :
    {
	    KEEP(*(.rfe_fw));
    } > RFE_SW_RAM

	/* Interrupt vectors table */
    .all :
    {
    /* Code and constant area (all code and constant sections shall be placed between .osbegincode and .osendcode sections). */
    . = ALIGN(0x80);
    *(.vector)
    . = ALIGN(0x20);
    *(.osbegincode)  /* for mem protection only */
    *(.ostext)

    *(.oshook)
    *(.osrodata)
    *(.syscall)
    *(.secinfo)
    *(.ossrodata)
    *(.sapp_c32)
    *(.sapp_c16)
    *(.sapp_cU)
    *(.sapp_c8)
    *(.appcode)
    *(.ROM.data)


    *(.osendcode)    /* for mem protection only */


    /* ------------------------------------ OS stack area ------------------------------------ */
    . = ALIGN(0x20);
    *(.osstack)

    . = ALIGN(0x20);
    *(.osstack2)

    OS_NONCACHE_BSS_START  = . ;
    . = ALIGN(0x20);
    *(.osbeginnoncache)
    *(.osnoncacheablebss)
    . = ALIGN(0x20);
    *(.osendnoncache)
    OS_NONCACHE_BSS_END    = . ;

    /* ------------------------------------ OS application data ------------------------------------ */
/* Begin of the RAM area for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */

/* Begin of the RAM area #1 for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area #1 for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */

/* Begin of the RAM area #2 for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area #2 for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */

/* Begin of the RAM area for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */

/* Begin of the RAM area #1 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area #1 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */

/* Begin of the RAM area #2 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area #2 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */




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
    *(.bss)
    *(.sbss)

    . = ALIGN(0x20);
    *(.sapp_v32_bss)
    *(.sapp_v16_bss)
    *(.sapp_vU_bss)
    *(.sapp_v8_bss)

    _bss_end = .;


    /* ------------------------------------ main stacks section ------------------------------------ */
    . = ALIGN(16);
    _Stack_end  = .;
    OS_MAIN_STACK_MIN = .;

    KEEP(*(.stack_main))

    _Stack_start = .; /* stack grows downward */
    OS_MAIN_STACK_MAX  = .;

    . = ALIGN(16);
    _Stack2_end  = .;
    OS2_MAIN_STACK_MIN = .;

    KEEP(*(.stack2_main))

    _Stack2_start = .; /* stack2 grows downward */
    OS2_MAIN_STACK_MAX  = .;

    } > OsInternalRAM
}
