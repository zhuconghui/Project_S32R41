/*
 * Copyright 2021-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <string.h>

#include "Spt_Types.h"
#include "Spt_Internals.h"
#include "Spt_Hw_Check.h"
#include "Spt_Cfg.h"
#include "rsdk_version.h"






/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPT_INTERNALS_C_VENDOR_ID                     43
#define SPT_INTERNALS_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define SPT_INTERNALS_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define SPT_INTERNALS_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
#define SPT_INTERNALS_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define SPT_INTERNALS_C_SW_MINOR_VERSION              RSDK_SW_MINOR
#define SPT_INTERNALS_C_SW_PATCH_VERSION              RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check if Spt_Internals source file and Spt_Types header file are of the same vendor */
#if (SPT_INTERNALS_C_VENDOR_ID != SPT_TYPES_VENDOR_ID)
    #error "Spt_Internals.c and Spt_Types.h have different vendor ids"
#endif

/* Check if Spt_Internals source file and Spt_Types header file are of the same Autosar version */
#if ((SPT_INTERNALS_C_AR_RELEASE_MAJOR_VERSION    != SPT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_INTERNALS_C_AR_RELEASE_MINOR_VERSION    != SPT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SPT_INTERNALS_C_AR_RELEASE_REVISION_VERSION != SPT_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Internals.c and Spt_Types.h are different"
#endif

