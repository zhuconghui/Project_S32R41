
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








/* clang-format off  */
#ifndef CTE_SPECIFIC_H
#define CTE_SPECIFIC_H

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include "Cte_Types.h"










#if defined(S32R294)
    #include "S32R294_CTE.h"


#else
    #include "S32R41_CTE.h"
#endif





#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

    #define CTE_SPECIFIC_VENDOR_ID                        43
    #define CTE_SPECIFIC_AR_RELEASE_MAJOR_VERSION         RSDK_AR_MAJOR
    #define CTE_SPECIFIC_AR_RELEASE_MINOR_VERSION         RSDK_AR_MINOR
    #define CTE_SPECIFIC_AR_RELEASE_REVISION_VERSION      RSDK_AR_REV
    #define CTE_SPECIFIC_SW_MAJOR_VERSION                 RSDK_SW_MAJOR
    #define CTE_SPECIFIC_SW_MINOR_VERSION                 RSDK_SW_MINOR
    #define CTE_SPECIFIC_SW_PATCH_VERSION                 RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/



/*==================================================================================================
 *                                          CONSTANTS
 ==================================================================================================*/
#define CTE_MAX_LARGE_TIME_TABLE_LEN    64u     /* maximum length for single time table usage                       */
#define CTE_MAX_SMALL_TIME_TABLE_LEN    32u     /* maximum length for double time table usage (single table)        */


#if defined(S32R294)
    #define CTE_IRQ_NUMBER      739u                /* hardware interrupt number                                        */


#else
    #define CTE_IRQ_NUMBER      219u                /* hardware interrupt number                                        */
#endif






/*==================================================================================================
 *                                      DEFINES AND MACROS
 ==================================================================================================*/
#define CTE_CLOCK_DIVIDER_LIMIT     0x40u       /* the clock divider limit (the value must be less than this value) */
#define CTE_TOO_BIG_TIME_DELAY      0xffffffffu /* a time delay which exceed the maximum admisible                  */
#define CTE_MAX_TIME_COUNTER        0x10000u    /* the internal timecounter limit for CTE events                    */
#define CTE_1G_FREQUENCY            1000000000u /* 1GHz frequency                                                   */

#define CTE_SPT0_SIG_MASK           0x10000000LU                /* mask for SPT0 signal                             */
#define CTE_FLEX_SIG_MASK           ((uint64_t)0x1LU << 33u)    /* mask for first FLEX signal                       */
#define CTE_OUTPUT_MASK_SHIFT_BASE  32u                         /* the minimum shift for the output signal mask     */

#define CTE_INTERNAL_CLOCKS         4u                          /* CTE has 4 internal clock dividers                */
#define CTE_MAX_REQ_CLK_DIVIDER     192u                        /* Max clock divider                                */
#define CTE_MAX_CLK_DIVIDERS        8u                          // the number of possible dividers for clocks       */


/*==================================================================================================
 *                                             ENUMS
 ==================================================================================================*/
/* enum for toggle signal manipulations         */
typedef enum {
    CTE_TOGGLE_MASK_TO_LOW = 0u,
    CTE_TOGGLE_MASK_TO_HIGH,
    CTE_TOGGLE_MASK_TOGGLE,
    CTE_TOGGLE_MASK_UNCHANGED,
}Cte_ToggleMaskType;

/* enum for clock signal manipulations          */
typedef enum {
    CTE_CLOCK_MASK_TO_LOW = 0u,
    CTE_CLOCK_MASK_SYNC_RISING,
    CTE_CLOCK_MASK_RUNNING,
    CTE_CLOCK_MASK_TO_HIGH,
}Cte_ClockMaskType;

/* enum for logic signal manipulations          */
typedef enum {
    CTE_LOGIC_MASK_TO_LOW = 0u,
    CTE_LOGIC_MASK_TO_HIGH,
    CTE_LOGIC_MASK_TO_HIZ,
    CTE_LOGIC_MASK_UNCHANGED,
}Cte_LogicMaskType;

/* enum for the driver states                   */
typedef enum {
    CTE_DRIVER_STATE_NOT_INIT = 0u,
    CTE_DRIVER_STATE_INITIALIZED,
    CTE_DRIVER_STATE_RUNNING,
}Cte_DriverStatusType;


/*==================================================================================================
 *                                STRUCTURES AND OTHER TYPEDEFS
 ==================================================================================================*/
/* Structure to keep the necessary data for low-level driver        */
typedef struct {
    uint8                   cteDriverStatus;        /* the current status of the driver                             */
    uint8                   cteMainClockDivider;    /* the main divider, for main CTE clock divider                 */
    uint8                   cteUsedClockDividers;   /* the number of used clocks                                    */
    uint32                  cteWorkingFreq;         /* the CTE working frequency, in Hz                             */
    uint32                  cteReqEvents;           /* the CTE events requested by application to be signaled       */



    uint32                  cteClocksPeriods[CTE_INTERNAL_CLOCKS];  /* resulting clock period                       */
    Cte_SingleOutputDefType signalDef0Ptr[CTE_OUTPUT_MAX + 1u];       /* copy of the existing signals definitions     */
    Cte_SingleOutputDefType signalDef1Ptr[CTE_OUTPUT_MAX + 1u];
} Cte_DriverStateType;

/*==================================================================================================
 *                                GLOBAL VARIABLE DECLARATIONS
 ==================================================================================================*/
extern Cte_DriverStateType gsDriverData;            /* the driver necessary data                */
extern volatile CTE_Type *gspCTEPtr;                   /* the pointer to the CTE registry          */


/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
 ==================================================================================================*/


#ifdef __cplusplus
}
#endif



#endif /* CTE_SPECIFIC_H    */
