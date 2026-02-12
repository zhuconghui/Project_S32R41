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

% This function reads the header file fname which contains the enums 
% defined by the user for jobs and debug info:
%     1. RSDK_TRACE_JOB_TYPE_<module>_T - used to add info about functions in _FUNC_START and _FUNC_END events. 
%               - The enum is considered to start with RSDK_TRACE_JOB_<module>_BASE and end with RSDK_TRACE_JOB_<module>_LAST
%     2. RSDK_TRACE_DBG_TYPE_<module>_T - used to add debug info in _EVENT_DBG_INFO.
%                - The enum is considered to start with RSDK_TRACE_DBG_<module>_BASE and end with RSDK_TRACE_DBG_<module>_LAST
%    
% Every line that begins with '/' is considered comment and is ignored.
% Every blank line (space or tabs) is ignored. 
%
% The function returns 2 lists of cells, one with job types and one with dbg info.

function [jobTypeListApp, dbgTypeListApp] = ReadModuleHeader(fname)

fid = fopen(fname);

if (fid == -1)
    fprintf('WARNING! Header file cannot be opened. Check if exists %s. \nAll enums in %s will be ignored \n', fname, fname);
    jobTypeListApp = [];
    dbgTypeListApp = [];
else
    line = fgetl(fid);
    jobTypeListApp = [];
    dbgTypeListApp = [];
    while (~feof(fid))
        while (~contains(line, 'typedef enum') && ~feof(fid))
                line = fgetl(fid);
        end
        if (feof(fid))
            continue
        end
        % Get the lines in header corresponding to the enum
        [lineList, enumType] = GetLineList(fid);
        if ( ~(isempty(strfind(enumType, 'RSDK_TRACE_JOB')) || isempty(strfind(enumType, 'LAST')) ) )
            % Split list in elements of enum
            jobTypeListApp = strsplit(lineList, ',');
            % Remove empty last cell
            jobTypeListApp(end) = [];
        elseif ( ~(isempty(strfind(enumType, 'RSDK_TRACE_DBG')) || isempty(strfind(enumType, 'LAST')) ) )
            % Split list in elements of enum
            dbgTypeListApp = strsplit(lineList, ',');
            % Remove empty last cell
            dbgTypeListApp(end) = [];
        end
        line = fgetl(fid);
    end
    fclose(fid);
end
