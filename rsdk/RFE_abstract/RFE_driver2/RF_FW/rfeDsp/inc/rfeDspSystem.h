/**************************************************************************************************
* Copyright 2021-2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/*
 * rfeDspSystem.h
 *
 *  Created on: Mar 15, 2021
 *
 *
 */

#ifndef RFE_DSP_SYSTEM_H_
#define RFE_DSP_SYSTEM_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * Code for running on M7
 */ 
#if !defined( BUILD_FOR_PC )

/*  STRX RFE CM7 definitions */
#define __CORTEX_M                  (0x07U)    /*!< Cortex-M Core: should it be moved to building script? */

/** RFE_DSP_FPU_USED indicates whether the RFE FPU is used or not.
    For this, RFE_DSP_FPU_PRESENT has to be checked prior to making use of FPU specific registers and functions.
*/
#define RFE_DSP_FPU_PRESENT              1U    /*!< FPU present or not    */

/* CMSIS definitions required by CMSIS header */
#define __FPU_PRESENT                    1U    /*!< Needed by cmsis_armclang/gcc: should it be moved to building script? */
#define __FPU_USED                       1U    /*!< Needed by cmsis_armclang/gcc: should it be moved to building script? */

#if defined( __GNUC__ ) && defined( __clang__ )
 #define __ARM_ARCH_7M__                  1     /*!< Needed by cmsis_armclang: should it be moved to building script? */
 #define __ARM_FEATURE_DSP                1     /*!< Needed by cmsis_armclang: should it be moved to building script? */
 #include <cmsis_armclang.h>
#else
 #define __ASM            __asm                 /*!< asm keyword for GNU Compiler */
 #define __INLINE         inline                /*!< inline keyword for GNU Compiler */
 #define __STATIC_INLINE  static inline         /*!< inline keyword for GNU Compiler */
 #include <cmsis_gcc.h>
#endif

/***********************************************************************
 * M7 DSP APSR register definitions and functions
 ***********************************************************************/

/* APSR & xPSR register bits */
#define M7_APSR_N_MASK         ( 0x80000000UL )   /* Negative flag: 1, if last instruction result is negative */
#define M7_APSR_Z_MASK         ( 0x40000000UL )   /* Zero flag: 1, if last comparing instruction result is zero or equal */
#define M7_APSR_C_MASK         ( 0x20000000UL )   /* Carry/borrow flag: 1, if unsigned add/sub overflow/inverse of borrow */
#define M7_APSR_V_MASK         ( 0x10000000UL )   /* Overflow flag: 1, if overflow in signed addition or subtract */
#define M7_APSR_Q_MASK         (  0x8000000UL )   /* Saturation sticky flag: 1, if saturate, need instruction to clear */
#define M7_APSR_GE_MASK        (    0xF0000UL )   /* >= flag: set by parallel add/sub, used by SEL */

#define GET_APSR_N( apsr )       ( ( (apsr) & M7_APSR_N_MASK) >> 31U )
#define GET_APSR_Z( apsr )       ( ( (apsr) & M7_APSR_Z_MASK) >> 30U )
#define GET_APSR_C( apsr )       ( ( (apsr) & M7_APSR_C_MASK) >> 29U )
#define GET_APSR_V( apsr )       ( ( (apsr) & M7_APSR_V_MASK) >> 28U )
#define GET_APSR_Q( apsr )       ( ( (apsr) & M7_APSR_Q_MASK) >> 27U )
#define GET_APSR_GE( apsr )      ( ( (apsr) & M7_APSR_GE_MASK) >> 16U )

/**
  \brief   Set APSR register
  \details Assigns the given value to the Arithmetic Program Status Register (APSR).
  \param [in]    rAPSR  new value to be writen to the APSR register
 */
__attribute__( ( always_inline ) ) static inline void rfeDsp_setAPSR( uint32_t rAPSR )
{
  __asm volatile ("MSR apsr_nzcvq, %0" : : "r" (rAPSR));
}

/**********************************************************************
 *  Cortex-M7 FPU control register definitions
 **********************************************************************/
/* FPU control registers */
#if ( RFE_DSP_FPU_PRESENT == 1U )
 typedef struct {
  uint32_t RESERVED0[1U];
  volatile uint32_t FPCCR;                  /*!< Offset: 0x004 (R/W)  Floating-Point Context Control Register */
  volatile uint32_t FPCAR;                  /*!< Offset: 0x008 (R/W)  Floating-Point Context Address Register */
  volatile uint32_t FPDSCR;                 /*!< Offset: 0x00C (R/W)  Floating-Point Default Status Control Register */
  volatile const  uint32_t MVFR0;           /*!< Offset: 0x010 (R/ )  Media and FP Feature Register 0 */
  volatile const  uint32_t MVFR1;           /*!< Offset: 0x014 (R/ )  Media and FP Feature Register 1 */
  volatile const  uint32_t MVFR2;           /*!< Offset: 0x018 (R/ )  Media and FP Feature Register 2 */
 } rfeDspFpuCtrlRegs_t;
#endif

