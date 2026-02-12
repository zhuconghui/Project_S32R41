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

function SrMem = rfft_out_format(Sr, pdmaCompressionType, nrRangeBins, nrChirps, nrAnt)
% Input radar cube dimensions are Sr - [ Range, Chirps, Antenna]

global CONST

if strcmp(pdmaCompressionType, 'NO')
    % SPT Memory layout, SRAM, 32bit complex(16b_Im + 16b_Re)
    % 63:48                             47:32                           31:16                           15:0
    % CH0_Im-Crp0                       CH0_Re-Crp0                     CH1_Im-Crp0                     CH1_Re-Crp0
	% |                                 |                               |                               |
    % CH<nrAnt-2>_Im-Crp0               CH<nrAnt-2>_Re-Crp0             CH<nrAnt-1>_Im-Crp0             CH<nrAnt-1>_Re-Crp0
    % |                                 |                               |                               |
    % |                                 |                               |                               |
    % |                                 |                               |                               |
    % CH0_Im-Crp<nrChirps-1>            CH0_Re-Crp<nrChirps-1>          CH1_Im-Crp<nrChirps-1>          CH1_Re-Crp<nrChirps-1>
	% |                                 |                               |                               |
    % CH<nrAnt-2>_Im-Crp<nrChirps-1>    CH<nrAnt-2>_Re-Crp<nrChirps-1>  CH<nrAnt-1>_Im-Crp<nrChirps-1>  CH<nrAnt-1>_Re-Crp<nrChirps-1>  ---> RangeBin #0
    % --------------------------------------------------------------------------------------------------------------------------------------------------------------
    % |                                 |                               |                               |
    % |                                 |                               |                               |
    % |                                 |                               |                               |
    % |                                 |                               |                               |
    % |                                 |                               |                               |
    % |                                 |                               |                               |
    % --------------------------------------------------------------------------------------------------------------------------------------------------------------
    % CH0_Im-Crp0                       CH0_Re-Crp0                     CH1_Im-Crp0                     CH1_Re-Crp0
	% |                                 |                               |                               |
    % CH<nrAnt-2>_Im-Crp0               CH<nrAnt-2>_Re-Crp0             CH<nrAnt-1>_Im-Crp0             CH<nrAnt-1>_Re-Crp0
    % |                                 |                               |                               |
    % |                                 |                               |                               |
    % |                                 |                               |                               |
    % CH0_Im-Crp<nrChirps-1>            CH0_Re-Crp<nrChirps-1>          CH1_Im-Crp<nrChirps-1>          CH1_Re-Crp<nrChirps-1>
	% |                                 |                               |                               |
    % CH<nrAnt-2>_Im-Crp<nrChirps-1>    CH<nrAnt-2>_Re-Crp<nrChirps-1>  CH<nrAnt-1>_Im-Crp<nrChirps-1>  CH<nrAnt-1>_Re-Crp<nrChirps-1>  ---> RangeBin #nrRangeBins-1
    % --------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    Sr_chALL = zeros(nrRangeBins*nrChirps,2*nrAnt);
    for i = 1:nrAnt
        ch_cmplx = reshape(Sr(:,:,i).', [], 1);
        Sr_ch = [imag(ch_cmplx), real(ch_cmplx)];
       
        Sr_chALL(:,(2*i-1):(2*i)) = Sr_ch;
    end

    SrMem_tmp = reshape(Sr_chALL.', 1, []);
    SrMem = round(SrMem_tmp * CONST.MAX_INT16);

elseif ~strcmp(pdmaCompressionType, 'NO')
    if(~CONST.isMEXPresent)
        fprintf(2, 'NO SPT TOOLBOX OR SPT TOOLBOX < VER 1.5.1.\nApplication will exit.\nCompression detected.\nInstall SPT Toolbox Ver 1.5.1\n');
        return;
    end
    
    tmp = permute(Sr,[3,2,1]);
    SrMemUnComp = round(tmp(:) * CONST.MAX_INT24);
    
    if (strcmp(pdmaCompressionType, 'CP4D') || strcmp(pdmaCompressionType, 'CP4Q'))
        % OUTPUT Memory layout:
        % SRAM, 64bit compressed data
        % 63:0
        % CH0CH1CH2CH3-Crp0
        % |
        % CH<nrAnt-4>CH<nrAnt-3>CH<nrAnt-2>CH<nrAnt-1>-Crp0
        % |
        % |
        % |
        % CH0CH1CH2CH3-Crp<nrChirps-1>
        % |
        % CH<nrAnt-4>CH<nrAnt-3>CH<nrAnt-2>CH<nrAnt-1>-Crp<nrChirps-1>  ---> RangeBin #0
        % --------------------------------------------------------------------------------------------
        % |
        % |
        % |
        % |
        % |
        % |
        % --------------------------------------------------------------------------------------------
        % CH0CH1CH2CH3-Crp0
        % |
        % CH<nrAnt-4>CH<nrAnt-3>CH<nrAnt-2>CH<nrAnt-1>-Crp0
        % |
        % |
        % |
        % CH0CH1CH2CH3-Crp<nrChirps-1>
        % |
        % CH<nrAnt-4>CH<nrAnt-3>CH<nrAnt-2>CH<nrAnt-1>-Crp<nrChirps-1>  ---> RangeBin #<nrRangeBins-1>
        % --------------------------------------------------------------------------------------------

        nrSampPerPacket = 2; % 32bit Packet contains 2 complex samples compressed

        jumpSize = nrRangeBins * nrAnt;
        cpJumpSize = jumpSize / nrSampPerPacket;

        SrMem = uint32(zeros(1,nrRangeBins*nrChirps*nrAnt/nrSampPerPacket));

        for i=0:(nrChirps-1)
            if strcmp(pdmaCompressionType, 'CP4D') && ~strcmp(CONST.HW, 'S32R41')
                SrMem((cpJumpSize*i+1):(cpJumpSize*(i+1))) = pdma_mex(complex(SrMemUnComp((jumpSize*i+1):(jumpSize*(i+1)))),'CP4D','COMPRESSION','FIXED_VALUE');
            else
                SrMem((cpJumpSize*i+1):(cpJumpSize*(i+1))) = pdma_mex(complex(SrMemUnComp((jumpSize*i+1):(jumpSize*(i+1)))),'CP4Q','COMPRESSION','FIXED_VALUE');
            end
        end

    elseif strcmp(pdmaCompressionType, 'CP4DFMTB')    
        % Input Data (48-bit complex): 4 x 16 (for a complete 64-bit exponent)
        % Output Data (32-bit): [16 (mantissa) + 1 (exponent)] * 2
        cpJumpSize = 34;
        jumpSize   = 64;
                    
        for i=0:length(SrMemUnComp)/jumpSize-1
            SrMem((cpJumpSize*i+1):(cpJumpSize*(i+1))) = ...
                pdma_mex(complex(SrMemUnComp((jumpSize*i+1):(jumpSize*(i+1)))),'CP4DFMTB','COMPRESSION','FIXED_VALUE');
        end
        
    elseif strcmp(pdmaCompressionType, 'CP8FMTB') 
        % Input Data (48-bit complex): 8 x 16 (for a complete 64-bit exponent)
        % Output Data (32-bit): [[16 (mantissa) + 1 (exponent)] * 2] * 2
        cpJumpSize = 68;
        jumpSize   = 128;
        
        for i=0:length(SrMemUnComp)/jumpSize-1
            SrMem((cpJumpSize*i+1):(cpJumpSize*(i+1))) = ...
                pdma_mex(complex(SrMemUnComp((jumpSize*i+1):(jumpSize*(i+1)))),'CP8FMTB','COMPRESSION','FIXED_VALUE');
        end
        
    elseif strcmp(pdmaCompressionType, 'CP16FMTB')
        % Input Data (48-bit complex): 16 x 16 (for a complete 64-bit exponent)
        % Output Data (32-bit): [[16 (mantissa) + 1 (exponent)] * 2] * 4
        cpJumpSize = 136;
        jumpSize   = 256;
        
        for i=0:length(SrMemUnComp)/jumpSize-1
            SrMem((cpJumpSize*i+1):(cpJumpSize*(i+1))) = ...
                pdma_mex(complex(SrMemUnComp((jumpSize*i+1):(jumpSize*(i+1)))),'CP16FMTB','COMPRESSION','FIXED_VALUE');
        end
    else
        error('PDMA Compression Type NOT supported');
    end
else
    error('Range output format NOT supported!')
end
