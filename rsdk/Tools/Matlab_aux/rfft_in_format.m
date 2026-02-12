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

function out = rfft_in_format(S)
global CONST
% Format and reorder data to map on SPT memory
% S has the format - [sample, chirp, antenna]
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

if (strcmp(CONST.HW, 'S32R294') || strcmp(CONST.HW, 'S32R41'))
    TILE_LENGTH = 8;
elseif strcmp(CONST.HW, 'S32R45')
    TILE_LENGTH = 16;
else
    error('HW Platform not supported');
end

[nrSamp,nrChirp,nrAnt] = size(S);
if (nrAnt == 4)
    Smem = zeros(numel(S),1);
    for i = 0:nrChirp-1
        for j = 0:TILE_LENGTH:nrSamp-1
            for k = 0:nrAnt-1
                iStart = i*nrSamp*nrAnt + j*nrAnt + k*TILE_LENGTH + 1;
                iStop  = i*nrSamp*nrAnt + j*nrAnt + k*TILE_LENGTH + TILE_LENGTH;
                Smem(iStart:iStop) = S(j+1:j+TILE_LENGTH, i+1, k+1);
            end
        end
    end
elseif (nrAnt == 8)
    Smem = zeros(2, numel(S)/2);
    for i = 0:nrChirp-1
        for j = 0:TILE_LENGTH:nrSamp-1
            for k = 0:nrAnt/2-1
                % CH#0..CH#3
                iStart = i*nrSamp*nrAnt/2 + j*nrAnt/2 + k*TILE_LENGTH + 1;
                iStop  = i*nrSamp*nrAnt/2 + j*nrAnt/2 + k*TILE_LENGTH + TILE_LENGTH;
                Smem(1,iStart:iStop) = S(j+1:j+TILE_LENGTH, i+1, k+1);
                % CH#4..CH#7
                iStart = i*nrSamp*nrAnt/2 + j*nrAnt/2 + k*TILE_LENGTH + 1;
                iStop  = i*nrSamp*nrAnt/2 + j*nrAnt/2 + k*TILE_LENGTH + TILE_LENGTH;
                Smem(2,iStart:iStop) = S(j+1:j+TILE_LENGTH, i+1, (k+4)+1);
            end
        end
    end
elseif (nrAnt == 16)
    Smem = zeros(4, numel(S)/4);
    for i = 0:nrChirp-1
        for j = 0:TILE_LENGTH:nrSamp-1
            for k = 0:nrAnt/4-1
                % CH#0..CH#3
                iStart = i*nrSamp*nrAnt/4 + j*nrAnt/4 + k*TILE_LENGTH + 1;
                iStop  = i*nrSamp*nrAnt/4 + j*nrAnt/4 + k*TILE_LENGTH + TILE_LENGTH;
                Smem(1,iStart:iStop) = S(j+1:j+TILE_LENGTH, i+1, k+1);
                % CH#4..CH#7
                iStart = i*nrSamp*nrAnt/4 + j*nrAnt/4 + k*TILE_LENGTH + 1;
                iStop  = i*nrSamp*nrAnt/4 + j*nrAnt/4 + k*TILE_LENGTH + TILE_LENGTH;
                Smem(2,iStart:iStop) = S(j+1:j+TILE_LENGTH, i+1, (k+4)+1);
                % CH#8..CH#11
                iStart = i*nrSamp*nrAnt/4 + j*nrAnt/4 + k*TILE_LENGTH + 1;
                iStop  = i*nrSamp*nrAnt/4 + j*nrAnt/4 + k*TILE_LENGTH + TILE_LENGTH;
                Smem(3,iStart:iStop) = S(j+1:j+TILE_LENGTH, i+1, (k+8)+1);
                % CH#12..CH#15
                iStart = i*nrSamp*nrAnt/4 + j*nrAnt/4 + k*TILE_LENGTH + 1;
                iStop  = i*nrSamp*nrAnt/4 + j*nrAnt/4 + k*TILE_LENGTH + TILE_LENGTH;
                Smem(4,iStart:iStop) = S(j+1:j+TILE_LENGTH, i+1, (k+12)+1);
            end
        end
    end
else
    error('Wrong antenna number');
end

out = Smem;
