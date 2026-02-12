%{
    Copyright 2017-2022 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function Sd = dfft_out_unformat(SdMem, pdmaCompressionType, nrRangeBins, nrDopplerBins, nrVirtAnt)
% Rearrange data from SPT mem layout to radar cube 
% Radar cube - [ RangeBins: 0:N-1, DopplerBins: -(M/2):(M/2)-1, Ant: 0:P-1]

global CONST

if strcmp(pdmaCompressionType, 'NO')
    % SPT Memory layout, SRAM, 32bit complex(16b_Im + 16b_Re)
    % 63:48                                 47:32                               31:16                               15:0
    % CH0_Im-Crp0                           CH0_Re-Crp0                         CH1_Im-Crp0                         CH1_Re-Crp0
	% |                                     |                                   |                                   |
    % CH<nrVirtAnt-2>_Im-Crp0               CH<nrVirtAnt-2>_Re-Crp0             CH<nrVirtAnt-1>_Im-Crp0             CH<nrVirtAnt-1>_Re-Crp0
    % |                                     |                                   |                                   |
    % |                                     |                                   |                                   |
    % |                                     |                                   |                                   |
    % CH0_Im-Crp<nrChirps-1>                CH0_Re-Crp<nrChirps-1>              CH1_Im-Crp<nrChirps-1>              CH1_Re-Crp<nrChirps-1>
	% |                                     |                                   |                                   |
    % CH<nrVirtAnt-2>_Im-Crp<nrChirps-1>    CH<nrVirtAnt-2>_Re-Crp<nrChirps-1>  CH<nrVirtAnt-1>_Im-Crp<nrChirps-1>  CH<nrVirtAnt-1>_Re-Crp<nrChirps-1>  ---> RangeBin #0
    % ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    % |                                     |                                   |                                   |
    % |                                     |                                   |                                   |
    % |                                     |                                   |                                   |
    % |                                     |                                   |                                   |
    % |                                     |                                   |                                   |
    % |                                     |                                   |                                   |
    % ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    % CH0_Im-Crp0                           CH0_Re-Crp0                         CH1_Im-Crp0                         CH1_Re-Crp0
	% |                                     |                                   |                                   |
    % CH<nrVirtAnt-2>_Im-Crp0               CH<nrVirtAnt-2>_Re-Crp0             CH<nrVirtAnt-1>_Im-Crp0             CH<nrVirtAnt-1>_Re-Crp0
    % |                                     |                                   |                                   |
    % |                                     |                                   |                                   |
    % |                                     |                                   |                                   |
    % CH0_Im-Crp<nrChirps-1>                CH0_Re-Crp<nrChirps-1>              CH1_Im-Crp<nrChirps-1>              CH1_Re-Crp<nrChirps-1>
	% |                                     |                                   |                                   |
    % CH<nrVirtAnt-2>_Im-Crp<nrChirps-1>    CH<nrVirtAnt-2>_Re-Crp<nrChirps-1>  CH<nrVirtAnt-1>_Im-Crp<nrChirps-1>  CH<nrVirtAnt-1>_Re-Crp<nrChirps-1>  ---> RangeBin #nrRangeBins-1
    % ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    dIm = downsample(SdMem,2,0);
    dRe = downsample(SdMem,2,1);
    SdMem = dRe + 1i*dIm;

    ch = zeros((nrRangeBins * nrDopplerBins), nrVirtAnt);
    Sd = zeros(nrRangeBins, nrDopplerBins, nrVirtAnt);
    for i = 1:nrVirtAnt
        ch(:,i) = downsample(SdMem, nrVirtAnt, (i-1))./CONST.MAX_INT16;
        Sd(:,:,i) = (reshape(ch(:,i), nrDopplerBins, nrRangeBins).');
    end

elseif ~strcmp(pdmaCompressionType, 'NO')
    if(~CONST.isMEXPresent)
        fprintf(2, 'NO SPT TOOLBOX OR SPT TOOLBOX < VER 1.5.1.\nDOPPLER data cannot be visualized with compression.\nInstall SPT Toolbox Ver 1.5.1\n');
    end

    dfft_samples = zeros(1,nrRangeBins*nrDopplerBins*nrVirtAnt);
    if(CONST.isMEXPresent)   
        if (strcmp(pdmaCompressionType, 'CP4D') || strcmp(pdmaCompressionType, 'CP4Q'))
            % OUTPUT Memory layout:
            % SRAM, 64bit compressed data
            % 63:0
            % CH0CH1CH2CH3-Crp0
            % |
            % CH<nrVirtAnt-4>CH<nrVirtAnt-3>CH<nrVirtAnt-2>CH<nrVirtAnt-1>-Crp0
            % |
            % |
            % |
            % CH0CH1CH2CH3-Crp<nrChirps-1>
            % |
            % CH<nrVirtAnt-4>CH<nrVirtAnt-3>CH<nrVirtAnt-2>CH<nrVirtAnt-1>-Crp<nrChirps-1>  ---> RangeBin #0
            % ------------------------------------------------------------------------------------------------------------
            % |
            % |
            % |
            % |
            % |
            % |
            % ------------------------------------------------------------------------------------------------------------
            % CH0CH1CH2CH3-Crp0
            % |
            % CH<nrVirtAnt-4>CH<nrVirtAnt-3>CH<nrVirtAnt-2>CH<nrVirtAnt-1>-Crp0
            % |
            % |
            % |
            % CH0CH1CH2CH3-Crp<nrChirps-1>
            % |
            % CH<nrVirtAnt-4>CH<nrVirtAnt-3>CH<nrVirtAnt-2>CH<nrVirtAnt-1>-Crp<nrChirps-1>  ---> RangeBin #<nrRangeBins-1>
            % ------------------------------------------------------------------------------------------------------------
        
            nrSampPerPacket = 2; % 32bit Packet
            jumpSize = nrRangeBins * nrVirtAnt;
            cpJumpSize = jumpSize / nrSampPerPacket;

            for i=0:(nrDopplerBins-1)
            if strcmp(pdmaCompressionType, 'CP4D') && ~strcmp(CONST.HW, 'S32R41')
                    dfft_samples((jumpSize*i+1):(jumpSize*(i+1))) = pdma_mex(SdMem((cpJumpSize*i+1):(cpJumpSize*(i+1))),'CP4D','DECOMPRESSION');
                else
                    dfft_samples((jumpSize*i+1):(jumpSize*(i+1))) = pdma_mex(SdMem((cpJumpSize*i+1):(cpJumpSize*(i+1))),'CP4Q','DECOMPRESSION');
                end
            end

        elseif (strcmp(pdmaCompressionType, 'CP4DFMTB'))
            % Input Data (32-bit): [16 (mantissa) + 1 (exponent)] * 2
            % Output Data (48-bit complex): 4 x 16 (for a complete 64-bit exponent)
            cpJumpSize = 34;
            jumpSize   = 64;
            dfft_samples = zeros(1,nrRangeBins*nrDopplerBins*nrVirtAnt);

            for i=0:length(SdMem)/cpJumpSize-1
                dfft_samples((jumpSize*i+1):(jumpSize*(i+1))) = ...
                    pdma_mex(SdMem((cpJumpSize*i+1):(cpJumpSize*(i+1))),'CP4DFMTB','DECOMPRESSION');
            end  

        elseif (strcmp(pdmaCompressionType, 'CP8FMTB'))
            % Input Data (32-bit): [[16 (mantissa) + 1 (exponent)] * 2] * 2
            % Output Data (48-bit complex): 8 x 16 (for a complete 64-bit exponent)
            cpJumpSize = 68;
            jumpSize   = 128;

            for i=0:length(SdMem)/cpJumpSize-1
                dfft_samples((jumpSize*i+1):(jumpSize*(i+1))) = ...
                    pdma_mex(SdMem((cpJumpSize*i+1):(cpJumpSize*(i+1))),'CP8FMTB','DECOMPRESSION');
            end          

        elseif (strcmp(pdmaCompressionType, 'CP16FMTB'))
            % Input Data (32-bit): [[16 (mantissa) + 1 (exponent)] * 2] * 4
            % Output Data (48-bit complex): 16 x 16 (for a complete 64-bit exponent)
            cpJumpSize = 136;
            jumpSize   = 256;

            for i=0:length(SdMem)/cpJumpSize-1
                dfft_samples((jumpSize*i+1):(jumpSize*(i+1))) = ...
                    pdma_mex(SdMem((cpJumpSize*i+1):(cpJumpSize*(i+1))),'CP16FMTB','DECOMPRESSION');
            end  

        else
            error('PDMA Compression Type NOT supported');
        end
    end
    if(~CONST.isMEXPresent) 
        dfft_samples = zeros(1,nrRangeBins*nrDopplerBins*nrVirtAnt);
    else
        dfft_samples = dfft_samples./CONST.MAX_INT24;
    end

    Sd = zeros(nrRangeBins, nrDopplerBins, nrVirtAnt);
    for i = 1:nrVirtAnt
        Sd(:,:,i) = reshape(dfft_samples(i:nrVirtAnt:end),nrDopplerBins, nrRangeBins).';
    end
else
    error('Doppler output unformat NOT supported!')
end
