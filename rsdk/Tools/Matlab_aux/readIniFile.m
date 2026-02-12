%{
    Copyright 2018,2021-2022 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function out = readIniFile(fname)

% This function reads an initialization file and returns a list of cells
% Each cell contains the parameters from a line in the init file
% Every line that begins with '#' is considered comment and is ignored
% Every blank line (space or tabs) is ignored 

fid = fopen(fname);
line = fgetl(fid);
% Line index
k = 1;
while (~feof(fid) && (~contains(line, '@') || contains(line, '#')))  
    % Character index
    i = 1;
    % Ignore leading spaces
    while((i <= length(line)) && isspace(line(i))) 
        i = i+1;
    end
    % Ignore line if blank or comment
    if((i > length(line)) || (line(i) == '#'))
        line = fgetl(fid);
        continue
    end
    % Split line at whitespace
    nline = split(line);
    % Delete empty srings (if any)
    index = cellfun(@isempty,nline) == 0;
%     nline(nline == '') = [];
    % Add line to output list
    lineList{k} = nline(index);
    % Get next line
    line = fgetl(fid);
    k=k+1;
end
fclose(fid);

out = lineList;
