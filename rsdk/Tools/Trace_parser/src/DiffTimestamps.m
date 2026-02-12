%{
    Copyright 2020-2021 NXP
    NXP Confidential and Proprietary. This software is owned or controlled by NXP and
    may only be used strictly in accordance with the applicable license terms.  By
    expressly accepting such terms or by downloading, installing, activating and/or
    otherwise using the software, you are agreeing that you have read, and that you
    agree to comply with and are bound by, such license terms.  If you do not agree to
    be bound by the applicable license terms, then you may not retain, install, activate or
    otherwise use the software.
%}
% Computes difference between timestamps considering counter overflow.
% Assumption: timestamps are 32-bit values
function [diff] = DiffTimestamps(currentTime, baseTime)
    for i=1:length(currentTime)
        if currentTime(i) < baseTime(i)
            diff(i) = uint64(intmax('uint32')) - baseTime(i) + currentTime(i);
        else
            diff(i) = uint64(currentTime(i) - baseTime(i));
        end
    end
end

