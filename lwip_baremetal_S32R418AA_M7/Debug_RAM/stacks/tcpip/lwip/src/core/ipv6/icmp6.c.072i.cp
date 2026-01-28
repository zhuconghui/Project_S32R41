
IPA constant propagation start:
Determining dynamic type for call: icmp6_send_response_with_addrs_and_netif (p_11(D), code_12(D), data_13(D), type_14(D), dest_addr_8(D), src_addr_6(D), netif_10);
  Starting walk at: icmp6_send_response_with_addrs_and_netif (p_11(D), code_12(D), data_13(D), type_14(D), dest_addr_8(D), src_addr_6(D), netif_10);
  instance pointer: p_11(D)  Outer instance pointer: p_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_10 = ip6_route (dest_addr_8(D), src_addr_6(D));
Determining dynamic type for call: icmp6_send_response_with_addrs_and_netif (p_11(D), code_12(D), data_13(D), type_14(D), dest_addr_8(D), src_addr_6(D), netif_10);
  Starting walk at: icmp6_send_response_with_addrs_and_netif (p_11(D), code_12(D), data_13(D), type_14(D), dest_addr_8(D), src_addr_6(D), netif_10);
  instance pointer: dest_addr_8(D)  Outer instance pointer: dest_addr_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_10 = ip6_route (dest_addr_8(D), src_addr_6(D));
Determining dynamic type for call: icmp6_send_response_with_addrs_and_netif (p_11(D), code_12(D), data_13(D), type_14(D), dest_addr_8(D), src_addr_6(D), netif_10);
  Starting walk at: icmp6_send_response_with_addrs_and_netif (p_11(D), code_12(D), data_13(D), type_14(D), dest_addr_8(D), src_addr_6(D), netif_10);
  instance pointer: src_addr_6(D)  Outer instance pointer: src_addr_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_10 = ip6_route (dest_addr_8(D), src_addr_6(D));
Determining dynamic type for call: icmp6_send_response_with_addrs_and_netif (p_11(D), code_12(D), data_13(D), type_14(D), dest_addr_8(D), src_addr_6(D), netif_10);
  Starting walk at: icmp6_send_response_with_addrs_and_netif (p_11(D), code_12(D), data_13(D), type_14(D), dest_addr_8(D), src_addr_6(D), netif_10);
  instance pointer: netif_10  Outer instance pointer: netif_10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_10 = ip6_route (dest_addr_8(D), src_addr_6(D));
Determining dynamic type for call: icmp6_send_response_with_addrs_and_netif (p_8(D), code_9(D), data_10(D), type_11(D), reply_src_7, &ip_data.current_iphdr_src.u_addr.ip6, netif_4);
  Starting walk at: icmp6_send_response_with_addrs_and_netif (p_8(D), code_9(D), data_10(D), type_11(D), reply_src_7, &ip_data.current_iphdr_src.u_addr.ip6, netif_4);
  instance pointer: p_8(D)  Outer instance pointer: p_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ip6_select_source_address (netif_4, &ip_data.current_iphdr_src.u_addr.ip6);
Determining dynamic type for call: icmp6_send_response_with_addrs_and_netif (p_8(D), code_9(D), data_10(D), type_11(D), reply_src_7, &ip_data.current_iphdr_src.u_addr.ip6, netif_4);
  Starting walk at: icmp6_send_response_with_addrs_and_netif (p_8(D), code_9(D), data_10(D), type_11(D), reply_src_7, &ip_data.current_iphdr_src.u_addr.ip6, netif_4);
  instance pointer: reply_src_7  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ip6_select_source_address (netif_4, &ip_data.current_iphdr_src.u_addr.ip6);
Determining dynamic type for call: icmp6_send_response_with_addrs_and_netif (p_8(D), code_9(D), data_10(D), type_11(D), reply_src_7, &ip_data.current_iphdr_src.u_addr.ip6, netif_4);
  Starting walk at: icmp6_send_response_with_addrs_and_netif (p_8(D), code_9(D), data_10(D), type_11(D), reply_src_7, &ip_data.current_iphdr_src.u_addr.ip6, netif_4);
  instance pointer: &ip_data.current_iphdr_src.u_addr.ip6  Outer instance pointer: ip_data offset: 160 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ip6_select_source_address (netif_4, &ip_data.current_iphdr_src.u_addr.ip6);
Determining dynamic type for call: icmp6_send_response_with_addrs_and_netif (p_8(D), code_9(D), data_10(D), type_11(D), reply_src_7, &ip_data.current_iphdr_src.u_addr.ip6, netif_4);
  Starting walk at: icmp6_send_response_with_addrs_and_netif (p_8(D), code_9(D), data_10(D), type_11(D), reply_src_7, &ip_data.current_iphdr_src.u_addr.ip6, netif_4);
  instance pointer: netif_4  Outer instance pointer: netif_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ip6_select_source_address (netif_4, &ip_data.current_iphdr_src.u_addr.ip6);
