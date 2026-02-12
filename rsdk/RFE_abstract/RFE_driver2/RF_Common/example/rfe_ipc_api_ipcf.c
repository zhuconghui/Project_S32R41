/*
* Copyright 2024 NXP
*
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
/* RF_Abstract 2.0. Transport protocol implementation example using IPCF.
 * More details about IPCF can be found in SW32R41_IPCF_1.1.0_D2405_User_Manual.pdf
 * Communication between  server and the client requires initialization of three communication
 * channels. For command, command response and for status update.
 * Command and response channel are paired as the protocol acknowledge each command through
 * the response channel.
 * State channel is a asynchronous channel and is used to update the firmware state. This informations
 * are polled on a need basis and impose a requirement for the rfeIpc_clientStsPoll implementation.
 * It needs to provide the latest information in case meanwhile multiple update were received.
 *
 * The structure of this example uses a dedicated IPCF (eg RFE_ABSTRACT_IPCF_INSTANCE) instance for this communication
 * This instance has Two channels as IPCF channels are bidirectional. At logical level they need to be interpreted
 * as independent channels.
 * Response channel (RFE_ABSTRACT_IPCF_RSP_CH_ID) and State channels(RFE_ABSTRACT_IPCF_STS_CH_ID) are define with
 * IRQ events and command channel(RFE_ABSTRACT_IPCF_CMD_CH_ID) is configure without an IRQ event
 *
 * Channel minimum size must be 256 bytes for command and response  channels  and 32 bytes for State channel
 *  To reduce  the signaling overhead and taking in consideration that only one message queues are required
 *  unmanaged channels type was picked for this example
 *
 */
/**********************************************************************************************************************
*                                        INCLUDE FILES
 *********************************************************************************************************************/
#include "rfe_ipc_api_app.h"
#include "ipc-shm.h"
#include "ipcf_Ip_Cfg.h"
#include "rfe_ipc_api_app.h"
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
typedef struct {
    uint8_t instance;
    uint8_t chan_id;
    void *buf;
    bool present;
} ipcf_cb_arg_t;


/**********************************************************************************************************************
 *                                                 VARIABLES
 *********************************************************************************************************************/
volatile ipcf_cb_arg_t rsp_arg;
volatile ipcf_cb_arg_t sts_arg;
volatile ipcf_cb_arg_t cmd_arg;

const void* rsp_arg_ptr;
const void* sts_arg_ptr;
const void* cmd_arg_ptr;


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
    cmd_arg_ptr = (const void*)&cmd_arg;
    return ipc_shm_init(&ipcf_shm_instances_cfg);

}

int32_t rfeIpc_srvInitCheck(void)
{
    int32_t err = 1;
    uint32_t timeout = rfeIpc_getMaxTmo();
    while(timeout)
    {
        err = ipc_shm_is_remote_ready(RFE_ABSTRACT_IPCF_INSTANCE);
        if(err == 0)
        {
            break;
        }
        DECREMENT_TMO(timeout);
    }

    return err;
}

void* rfeIpc_srvRspBuffAcquire(void)
{
    return ipc_shm_unmanaged_acquire(RFE_ABSTRACT_IPCF_INSTANCE, RFE_ABSTRACT_IPCF_RSP_CH_ID);
}

void* rfeIpc_srvStsBuffAcquire(void)
{
    return ipc_shm_unmanaged_acquire(RFE_ABSTRACT_IPCF_INSTANCE, RFE_ABSTRACT_IPCF_STS_CH_ID);
}


int32_t rfeIpc_srvStsTx(void* msg, uint32_t msgLen)
{
    uint32_t* buff = NULL_PTR;
    int32_t err = 1;
    buff = (uint32_t*)ipc_shm_unmanaged_acquire(RFE_ABSTRACT_IPCF_INSTANCE, RFE_ABSTRACT_IPCF_STS_CH_ID);

    if((buff != NULL_PTR) && (msgLen <= (STS_MAX_SIZE * 4UL)))
    {
        uint32_t* pMsg = ( uint32_t*) msg;

        for(uint32_t i= 0; i < STS_MAX_SIZE; i++)
        {
            buff[i] = pMsg[i];
        }
        err = ipc_shm_unmanaged_tx(RFE_ABSTRACT_IPCF_INSTANCE, RFE_ABSTRACT_IPCF_STS_CH_ID);
    }

    return err;
}


