
/*==================================================================================================
 * Copyright 2022-2023 NXP Semiconductors
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
==================================================================================================*/








#ifndef CDD_CTE_H
#define CDD_CTE_H



#ifdef __cplusplus
extern "C"{
#endif


/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Cte_h_REF_1
* Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/

/**
*   @addtogroup cte_asr_api_const
*   @{
*/

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Cte_Cfg.h"
#include "Cte_Types.h"
#include "Cte_Irq.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

    #define CTE_VENDOR_ID                          43
    #define CTE_MODULE_ID                          255
    #define CTE_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
    #define CTE_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
    #define CTE_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
    #define CTE_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
    #define CTE_SW_MINOR_VERSION                   RSDK_SW_MINOR
    #define CTE_SW_PATCH_VERSION                   RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

    /* Check Cte_Types.h versions                                                                              */
    #if (CTE_VENDOR_ID != CTE_TYPES_VENDOR_ID)
        #error "CDD_CDD_Cte.h and Cte_Types.h have different vendor ids"
    #endif

    /* Check if Cte header file and Cte_Types configuration header file are of the same Autosar version       */
    #if ((CTE_AR_RELEASE_MAJOR_VERSION    != CTE_TYPES_AR_RELEASE_MAJOR_VERSION) ||   \
         (CTE_AR_RELEASE_MINOR_VERSION    != CTE_TYPES_AR_RELEASE_MINOR_VERSION) ||   \
         (CTE_AR_RELEASE_REVISION_VERSION != CTE_TYPES_AR_RELEASE_REVISION_VERSION)   \
        )
        #error "AutoSar Version Numbers of CDD_CDD_Cte.h and Cte_Types.h are different"
    #endif

    /* Check if Cte header file and Cte_Types configuration header file are of the same software version      */
    #if ((CTE_SW_MAJOR_VERSION    != CTE_TYPES_SW_MAJOR_VERSION) ||   \
         (CTE_SW_MINOR_VERSION    != CTE_TYPES_SW_MINOR_VERSION) ||   \
         (CTE_SW_PATCH_VERSION    != CTE_TYPES_SW_PATCH_VERSION)      \
        )
        #error "Software Version Numbers of CDD_CDD_Cte.h and Cte_Types.h are different"
    #endif

    /* Check Cte_Cfg.h versions                                                                                */
    #if (CTE_VENDOR_ID != CTE_CFG_VENDOR_ID)
        #error "CDD_Cte.h and Cte_Cfg.h have different vendor ids"
    #endif

    /* Check if Cte header file and Cte_Cfg configuration header file are of the same Autosar version         */
    #if ((CTE_AR_RELEASE_MAJOR_VERSION    != CTE_CFG_AR_RELEASE_MAJOR_VERSION) ||   \
         (CTE_AR_RELEASE_MINOR_VERSION    != CTE_CFG_AR_RELEASE_MINOR_VERSION) ||   \
         (CTE_AR_RELEASE_REVISION_VERSION != CTE_CFG_AR_RELEASE_REVISION_VERSION)   \
        )
        #error "AutoSar Version Numbers of CDD_Cte.h and Cte_Cfg.h are different"
    #endif

    /* Check if Cte header file and Cte_Cfg configuration header file are of the same software version        */
    #if ((CTE_SW_MAJOR_VERSION    != CTE_CFG_SW_MAJOR_VERSION) ||     \
         (CTE_SW_MINOR_VERSION    != CTE_CFG_SW_MINOR_VERSION) ||     \
         (CTE_SW_PATCH_VERSION    != CTE_CFG_SW_PATCH_VERSION)        \
        )
        #error "Software Version Numbers of CDD_Cte.h and Cte_Cfg.h are different"
    #endif

    /* Check Cte_Irq.h versions                                                                              */
    #if (CTE_VENDOR_ID != CTE_IRQ_VENDOR_ID)
        #error "CDD_Cte.h and Cte_Irq.h have different vendor ids"
    #endif

    /* Check if Cte header file and Cte_Irq configuration header file are of the same Autosar version       */
    #if ((CTE_AR_RELEASE_MAJOR_VERSION    != CTE_IRQ_AR_RELEASE_MAJOR_VERSION) ||   \
         (CTE_AR_RELEASE_MINOR_VERSION    != CTE_IRQ_AR_RELEASE_MINOR_VERSION) ||   \
         (CTE_AR_RELEASE_REVISION_VERSION != CTE_IRQ_AR_RELEASE_REVISION_VERSION)   \
        )
        #error "AutoSar Version Numbers of CDD_Cte.h and Cte_Irq.h are different"
    #endif

    /* Check if Cte header file and Cte_Irq configuration header file are of the same software version      */
    #if ((CTE_SW_MAJOR_VERSION    != CTE_IRQ_SW_MAJOR_VERSION) ||   \
         (CTE_SW_MINOR_VERSION    != CTE_IRQ_SW_MINOR_VERSION) ||   \
         (CTE_SW_PATCH_VERSION    != CTE_IRQ_SW_PATCH_VERSION)      \
        )
        #error "Software Version Numbers of CDD_Cte.h and Cte_Irq.h are different"
    #endif



/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*
* @brief Development error codes (passed to DET).
*/

    /**
    * @brief API request called with an invalid parameter (Nullpointer).
    * */
    #define CTE_E_PARAM_POINTER                ((uint8)0x01U)

    /**
    * @brief API request called with invalid parameter (invalid value).
    * */
    #define CTE_E_PARAM_VALUE                  ((uint8)0x02U)

    /**
    * @brief API request called with invalid parameter (out of range).
    * */
    #define CTE_E_PARAM_HANDLE                 ((uint8)0x03U)

    /**
    * @brief Setup of Cte Driver failed.
    * */
    #define CTE_E_SETUP_FAILED                 ((uint8)0x04U)

    /**
    * @brief Incorrect driver status.
    * */
    #define CTE_E_WRONG_STATE                  ((uint8)0x05U)

    /**
    * @brief Hardware error.
    * */
    #define CTE_E_HW_ERROR                     ((uint8)0x06U)

