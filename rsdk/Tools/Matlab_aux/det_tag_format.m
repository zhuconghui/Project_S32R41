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

function detMem = det_tag_format(detectTags)

%format detected peak tag list in the same memory format as the SPT does
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
%

BIT_PACK_SIZE = 32;
[nr,nd] = size(detectTags);

detMem = uint32(zeros(nd, ceil(nr/BIT_PACK_SIZE)));

%this loop could be optimized, but it's kept like this for clarity
for id = 1:nd
    for ir = 1:nr
        bitpos = mod(ir-1, BIT_PACK_SIZE)+1;
        detMem(id, ceil(ir/BIT_PACK_SIZE)) = bitset(detMem(id, ceil(ir/BIT_PACK_SIZE)), bitpos ,detectTags(ir,id),'uint32');
    end
end
detMem = reshape(detMem.', 1, []);
