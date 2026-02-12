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
function [paramList] = DecodeConfigList(configList)

i = 1;
while (i<length(configList))
    % Name of parameter line
    paramName = cell2mat(configList{i});    
    % Parameter line
    line = configList{i+1};
    i = i+2;
    
    switch char(paramName)
        case char('NR_FRAMES')
            paramList.acqNrFrames = str2double(line);                  % Number of frames
            
        case char('OUTPUT_DATA_CHANNEL')
            paramList.dataOutChannel     = str2double(line(1));              % Use RTP/TFTP/UART to stream data  
        
        case char('OUTPUT_DATA_ENABLE')
            paramList.dataOutEnable.adcData     = str2double(line(1));  % Output of ADC buffer - last 2 chirps of frame*/
            paramList.dataOutEnable.rangeData   = str2double(line(2));  % Output of Range FFT results*/
            paramList.dataOutEnable.rdCube      = str2double(line(3));  % Output of Range-Doppler cube*/
            paramList.dataOutEnable.rdMag       = str2double(line(4));  % Output of Range-Doppler magnitude matrix (in SPT log2 format)*/
            paramList.dataOutEnable.psDet       = str2double(line(5));  % Output of peak detect bitmap*/
            paramList.dataOutEnable.cfarDet     = str2double(line(6));  % Output of CFAR peak detect*/
            paramList.dataOutEnable.peakAntData = str2double(line(7));  % Output of peaks' antenna data*/
            paramList.dataOutEnable.dbfDoa      = str2double(line(8));  % Output of beamscans*/
            paramList.dataOutEnable.peakList    = str2double(line(9)); % Output of detected peaks range, doppler, angle */
            paramList.dataOutEnable.bistData    = str2double(line(10));  % Output of beamscans*/
        
        case char('RF_PARAMETERS')
            paramList.nrFrontends          = str2double(line(1));
            paramList.RF.samplingFrequency = str2double(line(2));   % The ADC sampling frequency in kSps
            paramList.RF.nrSamplesPerChirp = str2double(line(3));  
            paramList.RF.nrChirpsPerFrame  = str2double(line(4));  
            paramList.RF.nrChirpShapes     = str2double(line(5));  
            
            for cS = 1:paramList.RF.nrChirpShapes
                line = configList{i};
                i = i+1;
                
                paramList.RF.chirpShape(cS).tStart          = str2double(line(1));   % Time duration after the start of a chirp to when the ramp starts in ns steps
                paramList.RF.chirpShape(cS).tPreSampling    = str2double(line(2));   % Time duration between chirp ramp start and the beginning of the acquisition window in ns steps
                paramList.RF.chirpShape(cS).tPostSampling   = str2double(line(3));   % Time duration after the acquisition window has finished and the end of the chirp ramp in ns steps
                paramList.RF.chirpShape(cS).tReturn         = str2double(line(4));   % Time duration (ns) needed for the ramp to come back to the start frequency
                paramList.RF.chirpShape(cS).centerFrequency = str2double(line(5));   % Center frequency of the acquisition window in MHz
                paramList.RF.chirpShape(cS).acqBandwidth    = str2double(line(6));   % Frequency bandwidth that the chirp will encompass during the acquisition windows in MHz
                paramList.RF.chirpShape(cS).chirpSlope      = str2double(line(7));   % Chirp slope; 1 = ascending; 0 = descending
                paramList.RF.chirpShape(cS).txChanEnable    = str2double(line(8));   % Transmit channel enable mask
                paramList.RF.chirpShape(cS).txChanPower     = str2double(line(9));   % Frequency bandwidth that the chirp will encompass during the acquisition windows in MHz
                paramList.RF.chirpShape(cS).rxChGain        = str2double(line(10));   % Frequency bandwidth that the chirp will encompass during the acquisition windows in MHz
            end
        
        case char('RADAR_SIG_PROC_ENABLE')
            paramList.sigProcEnable = str2double(line(1)); % RSDK signal processing is enabled
               
        case char('SIG_PROC_CHAIN')
            paramList.SP.procChainSelect    = str2double(line(1));      % Number of MIMO time slots
            paramList.SP.antCombType        = str2double(line(2));
            paramList.SP.scaleFactorRange   = str2double(line(3));
            paramList.SP.scaleFactorDoppler = str2double(line(4));
            
        case char('TARGET_DETECTION')
            paramList.SP.histThreshFact = str2double(line(1));
            paramList.SP.cfarThreshFact = str2double(line(2));
            paramList.SP.cfarGuardSize  = str2double(line(3));
            paramList.SP.cfarWinSize    = str2double(line(4));
            paramList.SP.dbfFov         = str2double(line(5));
            paramList.SP.doaThreshFact  = str2double(line(6));
            
        case char('PROFILING_ACTIVE')
            paramList.profilingInfo.active = str2double(line(1));
            
        case char('STAGES_ANALYZED')
            paramList.profilingInfo.stagesNameLine = line;      % Line containing all stage names
            
        case char('EVENTS_ANALYZED')
            paramList.profilingInfo.eventsNameLine = line;      % Line containing all event names
    end
