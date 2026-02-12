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

% *************************************************************************
% %%%% Description: 
% This function is used to make plots that summarize information provided by the trace output binary file.
% It uses both the raw and the decoded information in order to make 2 figures:
%   1.Timeline   - a linear representation of the encountered events; pair events (e.g. jobs) are represented
%                  as individual continuous intervals, while individual events appear as a singular point; this
%                  figure can also show the exact moment of encounter for each individual event and duration (in
%                  microseconds) for each interval with the help of 2 dedicated buttons
%
%   2.Statistics - an overview of the execution time; it can be seen as a compact more graphical representation
%                  of the resulting xls file; it can be displayed in 2 different ways: a general view or a spt
%                  specific one; the concept is similar in both cases; the left side of the figure consists of
%                  the piechart(s) that represent the entire execution time and the right side holds some tables
%                  with statistics for jobs/debug events. 
%
% %%%% Input parameters:
%   *origContent        = initial raw information (from the hex file)
%   *finalParsedContent = final decoded information (in the xls file)
%   *traceColumns       = columns held by trace
%   *timerFreq          = frequency of timer used to count events
%   *jobPairs           = struct array of (start_idx, end_idx) pairs
%   *sptSpecial         = option for general(0) or spt specific(1) stats 
%
% *************************************************************************
function TraceMakePlots(origContent, finalParsedContent, traceColumns, timerFreq, jobPairs, sptSpecial)
%% Extraction of the basic information required by the figures
% Get timestamp list in microseconds
timestampsList = double(cell2mat(finalParsedContent(:, traceColumns.Timestamp).')) / timerFreq;
% Get info1 list as numeric values
info1NumericList = [origContent.extraInfo1];
% Get info1 list as corresponding text values
info1TextList = string(finalParsedContent(:, traceColumns.Info1).');
% Get entire processing duration
processingDuration = timestampsList(end) - timestampsList(1);
% Get event type list as text values
eventTypeList = string(finalParsedContent(:, traceColumns.Event_Type).');

% Maps holding info1 numeric value as key and corresponding text as value
info1JobMap = containers.Map('KeyType','uint64','ValueType','char');
info1DbgMap = containers.Map('KeyType','uint64','ValueType','char');

% Indices in struct arrays holding timestamps and corresponding info1 
jobIdx = 1;
dbgIdx = 1;

% Variable needed to compute known duration (union of all recorded intervals)
knownIntervals = 0;
lastTimestamp = 0;
unknownDuration = double(0);
jobPairsAux = jobPairs;

% Iterate over the entire list of events
for i=1:length(info1NumericList)
    % Process and hold job related information
    if contains(info1TextList{i}, 'JOB') || contains(eventTypeList{i}, 'FUNC')
        % Map job id to job value
        if ~isKey(info1JobMap, info1NumericList(i))
            info1JobMap(info1NumericList(i)) = info1TextList{i};
        end
        % Hold timestamps and corresponding info1 value for each job
        jobList(jobIdx).Time = timestampsList(i);
        jobList(jobIdx).Info1 = info1NumericList(i);
        jobIdx = jobIdx + 1;
    %end
    else% Process and hold information for debug events
        % Debug events that come in pairs - treated as jobs
        if contains(info1TextList{i}, '_START') || contains(info1TextList{i}, '_END')
            % Add big enough value to dbg info1 to avoid intersection with job info1 numeric values
            info1DbgNrNew = info1NumericList(i);
            if info1DbgNrNew < 10000
                info1DbgNrNew = info1DbgNrNew + 10000;
            end
            % Map debug event id to its value (as job)
            if ~isKey(info1JobMap, info1DbgNrNew)
                % Keep common prefix of info1 text value as value in map
                info1DbgTextNew = regexprep(regexprep(info1TextList{i}, '_START', '_END'), '_END', '');
                info1JobMap(info1DbgNrNew) = info1DbgTextNew;
                % Change the info1 numeric value of all debug events that start with this common prefix
                for j=1:length(info1NumericList)
                    if isequal(info1TextList{j}, strcat(info1DbgTextNew, '_START')) || ...
                        isequal(info1TextList{j}, strcat(info1DbgTextNew, '_END'))
                        info1NumericList(j) = info1DbgNrNew;
                    end
                end
            end
            % Hold timestamps and corresponding info1 value for each debug event (as job)
            jobList(jobIdx).Time = timestampsList(i);
            jobList(jobIdx).Info1 = info1DbgNrNew;
            jobIdx = jobIdx + 1;
        else% Individual debug events
            % Map debug event it to value
            if ~isKey(info1DbgMap, info1NumericList(i))
                info1DbgMap(info1NumericList(i)) = info1TextList{i};
            end
            % Hold timestamp and corresponding info1 value for each debug event
            dbgList(dbgIdx).Time = timestampsList(i);
            dbgList(dbgIdx).Info1 = info1NumericList(i);
            dbgIdx = dbgIdx + 1;
        end
    end
    
    % Process total number of unknown cycles
    % Start event = start of interval
    if ismember(i, [jobPairsAux.JobStartIdx])
        % Multiple possibile open at same time (for incomplete intervals - start at timestamp 0)
        count = 0;
        for j=1:length(jobPairsAux)
            if jobPairsAux(j).JobStartIdx == i
                % If option is to display spt stats separately, spt jobs are considered 'unknown' cycles
                if sptSpecial == 0 || sptSpecial == 1 && ~contains(info1TextList{jobPairsAux(j).JobEndIdx}, 'RSDK_TRACE_DBG_SPT_KERNEL')
                    count = count + 1;
                end
                jobPairsAux(j).JobStartIdx = -1;
            end
        end
        
        % Compute unknown cycles if no known interval is opened to 'cover' them
        if knownIntervals == 0
            unknownDuration = unknownDuration + (timestampsList(i) - lastTimestamp);
            lastTimestamp = timestampsList(i);
        end
        
        % Because a start event is being processed, it can open 1/more interval(s)
        knownIntervals = knownIntervals + count;
    end
    % End event = end of interval
    if ismember(i, [jobPairsAux.JobEndIdx])
        % Because an end event is being processed, it can close an interval
        if sptSpecial == 0 || sptSpecial == 1 && ~contains(info1TextList{i}, 'RSDK_TRACE_DBG_SPT_KERNEL')
            knownIntervals = knownIntervals - 1;
        elseif contains(info1TextList{i}, 'RSDK_TRACE_DBG_SPT_KERNEL')
            % If option is to display spt stats separately, spt jobs are considered 'unknown' cycles
            if knownIntervals == 0
                unknownDuration = unknownDuration + (timestampsList(i) - lastTimestamp);
            end
        end
        lastTimestamp = timestampsList(i);
    end
    % For any other type of event, compute unknown cycles if necessary
    if ~ismember(i, [jobPairsAux.JobStartIdx]) && ~ismember(i, [jobPairsAux.JobEndIdx])
        if knownIntervals == 0
            unknownDuration = unknownDuration + (timestampsList(i) - lastTimestamp);
            lastTimestamp = timestampsList(i);
        end
    end
end % for loop

% Get unknown cycles as percentage value (from entire execution time)
unknownDurationPercentage = round(unknownDuration * 100 / timestampsList(i) * 100) / 100;

% Sort keys (numeric values of info1) in order to get values in order
jobKeys = sort(cell2mat(info1JobMap.keys));
for i=1:length(jobKeys)
    % Make '_' printable in text values
    jobValues{i} = regexprep(info1JobMap(jobKeys(i)), '_', '\\_');
    % Hold an order number for each numeric key (to plot with a nice y axis)
    jobKeysEvenlyDistrib(i) = i;
end

if ~isempty(info1DbgMap)
    % Sort keys (numeric values of info1) in order to get values in order
    dbgKeys = sort(cell2mat(info1DbgMap.keys));
    for i=1:length(dbgKeys)
        % Make '_' printable in text values
        dbgValues{i} = regexprep(info1DbgMap(dbgKeys(i)), '_', '\\_');
        % Hold an order number for each numeric key (to plot with a nice y axis)
        dbgKeysEvenlyDistrib(i) = jobKeysEvenlyDistrib(end) + i;
    end

    % Combine keys and values
    allEventsValues = [jobKeysEvenlyDistrib, dbgKeysEvenlyDistrib];
    allEventsLabels = [jobValues, dbgValues];

    % Map old info1 numeric values to the evenly distributed ones
    dbgInfo1EvenlyDistrib = changem([dbgList.Info1], dbgKeysEvenlyDistrib, dbgKeys);
else
    allEventsValues = [jobKeysEvenlyDistrib];
    allEventsLabels = [jobValues];
end


% Set different colors for job vs debug labels
for i = 1:length(allEventsLabels)
    if i <= length(jobKeysEvenlyDistrib)
        allEventsLabelsColors{i} = ['\color{blue} ' allEventsLabels{i}];
    else
        allEventsLabelsColors{i} = ['\color{magenta} ' allEventsLabels{i}];
    end
end

% Get a set of distict evenly distributed colors from a colormap
colorMap = jet(100);
for i=1:length(allEventsValues)
    colorMapRow = round(length(colorMap) / (length(allEventsValues) + 2)) * i;
    allEventsColors{i} = colorMap(colorMapRow, :);
end

%% Information used by both figures for scaling graphics accordingly
set(0,'units','pixels');
% Get size of screen
figures.ScreenSize = get(0,'screensize');
% Get size of plot window
windowSize = get(gcf, 'Position');
figures.Width = windowSize(3);
figures.Height = windowSize(4);
% Get a 'unit' width and height for some graphical elements
figures.Units = 20;
figures.WidthUnit = figures.Width / figures.Units;
figures.HeightUnit = figures.Height / figures.Units;

%% Figure 1 - Timeline of all events (jobs and debug events)
figureTimeline = figure(1);
clf;
title('Timeline of all events');

% The figure will consist of multiple plots that will give the complete overview
hold on

% Display plots for encountered jobs (one small plot for each job)
for i=1:length(jobPairs)
    % Start and end timestamps of current job - x coordinates 
    timePair = [timestampsList(jobPairs(i).JobStartIdx), timestampsList(jobPairs(i).JobEndIdx)];
    % Start and end corresponding info1 type of current job - y coordinates 
    info1PairValues = [info1NumericList(jobPairs(i).JobEndIdx), info1NumericList(jobPairs(i).JobEndIdx)];
    info1Pair = changem(info1PairValues, jobKeysEvenlyDistrib, jobKeys);
    % Color for current pair
    color = allEventsColors{info1Pair(1)};
    % Plot job as independent interval
    plot(timePair, info1Pair, '-s', 'LineWidth', 2, 'MarkerSize', 10, 'Color', 0.9 * color, 'MarkerFaceColor', color);
    
    % Keep coordinates and text for later duration display on plot
    textPoints(i).ValX = double(timePair(1)) + 0.5;
    textPoints(i).ValY = double(info1Pair(1)) + 0.2;
    textPoints(i).Text = char(string(cell2mat(finalParsedContent(jobPairs(i).JobEndIdx,traceColumns.Micros))) + ' us');
end

if ~isempty(info1DbgMap)
    % Display plot for debug events (one plot with all individual events)
    dbgPoints = plot([dbgList.Time], dbgInfo1EvenlyDistrib, '*m');
    % Keep coordinates for detailed display on plot
    for i=1:length(dbgInfo1EvenlyDistrib)
        % Get timestamp of current debug event - x coordinates
        timeEvt = [dbgList(i).Time, dbgList(i).Time];
        % Get info1 of current event and 0 - y coordinates (used to plot vertical dotted line)
        typeEvt = [0, dbgInfo1EvenlyDistrib(i)];

        % Keep x and y values for each event along with specific color
        dbgPointsDetails(i).ValuesX = timeEvt;
        dbgPointsDetails(i).ValuesY = typeEvt;
        dbgPointsDetails(i).Color = 0.9 * allEventsColors{dbgInfo1EvenlyDistrib(i)};
    end
end

% All plots required have been drawn
hold off

%% Figure 1 - Additional plot config
% Set event labels on y axis (to display info1 text instead of numeric values)
set(gca, 'Ytick', allEventsValues, 'YTickLabel', allEventsLabelsColors);

% Set starting limits on x & y axis
xlim([0 processingDuration]); xlabel('Time[us]');
ylim([0.5 (allEventsValues(end) + 0.5)]);

% Allow zoom and pan only on x axis
plotZoom = zoom(figureTimeline); set(plotZoom,'Motion','horizontal');
plotPan = pan(figureTimeline); set(plotPan,'Motion','horizontal');

if ~isempty(info1DbgMap)
    % Additional info as legend
    legend(dbgPoints, {'Debug Events'})
end

%% Figure 1 - Additional buttons for a more detailed view
% Button position scaled to the window size
buttonPosition = [figures.WidthUnit * (figures.Units - 1.5), figures.Height / 2, figures.WidthUnit * 1, figures.HeightUnit];

% Draw button to show duration of each interval
buttonShowDuration = uicontrol('Parent', figureTimeline, 'Position', buttonPosition, 'Units', 'Normalized');
buttonShowDuration.String = 'Show Duration';
buttonShowDuration.Callback = {@showDuration, buttonShowDuration, textPoints};

if ~isempty(info1DbgMap)
    % Draw button to show where debug event occured
    buttonShowDetails = uicontrol('Parent', figureTimeline, 'Position', buttonPosition, 'Units', 'Normalized');
    buttonShowDetails.String = 'Show Details';
    buttonShowDetails.Callback = {@showDetails, buttonShowDetails, dbgPointsDetails};

    % Place buttons to the right side of the axes
    align(flip([buttonShowDetails buttonShowDuration]), 'Right', 'Fixed', 7);
else
    % Place button to the right side of the axes
    align([buttonShowDuration], 'Right', 'Fixed', 7);
end
%% Figure 2 - Statistics (Piecharts and tables)
figurePie = figure(2);
clf;
title('Statistics');

% Keep stats for each job in a structure array
for i=1:length(jobValues)
    jobStats(i).Total = 0;
    jobStats(i).Percentage = 0;
    jobStats(i).Average = 0;
    jobStats(i).Min = processingDuration;
    jobStats(i).Max = 0;
    jobStats(i).Times = uint32(0);
end

% Keep required info in the structure array
for i=1:length(textPoints)
    % There is a "textPoint" for each job holding duration as text
    eventType = uint32(textPoints(i).ValY - 0.2);
    durationSplit = split(textPoints(i).Text, ' ');
    durationText = durationSplit(1);
    durationValue = round(str2double(durationText) * 100) / 100;
    % Update stats for current event
    jobStats(eventType).Total = jobStats(eventType).Total + durationValue;
    jobStats(eventType).Min = min(jobStats(eventType).Min, durationValue);
    jobStats(eventType).Max = max(jobStats(eventType).Max, durationValue);
    jobStats(eventType).Times = jobStats(eventType).Times + 1;
end

% Compute remaining fields of structure array
for i=1:length(jobValues)
    jobStats(i).Percentage = 100 * jobStats(i).Total / processingDuration;
    if jobStats(i).Percentage == 0
        jobStats(i).Percentage = 0.00001;
    end
    jobStats(i).Average = round((jobStats(i).Total / double(jobStats(i).Times)) * 100) / 100;
    jobStats(i).Color = allEventsColors{i};
end

% Corresponding text for each field in the structure used above (to display in table)
rowNames = {'Total Duration [us]'; 'Total Duration [%]'; 'Average Duration [us]'; 'Min Duration [us]'; 'Max Duration [us]'; 'Times occured'};

% SPT specific stats
if sptSpecial == 1
    % SPT kernel types map (Range/Doppler etc..)
    kerTypesMap = containers.Map('KeyType','char','ValueType','double');
    % Default kernel type (in case others are not defined)
    kerTypesMap('UNKNOWN_KERNEL_TYPE') = 0;

    % Event name to index in array map
    idxMap = containers.Map('KeyType','char','ValueType','uint32');
    idxMap('UNKNOWN_KERNEL_TYPE') = 1;
    % Hold spt kernel info in structure array (as above)
    sptStats(1).Total = double(0);
    sptStats(1).Percentage = double(0);
    sptStats(1).Average = double(0);
    sptStats(1).Min = processingDuration;
    sptStats(1).Max = 0;
    sptStats(1).Times = 0;
    sptStats(1).Color = [0.75 0.75 0.75];
    idx = 2;
    
    % Go through all captured intervals
    for i=1:length(textPoints)
        % Get current job name
        eventType = uint32(textPoints(i).ValY - 0.2);
        eventName = regexprep(allEventsLabels{eventType}, '\\_', '_');

        % If job is spt kernel (start)
        if isequal(eventName, 'RSDK_TRACE_DBG_SPT_KERNEL') && ...
            isequal(info1TextList{jobPairs(i).JobStartIdx}, 'RSDK_TRACE_DBG_SPT_KERNEL_START')
        
            % Get kernel duration
            durationSplit = split(textPoints(i).Text, ' ');
            durationText = durationSplit(1);
            durationValue = round(str2double(durationText) * 100) / 100;

            % Find spt kernel type (must be an event very close to this one)
            posKerType = -1;
            if contains(info1TextList{jobPairs(i).JobStartIdx - 2}, 'RSDK_TRACE_DBG_APP_KER_')
                posKerType = 2;
            elseif contains(info1TextList{jobPairs(i).JobStartIdx - 3}, 'RSDK_TRACE_DBG_APP_KER_')
                posKerType = 3;
            end

            % Centralize duration based on kernel type
            if posKerType < 0
                % If no specific type was found, use default UNKNOWN
                disp 'No SPT kernel type found...'
                kerTypesMap('UNKNOWN_KERNEL_TYPE') = kerTypesMap('UNKNOWN_KERNEL_TYPE') + durationValue;
                % Update stats in structure array
                sptStats(1).Min = min(sptStats(1).Min, durationValue);
                sptStats(1).Max = max(sptStats(1).Max, durationValue);
                sptStats(1).Times = sptStats(1).Times + 1;
            else
                % If specific type was found (through a dbg evt) keep its info1 text value
                kerTypeName = info1TextList{jobPairs(i).JobStartIdx - posKerType};
                
                % First occurance => map and initialize struct array element
                if ~isKey(kerTypesMap, kerTypeName)
                    kerTypesMap(kerTypeName) = durationValue;
                    
                    sptStats(idx).Total = double(0);
                    sptStats(idx).Percentage = double(0);
                    sptStats(idx).Average = double(0);
                    sptStats(idx).Min = durationValue;
                    sptStats(idx).Max = durationValue;
                    sptStats(idx).Times = uint32(1);
                    
                    info1Nr = [info1NumericList(jobPairs(i).JobStartIdx - posKerType)];
                    info1NrEven = changem(info1Nr, dbgKeysEvenlyDistrib, dbgKeys);
                    sptStats(idx).Color = allEventsColors{info1NrEven};
                        
                    idxMap(kerTypeName) = idx;
                    idx = idx + 1;
                else% Not first occurance => update existing information
                    kerTypesMap(kerTypeName) = kerTypesMap(kerTypeName) + durationValue;
                    
                    currentIdx = idxMap(kerTypeName);
                    sptStats(currentIdx).Min = min(sptStats(currentIdx).Min, durationValue);
                    sptStats(currentIdx).Max = max(sptStats(currentIdx).Max, durationValue);
                    sptStats(currentIdx).Times = sptStats(currentIdx).Times + 1;
                end
            end
        end
    end

    % Gey array of spt kernel types and total spt processing time
    allKerTypes = kerTypesMap.keys;
    allKerDurations = kerTypesMap.values;
    allKerTime = sum([allKerDurations{:}]);

    for i=1:length(kerTypesMap)
        % Remove kernel type if duration is 0
        if (kerTypesMap(allKerTypes{i}) == 0)
            remove(kerTypesMap, allKerTypes{i});
            remove(idxMap, allKerTypes{i});
        else% Update remaining stats is struct array
            idx = idxMap(allKerTypes{i});
            sptStats(idx).Total = kerTypesMap(allKerTypes{i});
            sptStats(idx).Percentage = kerTypesMap(allKerTypes{i}) * 100 / processingDuration;
            sptStats(idx).Average = round((sptStats(idx).Total / double(sptStats(idx).Times)) * 100) / 100;
        end
    end

    % Compute spt idle time
    sptIdleTime = processingDuration - allKerTime;

    % Get array of corresponding colors in correct order
    allKerTypes = kerTypesMap.keys;
    for i=1:length(allKerTypes)
        index = idxMap(allKerTypes{i});
        sptColors{i} = sptStats(index).Color;
    end
    % Add grey for the 'idle' portion of the pie
    sptColors{i+1} = [0.5 0.5 0.5];
    
    %% Figure 2 - SPT piechart - all kernel types as fixed distinct slices
    subplot(2, 2, 3);
    pie([cell2mat(kerTypesMap.values), sptIdleTime], [regexprep(kerTypesMap.keys, '.*', ''), 'IDLE']);
    colormap(gca, cell2mat(sptColors.'));
    title('SPT Execution');

    % Spt piechart legend
    legend(regexprep(kerTypesMap.keys, '_', '\\_'), 'Location', [figures.Width / figures.Height / 20, 1 / 4, 0.1, 0.1], 'Orientation', 'vertical', 'FontSize', 8);
    
    %% Figure 2 - SPT Textbox & drop down menu
    % Textbox
    sptText = ['SPT execution time: ' char(string(allKerTime)) ' us (' char(string(round(allKerTime * 100 / processingDuration * 100) / 100)) '% from total time)'];
    annotation('textbox', [1 / 3 * 2 - 0.15 , 1 / 12 * 4, 0.3, 0.1], 'String', sptText, 'FitBoxToText', 'off', 'HorizontalAlignment', 'center');

    % Drop down
    sptDropDown = uicontrol(figurePie, 'Style', 'popupmenu','FontSize', 10);
    sptDropDown.Position = [figures.Width / 3 * 2 - 60, figures.Height / 12 * 4, 120, 20];
    sptDropDown.Units = 'normalized';
    sptDropDown.String = regexprep(kerTypesMap.keys, '\\_', '_');
    sptDropDown.Callback = {@dropDownCbSpt, sptDropDown, sptStats, idxMap};
    
    %% Figure 2 - SPT Table (with statistics for each kernel type)
    columnData = struct2cell(sptStats(idxMap(allKerTypes{1})));

    % Draw spt jobs table   
    global sptTable;
    sptTable = uitable(figurePie,'Data',columnData(1:end-1), 'RowName', rowNames, ...
        'ColumnName', regexprep(allKerTypes{1}, '\\_', '_'), 'ColumnWidth', {220}, ...
        'FontSize', 10, 'ColumnFormat', {'bank'});

    % Get proper height and width based on screen size and data to display
    jobTableExtent = get(sptTable,'Extent');
    tableHeight = jobTableExtent(4) * figures.Height / figures.ScreenSize(4) + 10;
    tableWidth = jobTableExtent(3) * figures.Width / figures.ScreenSize(3);
    sptTable.Position(3:4) = [tableWidth, tableHeight];
    sptTable.Position(1:2) = [figures.Width / 3 * 2 - tableWidth / 2, figures.Height / 12 * 2 - tableHeight / 3];
    sptTable.Units = 'normalized';
end
%% Figure 2 - Main piechart
if sptSpecial == 1
    % Prepare subplot and name for core display
    subplot(2, 2, 1);
    mainPieName = 'Core Execution';
else% No spt specific pie and stats
    % Display piechart in left half of figure
    subplot(1, 2, 1);
    mainPieName = 'Entire Execution';
end

% If spt stats are displayed separately - remove them from the rest of the stats
if sptSpecial == 1
   for i=1:length(jobStats)
      if isequal(regexprep(jobValues{i}, '\\_', '_'), 'RSDK_TRACE_DBG_SPT_KERNEL')
          jobValues(i) = [];
          jobStats(i) = [];
      end
   end
end

% Draw main pie for entire execution (with or without spt depending on the chosen option)
global menuHandle;
menuHandle = pie([jobStats(1).Percentage, 100 - jobStats(1).Percentage - unknownDurationPercentage, unknownDurationPercentage], {'', 'KNOWN', 'UNKNOWN'});
colormap(gca, [jobStats(1).Color; [0.75 0.75 0.75]; [0.5 0.5 0.5]]);
title(mainPieName);

% Legend for main pie
if sptSpecial == 1
    legend({jobValues{1}}, 'Location', [figures.Width / figures.Height / 20, 3 / 4, 0.1, 0.01], 'Orientation', 'vertical', 'FontSize', 8);
else
    legend({jobValues{1}}, 'Location', 'southoutside', 'Orientation', 'vertical', 'FontSize', 8);    
end

%% Figure 2 - Main Stats - Textbox & drop down menu
% Draw job drop down menu with available options
dropDown = uicontrol(figurePie, 'Style', 'popupmenu','FontSize', 10);
% Position the menu and corresponding textbox accordingly
if sptSpecial == 1
    dropDown.Position = [figures.Width / 3 * 2 - 60, figures.Height / 12 * 10, 120, 20];
    coreKnownTime = processingDuration - unknownDuration;
    jobText = ['Core execution time: ' char(string(coreKnownTime)) ' us (' char(string(100 - unknownDurationPercentage)) '% from total time)'];
    annotation('textbox', [1 / 3 * 2 - 0.15 , 1 / 12 * 10, 0.3, 0.1], 'String', jobText, 'FitBoxToText', 'off', 'HorizontalAlignment', 'center');
else
    dropDown.Position = [figures.Width / 3 * 2 - 60, figures.Height / 4 * 3, 120, 20];
    jobText = ['Total application execution time: ' char(string(processingDuration)) ' us'];
    annotation('textbox', [1 / 3 * 2 - 0.15 , 1 / 6 * 4.5, 0.3, 0.1], 'String', jobText, 'FitBoxToText', 'off', 'HorizontalAlignment', 'center');
end
% Additional settings for the drop down menu
dropDown.Units = 'normalized';
dropDown.String = regexprep(jobValues, '\\_', '_');
dropDown.Callback = {@dropDownCb, dropDown, jobStats, jobValues, unknownDurationPercentage, mainPieName, sptSpecial, figures};

%% Figure 2 - Main Stats - Table holding job related information
% Draw table holding job stats  
columnData = struct2cell(jobStats(1));

global jobTable;
jobTable = uitable(figurePie,'Data',columnData(1:end - 1), 'RowName', rowNames, ...
    'ColumnName', regexprep(jobValues{1}, '\\_', '_'), 'ColumnWidth', {220}, ...
    'FontSize', 10, 'ColumnFormat', {'bank'});

% Get proper height and width based on screen size and data to display
jobTableExtent = get(jobTable,'Extent');
tableHeight = jobTableExtent(4) * figures.Height / figures.ScreenSize(4) + 10;
tableWidth = jobTableExtent(3) * figures.Width / figures.ScreenSize(3);
jobTable.Position(3:4) = [tableWidth, tableHeight];

% Set table position depending on the display mode
if sptSpecial == 1
    jobTable.Position(1:2) = [figures.Width / 3 * 2 - tableWidth / 2, figures.Height / 12 * 8 - tableHeight / 3];
    jobTable.Units = 'normalized';
else
    jobTable.Position(1:2) = [figures.Width / 3 * 2 - tableWidth / 2, figures.Height / 2 - tableHeight / 2];
    jobTable.Units = 'normalized';
end

%% Figure 2 - Main Stats - Table holding debug events information

if ~isempty(info1DbgMap) && sptSpecial == 0
    % Plot debug event table if the display mode is the general one
    % Count occurances of each debug event
    dbgOccurances = zeros(1, length(dbgKeys));
    for i=1:length(dbgInfo1EvenlyDistrib)
        dbgType = dbgPointsDetails(i).ValuesY(2) - length(jobValues);
        dbgOccurances(dbgType) = dbgOccurances(dbgType) + 1;
    end

    % Draw table with debug event data
    eventTableData = [regexprep(dbgValues, '\\_', '_').', num2cell(dbgOccurances.')];%[num2cell(test1), num2cell(test1)];%
    eventTable = uitable(figurePie,'Data',eventTableData,'ColumnName',{'Debug Event', 'Occurances'}, 'ColumnWidth',{300, 120},'FontSize', 10);

    % Get proper height and width based on screen size and data to display
    eventTableExtent = get(eventTable,'Extent');
    tableHeight = min((eventTableExtent(4) + 10) * figures.Height / figures.ScreenSize(4), figures.Height / 4 - 16);
    extraWidth = 0;
    if tableHeight >= floor(figures.Height / 4) - 16
        extraWidth = 16;
    end
    tableWidth = (eventTableExtent(3) + extraWidth) * figures.Width / figures.ScreenSize(3);
    eventTable.Position(3:4) = [tableWidth, tableHeight];
    eventTable.Position(1:2) = [figures.Width / 3 * 2 - tableWidth / 2, figures.Height / 4 - tableHeight / 2];
    eventTable.Units = 'normalized';
end

end

%% Callback function for the durations button
function showDuration(~, ~, textButton, textPoints)
global textHandle;
if isequal(textButton.String, 'Show Duration')
    % Display durations and change button text
    textHandle = text([textPoints.ValX], [textPoints.ValY], {textPoints.Text}, 'Color', 'blue');
    set(textHandle, 'Clipping', 'on');
    set(textButton, 'String', 'Hide Duration');        
else
    % Remove durations and change button text
    delete(textHandle);
    set(textButton, 'String', 'Show Duration');
end
end

%% Callback function for the details button
function showDetails(~, ~, detailsButton, dbgPointsDetails)
global detailsHandle;
hold on
if isequal(detailsButton.String, 'Show Details')
    % Plot additional info and change button text
    for i=1:length(dbgPointsDetails)
        detailsHandle(i) = plot(dbgPointsDetails(i).ValuesX, dbgPointsDetails(i).ValuesY, 'LineStyle', '--', 'Color', dbgPointsDetails(i).Color);
    end
    set(detailsButton, 'String', 'Hide Details');        
else
    % Delete additional info and change button text
    for i=1:length(dbgPointsDetails)
        delete(detailsHandle(i));
    end
    set(detailsButton, 'String', 'Show Details');
end
hold off
end

%% Callback function for the drop down menu used for general job stats
function dropDownCb(~, ~, dropDown, jobStats, jobValues, unknownDuration, menuTitle, sptSpecial, figures)
% Get string chosen through drop down menu
val = dropDown.Value;

% Re-draw main pie for the chosen job
global menuHandle;
menuHandle = pie([jobStats(val).Percentage, 100 - jobStats(val).Percentage - unknownDuration, unknownDuration], {'', 'KNOWN', 'UNKNOWN'});
colormap(gca, [jobStats(val).Color; [0.75 0.75 0.75]; [0.5 0.5 0.5]]);
title(menuTitle);

% Update table information accordingly
columnData = struct2cell(jobStats(val));
global jobTable
jobTable.Data = columnData(1:end - 1);
jobTable.ColumnName = regexprep(jobValues{val}, '\\_', '_');

% Re-draw legend for main pie
if sptSpecial == 1
    legend({jobValues{val}}, 'Location', [figures.Width / figures.Height / 20, 3 / 4, 0.1, 0.01], 'Orientation', 'vertical', 'FontSize', 8);
else
    legend({jobValues{val}}, 'Location', 'southoutside', 'Orientation', 'vertical', 'FontSize', 8);    
end

end

%% Callback function for the drop down menu used for spt stats
function dropDownCbSpt(~, ~, dropDown, sptStats, idxMap)
% Get string chosen from menu (and corresponding index in stats array)
val = dropDown.Value;
str = dropDown.String;
idx = idxMap(str{val});

% Update table with corresponding information
columnData = struct2cell(sptStats(idx));
global sptTable
sptTable.Data = columnData(1:end-1);
sptTable.ColumnName = regexprep(str{val}, '\\_', '_');
end