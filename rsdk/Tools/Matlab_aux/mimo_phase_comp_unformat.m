%{
    Copyright 2017-2021 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function mpcVect = mimo_phase_comp_unformat(mpcVect, nrDopplerBins, nrTdMimoSlots)
% Rearrange MIMO phase compensation vectors for Doppler from SPT mem layout
% to Matlab Model format
% Input 
%     - mpcMem 
%     - nrTdMimoSlots
%     - nrDopplerBins
% Output
%     - mpcVect- [nrSlots-1,nrDopplerBins] 
    
temp = reshape(mpcVect, nrDopplerBins, nrTdMimoSlots-1);
mpcVect = temp.';
