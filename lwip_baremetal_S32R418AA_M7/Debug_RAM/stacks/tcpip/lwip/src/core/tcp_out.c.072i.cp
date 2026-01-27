
IPA constant propagation start:
Determining dynamic type for call: netif_12 = tcp_route (pcb_1(D), _10, _11);
  Starting walk at: netif_12 = tcp_route (pcb_1(D), _10, _11);
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_12 = tcp_route (pcb_1(D), _10, _11);
  Starting walk at: netif_12 = tcp_route (pcb_1(D), _10, _11);
  instance pointer: _10  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_12 = tcp_route (pcb_1(D), _10, _11);
  Starting walk at: netif_12 = tcp_route (pcb_1(D), _10, _11);
  instance pointer: _11  Outer instance pointer: pcb_1(D) offset: 192 (bits) vtbl reference: 
Determining dynamic type for call: err_75 = tcp_output_segment (seg_53, pcb_1(D), netif_12);
  Starting walk at: err_75 = tcp_output_segment (seg_53, pcb_1(D), netif_12);
  instance pointer: seg_53  Outer instance pointer: seg_53 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_56 = lwip_htons (_55);
  Function call may change dynamic type:_135 = lwip_htonl (_134);
  Function call may change dynamic type:_38 = lwip_htonl (_37);
  Function call may change dynamic type:netif_12 = tcp_route (pcb_1(D), _10, _11);
  Function call may change dynamic type:iftmp.14_26 = ip6_select_source_address (netif_12, _25);
  Function call may change dynamic type:_102 = lwip_htons (_101);
  Function call may change dynamic type:_89 = lwip_htons (_88);
  Function call may change dynamic type:_84 = lwip_htonl (_83);
  Function call may change dynamic type:err_75 = tcp_output_segment (seg_53, pcb_1(D), netif_12);
  Function call may change dynamic type:_72 = lwip_htons (16);
  Function call may change dynamic type:_114 = lwip_htonl (_113);
  Function call may change dynamic type:_110 = lwip_htonl (_109);
  Function call may change dynamic type:_127 = lwip_htonl (_126);
  Function call may change dynamic type:_124 = lwip_htonl (_123);
  Function call may change dynamic type:tcp_seg_free (seg_53);
Determining dynamic type for call: err_75 = tcp_output_segment (seg_53, pcb_1(D), netif_12);
  Starting walk at: err_75 = tcp_output_segment (seg_53, pcb_1(D), netif_12);
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_56 = lwip_htons (_55);
  Function call may change dynamic type:_135 = lwip_htonl (_134);
  Function call may change dynamic type:_38 = lwip_htonl (_37);
  Function call may change dynamic type:netif_12 = tcp_route (pcb_1(D), _10, _11);
  Function call may change dynamic type:iftmp.14_26 = ip6_select_source_address (netif_12, _25);
  Function call may change dynamic type:_102 = lwip_htons (_101);
  Function call may change dynamic type:_89 = lwip_htons (_88);
  Function call may change dynamic type:_84 = lwip_htonl (_83);
  Function call may change dynamic type:err_75 = tcp_output_segment (seg_53, pcb_1(D), netif_12);
  Function call may change dynamic type:_72 = lwip_htons (16);
  Function call may change dynamic type:_114 = lwip_htonl (_113);
  Function call may change dynamic type:_110 = lwip_htonl (_109);
  Function call may change dynamic type:_127 = lwip_htonl (_126);
  Function call may change dynamic type:_124 = lwip_htonl (_123);
  Function call may change dynamic type:tcp_seg_free (seg_53);
Determining dynamic type for call: err_75 = tcp_output_segment (seg_53, pcb_1(D), netif_12);
  Starting walk at: err_75 = tcp_output_segment (seg_53, pcb_1(D), netif_12);
  instance pointer: netif_12  Outer instance pointer: netif_12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_56 = lwip_htons (_55);
  Function call may change dynamic type:_135 = lwip_htonl (_134);
  Function call may change dynamic type:_38 = lwip_htonl (_37);
  Function call may change dynamic type:netif_12 = tcp_route (pcb_1(D), _10, _11);
  Function call may change dynamic type:iftmp.14_26 = ip6_select_source_address (netif_12, _25);
  Function call may change dynamic type:_102 = lwip_htons (_101);
  Function call may change dynamic type:_89 = lwip_htons (_88);
  Function call may change dynamic type:_84 = lwip_htonl (_83);
  Function call may change dynamic type:err_75 = tcp_output_segment (seg_53, pcb_1(D), netif_12);
  Function call may change dynamic type:_72 = lwip_htons (16);
  Function call may change dynamic type:_114 = lwip_htonl (_113);
  Function call may change dynamic type:_110 = lwip_htonl (_109);
  Function call may change dynamic type:_127 = lwip_htonl (_126);
  Function call may change dynamic type:_124 = lwip_htonl (_123);
  Function call may change dynamic type:tcp_seg_free (seg_53);
Determining dynamic type for call: _49 = tcp_send_empty_ack (pcb_1(D));
  Starting walk at: _49 = tcp_send_empty_ack (pcb_1(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_38 = lwip_htonl (_37);
  Function call may change dynamic type:netif_12 = tcp_route (pcb_1(D), _10, _11);
  Function call may change dynamic type:iftmp.14_26 = ip6_select_source_address (netif_12, _25);
Determining dynamic type for call: _9 = tcp_send_empty_ack (pcb_1(D));
  Starting walk at: _9 = tcp_send_empty_ack (pcb_1(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Starting walk at: p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  Starting walk at: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_4, 0);
  Function call may change dynamic type:p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  Starting walk at: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  instance pointer: p_4  Outer instance pointer: p_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_4, 0);
  Function call may change dynamic type:p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  Starting walk at: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  instance pointer: _7  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_4, 0);
  Function call may change dynamic type:p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  Starting walk at: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  instance pointer: _8  Outer instance pointer: pcb_1(D) offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_4, 0);
  Function call may change dynamic type:p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: tcp_output_fill_options.isra.0 (p_4, 0);
  Starting walk at: tcp_output_fill_options.isra.0 (p_4, 0);
  instance pointer: p_4  Outer instance pointer: p_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: seg_15 = tcp_create_segment (pcb_8(D), p_7, flags_1(D), _14, optflags_3);
  Starting walk at: seg_15 = tcp_create_segment (pcb_8(D), p_7, flags_1(D), _14, optflags_3);
  instance pointer: pcb_8(D)  Outer instance pointer: pcb_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_7 = pbuf_alloc (74, _6, 640);
Determining dynamic type for call: seg_15 = tcp_create_segment (pcb_8(D), p_7, flags_1(D), _14, optflags_3);
  Starting walk at: seg_15 = tcp_create_segment (pcb_8(D), p_7, flags_1(D), _14, optflags_3);
  instance pointer: p_7  Outer instance pointer: p_7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_7 = pbuf_alloc (74, _6, 640);
Determining dynamic type for call: netif_4 = tcp_route (pcb_1(D), src_2(D), dst_3(D));
  Starting walk at: netif_4 = tcp_route (pcb_1(D), src_2(D), dst_3(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_4 = tcp_route (pcb_1(D), src_2(D), dst_3(D));
  Starting walk at: netif_4 = tcp_route (pcb_1(D), src_2(D), dst_3(D));
  instance pointer: src_2(D)  Outer instance pointer: src_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_4 = tcp_route (pcb_1(D), src_2(D), dst_3(D));
  Starting walk at: netif_4 = tcp_route (pcb_1(D), src_2(D), dst_3(D));
  instance pointer: dst_3(D)  Outer instance pointer: dst_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Starting walk at: p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  instance pointer: pcb_38(D)  Outer instance pointer: pcb_38(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = lwip_htons (_5);
Determining dynamic type for call: tcp_output_fill_options.isra.0 (p_46, 0);
  Starting walk at: tcp_output_fill_options.isra.0 (p_46, 0);
  instance pointer: p_46  Outer instance pointer: p_46 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_24 = lwip_htonl (_23);
  Function call may change dynamic type:_14 = lwip_htons (17);
  Function call may change dynamic type:p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Function call may change dynamic type:_6 = lwip_htons (_5);
  Function call may change dynamic type:pbuf_copy_partial (_18, d_48, 1, _21);
Determining dynamic type for call: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  Starting walk at: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  instance pointer: pcb_38(D)  Outer instance pointer: pcb_38(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_46, 0);
  Function call may change dynamic type:_24 = lwip_htonl (_23);
  Function call may change dynamic type:_14 = lwip_htons (17);
  Function call may change dynamic type:p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Function call may change dynamic type:_6 = lwip_htons (_5);
  Function call may change dynamic type:pbuf_copy_partial (_18, d_48, 1, _21);
Determining dynamic type for call: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  Starting walk at: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  instance pointer: p_46  Outer instance pointer: p_46 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_46, 0);
  Function call may change dynamic type:_24 = lwip_htonl (_23);
  Function call may change dynamic type:_14 = lwip_htons (17);
  Function call may change dynamic type:p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Function call may change dynamic type:_6 = lwip_htons (_5);
  Function call may change dynamic type:pbuf_copy_partial (_18, d_48, 1, _21);
Determining dynamic type for call: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  Starting walk at: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  instance pointer: _28  Outer instance pointer: pcb_38(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_46, 0);
  Function call may change dynamic type:_24 = lwip_htonl (_23);
  Function call may change dynamic type:_14 = lwip_htons (17);
  Function call may change dynamic type:p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Function call may change dynamic type:_6 = lwip_htons (_5);
  Function call may change dynamic type:pbuf_copy_partial (_18, d_48, 1, _21);
Determining dynamic type for call: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  Starting walk at: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  instance pointer: _29  Outer instance pointer: pcb_38(D) offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_46, 0);
  Function call may change dynamic type:_24 = lwip_htonl (_23);
  Function call may change dynamic type:_14 = lwip_htons (17);
  Function call may change dynamic type:p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Function call may change dynamic type:_6 = lwip_htons (_5);
  Function call may change dynamic type:pbuf_copy_partial (_18, d_48, 1, _21);
Determining dynamic type for call: p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Starting walk at: p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: tcp_output_fill_options.isra.0 (p_13, 0);
  Starting walk at: tcp_output_fill_options.isra.0 (p_13, 0);
  instance pointer: p_13  Outer instance pointer: p_13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  Starting walk at: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_13, 0);
  Function call may change dynamic type:p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  Starting walk at: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  instance pointer: p_13  Outer instance pointer: p_13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_13, 0);
  Function call may change dynamic type:p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  Starting walk at: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  instance pointer: _4  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_13, 0);
  Function call may change dynamic type:p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  Starting walk at: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  instance pointer: _5  Outer instance pointer: pcb_9(D) offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_13, 0);
  Function call may change dynamic type:p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: _2 = tcp_send_empty_ack.part.0 (pcb_4(D));
  Starting walk at: _2 = tcp_send_empty_ack.part.0 (pcb_4(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_output_fill_options.isra.0 (p_16, 0);
  Starting walk at: tcp_output_fill_options.isra.0 (p_16, 0);
  instance pointer: p_16  Outer instance pointer: p_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 33820);
  Function call may change dynamic type:_1 = lwip_htonl (seqno_10(D));
Determining dynamic type for call: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  Starting walk at: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  instance pointer: pcb_17(D)  Outer instance pointer: pcb_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_16, 0);
  Function call may change dynamic type:p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 33820);
  Function call may change dynamic type:_1 = lwip_htonl (seqno_10(D));
Determining dynamic type for call: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  Starting walk at: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  instance pointer: p_16  Outer instance pointer: p_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_16, 0);
  Function call may change dynamic type:p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 33820);
  Function call may change dynamic type:_1 = lwip_htonl (seqno_10(D));
Determining dynamic type for call: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  Starting walk at: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  instance pointer: local_ip_7(D)  Outer instance pointer: local_ip_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_16, 0);
  Function call may change dynamic type:p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 33820);
  Function call may change dynamic type:_1 = lwip_htonl (seqno_10(D));
Determining dynamic type for call: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  Starting walk at: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  instance pointer: remote_ip_9(D)  Outer instance pointer: remote_ip_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_16, 0);
  Function call may change dynamic type:p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 33820);
  Function call may change dynamic type:_1 = lwip_htonl (seqno_10(D));
Determining dynamic type for call: _3 = tcp_output_control_segment.part.0 (pcb_6(D), p_4(D), src_7(D), dst_8(D));
  Starting walk at: _3 = tcp_output_control_segment.part.0 (pcb_6(D), p_4(D), src_7(D), dst_8(D));
  instance pointer: pcb_6(D)  Outer instance pointer: pcb_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = tcp_output_control_segment.part.0 (pcb_6(D), p_4(D), src_7(D), dst_8(D));
  Starting walk at: _3 = tcp_output_control_segment.part.0 (pcb_6(D), p_4(D), src_7(D), dst_8(D));
  instance pointer: p_4(D)  Outer instance pointer: p_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = tcp_output_control_segment.part.0 (pcb_6(D), p_4(D), src_7(D), dst_8(D));
  Starting walk at: _3 = tcp_output_control_segment.part.0 (pcb_6(D), p_4(D), src_7(D), dst_8(D));
  instance pointer: src_7(D)  Outer instance pointer: src_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = tcp_output_control_segment.part.0 (pcb_6(D), p_4(D), src_7(D), dst_8(D));
  Starting walk at: _3 = tcp_output_control_segment.part.0 (pcb_6(D), p_4(D), src_7(D), dst_8(D));
  instance pointer: dst_8(D)  Outer instance pointer: dst_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_output_alloc_header.part.0 (pcb_6(D));
  Starting walk at: tcp_output_alloc_header.part.0 (pcb_6(D));
  instance pointer: pcb_6(D)  Outer instance pointer: pcb_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_12 = tcp_output_alloc_header_common (_1, optlen_8(D), datalen_9(D), seqno_be_10(D), _2, _3, 16, _4);
