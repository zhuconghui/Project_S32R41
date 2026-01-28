
IPA constant propagation start:
Determining dynamic type for call: err_29 = udp_bind (pcb_25(D), _2, 0);
  Starting walk at: err_29 = udp_bind (pcb_25(D), _2, 0);
  instance pointer: pcb_25(D)  Outer instance pointer: pcb_25(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_29 = udp_bind (pcb_25(D), _2, 0);
  Starting walk at: err_29 = udp_bind (pcb_25(D), _2, 0);
  instance pointer: _2  Outer instance pointer: pcb_25(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_65 = udp_bind (pcb_57(D), _5, 0);
  Starting walk at: err_65 = udp_bind (pcb_57(D), _5, 0);
  instance pointer: pcb_57(D)  Outer instance pointer: pcb_57(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_65 = udp_bind (pcb_57(D), _5, 0);
  Starting walk at: err_65 = udp_bind (pcb_57(D), _5, 0);
  instance pointer: _5  Outer instance pointer: pcb_57(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);
  Starting walk at: _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);
  instance pointer: pcb_19(D)  Outer instance pointer: pcb_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_11 = netif_get_ip6_addr_match (netif_22(D), _4);
  Function call may change dynamic type:src_ip_27 = ip6_select_source_address (netif_22(D), _10);
Determining dynamic type for call: _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);
  Starting walk at: _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);
  instance pointer: p_20(D)  Outer instance pointer: p_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_11 = netif_get_ip6_addr_match (netif_22(D), _4);
  Function call may change dynamic type:src_ip_27 = ip6_select_source_address (netif_22(D), _10);
Determining dynamic type for call: _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);
  Starting walk at: _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);
  instance pointer: dst_ip_21(D)  Outer instance pointer: dst_ip_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_11 = netif_get_ip6_addr_match (netif_22(D), _4);
  Function call may change dynamic type:src_ip_27 = ip6_select_source_address (netif_22(D), _10);
Determining dynamic type for call: _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);
  Starting walk at: _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);
  instance pointer: netif_22(D)  Outer instance pointer: netif_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_11 = netif_get_ip6_addr_match (netif_22(D), _4);
  Function call may change dynamic type:src_ip_27 = ip6_select_source_address (netif_22(D), _10);
Determining dynamic type for call: _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);
  Starting walk at: _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);
  instance pointer: src_ip_15  Outer instance pointer: src_ip_15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_11 = netif_get_ip6_addr_match (netif_22(D), _4);
  Function call may change dynamic type:src_ip_27 = ip6_select_source_address (netif_22(D), _10);
