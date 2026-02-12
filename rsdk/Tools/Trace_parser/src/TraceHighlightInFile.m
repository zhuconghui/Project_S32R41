%{
    Copyright 2020-2022 NXP
    NXP Confidential and Proprietary. This software is owned or controlled by NXP and
    may only be used strictly in accordance with the applicable license terms.  By
    expressly accepting such terms or by downloading, installing, activating and/or
    otherwise using the software, you are agreeing that you have read, and that you
    agree to comply with and are bound by, such license terms.  If you do not agree to
    be bound by the applicable license terms, then you may not retain, install, activate or
    otherwise use the software.
%}

% *************************************************************************
% %%%% Description: 
% This function reads the trace xls file and highlights cells describing pair events with the same color.
%
% %%%% Input parameters:
%   *outputXlsFileName  = name of the previously written xls trace file
%   *numRows            = number of rows in the trace xls file
%   *uniqEvts           = cell array of all encountered unique events; in this case, an event is the
%                       concatenation of the 'type' and 'info1' char values
% *************************************************************************
function TraceHighlightInFile(outputXlsFileName, numRows, uniqEvts)
% Get full path to Trace Parser root folder
fullPathSplit = strsplit(mfilename('fullpath'), '\');
fullPathToParserSplit = fullPathSplit(1:end-2);
fullPathToParser = strcat(regexprep(join(fullPathToParserSplit), ' ', '\'), '\');

% Get relative path of xlsx file to Trace Parser directory
outputXlsFileNameSlsh = regexprep(outputXlsFileName, '\\', '/');
relativePathToXlsSplit = strsplit(outputXlsFileNameSlsh, '/');
relativePathToXls = regexprep(join(relativePathToXlsSplit(2:end)), ' ', '\');

% Full path of xlsx output file
fullPathToXls = strcat(fullPathToParser, relativePathToXls);

% Create server to access xls file
Excel = actxserver('excel.application');

% Get Workbook object
traceXls = Excel.Workbooks.Open(char(fullPathToXls));

% Keep background colors for 'type' and 'info1' in corresponding maps
typeBgColors = containers.Map;
info1BgColors = containers.Map;

% Count uniques event
uniqCnt = length(uniqEvts(~cellfun('isempty', regexp(uniqEvts, '.*_END'))));

% Get a set of different colors for cells
colorVec = GetEventMapColor(uniqCnt);

% Go through all rows in the xls file
for i=2:numRows+1
    % Get the type of the event from the xls file
    typeCurrentCell = strcat('C', char(string(i)));
    typeContent = string(traceXls.Worksheets.Item(1).Range(typeCurrentCell).Value);

    % Get the info1 value of the event from the xls file
    info1CurrentCell = strcat('D', char(string(i)));
    info1Content = string(traceXls.Worksheets.Item(1).Range(info1CurrentCell).Value);
    
    % Get cells that give duration of event (app cycles & micros)
    durationCurrentCell = strcat(strcat('G', char(string(i))), (strcat(':', strcat('H', char(string(i))))));
    
    % If current event is of type START or END
    if (contains(typeContent, 'START') && any(strcmp(uniqEvts, strcat(regexprep(typeContent, 'START', 'END'), info1Content)))) || contains(typeContent, 'END')
        % Get corresponding background and foreground colors
        [bgColor] = GetEventBgColor(typeBgColors, info1Content, colorVec, typeBgColors.Count + info1BgColors.Count + 1);
        fgColor = GetEventFgColor(bgColor);
        
        % Set the extracted colors for the type and info1 cells in the xls file
        rangeCurrentCell = strcat(typeCurrentCell, (strcat(':', info1CurrentCell)));
        traceXls.Worksheets.Item(1).Range(rangeCurrentCell).Interior.Color = bgColor;
        traceXls.Worksheets.Item(1).Range(rangeCurrentCell).Font.Color = fgColor;
        
        % If it is an END event then also set these colors for the cells that give the corresponding job duration
        if contains(typeContent, 'END')
            traceXls.Worksheets.Item(1).Range(durationCurrentCell).Interior.Color = bgColor;
            traceXls.Worksheets.Item(1).Range(durationCurrentCell).Font.Color = fgColor;
        end
    
    
    % If current debug event is of type START
    elseif isstring(info1Content) && contains(info1Content, 'START')
        % Get corresponding background and foreground colors
        [bgColor] = GetEventBgColor(info1BgColors, info1Content, colorVec, typeBgColors.Count + info1BgColors.Count + 1);
        fgColor = GetEventFgColor(bgColor);
        
        % Highlight 'info1' of event using extracted colors
        traceXls.Worksheets.Item(1).Range(info1CurrentCell).Interior.Color = bgColor;
        traceXls.Worksheets.Item(1).Range(info1CurrentCell).Font.Color = fgColor;
    
    
    % If current debug event is of type END
    elseif isstring(info1Content) && contains(info1Content, 'END')
        info1ContentStart = strrep(info1Content, 'END', 'START');
        % Check if corresponding colors exist in map
        if isKey(info1BgColors, info1ContentStart)
            % Extract colors
            bgColor = info1BgColors(info1ContentStart);
            fgColor = GetEventFgColor(bgColor);
            
            % Highlight 'info1' of event using extracted colors
            traceXls.Worksheets.Item(1).Range(info1CurrentCell).Interior.Color = bgColor;
            traceXls.Worksheets.Item(1).Range(info1CurrentCell).Font.Color = fgColor;
            
            % Highlight duration of event using extracted colors
            traceXls.Worksheets.Item(1).Range(durationCurrentCell).Interior.Color = bgColor;
            traceXls.Worksheets.Item(1).Range(durationCurrentCell).Font.Color = fgColor;
        end
    end
end

% Set cell sizes in xlsx file to fit content accordingly
Excel.Cells.EntireColumn.AutoFit;
% Set cell borders for written data
set(traceXls.Worksheets.Item(1).Range(char(strcat('A1:H', string(numRows + 1)))).Borders, 'LineStyle', 1);
% Save Workbook
traceXls.Save();
% Close Workbook
traceXls.Close();
% Quit Excel
Excel.Quit();
end

% Auxiliary function that returns a set of colors from the 'parula' colormap
function [colorVec] = GetEventMapColor(size)
colorMap = parula();
for i=1:size
    colorMapRow = floor(length(colorMap) / size) * i;
    colorRgb = colorMap(colorMapRow, :);
    colorDec = Rgb2dec(colorRgb);
    colorVec(i) = colorDec;
end
end

% Auxiliary function that returns a fixed background color for certain events
function [bgColor] = GetEventBgColor(map, content, colorVec, colorIdx)
if isKey(map, content)
    % If corresponding color already exists, return it
    bgColor = map(content);
else
    % If not, generate color & add to map (map(textIdEvent) = colorDecimalFormat)
    colorCellDec = colorVec(colorIdx);
    bgColor = colorCellDec;
    map(content) = bgColor;
end
end

% Auxiliary function that returns black or white for text based on background color
function [fgColor] = GetEventFgColor(bgColor)
less = 0;
more = 0;

if bitand(uint64(bgColor), hex2dec('0000FF')) > hex2dec('000088')
    more = more + 1;
else
    less = less + 1;
end

if bitand(uint64(bgColor), hex2dec('00FF00')) > hex2dec('008800')
    more = more + 1;
else
    less = less + 1;
end

if bitand(uint64(bgColor), hex2dec('FF0000')) > hex2dec('880000')
    more = more + 1;
else
    less = less + 1;
end

if (more < less)
    fgColor = hex2dec('FFFFFF');
else
    fgColor = 0;
end
end

% Auxiliary function that converts a rgb color in the corresponding decimal value
function [colorDec] = Rgb2dec(colorRgb)
    hex1 = round(colorRgb(1) * 255);
    hex2 = round(colorRgb(2) * 255);
    hex3 = round(colorRgb(3) * 255);
    colorDec = hex1 + 256 * hex2 + 256 * 256 * hex3;
end
