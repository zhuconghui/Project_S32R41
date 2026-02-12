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

% Function used to obtain a linear timeline (in case of timestamp wraparound)
function [timeline] = LinearTime(timestampsOrig)
timestamps = timestampsOrig;
for i=2:length(timestampsOrig)-1
    % Highly unlikely to get exactly 0 as timestamp - might be error..
    if timestampsOrig(i) == 0 && timestampsOrig(i - 1) < timestampsOrig(i + 1)
        timestamps(i) = (timestampsOrig(i - 1) + timestampsOrig(i + 1)) / 2;
    else
        timestamps(i) = timestampsOrig(i);
    end
end

% Make first timestamp 0 and shift all others
firstTimestamp = timestamps(1);
fromZeroTimestamps = DiffTimestamps(timestamps, uint64(firstTimestamp) * uint64(ones(length(timestamps))));
timestamps = uint64(fromZeroTimestamps);

% In case of encountering an overflow add uint32 max value to all affected timestamps
for i=2:length(timestamps)
    if timestamps(i) < timestamps(i - 1)
        newTimestamps = [timestamps(1:i-1), timestamps(i:end) + uint64(intmax('uint32'))];
        timestamps = newTimestamps;
    end
end

timeline = timestamps;
end
