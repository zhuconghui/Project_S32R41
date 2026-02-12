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

function rdMagMem = rd_mag_format(rdMag)
% Format Range_Doppler Magnitude matrix to SPT memory layout
% *     OUTPUT Memory layout:
% *     SRAM, 32 bit complex(16b_Im + 16b_Re)
% *     63:48           47:32           31:16           15:0
% *     A0_Crp0         A1_Crp0         A2_Crp0         A3_Crp0
% *     |               |               |               |
% *     A124_Crp0       A125_Crp0       A126_Crp0       A127_Crp0
% *     A0_Crp1         A1_Crp1         A2_Crp1         A3_Crp1
% *     |               |               |               |
% *     A124_Crp1       A125_Crp1       A126_Crp1       A127_Crp1
% *     |               |               |               |
% *     |               |               |               |
% *     |               |               |               |
% *     |               |               |               |
% *     |               |               |               |
% *     A0_Crp127       A1_Crp127       A2_Crp127       A3_Crp127
% *     |               |               |               |
% *     A124_Crp127     A125_Crp127     A126_Crp127     A127_Crp127

rdMagMem = reshape(rdMag.', [], 1);
