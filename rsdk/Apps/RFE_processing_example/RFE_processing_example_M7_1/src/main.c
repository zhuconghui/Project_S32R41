/**************************************************************************************************
* Copyright 2022 - 2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

#include <string.h>

#include "Mcal.h"
#include "Mcu.h"
#include "Mcu_Cfg.h"
#include "Mcu_PBcfg.h"
#include "Gpt.h"
#include "Gpt_Cfg.h"
#include "Eth_43_GMAC.h"
#include "Siul2_Port_Ip.h"
#include "Siul2_Port_Ip_Cfg.h"
#include "OsIf.h"

#include "lwip/init.h"
#include "lwip/timeouts.h"
#include "lwip/udp.h"
#include "lwip/pbuf.h"
#include "lwip/ip4_addr.h"
#include "lwip/netif.h"
#include "lwip/etharp.h"

#include "netifcfg.h"
#include "gmacif.h"

#define GPT_1MS_CHANNEL GptConf_GptChannelConfiguration_GptChannelConfiguration_2
#define GPT_1MS_TICKS   (100000U)

#define UDP_TARGET_IP_STR  "192.168.0.8"
#define UDP_TARGET_PORT    (5000U)
#define UDP_PAYLOAD_SIZE   (1024U)
#define UDP_SEND_PERIOD_MS (1000U)

static struct netif s_netif[ETHIF_NUMBER];
extern void GmacIf_RxNotification(uint8 instance, uint8 channel);
static struct udp_pcb *s_udp_pcb = NULL;
static ip_addr_t s_udp_dst;
static uint8_t s_udp_payload[UDP_PAYLOAD_SIZE];

static void Eth_InitStackInterface(void)
{
    ip4_addr_t ipaddr;
    ip4_addr_t netmask;
    ip4_addr_t gw;

    ip4_addr_set_zero(&ipaddr);
    ip4_addr_set_zero(&netmask);
    ip4_addr_set_zero(&gw);

    if ((!netif_cfg[0]->has_dhcp) && (!netif_cfg[0]->has_auto_ip))
    {
        IP4_ADDR(&gw, netif_cfg[0]->gw[0], netif_cfg[0]->gw[1], netif_cfg[0]->gw[2], netif_cfg[0]->gw[3]);
        IP4_ADDR(&ipaddr, netif_cfg[0]->ip_addr[0], netif_cfg[0]->ip_addr[1], netif_cfg[0]->ip_addr[2], netif_cfg[0]->ip_addr[3]);
        IP4_ADDR(&netmask, netif_cfg[0]->netmask[0], netif_cfg[0]->netmask[1], netif_cfg[0]->netmask[2], netif_cfg[0]->netmask[3]);
    }

    netif_set_default(netif_add(&s_netif[0], &ipaddr, &netmask, &gw, NULL_PTR, ETHIF_INIT, netif_input));
    netif_set_up(&s_netif[0]);
}

static void Eth_UdpPeriodicSendCb(void *arg)
{
    struct pbuf *p;
    (void)arg;

    if (s_udp_pcb == NULL)
    {
        /* Retry next second if PCB has not been created yet. */
        (void)sys_timeout(UDP_SEND_PERIOD_MS, Eth_UdpPeriodicSendCb, NULL_PTR);
        return;
    }

    p = pbuf_alloc(PBUF_TRANSPORT, UDP_PAYLOAD_SIZE, PBUF_RAM);
    if (p != NULL)
    {
        (void)pbuf_take(p, s_udp_payload, UDP_PAYLOAD_SIZE);
        (void)udp_sendto(s_udp_pcb, p, &s_udp_dst, UDP_TARGET_PORT);
        pbuf_free(p);
    }

    (void)sys_timeout(UDP_SEND_PERIOD_MS, Eth_UdpPeriodicSendCb, NULL_PTR);
}

static void Eth_StartPeriodicUdpSend(void)
{
    memset(s_udp_payload, 0xA5, sizeof(s_udp_payload));

    s_udp_pcb = udp_new();
    if (s_udp_pcb == NULL)
    {
        return;
    }

    (void)udp_bind(s_udp_pcb, IP_ADDR_ANY, 0U);

    if (ipaddr_aton(UDP_TARGET_IP_STR, &s_udp_dst) == 0)
    {
        udp_remove(s_udp_pcb);
        s_udp_pcb = NULL;
        return;
    }

    (void)sys_timeout(UDP_SEND_PERIOD_MS, Eth_UdpPeriodicSendCb, NULL_PTR);
}

int main(void)
{
    Mcu_Init(&Mcu_Config);
    (void)Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);

    (void)Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

    OsIf_Init(NULL_PTR);

    Gpt_Init(&Gpt_Config);
    Gpt_EnableNotification(GPT_1MS_CHANNEL);
    Gpt_StartTimer(GPT_1MS_CHANNEL, GPT_1MS_TICKS);

    Eth_43_GMAC_Init(NULL_PTR);
    (void)Eth_43_GMAC_SetControllerMode(EthConf_EthCtrlConfig_EthCtrlConfig_0, ETH_MODE_ACTIVE);

    lwip_init();
    Eth_InitStackInterface();

    /* Start periodic UDP transmission: one 1024-byte frame per second. */
    Eth_StartPeriodicUdpSend();

    while (1)
    {
        /* Poll RX path so ARP/UDP replies can be processed. */
//        GmacIf_RxNotification(0U, 0U);
        sys_check_timeouts();
    }
}
