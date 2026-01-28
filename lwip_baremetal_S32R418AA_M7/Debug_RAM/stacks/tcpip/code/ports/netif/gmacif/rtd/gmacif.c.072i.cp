
IPA constant propagation start:
Determining dynamic type for call: _4 = rx_buff_process_handler.8_3 (instance_16(D), &bd);
  Starting walk at: _4 = rx_buff_process_handler.8_3 (instance_16(D), &bd);
  instance pointer: &bd  Outer instance pointer: bd offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gmac_status_19 = Gmac_Ip_ReadFrame (instance_16(D), channel_17(D), &bd, &info);
  Function call may change dynamic type:gmac_status_19 = Gmac_Ip_ReadFrame (instance_16(D), channel_17(D), &bd, &info);
  Function call may change dynamic type:Gmac_Ip_ProvideRxBuff (instance_16(D), channel_17(D), &bd);
  Function call may change dynamic type:Gmac_Ip_ProvideRxBuff (instance_16(D), channel_17(D), &bd);
  Function call may change dynamic type:_4 = rx_buff_process_handler.8_3 (instance_16(D), &bd);
  Function call may change dynamic type:gmacif_input (_7, _8, _9);
Determining dynamic type for call: gmacif_input (_7, _8, _9);
  Starting walk at: gmacif_input (_7, _8, _9);
  instance pointer: _7  Outer instance pointer: _7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gmac_status_19 = Gmac_Ip_ReadFrame (instance_16(D), channel_17(D), &bd, &info);
  Function call may change dynamic type:Gmac_Ip_ProvideRxBuff (instance_16(D), channel_17(D), &bd);
  Function call may change dynamic type:Gmac_Ip_ProvideRxBuff (instance_16(D), channel_17(D), &bd);
  Function call may change dynamic type:_4 = rx_buff_process_handler.8_3 (instance_16(D), &bd);
  Function call may change dynamic type:gmacif_input (_7, _8, _9);
Determining dynamic type for call: gmacif_input (_7, _8, _9);
  Starting walk at: gmacif_input (_7, _8, _9);
  instance pointer: _8  Outer instance pointer: _8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gmac_status_19 = Gmac_Ip_ReadFrame (instance_16(D), channel_17(D), &bd, &info);
  Function call may change dynamic type:Gmac_Ip_ProvideRxBuff (instance_16(D), channel_17(D), &bd);
  Function call may change dynamic type:Gmac_Ip_ProvideRxBuff (instance_16(D), channel_17(D), &bd);
  Function call may change dynamic type:_4 = rx_buff_process_handler.8_3 (instance_16(D), &bd);
  Function call may change dynamic type:gmacif_input (_7, _8, _9);
Determining dynamic type for call: memcpy_64 (pd_17, ps_18, len_19);
  Starting walk at: memcpy_64 (pd_17, ps_18, len_19);
  instance pointer: pd_17  Outer instance pointer: pd_17 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memcpy (dst_9(D), src_7(D), alignment_15);
Determining dynamic type for call: memcpy_64 (pd_17, ps_18, len_19);
  Starting walk at: memcpy_64 (pd_17, ps_18, len_19);
  instance pointer: ps_18  Outer instance pointer: ps_18 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memcpy (dst_9(D), src_7(D), alignment_15);