end
if ~isfield(paramList,'profilingInfo')
    paramList.profilingInfo.active = 0;
end

RSDK_SAMPLES512_CHIRPS128_NOCOMP_NOMIMO  = 0;
RSDK_SAMPLES256_CHIRPS256_NOCOMP_NOMIMO  = 1;
RSDK_SAMPLES1024_CHIRPS128_CP4D_NOMIMO   = 2;
RSDK_SAMPLES256_CHIRPS256_CP4D_2TXMIMO   = 3;
RSDK_SAMPLES256_CHIRPS128_NOCOMP_3TXMIMO = 4;

% switch paramList.SP.procChainSelect
%     case RSDK_SAMPLES512_CHIRPS128_NOCOMP_NOMIMO
%         paramList.scParam.cpMode = 'NO';
%     case RSDK_SAMPLES256_CHIRPS256_NOCOMP_NOMIMO
%         paramList.scParam.cpMode = 'NO';
%     case RSDK_SAMPLES1024_CHIRPS128_CP4D_NOMIMO
%         paramList.scParam.cpMode = 'CP4D';
%     case RSDK_SAMPLES256_CHIRPS256_CP4D_2TXMIMO
%         paramList.scParam.cpMode = 'CP4D';
%     case RSDK_SAMPLES256_CHIRPS128_NOCOMP_3TXMIMO
%         paramList.scParam.cpMode = 'NO';   
% end
compressUC = [2,3,5,6,9,14,15,16];
if any(find(compressUC == paramList.SP.procChainSelect))
    paramList.scParam.cpMode = 'CP4Q';
else
    paramList.scParam.cpMode = 'NO';
end
        
switch paramList.scParam.cpMode
    case 'NO'
        paramList.scParam.cpRate = 1;
    case 'CP4D'
        paramList.scParam.cpRate = 2;
end

RSDK_DBF_30_DEG  = 0;
RSDK_DBF_60_DEG  = 1;
RSDK_DBF_90_DEG  = 2;
RSDK_DBF_120_DEG = 3;

switch paramList.SP.dbfFov
	case RSDK_DBF_30_DEG
		paramList.scParam.dbfFovDeg = 30;
	case RSDK_DBF_60_DEG
		paramList.scParam.dbfFovDeg = 60;
	case RSDK_DBF_90_DEG
		paramList.scParam.dbfFovDeg = 90;
	case RSDK_DBF_120_DEG
		paramList.scParam.dbfFovDeg = 120;
end

sp.nrRangeBins = paramList.RF.nrSamplesPerChirp/2;
sp.nrTdMimoSlots =  paramList.RF.nrChirpShapes;
sp.nrDopplerBins = paramList.RF.nrChirpsPerFrame/sp.nrTdMimoSlots;
sp.nrRxAnt =  paramList.nrFrontends * 4; % fixed;
sp.nrVirtRxAnt  = sp.nrRxAnt * sp.nrTdMimoSlots;
sp.nrSteerVect   = 64;  % not in config file (SPT dependent)
sp.maxNrPeaks = 128;

paramList.specific = sp;

if (paramList.acqNrFrames == 0)
    paramList.appRunMode = 1;
else
    paramList.appRunMode = 0;
end

% Sanity checks:
if (mod(paramList.RF.nrSamplesPerChirp,8))
    disp('WARNING! Number of samples per chirp is not multiple of 8.')
end



