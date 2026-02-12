/*
 * Copyright 2018-2024 NXP
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
==================================================================================================*/
#include <string.h>
#include <xtensa/tie/radar24.h>
#include "cmd_handlers.h"
#include "hw_defs.h"
#include "crc8.h"


#include <xtensa/tie/xt_bben_scalarfp.h>




#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/**
* @brief          Number of elements in a BBE32 DSP native vector type.
* @details        Equal to the number of registers in a BBE32 DSP vector register file.
* */
#define BBE32_SIMD_VEC_SIZE 16

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
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

static uint32_t readWR(int32_t wRegIndex)
{
    //Read 32-bit value from Work Register: lower (least significant) 16 bits from the real part,
    //the higher 16 bits from the imaginary part

    bbx_vecNx24 wRegDataVec, tmpVec;
    int32_t    wRegDataRe, wRegDataIm;
    uint32_t wRegVal;


    wRegDataVec = BBX_LLU0NX24_I(wRegIndex, 0);



    wRegDataRe = BBX_MOVL2A(wRegDataVec);    //move element 0 to scalar
    BBX_SELNX24(tmpVec, wRegDataVec, 1);     //mode element 1 to element 0 of tmpVec
    wRegDataIm = BBX_MOVL2A(tmpVec);

    wRegVal = (((uint32_t)wRegDataRe & 0x00ffffffu)  + (((uint32_t)wRegDataIm & 0x000000ffu) << 24u));

    return wRegVal;
}



static void CheckFsrAndThrowFpErrors(uint8_t funcId)
{

    uint32_t fsrValue = XT_RUR_FSR();
    uint16_t fpExc = (uint16_t)((fsrValue >> DSP_FPU_EXC_SHIFT_VAL) & DSP_FPU_EXC_MASK);

    if (fpExc != 0u)
    {

        BBX_SCRLU(((int32_t)((fpExc << 8) | funcId)) , ADDR_DSP_DEBUG1_REG);



        SetDspError(RSDK_DSP_RET_ERR_FP);
    }
}


