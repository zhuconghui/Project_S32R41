/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */


/******************************************************************************
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/


/* RF_Abstract 2.0 Memory Map Shared Memory example
 *
 *  For R41, the values are :
 *                  RFE_CMD_IF_BASE_ADDRESS_PTR     = 0x343FFFFCUL
 *                  RFE_CMD_CLIENT_BASE_ADDRESS     = 0x343F0000UL
 *
 *   +-------------------------------+
 *   |...                            |
 *   +-------------------------------+
 *   |RFE Communication BASEADDRESS  | <- This is the base address of the command/response server-client communication.
 *   |(512 bytes)                    |    Defined by application and hand over to Client (RFE Driver) and Server (RFE FW) via rfeCmdClient_init()
 *   |This address is user definable.|    The uint32_t pointer rfeCmdClient_cmdArea will point to this region.
 *   |                               |    Its location is defined by the RfeDriver. During initialization the RFE M7
 *   |                               |    RFE Server is informed about the location using the fixed 2 memory locations
 *   | +---------------------------+ |    RFE_STATE_ADDRESS and BASE_ADDRESS_PTR (see at the end of the memory map).
 *   | |                           | |
 *   | | +-----------------------+ | |
 *   | | |Command buffer         | | |
 *   | | |BASEADDRESS+0          | | |
 *   | | |(256 Bytes)            | | |
 *   | | |                       | | |
 *   | | |                       | | |
 *   | | +-----------------------+ | |
 *   | | |Offset 256: CNT        | | | <- CNT is used as sequence counter and to be able to detect a new command (trigger)
 *   | | +-----------------------+ | |
 *   | +---------------------------+ |
 *   | |                           | |
 *   | | +-----------------------+ | |
 *   | | |Response buffer        | | |
 *   | | |BASEADDRESS+257        | | |
 *   | | |                       | | |
 *   | | |                       | | |
 *   | | |                       | | |
 *   | | +-----------------------+ | |
 *   | | |Offset 256: CNT        | | | <- CNT is used as sequence counter and to be able to detect a new response
 *   | | +-----------------------+ | |
 *   | +---------------------------+ |
 *   | +---------------------------+ |
 *   | |                           | |
 *   | | +-----------------------+ | |
 *   | | |State buffer           | | |
 *   | | |BASEADDRESS+514        | | |
 *   | | |                       | | |
 *   | | |                       | | |
 *   | | |                       | | |
 *   | | +-----------------------+ | |
 *   | | |Offset 32: CNT         | | | <- CNT is used as sequence counter and to be able to detect a state update event
 *   | | +-----------------------+ | |
 *   +-------------------------------+
 *   |...                            |
 *   |...                            |
 *   +-------------------------------+
 *   |0x343fff80: RFE Sync Area      | <- This memory address and area is fixed for RF_Abstract 2.0 and has to be avoided by the application
 *   |(128 bytes)                    |
 *   |                               |
 *   | +---------------------------+ |
 *   | | Reserved                  | |
 *   | | ...                       | |
 *   | +---------------------------+ |
 *   | | 0x343ffffc: (4 bytes)     | |
 *   | | BASE_ADDRESS_PTR          | |
 *   | +---------------------------+ |
 *   +-------------------------------+
 *
 */

/**********************************************************************************************************************
*                                        INCLUDE FILES
 *********************************************************************************************************************/
#include "rfe_ipc_api_app.h"
#include "rfe20_PCCfg.h"
#include "typedefs.h"
#include "rfe_cmd_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************************************************
*                                      DEFINES AND MACROS
 *********************************************************************************************************************/
#define CMD_MAX_SIZE  (RFE_CMD_IF_CMDRSPLEN)
#define RSP_MAX_SIZE  (RFE_CMD_IF_CMDRSPLEN)
#define STS_MAX_SIZE  (RFE_CMD_IF_SHAREDATACOUNT)

/**********************************************************************************************************************
 *                                                 LOCAL TYPES
 *********************************************************************************************************************/
/*Cmd, rsp and sts are aligned enforced to word. Added to make sure that rfeCmdClient_stsAreaShadow is updated
 * with a word granularity
 */
typedef struct
{
   uint32_t cmdArea[CMD_MAX_SIZE] __attribute__((aligned(4)));
   uint32_t cmdCnt;
   uint32_t rspArea[RSP_MAX_SIZE] __attribute__((aligned(4)));
   uint32_t rspCnt;
   uint32_t stsArea[STS_MAX_SIZE] __attribute__((aligned(4)));
   uint32_t stsCnt;
}ipcSharedMem_t;

typedef struct
{
    uint32_t prevCmdCnt;
    uint32_t prevRspCnt;
    uint32_t prevStsCnt;
    volatile ipcSharedMem_t* ipc_mem;
}ipc_t;


/**********************************************************************************************************************
 *                                                 VARIABLES
 *********************************************************************************************************************/
static volatile ipc_t ipc;


/*==================================================================================================
 *                              FUNCTIONS.
 *==================================================================================================*/
static uint32 rfeIpc_getMaxTmo(void)
{
    return RFE_IPC_TIMEOUT;
}


/*==================================================================================================
 *                              FUNCTIONS. Called on Server Side
 *==================================================================================================*/