Determining dynamic type for call: icmp6_send_response (p_6(D), c_7(D), pointer_u32_5, 4);
  Starting walk at: icmp6_send_response (p_6(D), c_7(D), pointer_u32_5, 4);
  instance pointer: p_6(D)  Outer instance pointer: p_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: icmp6_send_response_with_addrs (p_2(D), c_3(D), 0, 3, src_addr_4(D), dest_addr_5(D));
  Starting walk at: icmp6_send_response_with_addrs (p_2(D), c_3(D), 0, 3, src_addr_4(D), dest_addr_5(D));
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: icmp6_send_response_with_addrs (p_2(D), c_3(D), 0, 3, src_addr_4(D), dest_addr_5(D));
  Starting walk at: icmp6_send_response_with_addrs (p_2(D), c_3(D), 0, 3, src_addr_4(D), dest_addr_5(D));
  instance pointer: src_addr_4(D)  Outer instance pointer: src_addr_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: icmp6_send_response_with_addrs (p_2(D), c_3(D), 0, 3, src_addr_4(D), dest_addr_5(D));
  Starting walk at: icmp6_send_response_with_addrs (p_2(D), c_3(D), 0, 3, src_addr_4(D), dest_addr_5(D));
  instance pointer: dest_addr_5(D)  Outer instance pointer: dest_addr_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: icmp6_send_response (p_2(D), c_3(D), 0, 3);
  Starting walk at: icmp6_send_response (p_2(D), c_3(D), 0, 3);
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: icmp6_send_response (p_2(D), 0, mtu_3(D), 2);
  Starting walk at: icmp6_send_response (p_2(D), 0, mtu_3(D), 2);
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: icmp6_send_response (p_2(D), c_3(D), 0, 1);
  Starting walk at: icmp6_send_response (p_2(D), c_3(D), 0, 1);
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  icmp6_send_response.part.0/23:
  Jump functions of caller  ip6_route/22:
  Jump functions of caller  pbuf_take_at/21:
  Jump functions of caller  lwip_htonl/20:
  Jump functions of caller  ip6_select_source_address/19:
  Jump functions of caller  ip6_output_if/18:
  Jump functions of caller  pbuf_copy/17:
  Jump functions of caller  pbuf_alloc/16:
  Jump functions of caller  mld6_input/15:
  Jump functions of caller  nd6_input/14:
  Jump functions of caller  ip6_chksum_pseudo/12:
  Jump functions of caller  pbuf_free/11:
  Jump functions of caller  icmp6_send_response_with_addrs_and_netif/9:
  Jump functions of caller  icmp6_send_response_with_addrs/8:
    callsite  icmp6_send_response_with_addrs/8 -> icmp6_send_response_with_addrs_and_netif/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  icmp6_send_response/7:
    callsite  icmp6_send_response/7 -> icmp6_send_response_with_addrs_and_netif/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: CONST: &ip_data.current_iphdr_src.u_addr.ip6
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 6: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  icmp6_send_response/7 -> icmp6_send_response.part.0/23 : 
  Jump functions of caller  icmp6_param_problem/6:
    callsite  icmp6_param_problem/6 -> icmp6_send_response/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
  Jump functions of caller  icmp6_time_exceeded_with_addrs/5:
    callsite  icmp6_time_exceeded_with_addrs/5 -> icmp6_send_response_with_addrs/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  icmp6_time_exceeded/4:
    callsite  icmp6_time_exceeded/4 -> icmp6_send_response/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
  Jump functions of caller  icmp6_packet_too_big/3:
    callsite  icmp6_packet_too_big/3 -> icmp6_send_response/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
  Jump functions of caller  icmp6_dest_unreach/2:
    callsite  icmp6_dest_unreach/2 -> icmp6_send_response/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  icmp6_input/1:

 Propagating constants:

Not considering icmp6_param_problem for cloning; -fipa-cp-clone disabled.
Not considering icmp6_time_exceeded_with_addrs for cloning; -fipa-cp-clone disabled.
Not considering icmp6_time_exceeded for cloning; -fipa-cp-clone disabled.
Not considering icmp6_packet_too_big for cloning; -fipa-cp-clone disabled.
Not considering icmp6_dest_unreach for cloning; -fipa-cp-clone disabled.
Not considering icmp6_input for cloning; -fipa-cp-clone disabled.

