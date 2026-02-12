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

% This function computes 2D peak search kernel 
% Input param: 
%   - rdm - Range Doppler Matrix
%   - threshold - array of threshold values real
%   - nrRangeBins - number of Range Bins
%   - nrDopplerBins  - number of Doppler Bins
% Output:
%   - detected peaks matrix bitmap [nrRangeBins, nrDopplerBins]
function Out = peakSearch(rdm, threshold, nrRangeBins, nrDopplerBins)

outMaxRange = zeros(nrDopplerBins , nrRangeBins);
outArray = zeros(nrRangeBins, nrDopplerBins );

for i = 1:(nrRangeBins)

    %% 2D Peak Search Round 1 - Max with tagging
    %Input Data Type
    in_dattyp = 'LOG2';
    %Pre-processing
    preproc = 'NO_PROCESSING'; % No preprocessing (for log2 and others)
    %Input Tagged
    in_tag = 'NO_TAG'; % Input is not tagged
    %Local not Global maxima
    max_mode = 'LOCAL_MAXIMA_THLD'; % Local maxima with threshold to be calculated
    %Cyclic extension (valid only for local maximum calculation)
    cyc_extn = 'NO_CYC_EXTN'; % Cyclic extension disabled
    % MAXSN Mode Select bits - maxsn_sel
    maxsn_sel = 'MAXSN_DISABLED'; % no maxes
    % Threshold mode comparison - thld_mode
    thld_mode = 'GREATER'; % greater
    %TAGGED output enabled
    out_mode = 'TAGGED';

    MAX_range_Out = maxs_mex(complex(threshold(i).'), complex(rdm(i,:)).', in_dattyp, preproc, in_tag, max_mode, cyc_extn, maxsn_sel, thld_mode, out_mode);               

    outMaxRange(:,i) = MAX_range_Out;    
end

for i = 1:nrDopplerBins 
    %% 2D Peak Search Round 2 - Max on tagged input
    %Input Data Type
    in_dattyp = 'LOG2';
    %Pre-processing
    preproc = 'NO_PROCESSING'; % No preprocessing (for log2 and others)
    %Input Tagged
    in_tag = 'TAGGED'; % Input is tagged
    %Local not Global maxima
    max_mode = 'LOCAL_MAXIMA'; % Local maxima to be calculated
    %Cyclic extension (valid only for local maximum calculation)
    cyc_extn = 'NO_CYC_EXTN'; % Cyclic extension disabled
    % MAXSN Mode Select bits - maxsn_sel
    maxsn_sel = 'MAXSN_DISABLED'; % no maxs
    % Threshold mode comparison - thld_mode
    thld_mode = 'GREATER'; % greater
    %BITFIELD output enabled
    out_mode = 'BITFIELD';

    MAX_final_Out = maxs_mex(complex(0), complex(outMaxRange(i,:)), in_dattyp, preproc, in_tag, max_mode, cyc_extn, maxsn_sel, thld_mode, out_mode);               
   
    outArray(:,i) = MAX_final_Out;

end

Out = outArray;

end
