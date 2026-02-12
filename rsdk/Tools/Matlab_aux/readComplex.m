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

function out = readComplex(fname,format)
% Read complex signal/data from file stored in format "imag real"

switch format
    case 'int16'
        fact = 2^15;
    case 'int32'
        fact = 2^31;
    case 'int64'
        fact = 2^63;
end

fid = fopen(fname,'rb','ieee-be');
stream = fread(fid,format);
fclose(fid);

temp = stream(1:2*floor(length(stream)/2));
out = (downsample(temp,2,1) + 1i*downsample(temp,2,0)) / fact;
