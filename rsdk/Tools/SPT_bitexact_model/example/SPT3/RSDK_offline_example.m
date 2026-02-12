%{
    Copyright 2017-2023 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function RSDK_offline_example(HW)

clc;
close all;

addpath '../../src/SPT3/common';
addpath '../../../Matlab_aux';

global CONST;

switch(upper(HW))
    case{'S32R45'}  %SPT3.1
        sptVersion = 31;
        CONST.HW = 'S32R45';
        addpath '../../src/SPT3/31';
    case{'S32R41'}  %SPT3.5
        sptVersion = 35;
        CONST.HW = 'S32R41';
        addpath '../../src/SPT3/34_35';
    case{'SAF85XX'} %SPT3.4
        sptVersion = 34;
        CONST.HW = 'SAF85XX';
        addpath '../../src/SPT3/34_35';
    otherwise
        error('SPT 3.1/3.4/3.5 Example CALLED WITH WRONG HARDWARE. S32R45/S32R41/SAF85XX ARE THE ONLY VALID VALUES');
end

switch_spt(sptVersion);
inFolder  = strcat('../data/in/', CONST.HW, '/');    %contains input files for testing
outFolder = strcat('../data/out/', CONST.HW, '/');   %contains test results produced by RSDK_offline_example

%% SPT Example
disp('SPT EXAMPLE STARTED');
disp('----------------------------');
fprintf('Running on SPT: %.1f\n', sptVersion/10);
disp('----------------------------');

CONST.MAX_INT16 = 2^15;
CONST.endian = 'ieee-be';

samplesPerChirp = 512;
chirpsPerFrame = 128;
channels = 4;
nrVirtCh = 4;

shiftInput = 8;
shiftRangeOutput = 3; % right shift for range output
shiftDopplerOutput = 0; % right shift for doppler output

%% Read from files input data, window data, twiddle coeficients and thresholds values
% Read range input samples from file (SPT memory format)
fname = [inFolder 'rfft_in.dat'];
disp(['Input file: ' fname]);
inSPTformat = readReal(fname, 1, 'int16');
inputSamples = parse_inSPTformat(inSPTformat, samplesPerChirp, chirpsPerFrame, channels);

% Generate the window coeficients for range fft
fhandle = str2func('blackman');
W = window(fhandle, samplesPerChirp).'; 
% saturate to 16 bits as SPT HW
maxInt16 = cast(intmax('int16'), 'double');
max_vect = repmat((maxInt16-1)/maxInt16,1,numel(W));
W = min([W; max_vect],[],1);
winCoefRangeFFT = round(W * CONST.MAX_INT16).';

% Read Twiddle coef for range fft
fname = [inFolder 'fft512_twiddle_factors.dat'];
disp(['Twiddle file range fft: ' fname]);
twiddleCoefSPTformat = readReal(fname, 1, 'int16');
twiddleCoefRangeFFT = parse_TwiddleCoef_SPTformat(twiddleCoefSPTformat);

%  Generate the window coeficients for doppler fft
fhandle = str2func('blackman');
W = window(fhandle, chirpsPerFrame).'; 
% saturate to 16 bits as doppler fft
max_vect = repmat((maxInt16-1)/maxInt16,1,numel(W));
W = min([W; max_vect],[],1);
winCoefDopplerFFT = round(W * CONST.MAX_INT16).';

% Read Twiddle coef for doppler fft
fname = [inFolder 'fft128_twiddle_factors.dat'];
disp(['Twiddle file doppler fft: ' fname]);
twiddleCoefSPTformat = readReal(fname, 1, 'int16');
twiddleCoefDopplerFFT = parse_TwiddleCoef_SPTformat(twiddleCoefSPTformat);

% Read threshold values from file 
fname = [inFolder 'ps_hthr_in.dat'];
disp(['Thresholds peak search file: ' fname]);
psThreshold = readReal(fname, 1, 'int16');

%% Call the Range FFT kernel model
disp('Running range fft ...');
outRangeFftCube = rangeFFT(inputSamples, winCoefRangeFFT, twiddleCoefRangeFFT, samplesPerChirp, chirpsPerFrame, channels, shiftInput, shiftRangeOutput, 'NO'); % 'NO' = no PDMA compression

%% Call the Doppler FFT
disp('Running doppler fft ...');
outDopplerFftCube = dopplerFFT(outRangeFftCube, winCoefDopplerFFT, twiddleCoefDopplerFFT, samplesPerChirp/2, chirpsPerFrame, channels, shiftInput, shiftDopplerOutput, 'NO', 1, complex(0)); % 'NO' = no PDMA compression

%% Call the NonCohComb kernel model
disp('Running non coherent combining ...');
[outNoCComb, outHistNoCComb] = NonCohComb(outDopplerFftCube, samplesPerChirp/2, chirpsPerFrame, channels, shiftInput);

%% Call the peak search kernel model
disp('Running peak search ...');
outPeakSearch = peakSearch(outNoCComb, psThreshold, samplesPerChirp/2, chirpsPerFrame);

%% Dump output data
disp('Dump out files ...');
% Scale the data, as required by the formating function
outRangeFftCube = outRangeFftCube./CONST.MAX_INT16;
outDopplerFftCube = outDopplerFftCube./CONST.MAX_INT16;
% Range fft
fname = [outFolder 'rfft_out.dat'];
outSPTmodel = rfft_out_format(outRangeFftCube, 'NO', samplesPerChirp/2, chirpsPerFrame, channels); % 'NO' = no PDMA compression
writeReal(fname, outSPTmodel, 1, 'int16');
% Doppler fft
fname = [outFolder 'dfft_out.dat'];
outSPTmodel = dfft_out_format(outDopplerFftCube, 'NO', samplesPerChirp/2, chirpsPerFrame, channels); % 'NO' = no PDMA compression
writeReal(fname, outSPTmodel, 1, 'int16');
% NoCComb
fname = [outFolder 'ncc_out.dat'];
outSPTmodel = rd_mag_format(outNoCComb);
writeReal(fname, outSPTmodel, 1, 'int16');
% NoCComb histogram
fname = [outFolder 'ncc_hist_out.dat'];
compHist = reshape(outHistNoCComb, 1, []);
histOutInv = zeros(size(compHist));
histOutInv(1:2:end) = compHist(2:2:end);
histOutInv(2:2:end) = compHist(1:2:end);
writeReal(fname, histOutInv, 1, 'uint16')      
% Peak detect
fname = [outFolder 'ps_out.dat'];
detMem = det_tag_format(outPeakSearch);
writeReal(fname, detMem, 1, 'uint32')     
%% Plot data
% Plot the radar cube - [rangeBins, dopplerBins] for all channels 
figure
for i=1:channels
    subplot(2,2,i)
    surf(abs(squeeze(outDopplerFftCube(:,:,i).')))
    xlabel('Range FFT'),ylabel('Doppler FFT'),
    title(['Range Doppler cube, channel ', num2str(i)]); 
end
% Plot the detected peaks resuls
figure
imagesc(abs(squeeze(outPeakSearch)))
xlabel('Range FFT'),ylabel('Doppler FFT'),
title('Peak detect'); 
    
switch(upper(HW))
    case{'S32R45'}  %SPT3.1
        rmpath '../../src/SPT3/31';
    case{'S32R41'}  %SPT3.5
        rmpath '../../src/SPT3/34_35';
    case{'SAF85XX'} %SPT3.4
        rmpath '../../src/SPT3/34_35';
    otherwise
        error('SPT 3.1/3.4/3.5 Example CALLED WITH WRONG HARDWARE. S32R45/S32R41/SAF85XX ARE THE ONLY VALID VALUES');
end
rmpath '../../src/SPT3/common';
rmpath '../../../Matlab_aux';

end
