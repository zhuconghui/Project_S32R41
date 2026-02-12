/*
 * Copyright 2017-2021, 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef RSDK_SPT_KERNELS_API_H
#define RSDK_SPT_KERNELS_API_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_toolchain_helper.h"




#include "rsdk_spt_kernels_s32r41.h"






/**
* \addtogroup spt_kernels_api_const
* @{
*/
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* NA */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* clang-format off */
/**
* @brief          Return SPT program code sizes in BYTES.
* @details        Used for relocation to SRAM. Use it in a .c file like: memcpy(gSptModuleCodeRelocBuf, 
*                 (void*)sptKernelLoadAddr, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptInit512smp128crp4ch));
*/
#define RSDK_SPT_GET_KERNEL_SIZE(kernelName) ((size_t)&kernelName##_size)

/**
* @brief          Number of chirp buffers to be allocated in SRAM.
* @details        The SPT modules can be used only when The number of chirp buffers in SRAM used
*                 in the radar application is equal to this values.
*/
#define RSDK_SPT_DOUBLE_BUFFER          (2)

/**
* @brief          Packing of peak detects.
* @details        Peak search output is bitmap - 8 detect tags per byte.
*/
#define RSDK_SPT_PEAK_BITMAP_PACK_SIZE(x) (x>>3)

/**
* @brief          Number of SPT histogram bins.
* @details        Number of SPT histogram bins.
*/
#define RSDK_SPT_HIST_BINS              (64)

/**
* @brief          <br><br> <b>Tag value for DOA detect:</b>
* @details        Beamforming output is tag/magnitude per each beam.
*/
/** @{  */
#define RSDK_SPT_DOA_TAG                (0xFF80)
/** @} */

/**
* @brief          Number of beams used for DBF and DOA.
* @details        Number of beams used for Digital Beamforming and Direction of Arrival.
*/
#define RSDK_SPT_DBFDOA_BEAMS_NUM       (64)

/**
* @brief          Number of peaks used for DBF and DOA.
* @details        Number of peaks used for Digital Beamforming and Direction of Arrival.
*/
#define RSDK_SPT_DBFDOA_PEAKS_NUM       (128)

/**
* @brief          <br><br> <b>Number of peaks used for DBF with FFT:</b>
* @details        Number of peaks used for Digital Beamforming with FFT.
*/
/** @{ */
#define RSDK_SPT_DBFFFT_PEAKS_NUM       (128)
/** @} */

/*! \name
* @brief          <br><br> <b>Number of points for the range FFT:</b>
* @details        The SPT modules can be used only when The number of samples per chirp used
*                 in the radar application is equal to one of these values.
*/
/** @{ */
#define RSDK_SPT_NP_RANGE2048           (2048)
#define RSDK_SPT_NP_RANGE1024           (1024)
#define RSDK_SPT_NP_RANGE512             (512)
#define RSDK_SPT_NP_RANGE256             (256)
/** @} */

/**
* @brief          A data layout gap in ADC chirp data to accomodate the MIPICSI2 statistics (measured in bytes).
* @details        Each chirp is followed by 80B of MIPI/CSI2 statistics. Buffer size considers double buffering and int16 values.
*/
#define RSDK_BYTES_CSI2_STATS             (80)
#define RSDK_CSI2_STATS_DOUBLE_BUFFER     ((RSDK_BYTES_CSI2_STATS*RSDK_SPT_DOUBLE_BUFFER)>>1)

/**
* @brief          <br><br> <b>Number of points for the Doppler FFT:</b>
* @details        The SPT modules can be used only when the number of chirps per acquisition frame used
*                 in the radar application is equal to one of these values.
*/
/** @{ */
#define RSDK_SPT_NP_DOPPLER512          (512)
#define RSDK_SPT_NP_DOPPLER256          (256)
#define RSDK_SPT_NP_DOPPLER128          (128)
#define RSDK_SPT_NP_DOPPLER64            (64)
/**  @} */

/**
* @brief          <br><br> <b>Number of points for the RFBist FFT:</b>
* @details        The SPT modules can be used only when The number of samples per chirp used
*                 in the radar application is equal to one of these values.
*/
/** @{ */
#define RSDK_SPT_NP_RFBIST128            (128)
#define RSDK_SPT_NP_RFBIST2048          (2048)
/** @} */

/**
* @brief          <br><br> <b>Number of points for the DBF FFT:</b>
* @details        FFT length for the Digital Beamforming.
*/
/** @{ */
#define RSDK_SPT_NP_DBF128              (128)
#define RSDK_SPT_NP_DBF512              (512)
/** @} */




/**
* @brief          <br><br> <b>Compute the number of loops for the RsdkSptOsCfar kernel</b>
* @details        1 ORAM bank (8192) operands processed each loop with a total number of rangeBins * dopplerBins operands
*/
//! @{ 
#define RSDK_SPT_NUM_OF_OPERANDS_PER_BANK (8192)
#define RSDK_SPT_OSCFAR_NUM_OF_LOOPS(rangeBins, dopplerBins) ((rangeBins * dopplerBins) / RSDK_SPT_NUM_OF_OPERANDS_PER_BANK)
//! @} 

/**
* @brief          <br><br> <b>Size of the OS-CFAR input buffer in uint16 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for OS-CFAR input.
*/
//! @{
#define RSDK_SPT_OSCFAR_INPUT_BUF_SIZE(rangeBins, dopplerBins)    (rangeBins * dopplerBins)
//! @}

/**
* @brief          <br><br> <b>Size of the OS-CFAR output buffer in uint8 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for OS-CFAR output.
*/
//! @{
#define RSDK_SPT_OSCFAR_OUTPUT_BUF_SIZE(rangeBins, dopplerBins)    ((rangeBins * dopplerBins) >> 3)
//! @}



/** @} */

/**
* \addtogroup spt_kernels_api_data_type
* @{
*/
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/**
  * @anchor Anchor_RSDK_SPT_CUBE_BASE_ADDR "RSDK_SPT_CUBE_BASE_ADDR"
  */
RSDK_DECL_LNK_SYM(RSDK_SPT_CUBE_BASE_ADDR);
/**
  * @anchor Anchor_RSDK_SPT_OTHER_BASE_ADDR "RSDK_SPT_OTHER_BASE_ADDR"
  */
RSDK_DECL_LNK_SYM(RSDK_SPT_OTHER_BASE_ADDR);
/** @} */

/**
* \addtogroup spt_kernels_api_func
* @{
*/
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/* clang-format on */

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* RSDK_SPT_KERNELS_API_H */