overall_size: 293, max_new_size: 11001
 - context independent values, size: 26, time_benefit: 2.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: icmp6_send_response.part.0/23:
  Node: icmp6_send_response_with_addrs_and_netif/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 1, loc_size: 69, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
               0 [loc_time: 1, loc_size: 69, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: 4 [loc_time: 1, loc_size: 69, prop_time: 0, prop_size: 0]
               2 [loc_time: 1, loc_size: 69, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 69, prop_time: 0, prop_size: 0]
               3 [loc_time: 1, loc_size: 69, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x3, mask = 0x7
         u8_t [1, 4]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [5]: VARIABLE
               &ip_data.current_iphdr_src.u_addr.ip6 [loc_time: 1, loc_size: 69, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [6]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: icmp6_send_response_with_addrs/8:
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
    param [2]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         u32_t [0, 0]
        AGGS VARIABLE
    param [3]: 3 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x3, mask = 0x0
         u8_t [3, 3]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [5]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: icmp6_send_response/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 1, loc_size: 23, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
               0 [loc_time: 1, loc_size: 23, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: 1 [loc_time: 1, loc_size: 23, prop_time: 0, prop_size: 0]
               2 [loc_time: 1, loc_size: 23, prop_time: 0, prop_size: 0]
               3 [loc_time: 1, loc_size: 23, prop_time: 0, prop_size: 0]
               4 [loc_time: 1, loc_size: 23, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x4, mask = 0x7
         u8_t [1, 4]
        AGGS VARIABLE
  Node: icmp6_param_problem/6:
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
  Node: icmp6_time_exceeded_with_addrs/5:
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
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: icmp6_time_exceeded/4:
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
  Node: icmp6_packet_too_big/3:
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
  Node: icmp6_dest_unreach/2:
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
  Node: icmp6_input/1:
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

 - Creating a specialized node of icmp6_send_response_with_addrs/8 for all known contexts.
    replacing param #2 data with const 0
    replacing param #3 type with const 3
Propagated bits info for function icmp6_send_response_with_addrs.constprop/24:
 param 2: value = 0x0, mask = 0x0
 param 3: value = 0x3, mask = 0x0
Propagated bits info for function icmp6_send_response_with_addrs_and_netif/9:
 param 3: value = 0x3, mask = 0x7
Propagated bits info for function icmp6_send_response_with_addrs/8:
 param 2: value = 0x0, mask = 0x0
 param 3: value = 0x3, mask = 0x0
Propagated bits info for function icmp6_send_response/7:
 param 3: value = 0x4, mask = 0x7

IPA constant propagation end

Reclaiming functions: icmp6_send_response_with_addrs/8
Reclaiming variables:
Clearing address taken flags:
Symbol table:

icmp6_send_response_with_addrs.constprop.0/24 (icmp6_send_response_with_addrs.constprop) @0618ba80
  Type: function definition analyzed
  Visibility:
  References: lwip_stats/10 (read)lwip_stats/10 (write)
  Referring: 
  Clone of icmp6_send_response_with_addrs/8
  Availability: local
  Function flags: count:329661 (estimated locally) local optimize_size
  Called by: icmp6_time_exceeded_with_addrs/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: ip6_route/22 (123389 (estimated locally),0.37 per call) icmp6_send_response_with_addrs_and_netif/9 (85200 (estimated locally),0.26 per call) 
icmp6_send_response.part.0/23 (icmp6_send_response.part.0) @05f5e8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwip_stats/10 (read)lwip_stats/10 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: icmp6_send_response/7 (38189 (estimated locally),0.17 per call) 
  Calls: 
ip6_route/22 (ip6_route) @06119700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_send_response_with_addrs.constprop/24 (123389 (estimated locally),0.37 per call) 
  Calls: 
pbuf_take_at/21 (pbuf_take_at) @061192a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_send_response_with_addrs_and_netif/9 (463811 (estimated locally),2.37 per call) 
  Calls: 
lwip_htonl/20 (lwip_htonl) @061191c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_send_response_with_addrs_and_netif/9 (52886 (estimated locally),0.27 per call) 
  Calls: 
ip6_select_source_address/19 (ip6_select_source_address) @06119000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_send_response/7 (123389 (estimated locally),0.53 per call) 
  Calls: 
ip6_output_if/18 (ip6_output_if) @0610a000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_input/1 (48298294 (estimated locally),0.04 per call) icmp6_send_response_with_addrs_and_netif/9 (52886 (estimated locally),0.27 per call) 
  Calls: 
pbuf_copy/17 (pbuf_copy) @0610aee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_input/1 (73179233 (estimated locally),0.07 per call) 
  Calls: 
pbuf_alloc/16 (pbuf_alloc) @0610ae00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_input/1 (89341024 (estimated locally),0.08 per call) icmp6_send_response_with_addrs_and_netif/9 (195653 (estimated locally),1.00 per call) 
  Calls: 
mld6_input/15 (mld6_input) @0610ad20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_input/1 (113046975 (estimated locally),0.11 per call) 
  Calls: 
nd6_input/14 (nd6_input) @0610ac40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_input/1 (113046975 (estimated locally),0.11 per call) 
  Calls: 
ip_data/13 (ip_data) @06113708
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: icmp6_send_response/7 (addr)icmp6_send_response/7 (addr)icmp6_input/1 (addr)icmp6_send_response/7 (read)icmp6_input/1 (addr)icmp6_input/1 (addr)icmp6_input/1 (read)icmp6_input/1 (addr)icmp6_input/1 (addr)icmp6_input/1 (addr)icmp6_param_problem/6 (read)
  Availability: not_available
  Varpool flags:
ip6_chksum_pseudo/12 (ip6_chksum_pseudo) @0610ab60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_input/1 (48298294 (estimated locally),0.04 per call) icmp6_input/1 (708669604 (estimated locally),0.66 per call) icmp6_send_response_with_addrs_and_netif/9 (52886 (estimated locally),0.27 per call) 
  Calls: 
pbuf_free/11 (pbuf_free) @0610a9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: icmp6_input/1 (274392244 (estimated locally),0.26 per call) icmp6_input/1 (48298294 (estimated locally),0.04 per call) icmp6_input/1 (24880939 (estimated locally),0.02 per call) icmp6_input/1 (24880939 (estimated locally),0.02 per call) icmp6_input/1 (16161791 (estimated locally),0.02 per call) icmp6_input/1 (23705951 (estimated locally),0.02 per call) icmp6_input/1 (143434728 (estimated locally),0.13 per call) icmp6_input/1 (365072220 (estimated locally),0.34 per call) icmp6_send_response_with_addrs_and_netif/9 (52886 (estimated locally),0.27 per call) 
  Calls: 
lwip_stats/10 (lwip_stats) @06113630
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: icmp6_send_response_with_addrs_and_netif/9 (read)icmp6_send_response_with_addrs_and_netif/9 (write)icmp6_send_response_with_addrs_and_netif/9 (read)icmp6_send_response_with_addrs_and_netif/9 (write)icmp6_send_response.part.0/23 (read)icmp6_send_response.part.0/23 (write)icmp6_send_response_with_addrs.constprop.0/24 (read)icmp6_send_response_with_addrs.constprop.0/24 (write)icmp6_input/1 (read)icmp6_input/1 (write)icmp6_input/1 (read)icmp6_input/1 (write)icmp6_input/1 (read)icmp6_input/1 (write)icmp6_input/1 (read)icmp6_input/1 (write)icmp6_input/1 (read)icmp6_input/1 (write)icmp6_input/1 (read)icmp6_input/1 (write)icmp6_input/1 (read)icmp6_input/1 (write)icmp6_input/1 (read)icmp6_input/1 (write)icmp6_input/1 (read)icmp6_input/1 (write)icmp6_input/1 (read)icmp6_input/1 (write)icmp6_input/1 (read)icmp6_input/1 (write)
  Availability: not_available
  Varpool flags:
icmp6_send_response_with_addrs_and_netif/9 (icmp6_send_response_with_addrs_and_netif) @0610a460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: lwip_stats/10 (read)lwip_stats/10 (write)lwip_stats/10 (read)lwip_stats/10 (write)
  Referring: 
  Availability: local
  Function flags: count:195653 (estimated locally) body local optimize_size
  Called by: icmp6_send_response_with_addrs.constprop/24 (85200 (estimated locally),0.26 per call) icmp6_send_response/7 (85200 (estimated locally),0.37 per call) 
  Calls: pbuf_free/11 (52886 (estimated locally),0.27 per call) ip6_output_if/18 (52886 (estimated locally),0.27 per call) ip6_chksum_pseudo/12 (52886 (estimated locally),0.27 per call) pbuf_take_at/21 (463811 (estimated locally),2.37 per call) lwip_htonl/20 (52886 (estimated locally),0.27 per call) pbuf_alloc/16 (195653 (estimated locally),1.00 per call) 
icmp6_send_response_with_addrs/8 (icmp6_send_response_with_addrs) @0610a1c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:329661 (estimated locally) body optimize_size
  Called by: 
  Calls: 
icmp6_send_response/7 (icmp6_send_response) @06105e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ip_data/13 (read)ip_data/13 (addr)ip_data/13 (addr)
  Referring: 
  Availability: local
  Function flags: count:230763 (estimated locally) body local optimize_size
  Called by: icmp6_param_problem/6 (1073741824 (estimated locally),1.00 per call) icmp6_time_exceeded/4 (1073741824 (estimated locally),1.00 per call) icmp6_packet_too_big/3 (1073741824 (estimated locally),1.00 per call) icmp6_dest_unreach/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: icmp6_send_response_with_addrs_and_netif/9 (85200 (estimated locally),0.37 per call) icmp6_send_response.part.0/23 (38189 (estimated locally),0.17 per call) ip6_select_source_address/19 (123389 (estimated locally),0.53 per call) 
icmp6_param_problem/6 (icmp6_param_problem) @06105380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_data/13 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: icmp6_send_response/7 (1073741824 (estimated locally),1.00 per call) 
icmp6_time_exceeded_with_addrs/5 (icmp6_time_exceeded_with_addrs) @06105d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: icmp6_send_response_with_addrs.constprop/24 (1073741824 (estimated locally),1.00 per call) 
icmp6_time_exceeded/4 (icmp6_time_exceeded) @06105a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: icmp6_send_response/7 (1073741824 (estimated locally),1.00 per call) 
icmp6_packet_too_big/3 (icmp6_packet_too_big) @061057e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: icmp6_send_response/7 (1073741824 (estimated locally),1.00 per call) 
icmp6_dest_unreach/2 (icmp6_dest_unreach) @06105540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: icmp6_send_response/7 (1073741824 (estimated locally),1.00 per call) 
icmp6_input/1 (icmp6_input) @061052a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/10 (read)lwip_stats/10 (write)lwip_stats/10 (read)lwip_stats/10 (write)lwip_stats/10 (read)lwip_stats/10 (write)ip_data/13 (addr)ip_data/13 (addr)lwip_stats/10 (read)lwip_stats/10 (write)lwip_stats/10 (read)lwip_stats/10 (write)ip_data/13 (read)lwip_stats/10 (read)lwip_stats/10 (write)lwip_stats/10 (read)lwip_stats/10 (write)lwip_stats/10 (read)lwip_stats/10 (write)ip_data/13 (addr)ip_data/13 (addr)lwip_stats/10 (read)lwip_stats/10 (write)ip_data/13 (addr)ip_data/13 (addr)lwip_stats/10 (read)lwip_stats/10 (write)lwip_stats/10 (read)lwip_stats/10 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/11 (274392244 (estimated locally),0.26 per call) pbuf_free/11 (48298294 (estimated locally),0.04 per call) ip6_output_if/18 (48298294 (estimated locally),0.04 per call) ip6_chksum_pseudo/12 (48298294 (estimated locally),0.04 per call) pbuf_free/11 (24880939 (estimated locally),0.02 per call) pbuf_free/11 (24880939 (estimated locally),0.02 per call) pbuf_copy/17 (73179233 (estimated locally),0.07 per call) pbuf_free/11 (16161791 (estimated locally),0.02 per call) pbuf_alloc/16 (89341024 (estimated locally),0.08 per call) pbuf_free/11 (23705951 (estimated locally),0.02 per call) mld6_input/15 (113046975 (estimated locally),0.11 per call) nd6_input/14 (113046975 (estimated locally),0.11 per call) pbuf_free/11 (143434728 (estimated locally),0.13 per call) ip6_chksum_pseudo/12 (708669604 (estimated locally),0.66 per call) pbuf_free/11 (365072220 (estimated locally),0.34 per call) 

;; Function icmp6_send_response_with_addrs_and_netif (icmp6_send_response_with_addrs_and_netif, funcdef_no=9, decl_uid=7235, cgraph_uid=10, symbol_order=9)

Modification phase of node icmp6_send_response_with_addrs_and_netif/9
Adjusting mask for param 3 to 0x7
Setting value range of param 3 [1, 4]
icmp6_send_response_with_addrs_and_netif (struct pbuf * p, u8_t code, u32_t data, u8_t type, const struct ip6_addr_t * reply_src, const struct ip6_addr_t * reply_dest, struct netif * netif)
{
  err_t res;
  u16_t len;
  u16_t offset;
  u16_t datalen;
  struct icmp6_hdr * icmp6hdr;
  struct pbuf * q;
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  long unsigned int _6;
  short unsigned int _7;
  void * _8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;

  <bb 2> [local count: 195653]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_21(D)->tot_len;
  datalen_22 = MIN_EXPR <_1, 1232>;
  # DEBUG datalen => datalen_22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = datalen_22 + 8;
  q_24 = pbuf_alloc (54, _2, 640);
  # DEBUG q => q_24
  # DEBUG BEGIN_STMT
  if (q_24 == 0B)
    goto <bb 3>; [18.09%]
  else
    goto <bb 4>; [81.91%]

  <bb 3> [local count: 35394]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = lwip_stats.icmp6.memerr;
  _4 = _3 + 1;
  lwip_stats.icmp6.memerr = _4;
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 4> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = q_24->len;
  if (_5 <= 7)
    goto <bb 13>; [67.00%]
  else
    goto <bb 6>; [33.00%]

  <bb 13> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  icmp6hdr_25 = q_24->payload;
  # DEBUG icmp6hdr => icmp6hdr_25
  # DEBUG BEGIN_STMT
  icmp6hdr_25->type = type_26(D);
  # DEBUG BEGIN_STMT
  icmp6hdr_25->code = code_28(D);
  # DEBUG BEGIN_STMT
  _6 = lwip_htonl (data_30(D));
  icmp6hdr_25->data = _6;
  # DEBUG BEGIN_STMT
  # DEBUG offset => 8
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 463811]:
  # DEBUG BEGIN_STMT
  _7 = p_13->len;
  len_33 = MIN_EXPR <_7, datalen_14>;
  # DEBUG len => len_33
  # DEBUG BEGIN_STMT
  _8 = p_13->payload;
  res_35 = pbuf_take_at (q_24, _8, len_33, offset_15);
  # DEBUG res => res_35
  # DEBUG BEGIN_STMT
  if (res_35 != 0)
    goto <bb 11>; [3.66%]
  else
    goto <bb 8>; [96.34%]

  <bb 8> [local count: 446836]:
  # DEBUG BEGIN_STMT
  datalen_36 = datalen_14 - len_33;
  # DEBUG datalen => datalen_36
  # DEBUG BEGIN_STMT
  offset_37 = offset_15 + len_33;
  # DEBUG offset => offset_37
  # DEBUG BEGIN_STMT
  p_38 = p_13->next;
  # DEBUG p => p_38

  <bb 9> [local count: 499722]:
  # p_13 = PHI <p_21(D)(6), p_38(8)>
  # datalen_14 = PHI <datalen_22(6), datalen_36(8)>
  # offset_15 = PHI <8(6), offset_37(8)>
  # DEBUG offset => offset_15
  # DEBUG datalen => datalen_14
  # DEBUG p => p_13
  # DEBUG BEGIN_STMT
  if (p_13 != 0B)
    goto <bb 10>; [96.34%]
  else
    goto <bb 11>; [3.66%]

  <bb 10> [local count: 481432]:
  if (datalen_14 != 0)
    goto <bb 7>; [96.34%]
  else
    goto <bb 11>; [3.66%]

  <bb 11> [local count: 52886]:
  # DEBUG BEGIN_STMT
  icmp6hdr_25->chksum = 0;
  # DEBUG BEGIN_STMT
  _9 = q_24->tot_len;
  _10 = ip6_chksum_pseudo (q_24, 58, _9, reply_src_40(D), reply_dest_41(D));
  icmp6hdr_25->chksum = _10;
  # DEBUG BEGIN_STMT
  _11 = lwip_stats.icmp6.xmit;
  _12 = _11 + 1;
  lwip_stats.icmp6.xmit = _12;
  # DEBUG BEGIN_STMT
  ip6_output_if (q_24, reply_src_40(D), reply_dest_41(D), 255, 0, 58, netif_45(D));
  # DEBUG BEGIN_STMT
  pbuf_free (q_24);

  <bb 12> [local count: 88279]:
  return;

}



;; Function icmp6_send_response (icmp6_send_response, funcdef_no=7, decl_uid=7220, cgraph_uid=8, symbol_order=7)

Modification phase of node icmp6_send_response/7
Adjusting mask for param 3 to 0x7
Setting value range of param 3 [1, 4]
icmp6_send_response (struct pbuf * p, u8_t code, u32_t data, u8_t type)
{
  struct netif * netif;
  const struct ip6_addr * reply_src;
  const struct ip_addr_t * _1;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_4 = ip_data.current_netif;
  # DEBUG netif => netif_4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_4 == 0B)
    goto <bb 8>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 8> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG reply_dest => &ip_data.current_iphdr_src.u_addr.ip6
  # DEBUG BEGIN_STMT
  _1 = ip6_select_source_address (netif_4, &ip_data.current_iphdr_src.u_addr.ip6);
  reply_src_7 = &_1->u_addr.ip6;
  # DEBUG reply_src => reply_src_7
  # DEBUG BEGIN_STMT
  if (reply_src_7 == 0B)
    goto <bb 5>; [30.95%]
  else
    goto <bb 6>; [69.05%]

  <bb 5> [local count: 38189]:
  # DEBUG D#1 => p_8(D)
  # DEBUG D#2 => code_9(D)
  # DEBUG D#3 => data_10(D)
  # DEBUG D#4 => type_11(D)
  icmp6_send_response.part.0 ();
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 85200]:
  # DEBUG BEGIN_STMT
  icmp6_send_response_with_addrs_and_netif (p_8(D), code_9(D), data_10(D), type_11(D), reply_src_7, &ip_data.current_iphdr_src.u_addr.ip6, netif_4);

  <bb 7> [local count: 123389]:
  return;

}



;; Function icmp6_input (icmp6_input, funcdef_no=1, decl_uid=6860, cgraph_uid=2, symbol_order=1)

Modification phase of node icmp6_input/1
icmp6_input (struct pbuf * p, struct netif * inp)
{
  struct pbuf * r;
  struct icmp6_hdr * icmp6hdr;
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  short unsigned int _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  short unsigned int _13;
  unsigned char _14;
  long unsigned int _15;
  long unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int _21;
  signed char _22;
  short unsigned int _23;
  short unsigned int _24;
  void * _25;
  short unsigned int _26;
  short unsigned int _27;
  short unsigned int _28;
  short unsigned int _29;
  short unsigned int _30;
  short unsigned int _31;
  short unsigned int _32;
  short unsigned int _33;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = lwip_stats.icmp6.recv;
  _2 = _1 + 1;
  lwip_stats.icmp6.recv = _2;
  # DEBUG BEGIN_STMT
  _3 = p_38(D)->len;
  if (_3 <= 7)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_38(D));
  # DEBUG BEGIN_STMT
  _4 = lwip_stats.icmp6.lenerr;
  _5 = _4 + 1;
  lwip_stats.icmp6.lenerr = _5;
  # DEBUG BEGIN_STMT
  _6 = lwip_stats.icmp6.drop;
  _7 = _6 + 1;
  lwip_stats.icmp6.drop = _7;
  # DEBUG BEGIN_STMT
  goto <bb 18>; [100.00%]

  <bb 4> [local count: 708669604]:
  # DEBUG BEGIN_STMT
  icmp6hdr_39 = p_38(D)->payload;
  # DEBUG icmp6hdr => icmp6hdr_39
  # DEBUG BEGIN_STMT
  _8 = p_38(D)->tot_len;
  _9 = ip6_chksum_pseudo (p_38(D), 58, _8, &ip_data.current_iphdr_src.u_addr.ip6, &ip_data.current_iphdr_dest.u_addr.ip6);
  if (_9 != 0)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 143434728]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_38(D));
  # DEBUG BEGIN_STMT
  _10 = lwip_stats.icmp6.chkerr;
  _11 = _10 + 1;
  lwip_stats.icmp6.chkerr = _11;
  # DEBUG BEGIN_STMT
  _12 = lwip_stats.icmp6.drop;
  _13 = _12 + 1;
  lwip_stats.icmp6.drop = _13;
  # DEBUG BEGIN_STMT
  goto <bb 18>; [100.00%]

  <bb 6> [local count: 565234876]:
  # DEBUG BEGIN_STMT
  _14 = icmp6hdr_39->type;
  switch (_14) <default: <L20> [20.00%], case 2: <L4> [20.00%], case 128: <L13> [20.00%], case 130 ... 132: <L10> [20.00%], case 133: <L23> [20.00%], case 134 ... 137: <L4> [20.00%]>

  <bb 7> [local count: 113046975]:
<L4>:
  # DEBUG BEGIN_STMT
  nd6_input (p_38(D), inp_41(D));
  # DEBUG BEGIN_STMT
  goto <bb 18>; [100.00%]

  <bb 8> [local count: 113046975]:
<L10>:
  # DEBUG BEGIN_STMT
  mld6_input (p_38(D), inp_41(D));
  # DEBUG BEGIN_STMT
  goto <bb 18>; [100.00%]

  <bb 9> [local count: 113046975]:
<L13>:
  # DEBUG BEGIN_STMT
  _15 = ip_data.current_iphdr_dest.u_addr.ip6.addr[0];
  _16 = _15 & 255;
  if (_16 == 255)
    goto <bb 10>; [20.97%]
  else
    goto <bb 11>; [79.03%]

  <bb 10> [local count: 23705951]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_38(D));
  # DEBUG BEGIN_STMT
  _17 = lwip_stats.icmp6.drop;
  _18 = _17 + 1;
  lwip_stats.icmp6.drop = _18;
  # DEBUG BEGIN_STMT
  goto <bb 18>; [100.00%]

  <bb 11> [local count: 89341024]:
  # DEBUG BEGIN_STMT
  _19 = p_38(D)->tot_len;
  r_44 = pbuf_alloc (54, _19, 640);
  # DEBUG r => r_44
  # DEBUG BEGIN_STMT
  if (r_44 == 0B)
    goto <bb 12>; [18.09%]
  else
    goto <bb 13>; [81.91%]

  <bb 12> [local count: 16161791]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_38(D));
  # DEBUG BEGIN_STMT
  _20 = lwip_stats.icmp6.memerr;
  _21 = _20 + 1;
  lwip_stats.icmp6.memerr = _21;
  # DEBUG BEGIN_STMT
  goto <bb 18>; [100.00%]

  <bb 13> [local count: 73179233]:
  # DEBUG BEGIN_STMT
  _22 = pbuf_copy (r_44, p_38(D));
  if (_22 != 0)
    goto <bb 14>; [34.00%]
  else
    goto <bb 15>; [66.00%]

  <bb 14> [local count: 24880939]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_38(D));
  # DEBUG BEGIN_STMT
  pbuf_free (r_44);
  # DEBUG BEGIN_STMT
  _23 = lwip_stats.icmp6.err;
  _24 = _23 + 1;
  lwip_stats.icmp6.err = _24;
  # DEBUG BEGIN_STMT
  goto <bb 18>; [100.00%]

  <bb 15> [local count: 48298294]:
  # DEBUG BEGIN_STMT
  # DEBUG reply_src => &ip_data.current_iphdr_dest.u_addr.ip6
  # DEBUG BEGIN_STMT
  _25 = r_44->payload;
  MEM[(struct icmp6_echo_hdr *)_25].type = 129;
  # DEBUG BEGIN_STMT
  MEM[(struct icmp6_echo_hdr *)_25].chksum = 0;
  # DEBUG BEGIN_STMT
  _26 = r_44->tot_len;
  _27 = ip6_chksum_pseudo (r_44, 58, _26, &ip_data.current_iphdr_dest.u_addr.ip6, &ip_data.current_iphdr_src.u_addr.ip6);
  MEM[(struct icmp6_echo_hdr *)_25].chksum = _27;
  # DEBUG BEGIN_STMT
  _28 = lwip_stats.icmp6.xmit;
  _29 = _28 + 1;
  lwip_stats.icmp6.xmit = _29;
  # DEBUG BEGIN_STMT
  ip6_output_if (r_44, &ip_data.current_iphdr_dest.u_addr.ip6, &ip_data.current_iphdr_src.u_addr.ip6, 255, 0, 58, inp_41(D));
  # DEBUG BEGIN_STMT
  pbuf_free (r_44);
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 16> [local count: 113046975]:
<L20>:
  # DEBUG BEGIN_STMT
  _30 = lwip_stats.icmp6.proterr;
  _31 = _30 + 1;
  lwip_stats.icmp6.proterr = _31;
  # DEBUG BEGIN_STMT
  _32 = lwip_stats.icmp6.drop;
  _33 = _32 + 1;
  lwip_stats.icmp6.drop = _33;
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 274392244]:
<L23>:
  # DEBUG BEGIN_STMT
  pbuf_free (p_38(D));

  <bb 18> [local count: 1073741824]:
  return;

}