Determining dynamic type for call: _3 = tcp_rexmit (pcb_23(D));
  Starting walk at: _3 = tcp_rexmit (pcb_23(D));
  instance pointer: pcb_23(D)  Outer instance pointer: pcb_23(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = tcp_output_segment_busy (_1);
  Starting walk at: _2 = tcp_output_segment_busy (_1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = tcp_rexmit_rto_prepare (pcb_4(D));
  Starting walk at: _1 = tcp_rexmit_rto_prepare (pcb_4(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_rexmit_rto_commit (pcb_4(D));
  Starting walk at: tcp_rexmit_rto_commit (pcb_4(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = tcp_rexmit_rto_prepare (pcb_4(D));
Determining dynamic type for call: tcp_output (pcb_5(D));
  Starting walk at: tcp_output (pcb_5(D));
  instance pointer: pcb_5(D)  Outer instance pointer: pcb_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = tcp_output_segment_busy (seg_28);
  Starting walk at: _4 = tcp_output_segment_busy (seg_28);
  instance pointer: seg_28  Outer instance pointer: seg_20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = tcp_output_segment_busy (seg_20);
Determining dynamic type for call: _2 = tcp_output_segment_busy (seg_20);
  Starting walk at: _2 = tcp_output_segment_busy (seg_20);
  instance pointer: seg_20  Outer instance pointer: seg_20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = tcp_output_segment_busy (seg_20);
Determining dynamic type for call: _1 = tcp_output_segment_busy (seg_62(D));
  Starting walk at: _1 = tcp_output_segment_busy (seg_62(D));
  instance pointer: seg_62(D)  Outer instance pointer: seg_62(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = tcp_output.part.0 (pcb_9(D));
  Starting walk at: _3 = tcp_output.part.0 (pcb_9(D));
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = tcp_enqueue_flags.part.0 (pcb_8(D), flags_6(D));
  Starting walk at: _1 = tcp_enqueue_flags.part.0 (pcb_8(D), flags_6(D));
  instance pointer: pcb_8(D)  Outer instance pointer: pcb_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _28 = tcp_enqueue_flags (pcb_19(D), 1);
  Starting walk at: _28 = tcp_enqueue_flags (pcb_19(D), 1);
  instance pointer: pcb_19(D)  Outer instance pointer: pcb_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htons (_4);
Determining dynamic type for call: seg_82 = tcp_create_segment (pcb_64(D), p_72, remainder_flags_53, _24, optflags_68);
  Starting walk at: seg_82 = tcp_create_segment (pcb_64(D), p_72, remainder_flags_53, _24, optflags_68);
  instance pointer: pcb_64(D)  Outer instance pointer: pcb_64(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_22 = lwip_htonl (_21);
  Function call may change dynamic type:_18 = lwip_htons (_17);
  Function call may change dynamic type:_15 = pbuf_copy_partial (_8, _14, remainder_70, offset_73);
  Function call may change dynamic type:p_72 = pbuf_alloc (74, _7, 640);
Determining dynamic type for call: seg_82 = tcp_create_segment (pcb_64(D), p_72, remainder_flags_53, _24, optflags_68);
  Starting walk at: seg_82 = tcp_create_segment (pcb_64(D), p_72, remainder_flags_53, _24, optflags_68);
  instance pointer: p_72  Outer instance pointer: p_72 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_22 = lwip_htonl (_21);
  Function call may change dynamic type:_18 = lwip_htons (_17);
  Function call may change dynamic type:_15 = pbuf_copy_partial (_8, _14, remainder_70, offset_73);
  Function call may change dynamic type:p_72 = pbuf_alloc (74, _7, 640);
Determining dynamic type for call: err_166 = tcp_write_checks (pcb_160(D), len_164(D));
  Starting walk at: err_166 = tcp_write_checks (pcb_160(D), len_164(D));
  instance pointer: pcb_160(D)  Outer instance pointer: pcb_160(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: concat_p_192 = tcp_pbuf_prealloc (0, seglen_179, space_119, &oversize, pcb_160(D), apiflags_181(D), 1);
  Starting walk at: concat_p_192 = tcp_pbuf_prealloc (0, seglen_179, space_119, &oversize, pcb_160(D), apiflags_181(D), 1);
  instance pointer: &oversize  Outer instance pointer: oversize offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_166 = tcp_write_checks (pcb_160(D), len_164(D));
Determining dynamic type for call: concat_p_192 = tcp_pbuf_prealloc (0, seglen_179, space_119, &oversize, pcb_160(D), apiflags_181(D), 1);
  Starting walk at: concat_p_192 = tcp_pbuf_prealloc (0, seglen_179, space_119, &oversize, pcb_160(D), apiflags_181(D), 1);
  instance pointer: pcb_160(D)  Outer instance pointer: pcb_160(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_166 = tcp_write_checks (pcb_160(D), len_164(D));
Determining dynamic type for call: p_234 = tcp_pbuf_prealloc (74, seglen_224, iftmp.0_125, &oversize, pcb_160(D), apiflags_181(D), _46);
  Starting walk at: p_234 = tcp_pbuf_prealloc (74, seglen_224, iftmp.0_125, &oversize, pcb_160(D), apiflags_181(D), _46);
  instance pointer: &oversize  Outer instance pointer: oversize offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_166 = tcp_write_checks (pcb_160(D), len_164(D));
  Function call may change dynamic type:_195 = pbuf_clen (concat_p_192);
  Function call may change dynamic type:memcpy (_31, _33, _34);
  Function call may change dynamic type:concat_p_192 = tcp_pbuf_prealloc (0, seglen_179, space_119, &oversize, pcb_160(D), apiflags_181(D), 1);
  Function call may change dynamic type:_188 = pbuf_clen (concat_p_185);
  Function call may change dynamic type:concat_p_185 = pbuf_alloc (0, seglen_179, 1);
  Function call may change dynamic type:seg_241 = tcp_create_segment (pcb_160(D), p_121, 0, _57, 0);
  Function call may change dynamic type:_238 = pbuf_clen (p_121);
  Function call may change dynamic type:memcpy (_48, _50, _51);
  Function call may change dynamic type:p_234 = tcp_pbuf_prealloc (74, seglen_224, iftmp.0_125, &oversize, pcb_160(D), apiflags_181(D), _46);
  Function call may change dynamic type:pbuf_cat (p_229, p2_226);
  Function call may change dynamic type:p_229 = pbuf_alloc (74, 0, 640);
  Function call may change dynamic type:p2_226 = pbuf_alloc (74, seglen_224, 1);
Determining dynamic type for call: p_234 = tcp_pbuf_prealloc (74, seglen_224, iftmp.0_125, &oversize, pcb_160(D), apiflags_181(D), _46);
  Starting walk at: p_234 = tcp_pbuf_prealloc (74, seglen_224, iftmp.0_125, &oversize, pcb_160(D), apiflags_181(D), _46);
  instance pointer: pcb_160(D)  Outer instance pointer: pcb_160(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_166 = tcp_write_checks (pcb_160(D), len_164(D));
  Function call may change dynamic type:_195 = pbuf_clen (concat_p_192);
  Function call may change dynamic type:memcpy (_31, _33, _34);
  Function call may change dynamic type:concat_p_192 = tcp_pbuf_prealloc (0, seglen_179, space_119, &oversize, pcb_160(D), apiflags_181(D), 1);
  Function call may change dynamic type:_188 = pbuf_clen (concat_p_185);
  Function call may change dynamic type:concat_p_185 = pbuf_alloc (0, seglen_179, 1);
  Function call may change dynamic type:seg_241 = tcp_create_segment (pcb_160(D), p_121, 0, _57, 0);
  Function call may change dynamic type:_238 = pbuf_clen (p_121);
  Function call may change dynamic type:memcpy (_48, _50, _51);
  Function call may change dynamic type:p_234 = tcp_pbuf_prealloc (74, seglen_224, iftmp.0_125, &oversize, pcb_160(D), apiflags_181(D), _46);
  Function call may change dynamic type:pbuf_cat (p_229, p2_226);
  Function call may change dynamic type:p_229 = pbuf_alloc (74, 0, 640);
  Function call may change dynamic type:p2_226 = pbuf_alloc (74, seglen_224, 1);
Determining dynamic type for call: seg_241 = tcp_create_segment (pcb_160(D), p_121, 0, _57, 0);
  Starting walk at: seg_241 = tcp_create_segment (pcb_160(D), p_121, 0, _57, 0);
  instance pointer: pcb_160(D)  Outer instance pointer: pcb_160(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_238 = pbuf_clen (p_121);
  Function call may change dynamic type:memcpy (_48, _50, _51);
  Function call may change dynamic type:p_234 = tcp_pbuf_prealloc (74, seglen_224, iftmp.0_125, &oversize, pcb_160(D), apiflags_181(D), _46);
  Function call may change dynamic type:err_166 = tcp_write_checks (pcb_160(D), len_164(D));
  Function call may change dynamic type:_195 = pbuf_clen (concat_p_192);
  Function call may change dynamic type:memcpy (_31, _33, _34);
  Function call may change dynamic type:concat_p_192 = tcp_pbuf_prealloc (0, seglen_179, space_119, &oversize, pcb_160(D), apiflags_181(D), 1);
  Function call may change dynamic type:_188 = pbuf_clen (concat_p_185);
  Function call may change dynamic type:concat_p_185 = pbuf_alloc (0, seglen_179, 1);
  Function call may change dynamic type:seg_241 = tcp_create_segment (pcb_160(D), p_121, 0, _57, 0);
  Function call may change dynamic type:_238 = pbuf_clen (p_121);
  Function call may change dynamic type:pbuf_cat (p_229, p2_226);
  Function call may change dynamic type:p_229 = pbuf_alloc (74, 0, 640);
  Function call may change dynamic type:p2_226 = pbuf_alloc (74, seglen_224, 1);
Determining dynamic type for call: seg_241 = tcp_create_segment (pcb_160(D), p_121, 0, _57, 0);
  Starting walk at: seg_241 = tcp_create_segment (pcb_160(D), p_121, 0, _57, 0);
  instance pointer: p_121  Outer instance pointer: p_121 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_238 = pbuf_clen (p_121);
  Function call may change dynamic type:memcpy (_48, _50, _51);
  Function call may change dynamic type:p_234 = tcp_pbuf_prealloc (74, seglen_224, iftmp.0_125, &oversize, pcb_160(D), apiflags_181(D), _46);
  Function call may change dynamic type:err_166 = tcp_write_checks (pcb_160(D), len_164(D));
  Function call may change dynamic type:_195 = pbuf_clen (concat_p_192);
  Function call may change dynamic type:memcpy (_31, _33, _34);
  Function call may change dynamic type:concat_p_192 = tcp_pbuf_prealloc (0, seglen_179, space_119, &oversize, pcb_160(D), apiflags_181(D), 1);
  Function call may change dynamic type:_188 = pbuf_clen (concat_p_185);
  Function call may change dynamic type:concat_p_185 = pbuf_alloc (0, seglen_179, 1);
  Function call may change dynamic type:seg_241 = tcp_create_segment (pcb_160(D), p_121, 0, _57, 0);
  Function call may change dynamic type:_238 = pbuf_clen (p_121);
  Function call may change dynamic type:pbuf_cat (p_229, p2_226);
  Function call may change dynamic type:p_229 = pbuf_alloc (74, 0, 640);
  Function call may change dynamic type:p2_226 = pbuf_alloc (74, seglen_224, 1);
Determining dynamic type for call: _1 = tcp_pbuf_prealloc.part.0 (layer_12(D), length_5(D), max_length_9(D), oversize_6(D), pcb_8(D), apiflags_10(D), first_seg_11(D));
  Starting walk at: _1 = tcp_pbuf_prealloc.part.0 (layer_12(D), length_5(D), max_length_9(D), oversize_6(D), pcb_8(D), apiflags_10(D), first_seg_11(D));
  instance pointer: oversize_6(D)  Outer instance pointer: oversize_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = tcp_pbuf_prealloc.part.0 (layer_12(D), length_5(D), max_length_9(D), oversize_6(D), pcb_8(D), apiflags_10(D), first_seg_11(D));
  Starting walk at: _1 = tcp_pbuf_prealloc.part.0 (layer_12(D), length_5(D), max_length_9(D), oversize_6(D), pcb_8(D), apiflags_10(D), first_seg_11(D));
  instance pointer: pcb_8(D)  Outer instance pointer: pcb_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = tcp_create_segment.part.0 (pcb_5(D), p_7(D), hdrflags_10(D), seqno_9(D), optflags_8(D));
  Starting walk at: _1 = tcp_create_segment.part.0 (pcb_5(D), p_7(D), hdrflags_10(D), seqno_9(D), optflags_8(D));
  instance pointer: pcb_5(D)  Outer instance pointer: pcb_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = tcp_create_segment.part.0 (pcb_5(D), p_7(D), hdrflags_10(D), seqno_9(D), optflags_8(D));
  Starting walk at: _1 = tcp_create_segment.part.0 (pcb_5(D), p_7(D), hdrflags_10(D), seqno_9(D), optflags_8(D));
  instance pointer: p_7(D)  Outer instance pointer: p_7(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  tcp_output.part.0/55:
    callsite  tcp_output.part.0/55 -> tcp_send_empty_ack/22 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_output.part.0/55 -> tcp_route/1 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: ANCESTOR: 0, offset 0, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: ANCESTOR: 0, offset 192, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_output.part.0/55 -> tcp_send_empty_ack/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_output.part.0/55 -> tcp_output_segment/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_send_empty_ack.part.0/54:
    callsite  tcp_send_empty_ack.part.0/54 -> tcp_output_alloc_header/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_send_empty_ack.part.0/54 -> tcp_output_fill_options.isra.0/48 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  tcp_send_empty_ack.part.0/54 -> tcp_output_control_segment/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: ANCESTOR: 0, offset 192
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_enqueue_flags.part.0/53:
    callsite  tcp_enqueue_flags.part.0/53 -> tcp_create_segment/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
  Jump functions of caller  tcp_output_control_segment.part.0/52:
    callsite  tcp_output_control_segment.part.0/52 -> tcp_route/1 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_output_alloc_header.part.0/51:
  Jump functions of caller  tcp_create_segment.part.0/50:
  Jump functions of caller  tcp_pbuf_prealloc.part.0/49:
  Jump functions of caller  tcp_output_fill_options.isra.0/48:
  Jump functions of caller  ip4_output_if/47:
  Jump functions of caller  ip6_output_if/46:
  Jump functions of caller  tcp_eff_send_mss_netif/44:
  Jump functions of caller  ip4_route/43:
  Jump functions of caller  ip6_route/42:
  Jump functions of caller  netif_get_by_index/41:
  Jump functions of caller  ip6_select_source_address/40:
  Jump functions of caller  pbuf_realloc/38:
  Jump functions of caller  pbuf_copy_partial/37:
  Jump functions of caller  lwip_htonl/36:
  Jump functions of caller  tcp_seg_free/35:
  Jump functions of caller  pbuf_add_header/34:
  Jump functions of caller  memp_malloc/33:
  Jump functions of caller  tcp_segs_free/32:
  Jump functions of caller  lwip_htons/30:
  Jump functions of caller  pbuf_cat/29:
  Jump functions of caller  pbuf_free/28:
  Jump functions of caller  pbuf_alloc/27:
  Jump functions of caller  pbuf_clen/26:
  Jump functions of caller  memcpy/25:
  Jump functions of caller  tcp_zero_window_probe/24:
    callsite  tcp_zero_window_probe/24 -> tcp_output_control_segment/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: ANCESTOR: 0, offset 192
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  tcp_zero_window_probe/24 -> tcp_output_fill_options.isra.0/48 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  tcp_zero_window_probe/24 -> tcp_output_alloc_header/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_keepalive/23:
    callsite  tcp_keepalive/23 -> tcp_output_control_segment/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: ANCESTOR: 0, offset 192
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  tcp_keepalive/23 -> tcp_output_fill_options.isra.0/48 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  tcp_keepalive/23 -> tcp_output_alloc_header/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_send_empty_ack/22:
    callsite  tcp_send_empty_ack/22 -> tcp_send_empty_ack.part.0/54 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_rst/21:
    callsite  tcp_rst/21 -> tcp_output_control_segment/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_rst/21 -> tcp_output_fill_options.isra.0/48 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  tcp_rst/21 -> tcp_output_alloc_header_common/17 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 5: PASS THROUGH: 6, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 6: CONST: 20
         value: 0x14, mask: 0x0
         Unknown VR
       param 7: CONST: 33820
         value: 0x841c, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_output_control_segment/20:
    callsite  tcp_output_control_segment/20 -> tcp_output_control_segment.part.0/52 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_output_alloc_header/18:
    callsite  tcp_output_alloc_header/18 -> tcp_output_alloc_header.part.0/51 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_output_alloc_header/18 -> tcp_output_alloc_header_common/17 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 6: CONST: 16
         value: 0x10, mask: 0x0
         Unknown VR
       param 7: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  tcp_output_alloc_header_common/17:
  Jump functions of caller  tcp_rexmit_fast/16:
    callsite  tcp_rexmit_fast/16 -> tcp_rexmit/15 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_rexmit/15:
    callsite  tcp_rexmit/15 -> tcp_output_segment_busy/10 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_rexmit_rto/14:
    callsite  tcp_rexmit_rto/14 -> tcp_rexmit_rto_commit/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_rexmit_rto/14 -> tcp_rexmit_rto_prepare/12 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_rexmit_rto_commit/13:
    callsite  tcp_rexmit_rto_commit/13 -> tcp_output/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_rexmit_rto_prepare/12:
    callsite  tcp_rexmit_rto_prepare/12 -> tcp_output_segment_busy/10 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  tcp_rexmit_rto_prepare/12 -> tcp_output_segment_busy/10 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_output_segment/11:
    callsite  tcp_output_segment/11 -> tcp_output_segment_busy/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_output_segment_busy/10:
  Jump functions of caller  tcp_output/9:
    callsite  tcp_output/9 -> tcp_output.part.0/55 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_enqueue_flags/8:
    callsite  tcp_enqueue_flags/8 -> tcp_enqueue_flags.part.0/53 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  tcp_send_fin/7:
    callsite  tcp_send_fin/7 -> tcp_enqueue_flags/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_split_unsent_seg/6:
    callsite  tcp_split_unsent_seg/6 -> tcp_create_segment/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x9
         VR  [0, 9]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  tcp_write/5:
    callsite  tcp_write/5 -> tcp_create_segment/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  tcp_write/5 -> tcp_pbuf_prealloc/3 : 
       param 0: CONST: 74
         value: 0x4a, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
       param 4: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
    callsite  tcp_write/5 -> tcp_pbuf_prealloc/3 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
       param 4: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  tcp_write/5 -> tcp_write_checks/4 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  tcp_write_checks/4:
  Jump functions of caller  tcp_pbuf_prealloc/3:
    callsite  tcp_pbuf_prealloc/3 -> tcp_pbuf_prealloc.part.0/49 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: PASS THROUGH: 6, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  tcp_create_segment/2:
    callsite  tcp_create_segment/2 -> tcp_create_segment.part.0/50 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  tcp_route/1:

 Propagating constants:

Not considering tcp_zero_window_probe for cloning; -fipa-cp-clone disabled.
Not considering tcp_keepalive for cloning; -fipa-cp-clone disabled.
Not considering tcp_send_empty_ack for cloning; -fipa-cp-clone disabled.
Not considering tcp_rst for cloning; -fipa-cp-clone disabled.
Not considering tcp_rexmit_fast for cloning; -fipa-cp-clone disabled.
Not considering tcp_rexmit for cloning; -fipa-cp-clone disabled.
Not considering tcp_rexmit_rto for cloning; -fipa-cp-clone disabled.
Not considering tcp_rexmit_rto_commit for cloning; -fipa-cp-clone disabled.
Not considering tcp_rexmit_rto_prepare for cloning; -fipa-cp-clone disabled.
Not considering tcp_output for cloning; -fipa-cp-clone disabled.
Not considering tcp_enqueue_flags for cloning; -fipa-cp-clone disabled.
Not considering tcp_send_fin for cloning; -fipa-cp-clone disabled.
Not considering tcp_split_unsent_seg for cloning; -fipa-cp-clone disabled.
Not considering tcp_write for cloning; -fipa-cp-clone disabled.

overall_size: 1749, max_new_size: 11001
 - context independent values, size: 10, time_benefit: 3.099991
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 22, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 40, time_benefit: 2.393005
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: tcp_output.part.0/55:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_send_empty_ack.part.0/54:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_enqueue_flags.part.0/53:
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
  Node: tcp_output_control_segment.part.0/52:
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
  Node: tcp_output_alloc_header.part.0/51:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_create_segment.part.0/50:
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
               0 [loc_time: 1, loc_size: 63, prop_time: 0, prop_size: 0]
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
               0 [loc_time: 3, loc_size: 58, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_pbuf_prealloc.part.0/49:
    param [0]: 74 [loc_time: 1, loc_size: 40, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 40, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x4a, mask = 0x4a
         pbuf_layer [0, 74]
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
         Bits: value = 0x0, mask = 0xfffffffe
         u16_t * ~[0B, 0B]
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
               1 [loc_time: 1, loc_size: 38, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         u8_t [0, 1]
        AGGS VARIABLE
  Node: tcp_output_fill_options.isra.0/48:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         u8_t [0, 0]
        AGGS VARIABLE
  Node: tcp_zero_window_probe/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_keepalive/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_send_empty_ack/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_rst/21:
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
  Node: tcp_output_control_segment/20:
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
  Node: tcp_output_alloc_header/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         u16_t [0, 0]
        AGGS VARIABLE
    param [2]: VARIABLE
               0 [loc_time: 2, loc_size: 25, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         u16_t [0, 1]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_output_alloc_header_common/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         u16_t [0, 0]
        AGGS VARIABLE
    param [2]: VARIABLE
               0 [loc_time: 5, loc_size: 40, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         u16_t [0, 1]
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
    param [6]: 16 [loc_time: 3, loc_size: 41, prop_time: 0, prop_size: 0]
               20 [loc_time: 3, loc_size: 41, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x14, mask = 0x4
         u8_t [16, 20]
        AGGS VARIABLE
    param [7]: VARIABLE
               33820 [loc_time: 3, loc_size: 42, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_rexmit_fast/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_rexmit/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_rexmit_rto/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_rexmit_rto_commit/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_rexmit_rto_prepare/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_output_segment/11:
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
  Node: tcp_output_segment_busy/10:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_output/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_enqueue_flags/8:
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
  Node: tcp_send_fin/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_split_unsent_seg/6:
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
  Node: tcp_write/5:
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
  Node: tcp_write_checks/4:
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
  Node: tcp_pbuf_prealloc/3:
    param [0]: 0 [loc_time: 1, loc_size: 20, prop_time: 0, prop_size: 0]
               74 [loc_time: 1, loc_size: 20, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x4a, mask = 0x4a
         pbuf_layer [0, 74]
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
         Bits: value = 0x0, mask = 0xfffffffe
         u16_t * ~[0B, 0B]
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
               1 [loc_time: 1, loc_size: 20, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         u8_t [0, 1]
        AGGS VARIABLE
  Node: tcp_create_segment/2:
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
               0 [loc_time: 1, loc_size: 18, prop_time: 0, prop_size: 0]
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
               0 [loc_time: 1, loc_size: 18, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_route/1:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:

 - Creating a specialized node of tcp_output_fill_options.isra.0/48 for all known contexts.
    replacing param #1 optflags with const 0
 - Creating a specialized node of tcp_output_alloc_header/18 for all known contexts.
    replacing param #1 optlen with const 0
 - Creating a specialized node of tcp_output_alloc_header_common/17 for all known contexts.
    replacing param #1 optlen with const 0
Propagated bits info for function tcp_output_alloc_header_common.constprop/58:
 param 1: value = 0x0, mask = 0x0
 param 2: value = 0x0, mask = 0x1
 param 6: value = 0x14, mask = 0x4
Propagated bits info for function tcp_output_alloc_header.constprop/57:
 param 1: value = 0x0, mask = 0x0
 param 2: value = 0x0, mask = 0x1
Propagated bits info for function tcp_output_fill_options.isra.0.constprop/56:
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function tcp_pbuf_prealloc.part.0/49:
 param 0: value = 0x4a, mask = 0x4a
 param 3: value = 0x0, mask = 0xfffffffe
 param 6: value = 0x0, mask = 0x1
Propagated bits info for function tcp_output_fill_options.isra.0/48:
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function tcp_output_alloc_header/18:
 param 1: value = 0x0, mask = 0x0
 param 2: value = 0x0, mask = 0x1
Propagated bits info for function tcp_output_alloc_header_common/17:
 param 1: value = 0x0, mask = 0x0
 param 2: value = 0x0, mask = 0x1
 param 6: value = 0x14, mask = 0x4
Propagated bits info for function tcp_pbuf_prealloc/3:
 param 0: value = 0x4a, mask = 0x4a
 param 3: value = 0x0, mask = 0xfffffffe
 param 6: value = 0x0, mask = 0x1

IPA constant propagation end

Reclaiming functions: tcp_output_fill_options.isra.0/48 tcp_output_alloc_header/18 tcp_output_alloc_header_common/17
Reclaiming variables:
Clearing address taken flags:
Symbol table:

tcp_output_alloc_header_common.constprop.0/58 (tcp_output_alloc_header_common.constprop) @06458380
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of tcp_output_alloc_header_common/17
  Availability: local
  Function flags: count:228942 (estimated locally) local optimize_size
  Called by: tcp_rst/21 (123389 (estimated locally),0.37 per call) tcp_output_alloc_header.constprop/57 (123389 (estimated locally),0.53 per call) 
  Calls: pbuf_alloc/27 (228942 (estimated locally),1.00 per call) lwip_htons/30 (52886 (estimated locally),0.23 per call) lwip_htons/30 (52886 (estimated locally),0.23 per call) lwip_htonl/36 (52886 (estimated locally),0.23 per call) lwip_htons/30 (52886 (estimated locally),0.23 per call) lwip_htons/30 (52886 (estimated locally),0.23 per call) 
tcp_output_alloc_header.constprop.0/57 (tcp_output_alloc_header.constprop) @064580e0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of tcp_output_alloc_header/18
  Availability: local
  Function flags: count:230763 (estimated locally) local optimize_size
  Called by: tcp_send_empty_ack.part.0/54 (1073741824 (estimated locally),1.00 per call) tcp_keepalive/23 (123389 (estimated locally),0.53 per call) tcp_zero_window_probe/24 (205217 (estimated locally),0.57 per call) 
  Calls: tcp_output_alloc_header_common.constprop/58 (123389 (estimated locally),0.53 per call) tcp_output_alloc_header.part.0/51 (86372 (estimated locally),0.37 per call) 
tcp_output_fill_options.isra.0.constprop.0/56 (tcp_output_fill_options.isra.0.constprop) @0617b000
  Type: function definition analyzed
  Visibility: artificial
  References: 
  Referring: 
  Clone of tcp_output_fill_options.isra.0/48
  Availability: local
  Function flags: count:219131 (estimated locally) local optimize_size
  Called by: tcp_rst/21 (85200 (estimated locally),0.26 per call) tcp_send_empty_ack.part.0/54 (1063970774 (estimated locally),0.99 per call) tcp_keepalive/23 (122266 (estimated locally),0.53 per call) tcp_zero_window_probe/24 (204293 (estimated locally),0.57 per call) 
  Calls: 
tcp_output.part.0/55 (tcp_output.part.0) @063dbb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1650962 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_output/9 (135443 (estimated locally),0.38 per call) 
  Calls: tcp_send_empty_ack/22 (253504 (estimated locally),0.15 per call) tcp_route/1 (882769 (estimated locally),0.53 per call) ip6_select_source_address/40 (119172 (estimated locally),0.07 per call) lwip_htonl/36 (876147 (estimated locally),0.53 per call) tcp_send_empty_ack/22 (144564 (estimated locally),0.09 per call) lwip_htons/30 (4880636 (estimated locally),2.96 per call) lwip_htons/30 (2331352 (estimated locally),1.41 per call) tcp_output_segment/11 (4769541 (estimated locally),2.89 per call) lwip_htonl/36 (4664611 (estimated locally),2.83 per call) lwip_htons/30 (4664611 (estimated locally),2.83 per call) lwip_htons/30 (4664611 (estimated locally),2.83 per call) lwip_htonl/36 (1671092 (estimated locally),1.01 per call) lwip_htonl/36 (1671092 (estimated locally),1.01 per call) lwip_htonl/36 (3018862 (estimated locally),1.83 per call) lwip_htonl/36 (3018862 (estimated locally),1.83 per call) tcp_seg_free/35 (1539322 (estimated locally),0.93 per call) lwip_htonl/36 (4990426 (estimated locally),3.02 per call) 
tcp_send_empty_ack.part.0/54 (tcp_send_empty_ack.part.0) @063db2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_send_empty_ack/22 (123389 (estimated locally),0.53 per call) 
  Calls: lwip_htonl/36 (1073741824 (estimated locally),1.00 per call) tcp_output_alloc_header.constprop/57 (1073741824 (estimated locally),1.00 per call) tcp_output_fill_options.isra.0.constprop/56 (1063970774 (estimated locally),0.99 per call) tcp_output_control_segment/20 (1063970774 (estimated locally),0.99 per call) 
tcp_enqueue_flags.part.0/53 (tcp_enqueue_flags.part.0) @063a7460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwip_stats/31 (read)lwip_stats/31 (write)lwip_stats/31 (read)lwip_stats/31 (write)
  Referring: 
  Availability: local
  Function flags: count:160984 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_enqueue_flags/8 (75162 (estimated locally),0.35 per call) 
  Calls: pbuf_alloc/27 (160984 (estimated locally),1.00 per call) tcp_create_segment/2 (52886 (estimated locally),0.33 per call) pbuf_clen/26 (13162 (estimated locally),0.08 per call) 
tcp_output_control_segment.part.0/52 (tcp_output_control_segment.part.0) @063a7a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwip_stats/31 (read)lwip_stats/31 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_output_control_segment/20 (123389 (estimated locally),0.53 per call) 
  Calls: tcp_route/1 (1073741824 (estimated locally),1.00 per call) ip6_output_if/46 (177884361 (estimated locally),0.17 per call) ip4_output_if/47 (886515909 (estimated locally),0.83 per call) pbuf_free/28 (1073741824 (estimated locally),1.00 per call) 
tcp_output_alloc_header.part.0/51 (tcp_output_alloc_header.part.0) @063a71c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_output_alloc_header.constprop/57 (86372 (estimated locally),0.37 per call) 
  Calls: 
tcp_create_segment.part.0/50 (tcp_create_segment.part.0) @062ee620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwip_stats/31 (read)lwip_stats/31 (write)
  Referring: 
  Availability: local
  Function flags: count:167373 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_create_segment/2 (123389 (estimated locally),0.37 per call) 
  Calls: memp_malloc/33 (167373 (estimated locally),1.00 per call) pbuf_free/28 (7113 (estimated locally),0.04 per call) pbuf_add_header/34 (52886 (estimated locally),0.32 per call) tcp_seg_free/35 (9192 (estimated locally),0.05 per call) lwip_htons/30 (43694 (estimated locally),0.26 per call) lwip_htons/30 (43694 (estimated locally),0.26 per call) lwip_htonl/36 (43694 (estimated locally),0.26 per call) lwip_htons/30 (43694 (estimated locally),0.26 per call) 
tcp_pbuf_prealloc.part.0/49 (tcp_pbuf_prealloc.part.0) @062ee9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:167221 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_pbuf_prealloc/3 (167221 (estimated locally),0.49 per call) 
  Calls: pbuf_alloc/27 (167221 (estimated locally),1.00 per call) 
tcp_output_fill_options.isra.0/48 (tcp_output_fill_options.isra.0) @05ed18c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ip4_output_if/47 (ip4_output_if) @0624f0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_control_segment.part.0/52 (886515909 (estimated locally),0.83 per call) tcp_output_segment/11 (9076 (estimated locally),0.03 per call) 
  Calls: 
ip6_output_if/46 (ip6_output_if) @0624f000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_control_segment.part.0/52 (177884361 (estimated locally),0.17 per call) tcp_output_segment/11 (4675 (estimated locally),0.01 per call) 
  Calls: 
tcp_ticks/45 (tcp_ticks) @0624c7e0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: tcp_output_segment/11 (read)
  Availability: not_available
  Varpool flags:
tcp_eff_send_mss_netif/44 (tcp_eff_send_mss_netif) @061f69a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_segment/11 (15126 (estimated locally),0.04 per call) 
  Calls: 
ip4_route/43 (ip4_route) @061f61c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_route/1 (652565318 (estimated locally),0.61 per call) 
  Calls: 
ip6_route/42 (ip6_route) @061f6ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_route/1 (130940870 (estimated locally),0.12 per call) 
  Calls: 
netif_get_by_index/41 (netif_get_by_index) @061f6e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_route/1 (290235636 (estimated locally),0.27 per call) 
  Calls: 
ip6_select_source_address/40 (ip6_select_source_address) @061f6c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output.part.0/55 (119172 (estimated locally),0.07 per call) 
  Calls: 
tcp_input_pcb/39 (tcp_input_pcb) @0623e510
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: tcp_output/9 (read)
  Availability: not_available
  Varpool flags:
pbuf_realloc/38 (pbuf_realloc) @061f6540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_split_unsent_seg/6 (1840 (estimated locally),0.01 per call) 
  Calls: 
pbuf_copy_partial/37 (pbuf_copy_partial) @061f6460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_zero_window_probe/24 (102147 (estimated locally),0.29 per call) tcp_split_unsent_seg/6 (8074 (estimated locally),0.03 per call) 
  Calls: 
lwip_htonl/36 (lwip_htonl) @061f60e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_alloc_header_common.constprop/58 (52886 (estimated locally),0.23 per call) tcp_zero_window_probe/24 (204293 (estimated locally),0.57 per call) tcp_keepalive/23 (123389 (estimated locally),0.53 per call) tcp_output.part.0/55 (876147 (estimated locally),0.53 per call) tcp_output.part.0/55 (4664611 (estimated locally),2.83 per call) tcp_output.part.0/55 (1671092 (estimated locally),1.01 per call) tcp_output.part.0/55 (1671092 (estimated locally),1.01 per call) tcp_output.part.0/55 (3018862 (estimated locally),1.83 per call) tcp_output.part.0/55 (3018862 (estimated locally),1.83 per call) tcp_output.part.0/55 (4990426 (estimated locally),3.02 per call) tcp_send_empty_ack.part.0/54 (1073741824 (estimated locally),1.00 per call) tcp_rst/21 (123389 (estimated locally),0.37 per call) tcp_rexmit/15 (2170276 (estimated locally),6.06 per call) tcp_rexmit/15 (2170276 (estimated locally),6.06 per call) tcp_rexmit_rto_prepare/12 (125552 (estimated locally),0.35 per call) tcp_split_unsent_seg/6 (2664 (estimated locally),0.01 per call) tcp_output_segment/11 (15126 (estimated locally),0.04 per call) tcp_output_segment/11 (15126 (estimated locally),0.04 per call) tcp_output_segment/11 (45837 (estimated locally),0.13 per call) tcp_create_segment.part.0/50 (43694 (estimated locally),0.26 per call) 
  Calls: 
tcp_seg_free/35 (tcp_seg_free) @061f6000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output.part.0/55 (1539322 (estimated locally),0.93 per call) tcp_create_segment.part.0/50 (9192 (estimated locally),0.05 per call) 
  Calls: 
pbuf_add_header/34 (pbuf_add_header) @061ac620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_create_segment.part.0/50 (52886 (estimated locally),0.32 per call) 
  Calls: 
memp_malloc/33 (memp_malloc) @061ac540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_create_segment.part.0/50 (167373 (estimated locally),1.00 per call) 
  Calls: 
tcp_segs_free/32 (tcp_segs_free) @061acc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_write/5 (27397 (estimated locally),0.06 per call) 
  Calls: 
lwip_stats/31 (lwip_stats) @061c6318
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: tcp_output_segment/11 (read)tcp_output_segment/11 (write)tcp_create_segment.part.0/50 (read)tcp_create_segment.part.0/50 (write)tcp_rexmit/15 (read)tcp_rexmit/15 (write)tcp_output_control_segment.part.0/52 (read)tcp_output_control_segment.part.0/52 (write)tcp_output_segment/11 (read)tcp_output_segment/11 (write)tcp_write/5 (read)tcp_write/5 (write)tcp_enqueue_flags.part.0/53 (read)tcp_enqueue_flags.part.0/53 (write)tcp_write_checks/4 (read)tcp_write_checks/4 (write)tcp_split_unsent_seg/6 (read)tcp_split_unsent_seg/6 (write)tcp_enqueue_flags.part.0/53 (read)tcp_enqueue_flags.part.0/53 (write)tcp_rst/21 (read)tcp_rst/21 (write)
  Availability: not_available
  Varpool flags:
lwip_htons/30 (lwip_htons) @061acb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_alloc_header_common.constprop/58 (52886 (estimated locally),0.23 per call) tcp_output_alloc_header_common.constprop/58 (52886 (estimated locally),0.23 per call) tcp_output_alloc_header_common.constprop/58 (52886 (estimated locally),0.23 per call) tcp_output_alloc_header_common.constprop/58 (52886 (estimated locally),0.23 per call) tcp_zero_window_probe/24 (102147 (estimated locally),0.29 per call) tcp_zero_window_probe/24 (205217 (estimated locally),0.57 per call) tcp_output.part.0/55 (4880636 (estimated locally),2.96 per call) tcp_output.part.0/55 (2331352 (estimated locally),1.41 per call) tcp_output.part.0/55 (4664611 (estimated locally),2.83 per call) tcp_output.part.0/55 (4664611 (estimated locally),2.83 per call) tcp_rexmit_rto_prepare/12 (125552 (estimated locally),0.35 per call) tcp_send_fin/7 (41871 (estimated locally),0.12 per call) tcp_send_fin/7 (206870 (estimated locally),0.58 per call) tcp_split_unsent_seg/6 (1840 (estimated locally),0.01 per call) tcp_split_unsent_seg/6 (2664 (estimated locally),0.01 per call) tcp_write/5 (1124 (estimated locally),0.00 per call) tcp_output_segment/11 (45837 (estimated locally),0.13 per call) tcp_create_segment.part.0/50 (43694 (estimated locally),0.26 per call) tcp_create_segment.part.0/50 (43694 (estimated locally),0.26 per call) tcp_create_segment.part.0/50 (43694 (estimated locally),0.26 per call) 
  Calls: 
pbuf_cat/29 (pbuf_cat) @061aca80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_write/5 (4556 (estimated locally),0.01 per call) tcp_write/5 (376159 (estimated locally),0.80 per call) 
  Calls: 
pbuf_free/28 (pbuf_free) @061ac9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_split_unsent_seg/6 (5269 (estimated locally),0.02 per call) tcp_write/5 (27397 (estimated locally),0.06 per call) tcp_write/5 (11304 (estimated locally),0.02 per call) tcp_write/5 (7677 (estimated locally),0.02 per call) tcp_output_control_segment.part.0/52 (1073741824 (estimated locally),1.00 per call) tcp_create_segment.part.0/50 (7113 (estimated locally),0.04 per call) 
  Calls: 
pbuf_alloc/27 (pbuf_alloc) @061ac8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_alloc_header_common.constprop/58 (228942 (estimated locally),1.00 per call) tcp_enqueue_flags.part.0/53 (160984 (estimated locally),1.00 per call) tcp_split_unsent_seg/6 (11693 (estimated locally),0.04 per call) tcp_write/5 (383836 (estimated locally),0.81 per call) tcp_write/5 (391669 (estimated locally),0.83 per call) tcp_write/5 (8687 (estimated locally),0.02 per call) tcp_pbuf_prealloc.part.0/49 (167221 (estimated locally),1.00 per call) 
  Calls: 
pbuf_clen/26 (pbuf_clen) @061ac7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_enqueue_flags.part.0/53 (13162 (estimated locally),0.08 per call) tcp_split_unsent_seg/6 (1840 (estimated locally),0.01 per call) tcp_split_unsent_seg/6 (1840 (estimated locally),0.01 per call) tcp_split_unsent_seg/6 (1840 (estimated locally),0.01 per call) tcp_write/5 (565213 (estimated locally),1.20 per call) tcp_write/5 (2867 (estimated locally),0.01 per call) tcp_write/5 (1767 (estimated locally),0.00 per call) 
  Calls: 
memcpy/25 (memcpy) @061ac700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_write/5 (8584 (estimated locally),0.02 per call) tcp_write/5 (189054 (estimated locally),0.40 per call) tcp_write/5 (1767 (estimated locally),0.00 per call) 
  Calls: 
tcp_zero_window_probe/24 (tcp_zero_window_probe) @061ac000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_output_control_segment/20 (204293 (estimated locally),0.57 per call) tcp_output_fill_options.isra.0.constprop/56 (204293 (estimated locally),0.57 per call) lwip_htonl/36 (204293 (estimated locally),0.57 per call) pbuf_copy_partial/37 (102147 (estimated locally),0.29 per call) lwip_htons/30 (102147 (estimated locally),0.29 per call) tcp_output_alloc_header.constprop/57 (205217 (estimated locally),0.57 per call) lwip_htons/30 (205217 (estimated locally),0.57 per call) 
tcp_keepalive/23 (tcp_keepalive) @0617bd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_output_control_segment/20 (122266 (estimated locally),0.53 per call) tcp_output_fill_options.isra.0.constprop/56 (122266 (estimated locally),0.53 per call) tcp_output_alloc_header.constprop/57 (123389 (estimated locally),0.53 per call) lwip_htonl/36 (123389 (estimated locally),0.53 per call) 
tcp_send_empty_ack/22 (tcp_send_empty_ack) @0617b8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: tcp_output.part.0/55 (253504 (estimated locally),0.15 per call) tcp_output.part.0/55 (144564 (estimated locally),0.09 per call) 
  Calls: tcp_send_empty_ack.part.0/54 (123389 (estimated locally),0.53 per call) 
tcp_rst/21 (tcp_rst) @0617b620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/31 (read)lwip_stats/31 (write)
  Referring: 
  Availability: available
  Function flags: count:329661 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_output_control_segment/20 (85200 (estimated locally),0.26 per call) tcp_output_fill_options.isra.0.constprop/56 (85200 (estimated locally),0.26 per call) tcp_output_alloc_header_common.constprop/58 (123389 (estimated locally),0.37 per call) lwip_htonl/36 (123389 (estimated locally),0.37 per call) 
tcp_output_control_segment/20 (tcp_output_control_segment) @0617b380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:230763 (estimated locally) body local optimize_size
  Called by: tcp_zero_window_probe/24 (204293 (estimated locally),0.57 per call) tcp_keepalive/23 (122266 (estimated locally),0.53 per call) tcp_send_empty_ack.part.0/54 (1063970774 (estimated locally),0.99 per call) tcp_rst/21 (85200 (estimated locally),0.26 per call) 
  Calls: tcp_output_control_segment.part.0/52 (123389 (estimated locally),0.53 per call) 
tcp_output_alloc_header/18 (tcp_output_alloc_header) @0616e460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_output_alloc_header_common/17 (tcp_output_alloc_header_common) @0616ee00
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:228942 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_rexmit_fast/16 (tcp_rexmit_fast) @0616eb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_rexmit/15 (57875 (estimated locally),0.16 per call) 
tcp_rexmit/15 (tcp_rexmit) @0616e8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/31 (read)lwip_stats/31 (write)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_rexmit_fast/16 (57875 (estimated locally),0.16 per call) 
  Calls: lwip_htonl/36 (2170276 (estimated locally),6.06 per call) lwip_htonl/36 (2170276 (estimated locally),6.06 per call) tcp_output_segment_busy/10 (248259 (estimated locally),0.69 per call) 
tcp_rexmit_rto/14 (tcp_rexmit_rto) @0616e620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_rexmit_rto_commit/13 (40718 (estimated locally),0.18 per call) tcp_rexmit_rto_prepare/12 (123389 (estimated locally),0.53 per call) 
tcp_rexmit_rto_commit/13 (tcp_rexmit_rto_commit) @0616e380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_rexmit_rto/14 (40718 (estimated locally),0.18 per call) 
  Calls: tcp_output/9 (250539 (estimated locally),0.70 per call) 
tcp_rexmit_rto_prepare/12 (tcp_rexmit_rto_prepare) @0616e0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_rexmit_rto/14 (123389 (estimated locally),0.53 per call) 
  Calls: lwip_htons/30 (125552 (estimated locally),0.35 per call) lwip_htonl/36 (125552 (estimated locally),0.35 per call) tcp_output_segment_busy/10 (128232 (estimated locally),0.36 per call) tcp_output_segment_busy/10 (2203265 (estimated locally),6.16 per call) 
tcp_output_segment/11 (tcp_output_segment) @0615ce00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tcp_ticks/45 (read)lwip_stats/31 (read)lwip_stats/31 (write)lwip_stats/31 (read)lwip_stats/31 (write)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_output.part.0/55 (4769541 (estimated locally),2.89 per call) 
  Calls: ip4_output_if/47 (9076 (estimated locally),0.03 per call) ip6_output_if/46 (4675 (estimated locally),0.01 per call) lwip_htonl/36 (15126 (estimated locally),0.04 per call) lwip_htonl/36 (15126 (estimated locally),0.04 per call) tcp_eff_send_mss_netif/44 (15126 (estimated locally),0.04 per call) lwip_htons/30 (45837 (estimated locally),0.13 per call) lwip_htonl/36 (45837 (estimated locally),0.13 per call) tcp_output_segment_busy/10 (93774 (estimated locally),0.26 per call) 
tcp_output_segment_busy/10 (tcp_output_segment_busy) @0615c540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_rexmit/15 (248259 (estimated locally),0.69 per call) tcp_rexmit_rto_prepare/12 (128232 (estimated locally),0.36 per call) tcp_rexmit_rto_prepare/12 (2203265 (estimated locally),6.16 per call) tcp_output_segment/11 (93774 (estimated locally),0.26 per call) 
  Calls: 
tcp_output/9 (tcp_output) @0615c2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_input_pcb/39 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_rexmit_rto_commit/13 (250539 (estimated locally),0.70 per call) 
  Calls: tcp_output.part.0/55 (135443 (estimated locally),0.38 per call) 
tcp_enqueue_flags/8 (tcp_enqueue_flags) @060ffd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: tcp_send_fin/7 (208669 (estimated locally),0.58 per call) 
  Calls: tcp_enqueue_flags.part.0/53 (75162 (estimated locally),0.35 per call) 
tcp_send_fin/7 (tcp_send_fin) @060ffa80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_enqueue_flags/8 (208669 (estimated locally),0.58 per call) lwip_htons/30 (41871 (estimated locally),0.12 per call) lwip_htons/30 (206870 (estimated locally),0.58 per call) 
tcp_split_unsent_seg/6 (tcp_split_unsent_seg) @060ff700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/31 (read)lwip_stats/31 (write)
  Referring: 
  Availability: available
  Function flags: count:308170 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/28 (5269 (estimated locally),0.02 per call) pbuf_clen/26 (1840 (estimated locally),0.01 per call) pbuf_clen/26 (1840 (estimated locally),0.01 per call) lwip_htons/30 (1840 (estimated locally),0.01 per call) pbuf_realloc/38 (1840 (estimated locally),0.01 per call) pbuf_clen/26 (1840 (estimated locally),0.01 per call) tcp_create_segment/2 (2664 (estimated locally),0.01 per call) lwip_htonl/36 (2664 (estimated locally),0.01 per call) lwip_htons/30 (2664 (estimated locally),0.01 per call) pbuf_copy_partial/37 (8074 (estimated locally),0.03 per call) pbuf_alloc/27 (11693 (estimated locally),0.04 per call) 
tcp_write/5 (tcp_write) @060ff1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/31 (read)lwip_stats/31 (write)
  Referring: 
  Availability: available
  Function flags: count:471212 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_segs_free/32 (27397 (estimated locally),0.06 per call) pbuf_free/28 (27397 (estimated locally),0.06 per call) lwip_htons/30 (1124 (estimated locally),0.00 per call) pbuf_cat/29 (4556 (estimated locally),0.01 per call) memcpy/25 (8584 (estimated locally),0.02 per call) tcp_create_segment/2 (553908 (estimated locally),1.18 per call) pbuf_free/28 (11304 (estimated locally),0.02 per call) pbuf_clen/26 (565213 (estimated locally),1.20 per call) pbuf_cat/29 (376159 (estimated locally),0.80 per call) pbuf_free/28 (7677 (estimated locally),0.02 per call) pbuf_alloc/27 (383836 (estimated locally),0.81 per call) pbuf_alloc/27 (391669 (estimated locally),0.83 per call) memcpy/25 (189054 (estimated locally),0.40 per call) tcp_pbuf_prealloc/3 (196849 (estimated locally),0.42 per call) pbuf_clen/26 (2867 (estimated locally),0.01 per call) pbuf_alloc/27 (8687 (estimated locally),0.02 per call) pbuf_clen/26 (1767 (estimated locally),0.00 per call) memcpy/25 (1767 (estimated locally),0.00 per call) tcp_pbuf_prealloc/3 (5355 (estimated locally),0.01 per call) tcp_write_checks/4 (464823 (estimated locally),0.99 per call) 
tcp_write_checks/4 (tcp_write_checks) @060ba7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: lwip_stats/31 (read)lwip_stats/31 (write)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_write/5 (464823 (estimated locally),0.99 per call) 
  Calls: 
tcp_pbuf_prealloc/3 (tcp_pbuf_prealloc) @060ba540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:341266 (estimated locally) body local optimize_size
  Called by: tcp_write/5 (196849 (estimated locally),0.42 per call) tcp_write/5 (5355 (estimated locally),0.01 per call) 
  Calls: tcp_pbuf_prealloc.part.0/49 (167221 (estimated locally),0.49 per call) 
tcp_create_segment/2 (tcp_create_segment) @060ba2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:329661 (estimated locally) body local optimize_size
  Called by: tcp_enqueue_flags.part.0/53 (52886 (estimated locally),0.33 per call) tcp_split_unsent_seg/6 (2664 (estimated locally),0.01 per call) tcp_write/5 (553908 (estimated locally),1.18 per call) 
  Calls: tcp_create_segment.part.0/50 (123389 (estimated locally),0.37 per call) 
tcp_route/1 (tcp_route) @060ba000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: tcp_output.part.0/55 (882769 (estimated locally),0.53 per call) tcp_output_control_segment.part.0/52 (1073741824 (estimated locally),1.00 per call) 
  Calls: ip4_route/43 (652565318 (estimated locally),0.61 per call) ip6_route/42 (130940870 (estimated locally),0.12 per call) netif_get_by_index/41 (290235636 (estimated locally),0.27 per call) 

;; Function tcp_output_segment_busy (tcp_output_segment_busy, funcdef_no=10, decl_uid=7665, cgraph_uid=11, symbol_order=10)

Modification phase of node tcp_output_segment_busy/10
tcp_output_segment_busy (const struct tcp_seg * seg)
{
  struct pbuf * _1;
  unsigned char _2;
  int _3;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (seg_5(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = seg_5(D)->p;
  _2 = _1->ref;
  if (_2 != 1)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 125270]:
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 250539]:
  # _3 = PHI <1(5), 0(4)>
  return _3;

}



;; Function tcp_route (tcp_route, funcdef_no=1, decl_uid=7501, cgraph_uid=2, symbol_order=1)

Modification phase of node tcp_route/1
tcp_route (const struct tcp_pcb * pcb, const struct ip_addr_t * src, const struct ip_addr_t * dst)
{
  unsigned char _1;
  unsigned char _2;
  const struct ip6_addr_t * _3;
  const struct ip6_addr_t * _4;
  const struct ip4_addr_t * _5;
  struct netif * _6;
  struct netif * iftmp.19_7;
  struct netif * _13;
  struct netif * iftmp.19_17;
  struct netif * iftmp.19_19;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_10(D) != 0B)
    goto <bb 3>; [81.91%]
  else
    goto <bb 5>; [18.09%]

  <bb 3> [local count: 879501929]:
  _1 = pcb_10(D)->netif_idx;
  if (_1 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 290235636]:
  # DEBUG BEGIN_STMT
  _13 = netif_get_by_index (_1);
  goto <bb 10>; [100.00%]

  <bb 5> [local count: 783506189]:
  # DEBUG BEGIN_STMT
  if (dst_14(D) != 0B)
    goto <bb 6>; [82.57%]
  else
    goto <bb 8>; [17.43%]

  <bb 6> [local count: 646941060]:
  _2 = dst_14(D)->type;
  if (_2 == 6)
    goto <bb 7>; [20.24%]
  else
    goto <bb 8>; [79.76%]

  <bb 7> [local count: 130940870]:
  _3 = &src_15(D)->u_addr.ip6;
  _4 = &dst_14(D)->u_addr.ip6;
  iftmp.19_17 = ip6_route (_3, _4);
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 652565318]:
  _5 = &dst_14(D)->u_addr.ip4;
  iftmp.19_19 = ip4_route (_5);

  <bb 9> [local count: 783506188]:
  # iftmp.19_7 = PHI <iftmp.19_17(7), iftmp.19_19(8)>

  <bb 10> [local count: 1073741824]:
  # _6 = PHI <_13(4), iftmp.19_7(9)>
  return _6;

}



;; Function tcp_pbuf_prealloc (tcp_pbuf_prealloc, funcdef_no=3, decl_uid=7522, cgraph_uid=4, symbol_order=3)

Modification phase of node tcp_pbuf_prealloc/3
Adjusting mask for param 0 to 0x4a
Adjusting mask for param 3 to 0xfffffffe
Adjusting align: 2, misalign: 0
Adjusting mask for param 6 to 0x1
Setting value range of param 0 [0, 74]
Setting nonnull for 3
Setting value range of param 6 [0, 1]
tcp_pbuf_prealloc (pbuf_layer layer, u16_t length, u16_t max_length, u16_t * oversize, const struct tcp_pcb * pcb, u8_t apiflags, u8_t first_seg)
{
  struct pbuf * _1;

  <bb 2> [local count: 341266]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG alloc => length_5(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (oversize_6(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 102380]:

  <bb 3> [local count: 1023801147]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1023801147]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 238887]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_8(D) == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 8> [local count: 71666]:

  <bb 5> [local count: 716660804]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 716660804]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 167221]:
  _1 = tcp_pbuf_prealloc.part.0 (layer_12(D), length_5(D), max_length_9(D), oversize_6(D), pcb_8(D), apiflags_10(D), first_seg_11(D));
  return _1;

}



;; Function tcp_create_segment (tcp_create_segment, funcdef_no=2, decl_uid=7508, cgraph_uid=3, symbol_order=2)

Modification phase of node tcp_create_segment/2
tcp_create_segment (const struct tcp_pcb * pcb, struct pbuf * p, u8_t hdrflags, u32_t seqno, u8_t optflags)
{
  struct tcp_seg * _1;

  <bb 2> [local count: 329661]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_5(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 98898]:

  <bb 3> [local count: 988985746]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 988985746]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_7(D) == 0B)
    goto <bb 8>; [46.53%]
  else
    goto <bb 6>; [53.47%]

  <bb 8> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 123389]:
  _1 = tcp_create_segment.part.0 (pcb_5(D), p_7(D), hdrflags_10(D), seqno_9(D), optflags_8(D));
  return _1;

}



;; Function tcp_output_control_segment (tcp_output_control_segment, funcdef_no=20, decl_uid=7746, cgraph_uid=21, symbol_order=20)

Modification phase of node tcp_output_control_segment/20
tcp_output_control_segment (const struct tcp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * src, const struct ip_addr_t * dst)
{
  err_t D.8405;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
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
  _3 = tcp_output_control_segment.part.0 (pcb_6(D), p_4(D), src_7(D), dst_8(D));
  return _3;

}



;; Function tcp_output_fill_options.isra.0.constprop (tcp_output_fill_options.isra.0.constprop.0, funcdef_no=35, decl_uid=8452, cgraph_uid=54, symbol_order=56)

Modification phase of node tcp_output_fill_options.isra.0.constprop/56
tcp_output_fill_options.isra.0.constprop (struct pbuf * p)
{
  u32_t * opts;
  struct tcp_hdr * tcphdr;
  u8_t optflags;
  sizetype _4;
  sizetype _5;
  sizetype _6;
  sizetype _7;
  u8_t * _8;

  <bb 12> [local count: 219131]:
  # DEBUG optflags => 0

  <bb 2> [local count: 219131]:
  # DEBUG pcb s=> pcb
  # DEBUG num_sacks s=> num_sacks

  <bb 3> [local count: 219131]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG sacks_len => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_1(D) == 0B)
    goto <bb 4>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 4> [local count: 65739]:

  <bb 5> [local count: 657392954]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 657392954]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcphdr_2 = p_1(D)->payload;
  # DEBUG tcphdr => tcphdr_2
  # DEBUG BEGIN_STMT
  opts_3 = tcphdr_2 + 20;
  # DEBUG opts => opts_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = 0;
  _5 = _4 << 2;
  _6 = _5 & 4;
  _7 = _6 + 20;
  _8 = tcphdr_2 + _7;
  if (opts_3 != _8)
    goto <bb 8>; [70.00%]
  else
    goto <bb 11>; [30.00%]

  <bb 8> [local count: 107374]:

  <bb 9> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 9>; [100.00%]

  <bb 11> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function tcp_output_alloc_header_common.constprop (tcp_output_alloc_header_common.constprop.0, funcdef_no=33, decl_uid=8454, cgraph_uid=56, symbol_order=58)

Modification phase of node tcp_output_alloc_header_common.constprop/58
Adjusting mask for param 2 to 0x1
Adjusting mask for param 6 to 0x4
Setting value range of param 2 [0, 1]
Setting value range of param 6 [16, 20]
tcp_output_alloc_header_common.constprop (u32_t ackno, u16_t datalen, u32_t seqno_be, u16_t src_port, u16_t dst_port, u8_t flags, u16_t wnd)
{
  struct tcp_hdr * tcphdr;
  struct pbuf * p;
  u16_t optlen;
  short unsigned int _2;
  short unsigned int _3;
  int _5;
  int _6;
  short unsigned int _7;
  int _8;
  short unsigned int _11;
  short unsigned int _13;
  long unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _21;
  short unsigned int _22;
  short unsigned int _23;
  short unsigned int _25;

  <bb 9> [local count: 228942]:
  # DEBUG optlen => 0

  <bb 2> [local count: 228942]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = datalen_1(D);
  _3 = _2 + 20;
  p_4 = pbuf_alloc (54, _3, 640);
  # DEBUG p => p_4
  # DEBUG BEGIN_STMT
  if (p_4 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 3> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = 0;
  _6 = _5 + 19;
  _7 = p_4->len;
  _8 = (int) _7;
  if (_6 >= _8)
    goto <bb 4>; [67.00%]
  else
    goto <bb 7>; [33.00%]

  <bb 4> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcphdr_9 = p_4->payload;
  # DEBUG tcphdr => tcphdr_9
  # DEBUG BEGIN_STMT
  _11 = lwip_htons (src_port_10(D));
  tcphdr_9->src = _11;
  # DEBUG BEGIN_STMT
  _13 = lwip_htons (dst_port_12(D));
  tcphdr_9->dest = _13;
  # DEBUG BEGIN_STMT
  tcphdr_9->seqno = seqno_be_14(D);
  # DEBUG BEGIN_STMT
  _16 = lwip_htonl (ackno_15(D));
  tcphdr_9->ackno = _16;
  # DEBUG BEGIN_STMT
  _17 = 0;
  _18 = _17 + 5;
  _19 = _18 << 12;
  _21 = (short unsigned int) flags_20(D);
  _22 = _19 | _21;
  _23 = lwip_htons (_22);
  tcphdr_9->_hdrlen_rsvd_flags = _23;
  # DEBUG BEGIN_STMT
  _25 = lwip_htons (wnd_24(D));
  tcphdr_9->wnd = _25;
  # DEBUG BEGIN_STMT
  tcphdr_9->chksum = 0;
  # DEBUG BEGIN_STMT
  tcphdr_9->urgp = 0;

  <bb 8> [local count: 121568]:
  # DEBUG BEGIN_STMT
  return p_4;

}



;; Function tcp_output_alloc_header.constprop (tcp_output_alloc_header.constprop.0, funcdef_no=34, decl_uid=8453, cgraph_uid=55, symbol_order=57)

Modification phase of node tcp_output_alloc_header.constprop/57
Adjusting mask for param 2 to 0x1
Setting value range of param 2 [0, 1]
tcp_output_alloc_header.constprop (struct tcp_pcb * pcb, u16_t datalen, u32_t seqno_be)
{
  struct pbuf * p;
  u16_t optlen;
  long unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;

  <bb 9> [local count: 230763]:
  # DEBUG optlen => 0

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_1(D) == 0B)
    goto <bb 3>; [46.53%]
  else
    goto <bb 6>; [53.47%]

  <bb 3> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 6> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pcb_1(D)->rcv_nxt;
  _3 = pcb_1(D)->local_port;
  _4 = pcb_1(D)->remote_port;
  _5 = pcb_1(D)->rcv_ann_wnd;
  p_8 = tcp_output_alloc_header_common (_2, 0, datalen_6(D), seqno_be_7(D), _3, _4, 16, _5);
  # DEBUG p => p_8
  # DEBUG BEGIN_STMT
  if (p_8 != 0B)
    goto <bb 7>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 7> [local count: 86372]:
  # DEBUG D#3 => 0
  # DEBUG D#4 => datalen_6(D)
  # DEBUG D#5 => seqno_be_7(D)
  tcp_output_alloc_header.part.0 (pcb_1(D));

  <bb 8> [local count: 123389]:
  # DEBUG BEGIN_STMT
  return p_8;

}



;; Function tcp_write (tcp_write, funcdef_no=5, decl_uid=7237, cgraph_uid=6, symbol_order=5)

Modification phase of node tcp_write/5
tcp_write (struct tcp_pcb * pcb, const void * arg, u16_t len, u8_t apiflags)
{
  struct pbuf * p;
  struct pbuf * p;
  struct pbuf * p2;
  u16_t seglen;
  u16_t left;
  struct pbuf * p;
  struct pbuf * p;
  u16_t seglen;
  u16_t unsent_optlen;
  u16_t space;
  u16_t mss_local;
  err_t err;
  u16_t extendlen;
  u16_t oversize_used;
  u16_t oversize;
  u16_t queuelen;
  u16_t pos;
  struct tcp_seg * queue;
  struct tcp_seg * prev_seg;
  struct tcp_seg * seg;
  struct tcp_seg * last_unsent;
  struct pbuf * concat_p;
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  struct tcp_seg * _4;
  struct tcp_seg * _5;
  unsigned char _6;
  int _7;
  int _8;
  short unsigned int _9;
  int _10;
  short unsigned int _11;
  int _12;
  int _13;
  int _14;
  short unsigned int _16;
  short unsigned int _17;
  short unsigned int _21;
  short unsigned int _23;
  short unsigned int oversize.5_24;
  int _26;
  int _27;
  int _28;
  int _29;
  int _30;
  void * _31;
  sizetype _32;
  const void * _33;
  unsigned int _34;
  struct pbuf * _35;
  unsigned char _36;
  void * _37;
  short unsigned int _38;
  sizetype _39;
  const u8_t * _40;
  sizetype _41;
  const void * _42;
  short unsigned int _43;
  _Bool _45;
  unsigned char _46;
  short unsigned int _47;
  void * _48;
  sizetype _49;
  const void * _50;
  unsigned int _51;
  short unsigned int oversize.6_52;
  sizetype _53;
  const void * _54;
  long unsigned int _55;
  long unsigned int _56;
  long unsigned int _57;
  short unsigned int _58;
  short unsigned int _59;
  struct pbuf * _60;
  void * _61;
  short unsigned int _62;
  sizetype _63;
  void * _64;
  unsigned int _65;
  short unsigned int _66;
  short unsigned int _67;
  short unsigned int _68;
  short unsigned int _69;
  short unsigned int oversize.7_70;
  struct pbuf * _71;
  short unsigned int _72;
  short unsigned int _73;
  short unsigned int _74;
  struct pbuf * _75;
  short unsigned int _76;
  short unsigned int _77;
  struct pbuf * _78;
  short unsigned int _79;
  short unsigned int _80;
  short unsigned int _81;
  short unsigned int _82;
  short unsigned int _83;
  short unsigned int _84;
  long unsigned int _85;
  long unsigned int _86;
  long unsigned int _87;
  short unsigned int _88;
  short unsigned int _89;
  struct tcp_seg * _90;
  struct tcp_seg * _91;
  struct tcp_hdr * _92;
  short unsigned int _93;
  short unsigned int _94;
  struct tcp_hdr * _95;
  short unsigned int _96;
  short unsigned int _97;
  short unsigned int _98;
  short unsigned int _99;
  short unsigned int _100;
  short unsigned int _101;
  struct tcp_seg * _102;
  struct tcp_seg * _103;
  err_t _124;
  u16_t iftmp.0_125;
  unsigned char _153;
  unsigned char _154;
  int _155;
  unsigned char _156;
  unsigned char _157;
  short unsigned int _188;
  short unsigned int _195;
  short unsigned int _238;

  <bb 2> [local count: 471212]:
  # DEBUG BEGIN_STMT
  # DEBUG concat_p => 0B
  # DEBUG BEGIN_STMT
  # DEBUG last_unsent => 0B
  # DEBUG seg => 0B
  # DEBUG prev_seg => 0B
  # DEBUG queue => 0B
  # DEBUG BEGIN_STMT
  # DEBUG pos => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optflags => 0
  # DEBUG BEGIN_STMT
  oversize = 0;
  # DEBUG BEGIN_STMT
  # DEBUG oversize_used => 0
  # DEBUG BEGIN_STMT
  # DEBUG extendlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_160(D) == 0B)
    goto <bb 99>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 469091]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_160(D)->snd_wnd_max;
  _2 = _1 >> 1;
  _3 = pcb_160(D)->mss;
  mss_local_161 = MIN_EXPR <_2, _3>;
  # DEBUG mss_local => mss_local_161
  # DEBUG BEGIN_STMT
  if (mss_local_161 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 234546]:

  <bb 5> [local count: 469091]:
  # iftmp.0_125 = PHI <_3(4), mss_local_161(3)>
  # DEBUG mss_local => iftmp.0_125
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_163(D) == 0B)
    goto <bb 99>; [0.91%]
  else
    goto <bb 6>; [99.09%]

  <bb 6> [local count: 464823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  err_166 = tcp_write_checks (pcb_160(D), len_164(D));
  # DEBUG err => err_166
  # DEBUG BEGIN_STMT
  if (err_166 != 0)
    goto <bb 99>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 7> [local count: 306783]:
  # DEBUG BEGIN_STMT
  queuelen_167 = pcb_160(D)->snd_queuelen;
  # DEBUG queuelen => queuelen_167
  # DEBUG BEGIN_STMT
  # DEBUG optlen => 0
  # DEBUG BEGIN_STMT
  _4 = pcb_160(D)->unsent;
  if (_4 != 0B)
    goto <bb 111>; [70.00%]
  else
    goto <bb 35>; [30.00%]

  <bb 111> [local count: 214748]:

  <bb 8> [local count: 1952255]:
  # last_unsent_106 = PHI <_4(111), _5(125)>
  # DEBUG last_unsent => last_unsent_106
  # DEBUG BEGIN_STMT
  _5 = last_unsent_106->next;
  if (_5 != 0B)
    goto <bb 125>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 125> [local count: 1737507]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 214748]:
  # last_unsent_162 = PHI <last_unsent_106(8)>
  # DEBUG BEGIN_STMT
  _6 = last_unsent_162->flags;
  _7 = (int) _6;
  _8 = _7 << 2;
  _9 = (short unsigned int) _8;
  unsent_optlen_170 = _9 & 4;
  # DEBUG unsent_optlen => unsent_optlen_170
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = (int) iftmp.0_125;
  _11 = last_unsent_162->len;
  _12 = (int) _11;
  _13 = (int) unsent_optlen_170;
  _14 = _12 + _13;
  if (_10 < _14)
    goto <bb 100>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 100> [local count: 107374]:

  <bb 10> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 113> [local count: 1073741824]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = _11 + unsent_optlen_170;
  space_171 = iftmp.0_125 - _16;
  # DEBUG space => space_171
  # DEBUG BEGIN_STMT
  _17 = pcb_160(D)->unsent_oversize;
  oversize = _17;
  # DEBUG BEGIN_STMT
  if (_17 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 12> [local count: 53687]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_17 > space_171)
    goto <bb 101>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 101> [local count: 26844]:

  <bb 13> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 114> [local count: 268435456]:
  goto <bb 13>; [100.00%]

  <bb 14> [local count: 26843]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG seg => last_unsent_162
  # DEBUG BEGIN_STMT
  _21 = MIN_EXPR <_17, len_164(D)>;
  oversize_used_174 = MIN_EXPR <_21, space_171>;
  # DEBUG oversize_used => oversize_used_174
  # DEBUG BEGIN_STMT
  # DEBUG pos => oversize_used_174
  # DEBUG BEGIN_STMT
  _23 = _17 - oversize_used_174;
  oversize = _23;
  # DEBUG BEGIN_STMT
  space_176 = space_171 - oversize_used_174;
  # DEBUG space => space_176

  <bb 15> [local count: 80530]:
  # seg_107 = PHI <0B(11), last_unsent_162(14)>
  # pos_113 = PHI <0(11), oversize_used_174(14)>
  # space_119 = PHI <space_171(11), space_176(14)>
  # DEBUG space => space_119
  # DEBUG oversize_used => pos_113
  # DEBUG pos => pos_113
  # DEBUG seg => seg_107
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oversize.5_24 = oversize;
  if (oversize.5_24 != 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 16> [local count: 40265]:
  if (pos_113 != len_164(D))
    goto <bb 102>; [66.00%]
  else
    goto <bb 18>; [34.00%]

  <bb 102> [local count: 26575]:

  <bb 17> [local count: 265751101]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 115> [local count: 265751101]:
  goto <bb 17>; [100.00%]

  <bb 18> [local count: 53955]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pos_113 < len_164(D))
    goto <bb 19>; [67.00%]
  else
    goto <bb 59>; [33.00%]

  <bb 19> [local count: 36150]:
  if (space_119 != 0)
    goto <bb 20>; [67.00%]
  else
    goto <bb 59>; [33.00%]

  <bb 20> [local count: 24221]:
  if (_11 != 0)
    goto <bb 21>; [67.00%]
  else
    goto <bb 59>; [33.00%]

  <bb 21> [local count: 16228]:
  # DEBUG BEGIN_STMT
  _26 = (int) len_164(D);
  _27 = (int) pos_113;
  _28 = _26 - _27;
  _29 = (int) space_119;
  _30 = MIN_EXPR <_28, _29>;
  seglen_179 = (u16_t) _30;
  # DEBUG seglen => seglen_179
  # DEBUG BEGIN_STMT
  # DEBUG seg => last_unsent_162
  # DEBUG BEGIN_STMT
  _153 = apiflags_181(D) & 1;
  if (_153 != 0)
    goto <bb 22>; [33.00%]
  else
    goto <bb 25>; [67.00%]

  <bb 22> [local count: 5355]:
  # DEBUG BEGIN_STMT
  concat_p_192 = tcp_pbuf_prealloc (0, seglen_179, space_119, &oversize, pcb_160(D), apiflags_181(D), 1);
  # DEBUG concat_p => concat_p_192
  if (concat_p_192 == 0B)
    goto <bb 23>; [67.00%]
  else
    goto <bb 24>; [33.00%]

  <bb 23> [local count: 3588]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 91>; [100.00%]

  <bb 24> [local count: 1767]:
  # DEBUG BEGIN_STMT
  _31 = concat_p_192->payload;
  _32 = (sizetype) pos_113;
  _33 = arg_163(D) + _32;
  _155 = _30 & 65535;
  _34 = (unsigned int) _155;
  memcpy (_31, _33, _34);
  # DEBUG BEGIN_STMT
  _195 = pbuf_clen (concat_p_192);
  queuelen_196 = queuelen_167 + _195;
  # DEBUG queuelen => queuelen_196
  goto <bb 34>; [100.00%]

  <bb 25> [local count: 10873]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  p_182 = last_unsent_162->p;
  # DEBUG p => p_182

  <bb 26> [local count: 98842]:
  # p_120 = PHI <p_182(25), _35(124)>
  # DEBUG p => p_120
  # DEBUG BEGIN_STMT
  _35 = p_120->next;
  if (_35 != 0B)
    goto <bb 124>; [89.00%]
  else
    goto <bb 27>; [11.00%]

  <bb 124> [local count: 87969]:
  goto <bb 26>; [100.00%]

  <bb 27> [local count: 10873]:
  # p_25 = PHI <p_120(26)>
  # DEBUG BEGIN_STMT
  _36 = p_25->type_internal;
  _154 = _36 & 192;
  if (_154 == 0)
    goto <bb 28>; [67.00%]
  else
    goto <bb 31>; [33.00%]

  <bb 28> [local count: 7285]:
  _37 = p_25->payload;
  _38 = p_25->len;
  _39 = (sizetype) _38;
  _40 = _37 + _39;
  if (_40 == arg_163(D))
    goto <bb 29>; [30.00%]
  else
    goto <bb 31>; [70.00%]

  <bb 29> [local count: 2185]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pos_113 != 0)
    goto <bb 110>; [67.00%]
  else
    goto <bb 34>; [33.00%]

  <bb 110> [local count: 1464]:

  <bb 30> [local count: 14642189]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 123> [local count: 14642189]:
  goto <bb 30>; [100.00%]

  <bb 31> [local count: 8687]:
  # DEBUG BEGIN_STMT
  concat_p_185 = pbuf_alloc (0, seglen_179, 1);
  # DEBUG concat_p => concat_p_185
  if (concat_p_185 == 0B)
    goto <bb 32>; [67.00%]
  else
    goto <bb 33>; [33.00%]

  <bb 32> [local count: 5820]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 91>; [100.00%]

  <bb 33> [local count: 2867]:
  # DEBUG BEGIN_STMT
  _41 = (sizetype) pos_113;
  _42 = arg_163(D) + _41;
  MEM[(struct pbuf_rom *)concat_p_185].payload = _42;
  # DEBUG BEGIN_STMT
  _188 = pbuf_clen (concat_p_185);
  queuelen_189 = queuelen_167 + _188;
  # DEBUG queuelen => queuelen_189

  <bb 34> [local count: 5355]:
  # concat_p_104 = PHI <concat_p_192(24), 0B(29), concat_p_185(33)>
  # queuelen_115 = PHI <queuelen_196(24), queuelen_167(29), queuelen_189(33)>
  # extendlen_118 = PHI <0(24), seglen_179(29), 0(33)>
  # DEBUG extendlen => extendlen_118
  # DEBUG queuelen => queuelen_115
  # DEBUG concat_p => concat_p_104
  # DEBUG BEGIN_STMT
  pos_197 = pos_113 + seglen_179;
  # DEBUG pos => pos_197
  goto <bb 59>; [100.00%]

  <bb 35> [local count: 92035]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _43 = pcb_160(D)->unsent_oversize;
  if (_43 != 0)
    goto <bb 112>; [67.00%]
  else
    goto <bb 59>; [33.00%]

  <bb 112> [local count: 61663]:

  <bb 36> [local count: 616634588]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 126> [local count: 616634588]:
  goto <bb 36>; [100.00%]

  <bb 37> [local count: 596511]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  left_223 = len_164(D) - pos_114;
  # DEBUG left => left_223
  # DEBUG BEGIN_STMT
  # DEBUG max_len => iftmp.0_125
  # DEBUG BEGIN_STMT
  seglen_224 = MIN_EXPR <iftmp.0_125, left_223>;
  # DEBUG seglen => seglen_224
  # DEBUG BEGIN_STMT
  _157 = apiflags_181(D) & 1;
  if (_157 != 0)
    goto <bb 38>; [33.00%]
  else
    goto <bb 43>; [67.00%]

  <bb 38> [local count: 196849]:
  # DEBUG BEGIN_STMT
  _45 = queue_111 == 0B;
  _46 = (unsigned char) _45;
  p_234 = tcp_pbuf_prealloc (74, seglen_224, iftmp.0_125, &oversize, pcb_160(D), apiflags_181(D), _46);
  # DEBUG p => p_234
  if (p_234 == 0B)
    goto <bb 39>; [2.00%]
  else
    goto <bb 40>; [98.00%]

  <bb 39> [local count: 3937]:
  # queue_15 = PHI <queue_111(38)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 91>; [100.00%]

  <bb 40> [local count: 192912]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _47 = p_234->len;
  if (_47 < seglen_224)
    goto <bb 104>; [2.00%]
  else
    goto <bb 42>; [98.00%]

  <bb 104> [local count: 3858]:

  <bb 41> [local count: 38582415]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 117> [local count: 38582415]:
  goto <bb 41>; [100.00%]

  <bb 42> [local count: 189054]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _48 = p_234->payload;
  _49 = (sizetype) pos_114;
  _50 = arg_163(D) + _49;
  _51 = (unsigned int) seglen_224;
  memcpy (_48, _50, _51);
  goto <bb 50>; [100.00%]

  <bb 43> [local count: 399663]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oversize.6_52 = oversize;
  if (oversize.6_52 != 0)
    goto <bb 106>; [2.00%]
  else
    goto <bb 45>; [98.00%]

  <bb 106> [local count: 7993]:

  <bb 44> [local count: 79932647]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 119> [local count: 79932647]:
  goto <bb 44>; [100.00%]

  <bb 45> [local count: 391669]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  p2_226 = pbuf_alloc (74, seglen_224, 1);
  # DEBUG p2 => p2_226
  if (p2_226 == 0B)
    goto <bb 46>; [2.00%]
  else
    goto <bb 47>; [98.00%]

  <bb 46> [local count: 7833]:
  # queue_18 = PHI <queue_111(45)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 91>; [100.00%]

  <bb 47> [local count: 383836]:
  # DEBUG BEGIN_STMT
  _53 = (sizetype) pos_114;
  _54 = arg_163(D) + _53;
  MEM[(struct pbuf_rom *)p2_226].payload = _54;
  # DEBUG BEGIN_STMT
  p_229 = pbuf_alloc (74, 0, 640);
  # DEBUG p => p_229
  if (p_229 == 0B)
    goto <bb 48>; [2.00%]
  else
    goto <bb 49>; [98.00%]

  <bb 48> [local count: 7677]:
  # queue_19 = PHI <queue_111(47)>
  # p2_199 = PHI <p2_226(47)>
  # DEBUG BEGIN_STMT
  pbuf_free (p2_199);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 91>; [100.00%]

  <bb 49> [local count: 376159]:
  # DEBUG BEGIN_STMT
  pbuf_cat (p_229, p2_226);

  <bb 50> [local count: 565213]:
  # p_121 = PHI <p_234(42), p_229(49)>
  # DEBUG p => p_121
  # DEBUG BEGIN_STMT
  _238 = pbuf_clen (p_121);
  queuelen_239 = queuelen_116 + _238;
  # DEBUG queuelen => queuelen_239
  # DEBUG BEGIN_STMT
  if (queuelen_239 > 20)
    goto <bb 51>; [2.00%]
  else
    goto <bb 52>; [98.00%]

  <bb 51> [local count: 11304]:
  # queue_173 = PHI <queue_111(50)>
  # p_180 = PHI <p_121(50)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_180);
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 91>; [100.00%]

  <bb 52> [local count: 553908]:
  # DEBUG BEGIN_STMT
  _55 = pcb_160(D)->snd_lbb;
  _56 = (long unsigned int) pos_114;
  _57 = _55 + _56;
  seg_241 = tcp_create_segment (pcb_160(D), p_121, 0, _57, 0);
  # DEBUG seg => seg_241
  if (seg_241 == 0B)
    goto <bb 53>; [2.00%]
  else
    goto <bb 54>; [98.00%]

  <bb 53> [local count: 11078]:
  # queue_20 = PHI <queue_111(52)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 91>; [100.00%]

  <bb 54> [local count: 542830]:
  # DEBUG BEGIN_STMT
  if (queue_111 == 0B)
    goto <bb 58>; [30.00%]
  else
    goto <bb 55>; [70.00%]

  <bb 55> [local count: 379981]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (prev_seg_109 == 0B)
    goto <bb 105>; [2.00%]
  else
    goto <bb 57>; [98.00%]

  <bb 105> [local count: 7600]:

  <bb 56> [local count: 75996370]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 118> [local count: 75996370]:
  goto <bb 56>; [100.00%]

  <bb 57> [local count: 372382]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  prev_seg_109->next = seg_241;

  <bb 58> [local count: 535231]:
  # queue_110 = PHI <seg_241(54), queue_111(57)>
  # DEBUG queue => queue_110
  # DEBUG BEGIN_STMT
  # DEBUG prev_seg => seg_241
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pos_244 = pos_114 + seglen_224;
  # DEBUG pos => pos_244
  goto <bb 60>; [100.00%]

  <bb 59> [local count: 73454]:
  # concat_p_252 = PHI <0B(35), 0B(18), 0B(19), 0B(20), concat_p_104(34)>
  # last_unsent_253 = PHI <0B(35), last_unsent_162(18), last_unsent_162(19), last_unsent_162(20), last_unsent_162(34)>
  # seg_254 = PHI <0B(35), seg_107(18), seg_107(19), seg_107(20), last_unsent_162(34)>
  # pos_255 = PHI <0(35), pos_113(18), pos_113(19), pos_113(20), pos_197(34)>
  # queuelen_256 = PHI <queuelen_167(35), queuelen_167(18), queuelen_167(19), queuelen_167(20), queuelen_115(34)>
  # oversize_used_257 = PHI <0(35), pos_113(18), pos_113(19), pos_113(20), pos_113(34)>
  # extendlen_258 = PHI <0(35), 0(18), 0(19), 0(20), extendlen_118(34)>

  <bb 60> [local count: 608685]:
  # seg_108 = PHI <seg_254(59), seg_241(58)>
  # prev_seg_109 = PHI <0B(59), seg_241(58)>
  # queue_111 = PHI <0B(59), queue_110(58)>
  # pos_114 = PHI <pos_255(59), pos_244(58)>
  # queuelen_116 = PHI <queuelen_256(59), queuelen_239(58)>
  # DEBUG extendlen => extendlen_258
  # DEBUG oversize_used => oversize_used_257
  # DEBUG queuelen => queuelen_116
  # DEBUG pos => pos_114
  # DEBUG queue => queue_111
  # DEBUG prev_seg => prev_seg_109
  # DEBUG seg => seg_108
  # DEBUG last_unsent => last_unsent_253
  # DEBUG concat_p => concat_p_252
  # DEBUG BEGIN_STMT
  if (pos_114 < len_164(D))
    goto <bb 37>; [98.00%]
  else
    goto <bb 61>; [2.00%]

  <bb 61> [local count: 12174]:
  # seg_169 = PHI <seg_108(60)>
  # queue_22 = PHI <queue_111(60)>
  # queuelen_117 = PHI <queuelen_116(60)>
  # DEBUG BEGIN_STMT
  if (oversize_used_257 != 0)
    goto <bb 62>; [50.00%]
  else
    goto <bb 68>; [50.00%]

  <bb 62> [local count: 6087]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  p_200 = last_unsent_253->p;
  # DEBUG p => p_200
  goto <bb 66>; [100.00%]

  <bb 63> [local count: 49248]:
  # DEBUG BEGIN_STMT
  _58 = p_122->tot_len;
  _59 = _58 + oversize_used_257;
  p_122->tot_len = _59;
  # DEBUG BEGIN_STMT
  _60 = p_122->next;
  if (_60 == 0B)
    goto <bb 64>; [17.43%]
  else
    goto <bb 65>; [82.57%]

  <bb 64> [local count: 8584]:
  # DEBUG BEGIN_STMT
  _61 = p_122->payload;
  _62 = p_122->len;
  _63 = (sizetype) _62;
  _64 = _61 + _63;
  _65 = (unsigned int) oversize_used_257;
  memcpy (_64, arg_163(D), _65);
  # DEBUG BEGIN_STMT
  _66 = p_122->len;
  _67 = _66 + oversize_used_257;
  p_122->len = _67;

  <bb 65> [local count: 49248]:
  # DEBUG BEGIN_STMT
  p_205 = p_122->next;
  # DEBUG p => p_205

  <bb 66> [local count: 55335]:
  # p_122 = PHI <p_200(62), p_205(65)>
  # DEBUG p => p_122
  # DEBUG BEGIN_STMT
  if (p_122 != 0B)
    goto <bb 63>; [89.00%]
  else
    goto <bb 67>; [11.00%]

  <bb 67> [local count: 6087]:
  # DEBUG BEGIN_STMT
  _68 = last_unsent_253->len;
  _69 = _68 + oversize_used_257;
  last_unsent_253->len = _69;

  <bb 68> [local count: 12174]:
  # DEBUG BEGIN_STMT
  oversize.7_70 = oversize;
  pcb_160(D)->unsent_oversize = oversize.7_70;
  # DEBUG BEGIN_STMT
  if (concat_p_252 != 0B)
    goto <bb 69>; [70.00%]
  else
    goto <bb 72>; [30.00%]

  <bb 69> [local count: 8522]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (last_unsent_253 == 0B)
    goto <bb 107>; [46.53%]
  else
    goto <bb 71>; [53.47%]

  <bb 107> [local count: 3965]:

  <bb 70> [local count: 39651025]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 120> [local count: 39651025]:
  goto <bb 70>; [100.00%]

  <bb 71> [local count: 4556]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _71 = last_unsent_253->p;
  pbuf_cat (_71, concat_p_252);
  # DEBUG BEGIN_STMT
  _72 = last_unsent_253->len;
  _73 = concat_p_252->tot_len;
  _74 = _72 + _73;
  last_unsent_253->len = _74;
  goto <bb 80>; [100.00%]

  <bb 72> [local count: 3652]:
  # DEBUG BEGIN_STMT
  if (extendlen_258 != 0)
    goto <bb 73>; [50.00%]
  else
    goto <bb 80>; [50.00%]

  <bb 73> [local count: 1826]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (last_unsent_253 == 0B)
    goto <bb 74>; [30.00%]
  else
    goto <bb 75>; [70.00%]

  <bb 74> [local count: 931]:
  goto <bb 76>; [100.00%]

  <bb 75> [local count: 1278]:
  _75 = last_unsent_253->p;
  if (_75 == 0B)
    goto <bb 74>; [30.00%]
  else
    goto <bb 109>; [70.00%]

  <bb 109> [local count: 895]:
  goto <bb 78>; [100.00%]

  <bb 122> [local count: 9312896]:

  <bb 76> [local count: 9312896]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT
  goto <bb 122>; [100.00%]

  <bb 77> [local count: 7239]:
  # DEBUG BEGIN_STMT
  _76 = p_123->tot_len;
  _77 = _76 + extendlen_258;
  p_123->tot_len = _77;
  # DEBUG BEGIN_STMT
  # DEBUG p => _78

  <bb 78> [local count: 8134]:
  # p_123 = PHI <_78(77), _75(109)>
  # DEBUG p => p_123
  # DEBUG BEGIN_STMT
  _78 = p_123->next;
  if (_78 != 0B)
    goto <bb 77>; [89.00%]
  else
    goto <bb 79>; [11.00%]

  <bb 79> [local count: 895]:
  # p_190 = PHI <p_123(78)>
  # DEBUG BEGIN_STMT
  _79 = p_190->tot_len;
  _80 = _79 + extendlen_258;
  p_190->tot_len = _80;
  # DEBUG BEGIN_STMT
  _81 = p_190->len;
  _82 = _81 + extendlen_258;
  p_190->len = _82;
  # DEBUG BEGIN_STMT
  _83 = last_unsent_253->len;
  _84 = _83 + extendlen_258;
  last_unsent_253->len = _84;

  <bb 80> [local count: 7277]:
  # DEBUG BEGIN_STMT
  if (last_unsent_253 == 0B)
    goto <bb 81>; [30.00%]
  else
    goto <bb 82>; [70.00%]

  <bb 81> [local count: 2183]:
  # DEBUG BEGIN_STMT
  pcb_160(D)->unsent = queue_22;
  goto <bb 83>; [100.00%]

  <bb 82> [local count: 5094]:
  # DEBUG BEGIN_STMT
  last_unsent_253->next = queue_22;

  <bb 83> [local count: 7277]:
  # DEBUG BEGIN_STMT
  _85 = pcb_160(D)->snd_lbb;
  _86 = (long unsigned int) len_164(D);
  _87 = _85 + _86;
  pcb_160(D)->snd_lbb = _87;
  # DEBUG BEGIN_STMT
  _88 = pcb_160(D)->snd_buf;
  _89 = _88 - len_164(D);
  pcb_160(D)->snd_buf = _89;
  # DEBUG BEGIN_STMT
  pcb_160(D)->snd_queuelen = queuelen_117;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (queuelen_117 != 0)
    goto <bb 84>; [50.00%]
  else
    goto <bb 87>; [50.00%]

  <bb 84> [local count: 3639]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _90 = pcb_160(D)->unacked;
  if (_90 == 0B)
    goto <bb 85>; [30.00%]
  else
    goto <bb 87>; [70.00%]

  <bb 85> [local count: 1092]:
  _91 = pcb_160(D)->unsent;
  if (_91 == 0B)
    goto <bb 108>; [30.00%]
  else
    goto <bb 87>; [70.00%]

  <bb 108> [local count: 328]:

  <bb 86> [local count: 3274798]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 121> [local count: 3274798]:
  goto <bb 86>; [100.00%]

  <bb 87> [local count: 6950]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (seg_169 != 0B)
    goto <bb 88>; [70.00%]
  else
    goto <bb 99>; [30.00%]

  <bb 88> [local count: 4865]:
  _92 = seg_169->tcphdr;
  if (_92 != 0B)
    goto <bb 89>; [70.00%]
  else
    goto <bb 99>; [30.00%]

  <bb 89> [local count: 3405]:
  _156 = apiflags_181(D) & 2;
  if (_156 == 0)
    goto <bb 90>; [33.00%]
  else
    goto <bb 99>; [67.00%]

  <bb 90> [local count: 1124]:
  # DEBUG BEGIN_STMT
  _93 = _92->_hdrlen_rsvd_flags;
  _94 = lwip_htons (8);
  _95 = seg_169->tcphdr;
  _96 = _93 | _94;
  _95->_hdrlen_rsvd_flags = _96;
  goto <bb 99>; [100.00%]

  <bb 91> [local count: 51238]:
  # concat_p_105 = PHI <0B(23), 0B(32), concat_p_252(39), concat_p_252(46), concat_p_252(48), concat_p_252(51), concat_p_252(53)>
  # queue_112 = PHI <0B(23), 0B(32), queue_15(39), queue_18(46), queue_19(48), queue_173(51), queue_20(53)>
memerr:
  # DEBUG queue => queue_112
  # DEBUG concat_p => concat_p_105
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _97 = pcb_160(D)->flags;
  _98 = _97 | 128;
  pcb_160(D)->flags = _98;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _99 = lwip_stats.tcp.memerr;
  _100 = _99 + 1;
  lwip_stats.tcp.memerr = _100;
  # DEBUG BEGIN_STMT
  if (concat_p_105 != 0B)
    goto <bb 92>; [53.47%]
  else
    goto <bb 93>; [46.53%]

  <bb 92> [local count: 27397]:
  # DEBUG BEGIN_STMT
  pbuf_free (concat_p_105);

  <bb 93> [local count: 51238]:
  # DEBUG BEGIN_STMT
  if (queue_112 != 0B)
    goto <bb 94>; [53.47%]
  else
    goto <bb 95>; [46.53%]

  <bb 94> [local count: 27397]:
  # DEBUG BEGIN_STMT
  tcp_segs_free (queue_112);

  <bb 95> [local count: 51238]:
  # DEBUG BEGIN_STMT
  _101 = pcb_160(D)->snd_queuelen;
  if (_101 != 0)
    goto <bb 96>; [98.00%]
  else
    goto <bb 99>; [2.00%]

  <bb 96> [local count: 50213]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _102 = pcb_160(D)->unacked;
  if (_102 == 0B)
    goto <bb 97>; [95.45%]
  else
    goto <bb 99>; [4.55%]

  <bb 97> [local count: 47928]:
  _103 = pcb_160(D)->unsent;
  if (_103 == 0B)
    goto <bb 103>; [95.45%]
  else
    goto <bb 99>; [4.55%]

  <bb 103> [local count: 45747]:

  <bb 98> [local count: 457477875]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 116> [local count: 457477875]:
  goto <bb 98>; [100.00%]

  <bb 99> [local count: 176869]:
  # _124 = PHI <-16(2), -16(5), err_166(6), 0(88), -1(96), -1(95), -1(97), 0(87), 0(90), 0(89)>
  oversize ={v} {CLOBBER};
  return _124;

}



;; Function tcp_split_unsent_seg (tcp_split_unsent_seg, funcdef_no=6, decl_uid=7344, cgraph_uid=7, symbol_order=6)

Modification phase of node tcp_split_unsent_seg/6
tcp_split_unsent_seg (struct tcp_pcb * pcb, u16_t split)
{
  u16_t offset;
  u16_t remainder;
  u8_t remainder_flags;
  u8_t split_flags;
  u8_t optflags;
  u8_t optlen;
  struct pbuf * p;
  struct tcp_seg * useg;
  struct tcp_seg * seg;
  short unsigned int _1;
  short unsigned int _2;
  int _3;
  int _4;
  unsigned char _5;
  short unsigned int _6;
  short unsigned int _7;
  struct pbuf * _8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  void * _12;
  sizetype _13;
  void * _14;
  short unsigned int _15;
  struct tcp_hdr * _16;
  short unsigned int _17;
  short unsigned int _18;
  unsigned char _19;
  struct tcp_hdr * _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  struct pbuf * _25;
  short unsigned int _26;
  short unsigned int _27;
  struct pbuf * _28;
  short unsigned int _29;
  short unsigned int _30;
  short unsigned int _31;
  short unsigned int _32;
  struct tcp_hdr * _33;
  short unsigned int _34;
  short unsigned int _35;
  short unsigned int _36;
  struct tcp_hdr * _37;
  short unsigned int _38;
  struct pbuf * _39;
  short unsigned int _40;
  short unsigned int _41;
  struct pbuf * _42;
  short unsigned int _43;
  short unsigned int _44;
  struct tcp_seg * _45;
  struct tcp_seg * _46;
  short unsigned int _47;
  short unsigned int _48;
  err_t _54;
  unsigned char _61;
  unsigned char _62;
  short unsigned int _63;
  short unsigned int _84;
  short unsigned int _91;
  short unsigned int _94;

  <bb 2> [local count: 308170]:
  # DEBUG BEGIN_STMT
  # DEBUG seg => 0B
  # DEBUG useg => 0B
  # DEBUG BEGIN_STMT
  # DEBUG p => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_64(D) == 0B)
    goto <bb 27>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 27> [local count: 92451]:

  <bb 3> [local count: 924510431]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 31> [local count: 924510431]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 215719]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  useg_66 = pcb_64(D)->unsent;
  # DEBUG useg => useg_66
  # DEBUG BEGIN_STMT
  if (useg_66 == 0B)
    goto <bb 26>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 214748]:
  # DEBUG BEGIN_STMT
  if (split_67(D) == 0)
    goto <bb 28>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 28> [local count: 107374]:

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 32> [local count: 1073741824]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 107374]:
  # DEBUG BEGIN_STMT
  _1 = useg_66->len;
  if (_1 <= split_67(D))
    goto <bb 26>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 8> [local count: 70867]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pcb_64(D)->mss;
  if (_2 < split_67(D))
    goto <bb 29>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 29> [local count: 35434]:

  <bb 9> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 33> [local count: 354334802]:
  goto <bb 9>; [100.00%]

  <bb 10> [local count: 35433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_1 == 0)
    goto <bb 30>; [67.00%]
  else
    goto <bb 12>; [33.00%]

  <bb 30> [local count: 23740]:

  <bb 11> [local count: 237404317]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 34> [local count: 237404317]:
  goto <bb 11>; [100.00%]

  <bb 12> [local count: 11693]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  optflags_68 = useg_66->flags;
  # DEBUG optflags => optflags_68
  # DEBUG BEGIN_STMT
  _3 = (int) optflags_68;
  _4 = _3 << 2;
  _5 = (unsigned char) _4;
  optlen_69 = _5 & 4;
  # DEBUG optlen => optlen_69
  # DEBUG BEGIN_STMT
  remainder_70 = _1 - split_67(D);
  # DEBUG remainder => remainder_70
  # DEBUG BEGIN_STMT
  _6 = (short unsigned int) optlen_69;
  _7 = _6 + remainder_70;
  p_72 = pbuf_alloc (74, _7, 640);
  # DEBUG p => p_72
  # DEBUG BEGIN_STMT
  if (p_72 == 0B)
    goto <bb 13>; [30.95%]
  else
    goto <bb 14>; [69.05%]

  <bb 13> [local count: 3619]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 24>; [100.00%]

  <bb 14> [local count: 8074]:
  # DEBUG BEGIN_STMT
  _8 = useg_66->p;
  _9 = _8->tot_len;
  _10 = useg_66->len;
  _11 = _9 - _10;
  offset_73 = _11 + split_67(D);
  # DEBUG offset => offset_73
  # DEBUG BEGIN_STMT
  _12 = p_72->payload;
  _13 = (sizetype) optlen_69;
  _14 = _12 + _13;
  _15 = pbuf_copy_partial (_8, _14, remainder_70, offset_73);
  if (_15 != remainder_70)
    goto <bb 15>; [67.00%]
  else
    goto <bb 16>; [33.00%]

  <bb 15> [local count: 5410]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 24>; [100.00%]

  <bb 16> [local count: 2664]:
  # DEBUG BEGIN_STMT
  _16 = useg_66->tcphdr;
  _17 = _16->_hdrlen_rsvd_flags;
  _18 = lwip_htons (_17);
  _19 = (unsigned char) _18;
  split_flags_76 = _19 & 63;
  # DEBUG split_flags => split_flags_76
  # DEBUG BEGIN_STMT
  # DEBUG remainder_flags => 0
  # DEBUG BEGIN_STMT
  _61 = _19 & 8;
  if (_61 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 17> [local count: 1332]:
  # DEBUG BEGIN_STMT
  split_flags_77 = _19 & 55;
  # DEBUG split_flags => split_flags_77
  # DEBUG BEGIN_STMT
  # DEBUG remainder_flags => 8

  <bb 18> [local count: 2664]:
  # split_flags_50 = PHI <split_flags_76(16), split_flags_77(17)>
  # remainder_flags_52 = PHI <0(16), 8(17)>
  # DEBUG remainder_flags => remainder_flags_52
  # DEBUG split_flags => split_flags_50
  # DEBUG BEGIN_STMT
  _62 = split_flags_50 & 1;
  if (_62 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 19> [local count: 1332]:
  # DEBUG BEGIN_STMT
  split_flags_78 = split_flags_50 & 254;
  # DEBUG split_flags => split_flags_78
  # DEBUG BEGIN_STMT
  remainder_flags_79 = remainder_flags_52 | 1;
  # DEBUG remainder_flags => remainder_flags_79

  <bb 20> [local count: 2664]:
  # split_flags_51 = PHI <split_flags_50(18), split_flags_78(19)>
  # remainder_flags_53 = PHI <remainder_flags_52(18), remainder_flags_79(19)>
  # DEBUG remainder_flags => remainder_flags_53
  # DEBUG split_flags => split_flags_51
  # DEBUG BEGIN_STMT
  _20 = useg_66->tcphdr;
  _21 = _20->seqno;
  _22 = lwip_htonl (_21);
  _23 = (long unsigned int) split_67(D);
  _24 = _22 + _23;
  seg_82 = tcp_create_segment (pcb_64(D), p_72, remainder_flags_53, _24, optflags_68);
  # DEBUG seg => seg_82
  # DEBUG BEGIN_STMT
  if (seg_82 == 0B)
    goto <bb 21>; [30.95%]
  else
    goto <bb 22>; [69.05%]

  <bb 21> [local count: 825]:
  # DEBUG BEGIN_STMT
  # DEBUG p => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 24>; [100.00%]

  <bb 22> [local count: 1840]:
  # DEBUG BEGIN_STMT
  _25 = useg_66->p;
  _84 = pbuf_clen (_25);
  _26 = pcb_64(D)->snd_queuelen;
  _27 = _26 - _84;
  pcb_64(D)->snd_queuelen = _27;
  # DEBUG BEGIN_STMT
  _28 = useg_66->p;
  _29 = _28->tot_len;
  _63 = split_67(D) - _1;
  _30 = _29 + _63;
  pbuf_realloc (_28, _30);
  # DEBUG BEGIN_STMT
  _31 = useg_66->len;
  _32 = _31 + _63;
  useg_66->len = _32;
  # DEBUG BEGIN_STMT
  _33 = useg_66->tcphdr;
  _34 = _33->_hdrlen_rsvd_flags;
  _35 = (short unsigned int) split_flags_51;
  _36 = lwip_htons (_35);
  _37 = useg_66->tcphdr;
  _38 = _34 | _36;
  _37->_hdrlen_rsvd_flags = _38;
  # DEBUG BEGIN_STMT
  _39 = useg_66->p;
  _91 = pbuf_clen (_39);
  _40 = pcb_64(D)->snd_queuelen;
  _41 = _40 + _91;
  pcb_64(D)->snd_queuelen = _41;
  # DEBUG BEGIN_STMT
  _42 = seg_82->p;
  _94 = pbuf_clen (_42);
  _43 = pcb_64(D)->snd_queuelen;
  _44 = _43 + _94;
  pcb_64(D)->snd_queuelen = _44;
  # DEBUG BEGIN_STMT
  _45 = useg_66->next;
  seg_82->next = _45;
  # DEBUG BEGIN_STMT
  useg_66->next = seg_82;
  # DEBUG BEGIN_STMT
  _46 = seg_82->next;
  if (_46 == 0B)
    goto <bb 23>; [30.00%]
  else
    goto <bb 26>; [70.00%]

  <bb 23> [local count: 552]:
  # DEBUG BEGIN_STMT
  pcb_64(D)->unsent_oversize = 0;
  goto <bb 26>; [100.00%]

  <bb 24> [local count: 9853]:
  # p_49 = PHI <0B(13), p_72(15), 0B(21)>
memerr:
  # DEBUG p => p_49
  # DEBUG seg => 0B
  # DEBUG BEGIN_STMT
  _47 = lwip_stats.tcp.memerr;
  _48 = _47 + 1;
  lwip_stats.tcp.memerr = _48;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_49 != 0B)
    goto <bb 25>; [53.47%]
  else
    goto <bb 26>; [46.53%]

  <bb 25> [local count: 5269]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_49);

  <bb 26> [local count: 49171]:
  # _54 = PHI <-1(4), -1(25), 0(7), 0(23), -1(24), 0(22)>
  return _54;

}



;; Function tcp_enqueue_flags (tcp_enqueue_flags, funcdef_no=8, decl_uid=7326, cgraph_uid=9, symbol_order=8)

Modification phase of node tcp_enqueue_flags/8
tcp_enqueue_flags (struct tcp_pcb * pcb, u8_t flags)
{
  signed char _1;
  unsigned char _5;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optflags => 0
  # DEBUG BEGIN_STMT
  # DEBUG optlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = flags_6(D) & 3;
  if (_5 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_8(D) == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 8> [local count: 32212]:

  <bb 5> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 322122547]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 75162]:
  _1 = tcp_enqueue_flags.part.0 (pcb_8(D), flags_6(D));
  return _1;

}



;; Function tcp_send_fin (tcp_send_fin, funcdef_no=7, decl_uid=7323, cgraph_uid=8, symbol_order=7)

Modification phase of node tcp_send_fin/7
tcp_send_fin (struct tcp_pcb * pcb)
{
  struct tcp_seg * last_unsent;
  struct tcp_seg * _1;
  struct tcp_seg * _2;
  struct tcp_hdr * _3;
  short unsigned int _4;
  short unsigned int _5;
  unsigned char _6;
  struct tcp_hdr * _7;
  short unsigned int _8;
  short unsigned int _9;
  struct tcp_hdr * _10;
  short unsigned int _11;
  short unsigned int _12;
  short unsigned int _13;
  err_t _15;
  unsigned char _26;
  err_t _28;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_19(D) == 0B)
    goto <bb 10>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 10> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_19(D)->unsent;
  if (_1 != 0B)
    goto <bb 11>; [82.57%]
  else
    goto <bb 8>; [17.43%]

  <bb 11> [local count: 206870]:

  <bb 5> [local count: 1880639]:
  # last_unsent_14 = PHI <_1(11), _2(13)>
  # DEBUG last_unsent => last_unsent_14
  # DEBUG BEGIN_STMT
  _2 = last_unsent_14->next;
  if (_2 != 0B)
    goto <bb 13>; [89.00%]
  else
    goto <bb 6>; [11.00%]

  <bb 13> [local count: 1673769]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 206870]:
  # last_unsent_21 = PHI <last_unsent_14(5)>
  # DEBUG BEGIN_STMT
  _3 = last_unsent_21->tcphdr;
  _4 = _3->_hdrlen_rsvd_flags;
  _5 = lwip_htons (_4);
  _6 = (unsigned char) _5;
  _26 = _6 & 7;
  if (_26 == 0)
    goto <bb 7>; [20.24%]
  else
    goto <bb 8>; [79.76%]

  <bb 7> [local count: 41871]:
  # DEBUG BEGIN_STMT
  _7 = last_unsent_21->tcphdr;
  _8 = _7->_hdrlen_rsvd_flags;
  _9 = lwip_htons (1);
  _10 = last_unsent_21->tcphdr;
  _11 = _8 | _9;
  _10->_hdrlen_rsvd_flags = _11;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = pcb_19(D)->flags;
  _13 = _12 | 32;
  pcb_19(D)->flags = _13;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 208669]:
  # DEBUG BEGIN_STMT
  _28 = tcp_enqueue_flags (pcb_19(D), 1);

  <bb 9> [local count: 250539]:
  # _15 = PHI <0(7), _28(8)>
  return _15;

}



;; Function tcp_rexmit_rto_prepare (tcp_rexmit_rto_prepare, funcdef_no=12, decl_uid=7282, cgraph_uid=13, symbol_order=12)

Modification phase of node tcp_rexmit_rto_prepare/12
tcp_rexmit_rto_prepare (struct tcp_pcb * pcb)
{
  struct tcp_seg * seg;
  struct tcp_seg * _1;
  int _2;
  struct tcp_seg * _3;
  int _4;
  struct tcp_seg * _5;
  struct tcp_seg * _6;
  short unsigned int _7;
  short unsigned int _8;
  struct tcp_hdr * _9;
  long unsigned int _10;
  long unsigned int _11;
  short unsigned int _12;
  unsigned int _13;
  struct tcp_hdr * _14;
  short unsigned int _15;
  short unsigned int _16;
  unsigned char _17;
  unsigned int _18;
  long unsigned int _19;
  err_t _21;
  unsigned int iftmp.22_22;
  unsigned char _36;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_26(D) == 0B)
    goto <bb 13>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 13> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_26(D)->unacked;
  if (_1 == 0B)
    goto <bb 12>; [0.45%]
  else
    goto <bb 14>; [99.55%]

  <bb 14> [local count: 249412]:
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 2203265]:
  # DEBUG BEGIN_STMT
  _2 = tcp_output_segment_busy (seg_20);
  if (_2 != 0)
    goto <bb 12>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 2082085]:
  # DEBUG BEGIN_STMT
  seg_40 = seg_20->next;
  # DEBUG seg => seg_40

  <bb 7> [local count: 2331497]:
  # seg_20 = PHI <seg_40(6), _1(14)>
  # DEBUG seg => seg_20
  # DEBUG BEGIN_STMT
  _3 = seg_20->next;
  if (_3 != 0B)
    goto <bb 5>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 128232]:
  # seg_28 = PHI <seg_20(7)>
  # DEBUG BEGIN_STMT
  _4 = tcp_output_segment_busy (seg_28);
  if (_4 != 0)
    goto <bb 12>; [2.09%]
  else
    goto <bb 9>; [97.91%]

  <bb 9> [local count: 125552]:
  # DEBUG BEGIN_STMT
  _5 = pcb_26(D)->unsent;
  seg_28->next = _5;
  # DEBUG BEGIN_STMT
  _6 = pcb_26(D)->unacked;
  pcb_26(D)->unsent = _6;
  # DEBUG BEGIN_STMT
  pcb_26(D)->unacked = 0B;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = pcb_26(D)->flags;
  _8 = _7 | 2048;
  pcb_26(D)->flags = _8;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = seg_28->tcphdr;
  _10 = _9->seqno;
  _11 = lwip_htonl (_10);
  _12 = seg_28->len;
  _13 = (unsigned int) _12;
  _14 = seg_28->tcphdr;
  _15 = _14->_hdrlen_rsvd_flags;
  _16 = lwip_htons (_15);
  _17 = (unsigned char) _16;
  _36 = _17 & 3;
  if (_36 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 10> [local count: 62776]:

  <bb 11> [local count: 125552]:
  # iftmp.22_22 = PHI <1(9), 0(10)>
  _18 = _13 + iftmp.22_22;
  _19 = _11 + _18;
  pcb_26(D)->rto_end = _19;
  # DEBUG BEGIN_STMT
  pcb_26(D)->rttest = 0;
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 250539]:
  # _21 = PHI <-6(4), -6(5), -6(8), 0(11)>
  return _21;

}



;; Function tcp_rexmit (tcp_rexmit, funcdef_no=15, decl_uid=7280, cgraph_uid=16, symbol_order=15)

Modification phase of node tcp_rexmit/15
tcp_rexmit (struct tcp_pcb * pcb)
{
  struct tcp_seg * * cur_seg;
  struct tcp_seg * _1;
  int _2;
  struct tcp_seg * _3;
  struct tcp_seg * _4;
  struct tcp_seg * _5;
  struct tcp_hdr * _6;
  long unsigned int _7;
  long unsigned int _8;
  struct tcp_hdr * _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long int _13;
  struct tcp_seg * _14;
  struct tcp_seg * _15;
  unsigned char _16;
  unsigned char _17;
  long unsigned int _18;
  long unsigned int _19;
  err_t _21;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_28(D) == 0B)
    goto <bb 16>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 16> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_28(D)->unacked;
  if (_1 == 0B)
    goto <bb 15>; [0.91%]
  else
    goto <bb 5>; [99.09%]

  <bb 5> [local count: 248259]:
  # DEBUG BEGIN_STMT
  # DEBUG seg => _1
  # DEBUG BEGIN_STMT
  _2 = tcp_output_segment_busy (_1);
  if (_2 != 0)
    goto <bb 15>; [1.04%]
  else
    goto <bb 6>; [98.96%]

  <bb 6> [local count: 245678]:
  # DEBUG BEGIN_STMT
  _3 = _1->next;
  pcb_28(D)->unacked = _3;
  # DEBUG BEGIN_STMT
  cur_seg_33 = &pcb_28(D)->unsent;
  # DEBUG cur_seg => cur_seg_33
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 2050911]:
  # DEBUG BEGIN_STMT
  _4 = *cur_seg_20;
  cur_seg_36 = &_4->next;
  # DEBUG cur_seg => cur_seg_36

  <bb 8> [local count: 2296588]:
  # cur_seg_20 = PHI <cur_seg_33(6), cur_seg_36(7)>
  # DEBUG cur_seg => cur_seg_20
  # DEBUG BEGIN_STMT
  _5 = *cur_seg_20;
  if (_5 != 0B)
    goto <bb 9>; [94.50%]
  else
    goto <bb 10>; [5.50%]

  <bb 9> [local count: 2170276]:
  _6 = _5->tcphdr;
  _7 = _6->seqno;
  _8 = lwip_htonl (_7);
  _9 = _1->tcphdr;
  _10 = _9->seqno;
  _11 = lwip_htonl (_10);
  _12 = _8 - _11;
  _13 = (long int) _12;
  if (_13 < 0)
    goto <bb 7>; [94.50%]
  else
    goto <bb 10>; [5.50%]

  <bb 10> [local count: 245678]:
  # cur_seg_30 = PHI <cur_seg_20(8), cur_seg_20(9)>
  # DEBUG BEGIN_STMT
  _14 = *cur_seg_30;
  _1->next = _14;
  # DEBUG BEGIN_STMT
  *cur_seg_30 = _1;
  # DEBUG BEGIN_STMT
  _15 = _1->next;
  if (_15 == 0B)
    goto <bb 11>; [30.00%]
  else
    goto <bb 12>; [70.00%]

  <bb 11> [local count: 73703]:
  # DEBUG BEGIN_STMT
  pcb_28(D)->unsent_oversize = 0;

  <bb 12> [local count: 245678]:
  # DEBUG BEGIN_STMT
  _16 = pcb_28(D)->nrtx;
  if (_16 != 255)
    goto <bb 13>; [66.00%]
  else
    goto <bb 14>; [34.00%]

  <bb 13> [local count: 162147]:
  # DEBUG BEGIN_STMT
  _17 = _16 + 1;
  pcb_28(D)->nrtx = _17;

  <bb 14> [local count: 245678]:
  # DEBUG BEGIN_STMT
  pcb_28(D)->rttest = 0;
  # DEBUG BEGIN_STMT
  _18 = lwip_stats.mib2.tcpretranssegs;
  _19 = _18 + 1;
  lwip_stats.mib2.tcpretranssegs = _19;
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 250539]:
  # _21 = PHI <-6(4), -6(5), 0(14)>
  return _21;

}



