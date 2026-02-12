/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : SAF85xx_SAF86xx_S32R41_RTD_2_0_0_P03_D2404_ASR_REL_4_7_REV_0000_20240405
*
*   Copyright 2021 - 2024 NXP NXP
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
*   @file    Spi_Ip_Irq.c
*   @implements     Spi_Ip_Irq.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file.
*   @details Generated Post-Build(PB) configuration file.
*
*   @addtogroup SPI_IP_DRIVER Spi Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Spi_Ip.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IP_VENDOR_ID_IRQ_C                      43
#define SPI_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define SPI_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       7
#define SPI_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define SPI_IP_SW_MAJOR_VERSION_IRQ_C               2
#define SPI_IP_SW_MINOR_VERSION_IRQ_C               0
#define SPI_IP_SW_PATCH_VERSION_IRQ_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ip.h and Spi_Ip_Irq.c are of the same vendor */
#if (SPI_IP_VENDOR_ID != SPI_IP_VENDOR_ID_IRQ_C)
    #error "Spi_Ip.h and Spi_Ip_Irq.c have different vendor ids"
#endif
/* Check if Spi_Ip.h file and Spi_Ip_Irq.c file are of the same Autosar version */
#if ((SPI_IP_AR_RELEASE_MAJOR_VERSION != SPI_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C) || \
     (SPI_IP_AR_RELEASE_MINOR_VERSION != SPI_IP_AR_RELEASE_MINOR_VERSION_IRQ_C) || \
     (SPI_IP_AR_RELEASE_REVISION_VERSION != SPI_IP_AR_RELEASE_REVISION_VERSION_IRQ_C))
#error "AutoSar Version Numbers of Spi_Ip.h and Spi_Ip_Irq.c are different"
#endif
#if ((SPI_IP_SW_MAJOR_VERSION != SPI_IP_SW_MAJOR_VERSION_IRQ_C) || \
     (SPI_IP_SW_MINOR_VERSION != SPI_IP_SW_MINOR_VERSION_IRQ_C) || \
     (SPI_IP_SW_PATCH_VERSION != SPI_IP_SW_PATCH_VERSION_IRQ_C))
#error "Software Version Numbers of Spi_Ip.h and Spi_Ip_Irq.c are different"
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#ifdef SPI_IP_0_ENABLED
    #if (SPI_IP_0_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_0_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_0_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_1_ENABLED
    #if (SPI_IP_1_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_1_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_1_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_2_ENABLED
    #if (SPI_IP_2_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_2_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_2_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_3_ENABLED
    #if (SPI_IP_3_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_3_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_3_IrqDmaHandler(void);
        #endif
    #endif
#endif
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef SPI_IP_0_ENABLED
    #if (SPI_IP_0_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_0_IRQHandler)
{
    /* Calling interrupt handler for instance 0 */
    Spi_Ip_IrqHandler(0u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_0_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 0 */
    Spi_Ip_IrqDmaHandler(0u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_1_ENABLED
    #if (SPI_IP_1_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_1_IRQHandler)
{
    /* Calling interrupt handler for instance 1 */
    Spi_Ip_IrqHandler(1u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_1_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 1 */
    Spi_Ip_IrqDmaHandler(1u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_2_ENABLED
    #if (SPI_IP_2_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_2_IRQHandler)
{
    /* Calling interrupt handler for instance 2 */
    Spi_Ip_IrqHandler(2u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_2_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 2 */
    Spi_Ip_IrqDmaHandler(2u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_3_ENABLED
    #if (SPI_IP_3_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_3_IRQHandler)
{
    /* Calling interrupt handler for instance 3 */
    Spi_Ip_IrqHandler(3u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_3_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 3 */
    Spi_Ip_IrqDmaHandler(3u);
}
        #endif
    #endif
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