Determining dynamic type for call: _45 = udp_sendto_if (pcb_27(D), p_28(D), dst_ip_29(D), dst_port_43(D), netif_21);
  Starting walk at: _45 = udp_sendto_if (pcb_27(D), p_28(D), dst_ip_29(D), dst_port_43(D), netif_21);
  instance pointer: pcb_27(D)  Outer instance pointer: pcb_27(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_42 = netif_get_by_index (_3);
  Function call may change dynamic type:netif_34 = ip4_route (_13);
  Function call may change dynamic type:netif_36 = netif_get_by_index (_9);
  Function call may change dynamic type:iftmp.9_40 = ip4_route (_17);
  Function call may change dynamic type:iftmp.9_38 = ip6_route (_15, _16);
Determining dynamic type for call: _45 = udp_sendto_if (pcb_27(D), p_28(D), dst_ip_29(D), dst_port_43(D), netif_21);
  Starting walk at: _45 = udp_sendto_if (pcb_27(D), p_28(D), dst_ip_29(D), dst_port_43(D), netif_21);
  instance pointer: p_28(D)  Outer instance pointer: p_28(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_42 = netif_get_by_index (_3);
  Function call may change dynamic type:netif_34 = ip4_route (_13);
  Function call may change dynamic type:netif_36 = netif_get_by_index (_9);
  Function call may change dynamic type:iftmp.9_40 = ip4_route (_17);
  Function call may change dynamic type:iftmp.9_38 = ip6_route (_15, _16);
Determining dynamic type for call: _45 = udp_sendto_if (pcb_27(D), p_28(D), dst_ip_29(D), dst_port_43(D), netif_21);
  Starting walk at: _45 = udp_sendto_if (pcb_27(D), p_28(D), dst_ip_29(D), dst_port_43(D), netif_21);
  instance pointer: dst_ip_29(D)  Outer instance pointer: dst_ip_29(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_42 = netif_get_by_index (_3);
  Function call may change dynamic type:netif_34 = ip4_route (_13);
  Function call may change dynamic type:netif_36 = netif_get_by_index (_9);
  Function call may change dynamic type:iftmp.9_40 = ip4_route (_17);
  Function call may change dynamic type:iftmp.9_38 = ip6_route (_15, _16);
Determining dynamic type for call: _45 = udp_sendto_if (pcb_27(D), p_28(D), dst_ip_29(D), dst_port_43(D), netif_21);
  Starting walk at: _45 = udp_sendto_if (pcb_27(D), p_28(D), dst_ip_29(D), dst_port_43(D), netif_21);
  instance pointer: netif_21  Outer instance pointer: netif_21 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_42 = netif_get_by_index (_3);
  Function call may change dynamic type:netif_34 = ip4_route (_13);
  Function call may change dynamic type:netif_36 = netif_get_by_index (_9);
  Function call may change dynamic type:iftmp.9_40 = ip4_route (_17);
  Function call may change dynamic type:iftmp.9_38 = ip6_route (_15, _16);
Determining dynamic type for call: _10 = udp_sendto (pcb_6(D), p_7(D), _2, _3);
  Starting walk at: _10 = udp_sendto (pcb_6(D), p_7(D), _2, _3);
  instance pointer: pcb_6(D)  Outer instance pointer: pcb_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = udp_sendto (pcb_6(D), p_7(D), _2, _3);
  Starting walk at: _10 = udp_sendto (pcb_6(D), p_7(D), _2, _3);
  instance pointer: p_7(D)  Outer instance pointer: p_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = udp_sendto (pcb_6(D), p_7(D), _2, _3);
  Starting walk at: _10 = udp_sendto (pcb_6(D), p_7(D), _2, _3);
  instance pointer: _2  Outer instance pointer: pcb_6(D) offset: 192 (bits) vtbl reference: 
Determining dynamic type for call: _16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
  Starting walk at: _16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
  instance pointer: pcb_62  Outer instance pointer: pcb_62 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dest_115 = lwip_htons (_14);
  Function call may change dynamic type:src_113 = lwip_htons (_13);
  Function call may change dynamic type:iftmp.0_111 = ip4_addr_isbroadcast_u32 (_11, _12);
  Function call may change dynamic type:_16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
Determining dynamic type for call: _16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
  Starting walk at: _16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
  instance pointer: inp_107(D)  Outer instance pointer: inp_107(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dest_115 = lwip_htons (_14);
  Function call may change dynamic type:src_113 = lwip_htons (_13);
  Function call may change dynamic type:iftmp.0_111 = ip4_addr_isbroadcast_u32 (_11, _12);
  Function call may change dynamic type:_16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
Determining dynamic type for call: _68 (_69, pcb_63, p_105(D), &ip_data.current_iphdr_src, src_113);
  Starting walk at: _68 (_69, pcb_63, p_105(D), &ip_data.current_iphdr_src, src_113);
  instance pointer: _69  Outer instance pointer: _69 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_61 = pbuf_remove_header (p_105(D), 8);
  Function call may change dynamic type:_16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
  Function call may change dynamic type:dest_115 = lwip_htons (_14);
  Function call may change dynamic type:src_113 = lwip_htons (_13);
  Function call may change dynamic type:iftmp.0_111 = ip4_addr_isbroadcast_u32 (_11, _12);
  Function call may change dynamic type:_55 = netif_get_ip6_addr_match (inp_107(D), &ip_data.current_iphdr_dest.u_addr.ip6);
Determining dynamic type for call: _68 (_69, pcb_63, p_105(D), &ip_data.current_iphdr_src, src_113);
  Starting walk at: _68 (_69, pcb_63, p_105(D), &ip_data.current_iphdr_src, src_113);
  instance pointer: pcb_63  Outer instance pointer: pcb_63 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_61 = pbuf_remove_header (p_105(D), 8);
  Function call may change dynamic type:_16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
  Function call may change dynamic type:dest_115 = lwip_htons (_14);
  Function call may change dynamic type:src_113 = lwip_htons (_13);
  Function call may change dynamic type:iftmp.0_111 = ip4_addr_isbroadcast_u32 (_11, _12);
  Function call may change dynamic type:_55 = netif_get_ip6_addr_match (inp_107(D), &ip_data.current_iphdr_dest.u_addr.ip6);
Determining dynamic type for call: _68 (_69, pcb_63, p_105(D), &ip_data.current_iphdr_src, src_113);
  Starting walk at: _68 (_69, pcb_63, p_105(D), &ip_data.current_iphdr_src, src_113);
  instance pointer: p_105(D)  Outer instance pointer: p_105(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_61 = pbuf_remove_header (p_105(D), 8);
  Function call may change dynamic type:_16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
  Function call may change dynamic type:dest_115 = lwip_htons (_14);
  Function call may change dynamic type:src_113 = lwip_htons (_13);
  Function call may change dynamic type:iftmp.0_111 = ip4_addr_isbroadcast_u32 (_11, _12);
  Function call may change dynamic type:_55 = netif_get_ip6_addr_match (inp_107(D), &ip_data.current_iphdr_dest.u_addr.ip6);
Determining dynamic type for call: _68 (_69, pcb_63, p_105(D), &ip_data.current_iphdr_src, src_113);
  Starting walk at: _68 (_69, pcb_63, p_105(D), &ip_data.current_iphdr_src, src_113);
  instance pointer: &ip_data.current_iphdr_src  Outer instance pointer: ip_data offset: 160 (bits) vtbl reference: 
  Function call may change dynamic type:_61 = pbuf_remove_header (p_105(D), 8);
  Function call may change dynamic type:_16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
  Function call may change dynamic type:dest_115 = lwip_htons (_14);
  Function call may change dynamic type:src_113 = lwip_htons (_13);
  Function call may change dynamic type:iftmp.0_111 = ip4_addr_isbroadcast_u32 (_11, _12);
  Function call may change dynamic type:_55 = netif_get_ip6_addr_match (inp_107(D), &ip_data.current_iphdr_dest.u_addr.ip6);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  memset/45:
  Jump functions of caller  memp_malloc/44:
  Jump functions of caller  memp_free/43:
  Jump functions of caller  ip4_output_if_src/40:
  Jump functions of caller  ip6_output_if_src/39:
  Jump functions of caller  pbuf_chain/38:
  Jump functions of caller  pbuf_alloc/37:
  Jump functions of caller  pbuf_add_header/36:
  Jump functions of caller  ip6_select_source_address/35:
  Jump functions of caller  ip6_route/34:
  Jump functions of caller  ip4_route/33:
  Jump functions of caller  netif_get_by_index/31:
  Jump functions of caller  icmp_dest_unreach/30:
  Jump functions of caller  icmp6_dest_unreach/29:
  Jump functions of caller  pbuf_header_force/28:
  Jump functions of caller  pbuf_remove_header/27:
  Jump functions of caller  netif_get_ip6_addr_match/26:
  Jump functions of caller  lwip_htons/25:
  Jump functions of caller  ip4_addr_isbroadcast_u32/24:
  Jump functions of caller  pbuf_free/23:
  Jump functions of caller  rand/21:
  Jump functions of caller  udp_netif_ip_addr_changed/20:
  Jump functions of caller  udp_new_ip_type/19:
    callsite  udp_new_ip_type/19 -> udp_new/18 : 
  Jump functions of caller  udp_new/18:
  Jump functions of caller  udp_remove/17:
  Jump functions of caller  udp_recv/16:
  Jump functions of caller  udp_disconnect/15:
  Jump functions of caller  udp_connect/14:
    callsite  udp_connect/14 -> udp_bind/12 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: ANCESTOR: 0, offset 0, agg_preserved
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  udp_bind_netif/13:
  Jump functions of caller  udp_bind/12:
    callsite  udp_bind/12 -> udp_new_port/4 : 
  Jump functions of caller  udp_sendto_if_src/11:
    callsite  udp_sendto_if_src/11 -> udp_bind/12 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: ANCESTOR: 0, offset 0, agg_preserved
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  udp_sendto_if/10:
    callsite  udp_sendto_if/10 -> udp_sendto_if_src/11 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  udp_sendto/9:
    callsite  udp_sendto/9 -> udp_sendto_if/10 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  udp_send/8:
    callsite  udp_send/8 -> udp_sendto/9 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: ANCESTOR: 0, offset 192, agg_preserved
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  udp_input/7:
    callsite  udp_input/7 -> udp_input_local_match/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _68 (_69, pcb_63, p_105(D), &ip_data.current_iphdr_src, src_113);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: &ip_data.current_iphdr_src
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 4: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  udp_input_local_match/5:
  Jump functions of caller  udp_new_port/4:
  Jump functions of caller  udp_init/3:

 Propagating constants:

Not considering udp_netif_ip_addr_changed for cloning; -fipa-cp-clone disabled.
Not considering udp_new_ip_type for cloning; -fipa-cp-clone disabled.
Not considering udp_new for cloning; -fipa-cp-clone disabled.
Not considering udp_remove for cloning; -fipa-cp-clone disabled.
Not considering udp_recv for cloning; -fipa-cp-clone disabled.
Not considering udp_disconnect for cloning; -fipa-cp-clone disabled.
Not considering udp_connect for cloning; -fipa-cp-clone disabled.
Not considering udp_bind_netif for cloning; -fipa-cp-clone disabled.
Not considering udp_bind for cloning; -fipa-cp-clone disabled.
Not considering udp_sendto_if_src for cloning; -fipa-cp-clone disabled.
Not considering udp_sendto_if for cloning; -fipa-cp-clone disabled.
Not considering udp_sendto for cloning; -fipa-cp-clone disabled.
Not considering udp_send for cloning; -fipa-cp-clone disabled.
Not considering udp_input for cloning; -fipa-cp-clone disabled.
Not considering udp_init for cloning; -fipa-cp-clone disabled.

overall_size: 1135, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: udp_netif_ip_addr_changed/20:
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
  Node: udp_new_ip_type/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: udp_new/18:
  Node: udp_remove/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: udp_recv/16:
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
  Node: udp_disconnect/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: udp_connect/14:
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
  Node: udp_bind_netif/13:
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
  Node: udp_bind/12:
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
  Node: udp_sendto_if_src/11:
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
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [5]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: udp_sendto_if/10:
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
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: udp_sendto/9:
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
  Node: udp_send/8:
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
  Node: udp_input/7:
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
  Node: udp_input_local_match/5:
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
  Node: udp_new_port/4:
  Node: udp_init/3:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

memset/45 (memset) @062fdee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_new/18 (574129754 (estimated locally),0.53 per call) 
  Calls: 
memp_malloc/44 (memp_malloc) @062fde00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_new/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
memp_free/43 (memp_free) @062fdc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_remove/17 (140173161 (estimated locally),0.82 per call) 
  Calls: 
ip_addr_any_type/42 (ip_addr_any_type) @06332900
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: udp_disconnect/15 (read)udp_disconnect/15 (read)udp_disconnect/15 (read)udp_disconnect/15 (read)udp_disconnect/15 (read)udp_disconnect/15 (read)udp_disconnect/15 (read)
  Availability: not_available
  Varpool flags: read-only
ip_addr_any/41 (ip_addr_any) @06323990
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: udp_bind/12 (addr)
  Availability: not_available
  Varpool flags: read-only
ip4_output_if_src/40 (ip4_output_if_src) @062fd000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto_if_src/11 (34905 (estimated locally),0.18 per call) 
  Calls: 
ip6_output_if_src/39 (ip6_output_if_src) @062d5ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto_if_src/11 (17981 (estimated locally),0.09 per call) 
  Calls: 
pbuf_chain/38 (pbuf_chain) @062d51c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto_if_src/11 (17400 (estimated locally),0.09 per call) 
  Calls: 
pbuf_alloc/37 (pbuf_alloc) @062d5380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto_if_src/11 (52964 (estimated locally),0.27 per call) 
  Calls: 
pbuf_add_header/36 (pbuf_add_header) @062d52a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto_if_src/11 (160498 (estimated locally),0.83 per call) 
  Calls: 
ip6_select_source_address/35 (ip6_select_source_address) @062d5d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto_if/10 (191677839 (estimated locally),0.18 per call) 
  Calls: 
ip6_route/34 (ip6_route) @062d59a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_connect/14 (12742515 (estimated locally),0.10 per call) udp_sendto/9 (203798594 (estimated locally),0.19 per call) udp_bind/12 (4195868 (estimated locally),0.08 per call) 
  Calls: 
ip4_route/33 (ip4_route) @062d58c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto/9 (395609036 (estimated locally),0.37 per call) udp_sendto/9 (28671051 (estimated locally),0.03 per call) 
  Calls: 
ip_addr_broadcast/32 (ip_addr_broadcast) @062e3ea0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: udp_sendto/9 (read)
  Availability: not_available
  Varpool flags: read-only
netif_get_by_index/31 (netif_get_by_index) @062d57e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto/9 (115561069 (estimated locally),0.11 per call) udp_sendto/9 (344958415 (estimated locally),0.32 per call) 
  Calls: 
icmp_dest_unreach/30 (icmp_dest_unreach) @062d5000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_input/7 (879 (estimated locally),0.00 per call) 
  Calls: 
icmp6_dest_unreach/29 (icmp6_dest_unreach) @0628ac40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_input/7 (2051 (estimated locally),0.01 per call) 
  Calls: 
pbuf_header_force/28 (pbuf_header_force) @0628ab60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_input/7 (2930 (estimated locally),0.01 per call) 
  Calls: 
pbuf_remove_header/27 (pbuf_remove_header) @0628aa80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_input/7 (118403 (estimated locally),0.33 per call) 
  Calls: 
netif_get_ip6_addr_match/26 (netif_get_ip6_addr_match) @0628a9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto_if/10 (162134508 (estimated locally),0.15 per call) udp_input/7 (34802 (estimated locally),0.10 per call) 
  Calls: 
lwip_htons/25 (lwip_htons) @0628aee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto_if_src/11 (17452 (estimated locally),0.09 per call) udp_sendto_if_src/11 (35433 (estimated locally),0.18 per call) udp_sendto_if_src/11 (52886 (estimated locally),0.27 per call) udp_sendto_if_src/11 (52886 (estimated locally),0.27 per call) udp_input/7 (139881 (estimated locally),0.39 per call) udp_input/7 (139881 (estimated locally),0.39 per call) 
  Calls: 
ip4_addr_isbroadcast_u32/24 (ip4_addr_isbroadcast_u32) @0628ae00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_input/7 (68374 (estimated locally),0.19 per call) 
  Calls: 
pbuf_free/23 (pbuf_free) @0628ad20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_sendto_if_src/11 (28278 (estimated locally),0.15 per call) udp_input/7 (21479 (estimated locally),0.06 per call) udp_input/7 (17760 (estimated locally),0.05 per call) udp_input/7 (4065 (estimated locally),0.01 per call) udp_input/7 (35496 (estimated locally),0.10 per call) 
  Calls: 
lwip_stats/22 (lwip_stats) @062cfaf8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: udp_input/7 (read)udp_input/7 (write)udp_input/7 (read)udp_input/7 (write)udp_sendto_if_src/11 (read)udp_sendto_if_src/11 (write)udp_input/7 (read)udp_input/7 (write)udp_input/7 (read)udp_input/7 (write)udp_input/7 (read)udp_input/7 (write)udp_input/7 (read)udp_input/7 (write)udp_input/7 (read)udp_input/7 (write)udp_input/7 (read)udp_input/7 (write)udp_input/7 (read)udp_input/7 (write)udp_sendto_if_src/11 (read)udp_sendto_if_src/11 (write)udp_sendto/9 (read)udp_sendto/9 (write)
  Availability: not_available
  Varpool flags:
rand/21 (rand) @0628a8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_init/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
udp_netif_ip_addr_changed/20 (udp_netif_ip_addr_changed) @0628a460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: udp_pcbs/2 (read)
  Referring: 
  Availability: available
  Function flags: count:964176328 (estimated locally) body optimize_size
  Called by: 
  Calls: 
udp_new_ip_type/19 (udp_new_ip_type) @0627b7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: udp_new/18 (1073741824 (estimated locally),1.00 per call) 
udp_new/18 (udp_new) @0627b380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: udp_new_ip_type/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: memset/45 (574129754 (estimated locally),0.53 per call) memp_malloc/44 (1073741824 (estimated locally),1.00 per call) 
udp_remove/17 (udp_remove) @0627b000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: udp_pcbs/2 (read)udp_pcbs/2 (write)
  Referring: 
  Availability: available
  Function flags: count:171130708 (estimated locally) body optimize_size
  Called by: 
  Calls: memp_free/43 (140173161 (estimated locally),0.82 per call) 
udp_recv/16 (udp_recv) @06274ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
udp_disconnect/15 (udp_disconnect) @06274c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any_type/42 (read)ip_addr_any_type/42 (read)ip_addr_any_type/42 (read)ip_addr_any_type/42 (read)ip_addr_any_type/42 (read)ip_addr_any_type/42 (read)ip_addr_any_type/42 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
udp_connect/14 (udp_connect) @06229c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: udp_pcbs/2 (read)udp_pcbs/2 (write)
  Referring: 
  Availability: available
  Function flags: count:130552291 (estimated locally) body optimize_size
  Called by: 
  Calls: ip6_route/34 (12742515 (estimated locally),0.10 per call) udp_bind/12 (42695388 (estimated locally),0.33 per call) 
udp_bind_netif/13 (udp_bind_netif) @06215b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
udp_bind/12 (udp_bind) @062158c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any/41 (addr)udp_pcbs/2 (read)udp_pcbs/2 (read)udp_pcbs/2 (read)udp_pcbs/2 (write)
  Referring: 
  Availability: available
  Function flags: count:54276207 (estimated locally) body optimize_size
  Called by: udp_connect/14 (42695388 (estimated locally),0.33 per call) udp_sendto_if_src/11 (60931 (estimated locally),0.31 per call) 
  Calls: udp_new_port/4 (17830548 (estimated locally),0.33 per call) ip6_route/34 (4195868 (estimated locally),0.08 per call) 
udp_sendto_if_src/11 (udp_sendto_if_src) @061cd620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/22 (read)lwip_stats/22 (write)lwip_stats/22 (read)lwip_stats/22 (write)
  Referring: 
  Availability: available
  Function flags: count:193920 (estimated locally) body optimize_size
  Called by: udp_sendto_if/10 (1034045458 (estimated locally),0.96 per call) 
  Calls: pbuf_free/23 (28278 (estimated locally),0.15 per call) ip4_output_if_src/40 (34905 (estimated locally),0.18 per call) ip6_output_if_src/39 (17981 (estimated locally),0.09 per call) lwip_htons/25 (17452 (estimated locally),0.09 per call) lwip_htons/25 (35433 (estimated locally),0.18 per call) lwip_htons/25 (52886 (estimated locally),0.27 per call) lwip_htons/25 (52886 (estimated locally),0.27 per call) pbuf_chain/38 (17400 (estimated locally),0.09 per call) pbuf_alloc/37 (52964 (estimated locally),0.27 per call) pbuf_add_header/36 (160498 (estimated locally),0.83 per call) udp_bind/12 (60931 (estimated locally),0.31 per call) 
udp_sendto_if/10 (udp_sendto_if) @061aaee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: udp_sendto/9 (1035816040 (estimated locally),0.96 per call) 
  Calls: udp_sendto_if_src/11 (1034045458 (estimated locally),0.96 per call) netif_get_ip6_addr_match/26 (162134508 (estimated locally),0.15 per call) ip6_select_source_address/35 (191677839 (estimated locally),0.18 per call) 
udp_sendto/9 (udp_sendto) @061aa1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_broadcast/32 (read)lwip_stats/22 (read)lwip_stats/22 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: udp_send/8 (1052501202 (estimated locally),0.98 per call) 
  Calls: udp_sendto_if/10 (1035816040 (estimated locally),0.96 per call) ip4_route/33 (395609036 (estimated locally),0.37 per call) ip6_route/34 (203798594 (estimated locally),0.19 per call) ip4_route/33 (28671051 (estimated locally),0.03 per call) netif_get_by_index/31 (115561069 (estimated locally),0.11 per call) netif_get_by_index/31 (344958415 (estimated locally),0.32 per call) 
udp_send/8 (udp_send) @061a02a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: udp_sendto/9 (1052501202 (estimated locally),0.98 per call) 
udp_input/7 (udp_input) @061a0000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/22 (read)lwip_stats/22 (write)lwip_stats/22 (read)lwip_stats/22 (write)lwip_stats/22 (read)lwip_stats/22 (write)lwip_stats/22 (read)lwip_stats/22 (write)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)udp_pcbs/2 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)udp_pcbs/2 (read)udp_pcbs/2 (write)lwip_stats/22 (read)lwip_stats/22 (write)ip_data/6 (read)ip_data/6 (addr)ip_data/6 (read)ip_data/6 (read)lwip_stats/22 (read)lwip_stats/22 (write)ip_data/6 (addr)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)lwip_stats/22 (read)lwip_stats/22 (write)lwip_stats/22 (read)lwip_stats/22 (write)lwip_stats/22 (read)lwip_stats/22 (write)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/23 (21479 (estimated locally),0.06 per call) pbuf_free/23 (17760 (estimated locally),0.05 per call) icmp_dest_unreach/30 (879 (estimated locally),0.00 per call) icmp6_dest_unreach/29 (2051 (estimated locally),0.01 per call) pbuf_header_force/28 (2930 (estimated locally),0.01 per call) pbuf_free/23 (4065 (estimated locally),0.01 per call) pbuf_remove_header/27 (118403 (estimated locally),0.33 per call) netif_get_ip6_addr_match/26 (34802 (estimated locally),0.10 per call) udp_input_local_match/5 (1204580 (estimated locally),3.37 per call) lwip_htons/25 (139881 (estimated locally),0.39 per call) lwip_htons/25 (139881 (estimated locally),0.39 per call) ip4_addr_isbroadcast_u32/24 (68374 (estimated locally),0.19 per call) pbuf_free/23 (35496 (estimated locally),0.10 per call) 
   Indirect call(37376 (estimated locally),0.10 per call) 
ip_data/6 (ip_data) @0612ed80
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: udp_input_local_match/5 (read)udp_input_local_match/5 (read)udp_input_local_match/5 (read)udp_input_local_match/5 (read)udp_input_local_match/5 (read)udp_input_local_match/5 (read)udp_input_local_match/5 (read)udp_input_local_match/5 (read)udp_input_local_match/5 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (addr)udp_input/7 (read)udp_input/7 (read)udp_input/7 (addr)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)udp_input/7 (read)
  Availability: not_available
  Varpool flags:
udp_input_local_match/5 (udp_input_local_match) @06133b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: udp_input/7 (1204580 (estimated locally),3.37 per call) 
  Calls: 
udp_new_port/4 (udp_new_port) @0612f8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: udp_port/1 (read)udp_port/1 (write)udp_port/1 (write)udp_pcbs/2 (read)udp_port/1 (read)udp_port/1 (read)
  Referring: 
  Availability: local
  Function flags: count:59613878 (estimated locally) body local optimize_size
  Called by: udp_bind/12 (17830548 (estimated locally),0.33 per call) 
  Calls: 
udp_init/3 (udp_init) @0612f620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: udp_port/1 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: rand/21 (1073741824 (estimated locally),1.00 per call) 
udp_pcbs/2 (udp_pcbs) @0612e870
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: udp_bind/12 (read)udp_bind/12 (write)udp_remove/17 (write)udp_bind/12 (read)udp_bind/12 (read)udp_connect/14 (read)udp_new_port/4 (read)udp_connect/14 (write)udp_input/7 (read)udp_input/7 (read)udp_input/7 (write)udp_remove/17 (read)udp_netif_ip_addr_changed/20 (read)
  Availability: available
  Varpool flags:
udp_port/1 (udp_port) @0612e828
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: udp_new_port/4 (read)udp_new_port/4 (read)udp_new_port/4 (write)udp_new_port/4 (write)udp_new_port/4 (read)udp_init/3 (write)
  Availability: available
  Varpool flags: initialized

;; Function udp_init (udp_init, funcdef_no=1, decl_uid=7034, cgraph_uid=2, symbol_order=3)

Modification phase of node udp_init/3
udp_init ()
{
  int _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = rand ();
  _2 = (short unsigned int) _1;
  _3 = _2 & 16383;
  _4 = _3 + 49152;
  udp_port = _4;
  return;

}



;; Function udp_input (udp_input, funcdef_no=4, decl_uid=7032, cgraph_uid=5, symbol_order=7)

Modification phase of node udp_input/7
udp_input (struct pbuf * p, struct netif * inp)
{
  u8_t for_us;
  u16_t dest;
  u16_t src;
  struct udp_pcb * uncon_pcb;
  struct udp_pcb * prev;
  struct udp_pcb * pcb;
  struct udp_hdr * udphdr;
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  short unsigned int _6;
  short unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  unsigned char _10;
  long unsigned int _11;
  struct netif * _12;
  short unsigned int _13;
  short unsigned int _14;
  short unsigned int _15;
  unsigned char _16;
  unsigned char _17;
  long unsigned int _18;
  unsigned char _19;
  long unsigned int _20;
  long unsigned int _22;
  unsigned char _23;
  long unsigned int _24;
  long unsigned int _25;
  short unsigned int _26;
  unsigned char _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  _Bool _32;
  long unsigned int _33;
  unsigned char _35;
  long unsigned int _37;
  long unsigned int _38;
  long unsigned int _39;
  long unsigned int _40;
  long unsigned int _41;
  long unsigned int _42;
  long unsigned int _43;
  long unsigned int _44;
  unsigned char _45;
  unsigned char _46;
  _Bool _47;
  long unsigned int _48;
  long unsigned int _49;
  struct udp_pcb * _50;
  struct udp_pcb * udp_pcbs.3_51;
  short unsigned int _52;
  short unsigned int _53;
  struct ip6_hdr * _54;
  signed char _55;
  _Bool _56;
  struct ip6_hdr * _57;
  long unsigned int _58;
  long unsigned int _59;
  _Bool _60;
  unsigned char _61;
  long unsigned int _66;
  long unsigned int _67;
  void (*<T729>) (void *, struct udp_pcb *, struct pbuf *, const struct ip_addr_t *, u16_t) _68;
  void * _69;
  unsigned char _70;
  long unsigned int _71;
  long unsigned int _72;
  long unsigned int _73;
  long unsigned int _74;
  short unsigned int _75;
  unsigned short _76;
  short int _77;
  struct ip6_hdr * _78;
  short unsigned int _79;
  short unsigned int _80;
  short unsigned int _81;
  short unsigned int _82;
  long unsigned int _83;
  long unsigned int _84;
  u8_t iftmp.0_90;
  int iftmp.1_91;
  int iftmp.2_92;
  _Bool iftmp.4_93;
  unsigned char _104;
  u8_t iftmp.0_111;
  _Bool iftmp.4_130;
  _Bool iftmp.4_131;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG for_us => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_105(D) == 0B)
    goto <bb 71>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 71> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 74> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (inp_107(D) == 0B)
    goto <bb 72>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 72> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 75> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = lwip_stats.udp.recv;
  _2 = _1 + 1;
  lwip_stats.udp.recv = _2;
  # DEBUG BEGIN_STMT
  _3 = p_105(D)->len;
  if (_3 <= 7)
    goto <bb 7>; [20.24%]
  else
    goto <bb 8>; [79.76%]

  <bb 7> [local count: 35496]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = lwip_stats.udp.lenerr;
  _5 = _4 + 1;
  lwip_stats.udp.lenerr = _5;
  # DEBUG BEGIN_STMT
  _6 = lwip_stats.udp.drop;
  _7 = _6 + 1;
  lwip_stats.udp.drop = _7;
  # DEBUG BEGIN_STMT
  _8 = lwip_stats.mib2.udpinerrors;
  _9 = _8 + 1;
  lwip_stats.mib2.udpinerrors = _9;
  # DEBUG BEGIN_STMT
  pbuf_free (p_105(D));
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 70>; [100.00%]

  <bb 8> [local count: 139881]:
  # DEBUG BEGIN_STMT
  udphdr_109 = p_105(D)->payload;
  # DEBUG udphdr => udphdr_109
  # DEBUG BEGIN_STMT
  _10 = ip_data.current_iphdr_dest.type;
  if (_10 != 6)
    goto <bb 9>; [48.88%]
  else
    goto <bb 10>; [51.12%]

  <bb 9> [local count: 68374]:
  _11 = ip_data.current_iphdr_dest.u_addr.ip4.addr;
  _12 = ip_data.current_netif;
  iftmp.0_111 = ip4_addr_isbroadcast_u32 (_11, _12);

  <bb 10> [local count: 139881]:
  # iftmp.0_90 = PHI <iftmp.0_111(9), 0(8)>
  # DEBUG broadcast => iftmp.0_90
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = udphdr_109->src;
  src_113 = lwip_htons (_13);
  # DEBUG src => src_113
  # DEBUG BEGIN_STMT
  _14 = udphdr_109->dest;
  dest_115 = lwip_htons (_14);
  # DEBUG dest => dest_115
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pcb => 0B
  # DEBUG BEGIN_STMT
  # DEBUG prev => 0B
  # DEBUG BEGIN_STMT
  # DEBUG uncon_pcb => 0B
  # DEBUG BEGIN_STMT
  pcb_116 = udp_pcbs;
  # DEBUG pcb => pcb_116
  goto <bb 45>; [100.00%]

  <bb 11> [local count: 5951483]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = pcb_62->local_port;
  if (_15 == dest_115)
    goto <bb 12>; [20.24%]
  else
    goto <bb 44>; [79.76%]

  <bb 12> [local count: 1204580]:
  _16 = udp_input_local_match (pcb_62, inp_107(D), iftmp.0_90);
  if (_16 != 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 44>; [50.00%]

  <bb 13> [local count: 602290]:
  # DEBUG BEGIN_STMT
  _17 = pcb_62->flags;
  _104 = _17 & 4;
  if (_104 == 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 22>; [50.00%]

  <bb 14> [local count: 301145]:
  # DEBUG BEGIN_STMT
  if (uncon_pcb_86 == 0B)
    goto <bb 22>; [30.00%]
  else
    goto <bb 15>; [70.00%]

  <bb 15> [local count: 210802]:
  # DEBUG BEGIN_STMT
  if (iftmp.0_90 != 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 22>; [50.00%]

  <bb 16> [local count: 105401]:
  _18 = ip_data.current_iphdr_dest.u_addr.ip4.addr;
  if (_18 == 4294967295)
    goto <bb 17>; [34.00%]
  else
    goto <bb 22>; [66.00%]

  <bb 17> [local count: 35836]:
  # DEBUG BEGIN_STMT
  _19 = uncon_pcb_86->local_ip.type;
  if (_19 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 18> [local count: 17918]:
  _20 = uncon_pcb_86->local_ip.u_addr.ip4.addr;
  _22 = MEM[(const struct ip4_addr_t *)inp_107(D) + 4B].addr;
  if (_20 != _22)
    goto <bb 19>; [66.00%]
  else
    goto <bb 22>; [34.00%]

  <bb 19> [local count: 29744]:
  # DEBUG BEGIN_STMT
  _23 = pcb_62->local_ip.type;
  if (_23 == 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 22>; [50.00%]

  <bb 20> [local count: 14872]:
  _24 = pcb_62->local_ip.u_addr.ip4.addr;
  _25 = MEM[(const struct ip4_addr_t *)inp_107(D) + 4B].addr;
  if (_24 == _25)
    goto <bb 21>; [34.00%]
  else
    goto <bb 22>; [66.00%]

  <bb 21> [local count: 5056]:
  # DEBUG BEGIN_STMT
  # DEBUG uncon_pcb => pcb_62

  <bb 22> [local count: 602290]:
  # uncon_pcb_65 = PHI <uncon_pcb_86(13), pcb_62(14), uncon_pcb_86(15), uncon_pcb_86(16), uncon_pcb_86(18), uncon_pcb_86(19), uncon_pcb_86(20), pcb_62(21)>
  # DEBUG uncon_pcb => uncon_pcb_65
  # DEBUG BEGIN_STMT
  _26 = pcb_62->remote_port;
  if (_26 == src_113)
    goto <bb 23>; [34.00%]
  else
    goto <bb 44>; [66.00%]

  <bb 23> [local count: 204779]:
  _27 = pcb_62->remote_ip.type;
  if (_27 == 6)
    goto <bb 24>; [34.00%]
  else
    goto <bb 30>; [66.00%]

  <bb 24> [local count: 69625]:
  _28 = pcb_62->remote_ip.u_addr.ip6.addr[0];
  if (_28 == 0)
    goto <bb 25>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 25> [local count: 34812]:
  _29 = pcb_62->remote_ip.u_addr.ip6.addr[1];
  if (_29 == 0)
    goto <bb 26>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 26> [local count: 17406]:
  _30 = pcb_62->remote_ip.u_addr.ip6.addr[2];
  if (_30 == 0)
    goto <bb 27>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 27> [local count: 8703]:
  _31 = pcb_62->remote_ip.u_addr.ip6.addr[3];
  if (_31 == 0)
    goto <bb 29>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 28> [local count: 65273]:

  <bb 29> [local count: 69625]:
  # iftmp.1_91 = PHI <1(27), 0(28)>
  _32 = (_Bool) iftmp.1_91;
  if (_32 != 0)
    goto <bb 41>; [2.20%]
  else
    goto <bb 31>; [97.80%]

  <bb 30> [local count: 135154]:
  _33 = pcb_62->remote_ip.u_addr.ip4.addr;
  if (_33 == 0)
    goto <bb 41>; [2.20%]
  else
    goto <bb 31>; [97.80%]

  <bb 31> [local count: 200274]:
  _35 = ip_data.current_iphdr_src.type;
  if (_27 == _35)
    goto <bb 32>; [34.00%]
  else
    goto <bb 44>; [66.00%]

  <bb 32> [local count: 68093]:
  if (_27 == 6)
    goto <bb 33>; [34.00%]
  else
    goto <bb 40>; [66.00%]

  <bb 33> [local count: 23152]:
  _37 = pcb_62->remote_ip.u_addr.ip6.addr[0];
  _38 = ip_data.current_iphdr_src.u_addr.ip6.addr[0];
  if (_37 == _38)
    goto <bb 34>; [34.00%]
  else
    goto <bb 38>; [66.00%]

  <bb 34> [local count: 7872]:
  _39 = pcb_62->remote_ip.u_addr.ip6.addr[1];
  _40 = ip_data.current_iphdr_src.u_addr.ip6.addr[1];
  if (_39 == _40)
    goto <bb 35>; [34.00%]
  else
    goto <bb 38>; [66.00%]

  <bb 35> [local count: 2676]:
  _41 = pcb_62->remote_ip.u_addr.ip6.addr[2];
  _42 = ip_data.current_iphdr_src.u_addr.ip6.addr[2];
  if (_41 == _42)
    goto <bb 36>; [34.00%]
  else
    goto <bb 38>; [66.00%]

  <bb 36> [local count: 910]:
  _43 = pcb_62->remote_ip.u_addr.ip6.addr[3];
  _44 = ip_data.current_iphdr_src.u_addr.ip6.addr[3];
  if (_43 == _44)
    goto <bb 37>; [34.00%]
  else
    goto <bb 38>; [66.00%]

  <bb 37> [local count: 309]:
  _45 = pcb_62->remote_ip.u_addr.ip6.zone;
  _46 = ip_data.current_iphdr_src.u_addr.ip6.zone;
  if (_45 == _46)
    goto <bb 39>; [34.00%]
  else
    goto <bb 38>; [66.00%]

  <bb 38> [local count: 23046]:

  <bb 39> [local count: 23152]:
  # iftmp.2_92 = PHI <1(37), 0(38)>
  _47 = (_Bool) iftmp.2_92;
  if (_47 != 0)
    goto <bb 41>; [2.20%]
  else
    goto <bb 44>; [97.80%]

  <bb 40> [local count: 44941]:
  _48 = pcb_62->remote_ip.u_addr.ip4.addr;
  _49 = ip_data.current_iphdr_src.u_addr.ip4.addr;
  if (_48 == _49)
    goto <bb 41>; [2.20%]
  else
    goto <bb 44>; [97.80%]

  <bb 41> [local count: 6003]:
  # pcb_118 = PHI <pcb_62(29), pcb_62(30), pcb_62(39), pcb_62(40)>
  # prev_36 = PHI <prev_64(29), prev_64(30), prev_64(39), prev_64(40)>
  # uncon_pcb_123 = PHI <uncon_pcb_65(29), uncon_pcb_65(30), uncon_pcb_65(39), uncon_pcb_65(40)>
  # DEBUG BEGIN_STMT
  if (prev_36 != 0B)
    goto <bb 42>; [70.00%]
  else
    goto <bb 43>; [30.00%]

  <bb 42> [local count: 4202]:
  # DEBUG BEGIN_STMT
  _50 = pcb_118->next;
  prev_36->next = _50;
  # DEBUG BEGIN_STMT
  udp_pcbs.3_51 = udp_pcbs;
  pcb_118->next = udp_pcbs.3_51;
  # DEBUG BEGIN_STMT
  udp_pcbs = pcb_118;
  goto <bb 46>; [100.00%]

  <bb 43> [local count: 1801]:
  # DEBUG BEGIN_STMT
  _52 = lwip_stats.udp.cachehit;
  _53 = _52 + 1;
  lwip_stats.udp.cachehit = _53;
  goto <bb 46>; [100.00%]

  <bb 44> [local count: 5945480]:
  # uncon_pcb_85 = PHI <uncon_pcb_86(11), uncon_pcb_86(12), uncon_pcb_65(22), uncon_pcb_65(39), uncon_pcb_65(40), uncon_pcb_65(31)>
  # DEBUG uncon_pcb => uncon_pcb_85
  # DEBUG BEGIN_STMT
  # DEBUG prev => pcb_62
  # DEBUG BEGIN_STMT
  pcb_124 = pcb_62->next;
  # DEBUG pcb => pcb_124

  <bb 45> [local count: 6085361]:
  # pcb_62 = PHI <pcb_116(10), pcb_124(44)>
  # prev_64 = PHI <0B(10), pcb_62(44)>
  # uncon_pcb_86 = PHI <0B(10), uncon_pcb_85(44)>
  # DEBUG uncon_pcb => uncon_pcb_86
  # DEBUG prev => prev_64
  # DEBUG pcb => pcb_62
  # DEBUG BEGIN_STMT
  if (pcb_62 != 0B)
    goto <bb 11>; [97.80%]
  else
    goto <bb 46>; [2.20%]

  <bb 46> [local count: 139881]:
  # uncon_pcb_87 = PHI <uncon_pcb_123(43), uncon_pcb_86(45), uncon_pcb_123(42)>
  # pcb_34 = PHI <pcb_118(43), pcb_62(45), pcb_118(42)>
  # DEBUG uncon_pcb => uncon_pcb_87
  # DEBUG BEGIN_STMT
  if (pcb_34 == 0B)
    goto <bb 47>; [30.00%]
  else
    goto <bb 48>; [70.00%]

  <bb 47> [local count: 41964]:
  # DEBUG BEGIN_STMT
  # DEBUG pcb => uncon_pcb_87

  <bb 48> [local count: 139881]:
  # pcb_63 = PHI <pcb_34(46), uncon_pcb_87(47)>
  # DEBUG pcb => pcb_63
  # DEBUG BEGIN_STMT
  if (pcb_63 != 0B)
    goto <bb 54>; [53.47%]
  else
    goto <bb 49>; [46.53%]

  <bb 49> [local count: 65087]:
  # DEBUG BEGIN_STMT
  _54 = ip_data.current_ip6_header;
  if (_54 != 0B)
    goto <bb 50>; [53.47%]
  else
    goto <bb 51>; [46.53%]

  <bb 50> [local count: 34802]:
  # DEBUG BEGIN_STMT
  _55 = netif_get_ip6_addr_match (inp_107(D), &ip_data.current_iphdr_dest.u_addr.ip6);
  _56 = _55 >= 0;
  for_us_126 = (u8_t) _56;
  # DEBUG for_us => for_us_126

  <bb 51> [local count: 65087]:
  # for_us_88 = PHI <0(49), for_us_126(50)>
  # DEBUG for_us => for_us_88
  # DEBUG BEGIN_STMT
  _57 = ip_data.current_ip6_header;
  if (_57 == 0B)
    goto <bb 52>; [30.00%]
  else
    goto <bb 53>; [70.00%]

  <bb 52> [local count: 19526]:
  # DEBUG BEGIN_STMT
  _58 = MEM[(const struct ip4_addr_t *)inp_107(D) + 4B].addr;
  _59 = ip_data.current_iphdr_dest.u_addr.ip4.addr;
  _60 = _58 == _59;
  for_us_127 = (u8_t) _60;
  # DEBUG for_us => for_us_127

  <bb 53> [local count: 65087]:
  # for_us_89 = PHI <for_us_127(52), for_us_88(51)>
  # DEBUG for_us => for_us_89
  # DEBUG BEGIN_STMT
  if (for_us_89 != 0)
    goto <bb 54>; [67.00%]
  else
    goto <bb 69>; [33.00%]

  <bb 54> [local count: 118403]:
  # DEBUG for_us => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _61 = pbuf_remove_header (p_105(D), 8);
  if (_61 != 0)
    goto <bb 73>; [50.00%]
  else
    goto <bb 56>; [50.00%]

  <bb 73> [local count: 59201]:

  <bb 55> [local count: 592013595]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 76> [local count: 592013595]:
  goto <bb 55>; [100.00%]

  <bb 56> [local count: 59201]:
  # DEBUG BEGIN_STMT
  if (pcb_63 != 0B)
    goto <bb 57>; [70.00%]
  else
    goto <bb 60>; [30.00%]

  <bb 57> [local count: 41441]:
  # DEBUG BEGIN_STMT
  _66 = lwip_stats.mib2.udpindatagrams;
  _67 = _66 + 1;
  lwip_stats.mib2.udpindatagrams = _67;
  # DEBUG BEGIN_STMT
  _68 = pcb_63->recv;
  if (_68 != 0B)
    goto <bb 58>; [90.19%]
  else
    goto <bb 59>; [9.81%]

  <bb 58> [local count: 37376]:
  # DEBUG BEGIN_STMT
  _69 = pcb_63->recv_arg;
  _68 (_69, pcb_63, p_105(D), &ip_data.current_iphdr_src, src_113);
  goto <bb 70>; [100.00%]

  <bb 59> [local count: 4065]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_105(D));
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 70>; [100.00%]

  <bb 60> [local count: 17760]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (iftmp.0_90 == 0)
    goto <bb 61>; [50.00%]
  else
    goto <bb 68>; [50.00%]

  <bb 61> [local count: 8880]:
  _70 = ip_data.current_iphdr_dest.type;
  if (_70 == 6)
    goto <bb 62>; [34.00%]
  else
    goto <bb 63>; [66.00%]

  <bb 62> [local count: 3019]:
  _71 = ip_data.current_iphdr_dest.u_addr.ip6.addr[0];
  _72 = _71 & 255;
  iftmp.4_131 = _72 != 255;
  goto <bb 64>; [100.00%]

  <bb 63> [local count: 5861]:
  _73 = ip_data.current_iphdr_dest.u_addr.ip4.addr;
  _74 = _73 & 240;
  iftmp.4_130 = _74 != 224;

  <bb 64> [local count: 8880]:
  # iftmp.4_93 = PHI <iftmp.4_131(62), iftmp.4_130(63)>
  if (iftmp.4_93 != 0)
    goto <bb 65>; [33.00%]
  else
    goto <bb 68>; [67.00%]

  <bb 65> [local count: 2930]:
  # DEBUG BEGIN_STMT
  _75 = ip_data.current_ip_header_tot_len;
  _76 = _75 + 8;
  _77 = (short int) _76;
  pbuf_header_force (p_105(D), _77);
  # DEBUG BEGIN_STMT
  _78 = ip_data.current_ip6_header;
  if (_78 != 0B)
    goto <bb 66>; [70.00%]
  else
    goto <bb 67>; [30.00%]

  <bb 66> [local count: 2051]:
  icmp6_dest_unreach (p_105(D), 4);
  goto <bb 68>; [100.00%]

  <bb 67> [local count: 879]:
  icmp_dest_unreach (p_105(D), 3);

  <bb 68> [local count: 17760]:
  # DEBUG BEGIN_STMT
  _79 = lwip_stats.udp.proterr;
  _80 = _79 + 1;
  lwip_stats.udp.proterr = _80;
  # DEBUG BEGIN_STMT
  _81 = lwip_stats.udp.drop;
  _82 = _81 + 1;
  lwip_stats.udp.drop = _82;
  # DEBUG BEGIN_STMT
  _83 = lwip_stats.mib2.udpnoports;
  _84 = _83 + 1;
  lwip_stats.mib2.udpnoports = _84;
  # DEBUG BEGIN_STMT
  pbuf_free (p_105(D));
  goto <bb 70>; [100.00%]

  <bb 69> [local count: 21479]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_105(D));

  <bb 70> [local count: 116176]:
end:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function udp_bind (udp_bind, funcdef_no=9, decl_uid=6995, cgraph_uid=10, symbol_order=12)

Modification phase of node udp_bind/12
udp_bind (struct udp_pcb * pcb, const struct ip_addr_t * ipaddr, u16_t port)
{
  struct netif * selected_netif;
  struct ip_addr_t zoned_ipaddr;
  u8_t rebind;
  struct udp_pcb * ipcb;
  unsigned char _1;
  unsigned char _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  unsigned char _12;
  short unsigned int _13;
  unsigned char _14;
  unsigned char _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  unsigned char _24;
  unsigned char _25;
  _Bool _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  long unsigned int _32;
  _Bool _33;
  long unsigned int _34;
  _Bool _35;
  long unsigned int _36;
  long unsigned int _37;
  long unsigned int _38;
  long unsigned int _39;
  _Bool _40;
  long unsigned int _41;
  _Bool _42;
  unsigned char _43;
  unsigned char _44;
  const struct ip4_addr_t * _45;
  struct udp_pcb * udp_pcbs.26_46;
  err_t _53;
  u8_t iftmp.14_54;
  int iftmp.15_55;
  int iftmp.16_56;
  int iftmp.17_57;
  int iftmp.18_58;
  int iftmp.19_59;
  const long unsigned int iftmp.25_60;
  u8_t iftmp.14_79;
  const long unsigned int iftmp.20_87;
  const long unsigned int iftmp.21_89;
  const long unsigned int iftmp.22_91;
  const long unsigned int iftmp.23_93;
  u8_t iftmp.24_95;
  const long unsigned int iftmp.25_97;

  <bb 2> [local count: 54276207]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_66(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 16282862]:
  # DEBUG BEGIN_STMT
  # DEBUG ipaddr => &ip_addr_any

  <bb 4> [local count: 54276207]:
  # ipaddr_47 = PHI <ipaddr_66(D)(2), &ip_addr_any(3)>
  # DEBUG ipaddr => ipaddr_47
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_67(D) == 0B)
    goto <bb 69>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 54031964]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG rebind => 0
  # DEBUG BEGIN_STMT
  ipcb_69 = udp_pcbs;
  # DEBUG ipcb => ipcb_69
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 477309710]:
  # DEBUG BEGIN_STMT
  if (ipcb_50 == pcb_67(D))
    goto <bb 9>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 7> [local count: 451057676]:
  # DEBUG BEGIN_STMT
  ipcb_70 = ipcb_50->next;
  # DEBUG ipcb => ipcb_70

  <bb 8> [local count: 505089640]:
  # ipcb_50 = PHI <ipcb_69(5), ipcb_70(7)>
  # DEBUG ipcb => ipcb_50
  # DEBUG BEGIN_STMT
  if (ipcb_50 != 0B)
    goto <bb 6>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 54031964]:
  # rebind_52 = PHI <1(6), 0(8)>
  # DEBUG rebind => rebind_52
  # DEBUG BEGIN_STMT
  if (ipaddr_47 != 0B)
    goto <bb 10>; [70.00%]
  else
    goto <bb 21>; [30.00%]

  <bb 10> [local count: 37822375]:
  _1 = ipaddr_47->type;
  if (_1 == 6)
    goto <bb 11>; [34.00%]
  else
    goto <bb 21>; [66.00%]

  <bb 11> [local count: 12859607]:
  _2 = ipaddr_47->u_addr.ip6.zone;
  if (_2 == 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 12> [local count: 6429804]:
  _3 = ipaddr_47->u_addr.ip6.addr[0];
  _4 = _3 & 49407;
  if (_4 == 33022)
    goto <bb 15>; [20.24%]
  else
    goto <bb 13>; [79.76%]

  <bb 13> [local count: 5128411]:
  _5 = _3 & 36863;
  if (_5 == 511)
    goto <bb 15>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 14> [local count: 3384752]:
  if (_5 == 767)
    goto <bb 15>; [34.00%]
  else
    goto <bb 21>; [66.00%]

  <bb 15> [local count: 4195868]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  zoned_ipaddr.type = 6;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  zoned_ipaddr.u_addr.ip6.addr[0] = _3;
  # DEBUG BEGIN_STMT
  _6 = ipaddr_47->u_addr.ip6.addr[1];
  zoned_ipaddr.u_addr.ip6.addr[1] = _6;
  # DEBUG BEGIN_STMT
  _7 = ipaddr_47->u_addr.ip6.addr[2];
  zoned_ipaddr.u_addr.ip6.addr[2] = _7;
  # DEBUG BEGIN_STMT
  _8 = ipaddr_47->u_addr.ip6.addr[3];
  zoned_ipaddr.u_addr.ip6.addr[3] = _8;
  # DEBUG BEGIN_STMT
  zoned_ipaddr.u_addr.ip6.zone = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  selected_netif_78 = ip6_route (&zoned_ipaddr.u_addr.ip6, &zoned_ipaddr.u_addr.ip6);
  # DEBUG selected_netif => selected_netif_78
  # DEBUG BEGIN_STMT
  if (selected_netif_78 != 0B)
    goto <bb 16>; [70.00%]
  else
    goto <bb 21>; [30.00%]

  <bb 16> [local count: 2937107]:
  # DEBUG BEGIN_STMT
  _9 = zoned_ipaddr.u_addr.ip6.addr[0];
  _10 = _9 & 49407;
  if (_10 == 33022)
    goto <bb 19>; [34.00%]
  else
    goto <bb 17>; [66.00%]

  <bb 17> [local count: 1938491]:
  _11 = _9 & 36863;
  if (_11 == 511)
    goto <bb 19>; [34.00%]
  else
    goto <bb 18>; [66.00%]

  <bb 18> [local count: 1279404]:
  if (_11 == 767)
    goto <bb 19>; [34.00%]
  else
    goto <bb 20>; [66.00%]

  <bb 19> [local count: 2092701]:
  _12 = selected_netif_78->num;
  iftmp.14_79 = _12 + 1;

  <bb 20> [local count: 2937107]:
  # iftmp.14_54 = PHI <iftmp.14_79(19), 0(18)>
  zoned_ipaddr.u_addr.ip6.zone = iftmp.14_54;

  <bb 21> [local count: 54031964]:
  # ipaddr_48 = PHI <ipaddr_47(9), ipaddr_47(10), ipaddr_47(11), ipaddr_47(14), &zoned_ipaddr(20), &zoned_ipaddr(15)>
  # DEBUG ipaddr => ipaddr_48
  # DEBUG BEGIN_STMT
  if (port_81(D) == 0)
    goto <bb 22>; [33.00%]
  else
    goto <bb 23>; [67.00%]

  <bb 22> [local count: 17830548]:
  # DEBUG BEGIN_STMT
  port_85 = udp_new_port ();
  # DEBUG port => port_85
  # DEBUG BEGIN_STMT
  if (port_85 == 0)
    goto <bb 69>; [1.04%]
  else
    goto <bb 60>; [98.96%]

  <bb 23> [local count: 36201416]:
  # DEBUG BEGIN_STMT
  ipcb_82 = udp_pcbs;
  # DEBUG ipcb => ipcb_82
  goto <bb 59>; [100.00%]

  <bb 24> [local count: 1052266989]:
  # DEBUG BEGIN_STMT
  if (ipcb_51 != pcb_67(D))
    goto <bb 25>; [70.00%]
  else
    goto <bb 58>; [30.00%]

  <bb 25> [local count: 736586892]:
  # DEBUG BEGIN_STMT
  _13 = ipcb_51->local_port;
  if (_13 == port_81(D))
    goto <bb 26>; [34.00%]
  else
    goto <bb 58>; [66.00%]

  <bb 26> [local count: 250439543]:
  _14 = ipcb_51->local_ip.type;
  _15 = ipaddr_48->type;
  if (_14 == _15)
    goto <bb 27>; [34.00%]
  else
    goto <bb 56>; [66.00%]

  <bb 27> [local count: 85149445]:
  if (_14 == 6)
    goto <bb 28>; [34.00%]
  else
    goto <bb 35>; [66.00%]

  <bb 28> [local count: 28950811]:
  _16 = ipcb_51->local_ip.u_addr.ip6.addr[0];
  _17 = ipaddr_48->u_addr.ip6.addr[0];
  if (_16 == _17)
    goto <bb 29>; [34.00%]
  else
    goto <bb 33>; [66.00%]

  <bb 29> [local count: 9843276]:
  _18 = ipcb_51->local_ip.u_addr.ip6.addr[1];
  _19 = ipaddr_48->u_addr.ip6.addr[1];
  if (_18 == _19)
    goto <bb 30>; [34.00%]
  else
    goto <bb 33>; [66.00%]

  <bb 30> [local count: 3346714]:
  _20 = ipcb_51->local_ip.u_addr.ip6.addr[2];
  _21 = ipaddr_48->u_addr.ip6.addr[2];
  if (_20 == _21)
    goto <bb 31>; [34.00%]
  else
    goto <bb 33>; [66.00%]

  <bb 31> [local count: 1137883]:
  _22 = ipcb_51->local_ip.u_addr.ip6.addr[3];
  _23 = ipaddr_48->u_addr.ip6.addr[3];
  if (_22 == _23)
    goto <bb 32>; [34.00%]
  else
    goto <bb 33>; [66.00%]

  <bb 32> [local count: 386880]:
  _24 = ipcb_51->local_ip.u_addr.ip6.zone;
  _25 = ipaddr_48->u_addr.ip6.zone;
  if (_24 == _25)
    goto <bb 34>; [34.00%]
  else
    goto <bb 33>; [66.00%]

  <bb 33> [local count: 28819272]:

  <bb 34> [local count: 28950811]:
  # iftmp.15_55 = PHI <1(32), 0(33)>
  _26 = (_Bool) iftmp.15_55;
  if (_26 != 0)
    goto <bb 69>; [2.00%]
  else
    goto <bb 36>; [98.00%]

  <bb 35> [local count: 56198633]:
  _27 = ipcb_51->local_ip.u_addr.ip4.addr;
  _28 = ipaddr_48->u_addr.ip4.addr;
  if (_27 == _28)
    goto <bb 69>; [2.00%]
  else
    goto <bb 36>; [98.00%]

  <bb 36> [local count: 83446456]:
  if (_15 == 6)
    goto <bb 37>; [34.00%]
  else
    goto <bb 43>; [66.00%]

  <bb 37> [local count: 28371795]:
  _29 = ipaddr_48->u_addr.ip6.addr[0];
  if (_29 == 0)
    goto <bb 38>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 38> [local count: 14185897]:
  _30 = ipaddr_48->u_addr.ip6.addr[1];
  if (_30 == 0)
    goto <bb 39>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 39> [local count: 7092949]:
  _31 = ipaddr_48->u_addr.ip6.addr[2];
  if (_31 == 0)
    goto <bb 40>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 40> [local count: 3546474]:
  _32 = ipaddr_48->u_addr.ip6.addr[3];
  if (_32 == 0)
    goto <bb 42>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 41> [local count: 26598558]:

  <bb 42> [local count: 28371795]:
  # iftmp.16_56 = PHI <1(40), 0(41)>
  _33 = (_Bool) iftmp.16_56;
  if (_33 != 0)
    goto <bb 69>; [2.00%]
  else
    goto <bb 46>; [98.00%]

  <bb 43> [local count: 55074661]:
  _34 = ipaddr_48->u_addr.ip4.addr;
  if (_34 == 0)
    goto <bb 45>; [50.00%]
  else
    goto <bb 44>; [50.00%]

  <bb 44> [local count: 27537330]:

  <bb 45> [local count: 55074661]:
  # iftmp.17_57 = PHI <1(43), 0(44)>
  _35 = (_Bool) iftmp.17_57;
  if (_35 != 0)
    goto <bb 69>; [2.00%]
  else
    goto <bb 46>; [98.00%]

  <bb 46> [local count: 81777526]:
  if (_14 == 6)
    goto <bb 47>; [34.00%]
  else
    goto <bb 53>; [66.00%]

  <bb 47> [local count: 27804359]:
  _36 = ipcb_51->local_ip.u_addr.ip6.addr[0];
  if (_36 == 0)
    goto <bb 48>; [50.00%]
  else
    goto <bb 51>; [50.00%]

  <bb 48> [local count: 13902179]:
  _37 = ipcb_51->local_ip.u_addr.ip6.addr[1];
  if (_37 == 0)
    goto <bb 49>; [50.00%]
  else
    goto <bb 51>; [50.00%]

  <bb 49> [local count: 6951090]:
  _38 = ipcb_51->local_ip.u_addr.ip6.addr[2];
  if (_38 == 0)
    goto <bb 50>; [50.00%]
  else
    goto <bb 51>; [50.00%]

  <bb 50> [local count: 3475545]:
  _39 = ipcb_51->local_ip.u_addr.ip6.addr[3];
  if (_39 == 0)
    goto <bb 52>; [50.00%]
  else
    goto <bb 51>; [50.00%]

  <bb 51> [local count: 26066587]:

  <bb 52> [local count: 27804359]:
  # iftmp.18_58 = PHI <1(50), 0(51)>
  _40 = (_Bool) iftmp.18_58;
  if (_40 != 0)
    goto <bb 69>; [2.00%]
  else
    goto <bb 56>; [98.00%]

  <bb 53> [local count: 53973167]:
  _41 = ipcb_51->local_ip.u_addr.ip4.addr;
  if (_41 == 0)
    goto <bb 55>; [50.00%]
  else
    goto <bb 54>; [50.00%]

  <bb 54> [local count: 26986584]:

  <bb 55> [local count: 53973167]:
  # iftmp.19_59 = PHI <1(53), 0(54)>
  _42 = (_Bool) iftmp.19_59;
  if (_42 != 0)
    goto <bb 69>; [2.00%]
  else
    goto <bb 56>; [98.00%]

  <bb 56> [local count: 245432074]:
  if (_14 == 46)
    goto <bb 69>; [2.00%]
  else
    goto <bb 57>; [98.00%]

  <bb 57> [local count: 240523433]:
  if (_15 == 46)
    goto <bb 69>; [2.00%]
  else
    goto <bb 58>; [98.00%]

  <bb 58> [local count: 1037540410]:
  # DEBUG BEGIN_STMT
  ipcb_83 = ipcb_51->next;
  # DEBUG ipcb => ipcb_83

  <bb 59> [local count: 1073741824]:
  # ipcb_51 = PHI <ipcb_82(23), ipcb_83(58)>
  # DEBUG ipcb => ipcb_51
  # DEBUG BEGIN_STMT
  if (ipcb_51 != 0B)
    goto <bb 24>; [98.00%]
  else
    goto <bb 60>; [2.00%]

  <bb 60> [local count: 39119947]:
  # port_49 = PHI <port_85(22), port_81(D)(59)>
  # DEBUG port => port_49
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _43 = ipaddr_48->type;
  pcb_67(D)->local_ip.type = _43;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_48 != 0B)
    goto <bb 61>; [70.00%]
  else
    goto <bb 63>; [30.00%]

  <bb 61> [local count: 27383963]:
  _44 = ipaddr_48->type;
  if (_44 == 6)
    goto <bb 62>; [34.00%]
  else
    goto <bb 63>; [66.00%]

  <bb 62> [local count: 9310547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iftmp.20_87 = ipaddr_48->u_addr.ip6.addr[0];
  pcb_67(D)->local_ip.u_addr.ip6.addr[0] = iftmp.20_87;
  # DEBUG BEGIN_STMT
  iftmp.21_89 = ipaddr_48->u_addr.ip6.addr[1];
  pcb_67(D)->local_ip.u_addr.ip6.addr[1] = iftmp.21_89;
  # DEBUG BEGIN_STMT
  iftmp.22_91 = ipaddr_48->u_addr.ip6.addr[2];
  pcb_67(D)->local_ip.u_addr.ip6.addr[2] = iftmp.22_91;
  # DEBUG BEGIN_STMT
  iftmp.23_93 = ipaddr_48->u_addr.ip6.addr[3];
  pcb_67(D)->local_ip.u_addr.ip6.addr[3] = iftmp.23_93;
  # DEBUG BEGIN_STMT
  iftmp.24_95 = ipaddr_48->u_addr.ip6.zone;
  pcb_67(D)->local_ip.u_addr.ip6.zone = iftmp.24_95;
  # DEBUG BEGIN_STMT
  goto <bb 66>; [100.00%]

  <bb 63> [local count: 29809400]:
  # DEBUG BEGIN_STMT
  _45 = &ipaddr_48->u_addr.ip4;
  if (_45 != 0B)
    goto <bb 64>; [70.00%]
  else
    goto <bb 65>; [30.00%]

  <bb 64> [local count: 20866580]:
  iftmp.25_97 = ipaddr_48->u_addr.ip4.addr;

  <bb 65> [local count: 29809400]:
  # iftmp.25_60 = PHI <iftmp.25_97(64), 0(63)>
  pcb_67(D)->local_ip.u_addr.ip4.addr = iftmp.25_60;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_67(D)->local_ip.u_addr.ip6.addr[3] = 0;
  pcb_67(D)->local_ip.u_addr.ip6.addr[2] = 0;
  pcb_67(D)->local_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  pcb_67(D)->local_ip.u_addr.ip6.zone = 0;

  <bb 66> [local count: 39119947]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_67(D)->local_port = port_49;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (rebind_52 == 0)
    goto <bb 67>; [50.00%]
  else
    goto <bb 68>; [50.00%]

  <bb 67> [local count: 19559973]:
  # DEBUG BEGIN_STMT
  udp_pcbs.26_46 = udp_pcbs;
  pcb_67(D)->next = udp_pcbs.26_46;
  # DEBUG BEGIN_STMT
  udp_pcbs = pcb_67(D);

  <bb 68> [local count: 39119947]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 69> [local count: 54276206]:
  # _53 = PHI <-16(4), -8(22), -8(35), 0(68), -8(34), -8(55), -8(52), -8(56), -8(45), -8(42), -8(57)>
  zoned_ipaddr ={v} {CLOBBER};
  return _53;

}



;; Function udp_sendto_if_src (udp_sendto_if_src, funcdef_no=8, decl_uid=7021, cgraph_uid=9, symbol_order=11)

Modification phase of node udp_sendto_if_src/11
udp_sendto_if_src (struct udp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * dst_ip, u16_t dst_port, struct netif * netif, const struct ip_addr_t * src_ip)
{
  u16_t chklen_hdr;
  u16_t chklen;
  u8_t ip_proto;
  struct pbuf * q;
  err_t err;
  struct udp_hdr * udphdr;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  short unsigned int _4;
  struct ip_addr_t * _5;
  short unsigned int _6;
  unsigned char _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  unsigned char _13;
  unsigned char _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  unsigned char _19;
  unsigned char _20;
  short unsigned int _21;
  short unsigned int _22;
  short unsigned int _23;
  short unsigned int _24;
  unsigned char _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  unsigned char _30;
  const struct ip6_addr_t * _31;
  const struct ip6_addr_t * _32;
  unsigned char _33;
  const struct ip4_addr_t * _34;
  const struct ip4_addr_t * _35;
  unsigned char _36;
  long unsigned int _37;
  long unsigned int _38;
  short unsigned int _39;
  short unsigned int _40;
  err_t _44;
  _Bool iftmp.10_45;
  u8_t iftmp.11_46;
  _Bool iftmp.12_47;
  err_t iftmp.13_48;
  unsigned char _63;
  unsigned char _66;
  _Bool iftmp.10_78;
  _Bool iftmp.10_79;
  _Bool iftmp.12_86;
  _Bool iftmp.12_87;
  u8_t iftmp.11_88;
  u8_t iftmp.11_89;
  err_t iftmp.13_91;
  err_t iftmp.13_93;

  <bb 2> [local count: 193920]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_57(D) == 0B)
    goto <bb 43>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 193047]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_58(D) == 0B)
    goto <bb 43>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 192179]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (dst_ip_59(D) == 0B)
    goto <bb 43>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 191314]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (src_ip_60(D) == 0B)
    goto <bb 43>; [0.45%]
  else
    goto <bb 6>; [99.55%]

  <bb 6> [local count: 190453]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_61(D) == 0B)
    goto <bb 43>; [0.45%]
  else
    goto <bb 7>; [99.55%]

  <bb 7> [local count: 189596]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_57(D)->local_ip.type;
  if (_1 != 46)
    goto <bb 8>; [66.00%]
  else
    goto <bb 10>; [34.00%]

  <bb 8> [local count: 125133]:
  _2 = src_ip_60(D)->type;
  if (_1 != _2)
    goto <bb 43>; [2.00%]
  else
    goto <bb 9>; [98.00%]

  <bb 9> [local count: 122631]:
  _3 = dst_ip_59(D)->type;
  if (_1 != _3)
    goto <bb 43>; [2.00%]
  else
    goto <bb 10>; [98.00%]

  <bb 10> [local count: 184641]:
  # DEBUG BEGIN_STMT
  _4 = pcb_57(D)->local_port;
  if (_4 == 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 11> [local count: 60931]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = &pcb_57(D)->local_ip;
  err_65 = udp_bind (pcb_57(D), _5, 0);
  # DEBUG err => err_65
  # DEBUG BEGIN_STMT
  if (err_65 != 0)
    goto <bb 43>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 12> [local count: 163924]:
  # DEBUG BEGIN_STMT
  _6 = p_58(D)->tot_len;
  if (_6 > 65527)
    goto <bb 43>; [2.09%]
  else
    goto <bb 13>; [97.91%]

  <bb 13> [local count: 160498]:
  # DEBUG BEGIN_STMT
  _7 = pbuf_add_header (p_58(D), 8);
  if (_7 != 0)
    goto <bb 14>; [33.00%]
  else
    goto <bb 17>; [67.00%]

  <bb 14> [local count: 52964]:
  # DEBUG BEGIN_STMT
  q_69 = pbuf_alloc (54, 8, 640);
  # DEBUG q => q_69
  # DEBUG BEGIN_STMT
  if (q_69 == 0B)
    goto <bb 43>; [0.45%]
  else
    goto <bb 15>; [99.55%]

  <bb 15> [local count: 52726]:
  # DEBUG BEGIN_STMT
  _8 = p_58(D)->tot_len;
  if (_8 != 0)
    goto <bb 16>; [33.00%]
  else
    goto <bb 17>; [67.00%]

  <bb 16> [local count: 17400]:
  # DEBUG BEGIN_STMT
  pbuf_chain (q_69, p_58(D));

  <bb 17> [local count: 160260]:
  # q_41 = PHI <q_69(16), p_58(D)(13), q_69(15)>
  # DEBUG q => q_41
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = q_41->len;
  if (_9 <= 7)
    goto <bb 44>; [67.00%]
  else
    goto <bb 19>; [33.00%]

  <bb 44> [local count: 107374]:

  <bb 18> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 45> [local count: 1073741824]:
  goto <bb 18>; [100.00%]

  <bb 19> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  udphdr_71 = q_41->payload;
  # DEBUG udphdr => udphdr_71
  # DEBUG BEGIN_STMT
  _10 = pcb_57(D)->local_port;
  _11 = lwip_htons (_10);
  udphdr_71->src = _11;
  # DEBUG BEGIN_STMT
  _12 = lwip_htons (dst_port_74(D));
  udphdr_71->dest = _12;
  # DEBUG BEGIN_STMT
  udphdr_71->chksum = 0;
  # DEBUG BEGIN_STMT
  _13 = pcb_57(D)->flags;
  _63 = _13 & 8;
  if (_63 != 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 25>; [50.00%]

  <bb 20> [local count: 26443]:
  _14 = dst_ip_59(D)->type;
  if (_14 == 6)
    goto <bb 21>; [34.00%]
  else
    goto <bb 22>; [66.00%]

  <bb 21> [local count: 8991]:
  _15 = dst_ip_59(D)->u_addr.ip6.addr[0];
  _16 = _15 & 255;
  iftmp.10_78 = _16 == 255;
  goto <bb 23>; [100.00%]

  <bb 22> [local count: 17452]:
  _17 = dst_ip_59(D)->u_addr.ip4.addr;
  _18 = _17 & 240;
  iftmp.10_79 = _18 == 224;

  <bb 23> [local count: 26443]:
  # iftmp.10_45 = PHI <iftmp.10_78(21), iftmp.10_79(22)>
  if (iftmp.10_45 != 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 25>; [50.00%]

  <bb 24> [local count: 13221]:
  # DEBUG BEGIN_STMT
  _19 = q_41->flags;
  _20 = _19 | 4;
  q_41->flags = _20;

  <bb 25> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _66 = _13 & 2;
  if (_66 != 0)
    goto <bb 26>; [67.00%]
  else
    goto <bb 30>; [33.00%]

  <bb 26> [local count: 35433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  chklen_83 = pcb_57(D)->chksum_len_tx;
  # DEBUG chklen => chklen_83
  # DEBUG chklen_hdr => chklen_83
  # DEBUG BEGIN_STMT
  if (chklen_83 <= 7)
    goto <bb 28>; [50.00%]
  else
    goto <bb 27>; [50.00%]

  <bb 27> [local count: 17717]:
  _21 = q_41->tot_len;
  if (_21 < chklen_83)
    goto <bb 28>; [50.00%]
  else
    goto <bb 29>; [50.00%]

  <bb 28> [local count: 26575]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG chklen_hdr => 0
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => q_41->tot_len
  # DEBUG chklen => D#1

  <bb 29> [local count: 35433]:
  # chklen_hdr_43 = PHI <chklen_83(27), 0(28)>
  # DEBUG chklen_hdr => chklen_hdr_43
  # DEBUG BEGIN_STMT
  _22 = lwip_htons (chklen_hdr_43);
  udphdr_71->len = _22;
  # DEBUG BEGIN_STMT
  # DEBUG ip_proto => 136
  goto <bb 31>; [100.00%]

  <bb 30> [local count: 17452]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _23 = q_41->tot_len;
  _24 = lwip_htons (_23);
  udphdr_71->len = _24;
  # DEBUG BEGIN_STMT
  # DEBUG ip_proto => 17

  <bb 31> [local count: 52886]:
  # ip_proto_42 = PHI <136(29), 17(30)>
  # DEBUG ip_proto => ip_proto_42
  # DEBUG BEGIN_STMT
  _25 = dst_ip_59(D)->type;
  if (_25 == 6)
    goto <bb 32>; [34.00%]
  else
    goto <bb 33>; [66.00%]

  <bb 32> [local count: 17981]:
  _26 = dst_ip_59(D)->u_addr.ip6.addr[0];
  _27 = _26 & 255;
  iftmp.12_86 = _27 == 255;
  goto <bb 34>; [100.00%]

  <bb 33> [local count: 34905]:
  _28 = dst_ip_59(D)->u_addr.ip4.addr;
  _29 = _28 & 240;
  iftmp.12_87 = _29 == 224;

  <bb 34> [local count: 52886]:
  # iftmp.12_47 = PHI <iftmp.12_86(32), iftmp.12_87(33)>
  if (iftmp.12_47 != 0)
    goto <bb 35>; [50.00%]
  else
    goto <bb 36>; [50.00%]

  <bb 35> [local count: 26443]:
  iftmp.11_89 = pcb_57(D)->mcast_ttl;
  goto <bb 37>; [100.00%]

  <bb 36> [local count: 26443]:
  iftmp.11_88 = pcb_57(D)->ttl;

  <bb 37> [local count: 52886]:
  # iftmp.11_46 = PHI <iftmp.11_89(35), iftmp.11_88(36)>
  # DEBUG ttl => iftmp.11_46
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _30 = dst_ip_59(D)->type;
  if (_30 == 6)
    goto <bb 38>; [34.00%]
  else
    goto <bb 39>; [66.00%]

  <bb 38> [local count: 17981]:
  _31 = &src_ip_60(D)->u_addr.ip6;
  _32 = &dst_ip_59(D)->u_addr.ip6;
  _33 = pcb_57(D)->tos;
  iftmp.13_91 = ip6_output_if_src (q_41, _31, _32, iftmp.11_46, _33, ip_proto_42, netif_61(D));
  goto <bb 40>; [100.00%]

  <bb 39> [local count: 34905]:
  _34 = &src_ip_60(D)->u_addr.ip4;
  _35 = &dst_ip_59(D)->u_addr.ip4;
  _36 = pcb_57(D)->tos;
  iftmp.13_93 = ip4_output_if_src (q_41, _34, _35, iftmp.11_46, _36, ip_proto_42, netif_61(D));

  <bb 40> [local count: 52886]:
  # iftmp.13_48 = PHI <iftmp.13_91(38), iftmp.13_93(39)>
  # DEBUG err => iftmp.13_48
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _37 = lwip_stats.mib2.udpoutdatagrams;
  _38 = _37 + 1;
  lwip_stats.mib2.udpoutdatagrams = _38;
  # DEBUG BEGIN_STMT
  if (q_41 != p_58(D))
    goto <bb 41>; [53.47%]
  else
    goto <bb 42>; [46.53%]

  <bb 41> [local count: 28278]:
  # DEBUG BEGIN_STMT
  pbuf_free (q_41);
  # DEBUG BEGIN_STMT
  # DEBUG q => 0B

  <bb 42> [local count: 52886]:
  # DEBUG BEGIN_STMT
  _39 = lwip_stats.udp.xmit;
  _40 = _39 + 1;
  lwip_stats.udp.xmit = _40;
  # DEBUG BEGIN_STMT

  <bb 43> [local count: 86546]:
  # _44 = PHI <-16(2), -16(3), -16(4), -16(5), -16(6), -6(9), err_65(11), -1(12), -1(14), iftmp.13_48(42), -6(8)>
  return _44;

}



;; Function udp_sendto_if (udp_sendto_if, funcdef_no=7, decl_uid=7014, cgraph_uid=8, symbol_order=10)

Modification phase of node udp_sendto_if/10
udp_sendto_if (struct udp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * dst_ip, u16_t dst_port, struct netif * netif)
{
  const struct ip_addr_t * src_ip;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  struct ip6_addr_t * _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  const struct ip6_addr_t * _10;
  signed char _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  err_t _16;
  err_t _32;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_19(D) == 0B)
    goto <bb 23>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_20(D) == 0B)
    goto <bb 23>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 1064099892]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (dst_ip_21(D) == 0B)
    goto <bb 23>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 1059311441]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_22(D) == 0B)
    goto <bb 23>; [0.45%]
  else
    goto <bb 6>; [99.55%]

  <bb 6> [local count: 1054544540]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_19(D)->local_ip.type;
  if (_1 != 46)
    goto <bb 7>; [66.00%]
  else
    goto <bb 8>; [34.00%]

  <bb 7> [local count: 695999396]:
  _2 = dst_ip_21(D)->type;
  if (_1 != _2)
    goto <bb 23>; [2.00%]
  else
    goto <bb 8>; [98.00%]

  <bb 8> [local count: 1040624552]:
  # DEBUG BEGIN_STMT
  _3 = dst_ip_21(D)->type;
  if (_3 == 6)
    goto <bb 9>; [34.00%]
  else
    goto <bb 17>; [66.00%]

  <bb 9> [local count: 353812347]:
  # DEBUG BEGIN_STMT
  _4 = &pcb_19(D)->local_ip.u_addr.ip6;
  _5 = pcb_19(D)->local_ip.u_addr.ip6.addr[0];
  if (_5 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 10> [local count: 176906174]:
  _6 = pcb_19(D)->local_ip.u_addr.ip6.addr[1];
  if (_6 == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 11> [local count: 88453087]:
  _7 = pcb_19(D)->local_ip.u_addr.ip6.addr[2];
  if (_7 == 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 44226543]:
  _8 = pcb_19(D)->local_ip.u_addr.ip6.addr[3];
  if (_8 == 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 13> [local count: 331699076]:
  _9 = _5 & 255;
  if (_9 == 255)
    goto <bb 14>; [51.12%]
  else
    goto <bb 15>; [48.88%]

  <bb 14> [local count: 191677839]:
  # DEBUG BEGIN_STMT
  _10 = &dst_ip_21(D)->u_addr.ip6;
  src_ip_27 = ip6_select_source_address (netif_22(D), _10);
  # DEBUG src_ip => src_ip_27
  # DEBUG BEGIN_STMT
  if (src_ip_27 == 0B)
    goto <bb 23>; [0.45%]
  else
    goto <bb 22>; [99.55%]

  <bb 15> [local count: 162134508]:
  # DEBUG BEGIN_STMT
  _11 = netif_get_ip6_addr_match (netif_22(D), _4);
  if (_11 < 0)
    goto <bb 23>; [0.73%]
  else
    goto <bb 16>; [99.27%]

  <bb 16> [local count: 160950926]:
  # DEBUG BEGIN_STMT
  src_ip_25 = &pcb_19(D)->local_ip;
  # DEBUG src_ip => src_ip_25
  goto <bb 22>; [100.00%]

  <bb 17> [local count: 686812204]:
  # DEBUG BEGIN_STMT
  _12 = pcb_19(D)->local_ip.u_addr.ip4.addr;
  if (_12 == 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 18> [local count: 343406101]:
  _13 = _12 & 240;
  if (_13 == 224)
    goto <bb 19>; [34.00%]
  else
    goto <bb 20>; [66.00%]

  <bb 19> [local count: 460164176]:
  # DEBUG BEGIN_STMT
  src_ip_29 = &netif_22(D)->ip_addr;
  # DEBUG src_ip => src_ip_29
  goto <bb 22>; [100.00%]

  <bb 20> [local count: 226648027]:
  # DEBUG BEGIN_STMT
  _14 = MEM[(const struct ip4_addr_t *)netif_22(D) + 4B].addr;
  if (_12 != _14)
    goto <bb 23>; [2.00%]
  else
    goto <bb 21>; [98.00%]

  <bb 21> [local count: 222115066]:
  # DEBUG BEGIN_STMT
  src_ip_28 = &pcb_19(D)->local_ip;
  # DEBUG src_ip => src_ip_28

  <bb 22> [local count: 1034045458]:
  # src_ip_15 = PHI <src_ip_25(16), src_ip_29(19), src_ip_28(21), src_ip_27(14)>
  # DEBUG src_ip => src_ip_15
  # DEBUG BEGIN_STMT
  _32 = udp_sendto_if_src (pcb_19(D), p_20(D), dst_ip_21(D), dst_port_30(D), netif_22(D), src_ip_15);

  <bb 23> [local count: 1073741822]:
  # _16 = PHI <-16(2), -16(3), -16(4), -16(5), -6(7), -4(14), -4(15), -4(20), _32(22)>
  return _16;

}



;; Function udp_sendto (udp_sendto, funcdef_no=6, decl_uid=7026, cgraph_uid=7, symbol_order=9)

Modification phase of node udp_sendto/9
udp_sendto (struct udp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * dst_ip, u16_t dst_port)
{
  struct netif * netif;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  unsigned char _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  unsigned char _9;
  unsigned char _10;
  long unsigned int _11;
  long unsigned int _12;
  struct ip4_addr_t * _13;
  unsigned char _14;
  struct ip6_addr_t * _15;
  const struct ip6_addr_t * _16;
  const struct ip4_addr_t * _17;
  short unsigned int _18;
  short unsigned int _19;
  err_t _22;
  _Bool iftmp.8_23;
  _Bool iftmp.8_31;
  _Bool iftmp.8_32;
  struct netif * iftmp.9_38;
  struct netif * iftmp.9_40;
  err_t _45;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_27(D) == 0B)
    goto <bb 26>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_28(D) == 0B)
    goto <bb 26>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 1064099892]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (dst_ip_29(D) == 0B)
    goto <bb 26>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 1059311441]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_27(D)->local_ip.type;
  if (_1 != 46)
    goto <bb 6>; [66.00%]
  else
    goto <bb 7>; [34.00%]

  <bb 6> [local count: 699145551]:
  _2 = dst_ip_29(D)->type;
  if (_1 != _2)
    goto <bb 26>; [2.00%]
  else
    goto <bb 7>; [98.00%]

  <bb 7> [local count: 1045328530]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = pcb_27(D)->netif_idx;
  if (_3 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 344958415]:
  # DEBUG BEGIN_STMT
  netif_42 = netif_get_by_index (_3);
  # DEBUG netif => netif_42
  goto <bb 23>; [100.00%]

  <bb 9> [local count: 700370115]:
  # DEBUG BEGIN_STMT
  # DEBUG netif => 0B
  # DEBUG BEGIN_STMT
  _4 = dst_ip_29(D)->type;
  if (_4 == 6)
    goto <bb 10>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 10> [local count: 238125839]:
  _5 = dst_ip_29(D)->u_addr.ip6.addr[0];
  _6 = _5 & 255;
  iftmp.8_31 = _6 == 255;
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 462244275]:
  _7 = dst_ip_29(D)->u_addr.ip4.addr;
  _8 = _7 & 240;
  iftmp.8_32 = _8 == 224;

  <bb 12> [local count: 700370115]:
  # iftmp.8_23 = PHI <iftmp.8_31(10), iftmp.8_32(11)>
  if (iftmp.8_23 != 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 13> [local count: 350185057]:
  # DEBUG BEGIN_STMT
  _9 = pcb_27(D)->mcast_ifindex;
  if (_9 != 0)
    goto <bb 14>; [33.00%]
  else
    goto <bb 15>; [67.00%]

  <bb 14> [local count: 115561069]:
  # DEBUG BEGIN_STMT
  netif_36 = netif_get_by_index (_9);
  # DEBUG netif => netif_36
  goto <bb 19>; [100.00%]

  <bb 15> [local count: 234623988]:
  # DEBUG BEGIN_STMT
  _10 = dst_ip_29(D)->type;
  if (_10 == 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 16> [local count: 117311994]:
  # DEBUG BEGIN_STMT
  _11 = pcb_27(D)->mcast_ip4.addr;
  if (_11 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 17> [local count: 58655997]:
  _12 = ip_addr_broadcast.u_addr.ip4.addr;
  if (_11 != _12)
    goto <bb 18>; [48.88%]
  else
    goto <bb 20>; [51.12%]

  <bb 18> [local count: 28671051]:
  # DEBUG BEGIN_STMT
  _13 = &pcb_27(D)->mcast_ip4;
  netif_34 = ip4_route (_13);
  # DEBUG netif => netif_34

  <bb 19> [local count: 144232120]:
  # netif_20 = PHI <netif_34(18), netif_36(14)>
  # DEBUG netif => netif_20
  # DEBUG BEGIN_STMT
  if (netif_20 == 0B)
    goto <bb 20>; [30.00%]
  else
    goto <bb 23>; [70.00%]

  <bb 20> [local count: 599407631]:
  # DEBUG netif => NULL
  # DEBUG BEGIN_STMT
  _14 = dst_ip_29(D)->type;
  if (_14 == 6)
    goto <bb 21>; [34.00%]
  else
    goto <bb 22>; [66.00%]

  <bb 21> [local count: 203798594]:
  _15 = &pcb_27(D)->local_ip.u_addr.ip6;
  _16 = &dst_ip_29(D)->u_addr.ip6;
  iftmp.9_38 = ip6_route (_15, _16);
  goto <bb 23>; [100.00%]

  <bb 22> [local count: 395609036]:
  _17 = &dst_ip_29(D)->u_addr.ip4;
  iftmp.9_40 = ip4_route (_17);

  <bb 23> [local count: 1045328530]:
  # netif_21 = PHI <netif_42(8), netif_20(19), iftmp.9_40(22), iftmp.9_38(21)>
  # DEBUG netif => netif_21
  # DEBUG BEGIN_STMT
  if (netif_21 == 0B)
    goto <bb 24>; [0.91%]
  else
    goto <bb 25>; [99.09%]

  <bb 24> [local count: 9512490]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _18 = lwip_stats.udp.rterr;
  _19 = _18 + 1;
  lwip_stats.udp.rterr = _19;
  # DEBUG BEGIN_STMT
  goto <bb 26>; [100.00%]

  <bb 25> [local count: 1035816040]:
  # DEBUG BEGIN_STMT
  _45 = udp_sendto_if (pcb_27(D), p_28(D), dst_ip_29(D), dst_port_43(D), netif_21);

  <bb 26> [local count: 1073741823]:
  # _22 = PHI <-16(2), -16(3), -16(4), -6(6), -4(24), _45(25)>
  return _22;

}



;; Function udp_send (udp_send, funcdef_no=5, decl_uid=7029, cgraph_uid=6, symbol_order=8)

Modification phase of node udp_send/8
udp_send (struct udp_pcb * pcb, struct pbuf * p)
{
  unsigned char _1;
  struct ip_addr_t * _2;
  short unsigned int _3;
  err_t _4;
  err_t _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_6(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_7(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 1064099892]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_6(D)->remote_ip.type;
  if (_1 == 46)
    goto <bb 6>; [1.09%]
  else
    goto <bb 5>; [98.91%]

  <bb 5> [local count: 1052501202]:
  # DEBUG BEGIN_STMT
  _2 = &pcb_6(D)->remote_ip;
  _3 = pcb_6(D)->remote_port;
  _10 = udp_sendto (pcb_6(D), p_7(D), _2, _3);

  <bb 6> [local count: 1073741824]:
  # _4 = PHI <-16(2), -16(3), -6(4), _10(5)>
  return _4;

}



;; Function udp_bind_netif (udp_bind_netif, funcdef_no=10, decl_uid=6998, cgraph_uid=11, symbol_order=13)

Modification phase of node udp_bind_netif/13
udp_bind_netif (struct udp_pcb * pcb, const struct netif * netif)
{
  unsigned char _1;
  unsigned char _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = netif_4(D)->num;
  _2 = _1 + 1;
  pcb_6(D)->netif_idx = _2;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  pcb_6(D)->netif_idx = 0;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function udp_connect (udp_connect, funcdef_no=11, decl_uid=7002, cgraph_uid=12, symbol_order=14)

Modification phase of node udp_connect/14
udp_connect (struct udp_pcb * pcb, const struct ip_addr_t * ipaddr, u16_t port)
{
  struct netif * selected_netif;
  err_t err;
  struct udp_pcb * ipcb;
  short unsigned int _1;
  struct ip_addr_t * _2;
  unsigned char _3;
  unsigned char _4;
  unsigned char _5;
  unsigned char _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  struct ip6_addr_t * _10;
  struct ip6_addr_t * _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  unsigned char _15;
  unsigned char _16;
  unsigned char _17;
  err_t _19;
  u8_t iftmp.36_20;
  const long unsigned int iftmp.30_31;
  const long unsigned int iftmp.31_33;
  const long unsigned int iftmp.32_35;
  const long unsigned int iftmp.33_37;
  u8_t iftmp.34_39;
  const long unsigned int iftmp.35_41;
  u8_t iftmp.36_49;

  <bb 2> [local count: 130552291]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_25(D) == 0B)
    goto <bb 25>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 129964806]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_26(D) == 0B)
    goto <bb 25>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 129379964]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_25(D)->local_port;
  if (_1 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 42695388]:
  # DEBUG BEGIN_STMT
  _2 = &pcb_25(D)->local_ip;
  err_29 = udp_bind (pcb_25(D), _2, 0);
  # DEBUG err => err_29
  # DEBUG BEGIN_STMT
  if (err_29 != 0)
    goto <bb 25>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 6> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = ipaddr_26(D)->type;
  pcb_25(D)->remote_ip.type = _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = ipaddr_26(D)->type;
  if (_4 == 6)
    goto <bb 7>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 7> [local count: 39053601]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iftmp.30_31 = ipaddr_26(D)->u_addr.ip6.addr[0];
  pcb_25(D)->remote_ip.u_addr.ip6.addr[0] = iftmp.30_31;
  # DEBUG BEGIN_STMT
  iftmp.31_33 = ipaddr_26(D)->u_addr.ip6.addr[1];
  pcb_25(D)->remote_ip.u_addr.ip6.addr[1] = iftmp.31_33;
  # DEBUG BEGIN_STMT
  iftmp.32_35 = ipaddr_26(D)->u_addr.ip6.addr[2];
  pcb_25(D)->remote_ip.u_addr.ip6.addr[2] = iftmp.32_35;
  # DEBUG BEGIN_STMT
  iftmp.33_37 = ipaddr_26(D)->u_addr.ip6.addr[3];
  pcb_25(D)->remote_ip.u_addr.ip6.addr[3] = iftmp.33_37;
  # DEBUG BEGIN_STMT
  iftmp.34_39 = ipaddr_26(D)->u_addr.ip6.zone;
  pcb_25(D)->remote_ip.u_addr.ip6.zone = iftmp.34_39;
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 75809931]:
  # DEBUG BEGIN_STMT
  iftmp.35_41 = ipaddr_26(D)->u_addr.ip4.addr;
  pcb_25(D)->remote_ip.u_addr.ip4.addr = iftmp.35_41;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_25(D)->remote_ip.u_addr.ip6.addr[3] = 0;
  pcb_25(D)->remote_ip.u_addr.ip6.addr[2] = 0;
  pcb_25(D)->remote_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  pcb_25(D)->remote_ip.u_addr.ip6.zone = 0;

  <bb 9> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = pcb_25(D)->remote_ip.type;
  if (_5 == 6)
    goto <bb 10>; [34.00%]
  else
    goto <bb 20>; [66.00%]

  <bb 10> [local count: 39053601]:
  _6 = pcb_25(D)->remote_ip.u_addr.ip6.zone;
  if (_6 == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 11> [local count: 19526800]:
  _7 = pcb_25(D)->remote_ip.u_addr.ip6.addr[0];
  _8 = _7 & 49407;
  if (_8 == 33022)
    goto <bb 14>; [20.24%]
  else
    goto <bb 12>; [79.76%]

  <bb 12> [local count: 15574576]:
  _9 = _7 & 36863;
  if (_9 == 511)
    goto <bb 14>; [34.00%]
  else
    goto <bb 13>; [66.00%]

  <bb 13> [local count: 10279220]:
  if (_9 == 767)
    goto <bb 14>; [34.00%]
  else
    goto <bb 20>; [66.00%]

  <bb 14> [local count: 12742515]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = &pcb_25(D)->local_ip.u_addr.ip6;
  _11 = &pcb_25(D)->remote_ip.u_addr.ip6;
  selected_netif_48 = ip6_route (_10, _11);
  # DEBUG selected_netif => selected_netif_48
  # DEBUG BEGIN_STMT
  if (selected_netif_48 != 0B)
    goto <bb 15>; [70.00%]
  else
    goto <bb 20>; [30.00%]

  <bb 15> [local count: 8919761]:
  # DEBUG BEGIN_STMT
  _12 = pcb_25(D)->remote_ip.u_addr.ip6.addr[0];
  _13 = _12 & 49407;
  if (_13 == 33022)
    goto <bb 18>; [34.00%]
  else
    goto <bb 16>; [66.00%]

  <bb 16> [local count: 5887042]:
  _14 = _12 & 36863;
  if (_14 == 511)
    goto <bb 18>; [34.00%]
  else
    goto <bb 17>; [66.00%]

  <bb 17> [local count: 3885448]:
  if (_14 == 767)
    goto <bb 18>; [34.00%]
  else
    goto <bb 19>; [66.00%]

  <bb 18> [local count: 6355365]:
  _15 = selected_netif_48->num;
  iftmp.36_49 = _15 + 1;

  <bb 19> [local count: 8919761]:
  # iftmp.36_20 = PHI <iftmp.36_49(18), 0(17)>
  pcb_25(D)->remote_ip.u_addr.ip6.zone = iftmp.36_20;

  <bb 20> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_25(D)->remote_port = port_51(D);
  # DEBUG BEGIN_STMT
  _16 = pcb_25(D)->flags;
  _17 = _16 | 4;
  pcb_25(D)->flags = _17;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ipcb_54 = udp_pcbs;
  # DEBUG ipcb => ipcb_54
  goto <bb 23>; [100.00%]

  <bb 21> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  if (ipcb_18 == pcb_25(D))
    goto <bb 25>; [5.50%]
  else
    goto <bb 22>; [94.50%]

  <bb 22> [local count: 958878294]:
  # DEBUG BEGIN_STMT
  ipcb_57 = ipcb_18->next;
  # DEBUG ipcb => ipcb_57

  <bb 23> [local count: 1073741824]:
  # ipcb_18 = PHI <ipcb_54(20), ipcb_57(22)>
  # DEBUG ipcb => ipcb_18
  # DEBUG BEGIN_STMT
  if (ipcb_18 != 0B)
    goto <bb 21>; [94.50%]
  else
    goto <bb 24>; [5.50%]

  <bb 24> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  pcb_25(D)->next = ipcb_54;
  # DEBUG BEGIN_STMT
  udp_pcbs = pcb_25(D);
  # DEBUG BEGIN_STMT

  <bb 25> [local count: 130552291]:
  # _19 = PHI <-16(2), -16(3), err_29(5), 0(21), 0(24)>
  return _19;

}