;; Function tcp_rexmit_fast (tcp_rexmit_fast, funcdef_no=16, decl_uid=7288, cgraph_uid=17, symbol_order=16)

Modification phase of node tcp_rexmit_fast/16
tcp_rexmit_fast (struct tcp_pcb * pcb)
{
  struct tcp_seg * _1;
  short unsigned int _2;
  signed char _3;
  short unsigned int _4;
  short unsigned int _5;
  short unsigned int _6;
  int _7;
  int _8;
  short unsigned int _9;
  unsigned int _10;
  short unsigned int _11;
  unsigned int _12;
  unsigned int _13;
  short unsigned int _14;
  short unsigned int _15;
  short unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _32;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_23(D) == 0B)
    goto <bb 11>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 11> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_23(D)->unacked;
  if (_1 != 0B)
    goto <bb 5>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 5> [local count: 175378]:
  _2 = pcb_23(D)->flags;
  _32 = _2 & 4;
  if (_32 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 6> [local count: 57875]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = tcp_rexmit (pcb_23(D));
  if (_3 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 7> [local count: 28937]:
  # DEBUG BEGIN_STMT
  _4 = pcb_23(D)->snd_wnd;
  _5 = pcb_23(D)->cwnd;
  _6 = MIN_EXPR <_4, _5>;
  _7 = (int) _6;
  _8 = _7 >> 1;
  _9 = (short unsigned int) _8;
  pcb_23(D)->ssthresh = _9;
  # DEBUG BEGIN_STMT
  _10 = (unsigned int) _8;
  _11 = pcb_23(D)->mss;
  _12 = (unsigned int) _11;
  _13 = _12 * 2;
  if (_10 < _13)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 14469]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = _11 * 2;
  pcb_23(D)->ssthresh = _14;

  <bb 9> [local count: 28937]:
  # DEBUG BEGIN_STMT
  _15 = pcb_23(D)->ssthresh;
  _16 = _11 * 3;
  _17 = _15 + _16;
  pcb_23(D)->cwnd = _17;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _18 = pcb_23(D)->flags;
  _19 = _18 | 4;
  pcb_23(D)->flags = _19;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_23(D)->rtime = 0;

  <bb 10> [local count: 250539]:
  return;

}