rsdkStatus_t DispatcherCmdParse(uint8_t *const pRawCmd, dspCmdContext_t *const pParsedCmd, rsdkDspFuncPtr_t *funcTable,
                         uint32_t funcTableSize, dspCmdSrc_t cmdSrc)
{
    rsdkStatus_t retStatus = RSDK_SUCCESS;
    uint8_t unsupportedCmds = 0;
    uint8_t cmdCrcRead, cmdCrcComp;
    uint8_t cmdFormatPam, cmdFormatCrcEn, cmdArgSize;

    int32_t wRegIndex;
    uint32_t wRegData;

    uint8_t* pCmdPayload = (uint8_t*)(&pParsedCmd->cmdPayloadBits[0]) + DSP_CMD_ID_OFFSET; //needed for byte access to 32-bit aligned storage space
    JobDescriptor_t* const pJobDesc = (JobDescriptor_t* const)pRawCmd;





    /*NOTE: The "commands" can come either from the SPT or the host CPU, we are using the same function for decoding them.
     * For SPT commands, the BBE32 reads the bytes from the SPT command queue in little-endian order,
     * so they are reversed, when compared to how they are pushed in the queue by the SPT
     * CPU commands are parsed using the definition of JobDescriptor_t, which mirrors the "DSP Calling Convention"
     * described in the RSDK User Manual and matches also with the SPT command structure.
     * */

    RSDK_COMPILER_ASSERT(sizeof(JobDescriptor_t) == SIZEOF_JOB_DESCRIPTOR);

    //interpret the command format:
    cmdFormatPam = pJobDesc->cmdFormat & DSP_CMD_FORMAT_PAM_BIT;
    cmdFormatCrcEn = pJobDesc->cmdFormat & DSP_CMD_FORMAT_CRCEN_BIT;

    if(cmdFormatPam == DSP_CMD_FORMAT_PAM_DIRECT)
    {
        //function ID and parameters are passed directly in the command bitfield

        //read the funcID from bits 8:15 of the SPT "DSP" command:
        pCmdPayload[0] = pJobDesc->funcId;

        //copy the parameter list from bits 16:111 of the "DSP" command to parsed cmd structure
        cmdArgSize = DSP_CMD_DIRECT_PARAM_SIZE;
        (void)memcpy(&pCmdPayload[DSP_CMD_ID_SIZE], &pJobDesc->paramList , cmdArgSize);

        //read the command CRC - bits 0:7 of the SPT "DSP" command:
        cmdCrcRead = pJobDesc->crc;
    }

    else
    {
        if(cmdSrc == DSP_CMD_SRC_SPT)
        {
            //function ID and parameters are passed through Work Regs

            //Index of the WorkReg which contains the funcID is read from bits 8:15 of the SPT "DSP" command:
            wRegIndex = (int32_t)pRawCmd[1];
            pCmdPayload[0] = (uint8_t)readWR(wRegIndex);

            //read index of the WorkReg which contains the command argument - bits 16:23 of the SPT "DSP" command:
            wRegIndex = (int32_t)pRawCmd[2];
            // Read the 32-bit command argument and copy to parsed cmd structure:
            wRegData = readWR(wRegIndex);
            cmdArgSize = (uint8_t)DSP_CMD_INDIRECT_PARAM_SIZE;
            (void)memcpy(&pCmdPayload[DSP_CMD_ID_SIZE], (uint8_t*)&wRegData, cmdArgSize);

            //read index of the WorkReg which contains the command CRC - bits 0:7 of the SPT "DSP" command:
            wRegIndex = (int32_t)pRawCmd[0];
            cmdCrcRead = (uint8_t)readWR(wRegIndex);
        }
        else //DSP_CMD_SRC_CPU
        {
            unsupportedCmds = 1;
            //commands coming from host CPU are restricted to direct parameter encoding format.
            retStatus = RSDK_DSP_RET_ERR_CMD_INVALID;
        }
    }

    if (unsupportedCmds == 0u)
    {
        pParsedCmd->funcID = pCmdPayload[0];
        pParsedCmd->pCmdArg = (dspCmdArgList_t)&pCmdPayload[DSP_CMD_ID_SIZE];

        if (pParsedCmd->funcID >= funcTableSize)
        {

            BBX_SCRLU((int32_t)pParsedCmd->funcID, ADDR_DSP_DEBUG1_REG);



            retStatus = RSDK_DSP_RET_ERR_CMD_INVALID;
        }
        else
        {
            pParsedCmd->pCmdHandler = (dspCmdHandler_t)funcTable[pParsedCmd->funcID];

            if(cmdFormatCrcEn != 0u)
            {
                //check command integrity. This implementation must be identical to the one in SPT Driver,
                //including endiannes and copy order of parameters

                cmdCrcComp = GenCrc8(pCmdPayload, (uint8_t)(DSP_CMD_ID_SIZE+cmdArgSize));
                if(cmdCrcComp != cmdCrcRead)
                {

                    BBX_SCRLU((int32_t)cmdCrcComp, ADDR_DSP_DEBUG1_REG);



                    retStatus = RSDK_DSP_RET_ERR_CRC_INVALID;
                }
            }
            else
            {
                retStatus = RSDK_DSP_RET_WARN_CMD_CRC_DISABLED;
            }
        }
    }

    return retStatus;
}

void RunDspCmd(dspCmdContext_t *pParsedCmd)
{

    if(gRsdkDspDispatcherMemPer.runtimeConfig.reportFPUExceptions == 1u)
    {
        // Clear FSR
        XT_WUR_FSR(0x0);
    }


    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, pParsedCmd->funcID, pParsedCmd->pCmdArg);
    pParsedCmd->cmdStatus = (pParsedCmd->pCmdHandler)(pParsedCmd->pCmdArg);
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, pParsedCmd->funcID, 0u);


    if(gRsdkDspDispatcherMemPer.runtimeConfig.reportFPUExceptions == 1u)
    {
        // Throw FP errors
        CheckFsrAndThrowFpErrors(pParsedCmd->funcID);
        // Clear FSR
        XT_WUR_FSR(0x0);
    }

}

/*================================================================================================*/

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
