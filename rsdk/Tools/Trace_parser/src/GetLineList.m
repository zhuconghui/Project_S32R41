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
% Function returns the lines in the header fid between the last 'typedef 
% enum' and the last element in enum, specified by RSDK_TRACE_<TYPE>_<MODULE>_LAST.
% The output is a string of elements separated by comma.

function [traceLineList, enumType]  = GetLineList(fid)

lineList = [];
line = fgetl(fid);
while ((isempty(strfind(line, 'RSDK_TRACE_')) || isempty(strfind(line, '_LAST'))) && isempty(strfind(line, '}')))
    i = 1;
    % Ignore leading spaces and bracket marking the start of enum 
    while((i <= length(line)) && (isspace(line(i)) || line(i) == '{'))
        i = i+1;
    end
    % Ignore line if blank or comment
    if((i > length(line)) || (line(i) == '/') || (line(i) == '*'))
        line = fgetl(fid);
        continue
    end
    % Line ends when ',' is encountered 
    lastChar = strfind(line, ',');
    if (isempty(lastChar))
        line = fgetl(fid);
        continue
    end
    % Add line to output list
    lineList = [lineList strtrim(line(i:lastChar(1)))];
    % Get next line
    line = fgetl(fid);
end
traceLineList = lineList;
enumType = line;
end
