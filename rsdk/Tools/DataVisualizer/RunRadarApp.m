% *************************************************************************
% NXP Confidential Proprietary
% Copyright 2017-2021 NXP
% All Rights Reserved
% *************************************************************************
% NXP Confidential and Proprietary. This software is owned or controlled by NXP and
% may only be used strictly in accordance with the applicable license terms.  By
% expressly accepting such terms or by downloading, installing, activating and/or
% otherwise using the software, you are agreeing that you have read, and that you
% agree to comply with and are bound by, such license terms.  If you do not agree to
% be bound by the applicable license terms, then you may not retain, install, activate or
% otherwise use the software.
% *************************************************************************
function RunRadarApp(varargin)
% INPUT arguments:
% chip        - 's32r274', 's32r372', 's32r294', 's32r45', 's32r41'
% frontEnd    - 'tef810x' or 'tef82xx'   
% cfgSource   - 'pc' or 'rtp'
% dataFolder  - '../data/' or <any_other> 
% dataView    - 'compact' or 'detailed'
% dataMode    - 'cont' or 'fbf' (frame by frame)
% rfeConfig   - 'config_<ID>'

[chip, frontEnd,cfgSource, dataFolder, dataView, dataMode, rfeConfig, radarCycle, radarFrame] = InputParameterHandler(nargin,varargin);
fprintf('HW Platform: %s\n', chip);
fprintf('Front-end:  %s\n', frontEnd);
fprintf('RFE Config:  %s\n', rfeConfig);
fprintf('Radar Cycle:  %s\n', radarCycle);
fprintf('Radar Frame:  %s\n', radarFrame);
fprintf('Config source:  %s\n', cfgSource);
fprintf('Data view:  %s\n',dataView);
fprintf('Data folder:  %s\n', dataFolder);
fprintf('Data mode:  %s\n', dataMode);

% Solve paths
if ~isdeployed
    addpath(genpath('../')); % <rsdk_root>/Tools/
end

% Initialize constants
global CONST
CONST = init_CONST(chip);
CONST.HW = upper(chip);
CONST.endian = "ieee-be";
CONST.DATA_CHAN.RTP = 1;
CONST.DATA_CHAN.TFTP = 2;
CONST.DATA_CHAN.UART = 3;
CONST.MAX_INT16 = 2^15;
CONST.MAX_INT24 = 2^23;
CONST.MAX_NR_PEAKS = 128;
CONST.C = 3*10^8;
CONST.dataInFolder  = [dataFolder 'in/',chip,'/'];
CONST.dataOutFolder = [dataFolder 'out/',chip,'/'];
semaFileName  = [CONST.dataOutFolder 'sema.dat'];

rtpChan = [];

global profilingInfo
global appState
appState = 'run';

% Init RTP
if (strcmp(cfgSource, 'rtp'))
    RtpStreamInit()
    
    cfgStream = [];
    configFileName = 'gAppConfig.ini';
    
    % Wait to receive config via RTP
    while(isempty(cfgStream))
        cfgStream = rtpstream('getnext',0);
    end
    
    % Update config file
    fid = fopen(configFileName,'w');
    fwrite(fid,cfgStream);
    fclose(fid);
else
    configFileName = [CONST.dataInFolder chip '_' frontEnd '_config_0.ini'];
end

% Set config to uninitialized state
updateConfigFlag = 1; 

%% Main loop
frame = 0;

% Used to display GUI elements based on the window size
pos = get(gcf, 'Position');
figWidth = pos(3);
figHeight = pos(4);
profilingInfo.unitWidth = figWidth  / 10;
profilingInfo.unitHeight = figHeight / 20;
profilingInfo.redrawElems = 1;
      
