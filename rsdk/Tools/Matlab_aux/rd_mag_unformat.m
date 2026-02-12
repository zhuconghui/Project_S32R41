%{
    Copyright 2017-2018,2020-2021 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function rdMag = rd_mag_unformat(rdMagMem, nrRangeBins, nrDopplerBins)
% Re-format from SPT memory layout to Range_Doppler Magnitude matrix 
%      OUTPUT Memory layout:
%      SRAM, 16 bit real Log2 Mag2 format
%      63:48           47:32           31:16           15:0
%      R0_D0_MAG       R0_D1_MAG       R0_D2_MAG       R0_D3_MAG
%      |               |               |               |
%      R0_D252_MAG     R0_D253_MAG     R0_D254_MAG     R0_D255_MAG
%      R1_D0_MAG       R1_D1_MAG       R1_D2_MAG       R1_D3_MAG
%      |               |               |               |
%      R1_D252_MAG     R1_D253_MAG     R1_D254_MAG     R1_D255_MAG
%      |               |               |               |
%      |               |               |               |
%      |               |               |               |
%      |               |               |               |
%      |               |               |               |
%      R127_D0_MAG     R127_D1_MAG     R127_D2_MAG     R127_D3_MAG
%      |               |               |               |
%      R127_D252_MAG   R127_D253_MAG   R127_D254_MAG   R127_D255_MAG

tmp = reshape(rdMagMem, nrDopplerBins, nrRangeBins);
rdMag = tmp.';
