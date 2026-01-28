
IPA constant propagation start:
Determining dynamic type for call: _67 = _66 (netif_61(D), p_13(D), dest_64);
  Starting walk at: _67 = _66 (netif_61(D), p_13(D), dest_64);
  instance pointer: netif_61(D)  Outer instance pointer: netif_61(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_46 = lwip_htons (ip_id.5_45);
  Function call may change dynamic type:_44 = lwip_htons (_43);
  Function call may change dynamic type:_28 = pbuf_add_header (p_13(D), 20);
  Function call may change dynamic type:memcpy (_19, ip_options_21(D), _20);
  Function call may change dynamic type:_14 = pbuf_add_header (p_13(D), _12);
  Function call may change dynamic type:memset (_23, 0, _27);
Determining dynamic type for call: _67 = _66 (netif_61(D), p_13(D), dest_64);
  Starting walk at: _67 = _66 (netif_61(D), p_13(D), dest_64);
  instance pointer: p_13(D)  Outer instance pointer: p_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_46 = lwip_htons (ip_id.5_45);
  Function call may change dynamic type:_44 = lwip_htons (_43);
  Function call may change dynamic type:_28 = pbuf_add_header (p_13(D), 20);
  Function call may change dynamic type:memcpy (_19, ip_options_21(D), _20);
  Function call may change dynamic type:_14 = pbuf_add_header (p_13(D), _12);
  Function call may change dynamic type:memset (_23, 0, _27);
Determining dynamic type for call: _67 = _66 (netif_61(D), p_13(D), dest_64);
  Starting walk at: _67 = _66 (netif_61(D), p_13(D), dest_64);
  instance pointer: dest_64  Outer instance pointer: dest_64 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_46 = lwip_htons (ip_id.5_45);
  Function call may change dynamic type:_44 = lwip_htons (_43);
  Function call may change dynamic type:_28 = pbuf_add_header (p_13(D), 20);
  Function call may change dynamic type:memcpy (_19, ip_options_21(D), _20);
  Function call may change dynamic type:_14 = pbuf_add_header (p_13(D), _12);
  Function call may change dynamic type:memset (_23, 0, _27);
Determining dynamic type for call: netif_11 = ip4_route (dest_9(D));
  Starting walk at: netif_11 = ip4_route (dest_9(D));
  instance pointer: dest_9(D)  Outer instance pointer: dest_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _17 = ip4_output_if (p_8(D), src_12(D), dest_9(D), ttl_13(D), tos_14(D), proto_15(D), netif_11);
  Starting walk at: _17 = ip4_output_if (p_8(D), src_12(D), dest_9(D), ttl_13(D), tos_14(D), proto_15(D), netif_11);
  instance pointer: p_8(D)  Outer instance pointer: p_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_11 = ip4_route (dest_9(D));
Determining dynamic type for call: _17 = ip4_output_if (p_8(D), src_12(D), dest_9(D), ttl_13(D), tos_14(D), proto_15(D), netif_11);
  Starting walk at: _17 = ip4_output_if (p_8(D), src_12(D), dest_9(D), ttl_13(D), tos_14(D), proto_15(D), netif_11);
  instance pointer: src_12(D)  Outer instance pointer: src_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_11 = ip4_route (dest_9(D));
Determining dynamic type for call: _17 = ip4_output_if (p_8(D), src_12(D), dest_9(D), ttl_13(D), tos_14(D), proto_15(D), netif_11);
  Starting walk at: _17 = ip4_output_if (p_8(D), src_12(D), dest_9(D), ttl_13(D), tos_14(D), proto_15(D), netif_11);
  instance pointer: dest_9(D)  Outer instance pointer: dest_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_11 = ip4_route (dest_9(D));
Determining dynamic type for call: _17 = ip4_output_if (p_8(D), src_12(D), dest_9(D), ttl_13(D), tos_14(D), proto_15(D), netif_11);
  Starting walk at: _17 = ip4_output_if (p_8(D), src_12(D), dest_9(D), ttl_13(D), tos_14(D), proto_15(D), netif_11);
  instance pointer: netif_11  Outer instance pointer: netif_11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_11 = ip4_route (dest_9(D));
Determining dynamic type for call: _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  Starting walk at: _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  instance pointer: p_6(D)  Outer instance pointer: p_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  Starting walk at: _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  instance pointer: src_13(D)  Outer instance pointer: src_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  Starting walk at: _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  instance pointer: dest_7(D)  Outer instance pointer: dest_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  Starting walk at: _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  instance pointer: netif_14(D)  Outer instance pointer: netif_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  Starting walk at: _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  instance pointer: ip_options_9(D)  Outer instance pointer: ip_options_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  Starting walk at: _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  Starting walk at: _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  instance pointer: src_3(D)  Outer instance pointer: src_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  Starting walk at: _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  instance pointer: dest_4(D)  Outer instance pointer: dest_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  Starting walk at: _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  instance pointer: netif_8(D)  Outer instance pointer: netif_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  Starting walk at: _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  Starting walk at: _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  instance pointer: p_8(D)  Outer instance pointer: p_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  Starting walk at: _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  instance pointer: src_used_2  Outer instance pointer: src_used_2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  Starting walk at: _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  instance pointer: dest_4(D)  Outer instance pointer: dest_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  Starting walk at: _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  instance pointer: netif_6(D)  Outer instance pointer: netif_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  Starting walk at: _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  instance pointer: ip_options_12(D)  Outer instance pointer: ip_options_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  Starting walk at: _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  Starting walk at: _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  instance pointer: src_3(D)  Outer instance pointer: src_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  Starting walk at: _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  instance pointer: dest_4(D)  Outer instance pointer: dest_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  Starting walk at: _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  instance pointer: netif_8(D)  Outer instance pointer: netif_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  Starting walk at: _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _32 = ip4_input_accept (inp_112(D));
  Starting walk at: _32 = ip4_input_accept (inp_112(D));
  instance pointer: inp_112(D)  Outer instance pointer: inp_112(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:iphdr_len_98 = lwip_htons (_15);
  Function call may change dynamic type:pbuf_realloc (p_94(D), iphdr_len_98);
Determining dynamic type for call: _35 = ip4_input_accept (netif_80);
  Starting walk at: _35 = ip4_input_accept (netif_80);
  instance pointer: netif_80  Outer instance pointer: netif_80 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_32 = ip4_input_accept (inp_112(D));
  Function call may change dynamic type:iphdr_len_98 = lwip_htons (_15);
  Function call may change dynamic type:pbuf_realloc (p_94(D), iphdr_len_98);
  Function call may change dynamic type:_35 = ip4_input_accept (netif_80);
Determining dynamic type for call: _6 = ip4_input_accept.part.0 (netif_8(D));
  Starting walk at: _6 = ip4_input_accept.part.0 (netif_8(D));
  instance pointer: netif_8(D)  Outer instance pointer: netif_8(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  ip4_output_if_opt_src.part.0/36:
    indirect aggregate callsite, calling param 6, offset 1440, by reference, for stmt _67 = _66 (netif_61(D), p_13(D), dest_64);
       param 0: PASS THROUGH: 6, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ip4_input_accept.part.0/35:
  Jump functions of caller  ip4_frag/34:
  Jump functions of caller  memset/32:
  Jump functions of caller  memcpy/31:
  Jump functions of caller  pbuf_add_header/30:
  Jump functions of caller  icmp_dest_unreach/29:
  Jump functions of caller  pbuf_header_force/28:
  Jump functions of caller  igmp_input/27:
  Jump functions of caller  icmp_input/26:
  Jump functions of caller  tcp_input/25:
  Jump functions of caller  udp_input/24:
  Jump functions of caller  pbuf_remove_header/23:
  Jump functions of caller  raw_input/22:
  Jump functions of caller  ip4_reass/21:
  Jump functions of caller  ip4_addr_isbroadcast_u32/20:
  Jump functions of caller  igmp_lookfor_group/19:
  Jump functions of caller  pbuf_realloc/18:
  Jump functions of caller  lwip_htons/17:
  Jump functions of caller  pbuf_free/16:
  Jump functions of caller  ip4_output/12:
    callsite  ip4_output/12 -> ip4_output_if/8 : 
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
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ip4_output/12 -> ip4_route/4 : 
       param 0: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ip4_output_if_opt_src/11:
    callsite  ip4_output_if_opt_src/11 -> ip4_output_if_opt_src.part.0/36 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: PASS THROUGH: 6, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 7: PASS THROUGH: 7, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 8: PASS THROUGH: 8, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  ip4_output_if_src/10:
    callsite  ip4_output_if_src/10 -> ip4_output_if_opt_src/11 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: PASS THROUGH: 6, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 7: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 8: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  ip4_output_if_opt/9:
    callsite  ip4_output_if_opt/9 -> ip4_output_if_opt_src/11 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: PASS THROUGH: 6, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 7: PASS THROUGH: 7, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 8: PASS THROUGH: 8, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  ip4_output_if/8:
    callsite  ip4_output_if/8 -> ip4_output_if_opt/9 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: PASS THROUGH: 6, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 7: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 8: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  ip4_input/7:
    callsite  ip4_input/7 -> ip4_input_accept/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ip4_input/7 -> ip4_input_accept/5 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ip4_input_accept/5:
    callsite  ip4_input_accept/5 -> ip4_input_accept.part.0/35 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ip4_route/4:
  Jump functions of caller  ip4_set_default_multicast_netif/3:

 Propagating constants:

Not considering ip4_output for cloning; -fipa-cp-clone disabled.
Not considering ip4_output_if_opt_src for cloning; -fipa-cp-clone disabled.
Not considering ip4_output_if_src for cloning; -fipa-cp-clone disabled.
Not considering ip4_output_if_opt for cloning; -fipa-cp-clone disabled.
Not considering ip4_output_if for cloning; -fipa-cp-clone disabled.
Not considering ip4_input for cloning; -fipa-cp-clone disabled.
Not considering ip4_route for cloning; -fipa-cp-clone disabled.
Not considering ip4_set_default_multicast_netif for cloning; -fipa-cp-clone disabled.

overall_size: 546, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: ip4_output_if_opt_src.part.0/36:
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
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
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
    param [6]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [7]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [8]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ip4_input_accept.part.0/35:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ip4_output/12:
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
  Node: ip4_output_if_opt_src/11:
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
    param [6]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [7]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [8]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ip4_output_if_src/10:
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
    param [6]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ip4_output_if_opt/9:
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
    param [6]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [7]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [8]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ip4_output_if/8:
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
    param [6]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ip4_input/7:
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
  Node: ip4_input_accept/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ip4_route/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ip4_set_default_multicast_netif/3:
    param [0]: BOTTOM
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

ip4_output_if_opt_src.part.0/36 (ip4_output_if_opt_src.part.0) @06228700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)ip_id/1 (read)ip_id/1 (read)ip_id/1 (write)ip_addr_any/33 (read)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)
  Referring: 
  Availability: local
  Function flags: count:237943 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: ip4_output_if_opt_src/11 (55314 (estimated locally),0.34 per call) 
  Calls: pbuf_add_header/30 (109263 (estimated locally),0.46 per call) memcpy/31 (106979 (estimated locally),0.45 per call) memset/32 (35303 (estimated locally),0.15 per call) pbuf_add_header/30 (161944 (estimated locally),0.68 per call) lwip_htons/17 (52886 (estimated locally),0.22 per call) lwip_htons/17 (52886 (estimated locally),0.22 per call) ip4_frag/34 (12501 (estimated locally),0.05 per call) 
   Indirect call(111025 (estimated locally),0.47 per call)  of param:6 loaded from aggregate passed by reference at offset 1440 (vptr maybe changed)
ip4_input_accept.part.0/35 (ip4_input_accept.part.0) @05f458c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ip_data/6 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: ip4_input_accept/5 (536870912 (estimated locally),0.50 per call) 
  Calls: ip4_addr_isbroadcast_u32/20 (348912405 (estimated locally),0.32 per call) 
ip4_frag/34 (ip4_frag) @061f2e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_output_if_opt_src.part.0/36 (12501 (estimated locally),0.05 per call) 
  Calls: 
ip_addr_any/33 (ip_addr_any) @061f7d80
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: ip4_output_if_opt_src.part.0/36 (read)
  Availability: not_available
  Varpool flags: read-only
memset/32 (memset) @061f2d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_output_if_opt_src.part.0/36 (35303 (estimated locally),0.15 per call) 
  Calls: 
memcpy/31 (memcpy) @061f2c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_output_if_opt_src.part.0/36 (106979 (estimated locally),0.45 per call) 
  Calls: 
pbuf_add_header/30 (pbuf_add_header) @061f2b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_output_if_opt_src.part.0/36 (109263 (estimated locally),0.46 per call) ip4_output_if_opt_src.part.0/36 (161944 (estimated locally),0.68 per call) 
  Calls: 
icmp_dest_unreach/29 (icmp_dest_unreach) @061f2380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (1139676 (estimated locally),0.00 per call) 
  Calls: 
pbuf_header_force/28 (pbuf_header_force) @061f22a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (1139676 (estimated locally),0.00 per call) 
  Calls: 
igmp_input/27 (igmp_input) @061f21c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (9540016 (estimated locally),0.01 per call) 
  Calls: 
icmp_input/26 (icmp_input) @061f20e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (9540016 (estimated locally),0.01 per call) 
  Calls: 
tcp_input/25 (tcp_input) @061f2000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (9540016 (estimated locally),0.01 per call) 
  Calls: 
udp_input/24 (udp_input) @06196d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (9540016 (estimated locally),0.01 per call) 
  Calls: 
pbuf_remove_header/23 (pbuf_remove_header) @06196b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (47700079 (estimated locally),0.04 per call) 
  Calls: 
raw_input/22 (raw_input) @06196a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (97586087 (estimated locally),0.09 per call) 
  Calls: 
ip4_reass/21 (ip4_reass) @061969a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (53645257 (estimated locally),0.05 per call) 
  Calls: 
ip4_addr_isbroadcast_u32/20 (ip4_addr_isbroadcast_u32) @061968c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (4663160 (estimated locally),0.00 per call) ip4_input/7 (182783002 (estimated locally),0.17 per call) ip4_input_accept.part.0/35 (348912405 (estimated locally),0.32 per call) 
  Calls: 
igmp_lookfor_group/19 (igmp_lookfor_group) @061960e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (31466445 (estimated locally),0.03 per call) 
  Calls: 
pbuf_realloc/18 (pbuf_realloc) @06196ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (177167401 (estimated locally),0.17 per call) 
  Calls: 
lwip_htons/17 (lwip_htons) @06196e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_output_if_opt_src.part.0/36 (52886 (estimated locally),0.22 per call) ip4_output_if_opt_src.part.0/36 (52886 (estimated locally),0.22 per call) ip4_input/7 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pbuf_free/16 (pbuf_free) @06196c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ip4_input/7 (9540016 (estimated locally),0.01 per call) ip4_input/7 (11670029 (estimated locally),0.01 per call) ip4_input/7 (67566965 (estimated locally),0.06 per call) ip4_input/7 (350343403 (estimated locally),0.33 per call) ip4_input/7 (536870913 (estimated locally),0.50 per call) 
  Calls: 
lwip_stats/15 (lwip_stats) @061cf438
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: ip4_route/4 (read)ip4_route/4 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_route/4 (read)ip4_route/4 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (read)ip4_input/7 (write)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)ip4_output/12 (read)ip4_output/12 (write)
  Availability: not_available
  Varpool flags:
netif_default/14 (netif_default) @061cf3f0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: ip4_route/4 (read)
  Availability: not_available
  Varpool flags:
netif_list/13 (netif_list) @061cf3a8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: ip4_route/4 (read)ip4_input/7 (read)
  Availability: not_available
  Varpool flags:
ip4_output/12 (ip4_output) @061962a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/15 (read)lwip_stats/15 (write)
  Referring: 
  Availability: available
  Function flags: count:134621 (estimated locally) body optimize_size
  Called by: 
  Calls: ip4_output_if/8 (26999 (estimated locally),0.20 per call) ip4_route/4 (27247 (estimated locally),0.20 per call) 
ip4_output_if_opt_src/11 (ip4_output_if_opt_src) @06196000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:162688 (estimated locally) body optimize_size
  Called by: ip4_output_if_src/10 (1073741824 (estimated locally),1.00 per call) ip4_output_if_opt/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: ip4_output_if_opt_src.part.0/36 (55314 (estimated locally),0.34 per call) 
ip4_output_if_src/10 (ip4_output_if_src) @06169d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ip4_output_if_opt_src/11 (1073741824 (estimated locally),1.00 per call) 
ip4_output_if_opt/9 (ip4_output_if_opt) @06169a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: ip4_output_if/8 (1073741824 (estimated locally),1.00 per call) 
  Calls: ip4_output_if_opt_src/11 (1073741824 (estimated locally),1.00 per call) 
