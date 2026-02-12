%{
    Copyright 2018,2020-2021 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function out = cfar_indices_unformat(detMem, nrRangeBins, nrDopplerBins)
% Convert indices of peaks in RDM, obtained using 2D CFAR, to peak tag matrix

% detMem contains indices starting from 0
cfarIndices = detMem + 1;

% Transposed peak tag matrix
cfarTagFile = zeros(nrDopplerBins, nrRangeBins);
cfarTagFile(cfarIndices) = 1;

out = cfarTagFile.';
