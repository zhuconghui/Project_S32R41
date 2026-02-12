/*
 * Copyright 2017-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef CSI2_SPECIFIC_H
#define CSI2_SPECIFIC_H

/**
*   @internal
*   @{
*/

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "rsdk_csi2_driver_api.h"

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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
/*================================================================================================*/
/**
 * @brief       Procedure to change the callback for a specific interrupt
 * @details     The procedure set for the specified unit and interrupt ID a new callback pointer
 * @note        The callback pointer is checked only to not be NULL
 *
 * @param[in] unitId    - unit : rsdkCsi2UnitID_t &isin; [ \if (S32R45_DOCS || S32R294_DOCS) \ref RSDK_CSI2_UNIT_1 ,
                                                                    \endif \ref RSDK_CSI2_MAX_UNITS )
 * @param[in] irqId     - interrupt ID &isin; [ \ref RSDK_ , \ref RSDK_CSI2_MAX_VC )
 * @param[in] pCallback - pointer to the new callback
 *
 * @return      RSDK_SUCCESS - if driver status is correct and all in-parameters are correct
 *
 */
rsdkStatus_t    Csi2_SetCallback(const rsdkCsi2UnitId_t unitId, const rsdkCsi2IrqId_t irqId,
        rsdkCsi2IsrCb_t pCallback);

#if defined(S32R294)
/*================================================================================================*/
/*
 * @brief       Procedure to get the buffer start for the next frame.
 * @details     The procedure returns the offset from the buffer start
 *                  where the first byte of the frame will be written.
 *              The procedure must be called after the previous frame was received,
 *                  but before the start of the expected frame.
 *
 * @param[in] unitId    - unit : rsdkCsi2UnitID_t &isin; [ \ref RSDK_CSI2_UNIT_1 , \ref RSDK_CSI2_MAX_UNITS )
 * @param[in] vcId      - VC ID &isin; [ \ref RSDK_CSI2_VC_0 , \ref RSDK_CSI2_MAX_VC )
 * @param[in] pOffset   - pointer to a uint32_t which will receive the real first byte offset
 *
 * @return      RSDK_SUCCESS - if driver status is correct; the offset will be passed
 *              error if the driver is in an inappropriate state; pOffset is not updated
 *
 */
rsdkStatus_t Csi2_GetFirstByteOffset(const rsdkCsi2UnitId_t unitId, const rsdkCsi2VirtChnlId_t vcId, uint32_t *pOffset);


/*================================================================================================*/
/*
 * @brief       Procedure to get the buffer start for the next frame.
 * @details     The procedure returns the buffer line
 *                  where the first line of the frame will be written.
 *              The procedure must be called after the previous frame was received,
 *                  but before the start of the expected frame.
 * @note        To get the exact address, must be used the buffer line length
 *                  declared in the unit initialization parameters (rsdkCsi2VCParams_t::bufLineLen).
 *
 * @param[in] unitId    - unit : rsdkCsi2UnitID_t &isin; [ \ref RSDK_CSI2_UNIT_1 , \ref RSDK_CSI2_MAX_UNITS )
 * @param[in] vcId      - VC ID &isin; [ \ref RSDK_CSI2_VC_0 , \ref RSDK_CSI2_MAX_VC )
 * @param[in] pFirstLine - pointer to a uint32_t which will receive the real first line position
 *
 * @return      RSDK_SUCCESS - if driver status is correct; the line will be passed (counting from 0)
 *              error if the driver is in an inappropriate state; pFirstLine is not updated
 *
 */
rsdkStatus_t Csi2_GetFirstLinePos(const rsdkCsi2UnitId_t unitId, const rsdkCsi2VirtChnlId_t vcId, uint32_t *pFirstLine);

#endif // #if defined(S32R294)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CSI2_SPECIFIC_H */
