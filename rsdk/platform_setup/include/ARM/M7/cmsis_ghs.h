/**************************************************************************//**
 * @file     cmsis_ghs.h
 * @brief    CMSIS compiler GHS header file
 * @version  V5.2.0
 * @date     08. May 2019
 ******************************************************************************/
/*
 * Copyright 2009-2019 Arm
 * Copyright 2020-2023 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CMSIS_GHS_H
#define __CMSIS_GHS_H

#include <arm_ghs.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \brief  BKPT_ASM
 *
 *   Macro to be used to trigger an debug interrupt
 */
#define BKPT_ASM __asm("BKPT #0\n\t")

/* CMSIS compiler specific defines */
#ifndef   __ASM
  #define __ASM                                  __asm
#endif
#ifndef   __INLINE
  #define __INLINE                               inline
#endif
#ifndef   __STATIC_INLINE
  #define __STATIC_INLINE                        static inline
#endif
#ifndef   __STATIC_FORCEINLINE
  #define __STATIC_FORCEINLINE                   __attribute__((always_inline)) static inline
#endif
#ifndef   __NO_RETURN
  #define __NO_RETURN                            __attribute__((__noreturn__))
#endif
#ifndef   __USED
  #define __USED                                 __attribute__((used))
#endif
#ifndef   __WEAK
  #define __WEAK                                 __attribute__((weak))
#endif
#ifndef   __PACKED
  #define __PACKED                               __attribute__((packed, aligned(1)))
#endif
#ifndef   __PACKED_STRUCT
  #define __PACKED_STRUCT                        struct __attribute__((packed, aligned(1)))
#endif
#ifndef   __PACKED_UNION
  #define __PACKED_UNION                         union __attribute__((packed, aligned(1)))
#endif
#ifndef   __COMPILER_BARRIER
  #define __COMPILER_BARRIER()                   __ASM volatile("":::"memory")
#endif
#ifndef __NAKED
#define __NAKED                                  __attribute__((entry_exit_history(0)))
#endif
#ifndef __RESTRICT
  #if defined(__STDC_VERSION__) && (__STDC_VERSION__>=199901L)
    #define __RESTRICT                           restrict
  #else
    #define __RESTRICT
  #endif
#endif

/* #########################  Startup and Lowlevel Init  ######################## */

#ifndef __EARLY_INIT
  /**
    \brief   Early system init: ECC, TCM etc.
    \details This default implementation initializes ECC memory sections
             relying on .ecc.table properly in the used linker script.

   */
__STATIC_FORCEINLINE void __cmsis_cpu_init(void)
{
#if defined (__ECC_PRESENT) && (__ECC_PRESENT == 1U)
  typedef struct {
    uint64_t* dest;
	uint64_t  wlen;
  } __ecc_table_t;

  extern const __ecc_table_t __ecc_table_start__;
  extern const __ecc_table_t __ecc_table_end__;

  for (__ecc_table_t const* pTable = &__ecc_table_start__; pTable < &__ecc_table_end__; ++pTable) {
    for(uint64_t i=0u; i<(pTable->wlen)>>3; ++i) {
      pTable->dest[i] = 0xDEADBEEFFEEDCAFEUL;
    }
  }
#endif
}

#define __EARLY_INIT __cmsis_cpu_init
#endif

#ifndef __PROGRAM_START

/**
  \brief   Initializes data and bss sections
  \details This default implementations initialized all data and additional bss
           sections relying on .copy.table and .zero.table specified properly
           in the used linker script.

 */
__STATIC_FORCEINLINE __NO_RETURN void __cmsis_start(void)
{
  extern int main(void) __NO_RETURN;

  typedef struct {
    uint32_t const* src;
    uint32_t* dest;
    uint32_t  wlen;
  } __copy_table_t;

  typedef struct {
    uint32_t* dest;
    uint32_t  wlen;
  } __zero_table_t;

  extern const __copy_table_t __copy_table_start__;
  extern const __copy_table_t __copy_table_end__;
  extern const __zero_table_t __zero_table_start__;
  extern const __zero_table_t __zero_table_end__;

  for (__copy_table_t const* pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable) {
    for(uint32_t i=0u; i<(pTable->wlen)>>2; ++i) {
      pTable->dest[i] = pTable->src[i];
    }
  }

  for (__zero_table_t const* pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable) {
    for(uint32_t i=0u; i<(pTable->wlen)>>2; ++i) {
      pTable->dest[i] = 0u;
    }
  }

  main();
}

#define __PROGRAM_START           __cmsis_start
#endif

#ifndef __INITIAL_SP
#define __INITIAL_SP              __StackTop
#endif

#ifndef __STACK_LIMIT
#define __STACK_LIMIT             __StackLimit
#endif

#ifndef __VECTOR_TABLE
#define __VECTOR_TABLE            __Vectors
#endif

#ifndef __VECTOR_TABLE_ATTRIBUTE
#define __VECTOR_TABLE_ATTRIBUTE  __attribute((used, section(".vectors")))
#endif

#ifndef __ECC_INIT_START
#define __ECC_INIT_START          __ecc_init_start
#endif

#ifndef __ECC_INIT_END
#define __ECC_INIT_END            __ecc_init_end
#endif

/**
  \brief   Enable IRQ Interrupts
  \details Enables IRQ interrupts by clearing the I-bit in the CPSR.
           Can only be executed in Privileged modes.
 */
__STATIC_FORCEINLINE void __enable_irq(void)
{
  __ASM volatile ("cpsie i" : : : "memory");
}


/**
  \brief   Disable IRQ Interrupts
  \details Disables IRQ interrupts by setting the I-bit in the CPSR.
           Can only be executed in Privileged modes.
 */
__STATIC_FORCEINLINE void __disable_irq(void)
{
  __ASM volatile ("cpsid i" : : : "memory");
}


/** \brief  Enable FPU
 *
 *   __FPU_USED indicates whether SystemInit will enable the Floating point unit (FPU)
 */

#if defined (__VFP__)
    #if defined (__FPU_PRESENT) && (__FPU_PRESENT == 1U)
        #define __FPU_USED       1U
    #endif
#endif

/**
  \brief   Set Main Stack Pointer
  \details Assigns the given value to the Main Stack Pointer (MSP).
  \param [in]    __INITIAL_SP  Main Stack Pointer value to set
 */

#define   __set_MSP(__INITIAL_SP) __MSR(__MSP, __INITIAL_SP)

#ifdef __cplusplus
}
#endif

#endif /* __CMSIS_GHS_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