ip4_output_if/8 (ip4_output_if) @06169540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: ip4_output/12 (26999 (estimated locally),0.20 per call) 
  Calls: ip4_output_if_opt/9 (1073741824 (estimated locally),1.00 per call) 
ip4_input/7 (ip4_input) @061692a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (addr)ip_data/6 (read)ip_data/6 (read)ip_data/6 (read)netif_list/13 (read)ip_data/6 (read)ip_data/6 (read)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)ip_data/6 (addr)lwip_stats/15 (read)lwip_stats/15 (write)ip_data/6 (read)ip_data/6 (read)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)ip_data/6 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/16 (9540016 (estimated locally),0.01 per call) icmp_dest_unreach/29 (1139676 (estimated locally),0.00 per call) pbuf_header_force/28 (1139676 (estimated locally),0.00 per call) ip4_addr_isbroadcast_u32/20 (4663160 (estimated locally),0.00 per call) igmp_input/27 (9540016 (estimated locally),0.01 per call) icmp_input/26 (9540016 (estimated locally),0.01 per call) tcp_input/25 (9540016 (estimated locally),0.01 per call) udp_input/24 (9540016 (estimated locally),0.01 per call) pbuf_remove_header/23 (47700079 (estimated locally),0.04 per call) raw_input/22 (97586087 (estimated locally),0.09 per call) ip4_reass/21 (53645257 (estimated locally),0.05 per call) pbuf_free/16 (11670029 (estimated locally),0.01 per call) pbuf_free/16 (67566965 (estimated locally),0.06 per call) ip4_addr_isbroadcast_u32/20 (182783002 (estimated locally),0.17 per call) ip4_input_accept/5 (217798474 (estimated locally),0.20 per call) ip4_input_accept/5 (91174646 (estimated locally),0.08 per call) igmp_lookfor_group/19 (31466445 (estimated locally),0.03 per call) pbuf_free/16 (350343403 (estimated locally),0.33 per call) pbuf_realloc/18 (177167401 (estimated locally),0.17 per call) lwip_htons/17 (536870913 (estimated locally),0.50 per call) pbuf_free/16 (536870913 (estimated locally),0.50 per call) 
ip_data/6 (ip_data) @0615e120
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: ip4_input_accept.part.0/35 (read)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (addr)ip4_input/7 (read)ip4_input/7 (read)ip4_input/7 (read)ip4_input/7 (read)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (addr)ip4_input/7 (read)ip4_input/7 (read)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)ip4_input/7 (write)
  Availability: not_available
  Varpool flags:
ip4_input_accept/5 (ip4_input_accept) @06150b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: ip4_input/7 (217798474 (estimated locally),0.20 per call) ip4_input/7 (91174646 (estimated locally),0.08 per call) 
  Calls: ip4_input_accept.part.0/35 (536870912 (estimated locally),0.50 per call) 
ip4_route/4 (ip4_route) @061502a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip4_default_multicast_netif/2 (read)netif_list/13 (read)netif_default/14 (read)lwip_stats/15 (read)lwip_stats/15 (write)lwip_stats/15 (read)lwip_stats/15 (write)
  Referring: 
  Availability: available
  Function flags: count:56865851 (estimated locally) body optimize_size
  Called by: ip4_output/12 (27247 (estimated locally),0.20 per call) 
  Calls: 
ip4_set_default_multicast_netif/3 (ip4_set_default_multicast_netif) @06146380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip4_default_multicast_netif/2 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ip4_default_multicast_netif/2 (ip4_default_multicast_netif) @06145ab0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ip4_set_default_multicast_netif/3 (write)ip4_route/4 (read)
  Availability: available
  Varpool flags:
ip_id/1 (ip_id) @06145a20
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (read)ip4_output_if_opt_src.part.0/36 (write)
  Availability: available
  Varpool flags:

;; Function ip4_input_accept (ip4_input_accept, funcdef_no=3, decl_uid=7729, cgraph_uid=4, symbol_order=5)

Modification phase of node ip4_input_accept/5
ip4_input_accept (struct netif * netif)
{
  unsigned char _1;
  _Bool _2;
  int _5;
  int _6;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_8(D)->flags;
  _2 = (_Bool) _1;
  if (_2 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870912]:
  _6 = ip4_input_accept.part.0 (netif_8(D));

  <bb 4> [local count: 1073741824]:
  # _5 = PHI <_6(3), 0(2)>
  return _5;

}



;; Function ip4_set_default_multicast_netif (ip4_set_default_multicast_netif, funcdef_no=1, decl_uid=6871, cgraph_uid=2, symbol_order=3)

Modification phase of node ip4_set_default_multicast_netif/3
ip4_set_default_multicast_netif (struct netif * default_multicast_netif)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ip4_default_multicast_netif = default_multicast_netif_2(D);
  return;

}



;; Function ip4_route (ip4_route, funcdef_no=2, decl_uid=6823, cgraph_uid=3, symbol_order=4)