/* Check if Spt_Internals source file and Spt_Types header file are of the same Software version */
#if ((SPT_INTERNALS_C_SW_MAJOR_VERSION != SPT_TYPES_SW_MAJOR_VERSION) || \
     (SPT_INTERNALS_C_SW_MINOR_VERSION != SPT_TYPES_SW_MINOR_VERSION) || \
     (SPT_INTERNALS_C_SW_PATCH_VERSION != SPT_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Internals.c and Spt_Types.h are different"
#endif

/* Check if Spt_Internals source file and Spt_Internals header file are of the same vendor */
#if (SPT_INTERNALS_C_VENDOR_ID != SPT_INTERNALS_VENDOR_ID)
    #error "Spt_Internals.c and Spt_Internals.h have different vendor ids"
#endif

/* Check if Spt_Internals source file and Spt_Internals header file are of the same Autosar version */
#if ((SPT_INTERNALS_C_AR_RELEASE_MAJOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_INTERNALS_C_AR_RELEASE_MINOR_VERSION    != SPT_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (SPT_INTERNALS_C_AR_RELEASE_REVISION_VERSION != SPT_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Internals.c and Spt_Internals.h are different"
#endif

/* Check if Spt_Internals source file and Spt_Internals header file are of the same Software version */
#if ((SPT_INTERNALS_C_SW_MAJOR_VERSION != SPT_INTERNALS_SW_MAJOR_VERSION) || \
     (SPT_INTERNALS_C_SW_MINOR_VERSION != SPT_INTERNALS_SW_MINOR_VERSION) || \
     (SPT_INTERNALS_C_SW_PATCH_VERSION != SPT_INTERNALS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Internals.c and Spt_Internals.h are different"
#endif

/* Check if Spt_Internals source file and Spt_Hw_Check header file are of the same vendor */
#if (SPT_INTERNALS_C_VENDOR_ID != SPT_HW_CHECK_VENDOR_ID)
    #error "Spt_Internals.c and Spt_Hw_Check.h have different vendor ids"
#endif

/* Check if Spt_Internals source file and Spt_Hw_Check header file are of the same Autosar version */
#if ((SPT_INTERNALS_C_AR_RELEASE_MAJOR_VERSION    != SPT_HW_CHECK_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_INTERNALS_C_AR_RELEASE_MINOR_VERSION    != SPT_HW_CHECK_AR_RELEASE_MINOR_VERSION) || \
     (SPT_INTERNALS_C_AR_RELEASE_REVISION_VERSION != SPT_HW_CHECK_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Internals.c and Spt_Hw_Check.h are different"
#endif

/* Check if Spt_Internals source file and Spt_Hw_Check header file are of the same Software version */
#if ((SPT_INTERNALS_C_SW_MAJOR_VERSION != SPT_HW_CHECK_SW_MAJOR_VERSION) || \
     (SPT_INTERNALS_C_SW_MINOR_VERSION != SPT_HW_CHECK_SW_MINOR_VERSION) || \
     (SPT_INTERNALS_C_SW_PATCH_VERSION != SPT_HW_CHECK_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Internals.c and Spt_Hw_Check.h are different"
#endif

/* Check if Spt_Internals source file and Spt_Cfg header file are of the same vendor */
#if (SPT_INTERNALS_C_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "Spt_Internals.c and Spt_Cfg.h have different vendor ids"
#endif

/* Check if Spt_Internals source file and Spt_Cfg header file are of the same Autosar version */
#if ((SPT_INTERNALS_C_AR_RELEASE_MAJOR_VERSION    != SPT_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_INTERNALS_C_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SPT_INTERNALS_C_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Internals.c and Spt_Cfg.h are different"
#endif

/* Check if Spt_Internals source file and Spt_Cfg header file are of the same Software version */
#if ((SPT_INTERNALS_C_SW_MAJOR_VERSION != SPT_CFG_SW_MAJOR_VERSION) || \
     (SPT_INTERNALS_C_SW_MINOR_VERSION != SPT_CFG_SW_MINOR_VERSION) || \
     (SPT_INTERNALS_C_SW_PATCH_VERSION != SPT_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Internals.c and Spt_Cfg.h are different"
#endif



/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

#define SPT_START_SEC_CONST_8
#include "Spt_MemMap.h"


#if(SPT_DSP_ENABLE == STD_ON)
static const uint8 gCrcTable[256] =
{
/* CRC SAE J-1850 / 0x11d: x^8 +x^4 +x^3 +x^2 +1; Hamming distance 3 for up to 247 bits of payload
   see https://users.ece.cmu.edu/~koopman/crc/hd4.html*/
    0x00, 0x1D, 0x3A, 0x27, 0x74, 0x69, 0x4E, 0x53,
    0xE8, 0xF5, 0xD2, 0xCF, 0x9C, 0x81, 0xA6, 0xBB,
    0xCD, 0xD0, 0xF7, 0xEA, 0xB9, 0xA4, 0x83, 0x9E,
    0x25, 0x38, 0x1F, 0x02, 0x51, 0x4C, 0x6B, 0x76,
    0x87, 0x9A, 0xBD, 0xA0, 0xF3, 0xEE, 0xC9, 0xD4,
    0x6F, 0x72, 0x55, 0x48, 0x1B, 0x06, 0x21, 0x3C,
    0x4A, 0x57, 0x70, 0x6D, 0x3E, 0x23, 0x04, 0x19,
    0xA2, 0xBF, 0x98, 0x85, 0xD6, 0xCB, 0xEC, 0xF1,
    0x13, 0x0E, 0x29, 0x34, 0x67, 0x7A, 0x5D, 0x40,
    0xFB, 0xE6, 0xC1, 0xDC, 0x8F, 0x92, 0xB5, 0xA8,
    0xDE, 0xC3, 0xE4, 0xF9, 0xAA, 0xB7, 0x90, 0x8D,
    0x36, 0x2B, 0x0C, 0x11, 0x42, 0x5F, 0x78, 0x65,
    0x94, 0x89, 0xAE, 0xB3, 0xE0, 0xFD, 0xDA, 0xC7,
    0x7C, 0x61, 0x46, 0x5B, 0x08, 0x15, 0x32, 0x2F,
    0x59, 0x44, 0x63, 0x7E, 0x2D, 0x30, 0x17, 0x0A,
    0xB1, 0xAC, 0x8B, 0x96, 0xC5, 0xD8, 0xFF, 0xE2,
    0x26, 0x3B, 0x1C, 0x01, 0x52, 0x4F, 0x68, 0x75,
    0xCE, 0xD3, 0xF4, 0xE9, 0xBA, 0xA7, 0x80, 0x9D,
    0xEB, 0xF6, 0xD1, 0xCC, 0x9F, 0x82, 0xA5, 0xB8,
    0x03, 0x1E, 0x39, 0x24, 0x77, 0x6A, 0x4D, 0x50,
    0xA1, 0xBC, 0x9B, 0x86, 0xD5, 0xC8, 0xEF, 0xF2,
    0x49, 0x54, 0x73, 0x6E, 0x3D, 0x20, 0x07, 0x1A,
    0x6C, 0x71, 0x56, 0x4B, 0x18, 0x05, 0x22, 0x3F,
    0x84, 0x99, 0xBE, 0xA3, 0xF0, 0xED, 0xCA, 0xD7,
    0x35, 0x28, 0x0F, 0x12, 0x41, 0x5C, 0x7B, 0x66,
    0xDD, 0xC0, 0xE7, 0xFA, 0xA9, 0xB4, 0x93, 0x8E,
    0xF8, 0xE5, 0xC2, 0xDF, 0x8C, 0x91, 0xB6, 0xAB,
    0x10, 0x0D, 0x2A, 0x37, 0x64, 0x79, 0x5E, 0x43,
    0xB2, 0xAF, 0x88, 0x95, 0xC6, 0xDB, 0xFC, 0xE1,
    0x5A, 0x47, 0x60, 0x7D, 0x2E, 0x33, 0x14, 0x09,
    0x7F, 0x62, 0x45, 0x58, 0x0B, 0x16, 0x31, 0x2C,
    0x97, 0x8A, 0xAD, 0xB0, 0xE3, 0xFE, 0xD9, 0xC4
};

#endif /* #if(SPT_DSP_ENABLE == STD_ON) */


#define SPT_STOP_SEC_CONST_8
#include "Spt_MemMap.h"


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define SPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spt_MemMap.h"


Spt_DrvMemPerType gSptMemPer



 = {
    .state = SPT_STATE_DISABLED,









#if (SPT_SINGLE_THREAD == STD_OFF)
    .drvBusyFlag = FALSE
#endif

};


#define SPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spt_MemMap.h"


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define SPT_START_SEC_CODE
#include "Spt_MemMap.h"


/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
volatile SPT_Type *Spt_GetMemMap(void)
{
    if (gSptMemPer.isSptMemMapped == FALSE)
    {
        /* First time called: map SPT registers' physical addresses to virtual mem in user space: */

        gSptMemPer.pSptRegs = (volatile SPT_Type *)IP_SPT_BASE;



        gSptMemPer.isSptMemMapped = TRUE;
        SPT_PRINT("SPT Driver info: Spt_GetMemMap: sptBaseAddr = %lx \n", (uintptr_t)gSptMemPer.pSptRegs);
        SPT_PRINT("SPT_CUBE_BASE_ADDR = %lx\n", (uintptr_t)RSDK_SPT_CUBE_BASE_ADDR);
    }
    else
    {
        /* Return the address stored in driver's persistent memory: */
    }

    return gSptMemPer.pSptRegs;
}

Std_ReturnType Spt_UnmapMem(void)
{
    Std_ReturnType retStatus = (Std_ReturnType)E_OK;

    if (gSptMemPer.isSptMemMapped == TRUE)
    {

        gSptMemPer.isSptMemMapped = FALSE;











    }

    return retStatus;
}


void Spt_InitPersistentMem(Spt_DrvMemPerType *pSptMemPer, Spt_DriverInitType const *const pSptInitInfo)
{
    Spt_SetDrvState(SPT_STATE_DISABLED);





    pSptMemPer->kernelRetPar = NULL_PTR;
    pSptMemPer->errInfo = 0u;






    UNUSED_ARG(pSptInitInfo);


    pSptMemPer->pSptRegs = NULL_PTR;
    pSptMemPer->isSptMemMapped = 0u;






    pSptMemPer->prevOpMode = SPT_OP_MODE_BLOCK;
}

static uintptr_t Spt_GetAddrOffset(uintptr_t sysAddr)
{
    uintptr_t addrOffset = 0xFFFFFFFFU;
    uintptr_t addrOffsetTemp;








    if (sysAddr >= (uintptr_t)RSDK_SPT_OTHER_BASE_ADDR)
    {
        addrOffsetTemp = sysAddr - (uintptr_t)RSDK_SPT_OTHER_BASE_ADDR;
        if (addrOffsetTemp < addrOffset)
        {
            addrOffset = addrOffsetTemp;
        }
    }
    if (sysAddr >= (uintptr_t)RSDK_SPT_CUBE_BASE_ADDR)
    {
        addrOffsetTemp = sysAddr - (uintptr_t)RSDK_SPT_CUBE_BASE_ADDR;
        if (addrOffsetTemp < addrOffset)
        {
            addrOffset = addrOffsetTemp;
        }
    }











    return addrOffset;
}

Std_ReturnType Spt_SetInputParams(Spt_DrvParamType const paramList[])
{
    Std_ReturnType                  retStatus = (Std_ReturnType)E_OK;
    volatile SPT_Type *const        pSptRegs = Spt_GetMemMap();
    volatile Spt_WrReTagType *      wrAddrRe = (volatile Spt_WrReTagType *)((volatile void *)&pSptRegs->WR_R1_RE);
    volatile Spt_WrImTagType *      wrAddrIm = (volatile Spt_WrImTagType *)((volatile void *)&pSptRegs->WR_R1_IM);
    uintptr_t                         addrOffset;
    uint32                          i = 0;
    boolean                         parReadDone = FALSE;

    do
    {
        switch (paramList[i].paramType)
        {
            case (SPT_PARAM_TYPE_ADDR):
                SPT_HW_WRITE_REG(wrAddrRe->R, 0);
                addrOffset = Spt_GetAddrOffset(paramList[i].paramValue);

#if (SPT_DEV_ERROR_DETECT == STD_ON)
                if ((addrOffset >= SPT_MAX_MEM_OFFSET) ||
                    ((paramList[i].paramValue % SPT_DATA_ADDR_ALIGN_BYTES) != 0u))
                {
                    /* Make sure we don't pass out-of-bounds or unaligned addresses to the SPT.
                     * They are limited by the destination (SPT Work Register) to 24 bits */
                    retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_PARAM, SPT_PARAM_SET, SPT_E_INVALID_PARAM);
                }
                else
#endif /* #if (SPT_DEV_ERROR_DETECT == STD_ON) */
                {
                    SPT_HW_WRITE_REG(wrAddrIm->R, (uint32)(addrOffset & 0xFFFFFFFFu));
                }
                break;
            case (SPT_PARAM_TYPE_VALUE):
                SPT_HW_WRITE_REG(wrAddrIm->R, (uint32)((paramList[i].paramValue >> 24u) & 0xffu));
                SPT_HW_WRITE_REG(wrAddrRe->R, (uint32)(paramList[i].paramValue & 0xffffffu));
                break;
            case (SPT_PARAM_TYPE_LAST):
                parReadDone = TRUE;
                break;
            case (SPT_PARAM_TYPE_NOTINIT):
                retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_PARAM, SPT_PARAM_SET, SPT_E_INVALID_PARAM);
                break;
            default:
                retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_PARAM, SPT_PARAM_SET, SPT_E_INVALID_PARAM);
                break;
        }

        /* Increment address of spt WRs, assuming all 48 of them are identical and memory-mapped in a contiguous area */
        wrAddrRe += 2;
        wrAddrIm += 2;
        i++;
    } while ((parReadDone != TRUE) && (i < SPT_MAX_N_PAR) && (retStatus == (Std_ReturnType)E_OK));

    return retStatus;
}

void Spt_GetKernelRetVal(volatile sint32 *kernelRetPar)
{
    volatile SPT_Type *const    pSptRegs = Spt_GetMemMap();
    uint32                      wrValRe, wrValIm;

    if (kernelRetPar != NULL_PTR)
    {
        wrValRe = SPT_HW_READ_REG(pSptRegs->WR_R0_RE);
        wrValIm = SPT_HW_READ_REG(pSptRegs->WR_R0_IM);
        *kernelRetPar = (sint32)(((wrValIm & 0x000000ffu) << 24u) + (wrValRe & 0x00ffffffu));
    }
}

#if (SPT_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spt_ParamCheckKernelWatermark(uintptr_t kernelCodeAddr)
{
    Std_ReturnType retStatus = (Std_ReturnType)E_OK;






    uint32 sptKernelWatermark[] =  /* "set #0x00525300444B, WR_0". The immed value is ASCII for RSDK */
        {(uint32)(SPT_KERNEL_WATERMARK & 0xffffffffuL), ((uint32)(SPT_KERNEL_WATERMARK >> 32u) & 0xffu),
         0x00000000, 0x04000000};

    if (memcmp((uint8 *)kernelCodeAddr, (uint8 *)sptKernelWatermark, SPT_SIZEOF_INSTRUCTION_WORD) != 0)
    {
        retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_KERNEL, SPT_PARAM_CHECK, SPT_E_INVALID_KERNEL);
    }


    return retStatus;
}
#endif

Std_ReturnType Spt_ParamCheckRun(Spt_DriverContextType const *const sptContext, const Spt_DrvStateType state)
{
    Std_ReturnType retStatus = (Std_ReturnType)E_OK;

#if (SPT_DEV_ERROR_DETECT == STD_ON)
    /*---Parameter and state check: */
    if ((sptContext == NULL_PTR) || (sptContext->kernelCodeAddr == 0u))
    {
        retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_PARAM, SPT_PARAM_CHECK, SPT_E_INVALID_PARAM);
    }

    /* Check if kernel address is 8 byte aligned */
    if ((retStatus == (Std_ReturnType)E_OK) && ((sptContext->kernelCodeAddr % SPT_CODE_ADDR_ALIGN_BYTES) != 0u))
    {
        retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_PARAM, SPT_PARAM_CHECK, SPT_E_INVALID_PARAM);
    }

    /* Check if first kernel instruction matches the predefined watermark pattern
     * to make sure we have loaded valid SPT code: */
    if ((retStatus == (Std_ReturnType)E_OK) && (sptContext->checkKernelWatermark == TRUE))
    {
        retStatus = Spt_ParamCheckKernelWatermark(sptContext->kernelCodeAddr);
    }
