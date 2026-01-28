
IPA constant propagation start:
Determining dynamic type for call: parsed_3 = http_parse_request.isra.0 (p_1(D), arg_2(D));
  Starting walk at: parsed_3 = http_parse_request.isra.0 (p_1(D), arg_2(D));
  instance pointer: p_1(D)  Outer instance pointer: p_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: parsed_3 = http_parse_request.isra.0 (p_1(D), arg_2(D));
  Starting walk at: parsed_3 = http_parse_request.isra.0 (p_1(D), arg_2(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_close_conn (pcb_5(D), arg_2(D));
  Starting walk at: http_close_conn (pcb_5(D), arg_2(D));
  instance pointer: pcb_5(D)  Outer instance pointer: pcb_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_1(D));
  Function call may change dynamic type:parsed_3 = http_parse_request.isra.0 (p_1(D), arg_2(D));
  Function call may change dynamic type:pbuf_free (_4);
Determining dynamic type for call: http_close_conn (pcb_5(D), arg_2(D));
  Starting walk at: http_close_conn (pcb_5(D), arg_2(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_1(D));
  Function call may change dynamic type:parsed_3 = http_parse_request.isra.0 (p_1(D), arg_2(D));
  Function call may change dynamic type:pbuf_free (_4);
Determining dynamic type for call: http_send (pcb_5(D), arg_2(D));
  Starting walk at: http_send (pcb_5(D), arg_2(D));
  instance pointer: pcb_5(D)  Outer instance pointer: pcb_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_1(D));
  Function call may change dynamic type:parsed_3 = http_parse_request.isra.0 (p_1(D), arg_2(D));
  Function call may change dynamic type:pbuf_free (_4);
Determining dynamic type for call: http_send (pcb_5(D), arg_2(D));
  Starting walk at: http_send (pcb_5(D), arg_2(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_1(D));
  Function call may change dynamic type:parsed_3 = http_parse_request.isra.0 (p_1(D), arg_2(D));
  Function call may change dynamic type:pbuf_free (_4);
Determining dynamic type for call: _32 = http_find_file (hs_2(D), _18, is_09_31);
  Starting walk at: _32 = http_find_file (hs_2(D), _18, is_09_31);
  instance pointer: hs_2(D)  Outer instance pointer: hs_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_27 = lwip_strnstr (data_14, "\r\n\r\n", _13);
  Function call may change dynamic type:sp2_23 = lwip_strnstr (_18, " ", _22);
  Function call may change dynamic type:crlf_15 = lwip_strnstr (data_14, "\r\n", _13);
  Function call may change dynamic type:pbuf_copy_partial (_6, &httpd_req_buf, data_len_9, 0);
  Function call may change dynamic type:pbuf_ref (inp_1(D));
  Function call may change dynamic type:pbuf_cat (_5, inp_1(D));
  Function call may change dynamic type:sp2_24 = lwip_strnstr (_18, "\r\n", _22);
Determining dynamic type for call: _32 = http_find_file (hs_2(D), _18, is_09_31);
  Starting walk at: _32 = http_find_file (hs_2(D), _18, is_09_31);
  instance pointer: _18  Outer instance pointer: data_14 offset: 32 (bits) vtbl reference: 
  Function call may change dynamic type:_27 = lwip_strnstr (data_14, "\r\n\r\n", _13);
  Function call may change dynamic type:sp2_23 = lwip_strnstr (_18, " ", _22);
  Function call may change dynamic type:crlf_15 = lwip_strnstr (data_14, "\r\n", _13);
  Function call may change dynamic type:pbuf_copy_partial (_6, &httpd_req_buf, data_len_9, 0);
  Function call may change dynamic type:pbuf_ref (inp_1(D));
  Function call may change dynamic type:pbuf_cat (_5, inp_1(D));
  Function call may change dynamic type:sp2_24 = lwip_strnstr (_18, "\r\n", _22);
Determining dynamic type for call: _3 = http_send (pcb_1(D), arg_2(D));
  Starting walk at: _3 = http_send (pcb_1(D), arg_2(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = http_send (pcb_1(D), arg_2(D));
  Starting walk at: _3 = http_send (pcb_1(D), arg_2(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: data_to_send_3 = http_send_data_nonssi (pcb_1(D), hs_2(D));
  Starting walk at: data_to_send_3 = http_send_data_nonssi (pcb_1(D), hs_2(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: data_to_send_3 = http_send_data_nonssi (pcb_1(D), hs_2(D));
  Starting walk at: data_to_send_3 = http_send_data_nonssi (pcb_1(D), hs_2(D));
  instance pointer: hs_2(D)  Outer instance pointer: hs_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_close_conn (pcb_1(D), hs_2(D));
  Starting walk at: http_close_conn (pcb_1(D), hs_2(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = fs_bytes_left (_5);
  Function call may change dynamic type:data_to_send_3 = http_send_data_nonssi (pcb_1(D), hs_2(D));
Determining dynamic type for call: http_close_conn (pcb_1(D), hs_2(D));
  Starting walk at: http_close_conn (pcb_1(D), hs_2(D));
  instance pointer: hs_2(D)  Outer instance pointer: hs_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = fs_bytes_left (_5);
  Function call may change dynamic type:data_to_send_3 = http_send_data_nonssi (pcb_1(D), hs_2(D));
Determining dynamic type for call: http_state_eof (hs_1(D));
  Starting walk at: http_state_eof (hs_1(D));
  instance pointer: hs_1(D)  Outer instance pointer: hs_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: httpd_init_pcb (pcb_4, 80);
  Starting walk at: httpd_init_pcb (pcb_4, 80);
  instance pointer: pcb_4  Outer instance pointer: pcb_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pcb_4 = tcp_new_ip_type (46);
Determining dynamic type for call: http_recv.part.0 (arg_7(D), pcb_11(D), p_9(D));
  Starting walk at: http_recv.part.0 (arg_7(D), pcb_11(D), p_9(D));
  instance pointer: arg_7(D)  Outer instance pointer: arg_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_recved (pcb_11(D), _2);
Determining dynamic type for call: http_recv.part.0 (arg_7(D), pcb_11(D), p_9(D));
  Starting walk at: http_recv.part.0 (arg_7(D), pcb_11(D), p_9(D));
  instance pointer: pcb_11(D)  Outer instance pointer: pcb_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_recved (pcb_11(D), _2);
Determining dynamic type for call: http_recv.part.0 (arg_7(D), pcb_11(D), p_9(D));
  Starting walk at: http_recv.part.0 (arg_7(D), pcb_11(D), p_9(D));
  instance pointer: p_9(D)  Outer instance pointer: p_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_recved (pcb_11(D), _2);
Determining dynamic type for call: http_close_conn (pcb_11(D), arg_7(D));
  Starting walk at: http_close_conn (pcb_11(D), arg_7(D));
  instance pointer: pcb_11(D)  Outer instance pointer: pcb_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_9(D));
  Function call may change dynamic type:tcp_recved (pcb_11(D), _1);
Determining dynamic type for call: http_close_conn (pcb_11(D), arg_7(D));
  Starting walk at: http_close_conn (pcb_11(D), arg_7(D));
  instance pointer: arg_7(D)  Outer instance pointer: arg_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_9(D));
  Function call may change dynamic type:tcp_recved (pcb_11(D), _1);
Determining dynamic type for call: http_poll.part.0 (arg_5(D), pcb_8(D));
  Starting walk at: http_poll.part.0 (arg_5(D), pcb_8(D));
  instance pointer: arg_5(D)  Outer instance pointer: arg_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_poll.part.0 (arg_5(D), pcb_8(D));
  Starting walk at: http_poll.part.0 (arg_5(D), pcb_8(D));
  instance pointer: pcb_8(D)  Outer instance pointer: pcb_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_close_conn (pcb_8(D), arg_5(D));
  Starting walk at: http_close_conn (pcb_8(D), arg_5(D));
  instance pointer: pcb_8(D)  Outer instance pointer: pcb_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_close_conn (pcb_8(D), arg_5(D));
  Starting walk at: http_close_conn (pcb_8(D), arg_5(D));
  instance pointer: arg_5(D)  Outer instance pointer: arg_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_close_conn (pcb_8(D), 0B);
  Starting walk at: http_close_conn (pcb_8(D), 0B);
  instance pointer: pcb_8(D)  Outer instance pointer: pcb_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_close_conn (pcb_8(D), 0B);
  Starting walk at: http_close_conn (pcb_8(D), 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_send (pcb_5(D), arg_2(D));
  Starting walk at: http_send (pcb_5(D), arg_2(D));
  instance pointer: pcb_5(D)  Outer instance pointer: pcb_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_send (pcb_5(D), arg_2(D));
  Starting walk at: http_send (pcb_5(D), arg_2(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_state_free (arg_2(D));
  Starting walk at: http_state_free (arg_2(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: file_47 = http_get_404_file (hs_37(D), &uri);
  Starting walk at: file_47 = http_get_404_file (hs_37(D), &uri);
  instance pointer: hs_37(D)  Outer instance pointer: hs_37(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_45 = fs_open (_11, uri.8_12);
  Function call may change dynamic type:memcpy (&http_uri_buf, uri.3_1, copy_len_28);
  Function call may change dynamic type:err_39 = fs_open (_9, file_name_17);
  Function call may change dynamic type:memcpy (_7, _6, name_copy_len_34);
Determining dynamic type for call: file_47 = http_get_404_file (hs_37(D), &uri);
  Starting walk at: file_47 = http_get_404_file (hs_37(D), &uri);
  instance pointer: &uri  Outer instance pointer: uri offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_45 = fs_open (_11, uri.8_12);
  Function call may change dynamic type:err_39 = fs_open (_9, file_name_17);
Determining dynamic type for call: file_49 = http_get_404_file (hs_37(D), &uri);
  Starting walk at: file_49 = http_get_404_file (hs_37(D), &uri);
  instance pointer: hs_37(D)  Outer instance pointer: hs_37(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memcpy (&http_uri_buf, uri.3_1, copy_len_28);
  Function call may change dynamic type:err_39 = fs_open (_9, file_name_17);
  Function call may change dynamic type:memcpy (_7, _6, name_copy_len_34);
  Function call may change dynamic type:err_45 = fs_open (_11, uri.8_12);
  Function call may change dynamic type:file_47 = http_get_404_file (hs_37(D), &uri);
Determining dynamic type for call: file_49 = http_get_404_file (hs_37(D), &uri);
  Starting walk at: file_49 = http_get_404_file (hs_37(D), &uri);
  instance pointer: &uri  Outer instance pointer: uri offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_39 = fs_open (_9, file_name_17);
  Function call may change dynamic type:err_45 = fs_open (_11, uri.8_12);
  Function call may change dynamic type:file_47 = http_get_404_file (hs_37(D), &uri);
Determining dynamic type for call: _52 = http_init_file.isra.0 (hs_37(D), file_16, is_09_50(D));
  Starting walk at: _52 = http_init_file.isra.0 (hs_37(D), file_16, is_09_50(D));
  instance pointer: hs_37(D)  Outer instance pointer: hs_37(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memcpy (&http_uri_buf, uri.3_1, copy_len_28);
  Function call may change dynamic type:err_39 = fs_open (_9, file_name_17);
  Function call may change dynamic type:memcpy (_7, _6, name_copy_len_34);
  Function call may change dynamic type:err_45 = fs_open (_11, uri.8_12);
  Function call may change dynamic type:file_47 = http_get_404_file (hs_37(D), &uri);
  Function call may change dynamic type:file_49 = http_get_404_file (hs_37(D), &uri);
Determining dynamic type for call: _52 = http_init_file.isra.0 (hs_37(D), file_16, is_09_50(D));
  Starting walk at: _52 = http_init_file.isra.0 (hs_37(D), file_16, is_09_50(D));
  instance pointer: file_16  Outer instance pointer: file_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memcpy (&http_uri_buf, uri.3_1, copy_len_28);
  Function call may change dynamic type:err_39 = fs_open (_9, file_name_17);
  Function call may change dynamic type:memcpy (_7, _6, name_copy_len_34);
  Function call may change dynamic type:err_45 = fs_open (_11, uri.8_12);
  Function call may change dynamic type:file_47 = http_get_404_file (hs_37(D), &uri);
  Function call may change dynamic type:file_49 = http_get_404_file (hs_37(D), &uri);
Determining dynamic type for call: _2 = http_check_eof (pcb_9(D), hs_7(D));
  Starting walk at: _2 = http_check_eof (pcb_9(D), hs_7(D));
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = http_check_eof (pcb_9(D), hs_7(D));
  Starting walk at: _2 = http_check_eof (pcb_9(D), hs_7(D));
  instance pointer: hs_7(D)  Outer instance pointer: hs_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = http_send.part.0 (pcb_9(D), hs_7(D));
  Starting walk at: _5 = http_send.part.0 (pcb_9(D), hs_7(D));
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = http_check_eof (pcb_9(D), hs_7(D));
Determining dynamic type for call: _5 = http_send.part.0 (pcb_9(D), hs_7(D));
  Starting walk at: _5 = http_send.part.0 (pcb_9(D), hs_7(D));
  instance pointer: hs_7(D)  Outer instance pointer: hs_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = http_check_eof (pcb_9(D), hs_7(D));
Determining dynamic type for call: err_18 = http_write (pcb_16(D), _3, &len, 0);
  Starting walk at: err_18 = http_write (pcb_16(D), _3, &len, 0);
  instance pointer: pcb_16(D)  Outer instance pointer: pcb_16(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_18 = http_write (pcb_16(D), _3, &len, 0);
  Starting walk at: err_18 = http_write (pcb_16(D), _3, &len, 0);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_18 = http_write (pcb_16(D), _3, &len, 0);
  Starting walk at: err_18 = http_write (pcb_16(D), _3, &len, 0);
  instance pointer: &len  Outer instance pointer: len offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_close_conn (pcb_9(D), hs_5(D));
  Starting walk at: http_close_conn (pcb_9(D), hs_5(D));
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bytes_left_7 = fs_bytes_left (_1);
Determining dynamic type for call: http_close_conn (pcb_9(D), hs_5(D));
  Starting walk at: http_close_conn (pcb_9(D), hs_5(D));
  instance pointer: hs_5(D)  Outer instance pointer: hs_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bytes_left_7 = fs_bytes_left (_1);
Determining dynamic type for call: http_close_conn (pcb_9(D), hs_5(D));
  Starting walk at: http_close_conn (pcb_9(D), hs_5(D));
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_close_conn (pcb_9(D), hs_5(D));
  Starting walk at: http_close_conn (pcb_9(D), hs_5(D));
  instance pointer: hs_5(D)  Outer instance pointer: hs_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = http_close_or_abort_conn (pcb_2(D), hs_3(D), 0);
  Starting walk at: _5 = http_close_or_abort_conn (pcb_2(D), hs_3(D), 0);
  instance pointer: pcb_2(D)  Outer instance pointer: pcb_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = http_close_or_abort_conn (pcb_2(D), hs_3(D), 0);
  Starting walk at: _5 = http_close_or_abort_conn (pcb_2(D), hs_3(D), 0);
  instance pointer: hs_3(D)  Outer instance pointer: hs_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_state_free (hs_11(D));
  Starting walk at: http_state_free (hs_11(D));
  instance pointer: hs_11(D)  Outer instance pointer: hs_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_sent (pcb_5(D), 0B);
  Function call may change dynamic type:tcp_poll (pcb_5(D), 0B, 0);
  Function call may change dynamic type:tcp_err (pcb_5(D), 0B);
  Function call may change dynamic type:tcp_recv (pcb_5(D), 0B);
  Function call may change dynamic type:tcp_arg (pcb_5(D), 0B);
Determining dynamic type for call: http_state_free.part.0 (hs_1(D));
  Starting walk at: http_state_free.part.0 (hs_1(D));
  instance pointer: hs_1(D)  Outer instance pointer: hs_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: http_state_init (ret_4);
  Starting walk at: http_state_init (ret_4);
  instance pointer: ret_4  Outer instance pointer: ret_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_4 = mem_malloc (44);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  http_recv.part.0/68:
    callsite  http_recv.part.0/68 -> http_parse_request.isra.0/67 : 
       param 0: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  http_recv.part.0/68 -> http_send/17 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  http_recv.part.0/68 -> http_close_conn/13 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_parse_request.isra.0/67:
    callsite  http_parse_request.isra.0/67 -> http_find_file/20 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
  Jump functions of caller  http_init_file.isra.0/66:
  Jump functions of caller  http_poll.part.0/65:
    callsite  http_poll.part.0/65 -> http_send/17 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_send.part.0/64:
    callsite  http_send.part.0/64 -> http_send_data_nonssi/16 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  http_send.part.0/64 -> http_close_conn/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_state_free.part.0/61:
    callsite  http_state_free.part.0/61 -> http_state_eof/9 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memset/60:
  Jump functions of caller  mem_malloc/59:
  Jump functions of caller  strchr/58:
  Jump functions of caller  fs_open/57:
  Jump functions of caller  memcpy/56:
  Jump functions of caller  strlen/55:
  Jump functions of caller  pbuf_clen/54:
  Jump functions of caller  strncmp/53:
  Jump functions of caller  lwip_strnstr/52:
  Jump functions of caller  pbuf_copy_partial/51:
  Jump functions of caller  pbuf_ref/50:
  Jump functions of caller  pbuf_cat/49:
  Jump functions of caller  tcp_recved/48:
  Jump functions of caller  tcp_output/47:
  Jump functions of caller  pbuf_free/46:
  Jump functions of caller  fs_close/45:
  Jump functions of caller  mem_free/44:
  Jump functions of caller  tcp_close/43:
  Jump functions of caller  tcp_abort/42:
  Jump functions of caller  tcp_write/41:
  Jump functions of caller  fs_bytes_left/40:
  Jump functions of caller  tcp_sent/39:
  Jump functions of caller  tcp_poll/38:
  Jump functions of caller  tcp_err/37:
  Jump functions of caller  tcp_recv/36:
  Jump functions of caller  tcp_arg/35:
  Jump functions of caller  tcp_accept/34:
  Jump functions of caller  tcp_listen_with_backlog/33:
  Jump functions of caller  tcp_bind/31:
  Jump functions of caller  tcp_setprio/30:
  Jump functions of caller  tcp_new_ip_type/29:
  Jump functions of caller  httpd_init/28:
    callsite  httpd_init/28 -> httpd_init_pcb/27 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 80
         value: 0x50, mask: 0x0
         Unknown VR
  Jump functions of caller  httpd_init_pcb/27:
  Jump functions of caller  http_accept/26:
    callsite  http_accept/26 -> http_state_alloc/8 : 
  Jump functions of caller  http_recv/25:
    callsite  http_recv/25 -> http_recv.part.0/68 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  http_recv/25 -> http_close_conn/13 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_poll/24:
    callsite  http_poll/24 -> http_poll.part.0/65 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  http_poll/24 -> http_close_conn/13 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  http_poll/24 -> http_close_conn/13 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
  Jump functions of caller  http_sent/23:
    callsite  http_sent/23 -> http_send/17 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 320, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_err/22:
    callsite  http_err/22 -> http_state_free/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_find_file/20:
    callsite  http_find_file/20 -> http_init_file.isra.0/66 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
    callsite  http_find_file/20 -> http_get_404_file/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  http_find_file/20 -> http_get_404_file/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  http_get_404_file/18:
  Jump functions of caller  http_send/17:
    callsite  http_send/17 -> http_send.part.0/64 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  http_send/17 -> http_check_eof/15 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_send_data_nonssi/16:
    callsite  http_send_data_nonssi/16 -> http_write/11 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  http_check_eof/15:
    callsite  http_check_eof/15 -> http_close_conn/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  http_check_eof/15 -> http_close_conn/13 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_close_conn/13:
    callsite  http_close_conn/13 -> http_close_or_abort_conn/12 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  http_close_or_abort_conn/12:
    callsite  http_close_or_abort_conn/12 -> http_state_free/10 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_write/11:
  Jump functions of caller  http_state_free/10:
    callsite  http_state_free/10 -> http_state_free.part.0/61 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_state_eof/9:
  Jump functions of caller  http_state_alloc/8:
    callsite  http_state_alloc/8 -> http_state_init/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  http_state_init/7:

 Propagating constants:

Not considering httpd_init for cloning; -fipa-cp-clone disabled.
Not considering http_accept for cloning; -fipa-cp-clone disabled.
Not considering http_recv for cloning; -fipa-cp-clone disabled.
Not considering http_poll for cloning; -fipa-cp-clone disabled.
Not considering http_sent for cloning; -fipa-cp-clone disabled.
Not considering http_err for cloning; -fipa-cp-clone disabled.

overall_size: 655, max_new_size: 11001
 - context independent values, size: 27, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 31, time_benefit: 1.000000
 - context independent values, size: 9, time_benefit: 1.000000
 - context independent values, size: 7, time_benefit: 1.000000
 - context independent values, size: 31, time_benefit: 3.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 37, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: http_recv.part.0/68:
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
  Node: http_parse_request.isra.0/67:
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
  Node: http_init_file.isra.0/66:
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
         Bits: value = 0x0, mask = 0x1
         int [0, 1]
        AGGS VARIABLE
  Node: http_poll.part.0/65:
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
  Node: http_send.part.0/64:
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
  Node: http_state_free.part.0/61:
    param [0]: VARIABLE
               0B [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: httpd_init/28:
  Node: httpd_init_pcb/27:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 80 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x50, mask = 0x0
         u16_t [80, 80]
        AGGS VARIABLE
  Node: http_accept/26:
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
  Node: http_recv/25:
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
  Node: http_poll/24:
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
  Node: http_sent/23:
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
  Node: http_err/22:
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
  Node: http_find_file/20:
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
         Bits: value = 0x0, mask = 0x1
         int [0, 1]
        AGGS VARIABLE
  Node: http_get_404_file/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const char * * ~[0B, 0B]
        AGGS VARIABLE
  Node: http_send/17:
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
  Node: http_send_data_nonssi/16:
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
  Node: http_check_eof/15:
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
  Node: http_close_conn/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0B [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: http_close_or_abort_conn/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0B [loc_time: 6, loc_size: 28, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         u8_t [0, 0]
        AGGS VARIABLE
  Node: http_write/11:
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
         Bits: value = 0x0, mask = 0xfffffffe
         u16_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         u8_t [0, 0]
        AGGS VARIABLE
  Node: http_state_free/10:
    param [0]: VARIABLE
               0B [loc_time: 3, loc_size: 3, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: http_state_eof/9:
    param [0]: VARIABLE
               0B [loc_time: 1, loc_size: 15, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: http_state_alloc/8:
  Node: http_state_init/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of httpd_init_pcb/27 for all known contexts.
    replacing param #1 port with const 80
 - Creating a specialized node of http_close_or_abort_conn/12 for all known contexts.
    replacing param #2 abort_conn with const 0
Introduced new external node (__builtin_unreachable/71).
 - Creating a specialized node of http_write/11 for all known contexts.
    replacing param #3 apiflags with const 0
Propagated bits info for function http_write.constprop/72:
 param 2: value = 0x0, mask = 0xfffffffe
 param 3: value = 0x0, mask = 0x0
Propagated bits info for function http_close_or_abort_conn.constprop/70:
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function httpd_init_pcb.constprop/69:
 param 1: value = 0x50, mask = 0x0
Propagated bits info for function http_init_file.isra.0/66:
 param 2: value = 0x0, mask = 0x1
Propagated bits info for function httpd_init_pcb/27:
 param 1: value = 0x50, mask = 0x0
Propagated bits info for function http_find_file/20:
 param 2: value = 0x0, mask = 0x1
Propagated bits info for function http_get_404_file/18:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function http_close_or_abort_conn/12:
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function http_write/11:
 param 2: value = 0x0, mask = 0xfffffffe
 param 3: value = 0x0, mask = 0x0

IPA constant propagation end

Reclaiming functions: tcp_abort/42 httpd_init_pcb/27 http_close_or_abort_conn/12 http_write/11
Reclaiming variables:
Clearing address taken flags:
Symbol table:

http_write.constprop.0/72 (http_write.constprop) @062e20e0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of http_write/11
  Availability: local
  Function flags: count:357913 (estimated locally) local optimize_size
  Called by: http_send_data_nonssi/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: tcp_write/41 (1545744 (estimated locally),4.32 per call) 
__builtin_unreachable/71 (__builtin_unreachable) @062e2ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_close_or_abort_conn.constprop/70 (0 (precise),0.00 per call) 
  Calls: 
http_close_or_abort_conn.constprop.0/70 (http_close_or_abort_conn.constprop) @0613f460
  Type: function definition analyzed
  Visibility:
  References: http_poll/24 (addr)
  Referring: 
  Clone of http_close_or_abort_conn/12
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: http_close_conn/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: tcp_arg/35 (1073741823 (estimated locally),1.00 per call) tcp_recv/36 (1073741823 (estimated locally),1.00 per call) tcp_err/37 (1073741823 (estimated locally),1.00 per call) tcp_poll/38 (1073741823 (estimated locally),1.00 per call) tcp_sent/39 (1073741823 (estimated locally),1.00 per call) http_state_free/10 (574129753 (estimated locally),0.53 per call) __builtin_unreachable/71 (0 (precise),0.00 per call) tcp_close/43 (708669604 (estimated locally),0.66 per call) tcp_poll/38 (233860969 (estimated locally),0.22 per call) 
httpd_init_pcb.constprop.0/69 (httpd_init_pcb.constprop) @0612de00
  Type: function definition analyzed
  Visibility:
  References: ip_addr_any_type/32 (addr)http_accept/26 (addr)
  Referring: 
  Clone of httpd_init_pcb/27
  Availability: local
  Function flags: count:299719 (estimated locally) local optimize_size
  Called by: httpd_init/28 (123389 (estimated locally),0.53 per call) 
  Calls: tcp_setprio/30 (160260 (estimated locally),0.53 per call) tcp_bind/31 (160260 (estimated locally),0.53 per call) tcp_listen_with_backlog/33 (52886 (estimated locally),0.18 per call) tcp_accept/34 (28278 (estimated locally),0.09 per call) 
http_recv.part.0/68 (http_recv.part.0) @061d5d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:746960 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: http_recv/25 (746960 (estimated locally),0.11 per call) 
  Calls: http_parse_request.isra.0/67 (746960 (estimated locally),1.00 per call) pbuf_free/46 (225711 (estimated locally),0.30 per call) pbuf_free/46 (639586 (estimated locally),0.86 per call) http_send/17 (211063 (estimated locally),0.28 per call) http_close_conn/13 (86733 (estimated locally),0.12 per call) 
http_parse_request.isra.0/67 (http_parse_request.isra.0) @060f70e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: httpd_req_buf/5 (addr)httpd_req_buf/5 (addr)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: http_recv.part.0/68 (746960 (estimated locally),1.00 per call) 
  Calls: pbuf_clen/54 (160953 (estimated locally),0.45 per call) http_find_file/20 (4919 (estimated locally),0.01 per call) lwip_strnstr/52 (13227 (estimated locally),0.04 per call) lwip_strnstr/52 (9981 (estimated locally),0.03 per call) lwip_strnstr/52 (57261 (estimated locally),0.16 per call) strncmp/53 (58483 (estimated locally),0.16 per call) lwip_strnstr/52 (83547 (estimated locally),0.23 per call) pbuf_copy_partial/51 (89346 (estimated locally),0.25 per call) pbuf_ref/50 (167095 (estimated locally),0.47 per call) pbuf_cat/49 (89346 (estimated locally),0.25 per call) 
http_init_file.isra.0/66 (http_init_file.isra.0) @060efe00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:511305 (estimated locally) body local optimize_size
  Called by: http_find_file/20 (1073741823 (estimated locally),1.00 per call) 
  Calls: lwip_strnstr/52 (24390 (estimated locally),0.05 per call) 
http_poll.part.0/65 (http_poll.part.0) @060ef9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: http_poll/24 (457949063 (estimated locally),0.43 per call) 
  Calls: http_send/17 (1073741824 (estimated locally),1.00 per call) tcp_output/47 (354334802 (estimated locally),0.33 per call) 
http_send.part.0/64 (http_send.part.0) @0612d000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: http_send/17 (729986600 (estimated locally),0.68 per call) 
  Calls: http_send_data_nonssi/16 (1073741824 (estimated locally),1.00 per call) fs_bytes_left/40 (354334802 (estimated locally),0.33 per call) http_close_conn/13 (53114787 (estimated locally),0.05 per call) 
http_state_free.part.0/61 (http_state_free.part.0) @05ef28c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: http_state_free/10 (574129752 (estimated locally),0.53 per call) 
  Calls: http_state_eof/9 (1073741824 (estimated locally),1.00 per call) mem_free/44 (1073741824 (estimated locally),1.00 per call) 
memset/60 (memset) @06197e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_state_init/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
mem_malloc/59 (mem_malloc) @06197c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_state_alloc/8 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
strchr/58 (strchr) @061978c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_find_file/20 (971266053 (estimated locally),0.90 per call) 
  Calls: 
fs_open/57 (fs_open) @061977e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_find_file/20 (971266053 (estimated locally),0.90 per call) http_find_file/20 (573985916 (estimated locally),0.53 per call) http_get_404_file/18 (116930485 (estimated locally),0.11 per call) http_get_404_file/18 (354334802 (estimated locally),0.33 per call) http_get_404_file/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
memcpy/56 (memcpy) @06197620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_find_file/20 (125014132 (estimated locally),0.12 per call) http_find_file/20 (71557368 (estimated locally),0.07 per call) 
  Calls: 
strlen/55 (strlen) @06197540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_find_file/20 (125014132 (estimated locally),0.12 per call) http_find_file/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pbuf_clen/54 (pbuf_clen) @061971c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_parse_request.isra.0/67 (160953 (estimated locally),0.45 per call) 
  Calls: 
strncmp/53 (strncmp) @061970e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_parse_request.isra.0/67 (58483 (estimated locally),0.16 per call) 
  Calls: 
lwip_strnstr/52 (lwip_strnstr) @06197000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_parse_request.isra.0/67 (13227 (estimated locally),0.04 per call) http_parse_request.isra.0/67 (9981 (estimated locally),0.03 per call) http_parse_request.isra.0/67 (57261 (estimated locally),0.16 per call) http_parse_request.isra.0/67 (83547 (estimated locally),0.23 per call) http_init_file.isra.0/66 (24390 (estimated locally),0.05 per call) 
  Calls: 
pbuf_copy_partial/51 (pbuf_copy_partial) @06187ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_parse_request.isra.0/67 (89346 (estimated locally),0.25 per call) 
  Calls: 
pbuf_ref/50 (pbuf_ref) @06187e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_parse_request.isra.0/67 (167095 (estimated locally),0.47 per call) 
  Calls: 
pbuf_cat/49 (pbuf_cat) @06187d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_parse_request.isra.0/67 (89346 (estimated locally),0.25 per call) 
  Calls: 
tcp_recved/48 (tcp_recved) @061879a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_recv/25 (2489867 (estimated locally),0.37 per call) http_recv/25 (2235164 (estimated locally),0.34 per call) 
  Calls: 
tcp_output/47 (tcp_output) @06187540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_poll.part.0/65 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pbuf_free/46 (pbuf_free) @06187380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_recv/25 (1742907 (estimated locally),0.26 per call) http_recv/25 (2235164 (estimated locally),0.34 per call) http_recv.part.0/68 (225711 (estimated locally),0.30 per call) http_recv.part.0/68 (639586 (estimated locally),0.86 per call) http_state_eof/9 (574129754 (estimated locally),0.53 per call) 
  Calls: 
fs_close/45 (fs_close) @061872a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_state_eof/9 (574129754 (estimated locally),0.53 per call) 
  Calls: 
mem_free/44 (mem_free) @061870e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_state_free.part.0/61 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_close/43 (tcp_close) @06178ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_close_or_abort_conn.constprop/70 (708669604 (estimated locally),0.66 per call) 
  Calls: 
tcp_write/41 (tcp_write) @06178a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_write.constprop/72 (1545744 (estimated locally),4.32 per call) 
  Calls: 
fs_bytes_left/40 (fs_bytes_left) @06178620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_send.part.0/64 (354334802 (estimated locally),0.33 per call) http_check_eof/15 (126307 (estimated locally),0.82 per call) 
  Calls: 
tcp_sent/39 (tcp_sent) @06178380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_close_or_abort_conn.constprop/70 (1073741823 (estimated locally),1.00 per call) http_accept/26 (1043324037 (estimated locally),0.97 per call) 
  Calls: 
tcp_poll/38 (tcp_poll) @061782a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_close_or_abort_conn.constprop/70 (1073741823 (estimated locally),1.00 per call) http_close_or_abort_conn.constprop/70 (233860969 (estimated locally),0.22 per call) http_accept/26 (1043324037 (estimated locally),0.97 per call) 
  Calls: 
tcp_err/37 (tcp_err) @061781c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_close_or_abort_conn.constprop/70 (1073741823 (estimated locally),1.00 per call) http_accept/26 (1043324037 (estimated locally),0.97 per call) 
  Calls: 
tcp_recv/36 (tcp_recv) @061780e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_close_or_abort_conn.constprop/70 (1073741823 (estimated locally),1.00 per call) http_accept/26 (1043324037 (estimated locally),0.97 per call) 
  Calls: 
tcp_arg/35 (tcp_arg) @06178000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: http_close_or_abort_conn.constprop/70 (1073741823 (estimated locally),1.00 per call) http_accept/26 (1043324037 (estimated locally),0.97 per call) 
  Calls: 
tcp_accept/34 (tcp_accept) @06172ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: httpd_init_pcb.constprop/69 (28278 (estimated locally),0.09 per call) 
  Calls: 
tcp_listen_with_backlog/33 (tcp_listen_with_backlog) @06172e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: httpd_init_pcb.constprop/69 (52886 (estimated locally),0.18 per call) 
  Calls: 
ip_addr_any_type/32 (ip_addr_any_type) @061755a0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: httpd_init_pcb.constprop.0/69 (addr)
  Availability: not_available
  Varpool flags: read-only
tcp_bind/31 (tcp_bind) @06172d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: httpd_init_pcb.constprop/69 (160260 (estimated locally),0.53 per call) 
  Calls: 
tcp_setprio/30 (tcp_setprio) @06172c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: httpd_init_pcb.constprop/69 (160260 (estimated locally),0.53 per call) http_accept/26 (1052905478 (estimated locally),0.98 per call) 
  Calls: 
tcp_new_ip_type/29 (tcp_new_ip_type) @06172a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: httpd_init/28 (230763 (estimated locally),1.00 per call) 
  Calls: 
httpd_init/28 (httpd_init) @06172620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: httpd_init_pcb.constprop/69 (123389 (estimated locally),0.53 per call) tcp_new_ip_type/29 (230763 (estimated locally),1.00 per call) 
httpd_init_pcb/27 (httpd_init_pcb) @06172380
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:299719 (estimated locally) body optimize_size
  Called by: 
  Calls: 
http_accept/26 (http_accept) @06172000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: http_recv/25 (addr)http_err/22 (addr)http_poll/24 (addr)http_sent/23 (addr)
  Referring: httpd_init_pcb.constprop.0/69 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_sent/39 (1043324037 (estimated locally),0.97 per call) tcp_poll/38 (1043324037 (estimated locally),0.97 per call) tcp_err/37 (1043324037 (estimated locally),0.97 per call) tcp_recv/36 (1043324037 (estimated locally),0.97 per call) tcp_arg/35 (1043324037 (estimated locally),0.97 per call) http_state_alloc/8 (1052905478 (estimated locally),0.98 per call) tcp_setprio/30 (1052905478 (estimated locally),0.98 per call) 
http_recv/25 (http_recv) @0613fee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: http_accept/26 (addr)
  Availability: available
  Function flags: count:6670087 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/46 (1742907 (estimated locally),0.26 per call) http_recv.part.0/68 (746960 (estimated locally),0.11 per call) tcp_recved/48 (2489867 (estimated locally),0.37 per call) http_close_conn/13 (4180221 (estimated locally),0.63 per call) pbuf_free/46 (2235164 (estimated locally),0.34 per call) tcp_recved/48 (2235164 (estimated locally),0.34 per call) 
http_poll/24 (http_poll) @0613fc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: http_close_or_abort_conn.constprop.0/70 (addr)http_accept/26 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: http_poll.part.0/65 (457949063 (estimated locally),0.43 per call) http_close_conn/13 (111947936 (estimated locally),0.10 per call) http_close_conn/13 (105334073 (estimated locally),0.10 per call) 
http_sent/23 (http_sent) @0613f9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: http_accept/26 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: http_send/17 (741418730 (estimated locally),0.69 per call) 
http_err/22 (http_err) @0613f700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: http_accept/26 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: http_state_free/10 (574129754 (estimated locally),0.53 per call) 
http_find_file/20 (http_find_file) @0613f1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: http_uri_buf/6 (addr)http_uri_buf/6 (addr)http_uri_buf/6 (write)httpd_default_filenames/4 (read)http_uri_buf/6 (addr)http_uri_buf/6 (write)httpd_default_filenames/4 (read)http_uri_buf/6 (addr)http_uri_buf/6 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: http_parse_request.isra.0/67 (4919 (estimated locally),0.01 per call) 
  Calls: http_init_file.isra.0/66 (1073741823 (estimated locally),1.00 per call) http_get_404_file/18 (187153200 (estimated locally),0.17 per call) http_get_404_file/18 (320517797 (estimated locally),0.30 per call) fs_open/57 (971266053 (estimated locally),0.90 per call) strchr/58 (971266053 (estimated locally),0.90 per call) fs_open/57 (573985916 (estimated locally),0.53 per call) memcpy/56 (125014132 (estimated locally),0.12 per call) strlen/55 (125014132 (estimated locally),0.12 per call) memcpy/56 (71557368 (estimated locally),0.07 per call) strlen/55 (1073741824 (estimated locally),1.00 per call) 
http_get_404_file/18 (http_get_404_file) @0612db60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: http_find_file/20 (187153200 (estimated locally),0.17 per call) http_find_file/20 (320517797 (estimated locally),0.30 per call) 
  Calls: fs_open/57 (116930485 (estimated locally),0.11 per call) fs_open/57 (354334802 (estimated locally),0.33 per call) fs_open/57 (1073741824 (estimated locally),1.00 per call) 
http_send/17 (http_send) @0612d8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: http_recv.part.0/68 (211063 (estimated locally),0.28 per call) http_poll.part.0/65 (1073741824 (estimated locally),1.00 per call) http_sent/23 (741418730 (estimated locally),0.69 per call) 
  Calls: http_send.part.0/64 (729986600 (estimated locally),0.68 per call) http_check_eof/15 (439750964 (estimated locally),0.41 per call) 
http_send_data_nonssi/16 (http_send_data_nonssi) @0612d620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: http_send.part.0/64 (1073741824 (estimated locally),1.00 per call) 
  Calls: http_write.constprop/72 (1073741824 (estimated locally),1.00 per call) 
http_check_eof/15 (http_check_eof) @0612d380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:154203 (estimated locally) body local optimize_size
  Called by: http_send/17 (439750964 (estimated locally),0.41 per call) 
  Calls: http_close_conn/13 (18933 (estimated locally),0.12 per call) fs_bytes_left/40 (126307 (estimated locally),0.82 per call) http_close_conn/13 (27895 (estimated locally),0.18 per call) 
http_close_conn/13 (http_close_conn) @060feee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: http_recv/25 (4180221 (estimated locally),0.63 per call) http_recv.part.0/68 (86733 (estimated locally),0.12 per call) http_poll/24 (111947936 (estimated locally),0.10 per call) http_poll/24 (105334073 (estimated locally),0.10 per call) http_send.part.0/64 (53114787 (estimated locally),0.05 per call) http_check_eof/15 (18933 (estimated locally),0.12 per call) http_check_eof/15 (27895 (estimated locally),0.18 per call) 
  Calls: http_close_or_abort_conn.constprop/70 (1073741824 (estimated locally),1.00 per call) 
http_close_or_abort_conn/12 (http_close_or_abort_conn) @060fec40
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
http_write/11 (http_write) @060fe9a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
http_state_free/10 (http_state_free) @060fe700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: http_close_or_abort_conn.constprop/70 (574129753 (estimated locally),0.53 per call) http_err/22 (574129754 (estimated locally),0.53 per call) 
  Calls: http_state_free.part.0/61 (574129752 (estimated locally),0.53 per call) 
http_state_eof/9 (http_state_eof) @060fe460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: http_state_free.part.0/61 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_free/46 (574129754 (estimated locally),0.53 per call) fs_close/45 (574129754 (estimated locally),0.53 per call) 
http_state_alloc/8 (http_state_alloc) @060fe1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: http_accept/26 (1052905478 (estimated locally),0.98 per call) 
  Calls: http_state_init/7 (574129754 (estimated locally),0.53 per call) mem_malloc/59 (1073741824 (estimated locally),1.00 per call) 
http_state_init/7 (http_state_init) @060fbee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: http_state_alloc/8 (574129754 (estimated locally),0.53 per call) 
  Calls: memset/60 (1073741824 (estimated locally),1.00 per call) 
http_uri_buf/6 (http_uri_buf) @060f2f30
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: http_find_file/20 (addr)http_find_file/20 (addr)http_find_file/20 (write)http_find_file/20 (addr)http_find_file/20 (write)http_find_file/20 (addr)http_find_file/20 (addr)
  Availability: available
  Varpool flags:
httpd_req_buf/5 (httpd_req_buf) @060f2e58
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: http_parse_request.isra.0/67 (addr)http_parse_request.isra.0/67 (addr)
  Availability: available
  Varpool flags:
httpd_default_filenames/4 (httpd_default_filenames) @060f2d80
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: http_find_file/20 (read)http_find_file/20 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function http_state_eof (http_state_eof, funcdef_no=6, decl_uid=7941, cgraph_uid=7, symbol_order=9)

Modification phase of node http_state_eof/9
http_state_eof (struct http_state * hs)
{
  struct fs_file * _1;
  struct pbuf * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = hs_6(D)->handle;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  fs_close (_1);
  # DEBUG BEGIN_STMT
  hs_6(D)->handle = 0B;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = hs_6(D)->req;
  if (_2 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pbuf_free (_2);
  # DEBUG BEGIN_STMT
  hs_6(D)->req = 0B;

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function http_get_404_file (http_get_404_file, funcdef_no=15, decl_uid=7992, cgraph_uid=16, symbol_order=18)

Modification phase of node http_get_404_file/18
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
http_get_404_file (struct http_state * hs, const char * * uri)
{
  err_t err;
  struct fs_file * _1;
  struct fs_file * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *uri_5(D) = "/404.html";
  # DEBUG BEGIN_STMT
  _1 = &hs_7(D)->file_handle;
  err_9 = fs_open (_1, "/404.html");
  # DEBUG err => err_9
  # DEBUG BEGIN_STMT
  if (err_9 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  *uri_5(D) = "/404.htm";
  # DEBUG BEGIN_STMT
  err_12 = fs_open (_1, "/404.htm");
  # DEBUG err => err_12
  # DEBUG BEGIN_STMT
  if (err_12 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 4> [local count: 116930485]:
  # DEBUG BEGIN_STMT
  *uri_5(D) = "/404.shtml";
  # DEBUG BEGIN_STMT
  err_15 = fs_open (_1, "/404.shtml");
  # DEBUG err => err_15
  # DEBUG BEGIN_STMT
  if (err_15 != 0)
    goto <bb 5>; [17.38%]
  else
    goto <bb 6>; [82.62%]

  <bb 5> [local count: 20322518]:
  # DEBUG BEGIN_STMT
  *uri_5(D) = 0B;
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # _2 = PHI <0B(5), _1(3), _1(2), _1(4)>
  return _2;

}



;; Function http_accept (http_accept, funcdef_no=23, decl_uid=8074, cgraph_uid=24, symbol_order=26)

Modification phase of node http_accept/26
http_accept (void * arg, struct tcp_pcb * pcb, err_t err)
{
  struct http_state * hs;
  err_t _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_3(D) != 0)
    goto <bb 6>; [1.04%]
  else
    goto <bb 3>; [98.96%]

  <bb 3> [local count: 1062574910]:
  if (pcb_4(D) == 0B)
    goto <bb 6>; [0.91%]
  else
    goto <bb 4>; [99.09%]

  <bb 4> [local count: 1052905478]:
  # DEBUG BEGIN_STMT
  tcp_setprio (pcb_4(D), 1);
  # DEBUG BEGIN_STMT
  hs_8 = http_state_alloc ();
  # DEBUG hs => hs_8
  # DEBUG BEGIN_STMT
  if (hs_8 == 0B)
    goto <bb 6>; [0.91%]
  else
    goto <bb 5>; [99.09%]

  <bb 5> [local count: 1043324037]:
  # DEBUG BEGIN_STMT
  hs_8->pcb = pcb_4(D);
  # DEBUG BEGIN_STMT
  tcp_arg (pcb_4(D), hs_8);
  # DEBUG BEGIN_STMT
  tcp_recv (pcb_4(D), http_recv);
  # DEBUG BEGIN_STMT
  tcp_err (pcb_4(D), http_err);
  # DEBUG BEGIN_STMT
  tcp_poll (pcb_4(D), http_poll, 4);
  # DEBUG BEGIN_STMT
  tcp_sent (pcb_4(D), http_sent);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # _1 = PHI <-6(3), -1(4), 0(5), -6(2)>
  return _1;

}



;; Function http_err (http_err, funcdef_no=19, decl_uid=8047, cgraph_uid=20, symbol_order=22)

Modification phase of node http_err/22
http_err (void * arg, err_t err)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG hs => arg_2(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_2(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  http_state_free (arg_2(D));

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function http_close_conn (http_close_conn, funcdef_no=10, decl_uid=7911, cgraph_uid=11, symbol_order=13)

Modification phase of node http_close_conn/13
http_close_conn (struct tcp_pcb * pcb, struct http_state * hs)
{
  err_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = http_close_or_abort_conn (pcb_2(D), hs_3(D), 0);
  return _5;

}



;; Function http_send (http_send, funcdef_no=14, decl_uid=7987, cgraph_uid=15, symbol_order=17)

Modification phase of node http_send/17
http_send (struct tcp_pcb * pcb, struct http_state * hs)
{
  long unsigned int _1;
  unsigned char _2;
  u8_t _3;
  unsigned char _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG data_to_send => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (hs_7(D) == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  _1 = hs_7(D)->left;
  if (_1 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 439750964]:
  # DEBUG BEGIN_STMT
  _2 = http_check_eof (pcb_9(D), hs_7(D));
  if (_2 == 0)
    goto <bb 6>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 729986600]:
  _5 = http_send.part.0 (pcb_9(D), hs_7(D));

  <bb 6> [local count: 1073741824]:
  # _3 = PHI <0(2), 0(4), _5(5)>
  return _3;

}



;; Function http_sent (http_sent, funcdef_no=20, decl_uid=8053, cgraph_uid=21, symbol_order=23)

Modification phase of node http_sent/23
http_sent (void * arg, struct tcp_pcb * pcb, u16_t len)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG hs => arg_2(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_2(D) == 0B)
    goto <bb 4>; [30.95%]
  else
    goto <bb 3>; [69.05%]

  <bb 3> [local count: 741418730]:
  # DEBUG BEGIN_STMT
  MEM[(struct http_state *)arg_2(D)].retries = 0;
  # DEBUG BEGIN_STMT
  http_send (pcb_5(D), arg_2(D));
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  return 0;

}



;; Function http_poll (http_poll, funcdef_no=21, decl_uid=7929, cgraph_uid=22, symbol_order=24)

Modification phase of node http_poll/24
http_poll (void * arg, struct tcp_pcb * pcb)
{
  unsigned char _1;
  unsigned char _2;
  struct fs_file * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG hs => arg_5(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_5(D) == 0B)
    goto <bb 3>; [9.81%]
  else
    goto <bb 4>; [90.19%]

  <bb 3> [local count: 105334073]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  http_close_conn (pcb_8(D), 0B);
  # DEBUG closed => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 968407752]:
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct http_state *)arg_5(D)].retries;
  _2 = _1 + 1;
  MEM[(struct http_state *)arg_5(D)].retries = _2;
  # DEBUG BEGIN_STMT
  if (_2 == 4)
    goto <bb 5>; [11.56%]
  else
    goto <bb 6>; [88.44%]

  <bb 5> [local count: 111947936]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  http_close_conn (pcb_8(D), arg_5(D));
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 856459816]:
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct http_state *)arg_5(D)].handle;
  if (_3 != 0B)
    goto <bb 7>; [53.47%]
  else
    goto <bb 8>; [46.53%]

  <bb 7> [local count: 457949063]:
  http_poll.part.0 (arg_5(D), pcb_8(D));

  <bb 8> [local count: 1073741824]:
  return 0;

}



;; Function http_recv (http_recv, funcdef_no=22, decl_uid=8066, cgraph_uid=23, symbol_order=25)

Modification phase of node http_recv/25
http_recv (void * arg, struct tcp_pcb * pcb, struct pbuf * p, err_t err)
{
  short unsigned int _1;
  short unsigned int _2;
  struct fs_file * _3;

  <bb 2> [local count: 6670087]:
  # DEBUG BEGIN_STMT
  # DEBUG hs => arg_7(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_8(D) != 0)
    goto <bb 5>; [34.00%]
  else
    goto <bb 3>; [66.00%]

  <bb 3> [local count: 4402258]:
  if (p_9(D) == 0B)
    goto <bb 5>; [18.09%]
  else
    goto <bb 4>; [81.91%]

  <bb 4> [local count: 3605889]:
  if (arg_7(D) == 0B)
    goto <bb 5>; [30.95%]
  else
    goto <bb 8>; [69.05%]

  <bb 5> [local count: 4180221]:
  # DEBUG BEGIN_STMT
  if (p_9(D) != 0B)
    goto <bb 6>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 6> [local count: 2235164]:
  # DEBUG BEGIN_STMT
  _1 = p_9(D)->tot_len;
  tcp_recved (pcb_11(D), _1);
  # DEBUG BEGIN_STMT
  pbuf_free (p_9(D));

  <bb 7> [local count: 4180221]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  http_close_conn (pcb_11(D), arg_7(D));
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 8> [local count: 2489867]:
  # DEBUG BEGIN_STMT
  _2 = p_9(D)->tot_len;
  tcp_recved (pcb_11(D), _2);
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct http_state *)arg_7(D)].handle;
  if (_3 == 0B)
    goto <bb 9>; [30.00%]
  else
    goto <bb 10>; [70.00%]

  <bb 9> [local count: 746960]:
  # DEBUG D#6 => err_8(D)
  http_recv.part.0 (arg_7(D), pcb_11(D), p_9(D));
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 1742907]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_9(D));

  <bb 11> [local count: 6562713]:
  return 0;

}



;; Function httpd_init (httpd_init, funcdef_no=25, decl_uid=6397, cgraph_uid=26, symbol_order=28)

Modification phase of node httpd_init/28
httpd_init ()
{
  struct tcp_pcb * pcb;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4 = tcp_new_ip_type (46);
  # DEBUG pcb => pcb_4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4 == 0B)
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
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  httpd_init_pcb (pcb_4, 80);
  return;

}