;; Function icmp6_dest_unreach (icmp6_dest_unreach, funcdef_no=2, decl_uid=6863, cgraph_uid=3, symbol_order=2)

Modification phase of node icmp6_dest_unreach/2
icmp6_dest_unreach (struct pbuf * p, icmp6_dur_code c)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  icmp6_send_response (p_2(D), c_3(D), 0, 1);
  return;

}



;; Function icmp6_packet_too_big (icmp6_packet_too_big, funcdef_no=3, decl_uid=6866, cgraph_uid=4, symbol_order=3)

Modification phase of node icmp6_packet_too_big/3
icmp6_packet_too_big (struct pbuf * p, u32_t mtu)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  icmp6_send_response (p_2(D), 0, mtu_3(D), 2);
  return;

}



;; Function icmp6_time_exceeded (icmp6_time_exceeded, funcdef_no=4, decl_uid=6869, cgraph_uid=5, symbol_order=4)

Modification phase of node icmp6_time_exceeded/4
icmp6_time_exceeded (struct pbuf * p, icmp6_te_code c)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  icmp6_send_response (p_2(D), c_3(D), 0, 3);
  return;

}



;; Function icmp6_time_exceeded_with_addrs (icmp6_time_exceeded_with_addrs, funcdef_no=5, decl_uid=6874, cgraph_uid=6, symbol_order=5)

Modification phase of node icmp6_time_exceeded_with_addrs/5
icmp6_time_exceeded_with_addrs (struct pbuf * p, icmp6_te_code c, const struct ip6_addr_t * src_addr, const struct ip6_addr_t * dest_addr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  icmp6_send_response_with_addrs (p_2(D), c_3(D), 0, 3, src_addr_4(D), dest_addr_5(D));
  return;

}



;; Function icmp6_param_problem (icmp6_param_problem, funcdef_no=6, decl_uid=6878, cgraph_uid=7, symbol_order=6)

Modification phase of node icmp6_param_problem/6
icmp6_param_problem (struct pbuf * p, icmp6_pp_code c, const void * pointer)
{
  u32_t pointer_u32;
  struct ip6_hdr * _1;
  int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = ip_data.current_ip6_header;
  _2 = pointer_4(D) - _1;
  pointer_u32_5 = (u32_t) _2;
  # DEBUG pointer_u32 => pointer_u32_5
  # DEBUG BEGIN_STMT
  icmp6_send_response (p_6(D), c_7(D), pointer_u32_5, 4);
  return;

}


