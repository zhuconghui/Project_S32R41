
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  strcmp/10:
  Jump functions of caller  fs_bytes_left/9:
  Jump functions of caller  fs_close/8:
  Jump functions of caller  fs_open/7:

 Propagating constants:

Not considering fs_bytes_left for cloning; -fipa-cp-clone disabled.
Not considering fs_close for cloning; -fipa-cp-clone disabled.
Not considering fs_open for cloning; -fipa-cp-clone disabled.

overall_size: 34, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: fs_bytes_left/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: fs_close/8:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: fs_open/7:
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

strcmp/10 (strcmp) @0608a460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fs_open/7 (1014686025 (estimated locally),8.75 per call) 
  Calls: 
fs_bytes_left/9 (fs_bytes_left) @0608ab60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
fs_close/8 (fs_close) @0608a8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
fs_open/7 (fs_open) @0608a620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: file__index_html/6 (addr)
  Referring: 
  Availability: available
  Function flags: count:115904324 (estimated locally) body optimize_size
  Called by: 
  Calls: strcmp/10 (1014686025 (estimated locally),8.75 per call) 
file__index_html/6 (file__index_html) @0608b000
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: file__404_html/5 (addr)data__index_html/3 (addr)data__index_html/3 (addr)
  Referring: fs_open/7 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
file__404_html/5 (file__404_html) @06044b88
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: file__img_sics_gif/4 (addr)data__404_html/2 (addr)data__404_html/2 (addr)
  Referring: file__index_html/6 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
file__img_sics_gif/4 (file__img_sics_gif) @06044ee8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: data__img_sics_gif/1 (addr)data__img_sics_gif/1 (addr)
  Referring: file__404_html/5 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
data__index_html/3 (data__index_html) @06044e10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: file__index_html/6 (addr)file__index_html/6 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
data__404_html/2 (data__404_html) @06044cf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: file__404_html/5 (addr)file__404_html/5 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
data__img_sics_gif/1 (data__img_sics_gif) @06044bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: file__img_sics_gif/4 (addr)file__img_sics_gif/4 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function fs_open (fs_open, funcdef_no=1, decl_uid=6279, cgraph_uid=2, symbol_order=7)

Modification phase of node fs_open/7
fs_open (struct fs_file * file, const char * name)
{
  const struct fsdata_file * f;
  const unsigned char * _1;
  int _2;
  const unsigned char * _3;
  int _4;
  unsigned char _6;
  err_t _8;

  <bb 2> [local count: 115904324]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (file_10(D) == 0B)
    goto <bb 8>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 115382755]:
  if (name_11(D) == 0B)
    goto <bb 8>; [0.45%]
  else
    goto <bb 9>; [99.55%]

  <bb 9> [local count: 114863532]:
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _1 = f_7->name;
  _2 = strcmp (name_11(D), _1);
  if (_2 == 0)
    goto <bb 5>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 5> [local count: 55807731]:
  # f_5 = PHI <f_7(4)>
  # DEBUG BEGIN_STMT
  _3 = f_5->data;
  file_10(D)->data = _3;
  # DEBUG BEGIN_STMT
  _4 = f_5->len;
  file_10(D)->len = _4;
  # DEBUG BEGIN_STMT
  file_10(D)->index = _4;
  # DEBUG BEGIN_STMT
  file_10(D)->pextension = 0B;
  # DEBUG BEGIN_STMT
  _6 = f_5->flags;
  file_10(D)->flags = _6;
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  f_13 = f_7->next;
  # DEBUG f => f_13

  <bb 7> [local count: 1073741824]:
  # f_7 = PHI <f_13(6), &file__index_html(9)>
  # DEBUG f => f_7
  # DEBUG BEGIN_STMT
  if (f_7 != 0B)
    goto <bb 4>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 115904324]:
  # _8 = PHI <-16(3), 0(5), -6(7), -16(2)>
  return _8;

}



;; Function fs_close (fs_close, funcdef_no=2, decl_uid=6281, cgraph_uid=3, symbol_order=8)

Modification phase of node fs_close/8
fs_close (struct fs_file * file)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function fs_bytes_left (fs_bytes_left, funcdef_no=3, decl_uid=6283, cgraph_uid=4, symbol_order=9)

Modification phase of node fs_bytes_left/9
fs_bytes_left (struct fs_file * file)
{
  int _1;
  int _2;
  int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = file_4(D)->len;
  _2 = file_4(D)->index;
  _5 = _1 - _2;
  return _5;

}