/**********************************************************************
 *  Memory mapping of Cortex-M7 Hardware control space and registers
 **********************************************************************/
#define RFE_DSP_CTRL_SPACE_BASE     ( 0xE000E000UL )                        /*!< System Control Space Base Address */
#define RFE_DSP_CTRL_BLK_BASE       ( RFE_DSP_CTRL_SPACE_BASE + 0x0D00UL )  /*!< System Control Block Base Address */

#if (RFE_DSP_FPU_PRESENT == 1U)
  #define RFE_DSP_FPU_BASE          ( RFE_DSP_CTRL_SPACE_BASE      + 0x0F30UL )           /*!< Floating Point Unit */
  #define FPU                       ( ( rfeDspFpuCtrlRegs_t* )RFE_DSP_FPU_BASE )          /*!< Floating Point Unit */
#endif

/***********************************************************************
 * M7 FPU control functions
 ***********************************************************************/
#if ( RFE_DSP_FPU_PRESENT == 1U )
 #define RFE_DSP_USE_FPU_INSTRUCTION
#else
 #undef RFE_DSP_USE_FPU_INSTRUCTION
#endif

#if ( RFE_DSP_FPU_PRESENT == 1U )
/* Enable FPU */
static inline void rfeDsp_enableFPU( void )
{
    /* Enable FPU */
    *( ( volatile uint32_t* )0xE000ED88UL ) |= 0xFUL << 20U ;
    __asm volatile ( "dsb 0xF" : : : "memory" );
    __asm volatile ( "isb 0xF" : : : "memory" );
}

/* Get FPU type */
static inline uint32_t rfeDsp_getFpuType( void )
{
  uint32_t mvfr0;

  mvfr0 = FPU->MVFR0;
  if ( ( mvfr0 & 0x00000FF0UL ) == 0x220UL )
  {
      mvfr0 = 2UL;           /* Double + Single precision FPU */
  }
  else if ( ( mvfr0 & 0x00000FF0UL ) == 0x020UL )
  {
      mvfr0 = 1UL;           /* Single precision FPU */
  }
  else
  {
      mvfr0 = 0UL;           /* No FPU */
  }
  return mvfr0;
}

/***********************************************************************
 * M7 FPU FPSCR register definitions and functions
 ***********************************************************************/

/* FPSCR register bits */
#define M7_FPSCR_N_MASK     (0x80000000UL)     /* Negative flag: 1, if last instruction result is negative */
#define M7_FPSCR_Z_MASK     (0x40000000UL)     /* Zero flag: 1, if last comparing instruction result is zero or equal */
#define M7_FPSCR_C_MASK     (0x20000000UL)     /* Carry/borrow flag: 1, if unsigned add/sub overflow/inverse of borrow */
#define M7_FPSCR_V_MASK     (0x10000000UL)     /* Overflow flag: 1, if overflow in signed addition or subtract */
#define M7_FPSCR_CMP_MASK   (0xF0000000UL)     /* float compare flag: , ??? */
#define M7_FPSCR_AHP_MASK   ( 0x4000000UL)     /* Half-precision flag: 0, IEEE754-2008 Half-precision format selected
                                                                       1, Alternative half-precision format selected */
#define M7_FPSCR_DN_MASK    ( 0x2000000UL)     /* Default NaN mode: 0, NaN operands propagate to output of a Float operation
                                                                    1, Any opration involving a NaN returns the default NaN */
#define M7_FPSCR_FZ_MASK    ( 0x1000000UL)     /* Flush-to-zero mode: 1, enabled */
#define M7_FPSCR_RMODE_MASK (  0xC00000UL)     /* Rounding mode: 00, Round to Nearst (RN) mode, 
                                                                 01, Round towards plus infinity (RP)
                                                                 10, Round towards minus infinity (RM)
                                                                 11, Round towards zero (RP) */
#define M7_FPSCR_IDC_MASK   (      0x80UL)     /* Input Denormal cumulative exception bit:  
                                                       1, used in FZ mode if all inputs are float denormal */
#define M7_FPSCR_IXC_MASK    (     0x10UL)     /* Inexact cumulative exception bit
                                                       1, if an operation performed with unbounded precision & expo. range */
#define M7_FPSCR_UFC_MASK    (      0x8UL)     /* Underflow cumulative exception bit
                                                       1, if abs(result) < minimum range & rounding is inexact */
#define M7_FPSCR_OFC_MASK    (      0x4UL)     /* Overflow cumulative exception bit
                                                       1, if a abs(result) > maximum of the destination precesion */
#define M7_FPSCR_DZC_MASK    (      0x2UL)     /* Division by Zero cumulative exception bit
                                                       1, if divided by zero, but divident is not 0, infinity, or NaN */
#define M7_FPSCR_IOC_MASK    (      0x1UL)     /* Invalid Operation cumulative exception bit
                                                       1, if a result has no math value/meaning, eg infinity*0, +infin+(-infin) */
#define M7_FPSCR_EXCEPT_MASK (     0x9FUL)     /* All exceptions bits */