Modification phase of node ip4_route/4
ip4_route (const struct ip4_addr_t * dest)
{
  struct netif * netif;
  long unsigned int _1;
  long unsigned int _2;
  struct netif * ip4_default_multicast_netif.0_3;
  unsigned char _4;
  _Bool _5;
  unsigned int _6;
  unsigned int _7;
  _Bool _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  struct netif * netif_default.1_14;
  unsigned char _16;
  long unsigned int _17;
  long unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  struct netif * _24;
  unsigned char _32;
  unsigned char _34;

  <bb 2> [local count: 56865851]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = dest_27(D)->addr;
  _2 = _1 & 240;
  if (_2 == 224)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 19334389]:
  ip4_default_multicast_netif.0_3 = ip4_default_multicast_netif;
  if (ip4_default_multicast_netif.0_3 != 0B)
    goto <bb 20>; [54.59%]
  else
    goto <bb 4>; [45.41%]

  <bb 4> [local count: 46311208]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_29 = netif_list;
  # DEBUG netif => netif_29
  goto <bb 14>; [100.00%]

  <bb 5> [local count: 1034442874]:
  # DEBUG BEGIN_STMT
  _4 = netif_23->flags;
  _5 = (_Bool) _4;
  if (_5 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 6> [local count: 517221437]:
  _6 = (unsigned int) _4;
  _7 = _6 >> 2;
  _8 = (_Bool) _7;
  if (_8 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 7> [local count: 258610718]:
  _9 = MEM[(const struct ip4_addr_t *)netif_23 + 4B].addr;
  if (_9 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 8> [local count: 129305359]:
  # DEBUG BEGIN_STMT
  _10 = _1 ^ _9;
  _11 = MEM[(const struct ip4_addr_t *)netif_23 + 28B].addr;
  _12 = _10 & _11;
  if (_12 == 0)
    goto <bb 9>; [3.66%]
  else
    goto <bb 10>; [96.34%]

  <bb 9> [local count: 4732576]:
  # netif_28 = PHI <netif_23(8)>
  # DEBUG BEGIN_STMT
  goto <bb 20>; [100.00%]

  <bb 10> [local count: 124572783]:
  # DEBUG BEGIN_STMT
  _34 = _4 & 2;
  if (_34 == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 11> [local count: 62286392]:
  _13 = MEM[(const struct ip4_addr_t *)netif_23 + 52B].addr;
  if (_1 == _13)
    goto <bb 12>; [3.66%]
  else
    goto <bb 13>; [96.34%]

  <bb 12> [local count: 2279682]:
  # netif_15 = PHI <netif_23(11)>
  # DEBUG BEGIN_STMT
  goto <bb 20>; [100.00%]

  <bb 13> [local count: 1027430617]:
  # DEBUG BEGIN_STMT
  netif_33 = netif_23->next;
  # DEBUG netif => netif_33

  <bb 14> [local count: 1073741824]:
  # netif_23 = PHI <netif_29(4), netif_33(13)>
  # DEBUG netif => netif_23
  # DEBUG BEGIN_STMT
  if (netif_23 != 0B)
    goto <bb 5>; [96.34%]
  else
    goto <bb 15>; [3.66%]

  <bb 15> [local count: 39298951]:
  # DEBUG BEGIN_STMT
  netif_default.1_14 = netif_default;
  if (netif_default.1_14 == 0B)
    goto <bb 19>; [8.27%]
  else
    goto <bb 16>; [91.73%]

  <bb 16> [local count: 36048928]:
  _16 = netif_default.1_14->flags;
  _32 = _16 & 5;
  if (_32 != 5)
    goto <bb 19>; [29.00%]
  else
    goto <bb 17>; [71.00%]

  <bb 17> [local count: 25594739]:
  _17 = MEM[(const struct ip4_addr_t *)netif_default.1_14 + 4B].addr;
  if (_17 == 0)
    goto <bb 19>; [17.38%]
  else
    goto <bb 18>; [82.62%]

  <bb 18> [local count: 21146373]:
  _18 = _1 & 255;
  if (_18 == 127)
    goto <bb 19>; [9.78%]
  else
    goto <bb 20>; [90.22%]

  <bb 19> [local count: 20220693]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = lwip_stats.ip.rterr;
  _20 = _19 + 1;
  lwip_stats.ip.rterr = _20;
  # DEBUG BEGIN_STMT
  _21 = lwip_stats.mib2.ipoutnoroutes;
  _22 = _21 + 1;
  lwip_stats.mib2.ipoutnoroutes = _22;
  # DEBUG BEGIN_STMT

  <bb 20> [local count: 56865852]:
  # _24 = PHI <ip4_default_multicast_netif.0_3(3), netif_28(9), netif_15(12), 0B(19), netif_default.1_14(18)>
  return _24;

}



;; Function ip4_input (ip4_input, funcdef_no=4, decl_uid=6826, cgraph_uid=5, symbol_order=7)

Modification phase of node ip4_input/7
ip4_input (struct pbuf * p, struct netif * inp)
{
  raw_input_state_t raw_status;
  u16_t iphdr_len;
  u16_t iphdr_hlen;
  struct netif * netif;
  const struct ip_hdr * iphdr;
  short unsigned int _1;
  short unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  unsigned char _5;
  unsigned char _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  unsigned char _13;
  unsigned char _14;
  short unsigned int _15;
  short unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int _21;
  short unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  unsigned char _28;
  struct igmp_group * _29;
  long unsigned int _30;
  long unsigned int _31;
  int _32;
  long unsigned int _33;
  long unsigned int _34;
  int _35;
  long unsigned int _36;
  unsigned char _37;
  long unsigned int _38;
  long unsigned int _39;
  short unsigned int _40;
  short unsigned int _41;
  long unsigned int _42;
  long unsigned int _43;
  long unsigned int _44;
  long unsigned int _45;
  short unsigned int _46;
  short unsigned int _47;
  long unsigned int _48;
  long unsigned int _49;
  long unsigned int _50;
  long unsigned int _51;
  short unsigned int _52;
  unsigned char _53;
  unsigned char _54;
  unsigned char _55;
  short unsigned int _56;
  unsigned int _57;
  unsigned char _58;
  long unsigned int _59;
  long unsigned int _60;
  long unsigned int _61;
  long unsigned int _62;
  long unsigned int _63;
  long unsigned int _64;
  long unsigned int _65;
  long unsigned int _66;
  long unsigned int _67;
  unsigned char _68;
  long unsigned int _69;
  long unsigned int _70;
  short int iphdr_hlen.4_71;
  short unsigned int _72;
  short unsigned int _73;
  short unsigned int _74;
  short unsigned int _75;
  long unsigned int _76;
  long unsigned int _77;
  unsigned char _90;
  short unsigned int _114;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG check_ip_src => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = lwip_stats.ip.recv;
  _2 = _1 + 1;
  lwip_stats.ip.recv = _2;
  # DEBUG BEGIN_STMT
  _3 = lwip_stats.mib2.ipinreceives;
  _4 = _3 + 1;
  lwip_stats.mib2.ipinreceives = _4;
  # DEBUG BEGIN_STMT
  iphdr_95 = p_94(D)->payload;
  # DEBUG iphdr => iphdr_95
  # DEBUG BEGIN_STMT
  _5 = iphdr_95->_v_hl;
  _6 = _5 >> 4;
  if (_6 != 4)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_94(D));
  # DEBUG BEGIN_STMT
  _7 = lwip_stats.ip.err;
  _8 = _7 + 1;
  lwip_stats.ip.err = _8;
  # DEBUG BEGIN_STMT
  _9 = lwip_stats.ip.drop;
  _10 = _9 + 1;
  lwip_stats.ip.drop = _10;
  # DEBUG BEGIN_STMT
  _11 = lwip_stats.mib2.ipinhdrerrors;
  _12 = _11 + 1;
  lwip_stats.mib2.ipinhdrerrors = _12;
  # DEBUG BEGIN_STMT
  goto <bb 45>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _13 = _5 & 15;
  _14 = _13 * 4;
  iphdr_hlen_96 = (u16_t) _14;
  # DEBUG iphdr_hlen => iphdr_hlen_96
  # DEBUG BEGIN_STMT
  _15 = iphdr_95->_len;
  iphdr_len_98 = lwip_htons (_15);
  # DEBUG iphdr_len => iphdr_len_98
  # DEBUG BEGIN_STMT
  _16 = p_94(D)->tot_len;
  if (_16 > iphdr_len_98)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  pbuf_realloc (p_94(D), iphdr_len_98);

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _17 = p_94(D)->len;
  if (_17 < iphdr_hlen_96)
    goto <bb 9>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 7> [local count: 428208240]:
  _18 = p_94(D)->tot_len;
  if (_18 < iphdr_len_98)
    goto <bb 9>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 8> [local count: 282617438]:
  if (iphdr_hlen_96 <= 19)
    goto <bb 9>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 9> [local count: 350343403]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_94(D));
  # DEBUG BEGIN_STMT
  _19 = lwip_stats.ip.lenerr;
  _20 = _19 + 1;
  lwip_stats.ip.lenerr = _20;
  # DEBUG BEGIN_STMT
  _21 = lwip_stats.ip.drop;
  _22 = _21 + 1;
  lwip_stats.ip.drop = _22;
  # DEBUG BEGIN_STMT
  _23 = lwip_stats.mib2.ipindiscards;
  _24 = _23 + 1;
  lwip_stats.mib2.ipindiscards = _24;
  # DEBUG BEGIN_STMT
  goto <bb 45>; [100.00%]

  <bb 10> [local count: 186527509]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 = iphdr_95->dest.addr;
  ip_data.current_iphdr_dest.u_addr.ip4.addr = _25;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ip_data.current_iphdr_dest.type = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ip_data.current_iphdr_dest.u_addr.ip6.addr[3] = 0;
  ip_data.current_iphdr_dest.u_addr.ip6.addr[2] = 0;
  ip_data.current_iphdr_dest.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  ip_data.current_iphdr_dest.u_addr.ip6.zone = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _26 = iphdr_95->src.addr;
  ip_data.current_iphdr_src.u_addr.ip4.addr = _26;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ip_data.current_iphdr_src.type = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ip_data.current_iphdr_src.u_addr.ip6.addr[3] = 0;
  ip_data.current_iphdr_src.u_addr.ip6.addr[2] = 0;
  ip_data.current_iphdr_src.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  ip_data.current_iphdr_src.u_addr.ip6.zone = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _27 = _25 & 240;
  if (_27 == 224)
    goto <bb 11>; [51.12%]
  else
    goto <bb 15>; [48.88%]

  <bb 11> [local count: 95352863]:
  # DEBUG BEGIN_STMT
  _28 = inp_112(D)->flags;
  _90 = _28 & 32;
  if (_90 != 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 23>; [67.00%]

  <bb 12> [local count: 31466445]:
  _29 = igmp_lookfor_group (inp_112(D), &ip_data.current_iphdr_dest.u_addr.ip4);
  if (_29 != 0B)
    goto <bb 13>; [70.00%]
  else
    goto <bb 23>; [30.00%]

  <bb 13> [local count: 22026511]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG allsystems$addr => 16777440
  # DEBUG BEGIN_STMT
  _30 = ip_data.current_iphdr_dest.u_addr.ip4.addr;
  if (_30 == 16777440)
    goto <bb 14>; [34.00%]
  else
    goto <bb 23>; [66.00%]

  <bb 14> [local count: 7489014]:
  _31 = ip_data.current_iphdr_src.u_addr.ip4.addr;
  if (_31 == 0)
    goto <bb 26>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 15> [local count: 91174646]:
  # DEBUG BEGIN_STMT
  _32 = ip4_input_accept (inp_112(D));
  if (_32 != 0)
    goto <bb 23>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 16> [local count: 45587323]:
  # DEBUG BEGIN_STMT
  # DEBUG netif => 0B
  # DEBUG BEGIN_STMT
  _33 = ip_data.current_iphdr_dest.u_addr.ip4.addr;
  _34 = _33 & 255;
  if (_34 != 127)
    goto <bb 17>; [66.00%]
  else
    goto <bb 23>; [34.00%]

  <bb 17> [local count: 30087633]:
  # DEBUG BEGIN_STMT
  netif_115 = netif_list;
  # DEBUG netif => netif_115
  goto <bb 22>; [100.00%]

  <bb 18> [local count: 311140678]:
  # DEBUG BEGIN_STMT
  if (netif_80 == inp_112(D))
    goto <bb 19>; [30.00%]
  else
    goto <bb 20>; [70.00%]

  <bb 19> [local count: 93342203]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 21>; [100.00%]

  <bb 20> [local count: 217798474]:
  # DEBUG BEGIN_STMT
  _35 = ip4_input_accept (netif_80);
  if (_35 != 0)
    goto <bb 23>; [5.50%]
  else
    goto <bb 21>; [94.50%]

  <bb 21> [local count: 299161762]:
  # DEBUG BEGIN_STMT
  netif_117 = netif_80->next;
  # DEBUG netif => netif_117

  <bb 22> [local count: 329249395]:
  # netif_80 = PHI <netif_115(17), netif_117(21)>
  # DEBUG netif => netif_80
  # DEBUG BEGIN_STMT
  if (netif_80 != 0B)
    goto <bb 18>; [94.50%]
  else
    goto <bb 23>; [5.50%]

  <bb 23> [local count: 182783002]:
  # netif_167 = PHI <netif_80(20), 0B(12), inp_112(D)(14), inp_112(D)(13), 0B(16), inp_112(D)(15), netif_80(22), 0B(11)>
  # DEBUG allsystems$addr => NULL
  # DEBUG check_ip_src => NULL
  # DEBUG netif => NULL
  # DEBUG BEGIN_STMT
  _36 = ip_data.current_iphdr_src.u_addr.ip4.addr;
  _37 = ip4_addr_isbroadcast_u32 (_36, inp_112(D));
  if (_37 != 0)
    goto <bb 25>; [20.24%]
  else
    goto <bb 24>; [79.76%]

  <bb 24> [local count: 145787722]:
  _38 = ip_data.current_iphdr_src.u_addr.ip4.addr;
  _39 = _38 & 240;
  if (_39 == 224)
    goto <bb 25>; [20.97%]
  else
    goto <bb 26>; [79.03%]

  <bb 25> [local count: 67566965]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_94(D));
  # DEBUG BEGIN_STMT
  _40 = lwip_stats.ip.drop;
  _41 = _40 + 1;
  lwip_stats.ip.drop = _41;
  # DEBUG BEGIN_STMT
  _42 = lwip_stats.mib2.ipinaddrerrors;
  _43 = _42 + 1;
  lwip_stats.mib2.ipinaddrerrors = _43;
  # DEBUG BEGIN_STMT
  _44 = lwip_stats.mib2.ipindiscards;
  _45 = _44 + 1;
  lwip_stats.mib2.ipindiscards = _45;
  # DEBUG BEGIN_STMT
  goto <bb 45>; [100.00%]

  <bb 26> [local count: 118960544]:
  # netif_168 = PHI <inp_112(D)(14), netif_167(24)>
  # DEBUG allsystems$addr => NULL
  # DEBUG check_ip_src => NULL
  # DEBUG netif => NULL
  # DEBUG BEGIN_STMT
  if (netif_168 == 0B)
    goto <bb 27>; [9.81%]
  else
    goto <bb 28>; [90.19%]

  <bb 27> [local count: 11670029]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _46 = lwip_stats.ip.drop;
  _47 = _46 + 1;
  lwip_stats.ip.drop = _47;
  # DEBUG BEGIN_STMT
  _48 = lwip_stats.mib2.ipinaddrerrors;
  _49 = _48 + 1;
  lwip_stats.mib2.ipinaddrerrors = _49;
  # DEBUG BEGIN_STMT
  _50 = lwip_stats.mib2.ipindiscards;
  _51 = _50 + 1;
  lwip_stats.mib2.ipindiscards = _51;
  # DEBUG BEGIN_STMT
  pbuf_free (p_94(D));
  # DEBUG BEGIN_STMT
  goto <bb 45>; [100.00%]

  <bb 28> [local count: 107290514]:
  # DEBUG BEGIN_STMT
  _52 = iphdr_95->_offset;
  _114 = _52 & 65343;
  if (_114 != 0)
    goto <bb 29>; [50.00%]
  else
    goto <bb 31>; [50.00%]

  <bb 29> [local count: 53645257]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  p_125 = ip4_reass (p_94(D));
  # DEBUG p => p_125
  # DEBUG BEGIN_STMT
  if (p_125 == 0B)
    goto <bb 45>; [18.09%]
  else
    goto <bb 30>; [81.91%]

  <bb 30> [local count: 43940830]:
  # DEBUG BEGIN_STMT
  iphdr_126 = p_125->payload;
  # DEBUG iphdr => iphdr_126

  <bb 31> [local count: 97586087]:
  # p_78 = PHI <p_94(D)(28), p_125(30)>
  # iphdr_79 = PHI <iphdr_95(28), iphdr_126(30)>
  # DEBUG iphdr => iphdr_79
  # DEBUG p => p_78
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ip_data.current_netif = netif_168;
  # DEBUG BEGIN_STMT
  ip_data.current_input_netif = inp_112(D);
  # DEBUG BEGIN_STMT
  ip_data.current_ip4_header = iphdr_79;
  # DEBUG BEGIN_STMT
  _53 = iphdr_79->_v_hl;
  _54 = _53 & 15;
  _55 = _54 * 4;
  _56 = (short unsigned int) _55;
  ip_data.current_ip_header_tot_len = _56;
  # DEBUG BEGIN_STMT
  raw_status_132 = raw_input (p_78, inp_112(D));
  # DEBUG raw_status => raw_status_132
  # DEBUG BEGIN_STMT
  if (raw_status_132 != 1)
    goto <bb 32>; [48.88%]
  else
    goto <bb 44>; [51.12%]

  <bb 32> [local count: 47700079]:
  # DEBUG BEGIN_STMT
  _57 = (unsigned int) _14;
  pbuf_remove_header (p_78, _57);
  # DEBUG BEGIN_STMT
  _58 = iphdr_79->_proto;
  switch (_58) <default: <L54> [20.00%], case 1: <L52> [20.00%], case 2: <L53> [20.00%], case 6: <L51> [20.00%], case 17: <L49> [20.00%], case 136: <L49> [20.00%]>

  <bb 33> [local count: 9540016]:
<L49>:
  # DEBUG BEGIN_STMT
  _59 = lwip_stats.mib2.ipindelivers;
  _60 = _59 + 1;
  lwip_stats.mib2.ipindelivers = _60;
  # DEBUG BEGIN_STMT
  udp_input (p_78, inp_112(D));
  # DEBUG BEGIN_STMT
  goto <bb 44>; [100.00%]

  <bb 34> [local count: 9540016]:
<L51>:
  # DEBUG BEGIN_STMT
  _61 = lwip_stats.mib2.ipindelivers;
  _62 = _61 + 1;
  lwip_stats.mib2.ipindelivers = _62;
  # DEBUG BEGIN_STMT
  tcp_input (p_78, inp_112(D));
  # DEBUG BEGIN_STMT
  goto <bb 44>; [100.00%]

  <bb 35> [local count: 9540016]:
<L52>:
  # DEBUG BEGIN_STMT
  _63 = lwip_stats.mib2.ipindelivers;
  _64 = _63 + 1;
  lwip_stats.mib2.ipindelivers = _64;
  # DEBUG BEGIN_STMT
  icmp_input (p_78, inp_112(D));
  # DEBUG BEGIN_STMT
  goto <bb 44>; [100.00%]

  <bb 36> [local count: 9540016]:
<L53>:
  # DEBUG BEGIN_STMT
  igmp_input (p_78, inp_112(D), &ip_data.current_iphdr_dest.u_addr.ip4);
  # DEBUG BEGIN_STMT
  goto <bb 44>; [100.00%]

  <bb 37> [local count: 9540016]:
<L54>:
  # DEBUG BEGIN_STMT
  if (raw_status_132 == 2)
    goto <bb 38>; [51.12%]
  else
    goto <bb 39>; [48.88%]

  <bb 38> [local count: 4876856]:
  # DEBUG BEGIN_STMT
  _65 = lwip_stats.mib2.ipindelivers;
  _66 = _65 + 1;
  lwip_stats.mib2.ipindelivers = _66;
  goto <bb 43>; [100.00%]

  <bb 39> [local count: 4663160]:
  # DEBUG BEGIN_STMT
  _67 = ip_data.current_iphdr_dest.u_addr.ip4.addr;
  _68 = ip4_addr_isbroadcast_u32 (_67, netif_168);
  if (_68 == 0)
    goto <bb 40>; [50.00%]
  else
    goto <bb 42>; [50.00%]

  <bb 40> [local count: 2331580]:
  _69 = ip_data.current_iphdr_dest.u_addr.ip4.addr;
  _70 = _69 & 240;
  if (_70 != 224)
    goto <bb 41>; [48.88%]
  else
    goto <bb 42>; [51.12%]

  <bb 41> [local count: 1139676]:
  # DEBUG BEGIN_STMT
  iphdr_hlen.4_71 = (short int) _14;
  pbuf_header_force (p_78, iphdr_hlen.4_71);
  # DEBUG BEGIN_STMT
  icmp_dest_unreach (p_78, 2);

  <bb 42> [local count: 4663160]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _72 = lwip_stats.ip.proterr;
  _73 = _72 + 1;
  lwip_stats.ip.proterr = _73;
  # DEBUG BEGIN_STMT
  _74 = lwip_stats.ip.drop;
  _75 = _74 + 1;
  lwip_stats.ip.drop = _75;
  # DEBUG BEGIN_STMT
  _76 = lwip_stats.mib2.ipinunknownprotos;
  _77 = _76 + 1;
  lwip_stats.mib2.ipinunknownprotos = _77;

  <bb 43> [local count: 9540016]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_78);
  # DEBUG BEGIN_STMT

  <bb 44> [local count: 97586087]:
  # DEBUG BEGIN_STMT
  ip_data.current_netif = 0B;
  # DEBUG BEGIN_STMT
  ip_data.current_input_netif = 0B;
  # DEBUG BEGIN_STMT
  ip_data.current_ip4_header = 0B;
  # DEBUG BEGIN_STMT
  ip_data.current_ip_header_tot_len = 0;
  # DEBUG BEGIN_STMT
  ip_data.current_iphdr_src.u_addr.ip4.addr = 0;
  # DEBUG BEGIN_STMT
  ip_data.current_iphdr_dest.u_addr.ip4.addr = 0;
  # DEBUG BEGIN_STMT

  <bb 45> [local count: 1073741824]:
  return 0;

}