while (~strcmp(appState,'stop'))   
    if (updateConfigFlag)        
        % Read new config from file and update app config
        configFileLines = readIniFile(configFileName);
        
        [gAppConfig] = DecodeConfigList(configFileLines);
        gAppConfig.csi2StatsEnable = gAppConfig.sigProcEnable;
        
        if strcmp(frontEnd,'tef810x')
            gAppConfig.RF.nrBistSamples = 2048;
        else
            if  strcmp(frontEnd,'tef82xx')
                gAppConfig.RF.nrBistSamples = 128;
            end
        end
        gAppConfig.RF.nrBistTests   = 2; % LNA and Mixer
        
        % Init/Re-Init RTP channels if necessary
        if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
            if (gAppConfig.profilingInfo.active)
            % Parse the lines to get a string of corresponding names for each
            profilingInfo.stagesNameList = strsplit(char(gAppConfig.profilingInfo.stagesNameLine), ',');
            profilingInfo.eventsNameList = strsplit(char(gAppConfig.profilingInfo.eventsNameLine), ',');
            end
        
            RtpStreamInit()
            rtpChan = RtpStreamDataChanInit(gAppConfig);
        end
        
        % Init/Re-init figures/axis
        [graphAxis, measLUT] = FigureAxisInit(gAppConfig);
        close all

        updateConfigFlag = 0;
    end
       
    % NON-RTP stream sync for read
    if (gAppConfig.appRunMode == 1)  && (gAppConfig.dataOutChannel ~= CONST.DATA_CHAN.RTP)
        while(readReal(semaFileName,1,'uint8')~= 0)
        end
    end
  
    if ~strcmp(appState,'freeze')
        % Cycle through all data and display
        DataGetAndPlot(gAppConfig,frame,rtpChan, graphAxis, measLUT, dataView);
    end
    
    % NON-RTP stream sync for write/receive
    if (gAppConfig.appRunMode == 1)  && (gAppConfig.dataOutChannel ~= CONST.DATA_CHAN.RTP)
        writeReal(semaFileName, 1, 1, 'uint8');
    end
    
    % Check config change/need to parse config
    if(strcmp(cfgSource,'rtp'))
        cfgStream = rtpstream('getnext',0);
        if (~isempty(cfgStream))
            % Update config file and flag
            fid = fopen(configFileName,'w');
            fwrite(fid,cfgStream);
            fclose(fid);
            updateConfigFlag = 1;
        end
    end
    
    % Check app state    
    if (strcmp(appState,'debug') && (~isdeployed))         
         keyboard
         appState = 'run';
    end
    
    if (strcmp(dataMode,'fbf')) 
        appState = 'pause';
        fprintf('Application paused. "r" to resume execution\n')
        while (~strcmp(appState,'run'))
             pause(0.1)
        end
    end
    
    % End execution in non-streaming mode
    frame = frame+1;
    if (gAppConfig.appRunMode == 0) && (frame == gAppConfig.acqNrFrames)
        appState = 'stop';
    end
    
    pause(0.2)
end

% End RTP thread
if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
    rtpstream('term');
    clear mex
end

% Remove added paths from MATLAB search path list
if ~isdeployed
    rmpath(genpath('../../../Tools/'));
else
    close all
end
end

function cmdHandle(~,event)
global appState

switch event.Key
    case 'x'
        appState = 'stop';
        fprintf('Stop application.\n')
    case 'd'
        appState = 'debug';
        fprintf('Debug application. "F5" or "Continue" to resume execution.\n')
    case 'f'
        appState = 'freeze';
        fprintf('Application in Freeze View. "r" to resume execution.\n')
    case 'r'
        appState = 'run';      
        fprintf('Resume execution.\n')
	case 'return'
        fprintf('\n')
    otherwise
        fprintf('%s',event.Key);
end
end


function [chip, frontEnd,cfgSource, dataFolder, dataView, dataMode, rfeConfig, radarCycle, radarFrame] = InputParameterHandler(narg,varg)
% global nrFrontends;
chip       = 's32r294';  % Default chip S32R274
frontEnd   = 'tef82xx';  % Default front end TEF810X
cfgSource  = 'pc';       % Default config source is config file
dataView   = 'compact';  % Default visualize subset of meaningful data
dataFolder = '../../Apps/RSDK_Multi_RFE_example/data/'; % Default data folder is in <app_folder>/data/
dataMode   = 'cont';     % Default run continuous
rfeConfig  = 'config_0';
radarCycle = 'cycle_0';
radarFrame = 'frame_0';

if (narg > 10)
    error('Too many input parameters')
end

for i = 1:narg
    tmp = char(varg(i));
    tmp = lower(tmp);
    validParam = 0;
    
    if (strcmp(tmp, 's32r274') || strcmp(tmp, 's32r372') || strcmp(tmp, 's32r294') || strcmp(tmp, 's32r45') || strcmp(tmp, 's32r41'))
        chip = tmp;
        validParam = 1;
        continue
    end
    
    if (strcmp(tmp, 'tef810x') || strcmp(tmp, 'mr3003') || strcmp(tmp, 'tef82xx'))
        frontEnd = tmp;
        validParam = 1;
        continue
    end
    
    if (strcmp(tmp, 'pc') || strcmp(tmp, 'rtp'))
        cfgSource = tmp;
        validParam = 1;
        continue
    end
    
    if (strcmp(tmp, 'compact') || strcmp(tmp, 'detailed'))
        dataView = tmp;
        validParam = 1;
        continue
    end
    
   if contains(tmp, 'config')
        rfeConfig = tmp;
        validParam = 1;
        continue
    end

    if contains(tmp, 'cycle')
        radarCycle = tmp;
        validParam = 1;
        continue
    end
    
    if contains(tmp, 'frame')
        radarFrame = tmp;
        validParam = 1;
        continue
    end

    if isfolder(tmp)
        dataFolder = tmp;
        validParam = 1;
        continue
    end
    
    if (strcmp(tmp, 'cont') || strcmp(tmp, 'fbf'))
        dataMode = tmp;
        validParam = 1;
        continue
    end
    
    if (validParam == 0)
        fprintf('HW Platform options: s32r274, s32r372, s32r294\n');
        fprintf('Front-end options: tef82xx,tef810x\n');
        fprintf('Config source options: pc, rtp\n');
        fprintf('Data view options: compact, detailed\n');
        fprintf('Data mode options: cont, fbf\n');
        fprintf('RFE config parameter pattern: config_<id>, fbf\n');
        fprintf('Radar cycle parameter pattern: cycle_<id>, fbf\n');
        fprintf('Radar frame parameter pattern: frame_<id>, fbf\n');
        fprintf('RFE Tester enablement flag: rfe_tester_mode, fbf\n');
        error('Invalid input parameter: %s',tmp);
    end
