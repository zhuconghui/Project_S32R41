%{
    Copyright 2017-2019,2021 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function beamScansMem = doa_beamform_out_format(beamScans, detAngles, nrAngBins, nrScans)
% Rearrange data from radar cube to SPT memory layout
% Input: 
%        - beamScans - [nrAngBins,nrScans] - spt_log2 format
%        - detAngles - struct array of detects:
%               - beamScan - index
%               - angleBin - index
%               - magVal   - value
%        - pdmaCompressionType - 'NO' or 'CP4D'
%        - nrScans
%        - nrAngBins
% Output:
%        - antDataMem - array of int16

% SPT mem layout:
% *                 SRAM, 32 bit real. First 16 bit reserved for tagging, next 16bit for log2 magnitudes
% *                 63:48           47:32           31:16           15:0
% *                 P0-TAG-Beam0    P0-MAG-Beam0    P0-TAG-Beam1    P0-MAG-Beam1
% *                 P0-TAG-Beam2    P0-MAG-Beam2    P0-TAG-Beam3    P0-MAG-Beam3
% *                 |               |               |               |
% *                 P0-TAG-Beam62   P0-MAG-Beam62   P0-TAG-Beam63   P0-MAG-Beam63 -> Beamscan 0
% *                 ----------------------------------------------------------------------------
% *                 P1-TAG-Beam0    P1-MAG-Beam0    P1-TAG-Beam1    P1-MAG-Beam1
% *                 P1-TAG-Beam2    P1-MAG-Beam2    P1-TAG-Beam3    P1-MAG-Beam3
% *                 |               |               |               |
% *                 P1-TAG-Beam62   P1-MAG-Beam62   P1-TAG-Beam63   P1-MAG-Beam63 -> Beamscan 1
% *                 ----------------------------------------------------------------------------
% *                 |               |               |               |
% *                 |               |               |               |
% *                 |               |               |               |
% *                 ----------------------------------------------------------------------------
% *                 P127-TAG-Beam0  P127-MAG-Beam0  P127-TAG-Beam1  P127-MAG-Beam1
% *                 P127-TAG-Beam2  P127-MAG-Beam2  P127-TAG-Beam3  P127-MAG-Beam3
% *                 |               |               |               |   
% *                 P127-TAG-Beam62 P127-MAG-Beam62 P127-TAG-Beam63 P127-MAG-Beam63 -> Beamscan 127
% *                 ----------------------------------------------------------------------------

global CONST

% Create angle peak tab bitmap
tagValue = hex2dec('FF80');

tagBitmap = zeros(nrAngBins, nrScans);
nrDetAng = length(detAngles);
for i = 1:nrDetAng
    tagBitmap(detAngles(i).angleBin,detAngles(i).beamScan) = tagValue;
end
tagRow  = tagBitmap(:).';
beamRow = beamScans(:).';

layout = [ tagRow
           beamRow];

beamScansMem = layout(:);