Determining dynamic type for call: gmacif_low_level_init (netif_14(D));
  Starting walk at: gmacif_low_level_init (netif_14(D));
  instance pointer: netif_14(D)  Outer instance pointer: netif_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mld_gmac_filter (netif_35(D), &ip6_allnodes_ll, 1);
  Starting walk at: mld_gmac_filter (netif_35(D), &ip6_allnodes_ll, 1);
  instance pointer: netif_35(D)  Outer instance pointer: netif_35(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Gmac_Ip_SetMulticastHashFilter (_22, 1);
  Function call may change dynamic type:Gmac_Ip_EnableController (_18);
  Function call may change dynamic type:Gmac_Ip_ProvideRxBuff (_14, 0, &bd);
Determining dynamic type for call: mld_gmac_filter (netif_35(D), &ip6_allnodes_ll, 1);
  Starting walk at: mld_gmac_filter (netif_35(D), &ip6_allnodes_ll, 1);
  instance pointer: &ip6_allnodes_ll  Outer instance pointer: ip6_allnodes_ll offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Gmac_Ip_SetMulticastHashFilter (_22, 1);
  Function call may change dynamic type:Gmac_Ip_EnableController (_18);
  Function call may change dynamic type:Gmac_Ip_ProvideRxBuff (_14, 0, &bd);
Determining dynamic type for call: _2 = _1 (p_8, netif_11(D));
  Starting walk at: _2 = _1 (p_8, netif_11(D));
  instance pointer: p_8  Outer instance pointer: p_8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_8 = pbuf_alloc (0, size_6(D), 65);
Determining dynamic type for call: _2 = _1 (p_8, netif_11(D));
  Starting walk at: _2 = _1 (p_8, netif_11(D));
  instance pointer: netif_11(D)  Outer instance pointer: netif_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_8 = pbuf_alloc (0, size_6(D), 65);
Determining dynamic type for call: pbuf_status_3 = gmacif_low_level_output.part.0 (netif_6(D), p_4(D));
  Starting walk at: pbuf_status_3 = gmacif_low_level_output.part.0 (netif_6(D), p_4(D));
  instance pointer: netif_6(D)  Outer instance pointer: netif_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pbuf_status_3 = gmacif_low_level_output.part.0 (netif_6(D), p_4(D));
  Starting walk at: pbuf_status_3 = gmacif_low_level_output.part.0 (netif_6(D), p_4(D));
  instance pointer: p_4(D)  Outer instance pointer: p_4(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  gmacif_low_level_output.part.0/37:
  Jump functions of caller  Gmac_Ip_GetTransmitStatus/36:
  Jump functions of caller  pbuf_alloc/35:
  Jump functions of caller  Gmac_Ip_ReadFrame/34:
  Jump functions of caller  memcpy/33:
  Jump functions of caller  Gmac_Ip_RemoveDstAddrFromHashFilter/32:
  Jump functions of caller  Gmac_Ip_AddDstAddrToHashFilter/31:
  Jump functions of caller  lwip_htonl/30:
  Jump functions of caller  Gmac_Ip_Deinit/29:
  Jump functions of caller  netif_set_link_up/28:
  Jump functions of caller  Gmac_Ip_SetMulticastHashFilter/27:
  Jump functions of caller  Gmac_Ip_EnableController/26:
  Jump functions of caller  Gmac_Ip_ProvideRxBuff/25:
  Jump functions of caller  pbuf_free/24:
  Jump functions of caller  Gmac_Ip_SendMultiBufferFrame/23:
  Jump functions of caller  pbuf_clen/22:
  Jump functions of caller  pbuf_ref/21:
  Jump functions of caller  ethip6_output/20:
  Jump functions of caller  etharp_output/19:
  Jump functions of caller  GmacIf_TxNotification/17:
  Jump functions of caller  GmacIf_RxNotification/16:
    callsite  GmacIf_RxNotification/16 -> gmacif_input/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _4 = rx_buff_process_handler.8_3 (instance_16(D), &bd);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  memcpy_custom/15:
    callsite  memcpy_custom/15 -> memcpy_64/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  [17, -2]
  Jump functions of caller  memcpy_64/14:
  Jump functions of caller  gmacif_register_rx_buff_process_condition_handler/13:
  Jump functions of caller  igmp_gmac_filter/12:
  Jump functions of caller  mld_gmac_filter/11:
  Jump functions of caller  gmac_ethernetif_shutdown/10:
  Jump functions of caller  gmac_ethernetif_init/9:
    callsite  gmac_ethernetif_init/9 -> gmacif_low_level_init/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 1832, cst: 6
           offset: 1856, cst: 100000000
           offset: 1888, cst: 0
           offset: 1920, cst: 0
           offset: 1952, cst: 0
           offset: 1984, cst: 0
           offset: 2016, cst: 0
           offset: 2048, cst: 0
           offset: 2080, cst: 0
           offset: 2112, cst: 0
           offset: 2144, cst: 0
           offset: 2176, cst: 0
           offset: 2208, cst: 0
           offset: 2240, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  gmacif_low_level_init/8:
    callsite  gmacif_low_level_init/8 -> mld_gmac_filter/11 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 2304, cst: mld_gmac_filter
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 767
           offset: 32, cst: 0
           offset: 64, cst: 0
           offset: 96, cst: 16777216
           offset: 128, cst: 0
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  gmacif_input/7:
    indirect aggregate callsite, calling param 0, offset 1408, by reference, for stmt _2 = _1 (p_8, netif_11(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  gmacif_low_level_output/6:
    callsite  gmacif_low_level_output/6 -> gmacif_low_level_output.part.0/37 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR

 Propagating constants:

Not considering GmacIf_TxNotification for cloning; -fipa-cp-clone disabled.
Not considering GmacIf_RxNotification for cloning; -fipa-cp-clone disabled.
Not considering memcpy_custom for cloning; -fipa-cp-clone disabled.
Not considering memcpy_64 for cloning; -fipa-cp-clone disabled.
Not considering gmacif_register_rx_buff_process_condition_handler for cloning; -fipa-cp-clone disabled.
Not considering igmp_gmac_filter for cloning; -fipa-cp-clone disabled.
Not considering mld_gmac_filter for cloning; -fipa-cp-clone disabled.
Not considering gmac_ethernetif_shutdown for cloning; -fipa-cp-clone disabled.
Not considering gmac_ethernetif_init for cloning; -fipa-cp-clone disabled.
Not considering gmacif_low_level_output for cloning; -fipa-cp-clone disabled.

overall_size: 400, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: gmacif_low_level_output.part.0/37:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: GmacIf_TxNotification/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: GmacIf_RxNotification/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: memcpy_custom/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: memcpy_64/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: gmacif_register_rx_buff_process_condition_handler/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: igmp_gmac_filter/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mld_gmac_filter/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: gmac_ethernetif_shutdown/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: gmac_ethernetif_init/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: gmacif_low_level_init/8:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: gmacif_input/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: gmacif_low_level_output/6:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

gmacif_low_level_output.part.0/37 (gmacif_low_level_output.part.0) @05f5e000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: tx_pbufs/4 (read)netif_cfg/18 (read)tx_pbufs/4 (write)tx_pbufs/4 (write)
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: gmacif_low_level_output/6 (123389 (estimated locally),0.53 per call) 
  Calls: pbuf_ref/21 (214748 (estimated locally),1.00 per call) pbuf_clen/22 (214748 (estimated locally),1.00 per call) Gmac_Ip_SendMultiBufferFrame/23 (733545 (estimated locally),3.42 per call) pbuf_free/24 (35433 (estimated locally),0.16 per call) 
Gmac_Ip_GetTransmitStatus/36 (Gmac_Ip_GetTransmitStatus) @065222a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: GmacIf_TxNotification/17 (478422323 (estimated locally),2.67 per call) 
  Calls: 
pbuf_alloc/35 (pbuf_alloc) @065220e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: gmacif_input/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Gmac_Ip_ReadFrame/34 (Gmac_Ip_ReadFrame) @064f31c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: GmacIf_RxNotification/16 (1073741823 (estimated locally),9.09 per call) 
  Calls: 
memcpy/33 (memcpy) @064f3e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: memcpy_custom/15 (359703511 (estimated locally),0.33 per call) memcpy_custom/15 (118702159 (estimated locally),0.11 per call) memcpy_custom/15 (359703511 (estimated locally),0.33 per call) memcpy_custom/15 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Gmac_Ip_RemoveDstAddrFromHashFilter/32 (Gmac_Ip_RemoveDstAddrFromHashFilter) @064f39a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: igmp_gmac_filter/12 (536870913 (estimated locally),0.50 per call) mld_gmac_filter/11 (536870913 (estimated locally),0.50 per call) 
  Calls: 
Gmac_Ip_AddDstAddrToHashFilter/31 (Gmac_Ip_AddDstAddrToHashFilter) @064f38c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: igmp_gmac_filter/12 (536870913 (estimated locally),0.50 per call) mld_gmac_filter/11 (536870913 (estimated locally),0.50 per call) 
  Calls: 
lwip_htonl/30 (lwip_htonl) @064f37e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mld_gmac_filter/11 (1073741824 (estimated locally),1.00 per call) mld_gmac_filter/11 (1073741824 (estimated locally),1.00 per call) mld_gmac_filter/11 (1073741824 (estimated locally),1.00 per call) mld_gmac_filter/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Gmac_Ip_Deinit/29 (Gmac_Ip_Deinit) @064f3620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: gmac_ethernetif_shutdown/10 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
netif_set_link_up/28 (netif_set_link_up) @064f3460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: gmacif_low_level_init/8 (153437707 (estimated locally),1.00 per call) 
  Calls: 
Gmac_Ip_SetMulticastHashFilter/27 (Gmac_Ip_SetMulticastHashFilter) @064f3380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: gmacif_low_level_init/8 (153437707 (estimated locally),1.00 per call) 
  Calls: 
Gmac_Ip_EnableController/26 (Gmac_Ip_EnableController) @064f32a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: gmacif_low_level_init/8 (153437707 (estimated locally),1.00 per call) 
  Calls: 
Gmac_Ip_ProvideRxBuff/25 (Gmac_Ip_ProvideRxBuff) @064f30e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: GmacIf_RxNotification/16 (536870913 (estimated locally),4.55 per call) GmacIf_RxNotification/16 (131211251 (estimated locally),1.11 per call) gmacif_low_level_init/8 (767004445 (estimated locally),5.00 per call) 
  Calls: 
pbuf_free/24 (pbuf_free) @064e6380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: GmacIf_TxNotification/17 (233852832 (estimated locally),1.31 per call) gmacif_input/7 (351252089 (estimated locally),0.33 per call) gmacif_low_level_output.part.0/37 (35433 (estimated locally),0.16 per call) 
  Calls: 
Gmac_Ip_SendMultiBufferFrame/23 (Gmac_Ip_SendMultiBufferFrame) @064e60e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: gmacif_low_level_output.part.0/37 (733545 (estimated locally),3.42 per call) 
  Calls: 
pbuf_clen/22 (pbuf_clen) @064e6ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: gmacif_low_level_output.part.0/37 (214748 (estimated locally),1.00 per call) 
  Calls: 
pbuf_ref/21 (pbuf_ref) @064e6e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: gmacif_low_level_output.part.0/37 (214748 (estimated locally),1.00 per call) 
  Calls: 
ethip6_output/20 (ethip6_output) @064e6a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: gmac_ethernetif_init/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
etharp_output/19 (etharp_output) @064e69a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: gmac_ethernetif_init/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
netif_cfg/18 (netif_cfg) @064ed090
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: gmacif_low_level_init/8 (read)gmacif_low_level_init/8 (read)gmacif_low_level_init/8 (read)mld_gmac_filter/11 (read)mld_gmac_filter/11 (read)gmac_ethernetif_init/9 (read)igmp_gmac_filter/12 (read)gmacif_low_level_output.part.0/37 (read)gmacif_low_level_init/8 (read)gmacif_low_level_init/8 (read)gmac_ethernetif_shutdown/10 (read)igmp_gmac_filter/12 (read)GmacIf_RxNotification/16 (read)
  Availability: not_available
  Varpool flags:
GmacIf_TxNotification/17 (GmacIf_TxNotification) @064e6540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tx_pbufs/4 (read)tx_pbufs/4 (read)tx_pbufs/4 (read)tx_pbufs/4 (write)
  Referring: 
  Availability: available
  Function flags: count:178992764 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/24 (233852832 (estimated locally),1.31 per call) Gmac_Ip_GetTransmitStatus/36 (478422323 (estimated locally),2.67 per call) 
GmacIf_RxNotification/16 (GmacIf_RxNotification) @064e62a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: rx_buff_process_handler/2 (read)netif_cfg/18 (read)g_netif/1 (read)
  Referring: 
  Availability: available
  Function flags: count:118111598 (estimated locally) body optimize_size
  Called by: 
  Calls: Gmac_Ip_ProvideRxBuff/25 (536870913 (estimated locally),4.55 per call) gmacif_input/7 (39832748 (estimated locally),0.34 per call) Gmac_Ip_ProvideRxBuff/25 (131211251 (estimated locally),1.11 per call) Gmac_Ip_ReadFrame/34 (1073741823 (estimated locally),9.09 per call) 
   Indirect call(231713485 (estimated locally),1.96 per call) 
memcpy_custom/15 (memcpy_custom) @064e6000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: memcpy/33 (359703511 (estimated locally),0.33 per call) memcpy/33 (118702159 (estimated locally),0.11 per call) memcpy_64/14 (359703511 (estimated locally),0.33 per call) memcpy/33 (359703511 (estimated locally),0.33 per call) memcpy/33 (354334802 (estimated locally),0.33 per call) 
memcpy_64/14 (memcpy_64) @064dd8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: memcpy_custom/15 (359703511 (estimated locally),0.33 per call) 
  Calls: 
gmacif_register_rx_buff_process_condition_handler/13 (gmacif_register_rx_buff_process_condition_handler) @064dd000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: rx_buff_process_handler/2 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
igmp_gmac_filter/12 (igmp_gmac_filter) @064ddd20
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: netif_cfg/18 (read)netif_cfg/18 (read)
  Referring: gmacif_low_level_init/8 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gmac_Ip_RemoveDstAddrFromHashFilter/32 (536870913 (estimated locally),0.50 per call) Gmac_Ip_AddDstAddrToHashFilter/31 (536870913 (estimated locally),0.50 per call) 
mld_gmac_filter/11 (mld_gmac_filter) @064dd7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: netif_cfg/18 (read)netif_cfg/18 (read)
  Referring: gmacif_low_level_init/8 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: gmacif_low_level_init/8 (50634443 (estimated locally),0.33 per call) 
  Calls: Gmac_Ip_RemoveDstAddrFromHashFilter/32 (536870913 (estimated locally),0.50 per call) Gmac_Ip_AddDstAddrToHashFilter/31 (536870913 (estimated locally),0.50 per call) lwip_htonl/30 (1073741824 (estimated locally),1.00 per call) lwip_htonl/30 (1073741824 (estimated locally),1.00 per call) lwip_htonl/30 (1073741824 (estimated locally),1.00 per call) lwip_htonl/30 (1073741824 (estimated locally),1.00 per call) 
gmac_ethernetif_shutdown/10 (gmac_ethernetif_shutdown) @064dd1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: netif_cfg/18 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gmac_Ip_Deinit/29 (1073741824 (estimated locally),1.00 per call) 
gmac_ethernetif_init/9 (gmac_ethernetif_init) @06457e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tx_pbufs/4 (write)netif_cfg/18 (read)etharp_output/19 (addr)ethip6_output/20 (addr)gmacif_low_level_output/6 (addr)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: gmacif_low_level_init/8 (250539 (estimated locally),0.70 per call) 
gmacif_low_level_init/8 (gmacif_low_level_init) @06457d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: netif_cfg/18 (read)igmp_gmac_filter/12 (addr)g_netif/1 (write)gmacif_DataBuffer/3 (addr)netif_cfg/18 (read)rx_bufs/5 (write)netif_cfg/18 (read)netif_cfg/18 (read)netif_cfg/18 (read)mld_gmac_filter/11 (addr)
  Referring: 
  Availability: local
  Function flags: count:153437706 (estimated locally) body local optimize_size
  Called by: gmac_ethernetif_init/9 (250539 (estimated locally),0.70 per call) 
  Calls: netif_set_link_up/28 (153437707 (estimated locally),1.00 per call) mld_gmac_filter/11 (50634443 (estimated locally),0.33 per call) Gmac_Ip_SetMulticastHashFilter/27 (153437707 (estimated locally),1.00 per call) Gmac_Ip_EnableController/26 (153437707 (estimated locally),1.00 per call) Gmac_Ip_ProvideRxBuff/25 (767004445 (estimated locally),5.00 per call) 
gmacif_input/7 (gmacif_input) @06457a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: GmacIf_RxNotification/16 (39832748 (estimated locally),0.34 per call) 
  Calls: pbuf_free/24 (351252089 (estimated locally),0.33 per call) pbuf_alloc/35 (1073741824 (estimated locally),1.00 per call) 
   Indirect call(1064400271 (estimated locally),0.99 per call)  of param:0 loaded from aggregate passed by reference at offset 1408 (vptr maybe changed)
gmacif_low_level_output/6 (gmacif_low_level_output) @064577e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: gmac_ethernetif_init/9 (addr)
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: gmacif_low_level_output.part.0/37 (123389 (estimated locally),0.53 per call) 
rx_bufs/5 (rx_bufs) @06453a68
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: gmacif_low_level_init/8 (write)
  Availability: available
  Varpool flags:
tx_pbufs/4 (tx_pbufs) @064539d8
  Type: variable definition analyzed
  Visibility: force_output externally_visible public
  References: 
  Referring: gmac_ethernetif_init/9 (write)gmacif_low_level_output.part.0/37 (read)gmacif_low_level_output.part.0/37 (write)gmacif_low_level_output.part.0/37 (write)GmacIf_TxNotification/17 (read)GmacIf_TxNotification/17 (read)GmacIf_TxNotification/17 (read)GmacIf_TxNotification/17 (write)
  Availability: available
  Varpool flags:
gmacif_DataBuffer/3 (gmacif_DataBuffer) @06453948
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: gmacif_low_level_init/8 (addr)
  Availability: available
  Varpool flags:
rx_buff_process_handler/2 (rx_buff_process_handler) @064538b8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: gmacif_register_rx_buff_process_condition_handler/13 (write)GmacIf_RxNotification/16 (read)
  Availability: available
  Varpool flags: initialized
g_netif/1 (g_netif) @064537e0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: gmacif_low_level_init/8 (write)GmacIf_RxNotification/16 (read)
  Availability: available
  Varpool flags: initialized

;; Function mld_gmac_filter (mld_gmac_filter, funcdef_no=6, decl_uid=8212, cgraph_uid=7, symbol_order=11)

Modification phase of node mld_gmac_filter/11
mld_gmac_filter (struct netif * netif, const struct ip6_addr_t * group, netif_mac_filter_action action)
{
  uint8_t group_MAC[6];
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  unsigned char _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  unsigned char _10;
  long unsigned int _11;
  long unsigned int _12;
  short unsigned int _13;
  short unsigned int _14;
  unsigned char _15;
  long unsigned int _16;
  long unsigned int _17;
  unsigned char _18;
  unsigned char _19;
  int _20;
  struct netif_custom_t * _21;
  unsigned char _22;
  unsigned char _23;
  int _24;
  struct netif_custom_t * _25;
  unsigned char _26;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  group_MAC[0] = 51;
  # DEBUG BEGIN_STMT
  group_MAC[1] = 51;
  # DEBUG BEGIN_STMT
  _1 = group_31(D)->addr[3];
  _2 = lwip_htonl (_1);
  _3 = _2 >> 16;
  _4 = (short unsigned int) _3;
  _5 = _4 >> 8;
  _6 = (unsigned char) _5;
  group_MAC[2] = _6;
  # DEBUG BEGIN_STMT
  _7 = group_31(D)->addr[3];
  _8 = lwip_htonl (_7);
  _9 = _8 >> 16;
  _10 = (unsigned char) _9;
  group_MAC[3] = _10;
  # DEBUG BEGIN_STMT
  _11 = group_31(D)->addr[3];
  _12 = lwip_htonl (_11);
  _13 = (short unsigned int) _12;
  _14 = _13 >> 8;
  _15 = (unsigned char) _14;
  group_MAC[4] = _15;
  # DEBUG BEGIN_STMT
  _16 = group_31(D)->addr[3];
  _17 = lwip_htonl (_16);
  _18 = (unsigned char) _17;
  group_MAC[5] = _18;
  # DEBUG BEGIN_STMT
  if (action_40(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _19 = netif_41(D)->num;
  _20 = (int) _19;
  _21 = netif_cfg[_20];
  _22 = _21->num;
  Gmac_Ip_AddDstAddrToHashFilter (_22, &group_MAC);
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _23 = netif_41(D)->num;
  _24 = (int) _23;
  _25 = netif_cfg[_24];
  _26 = _25->num;
  Gmac_Ip_RemoveDstAddrFromHashFilter (_26, &group_MAC);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  group_MAC ={v} {CLOBBER};
  return 0;

}



;; Function igmp_gmac_filter (igmp_gmac_filter, funcdef_no=7, decl_uid=8216, cgraph_uid=8, symbol_order=12)

Modification phase of node igmp_gmac_filter/12
igmp_gmac_filter (struct netif * netif, const struct ip4_addr_t * group, netif_mac_filter_action action)
{
  uint8_t group_MAC[6];
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  unsigned char _4;
  unsigned char _5;
  int _6;
  struct netif_custom_t * _7;
  unsigned char _8;
  unsigned char _9;
  int _10;
  struct netif_custom_t * _11;
  unsigned char _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  group_MAC[0] = 1;
  # DEBUG BEGIN_STMT
  group_MAC[1] = 0;
  # DEBUG BEGIN_STMT
  group_MAC[2] = 94;
  # DEBUG BEGIN_STMT
  _1 = MEM[(const u8_t *)group_18(D) + 1B];
  _2 = _1 & 127;
  group_MAC[3] = _2;
  # DEBUG BEGIN_STMT
  _3 = MEM[(const u8_t *)group_18(D) + 2B];
  group_MAC[4] = _3;
  # DEBUG BEGIN_STMT
  _4 = MEM[(const u8_t *)group_18(D) + 3B];
  group_MAC[5] = _4;
  # DEBUG BEGIN_STMT
  if (action_22(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _5 = netif_23(D)->num;
  _6 = (int) _5;
  _7 = netif_cfg[_6];
  _8 = _7->num;
  Gmac_Ip_AddDstAddrToHashFilter (_8, &group_MAC);
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _9 = netif_23(D)->num;
  _10 = (int) _9;
  _11 = netif_cfg[_10];
  _12 = _11->num;
  Gmac_Ip_RemoveDstAddrFromHashFilter (_12, &group_MAC);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  group_MAC ={v} {CLOBBER};
  return 0;

}



;; Function gmacif_low_level_output (gmacif_low_level_output, funcdef_no=1, decl_uid=8232, cgraph_uid=2, symbol_order=6)

Modification phase of node gmacif_low_level_output/6
gmacif_low_level_output (struct netif * netif, struct pbuf * p)
{
  err_t pbuf_status;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG status => 1
  # DEBUG BEGIN_STMT
  # DEBUG pbuf_status => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pbuf_chain_type => 1
  # DEBUG BEGIN_STMT
  # DEBUG retries => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_4(D) == 0B)
    goto <bb 5>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  pbuf_status_3 = gmacif_low_level_output.part.0 (netif_6(D), p_4(D));
  # DEBUG BEGIN_STMT
  return pbuf_status_3;

}



;; Function gmac_ethernetif_init (gmac_ethernetif_init, funcdef_no=4, decl_uid=8206, cgraph_uid=5, symbol_order=9)

Modification phase of node gmac_ethernetif_init/9
gmac_ethernetif_init (struct netif * netif)
{
  uint8_t i;
  int _1;
  unsigned char _2;
  int _3;
  struct netif_custom_t * _4;
  char _5;
  char _6;
  _Bool _7;
  const char * _8;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_14(D) == 0B)
    goto <bb 11>; [30.00%]
  else
    goto <bb 12>; [70.00%]

  <bb 12> [local count: 250539]:
  goto <bb 5>; [100.00%]

  <bb 11> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 1252396]:
  # DEBUG BEGIN_STMT
  _1 = (int) i_9;
  tx_pbufs[_1] ={v} 0B;
  # DEBUG BEGIN_STMT
  i_38 = i_9 + 1;
  # DEBUG i => i_38

  <bb 5> [local count: 1502935]:
  # i_9 = PHI <i_38(4), 0(12)>
  # DEBUG i => i_9
  # DEBUG BEGIN_STMT
  if (i_9 != 5)
    goto <bb 4>; [83.33%]
  else
    goto <bb 6>; [16.67%]

  <bb 6> [local count: 250539]:
  # DEBUG BEGIN_STMT
  _2 = netif_14(D)->num;
  _3 = (int) _2;
  _4 = netif_cfg[_3];
  _5 = _4->name[0];
  netif_14(D)->name[0] = _5;
  # DEBUG BEGIN_STMT
  _6 = _4->name[1];
  netif_14(D)->name[1] = _6;
  # DEBUG BEGIN_STMT
  netif_14(D)->output = etharp_output;
  # DEBUG BEGIN_STMT
  _7 = _4->has_IPv6;
  if (_7 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 125270]:
  # DEBUG BEGIN_STMT
  netif_14(D)->output_ip6 = ethip6_output;

  <bb 8> [local count: 250539]:
  # DEBUG BEGIN_STMT
  netif_14(D)->linkoutput = gmacif_low_level_output;
  # DEBUG BEGIN_STMT
  _8 = _4->hostname;
  if (_8 != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 9> [local count: 175378]:
  # DEBUG BEGIN_STMT
  netif_14(D)->hostname = _8;

  <bb 10> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_14(D)->link_type = 6;
  # DEBUG BEGIN_STMT
  netif_14(D)->link_speed = 100000000;
  # DEBUG BEGIN_STMT
  netif_14(D)->ts = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifinoctets = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifinucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifinnucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifindiscards = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifinerrors = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifinunknownprotos = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifoutoctets = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifoutucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifoutnucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifoutdiscards = 0;
  # DEBUG BEGIN_STMT
  netif_14(D)->mib2_counters.ifouterrors = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  gmacif_low_level_init (netif_14(D));
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function gmac_ethernetif_shutdown (gmac_ethernetif_shutdown, funcdef_no=5, decl_uid=8208, cgraph_uid=6, symbol_order=10)

Modification phase of node gmac_ethernetif_shutdown/10
gmac_ethernetif_shutdown (struct netif * netif)
{
  unsigned char _1;
  int _2;
  struct netif_custom_t * _3;
  unsigned char _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = netif_6(D)->num;
  _2 = (int) _1;
  _3 = netif_cfg[_2];
  _4 = _3->num;
  Gmac_Ip_Deinit (_4);
  return;

}



;; Function gmacif_register_rx_buff_process_condition_handler (gmacif_register_rx_buff_process_condition_handler, funcdef_no=8, decl_uid=8218, cgraph_uid=9, symbol_order=13)

Modification phase of node gmacif_register_rx_buff_process_condition_handler/13
gmacif_register_rx_buff_process_condition_handler (unsigned int (*rx_buff_process_condition_handler_t) (uint8_t, struct Gmac_Ip_BufferType *) handler)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  rx_buff_process_handler = handler_2(D);
  return;

}



;; Function memcpy_64 (memcpy_64, funcdef_no=9, decl_uid=5651, cgraph_uid=10, symbol_order=14)

Modification phase of node memcpy_64/14
memcpy_64 (uint64_t * dst, uint64_t * src, unsigned int len)
{
  long long unsigned int _1;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  len_7 = len_6(D) >> 3;
  # DEBUG len => len_7
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  src_12 = src_3 + 8;
  # DEBUG src => src_12
  dst_13 = dst_2 + 8;
  # DEBUG dst => dst_13
  _1 = *src_3;
  *dst_2 = _1;

  <bb 4> [local count: 1073741824]:
  # dst_2 = PHI <dst_8(D)(2), dst_13(3)>
  # src_3 = PHI <src_9(D)(2), src_12(3)>
  # len_4 = PHI <len_7(2), len_11(3)>
  # DEBUG len => len_4
  # DEBUG src => src_3
  # DEBUG dst => dst_2
  # DEBUG BEGIN_STMT
  len_11 = len_4 + 4294967295;
  # DEBUG len => len_11
  if (len_4 != 0)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  return;

}



;; Function memcpy_custom (memcpy_custom, funcdef_no=10, decl_uid=5655, cgraph_uid=11, symbol_order=15)

Modification phase of node memcpy_custom/15
memcpy_custom (void * dst, const void * src, unsigned int len)
{
  unsigned int alignment;
  const char * ps;
  char * pd;
  unsigned int last_dest;
  unsigned int last_src;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  sizetype _4;
  unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (len_6(D) <= 32)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  memcpy (dst_9(D), src_7(D), len_6(D));
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  last_src_8 = (unsigned int) src_7(D);
  # DEBUG last_src => last_src_8
  # DEBUG BEGIN_STMT
  last_dest_10 = (unsigned int) dst_9(D);
  # DEBUG last_dest => last_dest_10
  # DEBUG BEGIN_STMT
  # DEBUG pd => dst_9(D)
  # DEBUG BEGIN_STMT
  # DEBUG ps => src_7(D)
  # DEBUG BEGIN_STMT
  _1 = last_src_8 ^ last_dest_10;
  _2 = _1 & 15;
  if (_2 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 359703511]:
  # DEBUG BEGIN_STMT
  alignment_14 = last_dest_10 & 15;
  # DEBUG alignment => alignment_14
  # DEBUG BEGIN_STMT
  alignment_15 = 16 - alignment_14;
  # DEBUG alignment => alignment_15
  # DEBUG BEGIN_STMT
  memcpy (dst_9(D), src_7(D), alignment_15);
  # DEBUG BEGIN_STMT
  pd_17 = dst_9(D) + alignment_15;
  # DEBUG pd => pd_17
  # DEBUG BEGIN_STMT
  ps_18 = src_7(D) + alignment_15;
  # DEBUG ps => ps_18
  # DEBUG BEGIN_STMT
  _11 = alignment_14 + 4294967280;
  len_19 = len_6(D) + _11;
  # DEBUG len => len_19
  # DEBUG BEGIN_STMT
  memcpy_64 (pd_17, ps_18, len_19);
  # DEBUG BEGIN_STMT
  _3 = len_19 & 15;
  if (_3 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 6> [local count: 118702159]:
  # DEBUG BEGIN_STMT
  _4 = len_19 & 4294967288;
  pd_21 = pd_17 + _4;
  # DEBUG pd => pd_21
  # DEBUG BEGIN_STMT
  ps_22 = ps_18 + _4;
  # DEBUG ps => ps_22
  # DEBUG BEGIN_STMT
  memcpy (pd_21, ps_22, _3);
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 359703511]:
  # DEBUG BEGIN_STMT
  memcpy (dst_9(D), src_7(D), len_6(D));

  <bb 8> [local count: 1073741824]:
  return;

}



;; Function GmacIf_RxNotification (GmacIf_RxNotification, funcdef_no=11, decl_uid=8226, cgraph_uid=12, symbol_order=16)

Modification phase of node GmacIf_RxNotification/16
GmacIf_RxNotification (uint8 instance, uint8 channel)
{
  uint32_t i;
  Gmac_Ip_StatusType gmac_status;
  struct Gmac_Ip_RxInfoType info;
  struct Gmac_Ip_BufferType bd;
  long unsigned int _1;
  long unsigned int _2;
  unsigned int (*<T8b8>) (uint8_t, struct Gmac_Ip_BufferType *) rx_buff_process_handler.8_3;
  unsigned int _4;
  struct netif_custom_t * _5;
  unsigned char _6;
  struct netif * _7;
  uint8 * _8;
  short unsigned int _9;

  <bb 2> [local count: 118111598]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG gmac_status => 2561
  # DEBUG BEGIN_STMT
  # DEBUG ret => -6

  <bb 3> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  gmac_status_19 = Gmac_Ip_ReadFrame (instance_16(D), channel_17(D), &bd, &info);
  # DEBUG gmac_status => gmac_status_19
  # DEBUG BEGIN_STMT
  if (gmac_status_19 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 4> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  _1 = info.ErrMask;
  if (_1 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => -12
  # DEBUG BEGIN_STMT
  _2 = _1 | 2097152;
  if (_2 != 2097152)
    goto <bb 6>; [48.88%]
  else
    goto <bb 13>; [51.12%]

  <bb 6> [local count: 131211251]:
  # DEBUG BEGIN_STMT
  Gmac_Ip_ProvideRxBuff (instance_16(D), channel_17(D), &bd);
  goto <bb 13>; [100.00%]

  <bb 7> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  rx_buff_process_handler.8_3 = rx_buff_process_handler;
  if (rx_buff_process_handler.8_3 == 0B)
    goto <bb 9>; [13.68%]
  else
    goto <bb 8>; [86.32%]

  <bb 8> [local count: 231713485]:
  _4 = rx_buff_process_handler.8_3 (instance_16(D), &bd);
  if (_4 != 0)
    goto <bb 9>; [27.00%]
  else
    goto <bb 13>; [73.00%]

  <bb 9> [local count: 99284611]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 12>; [100.00%]

  <bb 10> [local count: 59451863]:
  # DEBUG BEGIN_STMT
  _5 = netif_cfg[0];
  _6 = _5->num;
  if (_6 == instance_16(D))
    goto <bb 11>; [67.00%]
  else
    goto <bb 17>; [33.00%]

  <bb 11> [local count: 39832748]:
  # DEBUG BEGIN_STMT
  _7 = g_netif[0];
  _8 = bd.Data;
  _9 = bd.Length;
  gmacif_input (_7, _8, _9);
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 17> [local count: 19619115]:

  <bb 12> [local count: 118903726]:
  # i_10 = PHI <0(9), 1(17)>
  # DEBUG i => i_10
  # DEBUG BEGIN_STMT
  if (i_10 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 13> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Gmac_Ip_ProvideRxBuff (instance_16(D), channel_17(D), &bd);

  <bb 14> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (gmac_status_19 == 0)
    goto <bb 16>; [89.00%]
  else
    goto <bb 15>; [11.00%]

  <bb 16> [local count: 955630223]:
  goto <bb 3>; [100.00%]

  <bb 15> [local count: 118111601]:
  bd ={v} {CLOBBER};
  info ={v} {CLOBBER};
  return;

}



;; Function GmacIf_TxNotification (GmacIf_TxNotification, funcdef_no=12, decl_uid=8229, cgraph_uid=13, symbol_order=17)

Modification phase of node GmacIf_TxNotification/17
GmacIf_TxNotification (uint8 instance, uint8 channel)
{
  uint8_t i;
  int _1;
  struct pbuf * _2;
  struct pbuf * _3;
  void * _4;
  <unnamed type> _5;
  struct pbuf * _6;

  <bb 2> [local count: 178992764]:
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 894749062]:
  # DEBUG BEGIN_STMT
  _1 = (int) i_7;
  _2 ={v} tx_pbufs[_1];
  if (_2 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 4> [local count: 478422323]:
  # DEBUG BEGIN_STMT
  _3 ={v} tx_pbufs[_1];
  _4 = _3->payload;
  _5 = Gmac_Ip_GetTransmitStatus (instance_11(D), channel_12(D), _4, 0B);
  if (_5 != 2)
    goto <bb 5>; [48.88%]
  else
    goto <bb 6>; [51.12%]

  <bb 5> [local count: 233852832]:
  # DEBUG BEGIN_STMT
  _6 ={v} tx_pbufs[_1];
  pbuf_free (_6);
  # DEBUG BEGIN_STMT
  tx_pbufs[_1] ={v} 0B;

  <bb 6> [local count: 894749062]:
  # DEBUG BEGIN_STMT
  i_16 = i_7 + 1;
  # DEBUG i => i_16

  <bb 7> [local count: 1073741824]:
  # i_7 = PHI <0(2), i_16(6)>
  # DEBUG i => i_7
  # DEBUG BEGIN_STMT
  if (i_7 != 5)
    goto <bb 3>; [83.33%]
  else
    goto <bb 8>; [16.67%]

  <bb 8> [local count: 178992762]:
  return;

}