;; Function tcp_rst (tcp_rst, funcdef_no=21, decl_uid=7337, cgraph_uid=22, symbol_order=21)

Modification phase of node tcp_rst/21
tcp_rst (const struct tcp_pcb * pcb, u32_t seqno, u32_t ackno, const struct ip_addr_t * local_ip, const struct ip_addr_t * remote_ip, u16_t local_port, u16_t remote_port)
{
  struct pbuf * p;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 329661]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (local_ip_7(D) == 0B)
    goto <bb 9>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 9> [local count: 98898]:

  <bb 3> [local count: 988985746]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 988985746]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (remote_ip_9(D) == 0B)
    goto <bb 10>; [46.53%]
  else
    goto <bb 6>; [53.47%]

  <bb 10> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG wnd => 33820
  # DEBUG BEGIN_STMT
  _1 = lwip_htonl (seqno_10(D));
  p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 33820);
  # DEBUG p => p_16
  # DEBUG BEGIN_STMT
  if (p_16 == 0B)
    goto <bb 8>; [30.95%]
  else
    goto <bb 7>; [69.05%]

  <bb 7> [local count: 85200]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => pcb_17(D)
  # DEBUG D#2 => 0
  tcp_output_fill_options.isra.0 (p_16, 0);
  # DEBUG BEGIN_STMT
  _2 = lwip_stats.mib2.tcpoutrsts;
  _3 = _2 + 1;
  lwip_stats.mib2.tcpoutrsts = _3;
  # DEBUG BEGIN_STMT
  tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));

  <bb 8> [local count: 123389]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function tcp_send_empty_ack (tcp_send_empty_ack, funcdef_no=22, decl_uid=7278, cgraph_uid=23, symbol_order=22)

