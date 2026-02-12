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

% This function computes range FFT kernel 
% Input param:
%   - inputSamples - input samples cube defined as real [samplesPerChirp,chirpsPerFrame,noChannels] 
%   - winCoef - array of window coefficients real
%   - twiddleCoef - array of twiddle coefficients complex 
%   - samplesPerChirp - number of samples per chirp
%   - chirpsPerFrame - number of chirps per frame
%   - noChannels - number of channels/antennas
%   - shiftInput - custom left shift input (8)
%   - shiftOutput - custom right shift output
%   - compressionType - can be 'NO', 'CP4D'
% Output:
%   - fft cube complex [fftBins,chirpsPerFrame,noChannels] where fftBins = samplesPerChirp/2
function [Out] = rangeFFT(inputSamples, winCoef, twiddleCoef, samplesPerChirp, chirpsPerFrame, noChannels, shiftInput, shiftOutput, compressionType)

if(strcmp(compressionType, 'NO'))
    shiftOutput = shiftOutput - shiftInput;
end

% Out FFT bins
noFFTBins = samplesPerChirp/2;
% Init out range FFT cube for speed
rangeFFTCube = complex(zeros(noFFTBins, chirpsPerFrame, noChannels));

%% Range FFT kernel computes 2 channels / FFT
for j = 1:2:noChannels
    for i = 1:chirpsPerFrame
        % First channel on real part and seccond channel on imag part 
        inputSamplesMix = complex(inputSamples(:, i, j), inputSamples(:, i, j+1));
        
        %% FFT Round 0 - RDX4: left shift 8, windowing
        win_type = 'WIN_ENABLED';           % windowing is enabled
        win_coeff_type = 'MULTIPLE_COEFF';  % multiple complex values
        fft_rnd = 0;                        % round 0
        quad_ext = 'QUAD_EXT';              % don't care
        shft_val = shiftInput;              % pre-scaling left shift, no compression
        adaptv = 'NO_ADPTV';                % disable adaptive scaling

        Out_round0 = rdx4_mex(complex(winCoef.'), complex(inputSamplesMix.'), win_type, win_coeff_type, fft_rnd, quad_ext, shft_val, adaptv);

        %% FFT Round 1 - RDX4
        win_type = 'WIN_DISABLED';       % windowing is not enabled
        win_coeff_type = 'SINGLE_COEFF'; % don't care
        fft_rnd = 1;                     % round 1
        quad_ext = 'QUAD_EXT';           % quadrature extension used
        shft_val = 0;                    % no shift
        adaptv = 'NO_ADPTV';             % disable adaptive scaling

        Out_round1 = rdx4_mex(complex(twiddleCoef.'), Out_round0, win_type, win_coeff_type, fft_rnd, quad_ext, shft_val, adaptv);

        %% FFT Round 2 - RDX4
        win_type = 'WIN_DISABLED';       % windowing is not enabled
        win_coeff_type = 'SINGLE_COEFF'; % don't care
        fft_rnd = 2;                     % round 2
        quad_ext = 'QUAD_EXT';           % quadrature extension used
        shft_val = 0;                    % no shift
        adaptv = 'NO_ADPTV';             % disable adaptive scaling

        Out_round2 = rdx4_mex(complex(twiddleCoef.'), Out_round1, win_type, win_coeff_type, fft_rnd, quad_ext, shft_val, adaptv);

        %% FFT Round 3 - RDX4
        win_type = 'WIN_DISABLED';       % windowing is not enabled
        win_coeff_type = 'SINGLE_COEFF'; % don't care
        fft_rnd = 3;                     % round 3
        quad_ext = 'QUAD_EXT';           % quadrature extension used
        shft_val = 0;                    % no shift
        adaptv = 'NO_ADPTV';             % disable adaptive scaling

        Out_round3 = rdx4_mex(complex(twiddleCoef.'), Out_round2, win_type, win_coeff_type, fft_rnd, quad_ext, shft_val, adaptv);

        %% FFT Round 4 - RDX4/RDX2
        if (samplesPerChirp == 2048)
            win_type = 'WIN_DISABLED';       % windowing is not enabled
            win_coeff_type = 'SINGLE_COEFF'; % don't care
            fft_rnd = 4;                     % round 4
            quad_ext = 'QUAD_EXT';           % quadrature extension used
            shft_val = 0;                    % no shift
            adaptv = 'NO_ADPTV';             % disable adaptive scaling

            Out_round4 = rdx4_mex(complex(twiddleCoef.'), Out_round3, win_type, win_coeff_type, fft_rnd, quad_ext, shft_val, adaptv);
            
            fft_rnd = 5;                    % round 5
            real_fft = 'NO_OPERANDS_SPLIT'; % Normal Radix2 Command
            quad_ext = 'QUAD_EXT';          % quadrature extension used
            shft_val = 0;                   % no shift
            adaptv = 'NO_ADPTV';            % disable adaptive scaling

            Out_round4 = rdx2_mex(complex(twiddleCoef.'), Out_round4, fft_rnd, real_fft, quad_ext, shft_val, adaptv);
            
        elseif (samplesPerChirp == 1024)
            win_type = 'WIN_DISABLED';       % windowing is not enabled
            win_coeff_type = 'SINGLE_COEFF'; % don't care
            fft_rnd = 4;                     % round 4
            quad_ext = 'QUAD_EXT';           % quadrature extension used
            shft_val = 0;                    % no shift
            adaptv = 'NO_ADPTV';             % disable adaptive scaling

            Out_round4 = rdx4_mex(complex(twiddleCoef.'), Out_round3, win_type, win_coeff_type, fft_rnd, quad_ext, shft_val, adaptv);

        elseif (samplesPerChirp == 512)
            fft_rnd = 4;                    % round 4
            real_fft = 'NO_OPERANDS_SPLIT'; % Normal Radix2 Command
            quad_ext = 'QUAD_EXT';          % quadrature extension used
            shft_val = 0;                   % no shift
            adaptv = 'NO_ADPTV';            % disable adaptive scaling

            Out_round4 = rdx2_mex(complex(twiddleCoef.'), Out_round3, fft_rnd, real_fft, quad_ext, shft_val, adaptv);

        elseif (samplesPerChirp == 256)
            %% FFT Round 4 is skipped for 256 samples per chirp
            Out_round4 = Out_round3;
        else
            error('No of samples/chirp not supported!');            
        end
        
        %% FFT Round 5 - RDX2 Split
        fft_rnd = 5;                    % round 5
        real_fft = 'OPERANDS_SPLIT';    % Split
        quad_ext = 'QUAD_EXT';          % no quadrature extension used
        shft_val = 0;                   % no shift
        adaptv = 'NO_ADPTV';            % disable adaptive scaling

        Out_round5 = rdx2_mex(complex(twiddleCoef.'), Out_round4, fft_rnd, real_fft, quad_ext, shft_val, adaptv);
        
        %% VMT custom shift left 
        in_dattyp = 'COMPLEX';      % Complex operands
        op_sq2_st1 = 'BYPASS';      % No Preproccessing
        op_sq2_st2 = 'SHIFT';       % Shift
        op_sq2_st3 = 'BYPASS';      % No Operation
        shft_val = shiftOutput;     % Shift value - signed 6-bit number
        offset_val = complex(0);    % dummy for shift
        s_val = 0;                  % Multiplier value - signed 16-bit number
        n_val = 0;                  % Exponent value - 6-bit number

        Out_tmp = vmt_seq2_mex(complex(Out_round5), complex(0), in_dattyp, op_sq2_st1, op_sq2_st2, op_sq2_st3, shft_val, offset_val, s_val, n_val);

        %% Populate out range FFT cube
        rangeFFTCube(:, i, j) = Out_tmp(1:samplesPerChirp/2);
        rangeFFTCube(:, i, j+1) = Out_tmp(samplesPerChirp/2 + 1:samplesPerChirp);
    end
end

Out = rangeFFTCube;
end
