%{
    Copyright 2017-2021 NXP
    NXP Confidential and Proprietary. This software is owned or controlled by NXP and
    may only be used strictly in accordance with the applicable license terms.  By
    expressly accepting such terms or by downloading, installing, activating and/or
    otherwise using the software, you are agreeing that you have read, and that you
    agree to comply with and are bound by, such license terms.  If you do not agree to
    be bound by the applicable license terms, then you may not retain, install, activate or
    otherwise use the software.
%}

% Read raw trace from binary file:
function eventList = TraceReadRawData(binaryTraceFileName, endianness)

disp(['Reading raw binary from input trace file...']);

logRecord = struct( ...
'timestamp', NaN, ...
'coreID', NaN, ...
'eventType', NaN, ...
'extraInfo1', NaN, ...
'extraInfo2', NaN );

RECORD_NUM_BYTES = 12;

%first, check if empty:
file_info=dir(binaryTraceFileName);
if(isempty(file_info))
   error(['ERROR: Binary trace file not found: ' binaryTraceFileName]);
else
num_events = floor(file_info.bytes/RECORD_NUM_BYTES);
end

if(num_events == 0)
   disp(['\n WARNING: Binary trace file is empty: ' binaryTraceFileName '. Exiting. \n']);
   return
end

fid = fopen(binaryTraceFileName, 'rb');
if(fid == -1)
   error(['ERROR: The binary trace file cannot be opened: ' binaryTraceFileName]);
end

eventList = repmat(logRecord, num_events, 1);

ieeeEndian = 'ieee-be';
if isequal(endianness, 'little')
    ieeeEndian = 'ieee-le';
end

for(i=1:num_events)
    eventList(i).timestamp = uint64(fread(fid,1,'uint32',ieeeEndian));
    eventList(i).coreID = fread(fid,1,'uint8',ieeeEndian);
    eventList(i).eventType = fread(fid,1,'uint8',ieeeEndian);
    eventList(i).extraInfo1 = fread(fid,1,'uint16',ieeeEndian);
    eventList(i).extraInfo2 = fread(fid,1,'uint32',ieeeEndian);

    % Ignore the empty part of the trace buffer (can happen for LAX trace)
    if eventList(i).timestamp == 0 && eventList(i).coreID == 0 && ...
       eventList(i).eventType == 0 && eventList(i).extraInfo1 == 0 && ...
       eventList(i).extraInfo2 == 0 && i > 1
        eventList = eventList(1:i-1);
        break;
    end
end

fclose(fid);
