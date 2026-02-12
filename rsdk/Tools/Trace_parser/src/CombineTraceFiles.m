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

% Combines events from multiple trace files.
function origContent = CombineTraceFiles(eventList, configOptions, binaryTraceFileName)

% File name for getting lax graph names
global txtLaxFileName
txtLaxFileName = '';

origContent = eventList;

% Parse kernel trace if necessary
if configOptions.kernelTrace == true
    % Kernel file name
    binaryTraceFileNameSplit = strsplit(binaryTraceFileName, '.hex');
    kernelBinaryTraceFileName = char(binaryTraceFileNameSplit(1) + string('_kernel.hex'));
    
    % Modify parsed content only if kernel trace exists
    if exist(kernelBinaryTraceFileName, 'file') == 2
        % Read  kernel trace file
        kernelEventList = TraceReadRawData(kernelBinaryTraceFileName, configOptions.endianness);
        
        % Combine trace events from both files
        combinedEventList = [eventList; kernelEventList];
        
        % Sort struct array based on timestamp
        for j=1:length(combinedEventList)-1
            for k=j:length(combinedEventList)
                if (combinedEventList(j).timestamp > combinedEventList(k).timestamp)
                    aux = combinedEventList(j);
                    combinedEventList(j) = combinedEventList(k);
                    combinedEventList(k) = aux;
                end
            end
        end
        
        origContent = combinedEventList;
    end
end

% Parse LAX trace if necessary
if configOptions.laxTrace == true
    laxBinaryTraceFileName = configOptions.laxFile;
    
    % Modify parsed content only if lax trace exists
    if exist(laxBinaryTraceFileName, 'file') == 2
        txtLaxFileName = regexprep(configOptions.laxFile, '.hex', '.txt');

        % Read the lax trace .hex file
        laxEventList = TraceReadRawData(laxBinaryTraceFileName, configOptions.endianness);

        % Adjust original timestamps (core specific) in case of wraparound
        origContentTimestamps = LinearTime([origContent.timestamp]);
        for i=1:length(origContent)
            origContent(i).timestamp = origContentTimestamps(i);
        end
        
        % Get lax timestamps and adjust them to the core frequency
        laxTimestampList = [laxEventList.timestamp];
        laxTimestampList = LinearTime(laxTimestampList);
        laxTimestampList = round(laxTimestampList * configOptions.timerFreq / 400);
        
        % Find core-lax designated sync event to combine timestamps
        for i=1:length(origContent)
           if origContent(i).eventType == 5
               laxTimestampList = laxTimestampList + origContent(i).timestamp;
               break;
           end 
        end
        
        % Adjust lax timestamps with corresponding offset
        if i < length(origContent)
            for i=1:length(laxTimestampList)
                laxEventList(i).timestamp = laxTimestampList(i);
            end 
        end
        
        % Combine all events
        combinedEventList = [origContent; laxEventList];
        
        % Sort struct array based on timestamp
        for j=1:length(combinedEventList)-1
            for k=j:length(combinedEventList)
                if (combinedEventList(j).timestamp > combinedEventList(k).timestamp)
                    aux = combinedEventList(j);
                    combinedEventList(j) = combinedEventList(k);
                    combinedEventList(k) = aux;
                end
            end
        end
        
        origContent = combinedEventList;
    end
end

end