;; Function ip4_output_if_opt_src (ip4_output_if_opt_src, funcdef_no=8, decl_uid=6869, cgraph_uid=9, symbol_order=11)

Modification phase of node ip4_output_if_opt_src/11
ip4_output_if_opt_src (struct pbuf * p, const struct ip4_addr_t * src, const struct ip4_addr_t * dest, u8_t ttl, u8_t tos, u8_t proto, struct netif * netif, void * ip_options, u16_t optlen)
{
  unsigned char _1;
  signed char _2;

  <bb 2> [local count: 162688]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_6(D)->ref;
  if (_1 != 1)
    goto <bb 5>; [66.00%]
  else
    goto <bb 4>; [34.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 55314]:
  _2 = ip4_output_if_opt_src.part.0 (p_6(D), src_13(D), dest_7(D), ttl_10(D), tos_12(D), proto_11(D), netif_14(D), ip_options_9(D), optlen_8(D));
  return _2;

}



;; Function ip4_output_if_opt (ip4_output_if_opt, funcdef_no=6, decl_uid=6859, cgraph_uid=7, symbol_order=9)

Modification phase of node ip4_output_if_opt/9
ip4_output_if_opt (struct pbuf * p, const struct ip4_addr_t * src, const struct ip4_addr_t * dest, u8_t ttl, u8_t tos, u8_t proto, struct netif * netif, void * ip_options, u16_t optlen)
{
  const struct ip4_addr_t * src_used;
  long unsigned int _1;
  err_t _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG src_used => src_3(D)
  # DEBUG BEGIN_STMT
  if (dest_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  if (src_3(D) == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 4> [local count: 526133494]:
  _1 = src_3(D)->addr;
  if (_1 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 488552530]:
  # DEBUG BEGIN_STMT
  src_used_7 = &netif_6(D)->ip_addr.u_addr.ip4;
  # DEBUG src_used => src_used_7

  <bb 6> [local count: 1073741824]:
  # src_used_2 = PHI <src_3(D)(2), src_3(D)(4), src_used_7(5)>
  # DEBUG src_used => src_used_2
  # DEBUG BEGIN_STMT
  _15 = ip4_output_if_opt_src (p_8(D), src_used_2, dest_4(D), ttl_9(D), tos_10(D), proto_11(D), netif_6(D), ip_options_12(D), optlen_13(D));
  return _15;

}



;; Function ip4_output_if (ip4_output_if, funcdef_no=5, decl_uid=6841, cgraph_uid=6, symbol_order=8)

Modification phase of node ip4_output_if/8
ip4_output_if (struct pbuf * p, const struct ip4_addr_t * src, const struct ip4_addr_t * dest, u8_t ttl, u8_t tos, u8_t proto, struct netif * netif)
{
  err_t _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _10 = ip4_output_if_opt (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  return _10;

}



;; Function ip4_output_if_src (ip4_output_if_src, funcdef_no=7, decl_uid=6849, cgraph_uid=8, symbol_order=10)

Modification phase of node ip4_output_if_src/10
ip4_output_if_src (struct pbuf * p, const struct ip4_addr_t * src, const struct ip4_addr_t * dest, u8_t ttl, u8_t tos, u8_t proto, struct netif * netif)
{
  err_t _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _10 = ip4_output_if_opt_src (p_2(D), src_3(D), dest_4(D), ttl_5(D), tos_6(D), proto_7(D), netif_8(D), 0B, 0);
  return _10;

}



;; Function ip4_output (ip4_output, funcdef_no=9, decl_uid=6833, cgraph_uid=10, symbol_order=12)

Modification phase of node ip4_output/12
ip4_output (struct pbuf * p, const struct ip4_addr_t * src, const struct ip4_addr_t * dest, u8_t ttl, u8_t tos, u8_t proto)
{
  struct netif * netif;
  unsigned char _1;
  short unsigned int _2;
  short unsigned int _3;
  err_t _4;
  err_t _17;

  <bb 2> [local count: 134621]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_8(D)->ref;
  if (_1 != 1)
    goto <bb 8>; [79.76%]
  else
    goto <bb 4>; [20.24%]

  <bb 8> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 27247]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_11 = ip4_route (dest_9(D));
  # DEBUG netif => netif_11
  if (netif_11 == 0B)
    goto <bb 5>; [0.91%]
  else
    goto <bb 6>; [99.09%]

  <bb 5> [local count: 248]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = lwip_stats.ip.rterr;
  _3 = _2 + 1;
  lwip_stats.ip.rterr = _3;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 26999]:
  # DEBUG BEGIN_STMT
  _17 = ip4_output_if (p_8(D), src_12(D), dest_9(D), ttl_13(D), tos_14(D), proto_15(D), netif_11);

  <bb 7> [local count: 27247]:
  # _4 = PHI <-4(5), _17(6)>
  return _4;

}


