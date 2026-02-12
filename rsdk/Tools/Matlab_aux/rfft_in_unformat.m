%{
    Copyright 2017-2019,2021-2024 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function out = rfft_in_unformat(in, nrSamples, nrChirpsPerFrame, nrRxAnt)
global CONST
% Format and reorder SPT data to format: [sample, chirp, antenna]
% SPT memory is structured as following:
% ==============================
% S32R294
% ==============================
% s0c0a0 s1c0a0    ...    s7c0a0 
% s0c0a1 s1c0a1    ...    s7c0a1
% s0c0a2 s1c0a2    ...    s7c0a2
% s0c0a3 s1c0a3    ...    s7c0a3
% s8c0a0 s9c0a0    ...    s15c0a0
% s8c0a1 s9c0a1    ...    s15c0a1
% s8c0a2 s9c0a2    ...    s15c0a2
% s8c0a3 s9c0a3    ...    s15c0a3
% ...
% ...
% s0c1a0 s1c1a0    ...    s7c1a0 
% s0c1a1 s1c1a1    ...    s7c1a1
% s0c1a2 s1c1a2    ...    s7c1a2
% s0c1a3 s1c1a3    ...    s7c1a3
% ...
% ...
% ...
% ==============================
% S32R45
% ==============================
% s0c0a0 s1c0a0    ...    s15c0a0 
% s0c0a1 s1c0a1    ...    s15c0a1
% s0c0a2 s1c0a2    ...    s15c0a2
% s0c0a3 s1c0a3    ...    s15c0a3
% s16c0a0 s9c0a0    ...   s31c0a0
% s16c0a1 s9c0a1    ...   s31c0a1
% s16c0a2 s9c0a2    ...   s31c0a2
% s16c0a3 s9c0a3    ...   s31c0a3
% ...
% ...
% s0c1a0 s1c1a0    ...    s15c1a0 
% s0c1a1 s1c1a1    ...    s15c1a1
% s0c1a2 s1c1a2    ...    s15c1a2
% s0c1a3 s1c1a3    ...    s15c1a3
% ...
% ...
% ...
% ==============================

if (strcmp(CONST.HW, 'S32R294'))
    TILE_LENGTH = 8;
elseif strcmp(CONST.HW, 'S32R45')
    TILE_LENGTH = 16;
elseif strcmp(CONST.HW, 'S32R41')
    TILE_LENGTH = 8;
elseif strcmp(CONST.HW, 'SAF85XX')
    TILE_LENGTH = 8;
elseif strcmp(CONST.HW, 'SAF86XX')
    TILE_LENGTH = 16;
else
    error('HW Platform not supported');
end

out = zeros(nrSamples, nrChirpsPerFrame, nrRxAnt);
for i = 0:nrChirpsPerFrame-1
    for j = 0:TILE_LENGTH:nrSamples-1
        for k = 0:nrRxAnt-1
            start = i*nrSamples*nrRxAnt + j*nrRxAnt + k*TILE_LENGTH +1;
            stop  = i*nrSamples*nrRxAnt + j*nrRxAnt + k*TILE_LENGTH + TILE_LENGTH;
            out(j+1 : j+TILE_LENGTH, i+1, k+1) = in(start:stop);
        end
    end
end
