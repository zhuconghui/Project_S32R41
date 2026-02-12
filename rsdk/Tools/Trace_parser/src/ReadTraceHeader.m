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

% This function reads the trace header file placed in <proj>/Tools/Trace/api
% The header is expected to contain 3 enums:
%   1. rsdkTraceEventType_e - Predefined types of trace events. 
%                - Intended as the first argument in RsdkTraceLogEvent().
%                - Used to mark common event types like function start/end, system synchronization or general debug info.
%   2. rsdkTraceJobType_e - Used to indicate exactly which RSDK modules and functions are signalling _FUNC_START and _FUNC_END events.
%                 - It defines only the base indexes for functions associated to the RSDK modules. 
%                 - Each module must define its job types in its own header files, strictly within the boundaries defined here.
%   3. rsdkTraceDbgType_e - Used to indicate exactly which RSDK modules and functions are logging information related to RSDK_TRACE_EVENT_DBG_INFO.
%                 - This enum defines only the base indexes for debug events associated to the RSDK modules.
%                 - Each module must define its specific debug events in its own header files, strictly within the boundaries defined here.
%
% Each enum is considered to start at 'typedef enum' and end at RSDK_TRACE_<enum_type>_LAST.
% Every line that begins with '/' is considered a comment and is ignored.
% Every blank line (space or tabs) is ignored.
% 
% The function returns 3 lists, corresponding to the 3 enums. Each list
% contains the elements of the enum, and, for jobTypeList and dbgTypeList,
% the base indices for each module.

function traceTypeLists = ReadTraceHeader()

headerName = '..\..\..\Tools\Trace\api\trace.h';
fid = fopen(headerName);

if (fid == -1)
    fprintf('WARNING! Trace header file cannot be opened. Check if exists %s. Exiting.. \n', headerName);
    return
end

line = fgetl(fid);

while (~feof(fid))
    while (~contains(line, 'typedef enum') && ~feof(fid))
            line = fgetl(fid);
    end
    if (feof(fid))
        continue
    end
    [lineList, enumType] = GetLineList(fid);
    if (~isempty(strfind(enumType, 'RSDK_TRACE_EVENT_LAST')))
        % Split list in elements of enum
        eventTypeList = strsplit(lineList, ',');
        % Remove empty last cell
        eventTypeList(end) = [];
    elseif (~isempty(strfind(enumType, 'RSDK_TRACE_JOB_LAST')))
        % Split list in elements of enum and corresponding values
        jobTypeList = strsplit(lineList, {',', '='}, 'CollapseDelimiters', false);
        % Remove empty last cell
        jobTypeList(end) = [];
    elseif (~isempty(strfind(enumType, 'RSDK_TRACE_DBG_LAST')))
        % Split list in elements of enum and corresponding values
        dbgTypeList = strsplit(lineList, {',', '='}, 'CollapseDelimiters', false);
        % Remove empty last cell
        dbgTypeList(end) = [];
    end
    line = fgetl(fid);
end
fclose(fid);
traceTypeLists.eventTypeList = eventTypeList;
traceTypeLists.jobTypeList   = jobTypeList;
traceTypeLists.dbgTypeList   = dbgTypeList;
end