end
end

function RtpStreamInit()
 try
    rtpstream('init', 7778, 13);
 catch msg
 end
    noSwap = 1;
    cfgChannel = 0;
    cfgBuffSize = 4096;
    rtpstream('setch',cfgChannel,10,cfgBuffSize,noSwap);
end

function rtpChan = RtpStreamDataChanInit(gAppConfig)
noSwap = 1;

pT.adc = 1;
pT.range = 2;
pT.cube = 3;
pT.rdm = 4;
pT.ps = 5;
pT.cfar = 6;
pT.peakData = 7;
pT.dbf = 8;
pT.pl = 9;
pT.us = 10;
pT.other = 11;
pT.bist = 12;

if gAppConfig.sigProcEnable
    bS.adc = gAppConfig.RF.nrSamplesPerChirp * 2 * gAppConfig.specific.nrRxAnt * 2;
else
    bS.adc = gAppConfig.RF.nrSamplesPerChirp *  gAppConfig.RF.nrChirpsPerFrame * gAppConfig.specific.nrRxAnt * 2;
end

bS.radarCube = gAppConfig.specific.nrRangeBins*gAppConfig.specific.nrDopplerBins*gAppConfig.specific.nrVirtRxAnt*4 / gAppConfig.scParam.cpRate;
bS.rdm = gAppConfig.specific.nrRangeBins*gAppConfig.specific.nrDopplerBins*2;
bS.ps = gAppConfig.specific.nrRangeBins*gAppConfig.specific.nrDopplerBins/8;
bS.cfar = gAppConfig.specific.maxNrPeaks * 2; % Max number of peaks is 128; Size of index is uint16 THIS NEEDS TO CHANGE !!!!!!!!!!
bS.peakData = gAppConfig.specific.maxNrPeaks * gAppConfig.specific.nrVirtRxAnt * 4;
bS.dbf = gAppConfig.specific.maxNrPeaks * gAppConfig.specific.nrSteerVect * 4;
bS.pl = gAppConfig.specific.maxNrPeaks * 8;
bS.other = 10; %random
bS.bist = gAppConfig.RF.nrBistSamples * gAppConfig.RF.nrBistTests * gAppConfig.specific.nrRxAnt * 2;

global profilingInfo
if (gAppConfig.profilingInfo.active)
bS.us = 4 * 2 * (2 * length(profilingInfo.stagesNameList) + length(profilingInfo.eventsNameList));
end

defaultNrBuffers = 2;

nB.adc = defaultNrBuffers;
nB.radarCube = defaultNrBuffers;
nB.rdm = defaultNrBuffers;
nB.ps = defaultNrBuffers;
nB.cfar = defaultNrBuffers;
nB.peakData = defaultNrBuffers;
nB.dbf = defaultNrBuffers;
nB.pl = defaultNrBuffers;
nB.us = defaultNrBuffers;
nB.other = defaultNrBuffers;
nB.bist = defaultNrBuffers;

rtpChan.pt = pT; % Packet Types
rtpChan.bs = bS; % Buffer sizes
rtpChan.nB = nB; % Number of buffers

rtpstream('setch',pT.adc,defaultNrBuffers,bS.adc,noSwap);
rtpstream('setch',pT.range,defaultNrBuffers,bS.radarCube,noSwap);
rtpstream('setch',pT.cube,defaultNrBuffers,bS.radarCube,noSwap);
rtpstream('setch',pT.rdm,defaultNrBuffers,bS.rdm,noSwap);
rtpstream('setch',pT.ps,defaultNrBuffers,bS.ps,noSwap);
rtpstream('setch',pT.cfar,defaultNrBuffers,bS.cfar,noSwap);
rtpstream('setch',pT.peakData,defaultNrBuffers,bS.peakData,noSwap);
rtpstream('setch',pT.dbf,defaultNrBuffers,bS.dbf,noSwap);
rtpstream('setch',pT.pl,defaultNrBuffers,bS.pl,noSwap);
if (gAppConfig.profilingInfo.active)
    rtpstream('setch',pT.us,defaultNrBuffers,bS.us,noSwap);
end
%rtpstream('setch',pT.other,defaultNrBuffers,bS.other,noSwap);
rtpstream('setch',pT.bist,defaultNrBuffers,bS.bist,noSwap);
end

