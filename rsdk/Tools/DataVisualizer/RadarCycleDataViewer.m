% *************************************************************************
% Copyright 2024 NXP
% All Rights Reserved
% *************************************************************************
%  NXP Confidential and Proprietary. This software is owned or controlled by NXP and
%  may only be used strictly in accordance with the applicable license terms.  By
%  expressly accepting such terms or by downloading, installing, activating and/or
%  otherwise using the software, you are agreeing that you have read, and that you
%  agree to comply with and are bound by, such license terms.  If you do not agree to
%  be bound by the applicable license terms, then you may not retain, install, activate or
%  otherwise use the software.
% *************************************************************************
function RadarCycleDataViewer(varargin)
% INPUT arguments:
% chip        - 's32r274', 's32r372', 's32r294', 's32r45', 's32r41'
% dataFolder  - any existing folder with the structure
%             ./in
%                 ./<chip>
%                     app_running_session_config.ini
%                     <config folders>
%                         rfeConfig0.xml
%                         ...
%             ./out
%                 ./<chip>
%                     '<config>_cycle_N_sequence_M_adc_out.dat'
%                     ...

[chip, dataFolder] = InputParameterHandler(nargin,varargin);
fprintf('HW Platform: %s\n', chip);
fprintf('Data folder:  %s\n', dataFolder);

% Solve paths
if ~isdeployed
    addpath(genpath('../')); % <rsdk_root>/Tools/
end

% Initialize constants
global CONST
CONST = init_CONST(chip);
CONST.HW = upper(chip); % used for unformatting data
CONST.endian = "ieee-be"; % used for reading data
 
MAX_INT16 = 2^15;
NR_RX_PER_FRONTEND = 4; 
dataInFolder  = [dataFolder 'in/',chip,'/'];
dataOutFolder = [dataFolder 'out/',chip,'/'];

% Read and parse session config file
sessionCfgFile = [dataInFolder 'app_running_session_config.ini'];
sessionCfg = readIniFile(sessionCfgFile);
nrFrontends = 2; % hardcoded for now - can put in session cfg
nrRxAnt = nrFrontends*NR_RX_PER_FRONTEND;

% Go through all usecases an plot data
for useCase = 1:length(sessionCfg)
    close all
    configName = sessionCfg{useCase}{1};
    tmp = sessionCfg{useCase}{2};
    configNrRuns = sscanf(tmp,'%d');
    
    % Parse config of first RFE
    configFileName = [dataInFolder configName '/rfeConfig0.xml'];
    rfeConfig = importXML(configFileName);
    seqConfig = rfeConfig.rfeConfig.chirpSequenceConfigs.chirpSequenceConfig;
    configNrSequences=length(seqConfig);
    for run = 0:(configNrRuns-1)
        disp(['Use case ' configName ' Run ' num2str(run)]);
        figureNr = 1; % reset figure number; overwrite plots from previous run
        for seq = 0:configNrSequences-1
            try 
                currSeqConfig = seqConfig{seq+1};
            catch ME
                currSeqConfig = seqConfig;
            end
            
                
            outDataFilePrefix = [dataOutFolder  configName '_run_' num2str(run) '_sequence_' num2str(seq) '_'];           
            fname = [outDataFilePrefix 'adc_out.dat'];
            adcStream = readReal(fname,MAX_INT16,'int16');
            
            % Assume CSI2 stats not enabled and all chirps are buffered           
            tmp = currSeqConfig.chirpCount.count;
            acqBuffNrChirps = sscanf(tmp,'%d');
            
            tmp = currSeqConfig.chirpProfileSequence.sequence;
            tmp = sscanf(tmp,'%d');
            profileIdx = tmp(1);%take first profile
            try
                firstChirpProfile = rfeConfig.rfeConfig.chirpProfiles.chirpProfile{profileIdx+1};
            catch ME
                firstChirpProfile = rfeConfig.rfeConfig.chirpProfiles.chirpProfile;
            end
            tmp = firstChirpProfile.chirpTiming.acquisition_time_ticks;
            acqTicks = sscanf(tmp,'%d');
            tmp = firstChirpProfile.effectiveSamplingFrequency.frequency;
            samplingFreq = sscanf(tmp,'%d');
            nrSamplesPerChirp = acqTicks*samplingFreq/40;
            
            adcData = zeros(nrSamplesPerChirp, acqBuffNrChirps, nrRxAnt);
            acqBufLen = nrSamplesPerChirp * acqBuffNrChirps * NR_RX_PER_FRONTEND; % ADC data size from 1 frontend
            
            % Unformat data
            for i = 0:nrFrontends-1
                antRng  = i*NR_RX_PER_FRONTEND+1:(i+1)*NR_RX_PER_FRONTEND;
                dataRng = i*acqBufLen+1:(i+1)*acqBufLen;
                adcData(:,:,antRng) = rfft_in_unformat(adcStream(dataRng), nrSamplesPerChirp, acqBuffNrChirps, NR_RX_PER_FRONTEND);
            end        
            
            % Process ADC data 
            figTitlePref = [' Sequence ' num2str(seq) ' - '];
            figureNr = DefaultRadarProcessAndPlot(adcData,figureNr,figTitlePref);
            
        end
        pause;
    end
