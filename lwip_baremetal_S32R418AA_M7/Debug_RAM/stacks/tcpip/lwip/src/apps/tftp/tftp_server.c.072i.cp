
IPA constant propagation start:
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 5, "Wrong block number");
  Starting walk at: send_error (addr_72(D), port_71(D), 5, "Wrong block number");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:blknum_77 = lwip_htons (_55);
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 5, "Wrong block number");
  Starting walk at: send_error (addr_72(D), port_71(D), 5, "Wrong block number");
  instance pointer: "Wrong block number"  Outer instance pointer: "Wrong block number" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Not a read connection");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Not a read connection");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Not a read connection");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Not a read connection");
  instance pointer: "Not a read connection"  Outer instance pointer: "Not a read connection" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "No connection");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "No connection");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "No connection");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "No connection");
  instance pointer: "No connection"  Outer instance pointer: "No connection" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 5, "Wrong block number");
  Starting walk at: send_error (addr_72(D), port_71(D), 5, "Wrong block number");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:blknum_85 = lwip_htons (_44);
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 5, "Wrong block number");
  Starting walk at: send_error (addr_72(D), port_71(D), 5, "Wrong block number");
  instance pointer: "Wrong block number"  Outer instance pointer: "Wrong block number" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_90 = _47 (_48, p_69(D));
  Starting walk at: ret_90 = _47 (_48, p_69(D));
  instance pointer: _48  Outer instance pointer: _48 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_remove_header (p_69(D), 4);
  Function call may change dynamic type:blknum_85 = lwip_htons (_44);
Determining dynamic type for call: ret_90 = _47 (_48, p_69(D));
  Starting walk at: ret_90 = _47 (_48, p_69(D));
  instance pointer: p_69(D)  Outer instance pointer: p_69(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_remove_header (p_69(D), 4);
  Function call may change dynamic type:blknum_85 = lwip_htons (_44);
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "error writing file");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "error writing file");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_90 = _47 (_48, p_69(D));
  Function call may change dynamic type:pbuf_remove_header (p_69(D), 4);
  Function call may change dynamic type:blknum_85 = lwip_htons (_44);
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "error writing file");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "error writing file");
  instance pointer: "error writing file"  Outer instance pointer: "error writing file" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Not a write connection");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Not a write connection");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Not a write connection");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Not a write connection");
  instance pointer: "Not a write connection"  Outer instance pointer: "Not a write connection" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "No connection");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "No connection");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "No connection");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "No connection");
  instance pointer: "No connection"  Outer instance pointer: "No connection" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _33 = _30 (&filename, &mode, _32);
  Starting walk at: _33 = _30 (&filename, &mode, _32);
  instance pointer: &filename  Outer instance pointer: filename offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_copy_partial (p_69(D), &mode, _28, _27);
  Function call may change dynamic type:mode_end_offset_104 = pbuf_memfind (p_69(D), &tftp_null, 1, _27);
  Function call may change dynamic type:pbuf_copy_partial (p_69(D), &filename, _26, 2);
  Function call may change dynamic type:filename_end_offset_101 = pbuf_memfind (p_69(D), &tftp_null, 1, 2);
  Function call may change dynamic type:sys_timeout (1000, tftp_tmr, 0B);