Modification phase of node tcp_send_empty_ack/22
tcp_send_empty_ack (struct tcp_pcb * pcb)
{
  signed char _2;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optflags => 0
  # DEBUG BEGIN_STMT
  # DEBUG num_sacks => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) == 0B)
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
  _2 = tcp_send_empty_ack.part.0 (pcb_4(D));
  return _2;

}



;; Function tcp_output (tcp_output, funcdef_no=9, decl_uid=7242, cgraph_uid=10, symbol_order=9)

Modification phase of node tcp_output/9
tcp_output (struct tcp_pcb * pcb)
{
  tcp_state _1;
  struct tcp_pcb * tcp_input_pcb.8_2;
  signed char _3;
  err_t _6;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_9(D) == 0B)
    goto <bb 9>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 9> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_9(D)->state;
  if (_1 == 1)
    goto <bb 10>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 10> [local count: 85183]:

  <bb 5> [local count: 851835183]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 851835183]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 165356]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_input_pcb.8_2 = tcp_input_pcb;
  if (tcp_input_pcb.8_2 == pcb_9(D))
    goto <bb 8>; [18.09%]
  else
    goto <bb 7>; [81.91%]

  <bb 7> [local count: 135443]:
  _3 = tcp_output.part.0 (pcb_9(D));

  <bb 8> [local count: 156547]:
  # _6 = PHI <0(6), _3(7)>
  return _6;

}



