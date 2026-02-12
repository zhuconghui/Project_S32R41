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
% Write data to xls file:
function num_rows = TraceWriteToFile( parsedContent, traceColumns, outputFileName)

disp(['Writing trace to xls...']);

if(~isempty(parsedContent))
    
%     outputFileName = [binaryTraceFileName(1:end-4), '.xlsx'];
    if exist(outputFileName,'file')
        fprintf('\n Deleting existing file: %s\n', outputFileName);
        delete(outputFileName);
    end
    
    MAX_NUM_XLS_ROWS = 75000;
    num_rows = size(parsedContent, 1);
    
    if( num_rows > MAX_NUM_XLS_ROWS)
        rows_to_print = (num_rows - MAX_NUM_XLS_ROWS) : num_rows;
        fprintf('\n WARNING: The number of events parsed from the input data file is larger than the maximum number of rows allowed by "xlswrite". \n Only the most recent %d events will be printed to <%s>. \n\n',MAX_NUM_XLS_ROWS, outputFileName);
    else
        rows_to_print = 1 : num_rows;
    end
    
    traceHeader = fieldnames(traceColumns).';
    xlswrite(outputFileName, [traceHeader; parsedContent(rows_to_print, :)]);
    
    fprintf('Output has been printed to <%s> \n', outputFileName);
end

