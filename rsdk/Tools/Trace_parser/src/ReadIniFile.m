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

% %%%% Description:
% This function reads the trace ini file placed in <proj>/Tools/Trace_parser
% The file is used to set a specific configuration in order to interpret the trace output.
% Every line that begins with '#' is considered a comment and is ignored.
% Every blank line (space or tabs) is ignored.
% 
% %%%% Output parameter (configOptions) fields:
%   *endianness   = endianess used to write .hex file
%   *timerFreq    = frequency of the timer used for timestamps [MHz]
%   *kernelTrace  = include kernel trace data if available
%   *laxTrace     = include lax trace data if available
%   *laxFile      = relative path to lax trace file
%   *xlsHighlight = option to highlight pair events in resulting xls file
%   *makePlots    = option to plot relevant data as figures
%   *sptSeparate  = option to plot separate piecharts & stats for spt jobs
%
% *************************************************************************
function [configOptions] = ReadIniFile()

% Open config file
iniFileName = '..\platform_config.ini';
fid = fopen(iniFileName);

evalString = '';

while (~feof(fid))
    % Skip empty or commented lines
    line = fgetl(fid);
    if isempty(line) || line(1) == '#'
        continue
    end
    
    evalString = [evalString, sprintf('\n'), line];
end

eval(evalString);

% Close ini file
fclose(fid);

if isempty(evalString)
    error('No active config line found in ../platform_config.ini');
end

end



