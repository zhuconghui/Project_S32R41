/**************************************************************************//**
 * @file     cmsis_dcc.h
 * @brief    CMSIS compiler DIAB header file
 * @version
 * @date     25. Oct 2023
 ******************************************************************************/
/*
 * Copyright 2023 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __CMSIS_DCC_H
#define __CMSIS_DCC_H

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
  // #define __STATIC_FORCEINLINE                   __attribute__((always_inline)) static inline
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

/**
  \brief   Enable IRQ Interrupts
  \details Enables IRQ interrupts by clearing the I-bit in the CPSR.
           Can only be executed in Privileged modes.
 */
__STATIC_FORCEINLINE void __enable_irq(void)
{
   __ASM("cpsie i");
}

/**
  \brief   Disable IRQ Interrupts
  \details Disables IRQ interrupts by setting the I-bit in the CPSR.
           Can only be executed in Privileged modes.
 */
__STATIC_FORCEINLINE void __disable_irq(void)
{
  __ASM("cpsid i");
}

/**
  \brief   Instruction Synchronization Barrier
  \details Instruction Synchronization Barrier flushes the pipeline in the processor,
           so that all instructions following the ISB are fetched from cache or memory,
           after the instruction has been completed.
 */
__STATIC_FORCEINLINE void __ISB(void)
{
  __ASM ("dsb 0xF");
}

/**
  \brief   Data Synchronization Barrier
  \details Acts as a special kind of Data Memory Barrier.
           It completes when all explicit memory accesses before this instruction complete.
 */
__STATIC_FORCEINLINE void __DSB(void)
{
   __ASM ("dsb 0xF");
}

#ifdef __cplusplus
}
#endif

#endif /* __CMSIS_DCC_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/