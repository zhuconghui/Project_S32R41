%
% Copyright 2017-2021,2024 NXP
% NXP Confidential and Proprietary. This software is owned or controlled by NXP and
% may only be used strictly in accordance with the applicable license terms.  By
% expressly accepting such terms or by downloading, installing, activating and/or
% otherwise using the software, you are agreeing that you have read, and that you
% agree to comply with and are bound by, such license terms.  If you do not agree to
% be bound by the applicable license terms, then you may not retain, install, activate or
% otherwise use the software.
%
function RSDK_offline_example(HW)
%% Setup and run RSDK_offline_example
% INPUT arguments:
% HW: must be 'S32R41' or 'SAF85XX'

% Init
close all

% Solve paths
if ~isdeployed
    addpath(genpath('../../../Tools/Matlab_aux'));
end

if (exist('HW', 'var') == 0)   
    error('Missing input argument: HW. Valid values: "S32R41" or "SAF85XX" ')
end

HW = upper(HW);
global CONST
CONST = init_CONST(HW); % put HW as parameter to init
CONST.endian = 'ieee-be';

inFolder = strcat('../data/in/', CONST.HW, '/');
outFolder = strcat('../data/out/', CONST.HW, '/');

GENERATE_IN = 0;

nrSamples = 512;
nrChirps  = 128;
nrAnt     = 4;
nrVirtAnt = 4;

pdmaCompressionType = 'NO';
nrRangeBins = nrSamples/2;
nrDopplerBins = nrChirps;

% Read output data
fname = [outFolder,'rfft_out.dat'];
rfftOutMem = readReal(fname,2^15,'int16');
rfftOut = rfft_out_unformat(rfftOutMem, pdmaCompressionType, nrRangeBins, nrChirps, nrAnt);
figure,surf(abs(rfftOut(:,:,1))), title('Range FFT output'), xlabel('Chirps'), ylabel('Range bins')

fname = [outFolder,'dfft_out.dat'];
dfftOutMem = readReal(fname,2^15,'int16');
dfftOut = dfft_out_unformat(dfftOutMem,pdmaCompressionType, nrRangeBins, nrDopplerBins, nrAnt);
figure,surf(abs(dfftOut(:,:,1))),title('Doppler FFT output'), xlabel('Doppler bins'), ylabel('Range bins')

fname = [outFolder,'ncc_out.dat'];
rdMagMem = readReal(fname,2^15,'uint16');
rdMag = rd_mag_unformat(rdMagMem, nrRangeBins, nrDopplerBins);
figure,surf(rdMag),title('RD-Magnitude - "Log2 Mag2" format'), xlabel('Doppler bins'), ylabel('Range bins')

fname = [outFolder,'ps_out.dat'];
psStream = readReal(fname,1,'uint8');
psMem = charStreamToInt(psStream,4,'u');
psTag = det_tag_unformat(psMem,nrRangeBins, nrDopplerBins);
figure,surf(psTag),title('SPT Peak search'), xlabel('Doppler bins'), ylabel('Range bins')

fname = [outFolder,'caCfar_bmp_out.dat'];
cfarStream = readReal(fname,1,'uint8');
cfarMem = charStreamToInt(cfarStream,4,'u');
cfarTag = det_tag_unformat(cfarMem, nrDopplerBins, nrRangeBins);
cfarTag = cfarTag.'; % output from DSP is RDM transposed
figure,surf(cfarTag),title('DSP Peak search'), xlabel('Doppler bins'), ylabel('Range bins')

fname = [outFolder,'detIdx_out.dat'];
if isfile(fname)
detStream = readReal(fname,1,'uint8');
detIndexes = charStreamToInt(detStream,4,'u');
detBitmap = zeros(nrRangeBins,nrDopplerBins);
detBitmap = detBitmap.';
detBitmap(detIndexes+1) = 1;
detBitmap = detBitmap.';
figure,surf(detBitmap), title('Merged detects'), xlabel('Doppler bins'), ylabel('Range bins')
end

if (strcmp(HW, 'S32R45') == 1)
    fSpec = -64:63;
    fSpec = fSpec/64;
    fAxis = asin(fSpec)/pi*180;
    fname = [outFolder,'dbfFft_out.dat'];
    if isfile(fname)
        fid = fopen(fname);
        laxOutMem = fread(fid,'float');
        fclose(fid);
        re = downsample(laxOutMem,2,0);
        im = downsample(laxOutMem,2,1);
        laxOut = re + 1i*im;
        laxOut = reshape(laxOut,128,[]);
        figure,plot(fAxis,abs(laxOut()));
    else
        disp('Warning: LAX beamfornig output is not available. If the RSDK Offline example is running bare-metal, this is normal.')
    end
end
    
% Remove added paths from MATLAB search path list
if ~isdeployed
    rmpath(genpath('../../../Tools/Matlab_aux'));
end

end