function [graphAxis, measLUT] = FigureAxisInit(gAppConfig)
global CONST
global adcYmax
global rangeYmax
global dbfYmax
adcYmax = 0;
rangeYmax = 0;
dbfYmax = 0;

% Range axis
fSamp = gAppConfig.RF.samplingFrequency*10^3; % Convert from KHz to Hz
acqBw = gAppConfig.RF.chirpShape(1).acqBandwidth*10^6; % Convert from MHz to Hz
rangeRes = CONST.C/(2*acqBw);
rangeLUT = [0:(gAppConfig.specific.nrRangeBins-1)]*rangeRes; % meters
rangeAxis = rangeLUT;

% Doppler axis
tAcquisition = 1/fSamp * gAppConfig.RF.nrSamplesPerChirp;
tAux = (gAppConfig.RF.chirpShape(1).tStart + gAppConfig.RF.chirpShape(1).tPreSampling + gAppConfig.RF.chirpShape(1).tPostSampling + gAppConfig.RF.chirpShape(1).tReturn)*10^(-9); % convert from ns to s
tChirp = tAcquisition + tAux;
fChirp = 1/tChirp;
fSampDoppler = fChirp/gAppConfig.specific.nrTdMimoSlots;
velocRes = CONST.C*fSampDoppler/(2*gAppConfig.specific.nrDopplerBins*gAppConfig.RF.chirpShape(1).centerFrequency*10^6);
velocLUT = [(-gAppConfig.specific.nrDopplerBins/2):(gAppConfig.specific.nrDopplerBins/2-1)]*velocRes; % in meters per second
velocAxis = velocLUT;

% Angle axis
fov = gAppConfig.SP.dbfFov;
nrV = 64; % default 64 steering vectors for DOA
angleLUT  = linspace(-fov/2*pi/180,fov/2*pi/180,nrV); % in radians
angleLUT = angleLUT(end:-1:1); % Currently steering vectors are generated backwards: -maxAngle:maxAngle
angleAxis = angleLUT*180/pi; % in degrees)

measLUT.range = rangeLUT;
measLUT.veloc = velocLUT;
measLUT.angle = angleLUT;

graphAxis.range = rangeAxis;
graphAxis.veloc = velocAxis;
graphAxis.angle = angleAxis;

% Structre used for the profiling figure
global profilingInfo

% Initial limits on the x axis (in ms)
profilingInfo.xLeft = 0;
profilingInfo.xRight = 50;
profilingInfo.xMax = 50;

% Inital allowed error
profilingInfo.err = 5;

% Draw gui elements
profilingInfo.redrawElems = 1;

% Initial plot number
profilingInfo.plotNr = 0;

global pos
pos = get(gcf, 'Position');
end

function axisLim = getAxisLim(currentMax,data)
headRoom = 1.05;
resFit   = 1/2;

dMax = max(abs(data(:)));

if (dMax>currentMax) || (dMax<currentMax*resFit )
    axisLim = dMax*headRoom;
else
    axisLim = currentMax;
end
if (axisLim == 0)
    axisLim = 1;
end
end


function DataGetAndPlot(gAppConfig,frame,rtpChan,graphAxis, measLUT, dataView)
global CONST
global adcYmax
global rangeYmax
global dbfYmax
CONST.CSI2_STATS_SIZE = 80;
nrRxPerFrontend = 4;
sp = gAppConfig.specific;
figNr = 1;
if (gAppConfig.dataOutChannel ~= CONST.DATA_CHAN.RTP) && (gAppConfig.appRunMode)
    frameId = 0;
else
    frameId = frame;
end

nrPlots = gAppConfig.dataOutEnable.adcData + ...
    gAppConfig.dataOutEnable.rangeData + ...
    gAppConfig.dataOutEnable.rdCube + ...
    gAppConfig.dataOutEnable.rdMag + ...
    gAppConfig.dataOutEnable.psDet + ...
    gAppConfig.dataOutEnable.cfarDet + ...
    gAppConfig.dataOutEnable.dbfDoa + ...
    gAppConfig.dataOutEnable.peakList + ...
    gAppConfig.dataOutEnable.bistData + ...
    gAppConfig.profilingInfo.active;

eVLin = floor(sqrt(nrPlots));
eVCol = ceil(nrPlots/eVLin);
if (strcmp(dataView,'compact'))
    nrFigures = 1;
else
    nrFigures = nrPlots;
end

% Link Key press handle to figures
for i = 1:nrFigures
    h_fig = figure(i);
    set(h_fig,'KeyPressFcn',@cmdHandle);
end

