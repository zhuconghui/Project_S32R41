%{
    Copyright 2017,2019,2021-2022 NXP
    SPDX-License-Identifier: Cube
%}

function Out = parse_inSPTformat(varargin)
global CONST;

chPerMipi = 4;

%% parse_inSPTformat(in_SPTformat1, nrSamples, nrChirps, nrAnt)
if(nargin == 4) % 4 channels
    inSamplesArray = zeros(varargin{2}*varargin{3}*chPerMipi, 1); %allocate space for sample array
    [inSamplesArray(:,1), noSamples, noChirps, noAntennas] = varargin{1:4};
%% parse_inSPTformat(in_SPTformat1, in_SPTformat2, nrSamples, nrChirps, nrAnt)
elseif(nargin == 5) % 8 channels
    inSamplesArray = zeros(varargin{3}*varargin{4}*chPerMipi, 2); %allocate space for sample array
    [inSamplesArray(:,1), inSamplesArray(:,2), noSamples, noChirps, noAntennas] = varargin{1:5};
%% parse_inSPTformat(in_SPTformat1, in_SPTformat2, in_SPTformat3, in_SPTformat4, nrSamples, nrChirps, nrAnt)
elseif(nargin == 7) % 16 channels
    inSamplesArray = zeros(varargin{5}*varargin{6}*chPerMipi, 4); %allocate space for sample array
    [inSamplesArray(:,1), inSamplesArray(:,2), inSamplesArray(:,3), inSamplesArray(:,4), noSamples, noChirps, noAntennas] = varargin{1:7};
else
    disp('-------------------------');
    disp('WRONG NUMBER OF ARGUMENTS');
    disp('-------------------------');
    return;    
end

mipiCSIInterfaces = nargin - 3;

switch(CONST.HW)
    case{'S32R294','S32R41','SAF85XX'}
        tileFormat = 8;
    case{'S32R45'}
        tileFormat = 16;
    otherwise
        disp('INVALID PLATFORM! RERUN');
        return;
end


samplesCube = zeros( noSamples, noChirps, noAntennas);
antennaSamples = zeros(noAntennas, noSamples*noChirps);

Lines = zeros(noSamples*noChirps*chPerMipi/tileFormat, tileFormat, mipiCSIInterfaces);


for i=1:mipiCSIInterfaces
    Lines(:, :, i) = reshape(inSamplesArray(:, i).', tileFormat, []).';
end

runNumber = 0;

for m=1:noAntennas/mipiCSIInterfaces:noAntennas
    runNumber = runNumber + 1;
    for k = m:(m+chPerMipi-1)
        j = 0;
         for i=1:noAntennas/mipiCSIInterfaces:size(Lines, 1)
         antennaSamples(k, j*tileFormat+1:j*tileFormat + tileFormat) = Lines(i+(k-m), :, runNumber);    
             j = j + 1;
         end
         samplesCube(:,:,k) = reshape( antennaSamples(k,:), noSamples, []);
    end
end

Out = samplesCube;

end