;; Function tcp_rexmit_rto_commit (tcp_rexmit_rto_commit, funcdef_no=13, decl_uid=7284, cgraph_uid=14, symbol_order=13)

Modification phase of node tcp_rexmit_rto_commit/13
tcp_rexmit_rto_commit (struct tcp_pcb * pcb)
{
  unsigned char _1;
  unsigned char _2;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_5(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_5(D)->nrtx;
  if (_1 != 255)
    goto <bb 5>; [66.00%]
  else
    goto <bb 6>; [34.00%]

  <bb 5> [local count: 165356]:
  # DEBUG BEGIN_STMT
  _2 = _1 + 1;
  pcb_5(D)->nrtx = _2;

  <bb 6> [local count: 250539]:
  # DEBUG BEGIN_STMT
  tcp_output (pcb_5(D));
  return;

}



;; Function tcp_rexmit_rto (tcp_rexmit_rto, funcdef_no=14, decl_uid=7286, cgraph_uid=15, symbol_order=14)

Modification phase of node tcp_rexmit_rto/14
tcp_rexmit_rto (struct tcp_pcb * pcb)
{
  signed char _1;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) == 0B)
    goto <bb 7>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = tcp_rexmit_rto_prepare (pcb_4(D));
  if (_1 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 40718]:
  # DEBUG BEGIN_STMT
  tcp_rexmit_rto_commit (pcb_4(D));

  <bb 6> [local count: 123389]:
  return;

}



