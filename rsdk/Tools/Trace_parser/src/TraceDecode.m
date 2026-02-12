%{
    Copyright 2017,2020-2022 NXP
    NXP Confidential and Proprietary. This software is owned or controlled by NXP and
    may only be used strictly in accordance with the applicable license terms.  By
    expressly accepting such terms or by downloading, installing, activating and/or
    otherwise using the software, you are agreeing that you have read, and that you
    agree to comply with and are bound by, such license terms.  If you do not agree to
    be bound by the applicable license terms, then you may not retain, install, activate or
    otherwise use the software.
%}

function [ parsedContentArray, jobPairs ] = TraceDecode(appHeaderName, eventList, traceColumns, laxTrace)

disp(['Parsing the trace content...']);

% Parse the trace header file to obtain information about fields
traceTypeLists = ReadTraceHeader();
% Create a map of event types
evtMapObj = containers.Map('KeyType','double','ValueType','char');
eventTypes = traceTypeLists.eventTypeList;
for i = 1:length(eventTypes)
    evtMapObj(i-1) = eventTypes{i};    
end

TOTAL_NUM_COLS = length(fieldnames(traceColumns));

% Parsed content is a cell array, to store numeric or string values
parsedContentArray = cell(length(eventList), TOTAL_NUM_COLS);

timestampList = LinearTime([eventList.timestamp]);

parsedContentArray(:, traceColumns.Timestamp) = num2cell(timestampList);
parsedContentArray(2:end, traceColumns.Timestamp_delta) = num2cell(DiffTimestamps(timestampList(2:end), timestampList(1:end-1)));
parsedContentArray(:, traceColumns.Core_ID) = num2cell([eventList.coreID]).';

eventTypeList = values(evtMapObj,{eventList.eventType});

parsedContentArray(:, traceColumns.Event_Type) = eventTypeList;
parsedContentArray(:, traceColumns.Info1) = FieldDecodeInfo1(appHeaderName, eventTypeList, traceTypeLists, [eventList.extraInfo1], laxTrace);

info1List = parsedContentArray(:, traceColumns.Info1);

parsedContentArray(:, traceColumns.Info2) =  num2cell([eventList.extraInfo2].');
[parsedContentArray(:, traceColumns.App_Cycles), jobPairs] = ComputeCycles(eventTypeList, timestampList, info1List);

end