/** @} */

/* update a MIPI-CTE 32 bits registry                              */
#define CTE_SET_REGISTRY32(registryPtr, alignedMask, alignedValue) \
                *(registryPtr) = (((*(registryPtr)) & (~((uint32)alignedMask))) | ((uint32)alignedValue))

/* update a MIPI-CTE 32 bits registry                              */
#define CTE_GET_REGISTRY32(registryPtr, alignedMask, shiftValue) \
                (((*(registryPtr)) & (((uint32)alignedMask))) >> ((uint32)shiftValue))


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

    #define CTE_START_SEC_CODE
    /*
    * @section Cte_h_REF_1
    * Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
    * <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
    */
    #include "Cte_MemMap.h"


#if (CTE_VERSION_INFO_API == STD_ON)
/**
 * @brief       The function returns the version info for the module.
 * @details     The function returns the version info for the module.
 *
 * @param[in]   versionInfoPtr  - pointer to a version structure to receive the data
 *
 * @pre         It can be called when the reception need to be stopped. The unit must be in INITIALIZED state.
 *
 */
void Cte_GetVersionInfo(Std_VersionInfoType* versionInfoPtr);
#endif



/**
*   @addtogroup cte_asr_api_func
*   @{
*/

/**
 * @brief   Initialization procedure for CTE driver
 * @details After initialization the CTE is not started, a specific Cte_Start call must be used for this.
 *          The operation can be done at any moment; if the CTE is working, it will be stopped.
 *
 * @param[in]   cteInitParamsPtr    = pointer to the initialization structure
 * @param[in]   lutChecksumPtr      = pointer to a uint64 value, which will receive the final LUT checksum;
 *                                  this value can be checked later using Cte_GetLutChecksum
 * @return      E_OK/RSDK_SUCCESS = initialization succeeded
 * @return      other values      = initialization failed, use the appropriate tools to detect the issue
 *
 */
Std_ReturnType Cte_Setup(const Cte_SetupParamsType *cteInitParamsPtr, uint64 *lutChecksumPtr);

/**
 * @brief   Start procedure for CTE
 * @details After this call the CTE will start to work, if successful.
 *          The procedure could be unsuccessful only if the driver was not initialized before. 
 *          The exit status can be different than E_OK/RSDK_SUCCESS; if the unit is running, the return is not OK
 *          but it is only a warning, signaling the CTE was already working and this was not interrupt.
 *          Start after a Stop will use the initialization done before.
 * 
 * @return  E_OK/RSDK_SUCCESS = start succeeded
 * @return  other values      = start failed, use the appropriate tools to detect the issue
 *
 */
Std_ReturnType Cte_Start(void);

/**
 * @brief   Stop procedure for CTE
 * @details After this call the CTE will stop to work, if successful.
 *          The procedure could be unsuccessful only if the driver is not working at the call time.
 * 
 * @return  E_OK/RSDK_SUCCESS = stop succeeded
 * @return  other values      = stop failed, use the appropriate tools to detect the issue
 *
 */
Std_ReturnType Cte_Stop(void);

/**
 * @brief   Restart CTE.
 * @details This procedure is a single call for Cte_Stop and a Cte_Start.
 *
 * @return  E_OK/RSDK_SUCCESS = restart succeeded
 * @return  other values      = restart failed, use the appropriate tools to detect the issue
 *
 */
Std_ReturnType Cte_Restart(void);

/**
 * @brief   Generate a RFS software signal.
 * @details The procedure can be used only in Slave mode, to reset the time table execution.
 *          The real CTE execution must be triggered by a RCS signal.
 *
 * @return  E_OK/RSDK_SUCCESS = call succeeded
 * @return  other values      = call failed, use the appropriate tools to detect the issue
 *
 */
Std_ReturnType Cte_RfsGenerate(void);

/**
 * @brief   Procedure to update only the existing timing tables.
 * @details The procedure can be used only after a previous successful CTE initialization.
 *          If the CTE is working, it will be stopped and restarted after table changed.
 *          If stopped, it will remains in the same state. It is recommendable to do like this.
 *
 * @param[in]   table0Ptr, table1Ptr    = pointer to the new table(s); first pointer must not be NULL;
                                          if second is NULL, only one table used, else two tables used
 * @param[in]   lutChecksumPtr          = pointer to a uint64 value, which will receive the final LUT checksum;
 *                                        this value can be checked later using Cte_GetLutChecksum
 * @return  E_OK/RSDK_SUCCESS           = initialization succeeded
 * @return  other values                = initialization failed, use the appropriate tools to detect the issue
 *
 */
Std_ReturnType Cte_UpdateTables(Cte_TimeTableDefType *table0Ptr, Cte_TimeTableDefType *table1Ptr,
        uint64 *lutChecksumPtr);

/**
 * @brief   Get the checksum of the timing LUT.
 * @details This procedure returns the current checksum reported by the hardware, only 40 bits.
 *          The value can be compared to the previous values.
 *
 * @return  LUT checksum
 *
 */
uint64 Cte_GetLutChecksum(void);

/** @} */


    #define CTE_STOP_SEC_CODE
    /*
    * @section Cte_h_REF_1
    * Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
    * <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
    */
    #include "Cte_MemMap.h"



#ifdef __cplusplus
}
#endif

#endif /* CDD_CTE_H */
