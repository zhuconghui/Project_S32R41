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

% This function computes 3D FFT kernel 
% Input param: 
%   - inputSamples - input samples cube defined as complex [nrRangeBins, nrDopplerBins, noChannels]
%   - twiddleCoef - array of twiddle coefficients complex
%   - nrRangeBins - number of Range Bins
%   - nrDopplerBins  - number of Doppler Bins
%   - noChannels - number of channels/antennas
%   - shiftInput - custom left shift input (8 for non-compression; 0 for compression)
% Output:
%   - range doppler matrix (RDM) [nrRangeBins, nrDopplerBins ] 
%   - OutHist - histogram real [64, nrRangeBins]
function [Out, OutHist] = FFT3D(inputSamples, twiddleCoef, nrRangeBins, nrDopplerBins , noChannels, shiftInput)
if ((noChannels ~= 4) && (noChannels ~= 8) && (noChannels ~= 16))
    error('FFT3D kernel does not support this number of antennas.');
end

%outArray = zeros(nrDopplerBins , nrRangeBins/16/2);
outArray = zeros(nrRangeBins, nrDopplerBins );
outHist = zeros(64, nrRangeBins);

% permute input cube: first column is channels
inAux = permute(inputSamples, [3,2,1]);
% compute padding size
paddSize = 16 - noChannels;


for i = 1:nrRangeBins
    % pad input with zeros for fft16
    paddedIn = zeros(16, nrDopplerBins);
    for p = 1:nrDopplerBins
        paddedIn(:,p) = [inAux(:, p, i)' zeros([1 paddSize])];
    end
    % convert matrix into one dimension array
    inDataForFFT16 = reshape(paddedIn, 1, []);
    
    %% 3D Peak Search Round 1 - FFT16
    % FFT Round 0 - RDX4: left shift 8
    win_type = 'WIN_DISABLED';          % windowing is disabled
    win_coeff_type = 'SINGLE_COEFF';    % don't care
    fft_rnd = 0;                        % round 0
    quad_ext = 'QUAD_EXT';              % quadrature extension used
    shft_val = shiftInput;              % no shift for compression, samples already in 24bit
    adaptv = 'NO_ADPTV';                % disable adaptive scaling
    repeat = length(inDataForFFT16)/16; %FFT16
 
    outFFTRound0 = rdx4_mex(complex(twiddleCoef.'), complex(inDataForFFT16), win_type, win_coeff_type, fft_rnd, quad_ext, shft_val, adaptv, repeat);
    
    % FFT Round 1 - RDX4: left shift 8
    win_type = 'WIN_DISABLED';          % windowing is disabled
    win_coeff_type = 'MULTIPLE_COEFF';  % don't care
    fft_rnd = 1;                        % round 1
    quad_ext = 'QUAD_EXT';              % quadrature extension used
    shft_val = 0;                       % pre-scaling left shift 8
    adaptv = 'NO_ADPTV';                % disable adaptive scaling
    repeat = length(inDataForFFT16)/16; %FFT16

    outFFTRound1 = rdx4_mex(complex(twiddleCoef.'), complex(outFFTRound0), win_type, win_coeff_type, fft_rnd, quad_ext, shft_val, adaptv, repeat);
 
    %% 3D Peak Search Round 2 - VMT Mag2 + log2

    VMT_OutLog2 = vmt_mag2_log2_mex(complex(outFFTRound1));
         
    %% 3D Peak Search Round 3 - Global Max
    %Input Data Type
    in_dattyp = 'LOG2';
    %Pre-processing
    preproc = 'NO_PROCESSING'; % No preprocessing (for log2 and others)
    %Input Tagged
    in_tag = 'NO_TAG'; % Input is not tagged
    %Global maxima
    max_mode = 'GLOBAL_MAXIMA';
    %Cyclic extension (valid only for local maximum calculation)
    cyc_extn = 'NO_CYC_EXTN'; % No cyclic extension
    % MAXSN Mode Select bits - maxsn_sel
    maxsn_sel = 'MAXS8'; % maxs8
    % Threshold mode comparison - thld_mode
    thld_mode = 'GREATER'; % doesn't matter
    %Tag not bitfield (valid only for local maximum calculation)
    out_mode = 'TAGGED'; % tagged
    repeat = size(VMT_OutLog2,2)/8;

    maxGlobalOutTmp_1 = maxs_mex(complex(0), complex(VMT_OutLog2), in_dattyp, preproc, in_tag, max_mode, cyc_extn, maxsn_sel, thld_mode, out_mode, repeat);   
    
    maxGlobalOutTmp_2 = complex(zeros(1,4*size(maxGlobalOutTmp_1,2)));
    for j = 1:2:size(maxGlobalOutTmp_1,2)
        maxGlobalOutTmp_2(1,(4*j-3):(4*j-2)) = maxGlobalOutTmp_1(1,j:(j+1));
    end

    %Input Data Type
    in_dattyp = 'LOG2';
    %Pre-processing
    preproc = 'NO_PROCESSING'; % No preprocessing (for log2 and others)
    %Input Tagged
    in_tag = 'NO_TAG'; % Input is not tagged
    %Global maxima
    max_mode = 'GLOBAL_MAXIMA';
    %Cyclic extension (valid only for local maximum calculation)
    cyc_extn = 'NO_CYC_EXTN'; % No cyclic extension
    % MAXSN Mode Select bits - maxsn_sel
    maxsn_sel = 'MAXS8'; % maxs8
    % Threshold mode comparison - thld_mode
    thld_mode = 'GREATER'; % doesn't matter
    %Tag not bitfield (valid only for local maximum calculation)
    out_mode = 'TAGGED'; % tagged
    repeat = size(maxGlobalOutTmp_2,2)/8;
    
    maxGlobalOut = maxs_mex(complex(0), complex(maxGlobalOutTmp_2), in_dattyp, preproc, in_tag, max_mode, cyc_extn, maxsn_sel, thld_mode, out_mode, repeat);   
    
    outArray(i,:) = maxGlobalOut;

    %% Compute histogram 
    dat_typ = 'LOG2';
    preproc = 'NO_PROCESSING';
    bin_sz = '64BINS';
    thr = 0;
 
    outHist(:, i) = hist_mex(complex(maxGlobalOut), dat_typ, preproc, bin_sz, thr);    

    
end


OutHist = outHist;
Out = outArray;

end
