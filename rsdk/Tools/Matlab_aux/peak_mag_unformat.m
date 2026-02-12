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

function out = peak_mag_unformat(mag)

M = bitand(mag,(2^9-1));
E = floor(mag/2^8);

exponent = E + M/2^8 - 46; %TODO: we don't know where the '46' comes from, but this gives same results as the SPT hardware

peak_mag_val = 2.^exponent;

out = peak_mag_val;
