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

function writeReal(fname, data, scaleFactor, format)
% Function writes input array to binary file in specified format
global CONST

% if ((max(data(:)) > 1) && (scaleFactor > 1))
if (max(round(data(:)*scaleFactor)) > intmax(format))
    disp('ERROR:writeReal: Data values too large for requested format!');
    return
end

fileID = fopen(fname, 'wb',CONST.endian);
if fileID == -1
    disp(['ERROR:writeReal: Cannot open file for writing: ' fname]);
    return
else
    fwrite(fileID, round(data*scaleFactor), format);
    fclose(fileID);
end