%% Read ADC raw data
if (gAppConfig.dataOutEnable.adcData)
    if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
        adcStream = rtpstream('getlast',rtpChan.pt.adc);
        validData = numel(adcStream) == rtpChan.bs.adc;
    else
        [fname,validData] = getFname([CONST.dataOutFolder 'adc_out'], frameId);
        if (validData)
            adcStream = readReal(fname,1,'uint8');
        end
    end
    
    if (validData)       
        if (gAppConfig.csi2StatsEnable)
            singleChirpSizeBytes = gAppConfig.RF.nrSamplesPerChirp * nrRxPerFrontend * 2 +  CONST.CSI2_STATS_SIZE;
            tmp = reshape(adcStream,singleChirpSizeBytes,[]);
            csi2Stats = tmp(end-CONST.CSI2_STATS_SIZE+1:end,:)
            tmp2 = tmp(1:end-CONST.CSI2_STATS_SIZE,:);
            adcStream = tmp2(:);
        end
        
        tmp = charStreamToInt(adcStream,2);
        adcStream = tmp/CONST.MAX_INT16;
        
        acqBuffNrChirps = length(adcStream)/(gAppConfig.RF.nrSamplesPerChirp*sp.nrRxAnt);
        sepAnt = zeros(gAppConfig.RF.nrSamplesPerChirp, acqBuffNrChirps, sp.nrRxAnt);
        acqBufLen = gAppConfig.RF.nrSamplesPerChirp * acqBuffNrChirps * nrRxPerFrontend;
        
        % Unformat data and take only last chirp in frame
        for i = 0:gAppConfig.nrFrontends-1
            antRng  = i*nrRxPerFrontend+1:(i+1)*nrRxPerFrontend;
            dataRng = i*acqBufLen+1:(i+1)*acqBufLen;
            sepAnt(:,:,antRng) = rfft_in_unformat(adcStream(dataRng), gAppConfig.RF.nrSamplesPerChirp, acqBuffNrChirps, nrRxPerFrontend);
        end
        lastChirp = squeeze(sepAnt(:, end, :));

        adcYmax = getAxisLim(adcYmax,lastChirp);
        
        if (strcmp(dataView,'compact'))
            figure(1),subplot(eVLin,eVCol,figNr), plot(lastChirp(:,1)),title(['ADC Samples']), xlabel('Samples'), grid on, xlim([0,gAppConfig.RF.nrSamplesPerChirp]),ylim([-adcYmax,adcYmax]);
        else
            % Plot data
            a = floor(sqrt(sp.nrRxAnt));
            b = ceil(sp.nrRxAnt/a);
            figure(figNr)
            for ant = 1:sp.nrRxAnt
                subplot(a,b,ant), plot(lastChirp(:,ant)),title(['Antenna ' num2str(ant)]), grid on, xlabel('Samples'), ylabel('Amplitude'), xlim([0,gAppConfig.RF.nrSamplesPerChirp]),ylim([-adcYmax,adcYmax]);
            end
        end
        
        % Process ADC data if full cube is available
        if ((acqBuffNrChirps == gAppConfig.RF.nrChirpsPerFrame)&&(gAppConfig.dataOutChannel ~= CONST.DATA_CHAN.RTP))
           DefaultRadarProcess(sepAnt);
        end
        
    end
    figNr = figNr+1;
end

%% Read Range FFT output
if (gAppConfig.dataOutEnable.rangeData)
    
    if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
        rStream = rtpstream('getlast',rtpChan.pt.range);
        validData = numel(rStream) == (rtpChan.bs.radarCube);
    else
        [fname,validData] = getFname([CONST.dataOutFolder 'rfft_out'], frameId);
        if (validData)
            rStream = readReal(fname,1,'uint8');
        end
    end
    
    if (validData)
        if (strcmp( gAppConfig.scParam.cpMode,'NO'))
            rInt = charStreamToInt(rStream,2);
        else
            rInt = charStreamToInt(rStream,4,'u');
        end
        
        % Rearrange data
        rangeCube = rfft_out_unformat(rInt,  gAppConfig.scParam.cpMode, sp.nrRangeBins, gAppConfig.RF.nrChirpsPerFrame, sp.nrRxAnt);
        if (strcmp(dataView,'compact'))
            dataToPlot = rangeCube(:,end,1);
            rangeYmax = getAxisLim(rangeYmax,dataToPlot);
            figure(1),subplot(eVLin,eVCol,figNr),plot(graphAxis.range,abs(dataToPlot)), xlabel('Range[m]'), title(['Range FFT']), grid on, xlim([0,max(graphAxis.range)]),ylim([0,rangeYmax]);
        else
            % Plot all antennas
            a = floor(sqrt(sp.nrRxAnt));
            b = ceil(sp.nrRxAnt/a);
            figure(figNr)
            xAxis = 0:gAppConfig.RF.nrChirpsPerFrame-1;
            for i = 1:sp.nrRxAnt
                subplot(a,b,i), mesh(xAxis,graphAxis.range,(abs(rangeCube(:,:,i)))), xlabel('Chirp'), ylabel('Range'), zlabel('Magnitude'), title(['RxAnt ' num2str(i)]), axis tight
            end            
        end
    end
    figNr = figNr+1;