;; Function tcp_keepalive (tcp_keepalive, funcdef_no=23, decl_uid=7341, cgraph_uid=24, symbol_order=23)

Modification phase of node tcp_keepalive/23
tcp_keepalive (struct tcp_pcb * pcb)
{
  struct pbuf * p;
  err_t err;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  struct ip_addr_t * _4;
  struct ip_addr_t * _5;
  err_t _6;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_9(D) == 0B)
    goto <bb 7>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_9(D)->snd_nxt;
  _2 = _1 + 4294967295;
  _3 = lwip_htonl (_2);
  p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  # DEBUG p => p_13
  # DEBUG BEGIN_STMT
  if (p_13 == 0B)
    goto <bb 6>; [0.91%]
  else
    goto <bb 5>; [99.09%]

  <bb 5> [local count: 122266]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => pcb_9(D)
  # DEBUG D#2 => 0
  tcp_output_fill_options.isra.0 (p_13, 0);
  # DEBUG BEGIN_STMT
  _4 = &pcb_9(D)->local_ip;
  _5 = &pcb_9(D)->remote_ip;
  err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  # DEBUG err => err_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 123389]:
  # _6 = PHI <-1(4), err_16(5)>
  return _6;

}



;; Function tcp_zero_window_probe (tcp_zero_window_probe, funcdef_no=24, decl_uid=7346, cgraph_uid=25, symbol_order=24)