end
end

function [chip, dataFolder] = InputParameterHandler(narg,varg)
chip       = 's32r41';  % Default chip 
dataFolder = '../../Apps/RFE_processing_example\RFE_processing_example_M7_0\data\'; % Default data folder 

if (narg > 2)
    error('Too many input parameters')
end

for i = 1:narg
    tmp = char(varg(i));
    tmp = lower(tmp);
    validParam = 0;
    
    if (strcmp(tmp, 's32r45') || strcmp(tmp, 's32r41'))
        chip = tmp;
        validParam = 1;
    end
    
    if isfolder(tmp)
        dataFolder = tmp;
        validParam = 1;
    end
    
    if (validParam == 0)
        error('Invalid input parameter: %s',tmp);
    end
end
end

function nextFigure = DefaultRadarProcessAndPlot(adcData,firstFigure,titlePref)

[nrS, nrC, nrA] = size(adcData);
nrF = firstFigure;
subPlotPerLine = floor(sqrt(nrA));
subPlotPerCol = ceil(nrA/subPlotPerLine);

allAdcSamples = zeros(nrS*nrC, nrA);
for ant = 1:nrA
    tmp = adcData(:, :, ant);
    allAdcSamples(:, ant) = tmp(:);
    figure(nrF), subplot(subPlotPerLine, subPlotPerCol, ant),  plot(adcData(:,end, ant)), title(['Rx ' num2str(ant)]),sgtitle([titlePref 'Last Chirp']), xlabel('Samples'), grid on
end
nrF = nrF + 1;

% Range process
rFft = fft(adcData,[],1)/nrS;
rFft = rFft(1:nrS/2,:,:);
for ant = 1:nrA
    tmp = rFft(:,:,ant);
    figure(nrF),subplot(subPlotPerLine,subPlotPerCol,ant),mesh(20*log10(abs(tmp))), title(['Rx ' num2str(ant)]),sgtitle([titlePref 'Range FFT']),xlabel('Chirps'),ylabel('R [bins]'),zlabel('[dBFS]');
end
nrF = nrF+1;

% Doppler process
dFft = fft(rFft,[],2)/nrC;
dFft = fftshift(dFft,2);
for ant = 1:nrA
    tmp = dFft(:,:,ant);
    figure(nrF),subplot(subPlotPerLine,subPlotPerCol,ant),mesh(20*log10(abs(tmp))), title(['Rx ' num2str(ant)]),sgtitle([titlePref 'Doppler FFT']),xlabel('D [bins]'),ylabel('R [bins]'),zlabel('[dBFS]');
end
nrF = nrF+1;

% Non Coherent Combining
ncComb = sum(abs(dFft),3);
ncCombLog = 20*log10(ncComb);
figure(nrF),mesh(ncCombLog); sgtitle([titlePref 'NC Combining']),xlabel('D [bins]'),ylabel('R [bins]'),zlabel('[dBFS]');
nextFigure = nrF+1;
end