int32_t rfeIpc_srvInit(void)
{
    ipc.prevCmdCnt = 0;
    ipc.prevRspCnt = 0;
    ipc.prevStsCnt = 0;
    int32_t  error = 1;
    uint32_t timeout = rfeIpc_getMaxTmo();

    do
    {
        ipc.ipc_mem  = (volatile ipcSharedMem_t*)(*(volatile uint32_t*)(RFE_CMD_IF_BASE_ADDRESS_PTR));
        DECREMENT_TMO(timeout);
    }
    while((ipc.ipc_mem == NULL_PTR) && (timeout > 0));

    if(ipc.ipc_mem != NULL_PTR)
    {
        error = 0;
    }

    return error;
}

int32_t rfeIpc_srvInitCheck(void)
{
    int32_t  error = 1;
    uint32_t timeout = rfeIpc_getMaxTmo();

    while(timeout)
    {
        DECREMENT_TMO(timeout);
        ipc.ipc_mem  = (volatile ipcSharedMem_t*)(*(uint32_t*)(RFE_CMD_IF_BASE_ADDRESS_PTR));

        if(ipc.ipc_mem != NULL_PTR)
        {
            error = 0;
            break;
        }
    }

    return error;

}

void* rfeIpc_srvRspBuffAcquire(void)
{
    return (void*)ipc.ipc_mem->rspArea;
}

void* rfeIpc_srvStsBuffAcquire(void)
{
    return (void*)ipc.ipc_mem->stsArea;

}

int32_t rfeIpc_srvStsTx(void* msg, uint32_t msgLen)
{
    int32_t err = 1;
    uint32_t  *pMsg = (uint32_t*) msg;
    if((msg != NULL_PTR) && ((STS_MAX_SIZE * 4UL) >= msgLen))
    {
        /*added word granularity copy to avoid  a non atomic update of the status entries */
        /*best practice to avoid this is to add a mutex to protect status read and writes*/
        for(uint32_t i= 0; i < STS_MAX_SIZE; i++)
        {
            ipc.ipc_mem->stsArea[i] = pMsg[i];
        }
        ipc.ipc_mem->stsCnt++;
        err = 0;
    }

    return err;
}


int32_t rfeIpc_srvRspTx(void* msg, uint32_t msgLen)
{
    int32_t err = 1;

    if((msg != NULL_PTR) && ((RSP_MAX_SIZE * 4UL) >= msgLen))
    {
        memcpy((void*)ipc.ipc_mem->rspArea, msg, msgLen);
        ipc.ipc_mem->rspCnt++;
        err = 0;
    }

    return err;
}

void* rfeIpc_srvCmdPoll(int32_t *err)
{
    void* buff = NULL_PTR;
    *err = 0;

    if(ipc.ipc_mem->cmdCnt != ipc.prevCmdCnt)
    {
        buff =(void*)&ipc.ipc_mem->cmdArea[0];
        ipc.prevCmdCnt = ipc.ipc_mem->cmdCnt;
    }

    return buff;
}

/*==================================================================================================
 *                              FUNCTIONS. Called on Client Side
 *==================================================================================================*/
int32_t rfeIpc_clientInit(void)
{
    int32_t err = 0;
    uint32_t*  pBaseAddressPtr = (uint32_t *)RFE_CMD_IF_BASE_ADDRESS_PTR;

    ipc.prevCmdCnt = 0;
    ipc.prevRspCnt = 0;
    ipc.prevStsCnt = 0;
    ipc.ipc_mem = (volatile ipcSharedMem_t*) RFE_CMD_CLIENT_BASE_ADDRESS;
    memset((void*)ipc.ipc_mem, 0, sizeof(ipcSharedMem_t));
    *pBaseAddressPtr = (volatile uint32_t)RFE_CMD_CLIENT_BASE_ADDRESS;

    return err;
}

void* rfeIpc_clientCmdBuffAquire(void)
{
    return (void*)ipc.ipc_mem->cmdArea;
}
int32_t rfeIpc_clientCmdTx(void* msg, uint32_t msgLen)
{
    int32_t err = 1;

    if((msg != NULL_PTR) && ((CMD_MAX_SIZE * 4UL) >= msgLen))
    {
        memcpy((void*)ipc.ipc_mem->cmdArea, msg, msgLen);
        ipc.ipc_mem->cmdCnt++;
        err = 0;
    }

    return err;
}

void* rfeIpc_clientStsPoll(int32_t *err)
{
    void* buff = NULL_PTR;

    if(ipc.ipc_mem->stsCnt != ipc.prevStsCnt)
    {
        buff =(void*)&ipc.ipc_mem->stsArea[0];
        ipc.prevStsCnt = ipc.ipc_mem->stsCnt;
    }
    *err = 0;

    return buff;
}

void* rfeIpc_clientStsWait(int32_t *err)
{
    void* buff = NULL_PTR;
    int32_t localErr = 0;
    uint32_t timeout = rfeIpc_getMaxTmo();

    *err = 1;

    while(timeout)
    {
        DECREMENT_TMO(timeout);
        buff = rfeIpc_clientStsPoll(&localErr);

        if ((buff != NULL_PTR) && (localErr == 0))
        {
           *err = 0;
           break;
        }
    }

    return buff;
}

void* rfeIpc_clientRspWait(int32_t *err)
{
    void* buff = NULL_PTR;
    uint32_t timeout = rfeIpc_getMaxTmo();

    *err = 1;

    while(timeout)
    {
        DECREMENT_TMO(timeout);

        if(ipc.ipc_mem->rspCnt != ipc.prevRspCnt)
        {
           buff    =  (void*)(&ipc.ipc_mem->rspArea[0]);
           ipc.prevRspCnt = ipc.ipc_mem->rspCnt;
           *err    = 0;
           break;
        }
    }

    return buff;
}
/***** rfe_ipc_api_shm ***********************/

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