int32_t rfeIpc_srvRspTx(void* msg, uint32_t msgLen)
{
    void* buff = NULL_PTR;
    int32_t err = 1;
    buff = ipc_shm_unmanaged_acquire(RFE_ABSTRACT_IPCF_INSTANCE, RFE_ABSTRACT_IPCF_RSP_CH_ID);

    if(buff != NULL_PTR)
    {
        memcpy(buff, msg, msgLen);
        err = ipc_shm_unmanaged_tx(RFE_ABSTRACT_IPCF_INSTANCE, RFE_ABSTRACT_IPCF_RSP_CH_ID);
    }

    return err;
}

void* rfeIpc_srvCmdPoll(int32_t *err)
{
    void* buff = NULL_PTR;
    int32_t numMsg = 0;
    *err = 1;

    numMsg = ipc_shm_poll_channels(RFE_ABSTRACT_IPCF_INSTANCE);
    (void)numMsg;

    if ((cmd_arg.buf != NULL_PTR))
    {
       buff    = cmd_arg.buf;
       *err    = 0;
    }
    cmd_arg.buf = NULL_PTR;

    return buff;
}
/*==================================================================================================
 *                              FUNCTIONS. Called on Client Side
 *==================================================================================================*/

int32_t rfeIpc_clientInit(void)
{
    int32_t init_error = 1;
    int32_t err = 1;
    uint32_t timeout = rfeIpc_getMaxTmo();

    rsp_arg_ptr =(const void*) &rsp_arg;
    sts_arg_ptr = (const void*)&sts_arg;
    init_error =  ipc_shm_init(&ipcf_shm_instances_cfg);

    while((timeout) && (init_error == 0))
    {
        err = ipc_shm_is_remote_ready(RFE_ABSTRACT_IPCF_INSTANCE);

        if(err == 0)
        {
            break;
        }
        DECREMENT_TMO(timeout);
    }

    return err;
}

void* rfeIpc_clientCmdBuffAquire(void)
{
    return ipc_shm_unmanaged_acquire(RFE_ABSTRACT_IPCF_INSTANCE, RFE_ABSTRACT_IPCF_CMD_CH_ID);
}
int32_t rfeIpc_clientCmdTx(void* msg, uint32_t msgLen)
{
    void* buff = NULL_PTR;
    int err = 1;

    buff = ipc_shm_unmanaged_acquire(RFE_ABSTRACT_IPCF_INSTANCE, RFE_ABSTRACT_IPCF_CMD_CH_ID);
    if(buff != NULL_PTR)
    {
        memcpy(buff, msg, msgLen);
        if(ipc_shm_unmanaged_tx(RFE_ABSTRACT_IPCF_INSTANCE, RFE_ABSTRACT_IPCF_CMD_CH_ID) == 0)
            err = 0;
    }
//task might be suspended here
    return err;
}

void* rfeIpc_clientStsPoll(int32_t *err)
{
    static void* buff = NULL_PTR;

    *err = 0;

    if ((sts_arg.buf != NULL_PTR))// && (numMsg > 0))
    {
       buff    = sts_arg.buf;
    }

    sts_arg.buf = NULL_PTR;

    return buff;
}

void* rfeIpc_clientStsWait(int32_t *err)
{
    void* buff = NULL_PTR;
    *err = 1;
    uint32_t timeout = rfeIpc_getMaxTmo();

    while(timeout)
    {
        DECREMENT_TMO(timeout);

        if ((sts_arg.buf != NULL_PTR))// && (numMsg > 0))
        {
           buff    = sts_arg.buf;
           *err    = 0;
           break;
        }
    }

    sts_arg.buf = NULL_PTR;

    return buff;
}

void* rfeIpc_clientRspWait( int32_t *err)
{
    void* buff = NULL_PTR;
    uint32_t timeout = rfeIpc_getMaxTmo();

    *err = 1;

    while(timeout)
    {
        DECREMENT_TMO(timeout);

        if ((rsp_arg.buf != NULL_PTR))// && (numMsg > 0))
        {
           buff    = rsp_arg.buf;
           *err    = 0;
           break;
        }
    }

    rsp_arg.buf = 0;

    return buff;
}
void ipcf_chan_rx_cb(void *arg, const uint8 instance, uint8 chan_id, void *mem)
{
    ipcf_cb_arg_t* ipcf_arg = (ipcf_cb_arg_t*)(*((int32_t*)arg));
    //is used
    ipcf_arg->instance = instance;
    ipcf_arg->chan_id  = chan_id;
    ipcf_arg->buf      = mem;
    ipcf_arg->present= true;
    //task might be resume here

    return;
}
/***** rfe_ipc_api_ipcf ***********************/

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
