%{
    Copyright 2017-2019,2021 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function out = dec_to_spt_log2(in)
% Convert input to SPT log2 representation

global CONST

adjustment_factor = 46; %TODO: we don't know where the '46' comes from, but this gives same results as the SPT hardware

t1 = log2(in) + adjustment_factor;
% t1(t1==-inf) = 0;
t1(t1<0) = 0;

E = floor(t1);
M = floor((2^8)*(t1 - E));

out = (2^8)*E+M;