end

%% Read Range-Doppler cube
if (gAppConfig.dataOutEnable.rdCube)
    
    if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
        rdStream = rtpstream('getlast',rtpChan.pt.cube);
        validData = numel(rdStream) == (rtpChan.bs.radarCube);
    else
        [fname,validData] = getFname([CONST.dataOutFolder 'dfft_out'], frameId);
        if (validData)
            rdStream = readReal(fname,1,'uint8');
        end
    end
    
    if (validData)
        if (strcmp( gAppConfig.scParam.cpMode,'NO'))
            rdInt = charStreamToInt(rdStream,2);
        else
            rdInt = charStreamToInt(rdStream,4,'u');
        end
        
        % Rearrange data
        rdCube = dfft_out_unformat(rdInt,  gAppConfig.scParam.cpMode, sp.nrRangeBins, sp.nrDopplerBins, sp.nrVirtRxAnt);
        
        if (strcmp(dataView,'compact'))
            figure(1),subplot(eVLin,eVCol,figNr),pcolor(graphAxis.veloc,graphAxis.range,abs(rdCube(:,:,1))),xlabel('Velocity[m/s]'), ylabel('Range[m]'), title(['Doppler FFT']), axis tight, shading INTERP
        else
            % Plot all antennas
            a = floor(sqrt(sp.nrVirtRxAnt));
            b = ceil(sp.nrVirtRxAnt/a);
            figure(figNr)
            for i = 1:sp.nrVirtRxAnt
                subplot(a,b,i), mesh(graphAxis.veloc,graphAxis.range,(abs(rdCube(:,:,i)))), xlabel('Velocity[m/s]'), ylabel('Range[m]'), zlabel('Magnitude'), title(['VirtAnt ' num2str(i)]), axis tight
            end
        end
    end
    figNr = figNr+1;
end

%% Read Range-Doppler Magnitude Matrix
if (gAppConfig.dataOutEnable.rdMag)
    
    if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
        rdmStream = rtpstream('getlast',rtpChan.pt.rdm);
        validData = numel(rdmStream) == (rtpChan.bs.rdm);
    else
        [fname,validData] = getFname([CONST.dataOutFolder 'ncc_out'], frameId);
        if (validData)
            rdmStream = readReal(fname,1,'uint8');
        end
    end
    
    if (validData)
        rdmInt = charStreamToInt(rdmStream,2,'u');
        
        RDM = rd_mag_unformat(rdmInt, sp.nrRangeBins, sp.nrDopplerBins);
        RDM = RDM/(2^8); % Log2 format of SPT stores log value in 7Q8 fixed point
        
        if (strcmp(dataView,'compact'))
            figure(1),subplot(eVLin,eVCol,figNr),pcolor(graphAxis.veloc,graphAxis.range,RDM),xlabel('Velocity[m/s]'), ylabel('Range[m]'), title(['RDM']), axis tight,shading INTERP
        else
            figure(figNr),mesh(graphAxis.veloc,graphAxis.range,(RDM)),xlabel('Doppler'), ylabel('Range'), zlabel('Mag[log2]'), title('Range-Doppler Magnitude'), axis tight
        end
    end
    figNr = figNr + 1;
end

%% Read SPT Peak Search bitmap
if (gAppConfig.dataOutEnable.psDet)
    
    if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
        psStream = rtpstream('getlast',rtpChan.pt.ps);
        validData = numel(psStream) == (rtpChan.bs.ps);
    else
        [fname, validData] = getFname([CONST.dataOutFolder 'ps_out'], frameId);
        if (validData)
            psStream = readReal(fname,1,'uint8');
        end
    end
    
    if (validData)
        psInt = charStreamToInt(psStream,4,'u');
        
        detectTag = det_tag_unformat(psInt, sp.nrRangeBins, sp.nrDopplerBins);
        
        if (strcmp(dataView,'compact'))
            figure(1),subplot(eVLin,eVCol,figNr),pcolor(graphAxis.veloc, graphAxis.range,(detectTag)),xlabel('Velocity[m/s]'), ylabel('Range[m]'), title('Peak Search Detects'), axis tight, shading FLAT
        else
            figure(figNr),mesh(graphAxis.veloc, graphAxis.range,(detectTag)),xlabel('Velocity[m/s]'), ylabel('Range[m]'), title('Peak Search Detects'), axis tight
        end
    end
    figNr = figNr + 1;
end

