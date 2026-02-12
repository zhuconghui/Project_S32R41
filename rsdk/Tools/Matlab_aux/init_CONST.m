%{
    Copyright 2017-2024 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function CONST = init_CONST(HW)
% Initialize constant values 
CONST.isMEXPresent = false;

% Valid CONST.HW values
%CONST.HW = 'S32R45';
%CONST.HW = 'S32R41';

% Initialize const HW
CONST.HW = upper(HW);
switch(CONST.HW)
    case{'S32R45', 'RRM'}   %RRM
        CONST.HW = 'S32R45';
        sptVersion = 31;
    case{'S32R41', 'R41'}   %R41
        CONST.HW = 'S32R41';
        sptVersion = 35;
    case{'SAF85XX', 'STRX'} %STRX
        CONST.HW = 'SAF85XX';
        sptVersion = 34;
    case{'SAF86XX'}
        CONST.HW = 'SAF86XX';
        sptVersion = 34;
    otherwise
        error('Wrong platform. Application will exit\n');
        return;
end  

fprintf('Hardware selected: %s\n', CONST.HW);

if(exist('switch_spt') == 3) %if mex exists switch to the right sptVersion
    switch_spt(sptVersion);
    disp('----------------------------');
    fprintf('Running on SPT: %.1f\n', sptVersion/10);
    disp('----------------------------');
    CONST.isMEXPresent = true; 
else
    fprintf(2, 'MEX 1.5.1 not detected. Compression not enabled!\n');
    fprintf(2, 'For compression features install SPT TOOLBOX V 1.5.1\n');
end

%% General defines
CONST.TRUE = 1;
CONST.FALSE = 0;

CONST.MAX_INT16 = 2^15;
CONST.MAX_INT24 = 2^23;

CONST.MAX_NR_PEAKS = 128;
CONST.Fs = 40*10^6;     %'chirp' sampling frequency
CONST.Ts = 1/CONST.Fs;
CONST.C = 3*10^8;

CONST.endian = 'ieee-be';
end