Determining dynamic type for call: _33 = _30 (&filename, &mode, _32);
  Starting walk at: _33 = _30 (&filename, &mode, _32);
  instance pointer: &mode  Outer instance pointer: mode offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_copy_partial (p_69(D), &mode, _28, _27);
  Function call may change dynamic type:mode_end_offset_104 = pbuf_memfind (p_69(D), &tftp_null, 1, _27);
  Function call may change dynamic type:pbuf_copy_partial (p_69(D), &filename, _26, 2);
  Function call may change dynamic type:filename_end_offset_101 = pbuf_memfind (p_69(D), &tftp_null, 1, 2);
  Function call may change dynamic type:sys_timeout (1000, tftp_tmr, 0B);
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 1, "Unable to open requested file.");
  Starting walk at: send_error (addr_72(D), port_71(D), 1, "Unable to open requested file.");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_33 = _30 (&filename, &mode, _32);
  Function call may change dynamic type:pbuf_copy_partial (p_69(D), &mode, _28, _27);
  Function call may change dynamic type:mode_end_offset_104 = pbuf_memfind (p_69(D), &tftp_null, 1, _27);
  Function call may change dynamic type:pbuf_copy_partial (p_69(D), &filename, _26, 2);
  Function call may change dynamic type:filename_end_offset_101 = pbuf_memfind (p_69(D), &tftp_null, 1, 2);
  Function call may change dynamic type:sys_timeout (1000, tftp_tmr, 0B);
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 1, "Unable to open requested file.");
  Starting walk at: send_error (addr_72(D), port_71(D), 1, "Unable to open requested file.");
  instance pointer: "Unable to open requested file."  Outer instance pointer: "Unable to open requested file." offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Mode too long/not NULL terminated");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Mode too long/not NULL terminated");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mode_end_offset_104 = pbuf_memfind (p_69(D), &tftp_null, 1, _27);
  Function call may change dynamic type:pbuf_copy_partial (p_69(D), &filename, _26, 2);
  Function call may change dynamic type:filename_end_offset_101 = pbuf_memfind (p_69(D), &tftp_null, 1, 2);
  Function call may change dynamic type:sys_timeout (1000, tftp_tmr, 0B);
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Mode too long/not NULL terminated");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Mode too long/not NULL terminated");
  instance pointer: "Mode too long/not NULL terminated"  Outer instance pointer: "Mode too long/not NULL terminated" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Filename too long/not NULL terminated");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Filename too long/not NULL terminated");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:filename_end_offset_101 = pbuf_memfind (p_69(D), &tftp_null, 1, 2);
  Function call may change dynamic type:sys_timeout (1000, tftp_tmr, 0B);
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Filename too long/not NULL terminated");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Filename too long/not NULL terminated");
  instance pointer: "Filename too long/not NULL terminated"  Outer instance pointer: "Filename too long/not NULL terminated" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Only one connection at a time is supported");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Only one connection at a time is supported");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Only one connection at a time is supported");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Only one connection at a time is supported");
  instance pointer: "Only one connection at a time is supported"  Outer instance pointer: "Only one connection at a time is supported" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 4, "Unknown operation");
  Starting walk at: send_error (addr_72(D), port_71(D), 4, "Unknown operation");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 4, "Unknown operation");
  Starting walk at: send_error (addr_72(D), port_71(D), 4, "Unknown operation");
  instance pointer: "Unknown operation"  Outer instance pointer: "Unknown operation" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Only one connection at a time is supported");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Only one connection at a time is supported");
  instance pointer: addr_72(D)  Outer instance pointer: addr_72(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: send_error (addr_72(D), port_71(D), 2, "Only one connection at a time is supported");
  Starting walk at: send_error (addr_72(D), port_71(D), 2, "Only one connection at a time is supported");
  instance pointer: "Only one connection at a time is supported"  Outer instance pointer: "Only one connection at a time is supported" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_24 = _6 (_7, _8, 512);
  Starting walk at: ret_24 = _6 (_7, _8, 512);
  instance pointer: _7  Outer instance pointer: _7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_alloc (74, 516, 640);
  Function call may change dynamic type:pbuf_free (_1);
Determining dynamic type for call: ret_24 = _6 (_7, _8, 512);
  Starting walk at: ret_24 = _6 (_7, _8, 512);
  instance pointer: _8  Outer instance pointer: _8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_alloc (74, 516, 640);
  Function call may change dynamic type:pbuf_free (_1);
Determining dynamic type for call: send_error (&tftp_state.addr, _9, 2, "Error occured while reading the file.");
  Starting walk at: send_error (&tftp_state.addr, _9, 2, "Error occured while reading the file.");
  instance pointer: &tftp_state.addr  Outer instance pointer: tftp_state offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:ret_24 = _6 (_7, _8, 512);
  Function call may change dynamic type:_4 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_alloc (74, 516, 640);
  Function call may change dynamic type:pbuf_free (_1);
Determining dynamic type for call: send_error (&tftp_state.addr, _9, 2, "Error occured while reading the file.");
  Starting walk at: send_error (&tftp_state.addr, _9, 2, "Error occured while reading the file.");
  instance pointer: "Error occured while reading the file."  Outer instance pointer: "Error occured while reading the file." offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 (_2);
  Starting walk at: _4 (_2);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sys_untimeout (tftp_tmr, 0B);
  Function call may change dynamic type:pbuf_free (_1);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  tftp_tmr.part.0/30:
    callsite  tftp_tmr.part.0/30 -> resend_data/5 : 
  Jump functions of caller  memset/29:
  Jump functions of caller  memcpy/28:
  Jump functions of caller  strlen/27:
  Jump functions of caller  sys_untimeout/26:
  Jump functions of caller  pbuf_realloc/25:
  Jump functions of caller  udp_sendto/24:
  Jump functions of caller  pbuf_copy/23:
  Jump functions of caller  pbuf_alloc/22:
  Jump functions of caller  pbuf_remove_header/21:
  Jump functions of caller  lwip_htons/20:
  Jump functions of caller  pbuf_copy_partial/19:
  Jump functions of caller  pbuf_memfind/18:
  Jump functions of caller  sys_timeout/17:
  Jump functions of caller  pbuf_free/16:
  Jump functions of caller  udp_recv/15:
  Jump functions of caller  udp_remove/14:
  Jump functions of caller  udp_bind/12:
  Jump functions of caller  udp_new_ip_type/11:
  Jump functions of caller  tftp_cleanup/10:
    callsite  tftp_cleanup/10 -> close_handle/2 : 
  Jump functions of caller  tftp_init/9:
  Jump functions of caller  tftp_tmr/8:
    callsite  tftp_tmr/8 -> close_handle/2 : 
    callsite  tftp_tmr/8 -> tftp_tmr.part.0/30 : 
  Jump functions of caller  recv/7:
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 3: CONST: "Unknown operation"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> close_handle/2 : 
    callsite  recv/7 -> send_data/6 : 
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
       param 3: CONST: "Wrong block number"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: CONST: "Not a read connection"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: CONST: "No connection"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
       param 3: CONST: "Wrong block number"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_ack/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  recv/7 -> close_handle/2 : 
    callsite  recv/7 -> send_ack/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  recv/7 -> close_handle/2 : 
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: CONST: "error writing file"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: CONST: "Not a write connection"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: CONST: "No connection"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_data/6 : 
    callsite  recv/7 -> send_ack/4 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: CONST: "Unable to open requested file."
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: CONST: "Mode too long/not NULL terminated"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: CONST: "Filename too long/not NULL terminated"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: CONST: "Only one connection at a time is supported"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  recv/7 -> send_error/3 : 
       param 0: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: CONST: "Only one connection at a time is supported"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    indirect simple callsite, calling param -1, offset 0, for stmt ret_90 = _47 (_48, p_69(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _33 = _30 (&filename, &mode, _32);
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
  Jump functions of caller  send_data/6:
    callsite  send_data/6 -> resend_data/5 : 
    callsite  send_data/6 -> close_handle/2 : 
    callsite  send_data/6 -> send_error/3 : 
       param 0: CONST: &tftp_state.addr
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: CONST: "Error occured while reading the file."
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    indirect simple callsite, calling param -1, offset 0, for stmt ret_24 = _6 (_7, _8, 512);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 512
         value: 0x200, mask: 0x0
         Unknown VR
  Jump functions of caller  resend_data/5:
  Jump functions of caller  send_ack/4:
  Jump functions of caller  send_error/3:
  Jump functions of caller  close_handle/2:
    indirect simple callsite, calling param -1, offset 0, for stmt _4 (_2);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR

 Propagating constants:

Not considering tftp_cleanup for cloning; -fipa-cp-clone disabled.
Not considering tftp_init for cloning; -fipa-cp-clone disabled.
Not considering tftp_tmr for cloning; -fipa-cp-clone disabled.
Not considering recv for cloning; -fipa-cp-clone disabled.

overall_size: 531, max_new_size: 11001
 - context independent values, size: 26, time_benefit: 1.000000
 - context independent values, size: 289, time_benefit: 2.000000

IPA lattices after all propagation:

Lattices:
  Node: tftp_tmr.part.0/30:
  Node: tftp_cleanup/10:
  Node: tftp_init/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tftp_tmr/8:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: recv/7:
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
  Node: send_data/6:
  Node: resend_data/5:
  Node: send_ack/4:
    param [0]: VARIABLE
               0 [loc_time: 1, loc_size: 25, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: send_error/3:
    param [0]: VARIABLE
               &tftp_state.addr [loc_time: 1, loc_size: 34, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 1 [loc_time: 1, loc_size: 34, prop_time: 0, prop_size: 0]
               2 [loc_time: 1, loc_size: 34, prop_time: 0, prop_size: 0]
               5 [loc_time: 1, loc_size: 34, prop_time: 0, prop_size: 0]
               4 [loc_time: 1, loc_size: 34, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x4, mask = 0x7
         tftp_error [1, 5]
        AGGS VARIABLE
    param [3]: BOTTOM
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const char * ~[0B, 0B]
        AGGS VARIABLE
  Node: close_handle/2:

IPA decision stage:

Propagated bits info for function send_error/3:
 param 2: value = 0x4, mask = 0x7

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

tftp_tmr.part.0/30 (tftp_tmr.part.0) @06b308c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: tftp_state/1 (read)tftp_state/1 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tftp_tmr/8 (101011258 (estimated locally),0.09 per call) 
  Calls: resend_data/5 (1073741824 (estimated locally),1.00 per call) 
memset/29 (memset) @06d5c1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tftp_cleanup/10 (123389 (estimated locally),0.53 per call) 
  Calls: 
memcpy/28 (memcpy) @06d5c000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: send_error/3 (741418730 (estimated locally),0.69 per call) 
  Calls: 
strlen/27 (strlen) @06d0e9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: send_error/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
sys_untimeout/26 (sys_untimeout) @06d0e000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: close_handle/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pbuf_realloc/25 (pbuf_realloc) @06d0e0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: send_data/6 (545980753 (estimated locally),0.51 per call) 
  Calls: 
udp_sendto/24 (udp_sendto) @06d0ed20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: send_error/3 (741418730 (estimated locally),0.69 per call) send_ack/4 (741418730 (estimated locally),0.69 per call) resend_data/5 (489336361 (estimated locally),0.46 per call) 
  Calls: 
pbuf_copy/23 (pbuf_copy) @06d0ec40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: resend_data/5 (741418730 (estimated locally),0.69 per call) 
  Calls: 
pbuf_alloc/22 (pbuf_alloc) @06d0eb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: send_data/6 (1073741824 (estimated locally),1.00 per call) send_error/3 (1073741824 (estimated locally),1.00 per call) send_ack/4 (1073741824 (estimated locally),1.00 per call) resend_data/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pbuf_remove_header/21 (pbuf_remove_header) @06d0e7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: recv/7 (7305362 (estimated locally),0.01 per call) 
  Calls: 
lwip_htons/20 (lwip_htons) @06d0e700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: recv/7 (53078952 (estimated locally),0.05 per call) recv/7 (36093688 (estimated locally),0.03 per call) send_data/6 (741418730 (estimated locally),0.69 per call) send_error/3 (741418730 (estimated locally),0.69 per call) send_ack/4 (741418730 (estimated locally),0.69 per call) 
  Calls: 
pbuf_copy_partial/19 (pbuf_copy_partial) @06d0e620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: recv/7 (9642537 (estimated locally),0.01 per call) recv/7 (19285074 (estimated locally),0.02 per call) 
  Calls: 
pbuf_memfind/18 (pbuf_memfind) @06d0e540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: recv/7 (19285074 (estimated locally),0.02 per call) recv/7 (38570148 (estimated locally),0.04 per call) 
  Calls: 
sys_timeout/17 (sys_timeout) @06d0e460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: recv/7 (38570148 (estimated locally),0.04 per call) tftp_tmr/8 (741418730 (estimated locally),0.69 per call) 
  Calls: 
pbuf_free/16 (pbuf_free) @06d0e380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: recv/7 (514268646 (estimated locally),0.48 per call) recv/7 (559473178 (estimated locally),0.52 per call) send_data/6 (574129754 (estimated locally),0.53 per call) send_error/3 (741418730 (estimated locally),0.69 per call) close_handle/2 (574129754 (estimated locally),0.53 per call) send_ack/4 (741418730 (estimated locally),0.69 per call) resend_data/5 (489336361 (estimated locally),0.46 per call) resend_data/5 (252082368 (estimated locally),0.23 per call) 
  Calls: 
udp_recv/15 (udp_recv) @06d007e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tftp_init/9 (702220711 (estimated locally),0.65 per call) 
  Calls: 
udp_remove/14 (udp_remove) @06d002a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tftp_cleanup/10 (123389 (estimated locally),0.53 per call) tftp_init/9 (361750063 (estimated locally),0.34 per call) 
  Calls: 
ip_addr_any_type/13 (ip_addr_any_type) @06ce4c18
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: tftp_init/9 (addr)
  Availability: not_available
  Varpool flags: read-only
udp_bind/12 (udp_bind) @06d00ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tftp_init/9 (1063970774 (estimated locally),0.99 per call) 
  Calls: 
udp_new_ip_type/11 (udp_new_ip_type) @06d00e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tftp_init/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tftp_cleanup/10 (tftp_cleanup) @06d009a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tftp_state/1 (read)tftp_state/1 (addr)
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: memset/29 (123389 (estimated locally),0.53 per call) close_handle/2 (123389 (estimated locally),0.53 per call) udp_remove/14 (123389 (estimated locally),0.53 per call) 
tftp_init/9 (tftp_init) @06d00700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any_type/13 (addr)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)recv/7 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: udp_recv/15 (702220711 (estimated locally),0.65 per call) udp_remove/14 (361750063 (estimated locally),0.34 per call) udp_bind/12 (1063970774 (estimated locally),0.99 per call) udp_new_ip_type/11 (1073741824 (estimated locally),1.00 per call) 
tftp_tmr/8 (tftp_tmr) @06d00460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: tftp_state/1 (read)tftp_state/1 (write)tftp_state/1 (read)tftp_tmr/8 (addr)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)
  Referring: close_handle/2 (addr)tftp_tmr/8 (addr)recv/7 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: close_handle/2 (269698106 (estimated locally),0.25 per call) tftp_tmr.part.0/30 (101011258 (estimated locally),0.09 per call) sys_timeout/17 (741418730 (estimated locally),0.69 per call) 
recv/7 (recv) @06d001c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (read)tftp_tmr/8 (addr)tftp_state/1 (read)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (write)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (write)
  Referring: tftp_init/9 (addr)
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/16 (514268646 (estimated locally),0.48 per call) send_error/3 (128567161 (estimated locally),0.12 per call) close_handle/2 (7393489 (estimated locally),0.01 per call) send_data/6 (19740472 (estimated locally),0.02 per call) send_error/3 (25944992 (estimated locally),0.02 per call) lwip_htons/20 (53078952 (estimated locally),0.05 per call) send_error/3 (53078952 (estimated locally),0.05 per call) send_error/3 (22409256 (estimated locally),0.02 per call) send_error/3 (19000295 (estimated locally),0.02 per call) send_ack/4 (9788031 (estimated locally),0.01 per call) close_handle/2 (2410770 (estimated locally),0.00 per call) send_ack/4 (4310164 (estimated locally),0.00 per call) close_handle/2 (2995199 (estimated locally),0.00 per call) send_error/3 (2995199 (estimated locally),0.00 per call) pbuf_remove_header/21 (7305362 (estimated locally),0.01 per call) lwip_htons/20 (36093688 (estimated locally),0.03 per call) send_error/3 (70064217 (estimated locally),0.07 per call) send_error/3 (22409256 (estimated locally),0.02 per call) send_data/6 (5254816 (estimated locally),0.00 per call) send_ack/4 (2707027 (estimated locally),0.00 per call) send_error/3 (1680694 (estimated locally),0.00 per call) pbuf_copy_partial/19 (9642537 (estimated locally),0.01 per call) send_error/3 (9642537 (estimated locally),0.01 per call) pbuf_memfind/18 (19285074 (estimated locally),0.02 per call) pbuf_copy_partial/19 (19285074 (estimated locally),0.02 per call) send_error/3 (19285074 (estimated locally),0.02 per call) pbuf_memfind/18 (38570148 (estimated locally),0.04 per call) sys_timeout/17 (38570148 (estimated locally),0.04 per call) send_error/3 (89997013 (estimated locally),0.08 per call) pbuf_free/16 (559473178 (estimated locally),0.52 per call) send_error/3 (559473178 (estimated locally),0.52 per call) 
   Indirect call(7305362 (estimated locally),0.01 per call) 
   Indirect call(9642537 (estimated locally),0.01 per call) 
send_data/6 (send_data) @06cdda80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tftp_state/1 (read)tftp_state/1 (write)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (addr)tftp_state/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: recv/7 (19740472 (estimated locally),0.02 per call) recv/7 (5254816 (estimated locally),0.00 per call) 
  Calls: resend_data/5 (545980753 (estimated locally),0.51 per call) pbuf_realloc/25 (545980753 (estimated locally),0.51 per call) close_handle/2 (195437977 (estimated locally),0.18 per call) send_error/3 (195437977 (estimated locally),0.18 per call) lwip_htons/20 (741418730 (estimated locally),0.69 per call) pbuf_alloc/22 (1073741824 (estimated locally),1.00 per call) pbuf_free/16 (574129754 (estimated locally),0.53 per call) 
   Indirect call(741418730 (estimated locally),0.69 per call) 
resend_data/5 (resend_data) @06cdd7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: send_data/6 (545980753 (estimated locally),0.51 per call) tftp_tmr.part.0/30 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_free/16 (489336361 (estimated locally),0.46 per call) udp_sendto/24 (489336361 (estimated locally),0.46 per call) pbuf_free/16 (252082368 (estimated locally),0.23 per call) pbuf_copy/23 (741418730 (estimated locally),0.69 per call) pbuf_alloc/22 (1073741824 (estimated locally),1.00 per call) 
send_ack/4 (send_ack) @06cdd540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: recv/7 (9788031 (estimated locally),0.01 per call) recv/7 (4310164 (estimated locally),0.00 per call) recv/7 (2707027 (estimated locally),0.00 per call) 
  Calls: pbuf_free/16 (741418730 (estimated locally),0.69 per call) udp_sendto/24 (741418730 (estimated locally),0.69 per call) lwip_htons/20 (741418730 (estimated locally),0.69 per call) pbuf_alloc/22 (1073741824 (estimated locally),1.00 per call) 
send_error/3 (send_error) @06cdd2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tftp_state/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: recv/7 (128567161 (estimated locally),0.12 per call) recv/7 (25944992 (estimated locally),0.02 per call) recv/7 (53078952 (estimated locally),0.05 per call) recv/7 (22409256 (estimated locally),0.02 per call) recv/7 (19000295 (estimated locally),0.02 per call) recv/7 (2995199 (estimated locally),0.00 per call) recv/7 (70064217 (estimated locally),0.07 per call) recv/7 (22409256 (estimated locally),0.02 per call) recv/7 (1680694 (estimated locally),0.00 per call) recv/7 (9642537 (estimated locally),0.01 per call) recv/7 (19285074 (estimated locally),0.02 per call) recv/7 (89997013 (estimated locally),0.08 per call) recv/7 (559473178 (estimated locally),0.52 per call) send_data/6 (195437977 (estimated locally),0.18 per call) 
  Calls: pbuf_free/16 (741418730 (estimated locally),0.69 per call) udp_sendto/24 (741418730 (estimated locally),0.69 per call) memcpy/28 (741418730 (estimated locally),0.69 per call) lwip_htons/20 (741418730 (estimated locally),0.69 per call) pbuf_alloc/22 (1073741824 (estimated locally),1.00 per call) strlen/27 (1073741824 (estimated locally),1.00 per call) 
close_handle/2 (close_handle) @06cd8ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (write)tftp_state/1 (read)tftp_state/1 (write)tftp_tmr/8 (addr)tftp_state/1 (read)tftp_state/1 (read)tftp_state/1 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: tftp_cleanup/10 (123389 (estimated locally),0.53 per call) recv/7 (7393489 (estimated locally),0.01 per call) recv/7 (2410770 (estimated locally),0.00 per call) recv/7 (2995199 (estimated locally),0.00 per call) send_data/6 (195437977 (estimated locally),0.18 per call) tftp_tmr/8 (269698106 (estimated locally),0.25 per call) 
  Calls: sys_untimeout/26 (1073741824 (estimated locally),1.00 per call) pbuf_free/16 (574129754 (estimated locally),0.53 per call) 
   Indirect call(751619278 (estimated locally),0.70 per call) 
tftp_state/1 (tftp_state) @06cd3ca8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: send_data/6 (read)send_data/6 (read)send_data/6 (read)send_data/6 (read)send_data/6 (addr)send_data/6 (read)tftp_tmr/8 (read)tftp_tmr/8 (write)tftp_tmr/8 (read)tftp_tmr/8 (read)tftp_tmr/8 (read)tftp_tmr/8 (read)send_error/3 (read)close_handle/2 (write)send_data/6 (read)send_data/6 (write)recv/7 (write)resend_data/5 (read)resend_data/5 (read)send_ack/4 (read)send_ack/4 (read)send_ack/4 (addr)resend_data/5 (addr)close_handle/2 (write)recv/7 (read)recv/7 (read)recv/7 (write)tftp_init/9 (write)tftp_init/9 (write)tftp_init/9 (write)tftp_tmr.part.0/30 (read)close_handle/2 (write)close_handle/2 (write)close_handle/2 (write)close_handle/2 (write)close_handle/2 (write)close_handle/2 (read)close_handle/2 (write)close_handle/2 (read)close_handle/2 (read)tftp_tmr/8 (read)recv/7 (read)resend_data/5 (read)resend_data/5 (read)recv/7 (read)close_handle/2 (write)tftp_tmr.part.0/30 (write)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (write)recv/7 (write)recv/7 (read)recv/7 (read)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (write)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)recv/7 (read)tftp_init/9 (write)tftp_init/9 (write)tftp_init/9 (write)tftp_cleanup/10 (read)tftp_cleanup/10 (addr)
  Availability: available
  Varpool flags:

;; Function resend_data (resend_data, funcdef_no=4, decl_uid=7230, cgraph_uid=5, symbol_order=5)

Modification phase of node resend_data/5
resend_data ()
{
  struct pbuf * p;
  struct pbuf * _1;
  short unsigned int _2;
  struct pbuf * _3;
  signed char _4;
  struct udp_pcb * _5;
  short unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = tftp_state.last_data;
  _2 = _1->len;
  p_10 = pbuf_alloc (74, _2, 640);
  # DEBUG p => p_10
  # DEBUG BEGIN_STMT
  if (p_10 == 0B)
    goto <bb 6>; [30.95%]
  else
    goto <bb 3>; [69.05%]

  <bb 3> [local count: 741418730]:
  # DEBUG BEGIN_STMT
  _3 = tftp_state.last_data;
  _4 = pbuf_copy (p_10, _3);
  if (_4 != 0)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 252082368]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_10);
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 489336361]:
  # DEBUG BEGIN_STMT
  _5 = tftp_state.upcb;
  _6 = tftp_state.port;
  udp_sendto (_5, p_10, &tftp_state.addr, _6);
  # DEBUG BEGIN_STMT
  pbuf_free (p_10);

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function send_ack (send_ack, funcdef_no=3, decl_uid=7225, cgraph_uid=4, symbol_order=4)

Modification phase of node send_ack/4
send_ack (u16_t blknum)
{
  u16_t * payload;
  struct pbuf * p;
  short unsigned int _1;
  struct udp_pcb * _2;
  short unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  p_7 = pbuf_alloc (74, 4, 640);
  # DEBUG p => p_7
  # DEBUG BEGIN_STMT
  if (p_7 == 0B)
    goto <bb 4>; [30.95%]
  else
    goto <bb 3>; [69.05%]

  <bb 3> [local count: 741418730]:
  # DEBUG BEGIN_STMT
  payload_8 = p_7->payload;
  # DEBUG payload => payload_8
  # DEBUG BEGIN_STMT
  *payload_8 = 1024;
  # DEBUG BEGIN_STMT
  _1 = lwip_htons (blknum_10(D));
  MEM[(u16_t *)payload_8 + 2B] = _1;
  # DEBUG BEGIN_STMT
  _2 = tftp_state.upcb;
  _3 = tftp_state.port;
  udp_sendto (_2, p_7, &tftp_state.addr, _3);
  # DEBUG BEGIN_STMT
  pbuf_free (p_7);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function close_handle (close_handle, funcdef_no=1, decl_uid=7213, cgraph_uid=2, symbol_order=2)

Modification phase of node close_handle/2
close_handle ()
{
  struct pbuf * _1;
  void * _2;
  const struct tftp_context * _3;
  void (*<Te3>) (void *) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  tftp_state.port = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tftp_state.addr.u_addr.ip4.addr = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tftp_state.addr.type = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tftp_state.addr.u_addr.ip6.addr[3] = 0;
  tftp_state.addr.u_addr.ip6.addr[2] = 0;
  tftp_state.addr.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  tftp_state.addr.u_addr.ip6.zone = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = tftp_state.last_data;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pbuf_free (_1);
  # DEBUG BEGIN_STMT
  tftp_state.last_data = 0B;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  sys_untimeout (tftp_tmr, 0B);
  # DEBUG BEGIN_STMT
  _2 = tftp_state.handle;
  if (_2 != 0B)
    goto <bb 5>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 5> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _3 = tftp_state.ctx;
  _4 = _3->close;
  _4 (_2);
  # DEBUG BEGIN_STMT
  tftp_state.handle = 0B;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function send_error (send_error, funcdef_no=2, decl_uid=7219, cgraph_uid=3, symbol_order=3)

Modification phase of node send_error/3
Adjusting mask for param 2 to 0x7
Setting value range of param 2 [1, 5]
Setting nonnull for 3
send_error (const struct ip_addr_t * addr, u16_t port, tftp_error code, const char * str)
{
  u16_t * payload;
  struct pbuf * p;
  int str_length;
  unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  u16_t * _6;
  int _7;
  unsigned int _8;
  struct udp_pcb * _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = strlen (str_12(D));
  str_length_13 = (int) _1;
  # DEBUG str_length => str_length_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = (short unsigned int) _1;
  _3 = _2 + 5;
  p_15 = pbuf_alloc (74, _3, 640);
  # DEBUG p => p_15
  # DEBUG BEGIN_STMT
  if (p_15 == 0B)
    goto <bb 4>; [30.95%]
  else
    goto <bb 3>; [69.05%]

  <bb 3> [local count: 741418730]:
  # DEBUG BEGIN_STMT
  payload_16 = p_15->payload;
  # DEBUG payload => payload_16
  # DEBUG BEGIN_STMT
  *payload_16 = 1280;
  # DEBUG BEGIN_STMT
  _4 = (short unsigned int) code_18(D);
  _5 = lwip_htons (_4);
  MEM[(u16_t *)payload_16 + 2B] = _5;
  # DEBUG BEGIN_STMT
  _6 = payload_16 + 4;
  _7 = str_length_13 + 1;
  _8 = (unsigned int) _7;
  memcpy (_6, str_12(D), _8);
  # DEBUG BEGIN_STMT
  _9 = tftp_state.upcb;
  udp_sendto (_9, p_15, addr_22(D), port_23(D));
  # DEBUG BEGIN_STMT
  pbuf_free (p_15);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function send_data (send_data, funcdef_no=5, decl_uid=7234, cgraph_uid=6, symbol_order=6)

Modification phase of node send_data/6
send_data ()
{
  int ret;
  u16_t * payload;
  struct pbuf * _1;
  struct pbuf * _2;
  short unsigned int _3;
  short unsigned int _4;
  const struct tftp_context * _5;
  int (*<T644>) (void *, void *, int) _6;
  void * _7;
  u16_t * _8;
  short unsigned int _9;
  struct pbuf * _10;
  short unsigned int _11;
  short unsigned int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = tftp_state.last_data;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pbuf_free (_1);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = pbuf_alloc (74, 516, 640);
  tftp_state.last_data = _2;
  # DEBUG BEGIN_STMT
  if (_2 == 0B)
    goto <bb 8>; [30.95%]
  else
    goto <bb 5>; [69.05%]

  <bb 5> [local count: 741418730]:
  # DEBUG BEGIN_STMT
  payload_19 = _2->payload;
  # DEBUG payload => payload_19
  # DEBUG BEGIN_STMT
  *payload_19 = 768;
  # DEBUG BEGIN_STMT
  _3 = tftp_state.blknum;
  _4 = lwip_htons (_3);
  MEM[(u16_t *)payload_19 + 2B] = _4;
  # DEBUG BEGIN_STMT
  _5 = tftp_state.ctx;
  _6 = _5->read;
  _7 = tftp_state.handle;
  _8 = payload_19 + 4;
  ret_24 = _6 (_7, _8, 512);
  # DEBUG ret => ret_24
  # DEBUG BEGIN_STMT
  if (ret_24 < 0)
    goto <bb 6>; [26.36%]
  else
    goto <bb 7>; [73.64%]

  <bb 6> [local count: 195437977]:
  # DEBUG BEGIN_STMT
  _9 = tftp_state.port;
  send_error (&tftp_state.addr, _9, 2, "Error occured while reading the file.");
  # DEBUG BEGIN_STMT
  close_handle ();
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 545980753]:
  # DEBUG BEGIN_STMT
  _10 = tftp_state.last_data;
  _11 = (short unsigned int) ret_24;
  _12 = _11 + 4;
  pbuf_realloc (_10, _12);
  # DEBUG BEGIN_STMT
  resend_data ();

  <bb 8> [local count: 1073741824]:
  return;

}



;; Function recv (recv, funcdef_no=6, decl_uid=7243, cgraph_uid=7, symbol_order=7)

Modification phase of node recv/7
recv (void * arg, struct udp_pcb * upcb, struct pbuf * p, const struct ip_addr_t * addr, u16_t port)
{
  u16_t blknum;
  u16_t blknum;
  int ret;
  u16_t mode_end_offset;
  u16_t filename_end_offset;
  char mode[8];
  char filename[21];
  const char tftp_null;
  int opcode;
  u16_t * sbuf;
  short unsigned int _1;
  unsigned char _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  _Bool _7;
  long unsigned int _8;
  unsigned char _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  unsigned char _18;
  unsigned char _19;
  _Bool _20;
  long unsigned int _21;
  long unsigned int _22;
  short unsigned int _23;
  int _24;
  void * _25;
  short unsigned int _26;
  short unsigned int _27;
  short unsigned int _28;
  const struct tftp_context * _29;
  void * (*<T641>) (const char *, const char *, u8_t) _30;
  _Bool _31;
  unsigned char _32;
  void * _33;
  unsigned char _34;
  unsigned char _35;
  long unsigned int _36;
  long unsigned int _37;
  long unsigned int _38;
  long unsigned int _39;
  unsigned char _40;
  long unsigned int _41;
  void * _42;
  unsigned char _43;
  short unsigned int _44;
  short unsigned int _45;
  const struct tftp_context * _46;
  int (*<T646>) (void *, struct pbuf *) _47;
  void * _48;
  short unsigned int _49;
  short unsigned int _50;
  short unsigned int _51;
  short unsigned int _52;
  void * _53;
  unsigned char _54;
  short unsigned int _55;
  short unsigned int _56;
  struct pbuf * _57;
  short unsigned int _58;
  _Bool _59;
  short unsigned int _60;
  int iftmp.0_61;
  int iftmp.1_62;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  sbuf_70 = p_69(D)->payload;
  # DEBUG sbuf => sbuf_70
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = tftp_state.port;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870911]:
  if (_1 != port_71(D))
    goto <bb 22>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 805306368]:
  _2 = tftp_state.addr.type;
  if (_2 == 6)
    goto <bb 5>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 5> [local count: 273804165]:
  _3 = tftp_state.addr.u_addr.ip6.addr[0];
  if (_3 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 136902082]:
  _4 = tftp_state.addr.u_addr.ip6.addr[1];
  if (_4 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 68451041]:
  _5 = tftp_state.addr.u_addr.ip6.addr[2];
  if (_5 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 34225521]:
  _6 = tftp_state.addr.u_addr.ip6.addr[3];
  if (_6 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 17112760]:

  <bb 10> [local count: 273804165]:
  # iftmp.0_61 = PHI <1(6), 0(9), 1(5), 1(8), 1(7)>
  _7 = (_Bool) iftmp.0_61;
  if (_7 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 11> [local count: 531502202]:
  _8 = tftp_state.addr.u_addr.ip4.addr;
  if (_8 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 12> [local count: 402653184]:
  _9 = addr_72(D)->type;
  if (_2 == _9)
    goto <bb 13>; [50.00%]
  else
    goto <bb 22>; [50.00%]

  <bb 13> [local count: 201326592]:
  if (_2 == 6)
    goto <bb 14>; [34.00%]
  else
    goto <bb 21>; [66.00%]

  <bb 14> [local count: 68451041]:
  _10 = tftp_state.addr.u_addr.ip6.addr[0];
  _11 = addr_72(D)->u_addr.ip6.addr[0];
  if (_10 != _11)
    goto <bb 20>; [66.00%]
  else
    goto <bb 15>; [34.00%]

  <bb 15> [local count: 23273354]:
  _12 = tftp_state.addr.u_addr.ip6.addr[1];
  _13 = addr_72(D)->u_addr.ip6.addr[1];
  if (_12 != _13)
    goto <bb 20>; [66.00%]
  else
    goto <bb 16>; [34.00%]

  <bb 16> [local count: 7912940]:
  _14 = tftp_state.addr.u_addr.ip6.addr[2];
  _15 = addr_72(D)->u_addr.ip6.addr[2];
  if (_14 != _15)
    goto <bb 20>; [66.00%]
  else
    goto <bb 17>; [34.00%]

  <bb 17> [local count: 2690400]:
  _16 = tftp_state.addr.u_addr.ip6.addr[3];
  _17 = addr_72(D)->u_addr.ip6.addr[3];
  if (_16 != _17)
    goto <bb 20>; [66.00%]
  else
    goto <bb 18>; [34.00%]

  <bb 18> [local count: 914736]:
  _18 = tftp_state.addr.u_addr.ip6.zone;
  _19 = addr_72(D)->u_addr.ip6.zone;
  if (_18 != _19)
    goto <bb 20>; [66.00%]
  else
    goto <bb 19>; [34.00%]

  <bb 19> [local count: 311010]:

  <bb 20> [local count: 68451041]:
  # iftmp.1_62 = PHI <1(15), 0(19), 1(14), 1(18), 1(17), 1(16)>
  _20 = (_Bool) iftmp.1_62;
  if (_20 != 0)
    goto <bb 22>; [34.00%]
  else
    goto <bb 23>; [66.00%]

  <bb 21> [local count: 132875550]:
  _21 = tftp_state.addr.u_addr.ip4.addr;
  _22 = addr_72(D)->u_addr.ip4.addr;
  if (_21 != _22)
    goto <bb 22>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 22> [local count: 559473178]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 2, "Only one connection at a time is supported");
  # DEBUG BEGIN_STMT
  pbuf_free (p_69(D));
  # DEBUG BEGIN_STMT
  goto <bb 65>; [100.00%]

  <bb 23> [local count: 514268646]:
  # DEBUG BEGIN_STMT
  _23 = *sbuf_70;
  opcode_73 = (int) _23;
  # DEBUG opcode => opcode_73
  # DEBUG BEGIN_STMT
  _24 = tftp_state.timer;
  tftp_state.last_pkt = _24;
  # DEBUG BEGIN_STMT
  tftp_state.retries = 0;
  # DEBUG BEGIN_STMT
  switch (_23) <default: <L77> [25.00%], case 256: <L26> [25.00%], case 512: <L26> [25.00%], case 768: <L48> [25.00%], case 1024: <L65> [25.00%]>

  <bb 24> [local count: 128567161]:
<L26>:
  # DEBUG BEGIN_STMT
  tftp_null = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 = tftp_state.handle;
  if (_25 != 0B)
    goto <bb 25>; [70.00%]
  else
    goto <bb 26>; [30.00%]

  <bb 25> [local count: 89997013]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 2, "Only one connection at a time is supported");
  # DEBUG BEGIN_STMT
  goto <bb 38>; [100.00%]

  <bb 26> [local count: 38570148]:
  # DEBUG BEGIN_STMT
  sys_timeout (1000, tftp_tmr, 0B);
  # DEBUG BEGIN_STMT
  filename_end_offset_101 = pbuf_memfind (p_69(D), &tftp_null, 1, 2);
  # DEBUG filename_end_offset => filename_end_offset_101
  # DEBUG BEGIN_STMT
  _26 = filename_end_offset_101 + 65535;
  if (_26 > 21)
    goto <bb 27>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 27> [local count: 19285074]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 2, "Filename too long/not NULL terminated");
  # DEBUG BEGIN_STMT
  goto <bb 38>; [100.00%]

  <bb 28> [local count: 19285074]:
  # DEBUG BEGIN_STMT
  pbuf_copy_partial (p_69(D), &filename, _26, 2);
  # DEBUG BEGIN_STMT
  _27 = filename_end_offset_101 + 1;
  mode_end_offset_104 = pbuf_memfind (p_69(D), &tftp_null, 1, _27);
  # DEBUG mode_end_offset => mode_end_offset_104
  # DEBUG BEGIN_STMT
  _28 = mode_end_offset_104 - filename_end_offset_101;
  if (_28 > 8)
    goto <bb 29>; [50.00%]
  else
    goto <bb 30>; [50.00%]

  <bb 29> [local count: 9642537]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 2, "Mode too long/not NULL terminated");
  # DEBUG BEGIN_STMT
  goto <bb 38>; [100.00%]

  <bb 30> [local count: 9642537]:
  # DEBUG BEGIN_STMT
  pbuf_copy_partial (p_69(D), &mode, _28, _27);
  # DEBUG BEGIN_STMT
  _29 = tftp_state.ctx;
  _30 = _29->open;
  _31 = opcode_73 == 512;
  _32 = (unsigned char) _31;
  _33 = _30 (&filename, &mode, _32);
  tftp_state.handle = _33;
  # DEBUG BEGIN_STMT
  tftp_state.blknum = 1;
  # DEBUG BEGIN_STMT
  if (_33 == 0B)
    goto <bb 31>; [17.43%]
  else
    goto <bb 32>; [82.57%]

  <bb 31> [local count: 1680694]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 1, "Unable to open requested file.");
  # DEBUG BEGIN_STMT
  goto <bb 38>; [100.00%]

  <bb 32> [local count: 7961843]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _34 = addr_72(D)->type;
  tftp_state.addr.type = _34;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _35 = addr_72(D)->type;
  if (_35 == 6)
    goto <bb 33>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 33> [local count: 2707027]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _36 = addr_72(D)->u_addr.ip6.addr[0];
  tftp_state.addr.u_addr.ip6.addr[0] = _36;
  # DEBUG BEGIN_STMT
  _37 = addr_72(D)->u_addr.ip6.addr[1];
  tftp_state.addr.u_addr.ip6.addr[1] = _37;
  # DEBUG BEGIN_STMT
  _38 = addr_72(D)->u_addr.ip6.addr[2];
  tftp_state.addr.u_addr.ip6.addr[2] = _38;
  # DEBUG BEGIN_STMT
  _39 = addr_72(D)->u_addr.ip6.addr[3];
  tftp_state.addr.u_addr.ip6.addr[3] = _39;
  # DEBUG BEGIN_STMT
  _40 = addr_72(D)->u_addr.ip6.zone;
  tftp_state.addr.u_addr.ip6.zone = _40;
  # DEBUG BEGIN_STMT
  goto <bb 35>; [100.00%]

  <bb 34> [local count: 5254816]:
  # DEBUG BEGIN_STMT
  _41 = addr_72(D)->u_addr.ip4.addr;
  tftp_state.addr.u_addr.ip4.addr = _41;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tftp_state.addr.u_addr.ip6.addr[3] = 0;
  tftp_state.addr.u_addr.ip6.addr[2] = 0;
  tftp_state.addr.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  tftp_state.addr.u_addr.ip6.zone = 0;

  <bb 35> [local count: 7961843]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tftp_state.port = port_71(D);
  # DEBUG BEGIN_STMT
  if (opcode_73 == 512)
    goto <bb 36>; [34.00%]
  else
    goto <bb 37>; [66.00%]

  <bb 36> [local count: 2707027]:
  # DEBUG BEGIN_STMT
  tftp_state.mode_write = 1;
  # DEBUG BEGIN_STMT
  send_ack (0);
  goto <bb 38>; [100.00%]

  <bb 37> [local count: 5254816]:
  # DEBUG BEGIN_STMT
  tftp_state.mode_write = 0;
  # DEBUG BEGIN_STMT
  send_data ();

  <bb 38> [local count: 128567162]:
  tftp_null ={v} {CLOBBER};
  filename ={v} {CLOBBER};
  mode ={v} {CLOBBER};
  goto <bb 64>; [100.00%]

  <bb 39> [local count: 128567161]:
<L48>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _42 = tftp_state.handle;
  if (_42 == 0B)
    goto <bb 40>; [17.43%]
  else
    goto <bb 41>; [82.57%]

  <bb 40> [local count: 22409256]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 2, "No connection");
  # DEBUG BEGIN_STMT
  goto <bb 64>; [100.00%]

  <bb 41> [local count: 106157905]:
  # DEBUG BEGIN_STMT
  _43 = tftp_state.mode_write;
  if (_43 != 1)
    goto <bb 42>; [66.00%]
  else
    goto <bb 43>; [34.00%]

  <bb 42> [local count: 70064217]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 2, "Not a write connection");
  # DEBUG BEGIN_STMT
  goto <bb 64>; [100.00%]

  <bb 43> [local count: 36093688]:
  # DEBUG BEGIN_STMT
  _44 = MEM[(u16_t *)sbuf_70 + 2B];
  blknum_85 = lwip_htons (_44);
  # DEBUG blknum => blknum_85
  # DEBUG BEGIN_STMT
  _45 = tftp_state.blknum;
  if (_45 == blknum_85)
    goto <bb 44>; [20.24%]
  else
    goto <bb 50>; [79.76%]

  <bb 44> [local count: 7305362]:
  # DEBUG BEGIN_STMT
  pbuf_remove_header (p_69(D), 4);
  # DEBUG BEGIN_STMT
  _46 = tftp_state.ctx;
  _47 = _46->write;
  _48 = tftp_state.handle;
  ret_90 = _47 (_48, p_69(D));
  # DEBUG ret => ret_90
  # DEBUG BEGIN_STMT
  if (ret_90 < 0)
    goto <bb 45>; [41.00%]
  else
    goto <bb 46>; [59.00%]

  <bb 45> [local count: 2995199]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 2, "error writing file");
  # DEBUG BEGIN_STMT
  close_handle ();
  goto <bb 47>; [100.00%]

  <bb 46> [local count: 4310164]:
  # DEBUG BEGIN_STMT
  send_ack (blknum_85);

  <bb 47> [local count: 7305362]:
  # DEBUG BEGIN_STMT
  _49 = p_69(D)->tot_len;
  if (_49 <= 511)
    goto <bb 48>; [33.00%]
  else
    goto <bb 49>; [67.00%]

  <bb 48> [local count: 2410770]:
  # DEBUG BEGIN_STMT
  close_handle ();
  goto <bb 64>; [100.00%]

  <bb 49> [local count: 4894593]:
  # DEBUG BEGIN_STMT
  _50 = tftp_state.blknum;
  _51 = _50 + 1;
  tftp_state.blknum = _51;
  goto <bb 64>; [100.00%]

  <bb 50> [local count: 28788325]:
  # DEBUG BEGIN_STMT
  _52 = blknum_85 + 1;
  if (_45 == _52)
    goto <bb 51>; [34.00%]
  else
    goto <bb 52>; [66.00%]

  <bb 51> [local count: 9788031]:
  # DEBUG BEGIN_STMT
  send_ack (blknum_85);
  goto <bb 64>; [100.00%]

  <bb 52> [local count: 19000295]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 5, "Wrong block number");
  goto <bb 64>; [100.00%]

  <bb 53> [local count: 128567161]:
<L65>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _53 = tftp_state.handle;
  if (_53 == 0B)
    goto <bb 54>; [17.43%]
  else
    goto <bb 55>; [82.57%]

  <bb 54> [local count: 22409256]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 2, "No connection");
  # DEBUG BEGIN_STMT
  goto <bb 64>; [100.00%]

  <bb 55> [local count: 106157905]:
  # DEBUG BEGIN_STMT
  _54 = tftp_state.mode_write;
  if (_54 != 0)
    goto <bb 56>; [50.00%]
  else
    goto <bb 57>; [50.00%]

  <bb 56> [local count: 53078952]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 2, "Not a read connection");
  # DEBUG BEGIN_STMT
  goto <bb 64>; [100.00%]

  <bb 57> [local count: 53078952]:
  # DEBUG BEGIN_STMT
  _55 = MEM[(u16_t *)sbuf_70 + 2B];
  blknum_77 = lwip_htons (_55);
  # DEBUG blknum => blknum_77
  # DEBUG BEGIN_STMT
  _56 = tftp_state.blknum;
  if (_56 != blknum_77)
    goto <bb 58>; [48.88%]
  else
    goto <bb 59>; [51.12%]

  <bb 58> [local count: 25944992]:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 5, "Wrong block number");
  # DEBUG BEGIN_STMT
  goto <bb 64>; [100.00%]

  <bb 59> [local count: 27133960]:
  # DEBUG BEGIN_STMT
  # DEBUG lastpkt => 0
  # DEBUG BEGIN_STMT
  _57 = tftp_state.last_data;
  if (_57 != 0B)
    goto <bb 60>; [82.57%]
  else
    goto <bb 61>; [17.43%]

  <bb 60> [local count: 22404511]:
  # DEBUG BEGIN_STMT
  _58 = _57->tot_len;
  _59 = _58 != 516;
  # DEBUG lastpkt => (int) _59
  # DEBUG BEGIN_STMT
  if (_59 == 0)
    goto <bb 61>; [67.00%]
  else
    goto <bb 62>; [33.00%]

  <bb 61> [local count: 19740472]:
  # DEBUG lastpkt => NULL
  # DEBUG BEGIN_STMT
  _60 = _56 + 1;
  tftp_state.blknum = _60;
  # DEBUG BEGIN_STMT
  send_data ();
  goto <bb 64>; [100.00%]

  <bb 62> [local count: 7393489]:
  # DEBUG BEGIN_STMT
  close_handle ();
  goto <bb 64>; [100.00%]

  <bb 63> [local count: 128567161]:
<L77>:
  # DEBUG BEGIN_STMT
  send_error (addr_72(D), port_71(D), 4, "Unknown operation");
  # DEBUG BEGIN_STMT

  <bb 64> [local count: 514268646]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_69(D));

  <bb 65> [local count: 1073741824]:
  return;

}



;; Function tftp_tmr (tftp_tmr, funcdef_no=7, decl_uid=7211, cgraph_uid=8, symbol_order=8)

Modification phase of node tftp_tmr/8
tftp_tmr (void * arg)
{
  int _1;
  int _2;
  void * _3;
  int _4;
  int _5;
  int _6;
  struct pbuf * _7;
  unsigned char _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = tftp_state.timer;
  _2 = _1 + 1;
  tftp_state.timer = _2;
  # DEBUG BEGIN_STMT
  _3 = tftp_state.handle;
  if (_3 == 0B)
    goto <bb 8>; [30.95%]
  else
    goto <bb 3>; [69.05%]

  <bb 3> [local count: 741418730]:
  # DEBUG BEGIN_STMT
  sys_timeout (1000, tftp_tmr, 0B);
  # DEBUG BEGIN_STMT
  _4 = tftp_state.timer;
  _5 = tftp_state.last_pkt;
  _6 = _4 - _5;
  if (_6 > 10)
    goto <bb 4>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 4> [local count: 370709364]:
  # DEBUG BEGIN_STMT
  _7 = tftp_state.last_data;
  if (_7 != 0B)
    goto <bb 5>; [82.57%]
  else
    goto <bb 7>; [17.43%]

  <bb 5> [local count: 306094722]:
  _8 = tftp_state.retries;
  if (_8 <= 4)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 101011258]:
  # DEBUG D#1 => arg_9(D)
  tftp_tmr.part.0 ();
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 269698106]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  close_handle ();

  <bb 8> [local count: 1073741824]:
  return;

}