%% Read Peak detect indices after CFAR
if (gAppConfig.dataOutEnable.cfarDet)
    
    if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
        cfarStream = rtpstream('getlast',rtpChan.pt.cfar);
    else
        
        [fname,validData] = getFname([CONST.dataOutFolder 'caCfar_bmp_out'], frameId);
        if (validData)
            cfarStream = readReal(fname,1,'uint8');
        end
    end
    
    if (~isempty(cfarStream))
         detMem = charStreamToInt(cfarStream,4,'u');
         cfarTag = det_tag_unformat(detMem, sp.nrDopplerBins, sp.nrRangeBins);
         cfarTag = cfarTag.';
        if (strcmp(dataView,'compact'))
            figure(1),subplot(eVLin,eVCol,figNr),pcolor(graphAxis.veloc,graphAxis.range,(cfarTag)),xlabel('Velocity[m/s]'), ylabel('Range[m]'), title('CFAR Detects'), axis tight, shading FLAT
        else
            figure(figNr),mesh(graphAxis.veloc,graphAxis.range,(cfarTag)),xlabel('Velocity[m/s]'), ylabel('Range[m]'), title('CFAR Detects'), axis tight
        end
    end
    figNr = figNr + 1;
end

%% Read beamscans
if (gAppConfig.dataOutEnable.dbfDoa)
    
    if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
        dbfStream = rtpstream('getlast', rtpChan.pt.dbf);
        validData = (~isempty(dbfStream) && ~mod(length(dbfStream)/2,sp.nrSteerVect));
    else
        [fname,validData] = getFname([CONST.dataOutFolder 'beamscans'],frameId);
        if (validData)
            dbfStream = readReal(fname,1,'uint8');
            validData = ~isempty(dbfStream);
        end
    end
    
    if (validData)
        dbfInt = charStreamToInt(dbfStream,2,'u');
        
        [~, beamScans] = doa_unformat(dbfInt, sp.nrSteerVect, 0);
        beamScansDisp = beamScans/2^8; % Log2 format of SPT stores log value in 7Q8 fixed point
        
        dbfYmax = getAxisLim(dbfYmax,beamScansDisp);
        if (strcmp(dataView,'compact'))
            figure(1),subplot(eVLin,eVCol,figNr),plot(graphAxis.angle,beamScansDisp),title('DBF Scans'), xlabel('Angle[deg]'), grid on, xlim([min(graphAxis.angle),max(graphAxis.angle)]),ylim([dbfYmax-30,dbfYmax]);
        else
            figure(figNr),plot(graphAxis.angle,beamScansDisp),title('DBF Scans'), xlabel('Angle[deg]'), grid on, grid on, xlim([min(graphAxis.angle),max(graphAxis.angle)]),ylim([dbfYmax-30,dbfYmax]);
        end
    else
        % Also fheck for LAX beamforming
        [fname,validData] = getFname([CONST.dataOutFolder 'dbfFft_out'],frameId);
        if (validData)
            fid = fopen(fname);
            laxOutMem = fread(fid,'float');
            fclose(fid);
            re = downsample(laxOutMem,2,0);
            im = downsample(laxOutMem,2,1);
            laxOut = re + 1i*im;
            laxOut = reshape(laxOut,128,[]);
            
            if (strcmp(dataView,'compact'))
                figure(1),subplot(eVLin,eVCol,figNr),plot(abs(laxOut)),title('LAX DBF FFT'), grid on
            else
                figure(figNr),plot(abs(laxOut)),title('LAX DBF FFT'), grid on
            end
        end
    end
    figNr = figNr+1;
end

