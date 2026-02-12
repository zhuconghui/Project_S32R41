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

% This function computes Digital Beamforming - DBF for 64 Steering Vector,
%                 4/8 channels and 128 peaks and Direction of Arrival
% Input param:
%   - inputPeakList - input samples matrix defined as complex [128, noChannels(4 or 8)] 
%   - steeringVectors - array of steeringVectors as complex [64, noChannels(4 or 8)]
%   - noChannels - number of channels/antennas
%   - thresholdFactor - Threshold Factor, used for Threshold calculation (14bit log2 format).
%   - shiftInput - custom left shift input (8 for non-compression; 0 for compression)
% Output:
%   - tagged DBF for DOA real [128, 64] (log2+mag2 tagged as in SPT mem)
function outDoa = DBF_DOA(inputPeakList, steeringVectors, noChannels, thresholdFactor, shiftInput)

     if ((noChannels ~= 4) && (noChannels ~= 8) && (noChannels ~= 16))
        error('No antennas not supported by kernel');
     end

    scpOut = zeros(64, 128);
    vmtOutLog2 = zeros(64, 128);
    maxGlobalOut = zeros(128, 0);
    computedThreshold = zeros(128, 0);
    maxLocalBeamOut = zeros(64, 128);
    
    % Convert to array for SCP input
    inputPeakListScp = reshape(inputPeakList, 1, []);
    
    % SCP
    % SCP indirect: scalar product with 4 taps S = (P_A*SV_A + P_A*SV_A + P_C*SV_C + P_D*SV_D)/4, done for 4ch x PEAK_NUM(64).
    % Shift left(8) the input values, to work on 24bit resolution
    % SPT kernel command: scp.ind .cmplx .coef_cmplx .shift8 SCALAR_PROD_TAPS CHANNEL_NUM*PEAK_NUM WR_16, TR_447_0, 0x1, 0x1    
    %Pre-scaling left shift value
    shft_val = shiftInput;
    for i = 1:64
        scpOut(i,:) = scp_mex(steeringVectors(:,i), inputPeakListScp, shft_val); 
        % VMT
        % VMT: Operation Sequence 1
        % (Mag2 and log2). Done for 128 peaks*64beams
        % SPT kernel command: vmt .cmplx .rst_sum .in_48 .op_on .sq1 .no_sq2s1 .no_sq2s3 PEAK_NUM*BEAM_NUM OR_0_0_0, OR_1_0_0, WR_47, 0x1, 0x1    
        vmtOutLog2(i,:) = vmt_mag2_log2_mex(scpOut(i,:));
    end
    
    for i = 1:128
        % MAXS
        % Global MAXS on a beamscan, input packing, no threshold (WR_47 dummy)
        % SPT kernel command: maxs.gbl.ind .log2 .no_pre .in_48packed .no_maxsn BEAM_NUM WR_21, 0x1, 0x1, WR_47
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
        maxsn_sel = 'MAXSN_DISABLED'; % no MAXS
        % Threshold mode comparison - thld_mode
        thld_mode = 'GREATER'; % don't care
        %Output mode
        out_mode = 'TAGGED'; % Tagged
        maxGlobalOut(i) = maxs_mex(complex(0), complex(vmtOutLog2(:, i)), in_dattyp, preproc, in_tag, max_mode, cyc_extn, maxsn_sel, thld_mode, out_mode);
        
        % SEL
        % If (GLB_MAX - thresholdFactor) > 0 then Threshold = (GLB_MAX - thresholdFactor)
        % If (GLB_MAX - thresholdFactor) <= 0 then Threshold = GLB_MAX
        if ((maxGlobalOut(i) - thresholdFactor) > 0)
            computedThreshold(i) = maxGlobalOut(i) - thresholdFactor;
        else
            computedThreshold(i) = maxGlobalOut(i);
        end
        
        % MAXS 
        % MAXS with output tagging: local maxima on a beamscan, OUT packing
        % no cyclic extention search, threshold in computedThreshold
        % SPT kernel command: maxs.ind .log2 .no_pre .thld_cmp .no_tag_in .tagged_vect .no_cyc_ext .in_48packed .no_maxsn BEAM_NUM WR_23, 0x1, 0x1, WR_45
        in_dattyp = 'LOG2';
        %Pre-processing
        preproc = 'NO_PROCESSING'; % No preprocessing (for log2 and others)
        %Input Tagged
        in_tag = 'NO_TAG'; % Input is not tagged
        %Global maxima
        max_mode = 'LOCAL_MAXIMA_THLD';
        %Cyclic extension (valid only for local maximum calculation)
        cyc_extn = 'NO_CYC_EXTN'; % No cyclic extension
        % MAXSN Mode Select bits - maxsn_sel
        maxsn_sel = 'MAXSN_DISABLED'; % no MAXS
        % Threshold mode comparison - thld_mode
        thld_mode = 'GREATER'; % greater
        %MAXSN enable
        out_mode = 'TAGGED'; % MAXSN disable
        maxLocalBeamOut(:,i) = maxs_mex(complex(computedThreshold(i).'), complex(vmtOutLog2(:,i)).', in_dattyp, preproc, in_tag, max_mode, cyc_extn, maxsn_sel, thld_mode, out_mode);          
                
    end
    
    outDoa = maxLocalBeamOut;

end