;; Function udp_disconnect (udp_disconnect, funcdef_no=12, decl_uid=7004, cgraph_uid=13, symbol_order=15)

Modification phase of node udp_disconnect/15
udp_disconnect (struct udp_pcb * pcb)
{
  unsigned char _1;
  unsigned char _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned char _7;
  long unsigned int _8;
  unsigned char _9;
  unsigned char _10;
  unsigned char _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_14(D) == 0B)
    goto <bb 11>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_14(D)->local_ip.type;
  if (_1 == 46)
    goto <bb 4>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 4> [local count: 299030656]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = ip_addr_any_type.type;
  pcb_14(D)->remote_ip.type = _2;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_2 == 6)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 101670423]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = ip_addr_any_type.u_addr.ip6.addr[0];
  pcb_14(D)->remote_ip.u_addr.ip6.addr[0] = _3;
  # DEBUG BEGIN_STMT
  _4 = ip_addr_any_type.u_addr.ip6.addr[1];
  pcb_14(D)->remote_ip.u_addr.ip6.addr[1] = _4;
  # DEBUG BEGIN_STMT
  _5 = ip_addr_any_type.u_addr.ip6.addr[2];
  pcb_14(D)->remote_ip.u_addr.ip6.addr[2] = _5;
  # DEBUG BEGIN_STMT
  _6 = ip_addr_any_type.u_addr.ip6.addr[3];
  pcb_14(D)->remote_ip.u_addr.ip6.addr[3] = _6;
  # DEBUG BEGIN_STMT
  _7 = ip_addr_any_type.u_addr.ip6.zone;
  pcb_14(D)->remote_ip.u_addr.ip6.zone = _7;
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 6> [local count: 197360233]:
  # DEBUG BEGIN_STMT
  _8 = ip_addr_any_type.u_addr.ip4.addr;
  pcb_14(D)->remote_ip.u_addr.ip4.addr = _8;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.u_addr.ip6.addr[3] = 0;
  pcb_14(D)->remote_ip.u_addr.ip6.addr[2] = 0;
  pcb_14(D)->remote_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.u_addr.ip6.zone = 0;
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 580471273]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = pcb_14(D)->remote_ip.type;
  if (_9 == 6)
    goto <bb 8>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 8> [local count: 197360233]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.u_addr.ip6.addr[0] = 0;
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.u_addr.ip6.addr[2] = 0;
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.u_addr.ip6.addr[3] = 0;
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.u_addr.ip6.zone = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.type = 6;
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 383111040]:
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.u_addr.ip4.addr = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.type = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.u_addr.ip6.addr[3] = 0;
  pcb_14(D)->remote_ip.u_addr.ip6.addr[2] = 0;
  pcb_14(D)->remote_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_ip.u_addr.ip6.zone = 0;

  <bb 10> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_14(D)->remote_port = 0;
  # DEBUG BEGIN_STMT
  pcb_14(D)->netif_idx = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = pcb_14(D)->flags;
  _11 = _10 & 251;
  pcb_14(D)->flags = _11;

  <bb 11> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function udp_recv (udp_recv, funcdef_no=13, decl_uid=7008, cgraph_uid=14, symbol_order=16)

