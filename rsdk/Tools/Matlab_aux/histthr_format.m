%{
    Copyright 2017,2021 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function thMem = histthr_format(threshList)

%format threshold list memory in the proper format for SPT input
t1 = log2(threshList)+46; %TODO: we don't know where the '46' comes from, but this gives same results as the SPT hardware
t1(t1==-inf) = 0;

E = floor(t1);
M = floor((2^8)*(t1 - E));

thMem = (((2^8)*E+M));

%this section checks if we are able to recover the original values from the log2 format
% figure, surf(E)
% figure, surf(M)

% M = bitand(thMem, bin2dec('0000000011111111'));
% E = bitand(thMem, bin2dec('0011111100000000'))/2^8;
% 
% figure, surf(E)
% figure, surf(M)
% 
% threshListDecoded = 2.^(E + (M/2^8))/2^46;
