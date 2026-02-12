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

function antDataMem = doa_beamform_in_format(antData, pdmaCompressionType, nrPeaks, nrAnt)
% Rearrange data from radar cube to SPT memory layout
% Input: 
%        - antData - [nrAnt, nrPeaks]
%        - pdmaCompressionType - 'NO' or 'CP4D'
%        - nrPeaks
%        - nrAnt
% Output:
%        - antDataMem - array of int16
global CONST

if strcmp(pdmaCompressionType, 'NO')
    % SPT mem layout:
    % *    SRAM, 32bit complex(16b_Im + 16b_Re)
    % *    63:48         47:32           31:16           15:0
    % *    P0_Im-A       P0_Re-A         P0_Im-B         P0_Re-B
    % *    P0_Im-C       P0_Re-C         P0_Im-D         P0_Re-D
    % *    P1_Im-A       P1_Re-A         P1_Im-B         P1_Re-B
    % *    P1_Im-C       P1_Re-C         P1_Im-D         P1_Re-D
    % *    |             |               |               |
    % *    |             |               |               |
    % *    |             |               |               |
    % *    P127_Im-A     P127_Re-A       P127_Im-B       P127_Re-B
    % *    P127_Im-C     P127_Re-C       P127_Im-D       P127_Re-D
    %**************************************************************************
    
    dataIm = imag(antData(:)).';
    dataRe = real(antData(:)).';
    
    layout = [ dataIm
               dataRe];
    
    antDataMem = round(layout(:).' * CONST.MAX_INT16);
    
else
    if(~CONST.isMEXPresent)
        fprintf(2, 'NO SPT TOOLBOX OR SPT TOOLBOX < VER 1.5.1.\nApplication will exit.\nCompression detected.\nInstall SPT Toolbox Ver 1.5.1\n');
        return;
    end
    % SPT Memory layout:
    % *    SRAM, 64bit compressed data
    % *    63:0
    % *    ABCD-P0
    % *    EFGH-P0
    % *    ABCD-P1
    % *    EFGH-P1
    % *    |
    % *    |
    % *    ABCD-P<nr>
    % *    EFGH-P<nr>
    %**************************************************************************

    antData = antData(:)*CONST.MAX_INT24;
        
    if strcmp(pdmaCompressionType, 'CP4D') && ~strcmp(CONST.HW, 'S32R41') 
        antDataMem = pdma_mex(complex(antData),'CP4D','COMPRESSION','FIXED_VALUE');
    elseif strcmp(pdmaCompressionType, 'CP4D') && strcmp(CONST.HW, 'S32R41') 
        antDataMem = pdma_mex(complex(antData),'CP4Q','COMPRESSION','FIXED_VALUE');
    elseif strcmp(pdmaCompressionType, 'CP4Q')
        antDataMem = pdma_mex(complex(antData),'CP4Q','COMPRESSION','FIXED_VALUE');
    elseif strcmp(pdmaCompressionType, 'CP4DFMTB')  
        antDataMem = pdma_mex(complex(antData),'CP4DFMTB','COMPRESSION','FIXED_VALUE');
    elseif strcmp(pdmaCompressionType, 'CP8FMTB')  
        antDataMem = pdma_mex(complex(antData),'CP8FMTB','COMPRESSION','FIXED_VALUE');
    elseif strcmp(pdmaCompressionType, 'CP16FMTB')  
        antDataMem = pdma_mex(complex(antData),'CP16FMTB','COMPRESSION','FIXED_VALUE');
    else
        error('PDMA Compression Type NOT supported');
    end
end
