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

% Function creates a map between jobs and their corresponding values. 
% Input parameters:
%       1. baseList - the list of trace modules and their base indices
%               - It has the form <module_name_1>, <base_1>, <module_name_2>, <base_2>, ...  
%       2. enumElem - the list of jobs/debug info   
%               - first element contains information about the base index
%               - the value of each element should be computed according to
%                 this index
% Output parameter: map of jobs/debug info and their values

function out = GetMapObject(enumElem, baseList)
% baseList represents the list of trace modules and the corresponding base
% indices
% It has the form <module_name_1>, <base_1>, <module_name_2>, <base_2>, ... 

lineElem = split(enumElem{1}, '=');
jobType = char(strtrim(lineElem(2)));

% Index of module name in the list of trace modules
baseNameIndex = find(~cellfun('isempty',strfind(baseList, jobType)));
% The corresponsing job base is the next element in this list
jobBase = str2double(baseList{baseNameIndex+1});    

% Initialize mapObj with the first job in enum (corresponding to the base)
mapObj = containers.Map(jobBase, strtrim(char(lineElem(1))));
% Add the remaining jobs in the map at the corresponding position
for i = 1:length(enumElem)-1
    mapObj(jobBase+i) = strtrim(enumElem{i+1});    
end
out = mapObj;