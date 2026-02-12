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

% This function computes Non Coherent Combining kernel 
% Input param: 
%   - inputSamples - input samples cube defined as complex [nrRangeBins, nrDopplerBins, noChannels] 
%   - nrRangeBins - number of Range Bins
%   - nrDopplerBins  - number of Doppler Bins
%   - noChannels - number of channels/antennas
%   - shiftInput - custom left shift input (8 for non-compression; 0 for compression)
% Output:
%   - range doppler matrix (RDM) [nrRangeBins, nrDopplerBins ] 
%   - OutHist - histogram real [64, nrRangeBins]
function [Out, OutHist] = NonCohComb(inputSamples, nrRangeBins, nrDopplerBins , noChannels, shiftInput)

if ((noChannels ~= 4) && (noChannels ~= 8) && (noChannels ~= 16))
    error('NonCohComb kernel supports 4, 8 or 16 channels only.');
end

outVMT = zeros(nrDopplerBins , noChannels);
intermediateOut = zeros(nrDopplerBins , nrRangeBins);
outHist = zeros(64, nrRangeBins);

for i = 1:(nrRangeBins)
    for j = 1:noChannels
        if (shiftInput)
            %% 2D Peak Search Round 1 - VMT shift left 
            in_dattyp = 'COMPLEX';      % Complex operands
            op_sq2_st1 = 'BYPASS';      % No Preproccessing
            op_sq2_st2 = 'SHIFT';       % Shift
            op_sq2_st3 = 'BYPASS';      % No Operation
            shft_val = shiftInput;      % Custom left shift
            offset_val = complex(0);    % dummy for shift
            s_val = 0;                  % Multiplier value - signed 16-bit number
            n_val = 0;                  % Exponent value - 6-bit number
      
            VMT_OutShift = vmt_seq2_mex(complex(inputSamples(i,:,j)), complex(0), in_dattyp, op_sq2_st1, op_sq2_st2, op_sq2_st3, shft_val, offset_val, s_val, n_val);
        
        else
            VMT_OutShift = complex(inputSamples(i,:,j)); % no shift for compression, samples already in 24bit
        end

        %% 2D Peak Search Round 2 - VMT vector magnitude
        in_dattyp = 'COMPLEX';      % Complex operands
        op_sq2_st1 = 'MAG';         % Magnitude for complex values
        op_sq2_st2 = 'BYPASS';      % No Operation
        op_sq2_st3 = 'BYPASS';      % No Operation
        shft_val = 0;               % Shift value - signed 6-bit number
        offset_val = complex(0);    % dummy for shift
        s_val = 0;                  % Multiplier value - signed 16-bit number
        n_val = 0;                  % Exponent value - 6-bit number

        VMT_OutMag = vmt_seq2_mex(VMT_OutShift, complex(0), in_dattyp, op_sq2_st1, op_sq2_st2, op_sq2_st3, shft_val, offset_val, s_val, n_val);
    
        outVMT(:,j) = VMT_OutMag;
    end

    %% 2D Peak Search Round 3 - SCP sum channels
    %Pre-scaling left shift value
    shft_val = 0; %   0 - no shift 
    %Coefficients values
    if (noChannels == 4)
        M_Coeff = [32767, 32767, 32767, 32767]; % 7FFF
    elseif (noChannels == 8)
        M_Coeff = [16383, 16383, 16383, 16383, 16383, 16383, 16383, 16383]; % 0x3FFF
    else
        M_Coeff = [8192, 8192, 8192, 8192, 8192, 8192, 8192, 8192, 8192, 8192, 8192, 8192, 8192, 8192, 8192, 8192]; % 0x2000
    end
    
    scpIn = reshape(outVMT.', 1, []);

    scpOut = scp_mex(complex(M_Coeff), complex(scpIn), shft_val);    
 
    intermediateOut(:, i) = scpOut;
    
    %% 2D Peak Search Round 4 - VMT Mag2 + log2

    VMT_OutLog2 = vmt_mag2_log2_mex(scpOut);

    intermediateOut(:, i) = VMT_OutLog2;
    
    %% Compute histogram 
    dat_typ = 'LOG2';
    preproc = 'NO_PROCESSING';
    bin_sz = '64BINS';
    thr = 0;

    outHist(:, i) = hist_mex(VMT_OutLog2, dat_typ, preproc, bin_sz, thr);

end

OutHist = outHist;
Out = intermediateOut.';

end
