/*
 * Copyright 2018-2021, 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */
/*==================================================================================================
 *                                        INCLUDE FILES
 *==================================================================================================*/

/*==================================================================================================
 *                                          SECTION
 *==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL REFERENCES
 *==================================================================================================*/
.extern RSDK_SPT_OTHER_BASE_ADDR   /* Heap buffers start address */
.extern RSDK_SPT_CUBE_BASE_ADDR    /* Radar Cube buffer start address */

.ifdef S32R45
 .extern RSDK_SPT_CBRAM_BASE_ADDR  /* Chirp buffer RAM start address */
.endif

/*==================================================================================================
 *                                         CONSTANTS
 *==================================================================================================*/
.ifdef S32R45
 .set MEM_SLICES,                  (16)                                 /* Number of OPRAM/TRAM slices: 16 */
 .set TRAM_COL_NO,                 (256)                                /* Number of TRAM columns: 256 */
 .set TRAM_BANK_SIZE,              (TRAM_COL_NO * MEM_SLICES)           /* Max size of TRAM bank: columns(256) x slices(16) */
 .set OPRAM_BANK_SIZE,             (0)                                  /* Max size of OPRAM bank: columns(512) x slices(16) */
.else /* S32R41, SAF85XX */
 .set MEM_SLICES,                  (8)                                  /* Number of OPRAM/TRAM slices: 8 */
 .set TRAM_COL_NO,                 (512)                                /* Number of TRAM columns: 512 */
 .set OPRAM_COL_NO,                (512)                                /* Number of OPRAM columns: 512 */
 .set TRAM_BANK_SIZE,              (TRAM_COL_NO * MEM_SLICES)           /* Max size of TRAM bank: columns(512) x slices(8) */
 .set OPRAM_BANK_SIZE,             (OPRAM_COL_NO * MEM_SLICES)          /* Max size of OPRAM bank: columns(512) x slices(8) */
