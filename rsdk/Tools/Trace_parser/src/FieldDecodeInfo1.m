%{
    Copyright 2017-2018,2020-2024 NXP
    NXP Confidential and Proprietary. This software is owned or controlled by NXP and
    may only be used strictly in accordance with the applicable license terms.  By
    expressly accepting such terms or by downloading, installing, activating and/or
    otherwise using the software, you are agreeing that you have read, and that you
    agree to comply with and are bound by, such license terms.  If you do not agree to
    be bound by the applicable license terms, then you may not retain, install, activate or
    otherwise use the software.
%}

function [ parsedInfo1 ] = FieldDecodeInfo1(appHeaderName, eventTypeList, traceTypeLists, extraInfo1List, laxTrace)
sptDriverHeaderName = '../../../SPT/SPT_driver/include/common/Spt_Internals_Types.h';
csi2HeaderName = '../../../CSI2/CSI2_Driver/include/specific/csi2_driver_platform_trace.h';
laxDriverHeaderName = '../../../LAX/LAX_host/driver/lax_user/inc/rsdk_lax_internal.h';
dspDispHeaderName = '../../../DSP/DSP_common/include/dsp_trace.h';

% List of job and debug bases for each module
jobBaseList = traceTypeLists.jobTypeList;
dbgBaseList = traceTypeLists.dbgTypeList;

% Read SPT driver header file
[jobTypeListSPT, dbgTypeListSPT]   = ReadModuleHeader(sptDriverHeaderName);
% Read CSI2 client header file
[jobTypeListCsi2, dbgTypeListCsi2] = ReadModuleHeader(csi2HeaderName);
% Read LAX driver header file
[jobTypeListLAX, dbgTypeListLAX] = ReadModuleHeader(laxDriverHeaderName);
% Read SPT driver header file
[jobTypeListDSP, dbgTypeListDSP]   = ReadModuleHeader(dspDispHeaderName);

% Read header file containing job types and debug events specific to the
% user-defined module
[jobTypeListApp, dbgTypeListApp] = ReadModuleHeader(appHeaderName);

% Create maps for jobs and debug info for each module
% User defined module
if (~isempty(jobTypeListApp))
    jobMapApp = GetMapObject(jobTypeListApp, jobBaseList);
else
    jobMapApp = containers.Map('KeyType','double','ValueType','char');
end

if (~isempty(dbgTypeListApp))
    dbgInfoMapApp = GetMapObject(dbgTypeListApp, dbgBaseList);
else
    dbgInfoMapApp = containers.Map('KeyType','double','ValueType','char');
end

% SPT module
if (~isempty(jobTypeListSPT))
    jobMapSPT = GetMapObject(jobTypeListSPT,  jobBaseList);
else
    jobMapSPT = containers.Map('KeyType','double','ValueType','char');
end

if (~isempty(dbgTypeListSPT))
    dbgInfoMapSPT = GetMapObject(dbgTypeListSPT,  dbgBaseList);
else
    dbgInfoMapSPT = containers.Map('KeyType','double','ValueType','char');
end

% CSI2 module
if (~isempty(jobTypeListCsi2))
    jobMapCsi2 = GetMapObject(jobTypeListCsi2, jobBaseList);
else
    jobMapCsi2 = containers.Map('KeyType','double','ValueType','char');
end

if (~isempty(dbgTypeListCsi2))
    dbgInfoMapCsi2 = GetMapObject(dbgTypeListCsi2, dbgBaseList);
else
    dbgInfoMapCsi2 = containers.Map('KeyType','double','ValueType','char');
end

% LAX module
if (~isempty(jobTypeListLAX))
    jobMapLAX = GetMapObject(jobTypeListLAX, jobBaseList);
else
    jobMapLAX = containers.Map('KeyType','double','ValueType','char');
end

if (~isempty(dbgTypeListLAX))
    dbgInfoMapLAX = GetMapObject(dbgTypeListLAX, dbgBaseList);
else
    dbgInfoMapLAX = containers.Map('KeyType','double','ValueType','char');
end

if (laxTrace)
    laxGraphMap = ReadLaxTraceTxt();
else
    laxGraphMap = containers.Map('KeyType','double','ValueType','char');
end

% DSP Dispatcher
if (~isempty(jobTypeListDSP))
    jobMapDSP = GetMapObject(jobTypeListDSP,  jobBaseList);
else
    jobMapDSP = containers.Map('KeyType','double','ValueType','char');
end

if (~isempty(dbgTypeListDSP))
    dbgInfoMapDSP = GetMapObject(dbgTypeListDSP,  dbgBaseList);
else
    dbgInfoMapDSP = containers.Map('KeyType','double','ValueType','char');
end


% Get unified maps for jobs and debug info 
completeJobMap = [jobMapApp; jobMapSPT; jobMapCsi2; jobMapLAX; laxGraphMap; jobMapDSP];
completeDbgInfoMap = [dbgInfoMapApp; dbgInfoMapSPT; dbgInfoMapCsi2; dbgInfoMapLAX; dbgInfoMapDSP];

num_events = numel(extraInfo1List);
parsedInfo1 = cell(num_events,1);

for i=1:num_events
    switch eventTypeList{i}
        case {'RSDK_TRACE_EVENT_FUNC_START'; 'RSDK_TRACE_EVENT_FUNC_END'}
            if isKey(completeJobMap,{extraInfo1List(i)})
                parsedInfo1(i) = values(completeJobMap,{extraInfo1List(i)});
            else
                parsedInfo1(i) = {extraInfo1List(i)};
            end
        case 'RSDK_TRACE_EVENT_DBG_INFO'
            if isKey(completeDbgInfoMap,{extraInfo1List(i)})
                parsedInfo1(i) = values(completeDbgInfoMap,{extraInfo1List(i)});
            else
                parsedInfo1(i) = {extraInfo1List(i)};
            end
        otherwise
            parsedInfo1(i) = {extraInfo1List(i)};
    end
end
