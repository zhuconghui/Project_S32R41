
/*
 * Copyright 2017-2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */









#ifndef CDD_SPT_H
#define CDD_SPT_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Spt_Types.h"
#include "Spt_Cfg.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_SPT_VENDOR_ID                          43
#define CDD_SPT_MODULE_ID                          4024
#define CDD_SPT_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define CDD_SPT_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define CDD_SPT_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define CDD_SPT_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define CDD_SPT_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define CDD_SPT_SW_PATCH_VERSION                   RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check Spt_Types.h versions                                                                              */
#if (CDD_SPT_VENDOR_ID != SPT_TYPES_VENDOR_ID)
    #error "CDD_Spt.h and Spt_Types.h have different vendor ids"
#endif

/* Check if CDD_Spt header file and Spt_Types header file are of the same Autosar version       */
#if ((CDD_SPT_AR_RELEASE_MAJOR_VERSION   != SPT_TYPES_AR_RELEASE_MAJOR_VERSION) ||   \
    (CDD_SPT_AR_RELEASE_MINOR_VERSION    != SPT_TYPES_AR_RELEASE_MINOR_VERSION) ||   \
    (CDD_SPT_AR_RELEASE_REVISION_VERSION != SPT_TYPES_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of CDD_Spt.h and Spt_Types.h are different"
#endif

/* Check if CDD_Spt header file and Spt_Types header file are of the same software version      */
#if ((CDD_SPT_SW_MAJOR_VERSION   != SPT_TYPES_SW_MAJOR_VERSION) ||   \
    (CDD_SPT_SW_MINOR_VERSION    != SPT_TYPES_SW_MINOR_VERSION) ||   \
    (CDD_SPT_SW_PATCH_VERSION    != SPT_TYPES_SW_PATCH_VERSION)      \
    )
    #error "Software Version Numbers of CDD_Spt.h and Spt_Types.h are different"
#endif

/* Check Spt_Cfg.h versions                                                                                */
#if (CDD_SPT_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "CDD_Spt.h and Spt_Cfg.h have different vendor ids"
#endif

/* Check if CDD_Spt header file and Spt_Cfg configuration header file are of the same Autosar version         */
#if ((CDD_SPT_AR_RELEASE_MAJOR_VERSION   != SPT_CFG_AR_RELEASE_MAJOR_VERSION) ||   \
    (CDD_SPT_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) ||   \
    (CDD_SPT_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of CDD_Spt.h and Spt_Cfg.h are different"
#endif

/* Check if CDD_Spt header file and Spt_Cfg configuration header file are of the same software version        */
#if ((CDD_SPT_SW_MAJOR_VERSION   != SPT_CFG_SW_MAJOR_VERSION) ||     \
    (CDD_SPT_SW_MINOR_VERSION    != SPT_CFG_SW_MINOR_VERSION) ||     \
    (CDD_SPT_SW_PATCH_VERSION    != SPT_CFG_SW_PATCH_VERSION)        \
    )
    #error "Software Version Numbers of CDD_Spt.h and Spt_Cfg.h are different"
#endif



/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/** @addtogroup spt_driver_api_const
* @{
*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*
* @brief   SPT interrupt IDs in NVIC (to be registered by the application)
* */
#define SPT_INTC_OFFSET_DSP_ERR     (188)
#define SPT_INTC_OFFSET_EVT1        (189)
#define SPT_INTC_OFFSET_ECS         (190)
#define SPT_INTC_OFFSET_DMA         (191)



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

/** @}*/

/** * @addtogroup spt_driver_api_func
* @{
*/


#define SPT_START_SEC_CODE
#include "Spt_MemMap.h"


/**
* @brief        This function initializes the internal state of the SPT Driver and the hardware registers of the SPT
*               in preparation for running SPT kernel functions.
* @details      It checks the validity of the input arguments, then writes them into the SPT registers.
*               It does not modify the input argument.
*               It also enables boot-up of the BBE32 DSP, if Spt_DriverInitType::dspEn is not set to 0.
*
* @param[in]    pSptInitInfo - pointer to the SPT Driver initialization structure.
*
* @return       success or error status information.
*
* @pre          It must be called in the following situations:
*               <ul>
*                   <li>during the first setup of the SPT Driver (e.g. after boot),
*                   <li>whenever the system parameters described in Spt_DriverInitType need to be changed
*                   <li>everytime the Spt_Run() returns an SPT hardware error
*               </ul>
*
*/
Std_ReturnType Spt_Setup(Spt_DriverInitType const *const pSptInitInfo);

/**
* @brief        Configures the SPT kernel parameters, triggers SPT execution, feeds back status information to the caller.
* @details      It checks the validity of the input arguments, then parses the SPT Spt_DriverContextType::kernelParList,
*               writes the parameters into the SPT working registers (see @ref spt_call_conv), starts the SPT,
*               then it either waits for SPT completion (blocking mode) or exits immediately (non-blocking mode).
*               See also the @ref spt_rm_running for details.
*
* @param[in]    sptContext - pointer to the SPT runtime parameters structure
*
* @return       success or error status information.
*
* @pre          It must be called only after Spt_Setup() has been executed successfully at least once.
*               If the SPT signals a hardware error (through the Spt_DriverContextType::ecsIsrCb ),
*               then it is recommended to re-run Spt_Setup() before calling Spt_Run()
*/
Std_ReturnType Spt_Run(Spt_DriverContextType const *const sptContext);

/**
* @brief        Used to handle asynchronous control or status requests, apart from the SPT kernel processing sequence.
* @details      See Spt_DriverCommandIdType for details about the supported commands.
*
* @param[in]    pSptCommand - pointer to a structure containing the ID of the command to be served and additional parameters that may be needed.
*
* @param[out]    pSptCmdResult - container for the returned information.
*
* @return       success or error status information.
*
* @pre          It must be called only after Spt_Setup() has been executed successfully at least once.
*               If the SPT signals a hardware error (through the Spt_DriverContextType::ecsIsrCb ),
*               then it is recommended to re-run Spt_Setup() before calling Spt_Command().
*/
Std_ReturnType Spt_Command(Spt_DriverCommandType const *const pSptCommand, Spt_DriverCmdResType *const pSptCmdResult);

/**
* @brief        This function stops the SPT processing, brings the hardware and the Driver back into reset state,
*               ready for a new initialization.
* @details      It checks the validity of the input arguments, then stops the SPT sequencer, data acquisition
*               and waits until the SPT transitions to 'reset' state.
*
* @return       success or error status information.
*
* @pre          It must be called only after Spt_Setup() has been executed successfully at least once, to prepare
*               for reinitialization or to recover from a SPT hardware error.
*/
Std_ReturnType Spt_Stop(void);


#if (SPT_VERSION_INFO_API == STD_ON)
/**
 * @brief       The function returns the version info for the module.
 * @details     The function returns the version info for the module.
 *
 * @param[in]   versionInfoPtr - pointer to a version structure to receive the data
 */
void Spt_GetVersionInfo(Std_VersionInfoType* versionInfoPtr);
#endif



#define SPT_STOP_SEC_CODE
#include "Spt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_SPT_H */