#endif /* #if (SPT_DEV_ERROR_DETECT == STD_ON) */

    /* Check driver state */
    if (retStatus == (Std_ReturnType)E_OK)
    {
        /* Produce a separate 'warning' code if the SPT is busy processing a previous job */
        if (state == SPT_STATE_HW_BUSY)
        {
            retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_WARN_HW_BUSY, SPT_PARAM_CHECK, SPT_E_WARN_HW_BUSY);
        }
        else if (state != SPT_STATE_INITIALIZED)
        {
            retStatus = SPT_REPORT_ERROR(RSDK_SPT_RET_ERR_INVALID_STATE, SPT_PARAM_CHECK, SPT_E_INVALID_STATE);
        }
        else
        {
            /* retStatus remains (Std_ReturnType)E_OK */
        }
    }

    return retStatus;
}

#if (SPT_DEV_ERROR_DETECT == STD_ON)
Std_ReturnType Spt_ParamCheckInit(Spt_DriverInitType const *const pSptInitInfo)
{
    Std_ReturnType retStatus = (Std_ReturnType)E_OK;











    UNUSED_ARG(pSptInitInfo);


    return retStatus;
}
#endif /* #if (SPT_DEV_ERROR_DETECT == STD_ON) */

#if(SPT_DSP_ENABLE == STD_ON)
uint8 Spt_GenCrc8(const uint8* inData, uint8 numBytes)
{
    const uint8 gCrcInitVal = 0xFFU;
    const uint8 gCrcFinalXor = 0xFFU;
    uint8 i, val = gCrcInitVal;


    for (i = 0; i < numBytes; i++)
    {
        val = gCrcTable[val ^ inData[i]];
    }

    return (val ^ gCrcFinalXor);
}
#endif


#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
