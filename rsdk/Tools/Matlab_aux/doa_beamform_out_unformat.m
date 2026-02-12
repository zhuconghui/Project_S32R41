%{
    Copyright 2017,2021 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function antData = doa_beamform_in_unformat(antDataMem, pdmaCompressionType, nrPeaks, nrAnt)
% Rearrange data from radar cube to SPT memory layout
% Input: 
%        - antDataMem - array of int16 
%        - pdmaCompressionType - 'NO' or 'CP4D'
%        - nrPeaks
%        - nrAnt
% Output:
%        - antData - [nrAnt, nrPeaks]
global CONST

if strcmp(pdmaCompressionType, 'NO')
    % SPT mem layout:
    % *                 SRAM, 32bit complex(16b_Im + 16b_Re)
    % *                 63:48         47:32           31:16           15:0
    % *                 P0_Im-A       P0_Re-A         P0_Im-B         P0_Re-B
    % *                 P0_Im-C       P0_Re-C         P0_Im-D         P0_Re-D
    % *                 P1_Im-A       P1_Re-A         P1_Im-B         P1_Re-B
    % *                 P1_Im-C       P1_Re-C         P1_Im-D         P1_Re-D
    % *                 |             |               |               |
    % *                 |             |               |               |
    % *                 |             |               |               |
    % *                 P127_Im-A     P127_Re-A       P127_Im-B       P127_Re-B
    % *                 P127_Im-C     P127_Re-C       P127_Im-D       P127_Re-D
    
    dataIm = downsample(antDataMem,2,0);
    dataRe = downsample(antDataMem,2,1);
    
    data = (dataRe + 1i*dataIm)/CONST.MAX_INT16;
        
    antData = reshape(data,nrAnt,nrPeaks);
    
elseif strcmp(pdmaCompressionType, 'CP4D')
% SPT mem layout:
% *                 INPUT Memory layout:
% *                 SRAM, 64bit compressed data
% *                 63:0
% *                 ABCD-P0
% *                 ABCD-P1
% *                 |
% *                 |
% *                 |
% *                 ABCD-P127

%
% ------------------------------------PLEASE FILL compressed format
%
%




else
    error('PDMA Compression Type NOT supported');
end