Modification phase of node tcp_zero_window_probe/24
tcp_zero_window_probe (struct tcp_pcb * pcb)
{
  char * d;
  u32_t snd_nxt;
  u8_t is_fin;
  u16_t len;
  struct tcp_seg * seg;
  struct tcp_hdr * tcphdr;
  struct pbuf * p;
  err_t err;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  struct tcp_hdr * _4;
  short unsigned int _5;
  short unsigned int _6;
  unsigned char _7;
  short unsigned int _8;
  struct tcp_hdr * _9;
  long unsigned int _10;
  short unsigned int _11;
  signed short _12;
  signed short _13;
  short unsigned int _14;
  signed short _15;
  signed short _16;
  short unsigned int _17;
  struct pbuf * _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int _21;
  struct tcp_hdr * _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long int _27;
  struct ip_addr_t * _28;
  struct ip_addr_t * _29;
  err_t _30;
  int iftmp.24_31;
  unsigned char _37;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_38(D) == 0B)
    goto <bb 18>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 18> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 19> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  seg_40 = pcb_38(D)->unsent;
  # DEBUG seg => seg_40
  # DEBUG BEGIN_STMT
  if (seg_40 == 0B)
    goto <bb 17>; [18.09%]
  else
    goto <bb 5>; [81.91%]

  <bb 5> [local count: 205217]:
  # DEBUG BEGIN_STMT
  _1 = pcb_38(D)->persist_probe;
  if (_1 != 255)
    goto <bb 6>; [66.00%]
  else
    goto <bb 7>; [34.00%]

  <bb 6> [local count: 135443]:
  # DEBUG BEGIN_STMT
  _3 = _1 + 1;
  pcb_38(D)->persist_probe = _3;

  <bb 7> [local count: 205217]:
  # DEBUG BEGIN_STMT
  _4 = seg_40->tcphdr;
  _5 = _4->_hdrlen_rsvd_flags;
  _6 = lwip_htons (_5);
  _7 = (unsigned char) _6;
  _37 = _7 & 1;
  if (_37 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 102608]:
  _8 = seg_40->len;
  if (_8 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 153913]:

  <bb 10> [local count: 205217]:
  # iftmp.24_31 = PHI <1(8), 0(9)>
  is_fin_43 = (u8_t) iftmp.24_31;
  # DEBUG is_fin => is_fin_43
  # DEBUG BEGIN_STMT
  _2 = is_fin_43 ^ 1;
  len_44 = (u16_t) _2;
  # DEBUG len => len_44
  # DEBUG BEGIN_STMT
  _9 = seg_40->tcphdr;
  _10 = _9->seqno;
  p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  # DEBUG p => p_46
  # DEBUG BEGIN_STMT
  if (p_46 == 0B)
    goto <bb 17>; [0.45%]
  else
    goto <bb 11>; [99.55%]

  <bb 11> [local count: 204293]:
  # DEBUG BEGIN_STMT
  tcphdr_47 = p_46->payload;
  # DEBUG tcphdr => tcphdr_47
  # DEBUG BEGIN_STMT
  if (is_fin_43 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 102147]:
  # DEBUG BEGIN_STMT
  _11 = tcphdr_47->_hdrlen_rsvd_flags;
  _12 = (signed short) _11;
  _13 = _12 & -16129;
  _14 = lwip_htons (17);
  _15 = (signed short) _14;
  _16 = _13 | _15;
  _17 = (short unsigned int) _16;
  tcphdr_47->_hdrlen_rsvd_flags = _17;
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 102147]:
  # DEBUG BEGIN_STMT
  d_48 = tcphdr_47 + 20;
  # DEBUG d => d_48
  # DEBUG BEGIN_STMT
  _18 = seg_40->p;
  _19 = _18->tot_len;
  _20 = seg_40->len;
  _21 = _19 - _20;
  pbuf_copy_partial (_18, d_48, 1, _21);

  <bb 14> [local count: 204293]:
  # DEBUG BEGIN_STMT
  _22 = seg_40->tcphdr;
  _23 = _22->seqno;
  _24 = lwip_htonl (_23);
  snd_nxt_53 = _24 + 1;
  # DEBUG snd_nxt => snd_nxt_53
  # DEBUG BEGIN_STMT
  _25 = pcb_38(D)->snd_nxt;
  _26 = _25 - snd_nxt_53;
  _27 = (long int) _26;
  if (_27 < 0)
    goto <bb 15>; [41.00%]
  else
    goto <bb 16>; [59.00%]

  <bb 15> [local count: 83760]:
  # DEBUG BEGIN_STMT
  pcb_38(D)->snd_nxt = snd_nxt_53;

  <bb 16> [local count: 204293]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => pcb_38(D)
  # DEBUG D#2 => 0
  tcp_output_fill_options.isra.0 (p_46, 0);
  # DEBUG BEGIN_STMT
  _28 = &pcb_38(D)->local_ip;
  _29 = &pcb_38(D)->remote_ip;
  err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  # DEBUG err => err_57
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 250539]:
  # _30 = PHI <0(4), -1(10), err_57(16)>
  return _30;

}