;; Function tftp_init (tftp_init, funcdef_no=8, decl_uid=6409, cgraph_uid=9, symbol_order=9)

Modification phase of node tftp_init/9
tftp_init (const struct tftp_context * ctx)
{
  struct udp_pcb * pcb;
  err_t ret;
  err_t _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_5 = udp_new_ip_type (46);
  # DEBUG pcb => pcb_5
  # DEBUG BEGIN_STMT
  if (pcb_5 == 0B)
    goto <bb 6>; [0.91%]
  else
    goto <bb 3>; [99.09%]

  <bb 3> [local count: 1063970774]:
  # DEBUG BEGIN_STMT
  ret_7 = udp_bind (pcb_5, &ip_addr_any_type, 69);
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  if (ret_7 != 0)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 361750063]:
  # DEBUG BEGIN_STMT
  udp_remove (pcb_5);
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 702220711]:
  # DEBUG BEGIN_STMT
  tftp_state.handle = 0B;
  # DEBUG BEGIN_STMT
  tftp_state.port = 0;
  # DEBUG BEGIN_STMT
  tftp_state.ctx = ctx_10(D);
  # DEBUG BEGIN_STMT
  tftp_state.timer = 0;
  # DEBUG BEGIN_STMT
  tftp_state.last_data = 0B;
  # DEBUG BEGIN_STMT
  tftp_state.upcb = pcb_5;
  # DEBUG BEGIN_STMT
  udp_recv (pcb_5, recv, 0B);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # _1 = PHI <-1(2), ret_7(4), 0(5)>
  return _1;

}



;; Function tftp_cleanup (tftp_cleanup, funcdef_no=9, decl_uid=6411, cgraph_uid=10, symbol_order=10)

Modification phase of node tftp_cleanup/10
tftp_cleanup ()
{
  struct udp_pcb * _1;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = tftp_state.upcb;
  if (_1 == 0B)
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
  udp_remove (_1);
  # DEBUG BEGIN_STMT
  close_handle ();
  # DEBUG BEGIN_STMT
  memset (&tftp_state, 0, 56);
  return;

}


