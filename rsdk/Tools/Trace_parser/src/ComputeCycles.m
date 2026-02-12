%{
    Copyright 2017-2021, 2023-2024 NXP
    NXP Confidential and Proprietary. This software is owned or controlled by NXP and
    may only be used strictly in accordance with the applicable license terms.  By
    expressly accepting such terms or by downloading, installing, activating and/or
    otherwise using the software, you are agreeing that you have read, and that you
    agree to comply with and are bound by, such license terms.  If you do not agree to
    be bound by the applicable license terms, then you may not retain, install, activate or
    otherwise use the software.
%}

% %%%% Description: 
% Computes application cycles: delta between function start and end events.
%   *jobs:  'appCycles' for a job must be evaluated between one event of 'eventType' START and
%           one event of 'eventType' END; these 2 must have the same 'info1' value
%   *dbg evts:  'appCycles' for a pair of debug events must be evaluated between two events of
%               'eventType' DBG with the same 'info1' prefix; 'info1' should end differently (_START/_END)
%
% %%%% Input parameters:
%   *eventTypeList  = cell array containing the types of all recorded events
%   *timestampList  = row vector containing all recorded timestamps
%   *info1List      = cell array with the info1 value for all captured events
%
% %%%% Output parameters:
%   *appCycles      = cell array with the computed application cycles (written in xls file)
%   *allJobPairs    = struct array with all identified event pairs (help with plots)
% *************************************************************************
function [ appCycles, allJobPairs ] = ComputeCycles(eventTypeList, timestampList, info1List)
num_events = numel(timestampList);
appCycles = cell(num_events,1);
jobPairs(1) = struct('JobStartIdx',[],'JobEndIdx',[]);

% Keep first recorded timestamp
timestampFirst = timestampList(1);

% Counter for keeping track of pair events
pairIdx = 1;
incompleteIdx = 1;

% Keep separate first indices for timestamps (if kernel trace is available)
appFirstIdx = 0;
linkerFirstIdx = 0;

for i=1:num_events
    if isstr(info1List{i})
        if ~contains(info1List{i}, 'LINKER') && appFirstIdx == 0
            appFirstIdx = i;
        elseif contains(info1List{i}, 'LINKER') && linkerFirstIdx == 0
            linkerFirstIdx = i;
        end
    end
    
    switch eventTypeList{i}
        case 'RSDK_TRACE_EVENT_FUNC_START'
            % Keep start index for identified job
            jobPairs(pairIdx).JobStartIdx = i;
            pairIdx = pairIdx + 1;
        case 'RSDK_TRACE_EVENT_FUNC_END'
            % Keep end index for identified job if log caught END but lost START
            appCycles{i} = timestampList(i) - timestampFirst;
            
            % Flag the fact that the start event was not captured
            incomplete = true;
            
            % Look for matching pair index
            for j=pairIdx-1:-1:1
                % Corresponding START job must have the same 'info1' value
                if isequal(info1List{i}, info1List{jobPairs(j).JobStartIdx})
                    % Compute correct app cycles value
                    diff = DiffTimestamps([timestampList(i)], [timestampList(jobPairs(j).JobStartIdx)]);
                    appCycles{i} = diff(1);
                    
                    % Keep end index for identified interval
                    jobPairs(j).JobEndIdx = i;
                    incomplete = false;
                    break
                end
            end
            
            % If no corresponding START job was recorded, keep job as incomplete
            if incomplete == true
                % Earliest timestamp differs for user/kernel space (if kernel trace is available)
                if isstr(info1List{i})
                    if contains(info1List{i}, 'LINKER')
                        incompleteJobPairs(incompleteIdx).JobStartIdx = linkerFirstIdx;
                        incompleteJobPairs(incompleteIdx).JobEndIdx = i;
                        incompleteIdx = incompleteIdx + 1;
                    else
                        incompleteJobPairs(incompleteIdx).JobStartIdx = appFirstIdx;
                        incompleteJobPairs(incompleteIdx).JobEndIdx = i;
                        incompleteIdx = incompleteIdx + 1;
                    end
                end
            end
        case 'RSDK_TRACE_EVENT_DBG_INFO'
            if isstr(info1List{i})
                % Check if debug info1 has START/END
                if contains(info1List{i}, 'START')
                    % Keep start index for identified debug event
                    jobPairs(pairIdx).JobStartIdx = i;
                    pairIdx = pairIdx + 1;
                elseif contains(info1List{i}, 'END')
                    % Keep end index for identified debug event if log caught END but lost START
                    appCycles{i} = timestampList(i) - timestampFirst;

                    % Flag the fact that the start event was not captured
                    incomplete = true;

                    % Look for matching pair index
                    for j=pairIdx-1:-1:1
                        % Corresponding START debug event must have the same 'info1' prefix
                        if isequal(regexprep(info1List{i}, 'END', 'START'), info1List{jobPairs(j).JobStartIdx})
                            % Compute correct app cycles value
                            diff = DiffTimestamps([timestampList(i)], [timestampList(jobPairs(j).JobStartIdx)]);
                            appCycles{i} = diff(1);

                            % Keep end index for identified interval
                            jobPairs(j).JobEndIdx = i;
                            incomplete = false;
                            break
                        end
                    end

                    % If no corresponding START debug event was recorded, keep as incomplete job
                    if incomplete == true
                        % Earliest timestamp differs for user/kernel space (if kernel trace is available)
                        if contains(info1List{i}, 'LINKER')
                            incompleteJobPairs(incompleteIdx).JobStartIdx = linkerFirstIdx;
                            incompleteJobPairs(incompleteIdx).JobEndIdx = i;
                            incompleteIdx = incompleteIdx + 1;
                        else
                            incompleteJobPairs(incompleteIdx).JobStartIdx = appFirstIdx;
                            incompleteJobPairs(incompleteIdx).JobEndIdx = i;
                            incompleteIdx = incompleteIdx + 1;
                        end
                    end
                end
            end
        otherwise
            % do nothing
    end
end

% Combine all identified pairs in one array
if incompleteIdx > 1
    combinedJobPairs = [jobPairs, incompleteJobPairs];
else
    combinedJobPairs = jobPairs;
end

% Remove any job that has a START but no END event (this should not really happen)
allIdx = 1;
allJobPairs(1) = struct('JobStartIdx',[],'JobEndIdx',[]);
for i=1:length(combinedJobPairs)
    if isfield(combinedJobPairs(i), 'JobEndIdx')
        if ~isempty(combinedJobPairs(i).JobEndIdx)
            allJobPairs(allIdx) = combinedJobPairs(i);
            allIdx = allIdx + 1;
        end 
    end
end
end