Modification phase of node udp_recv/16
udp_recv (struct udp_pcb * pcb, void (*udp_recv_fn) (void *, struct udp_pcb *, struct pbuf *, const struct ip_addr_t *, u16_t) recv, void * recv_arg)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_2(D) == 0B)
    goto <bb 4>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_2(D)->recv = recv_4(D);
  # DEBUG BEGIN_STMT
  pcb_2(D)->recv_arg = recv_arg_6(D);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function udp_remove (udp_remove, funcdef_no=14, decl_uid=6991, cgraph_uid=15, symbol_order=17)

Modification phase of node udp_remove/17
udp_remove (struct udp_pcb * pcb)
{
  struct udp_pcb * pcb2;
  struct udp_pcb * udp_pcbs.38_1;
  struct udp_pcb * _2;
  struct udp_pcb * _3;
  struct udp_pcb * _5;

  <bb 2> [local count: 171130708]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_9(D) == 0B)
    goto <bb 11>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 140173163]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  udp_pcbs.38_1 = udp_pcbs;
  if (udp_pcbs.38_1 == pcb_9(D))
    goto <bb 4>; [30.00%]
  else
    goto <bb 12>; [70.00%]

  <bb 12> [local count: 98121215]:
  goto <bb 9>; [100.00%]

  <bb 4> [local count: 42051949]:
  # DEBUG BEGIN_STMT
  _2 = udp_pcbs.38_1->next;
  udp_pcbs = _2;
  goto <bb 10>; [100.00%]

  <bb 5> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  _3 = pcb2_6->next;
  if (_3 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 6> [local count: 710280217]:
  if (_3 == pcb_9(D))
    goto <bb 7>; [5.50%]
  else
    goto <bb 8>; [94.50%]

  <bb 7> [local count: 39065412]:
  # pcb2_4 = PHI <pcb2_6(6)>
  # DEBUG BEGIN_STMT
  _5 = pcb_9(D)->next;
  pcb2_4->next = _5;
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 975620612]:
  # pcb2_11 = PHI <_3(6), _3(5)>

  <bb 9> [local count: 1073741824]:
  # pcb2_6 = PHI <pcb2_11(8), udp_pcbs.38_1(12)>
  # DEBUG pcb2 => pcb2_6
  # DEBUG BEGIN_STMT
  if (pcb2_6 != 0B)
    goto <bb 5>; [94.50%]
  else
    goto <bb 10>; [5.50%]

  <bb 10> [local count: 140173161]:
  # DEBUG BEGIN_STMT
  memp_free (1, pcb_9(D));

  <bb 11> [local count: 171130706]:
  return;

}



