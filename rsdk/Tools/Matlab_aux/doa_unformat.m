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

function [dbfTagMap, beamScans] = doa_unformat(detMem_spt, nrSteerVect, nrScans)
% Rearrange data from SPT mem layout to list of detected angles 
% detAngles - struct
%               - beamScans
%               - tagMap

% SPT mem layout:
% *   SRAM, 32 bit real. First 16 bit reserved for tagging, next 16bit for log2 magnitudes
% *   3:48             47:32            31:16            15:0
% *   P0-TAG-Beam0     P0-MAG-Beam0     P0-TAG-Beam1     P0-MAG-Beam1
% *   P0-TAG-Beam2     P0-MAG-Beam2     P0-TAG-Beam3     P0-MAG-Beam3
% *   |                |                |                |
% *   P0-TAG-Beam62    P0-MAG-Beam62    P0-TAG-Beam63    P0-MAG-Beam63    -> Beamscan 0
% *   --------------------------------------------------------------------------------
% *   P1-TAG-Beam0     P1-MAG-Beam0     P1-TAG-Beam1     P1-MAG-Beam1
% *   P1-TAG-Beam2     P1-MAG-Beam2     P1-TAG-Beam3     P1-MAG-Beam3
% *   |                |                |                |
% *   P1-TAG-Beam62    P1-MAG-Beam62    P1-TAG-Beam63    P1-MAG-Beam63    -> Beamscan 1
% *   --------------------------------------------------------------------------------
% *   |                |                |                |
% *   |                |                |                |
% *   |                |                |                |
% *   ----------------------------------------------------------------------------
% *   P<nr>-TAG-Beam0  P<nr>-MAG-Beam0  P<nr>-TAG-Beam1  P<nr>-MAG-Beam1
% *   P<nr>-TAG-Beam2  P<nr>-MAG-Beam2  P<nr>-TAG-Beam3  P<nr>-MAG-Beam3
% *   |                |                |                |   
% *   P<nr>-TAG-Beam62 P<nr>-MAG-Beam62 P<nr>-TAG-Beam63 P<nr>-MAG-Beam63 -> Beamscan<nr>
% *   --------------------------------------------------------------------------------
%     

global CONST

% Tag value for found peak
tagVal = hex2dec('FF80');

% Separate beamscans from tags
tg = detMem_spt(1:2:end);
bs = detMem_spt(2:2:end);

% Create tag map
tg = tg == tagVal;
dbfTagMap = double(reshape(tg,nrSteerVect,[]));

% Create array of beamscans
beamScans = reshape(bs,nrSteerVect,[]);