%% Read and interpret peak list
if (gAppConfig.dataOutEnable.peakList)
    
    if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
        plStream = rtpstream('getlast',rtpChan.pt.pl);
        validData = ~isempty(plStream);
    else
        [fname, validData] = getFname([CONST.dataOutFolder 'peak_list'], frameId);
        if (validData)
            plStream = readReal(fname,1,'uint8');
            validData = ~isempty(plStream);
        end
    end
    
    if (validData)
        plInt = charStreamToInt(plStream,2,'u');
        
        peaks = (reshape(plInt,4,[])).'; % [RangeBin, DopplerBin, AngleBin, Magnitude]
        absPeakList = [measLUT.range(peaks(:,1)+1).' measLUT.veloc(peaks(:,2)+1).' measLUT.angle(peaks(:,3)+1).' peaks(:,4)];
        
        % Transform Range-Angle to XY position
        coordX = absPeakList(:,1).*sin(absPeakList(:,3));
        coordY = absPeakList(:,1).*cos(absPeakList(:,3));
        
        if (strcmp(dataView,'compact'))
            figure(1),subplot(eVLin,eVCol,figNr),plot(coordX,coordY,'*'), xlim([max(measLUT.range)*sin(min(measLUT.angle)) max(measLUT.range)*sin(max(measLUT.angle))])...
                ,ylim([0 max(measLUT.range)]), xlabel('X position [m]'), ylabel('Y position [m]'), title('Target Map'), grid on
        else
            figure(figNr),plot(coordX,coordY,'*'), xlim([max(measLUT.range)*sin(min(measLUT.angle)) max(measLUT.range)*sin(max(measLUT.angle))])...
                ,ylim([0 max(measLUT.range)]), xlabel('X position [m]'), ylabel('Y position [m]'), grid on
        end
    end
    
    drawnow;
    figNr = figNr + 1;
end

%% BIST data
if (gAppConfig.dataOutEnable.bistData) % rf bist data - to be introduced in output enable - also put in RTP currently only in file
    if (gAppConfig.dataOutChannel == CONST.DATA_CHAN.RTP)
        bistStream = rtpstream('getlast',rtpChan.pt.bist);
        validData = numel(bistStream) == (rtpChan.bs.bist);
        
    else
        [fname, validData] = getFname([CONST.dataOutFolder 'rfbist_adc'], frameId);
        if (validData)
            bistStream = readReal(fname,1,'uint8');
            validData = ~isempty(bistStream);
        end
    end
      
    if (validData)
        bistInt = charStreamToInt(bistStream,2);
        adcBistSamp = bistInt/CONST.MAX_INT16;
        
        sepAnt = rfft_in_unformat(adcBistSamp, gAppConfig.RF.nrBistSamples, gAppConfig.nrFrontends*gAppConfig.RF.nrBistTests, nrRxPerFrontend);
        sepAnt = squeeze(sepAnt);
        
        fftBist = zeros(gAppConfig.RF.nrBistSamples/2, gAppConfig.nrFrontends*gAppConfig.RF.nrBistTests, nrRxPerFrontend);
        for i = 1:nrRxPerFrontend
            tmp = fft(sepAnt(:,:,i));
            fftBist(:,:,i) = tmp(1:gAppConfig.RF.nrBistSamples/2,:,:);
        end
        
        if (strcmp(dataView,'compact'))
            figure(1),subplot(eVLin,eVCol,figNr),plot(abs(fftBist(:,1,1))),xlim([0 gAppConfig.RF.nrBistSamples/2]), title('LNA Bist Main'), grid on;
        else
            bLin = gAppConfig.RF.nrBistTests;
            bCol = gAppConfig.nrFrontends;
            btestInd = 0;
            for rfe = 0:gAppConfig.nrFrontends-1
                figure(figNr),subplot(bLin,bCol,rfe+1),plot(squeeze(abs(fftBist(:,btestInd+1,:)))), xlim([0 gAppConfig.RF.nrBistSamples]), title (sprintf('LNA Bist RFE %d',rfe)), grid on;
                figure(figNr),subplot(bLin,bCol,bCol+rfe+1),plot(squeeze(abs(fftBist(:,btestInd+2,:)))), xlim([0 gAppConfig.RF.nrBistSamples]), title (sprintf('Mixer Bist RFE %d',rfe)), grid on;
                btestInd = btestInd+2;
            end
        end
        
        figNr = figNr + 1;
    end
end
end

function [fname,validFile] = getFname (base, frameId)
validFile = 0;
% Check for naming convention
fname0 = [base '.dat'];
fname1 = [base '_' num2str(frameId) '.dat'];
if isfile(fname0)
    fname = fname0;
    validFile = 1;
else
    if isfile(fname1)
        fname = fname1;
        validFile = 1;
    else
        warning(['File with base "' base '" not found in directory !'])
        fname = '';
    end
end
end

function DefaultRadarProcess(adcData)

[nrS, nrC, nrA] = size(adcData);
nrF = 2;
subPlotPerLine = floor(sqrt(nrA));
subPlotPerCol = ceil(nrA/subPlotPerLine);

allAdcSamples = zeros(nrS*nrC, nrA);
for ant = 1:nrA
    tmp = adcData(:, :, ant);
    allAdcSamples(:, ant) = tmp(:);
    figure(nrF), subplot(subPlotPerLine, subPlotPerCol, ant),  plot(allAdcSamples(:, ant)), title(['ADC data (antenna ' num2str(ant), ')']), xlabel('Samples'), grid on
end
nrF = nrF + 1;

% Range process 
rFft = fft(adcData,[],1);
rFft = rFft(1:nrS/2,:,:);
for ant = 1:nrA
    tmp = rFft(:,:,ant);
    figure(nrF),subplot(subPlotPerLine,subPlotPerCol,ant),mesh(abs(tmp)), title(['Range Mat  ' num2str(ant)]);
end
nrF = nrF+1;

% Doppler process
dFft = fft(rFft,[],2);
dFft = fftshift(dFft,2);
for ant = 1:nrA
    tmp = dFft(:,:,ant);
    figure(nrF),subplot(subPlotPerLine,subPlotPerCol,ant),mesh(abs(tmp)), title(['Doppler Mat ' num2str(ant)]);
end
nrF = nrF+1;

% Non Coherent Combining
ncComb = sum(abs(dFft),3);

ind = find(ncComb == 0); % Replace zeros in ncComb with minumum non-zero value to avoid logarithm error
tmp = ncComb;
tmp(ind) = [];
minVal = min(tmp(:));
ncComb(ind) = minVal;
ncCombLog = 20*log10(ncComb);

figure(nrF),mesh(ncCombLog); title(['NC Comb Mat']);
end
