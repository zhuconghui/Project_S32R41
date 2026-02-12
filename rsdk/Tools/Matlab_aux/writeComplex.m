%{
    Copyright 2017-2018,2021 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function writeComplex(fname,data,precision,scale)
global CONST
% Write complex vector to file in format "imag real"
if scale
    if max([max(real(data)) max(imag(data))]) > 1
        disp('ERROR; Input data is not scaled to 1!');
        return
    end

    switch precision
        case 'int16'
            fact = 2^15;
        case 'int32'
            fact = 2^31;
        case 'int64'
            fact = 2^63;
    end

    realPart = round(real(data)*fact);
    imagPart = round(imag(data)*fact);
else
    realPart = real(data);
    imagPart = imag(data);    
end

outStream = zeros(1,2*length(data));
outStream(1:2:end) = imagPart;
outStream(2:2:end) = realPart;
fid = fopen(fname,'wb',CONST.endian);
if fid == -1
    disp(['ERROR:writeComplex: Cannot open file for writing: ' fname]);
    return
else
    fwrite(fid,outStream,precision);
    fclose(fid);
end