.endif

 .set FFT2048_TWIDDLES_NO,         (256)                                /* 256 unique 32bit(16Im + 16Re) twiddles for FFT2048 */
 .set FFT2048_TRAM_TWIDDLE_NO,     (FFT2048_TWIDDLES_NO * MEM_SLICES)   /* TRAM slices, 32bit(16Im + 16Re) per twiddle */
 .set FFT2048_TWIDDLE_SRAM_SLICES, (FFT2048_TRAM_TWIDDLE_NO >> 1)       /* SRAM slices(64bit/slice), used by PDMA */

 .set FFT1024_TWIDDLES_NO,         (128)                                /* 128 unique 32bit(16Im + 16Re) twiddles for FFT1024 */
 .set FFT1024_TRAM_TWIDDLE_NO,     (FFT1024_TWIDDLES_NO * MEM_SLICES)   /* TRAM slices, 32bit(16Im + 16Re) per twiddle */
 .set FFT1024_TWIDDLE_SRAM_SLICES, (FFT1024_TRAM_TWIDDLE_NO >> 1)       /* SRAM slices(64bit/slice), used by PDMA */

 .set FFT512_TWIDDLES_NO,          (64)                                 /* 64 unique 32bit(16Im + 16Re) twiddles for FFT512 */
 .set FFT512_TRAM_TWIDDLE_NO,      (FFT512_TWIDDLES_NO * MEM_SLICES)    /* TRAM slices, 32bit(16Im + 16Re) per twiddle */
 .set FFT512_TWIDDLE_SRAM_SLICES,  (FFT512_TRAM_TWIDDLE_NO >> 1)        /* SRAM slices(64bit/slice), used by PDMA */

 .set FFT256_TWIDDLES_NO,          (32)                                 /* 32 unique 32bit(16Im + 16Re) twiddles for FFT256 */
 .set FFT256_TRAM_TWIDDLE_NO,      (FFT256_TWIDDLES_NO * MEM_SLICES)    /* TRAM slices, 32bit(16Im + 16Re) per twiddle */
 .set FFT256_TWIDDLE_SRAM_SLICES,  (FFT256_TRAM_TWIDDLE_NO >> 1)        /* SRAM slices(64bit/slice), used by PDMA */

 .set FFT128_TWIDDLES_NO,          (16)                                 /* 16 unique 32bit(16Im + 16Re) twiddles for FFT128 */
 .set FFT128_TRAM_TWIDDLE_NO,      (FFT128_TWIDDLES_NO * MEM_SLICES)    /* TRAM slices, 32bit(16Im + 16Re) per twiddle */
 .set FFT128_TWIDDLE_SRAM_SLICES,  (FFT128_TRAM_TWIDDLE_NO >> 1)        /* SRAM slices(64bit/slice), used by PDMA */

 .set FFT64_TWIDDLES_NO,           (8)                                  /* 8 unique 32bit(16Im + 16Re) twiddles for FFT64 */
 .set FFT64_TRAM_TWIDDLE_NO,       (FFT64_TWIDDLES_NO * MEM_SLICES)     /* TRAM slices, 32bit(16Im + 16Re) per twiddle */
 .set FFT64_TWIDDLE_SRAM_SLICES,   (FFT64_TRAM_TWIDDLE_NO >> 1)         /* SRAM slices(64bit/slice), used by PDMA */

 .set FFT32_TWIDDLES_NO,           (4)                                  /* 4 unique 32bit(16Im + 16Re) twiddles for FFT32 */
 .set FFT32_TRAM_TWIDDLE_NO,       (FFT32_TWIDDLES_NO * MEM_SLICES)     /* TRAM slices, 32bit(16Im + 16Re) per twiddle */
 .set FFT32_TWIDDLE_SRAM_SLICES,   (FFT32_TRAM_TWIDDLE_NO >> 1)         /* SRAM slices(64bit/slice), used by PDMA */

 .set FFT16_TWIDDLES_NO,           (2)                                  /* 2 unique 32bit(16Im + 16Re) twiddles for FFT16 */
 .set FFT16_TRAM_TWIDDLE_NO,       (FFT16_TWIDDLES_NO * MEM_SLICES)     /* TRAM slices, 32bit(16Im + 16Re) per twiddle */
 .set FFT16_TWIDDLE_SRAM_SLICES,   (FFT16_TRAM_TWIDDLE_NO >> 1)         /* SRAM slices(64bit/slice), used by PDMA */

 .set FFT2048_WIN_NO,              (2048)                               /* Number of window 16bit real coef */
 .set FFT1024_WIN_NO,              (1024)                               /* Number of window 16bit real coef */
 .set FFT512_WIN_NO,               (512)                                /* Number of window 16bit real coef */
 .set FFT256_WIN_NO,               (256)                                /* Number of window 16bit real coef */
 .set FFT128_WIN_NO,               (128)                                /* Number of window 16bit real coef */
 .set FFT64_WIN_NO,                (64)                                 /* Number of window 16bit real coef */

 .set FFT2048_WIN_SRAM_SLICES,     (FFT2048_WIN_NO >> 2)                /* SRAM slices(64bit/slice), used by PDMA */
 .set FFT1024_WIN_SRAM_SLICES,     (FFT1024_WIN_NO >> 2)                /* SRAM slices(64bit/slice), used by PDMA */
 .set FFT512_WIN_SRAM_SLICES,      (FFT512_WIN_NO >> 2)                 /* SRAM slices(64bit/slice), used by PDMA */
 .set FFT256_WIN_SRAM_SLICES,      (FFT256_WIN_NO >> 2)                 /* SRAM slices(64bit/slice), used by PDMA */
 .set FFT128_WIN_SRAM_SLICES,      (FFT128_WIN_NO >> 2)                 /* SRAM slices(64bit/slice), used by PDMA */
 .set FFT64_WIN_SRAM_SLICES,       (FFT64_WIN_NO >> 2)                  /* SRAM slices(64bit/slice), used by PDMA */

 .set DEROT_VECT64_NO,             (64)                                 /* Number of derotation coef */
 .set DEROT_VECT128_NO,            (128)                                /* Number of derotation coef */
 .set DEROT_VECT256_NO,            (256)                                /* Number of derotation coef */
 .set DEROT_VECT64_SRAM_SLICES,    (DEROT_VECT64_NO >> 1)               /* SRAM slices(64bit/slice), used by PDMA */
 .set DEROT_VECT128_SRAM_SLICES,   (DEROT_VECT128_NO >> 1)              /* SRAM slices(64bit/slice), used by PDMA */
 .set DEROT_VECT256_SRAM_SLICES,   (DEROT_VECT256_NO >> 1)              /* SRAM slices(64bit/slice), used by PDMA */

 .set DBF_4CH_NO,                  (4)                                  /* Number of Beamforming channels */
 .set DBF_8CH_NO,                  (8)                                  /* Number of Beamforming channels */
 .set DBF_12CH_NO,                 (12)                                 /* Number of Beamforming channels */
 .set DBF_16CH_NO,                 (16)                                 /* Number of Beamforming channels */
 .set DBF_BEAMS_NO,                (64)                                 /* Number of Beams */
 .set DBF64_4CH_NO,                (DBF_BEAMS_NO * DBF_4CH_NO)          /* Number of steering coef */
 .set DBF64_8CH_NO,                (DBF_BEAMS_NO * DBF_8CH_NO)          /* Number of steering coef */
 .set DBF64_12CH_NO,               (DBF_BEAMS_NO * DBF_12CH_NO)         /* Number of steering coef */
 .set DBF64_16CH_NO,               (DBF_BEAMS_NO * DBF_16CH_NO)         /* Number of steering coef */
 .set DBF64_4CH_SRAM_SLICES,       (DBF64_4CH_NO  >> 1)                 /* SRAM slices(64bit/slice), used by PDMA */
 .set DBF64_8CH_SRAM_SLICES,       (DBF64_8CH_NO  >> 1)                 /* SRAM slices(64bit/slice), used by PDMA */
 .set DBF64_12CH_SRAM_SLICES,      (DBF64_12CH_NO >> 1)                 /* SRAM slices(64bit/slice), used by PDMA */
 .set DBF64_16CH_SRAM_SLICES,      (DBF64_16CH_NO >> 1)                 /* SRAM slices(64bit/slice), used by PDMA */

 .set BYTES_CSI2_STATS,            (80)                                 /* Number of bytes for CSI2 stats, to be skipped in range kernels */

