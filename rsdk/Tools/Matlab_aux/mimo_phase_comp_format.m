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

function mpcMem = mimo_phase_comp_format(mpcVect)
% Rearrange MIMO phase compensation vectors for Doppler to match SPT mem layout
% Input 
%     - mpcVect - [nrSlots-1,nrDopplerBins] 
% Output
%     - mpcMem

temp = mpcVect.';
mpcMem = temp(:);
