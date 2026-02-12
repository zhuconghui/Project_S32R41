%{
    Copyright 2017,2020-2021 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function detectTags = det_tag_unformat(detMem, nr, nd)
%Rearrange data from SPT mem layout to detected peak tag list
%e.g. if the deteted tags array is defined by [nr,nd] = size(detectTags), then the detMem memory content is:
% SRAM Addr        bitfield values P<n> = {1(peak), 0(non peak)}
% 0x0              P32 P31.......P17 P16 P15........P2 P1
% 0x4              P64................................P33
% 0x8              P96................................P65
% ...              ......................................
%                  P<nr>P<nr-1>...................P<nr-31> -> chirp 0
%                  -------------------------------------------------
%                  P32 P31.......P17 P16 P15........P2 P1 
%                  P64................................P33 
%                  P96................................P65 
%                  ...................................... 
%                  P<nr>P<nr-1>  ...      P<nr-30>P<nr-31> -> chirp 1
%                  -------------------------------------------------
%                  |                   |                   
%                  -------------------------------------------------
%                  P32 P31.......P17 P16 P15........P2 P1 
%                  P64................................P33 
%                  P96................................P65 
% ...              ...................................... 
% 0x<nr*nd/8>      P<nr>P<nr-1>  ...      P<nr-30>P<nr-31> -> chirp <nd>
%                  -------------------------------------------------
BIT_PACK_SIZE = 32;

unpacked_bits_array = zeros(BIT_PACK_SIZE ,numel(detMem));

for idx = 1:numel(detMem)
    unpacked_bits = bitget(detMem(idx), 1:BIT_PACK_SIZE);
    unpacked_bits_array(:,idx) = unpacked_bits;
end

detectTags = reshape(unpacked_bits_array,nr, nd);