;; Function udp_new (udp_new, funcdef_no=15, decl_uid=6987, cgraph_uid=16, symbol_order=18)

Modification phase of node udp_new/18
udp_new ()
{
  struct udp_pcb * pcb;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4 = memp_malloc (1);
  # DEBUG pcb => pcb_4
  # DEBUG BEGIN_STMT
  if (pcb_4 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  memset (pcb_4, 0, 84);
  # DEBUG BEGIN_STMT
  pcb_4->ttl = 255;
  # DEBUG BEGIN_STMT
  pcb_4->mcast_ttl = 255;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return pcb_4;

}



;; Function udp_new_ip_type (udp_new_ip_type, funcdef_no=16, decl_uid=6989, cgraph_uid=17, symbol_order=19)

Modification phase of node udp_new_ip_type/19
udp_new_ip_type (u8_t type)
{
  struct udp_pcb * pcb;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4 = udp_new ();
  # DEBUG pcb => pcb_4
  # DEBUG BEGIN_STMT
  if (pcb_4 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4->local_ip.type = type_5(D);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4->remote_ip.type = type_5(D);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return pcb_4;

}



;; Function udp_netif_ip_addr_changed (udp_netif_ip_addr_changed, funcdef_no=17, decl_uid=7037, cgraph_uid=18, symbol_order=20)

Modification phase of node udp_netif_ip_addr_changed/20
udp_netif_ip_addr_changed (const struct ip_addr_t * old_addr, const struct ip_addr_t * new_addr)
{
  struct udp_pcb * upcb;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned char _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  unsigned char _13;
  unsigned char _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  unsigned char _23;
  unsigned char _24;
  long unsigned int _25;
  long unsigned int _26;
  unsigned char _27;
  unsigned char _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  long unsigned int _32;
  unsigned char _33;
  long unsigned int _34;
  _Bool iftmp.41_36;
  int iftmp.42_37;
  int iftmp.43_38;
  _Bool iftmp.45_39;
  int iftmp.46_40;
  int iftmp.47_41;
  _Bool iftmp.49_42;
  int iftmp.50_43;
  _Bool iftmp.41_49;
  _Bool iftmp.41_50;
  _Bool iftmp.45_52;
  _Bool iftmp.45_53;
  _Bool iftmp.49_55;
  _Bool iftmp.49_56;

  <bb 2> [local count: 964176328]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (old_addr_47(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 43>; [30.00%]

  <bb 3> [local count: 674923430]:
  _1 = old_addr_47(D)->type;
  if (_1 == 6)
    goto <bb 4>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 4> [local count: 229473966]:
  _2 = old_addr_47(D)->u_addr.ip6.addr[0];
  if (_2 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 114736983]:
  _3 = old_addr_47(D)->u_addr.ip6.addr[1];
  if (_3 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 57368491]:
  _4 = old_addr_47(D)->u_addr.ip6.addr[2];
  if (_4 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 28684246]:
  _5 = old_addr_47(D)->u_addr.ip6.addr[3];
  if (_5 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 14342123]:

  <bb 9> [local count: 229473966]:
  # iftmp.42_37 = PHI <1(5), 0(8), 1(4), 1(7), 1(6)>
  iftmp.41_49 = (_Bool) iftmp.42_37;
  goto <bb 13>; [100.00%]

  <bb 10> [local count: 445449463]:
  _6 = old_addr_47(D)->u_addr.ip4.addr;
  if (_6 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 11> [local count: 222724732]:

  <bb 12> [local count: 445449463]:
  # iftmp.43_38 = PHI <1(10), 0(11)>
  iftmp.41_50 = (_Bool) iftmp.43_38;

  <bb 13> [local count: 674923430]:
  # iftmp.41_36 = PHI <iftmp.41_49(9), iftmp.41_50(12)>
  if (iftmp.41_36 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 43>; [50.00%]

  <bb 14> [local count: 337461715]:
  if (new_addr_51(D) != 0B)
    goto <bb 15>; [70.00%]
  else
    goto <bb 43>; [30.00%]

  <bb 15> [local count: 236223200]:
  _7 = new_addr_51(D)->type;
  if (_7 == 6)
    goto <bb 16>; [34.00%]
  else
    goto <bb 22>; [66.00%]

  <bb 16> [local count: 80315888]:
  _8 = new_addr_51(D)->u_addr.ip6.addr[0];
  if (_8 != 0)
    goto <bb 21>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 17> [local count: 40157944]:
  _9 = new_addr_51(D)->u_addr.ip6.addr[1];
  if (_9 != 0)
    goto <bb 21>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 18> [local count: 20078972]:
  _10 = new_addr_51(D)->u_addr.ip6.addr[2];
  if (_10 != 0)
    goto <bb 21>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 19> [local count: 10039486]:
  _11 = new_addr_51(D)->u_addr.ip6.addr[3];
  if (_11 != 0)
    goto <bb 21>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 20> [local count: 5019743]:

  <bb 21> [local count: 80315888]:
  # iftmp.46_40 = PHI <1(17), 0(20), 1(16), 1(19), 1(18)>
  iftmp.45_52 = (_Bool) iftmp.46_40;
  goto <bb 25>; [100.00%]

  <bb 22> [local count: 155907312]:
  _12 = new_addr_51(D)->u_addr.ip4.addr;
  if (_12 != 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 23> [local count: 77953656]:

  <bb 24> [local count: 155907312]:
  # iftmp.47_41 = PHI <1(22), 0(23)>
  iftmp.45_53 = (_Bool) iftmp.47_41;

  <bb 25> [local count: 236223200]:
  # iftmp.45_39 = PHI <iftmp.45_52(21), iftmp.45_53(24)>
  if (iftmp.45_39 != 0)
    goto <bb 26>; [50.00%]
  else
    goto <bb 43>; [50.00%]

  <bb 26> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  upcb_54 = udp_pcbs;
  # DEBUG upcb => upcb_54
  goto <bb 42>; [100.00%]

  <bb 27> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _13 = upcb_35->local_ip.type;
  _14 = old_addr_47(D)->type;
  if (_13 == _14)
    goto <bb 28>; [34.00%]
  else
    goto <bb 41>; [66.00%]

  <bb 28> [local count: 324914276]:
  if (_13 == 6)
    goto <bb 29>; [34.00%]
  else
    goto <bb 36>; [66.00%]

  <bb 29> [local count: 110470854]:
  _15 = upcb_35->local_ip.u_addr.ip6.addr[0];
  _16 = old_addr_47(D)->u_addr.ip6.addr[0];
  if (_15 == _16)
    goto <bb 30>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 30> [local count: 37560090]:
  _17 = upcb_35->local_ip.u_addr.ip6.addr[1];
  _18 = old_addr_47(D)->u_addr.ip6.addr[1];
  if (_17 == _18)
    goto <bb 31>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 31> [local count: 12770431]:
  _19 = upcb_35->local_ip.u_addr.ip6.addr[2];
  _20 = old_addr_47(D)->u_addr.ip6.addr[2];
  if (_19 == _20)
    goto <bb 32>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 32> [local count: 4341946]:
  _21 = upcb_35->local_ip.u_addr.ip6.addr[3];
  _22 = old_addr_47(D)->u_addr.ip6.addr[3];
  if (_21 == _22)
    goto <bb 33>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 33> [local count: 1476262]:
  _23 = upcb_35->local_ip.u_addr.ip6.zone;
  _24 = old_addr_47(D)->u_addr.ip6.zone;
  if (_23 == _24)
    goto <bb 35>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 34> [local count: 109968925]:

  <bb 35> [local count: 110470854]:
  # iftmp.50_43 = PHI <1(33), 0(34)>
  iftmp.49_56 = (_Bool) iftmp.50_43;
  goto <bb 37>; [100.00%]

  <bb 36> [local count: 214443422]:
  _25 = upcb_35->local_ip.u_addr.ip4.addr;
  _26 = old_addr_47(D)->u_addr.ip4.addr;
  iftmp.49_55 = _25 == _26;

  <bb 37> [local count: 324914276]:
  # iftmp.49_42 = PHI <iftmp.49_56(35), iftmp.49_55(36)>
  if (iftmp.49_42 != 0)
    goto <bb 38>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 38> [local count: 162457138]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _27 = new_addr_51(D)->type;
  upcb_35->local_ip.type = _27;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _28 = new_addr_51(D)->type;
  if (_28 == 6)
    goto <bb 39>; [34.00%]
  else
    goto <bb 40>; [66.00%]

  <bb 39> [local count: 55235427]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _29 = new_addr_51(D)->u_addr.ip6.addr[0];
  upcb_35->local_ip.u_addr.ip6.addr[0] = _29;
  # DEBUG BEGIN_STMT
  _30 = new_addr_51(D)->u_addr.ip6.addr[1];
  upcb_35->local_ip.u_addr.ip6.addr[1] = _30;
  # DEBUG BEGIN_STMT
  _31 = new_addr_51(D)->u_addr.ip6.addr[2];
  upcb_35->local_ip.u_addr.ip6.addr[2] = _31;
  # DEBUG BEGIN_STMT
  _32 = new_addr_51(D)->u_addr.ip6.addr[3];
  upcb_35->local_ip.u_addr.ip6.addr[3] = _32;
  # DEBUG BEGIN_STMT
  _33 = new_addr_51(D)->u_addr.ip6.zone;
  upcb_35->local_ip.u_addr.ip6.zone = _33;
  # DEBUG BEGIN_STMT
  goto <bb 41>; [100.00%]

  <bb 40> [local count: 107221711]:
  # DEBUG BEGIN_STMT
  _34 = new_addr_51(D)->u_addr.ip4.addr;
  upcb_35->local_ip.u_addr.ip4.addr = _34;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  upcb_35->local_ip.u_addr.ip6.addr[3] = 0;
  upcb_35->local_ip.u_addr.ip6.addr[2] = 0;
  upcb_35->local_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  upcb_35->local_ip.u_addr.ip6.zone = 0;

  <bb 41> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  upcb_68 = upcb_35->next;
  # DEBUG upcb => upcb_68

  <bb 42> [local count: 1073741824]:
  # upcb_35 = PHI <upcb_54(26), upcb_68(41)>
  # DEBUG upcb => upcb_35
  # DEBUG BEGIN_STMT
  if (upcb_35 != 0B)
    goto <bb 27>; [89.00%]
  else
    goto <bb 43>; [11.00%]

  <bb 43> [local count: 964176330]:
  return;

}


