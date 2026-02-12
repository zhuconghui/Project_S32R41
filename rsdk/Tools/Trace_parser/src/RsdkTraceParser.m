%{
    Copyright 2017-2022 NXP
    NXP Confidential and Proprietary. This software is owned or controlled by NXP and
    may only be used strictly in accordance with the applicable license terms.  By
    expressly accepting such terms or by downloading, installing, activating and/or
    otherwise using the software, you are agreeing that you have read, and that you
    agree to comply with and are bound by, such license terms.  If you do not agree to
    be bound by the applicable license terms, then you may not retain, install, activate or
    otherwise use the software.
%}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% %%%% File name: RsdkTraceParser.m
%     
% %%%% Description: Parses the trace binay file created by the CPU during
% application runtime, outputs the parsed content in a cell array and also
% writes it to a xlsx file in the same location
% The Trace Parser automatically gets the trace event names and IDs from 
% the corresponding C typedefs. It searches for them in the RSDK library 
% headers (default) + in a single header file in the user app. The 
% conventions for these is:
%        1. Trace header (trace.h) defines 3 enums: 
%               - enum rsdkTraceEventType_t: Predefined types of trace events. Enum's last element must be RSDK_TRACE_EVENT_LAST. 
%               - enum rsdkTraceJobType_t: Used to indicate exactly which RSDK modules and functions are signalling _FUNC_START and _FUNC_END events.
%                               It defines the base indices for functions associated to the RSDK modules (e.g. RSDK_TRACE_JOB_APP_BASE = 0).
%                               Enum's last element must be RSDK_TRACE_JOB_LAST. 
%               - enum rsdkTraceDbgType_t: Used to indicate exactly which RSDK modules and functions are logging information related to RSDK_TRACE_EVENT_DBG_INFO.
%                               It defines the base indices for debug events associated to the RSDK modules (e.g. RSDK_TRACE_DBG_APP_BASE = 0).
%                               Enum's last element must be RSDK_TRACE_DBG_LAST.
%        2. Module headers(library headers + user's header)
%               - RSDK_TRACE_JOB_TYPE_<module>_T: Used to add info about functions in _FUNC_START and _FUNC_END events. 
%                               The enum is considered to start at RSDK_TRACE_JOB_<module>_BASE and end at RSDK_TRACE_JOB_<module>_LAST
%               - RSDK_TRACE_DBG_TYPE_<module>_T: Used to add debug info in _EVENT_DBG_INFO.
%                               The enum is considered to start with RSDK_TRACE_DBG_<module>_BASE and end with RSDK_TRACE_DBG_<module>_LAST
%
% %%%% Input Parameters: 
%        1. binaryTraceFileName - String parameter representing the name of binary file to be parsed. 
%        2. appHeaderName - String parameter representing the name of the header file which contains the enums 
%                           defined by the user for jobs and debug info. 
%       *Note: binaryTraceFileName and outputXlsFileName should include the file paths relative to this source file.                         
%
% %%%% Output parameters:
%        1. parsedContent - cell array containing the resulted parsed content. Can be further used for trace analysis. 
%        2. traceColumns - structure having as members the header column names, each with the index assigned as value
%                     eg.: If 'Timestamp' is the name of the first column of the parsedContent, then traceColumns.Timestamp=1;
% 
% %%%% Assumptions:
%        1. the binary trace content is already unwrapped, having the most recent event at the end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ parsedContent, traceColumns ] = RsdkTraceParser(binaryTraceFileName, appHeaderName)

% Get config from ini file
configOptions = ReadIniFile();

startTime = clock;
disp(['CORE TRACE PARSER has started processing the file: ' binaryTraceFileName]);

% initialization block:
% fields used for parsing the binary trace and printed as header in the parsed .XLSX output file. 
traceColumns = struct( ...
'Timestamp',                1, ...
'Timestamp_delta',          2, ...
'Event_Type',               3, ...
'Info1',                    4, ...
'Info2',                    5, ...
'Core_ID',                  6, ...
'App_Cycles',               7, ...
'Micros',                   8 ...
);

% Read and store raw trace data
eventList = TraceReadRawData(binaryTraceFileName, configOptions.endianness);

% Combine trace data from multiple files if needed (for linux kernel/lax trace)
origContent = CombineTraceFiles(eventList, configOptions, binaryTraceFileName);

% Parse the trace
[parsedContent, jobPairs] = TraceDecode(appHeaderName, origContent, traceColumns, configOptions.laxTrace);

% Compute 'Micros' column for the xls file
for i=1:size(parsedContent)
   if ~isempty(cell2mat(parsedContent(i, traceColumns.App_Cycles)))
       parsedContent(i, traceColumns.Micros) = num2cell(round(double(cell2mat(parsedContent(i, traceColumns.App_Cycles))) / configOptions.timerFreq, 2));
   else
       parsedContent(i, traceColumns.Micros) = parsedContent(i, traceColumns.App_Cycles);
   end
end

% Write to xls file:
outputXlsFileName = [binaryTraceFileName(1:end-4), '.xlsx'];
numRows = TraceWriteToFile(parsedContent, traceColumns, outputXlsFileName);

% Get unique events
uniqEvts = unique(strcat(parsedContent(:, traceColumns.Event_Type), char(string(parsedContent(:, traceColumns.Info1)))));

% Highlight pair events with specific colors in xlsx file if needed
if configOptions.xlsHighlight == true
    TraceHighlightInFile(outputXlsFileName, numRows, uniqEvts);
end

% Plot useful information in 2 figures
if configOptions.makePlots == true
    TraceMakePlots(origContent, parsedContent, traceColumns, configOptions.timerFreq, jobPairs, configOptions.sptSeparate);
end

% Print end message
endTime = clock;
fprintf('\n INFO: <%s> has been successfuly parsed. Processing lasted for %d [sec].  \n\n', binaryTraceFileName, etime(endTime, startTime));

end