.ifdef S32R45
// memory mapping controller selection for read and write
// MEMMAP_CTRL_RxWy means read from controller x, write to controller y
 .set MEMMAP_CTRL_R0W0,            (0)
 .set MEMMAP_CTRL_R0W1,            (4)
 .set MEMMAP_CTRL_R0W2,            (8)
 .set MEMMAP_CTRL_R0W3,            (12)
 .set MEMMAP_CTRL_R1W0,            (1)
 .set MEMMAP_CTRL_R1W1,            (5)
 .set MEMMAP_CTRL_R1W2,            (9)
 .set MEMMAP_CTRL_R1W3,            (13)
 .set MEMMAP_CTRL_R2W0,            (2)
 .set MEMMAP_CTRL_R2W1,            (6)
 .set MEMMAP_CTRL_R2W2,            (10)
 .set MEMMAP_CTRL_R2W3,            (14)
 .set MEMMAP_CTRL_R3W0,            (3)
 .set MEMMAP_CTRL_R3W1,            (7)
 .set MEMMAP_CTRL_R3W2,            (11)
 .set MEMMAP_CTRL_R3W3,            (15)
// memory mapping command sequencer names for mem mapping SPRs
 .set MEMMAP_SPR_MCS,              (0x1000)
 .set MEMMAP_SPR_SCS0,             (0x1001)
 .set MEMMAP_SPR_SCS1,             (0x1002)
 .set MEMMAP_SPR_SCS2,             (0x1003)
 .set MEMMAP_SPR_SCS3,             (0x1004)
 .endif

.ifdef S32R45
 .set MIPI0_LINE_DONE0,            (0x08)                               /* MIPI0 signal LineDone[0] */
 .set MIPI1_LINE_DONE0,            (0x1C)                               /* MIPI1 signal LineDone[0] */
 .set MIPI2_LINE_DONE0,            (0x30)                               /* MIPI2 signal LineDone[0] */
 .set MIPI3_LINE_DONE0,            (0x44)                               /* MIPI3 signal LineDone[0] */
 .set MIPI_EVENT_LINE,             (MIPI1_LINE_DONE0)                   /* using MIPI1 signal LineDone[0] */
.else
.ifdef S32R41
 .set MIPI0_LINE_DONE0,            (0x1C)                               /* MIPI0 signal LineDone[0] */
 .set MIPI1_LINE_DONE0,            (0x08)                               /* MIPI1 signal LineDone[0] */
 .set MIPI_EVENT_LINE,             (MIPI0_LINE_DONE0)                   /* using MIPI1 signal LineDone[0] */
.else /*SAF85XX*/
 .set MIPI0_LINE_DONE0,            (0x1C)                               /* MIPI0 signal LineDone[0] */
 .set MIPI1_LINE_DONE0,            (0x08)                               /* MIPI1 signal LineDone[0] */
 .set MIPI_EVENT_LINE,             (MIPI1_LINE_DONE0)                   /* using MIPI1 signal LineDone[0] */
.endif
.endif

 .set RSDK_SPT_KERNEL_WATERMARK,   (0x00005253444B)                     /* Ascii for 'RSDK' */

/*******************************************************************************
 * EOF
 ******************************************************************************/