#define GET_FPSCR_N(FPSCR)       ( ( (FPSCR) & M7_FPSCR_N_MASK ) >> 31U )
#define GET_FPSCR_Z(FPSCR)       ( ( (FPSCR) & M7_FPSCR_Z_MASK ) >> 30U )
#define GET_FPSCR_C(FPSCR)       ( ( (FPSCR) & M7_FPSCR_C_MASK ) >> 29U )
#define GET_FPSCR_V(FPSCR)       ( ( (FPSCR) & M7_FPSCR_V_MASK ) >> 28U )
#define GET_FPSCR_CMP(FPSCR)     ( ( (FPSCR) & M7_FPSCR_CMP_MASK ) >>28U )
#define GET_FPSCR_AHP(FPSCR)     ( ( (FPSCR) & M7_FPSCR_AHP_MASK ) >>27U )
#define GET_FPSCR_DN(FPSCR)      ( ( (FPSCR) & M7_FPSCR_DN_MASK ) >>27U )
#define GET_FPSCR_FZ(FPSCR)      ( ( (FPSCR) & M7_FPSCR_FZ_MASK ) >>27U )
#define GET_FPSCR_RMODE(FPSCR)   ( ( (FPSCR) & M7_FPSCR_RMODE_MASK) >>22U )
#define GET_FPSCR_IDC(FPSCR)     ( ( (FPSCR) & M7_FPSCR_IDC_MASK ) >>7U )
#define GET_FPSCR_IXC(FPSCR)     ( ( (FPSCR) & M7_FPSCR_IXC_MASK ) >>4U )
#define GET_FPSCR_UFC(FPSCR)     ( ( (FPSCR) & M7_FPSCR_UFC_MASK ) >>3U )
#define GET_FPSCR_OFC(FPSCR)     ( ( (FPSCR) & M7_FPSCR_OFC_MASK ) >>2U )
#define GET_FPSCR_DZC(FPSCR)     ( ( (FPSCR) & M7_FPSCR_DZC_MASK ) >>1U )
#define GET_FPSCR_IOC(FPSCR)     ( (FPSCR) & M7_FPSCR_IOC_MASK )
#define GET_FPSCR_EXCEPT(FPSCR)  ( (FPSCR) & M7_FPSCR_EXCEPT_MASK )

/**
  \brief   Reset all exception bits in the FPSCR register
  \details Read FPSCR register, reset all cumulative exception flags and write the value back to FPSCR register.
 */
__attribute__( ( always_inline ) ) static inline void rfeDsp_resetAllException_FPSCR( void )
{
  uint32_t curFPSCR = __get_FPSCR();
  curFPSCR &= ~( M7_FPSCR_EXCEPT_MASK );
  __set_FPSCR( curFPSCR );
}

/**
  \brief   Reset overflow bit (OFC) in the FPSCR register
  \details Read FPSCR register, reset the cumulative overflow flag (OFC) and write the value back to FPSCR register.
 */
__attribute__( ( always_inline ) ) static inline void rfeDsp_resetFPSCR_OFC( void )
{
  uint32_t curFPSCR = __get_FPSCR();
  curFPSCR &= ~( M7_FPSCR_OFC_MASK );
  __set_FPSCR( curFPSCR );
}

/**
  \brief   Reset Inexact exception bit (IXC) in the FPSCR register
  \details Read FPSCR register, reset the cumulative inexact exception flag (IXC) and write back to FPSCR register.
 */
__attribute__( ( always_inline ) ) static inline void rfeDsp_resetFPSCR_IXC( void )
{
  uint32_t curFPSCR = __get_FPSCR();
  curFPSCR &= ~( M7_FPSCR_IXC_MASK );
  __set_FPSCR( curFPSCR );
}

#endif


/**
 * Code for rfeProxy running on PC
 */ 
#else  // !defined( BUILD_FOR_PC )

#include <math.h>

#if ( RFE_DSP_FPU_PRESENT == 1U )
/* Enable FPU */
void rfeDsp_enableFPU( void )
{
    /* Enable FPU */
    #warning "No rfeDsp_enableFPU() implementation on PC!"
}

/* Get FPU type */
uint32_t rfeDsp_getFpuType( void )
{
    #warning "No rfeDsp_getFpuType() implementation on PC!"
}
#endif

#endif  // !defined( BUILD_FOR_PC )

/**
  \brief   rfeDsp_memcpy: copy a numBytes data from pSrc to pDes buffer
  \param [in]    pSrc  pointer to the source buffer
  \param [in]    numBytes  number of bytes to be copied
  \param [out]   pDes  pointer to the destination buffer
 */
static inline void rfeDsp_memcpy ( void* pDes, const void* pSrc, uint32_t numBytes )
{
  uint8_t* pOut = ( uint8_t* ) pDes;
  const uint8_t* pIn = ( const uint8_t* ) pSrc;
  for ( uint32_t u32 = 0UL; u32 < numBytes; u32++ )
  {
    pOut[u32] = pIn[u32];
  }
}

#endif /*RFE_DSP_SYSTEM_H_*/

