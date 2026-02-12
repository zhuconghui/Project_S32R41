%{
    Copyright 2019 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function out = charStreamToInt(varargin)

if (nargin<2)
     error('Not enough input parameters');
end

if (nargin>3)
     error('Too many input parameters');
end

inStream = double(cell2mat(varargin(1)));
nrBytes = double(cell2mat(varargin(2)));

if nrBytes>4
    warning('Function does not ensure bit exactness for 64 bit integers!')
end

if (nargin == 3)
    unsigned = cell2mat(varargin(3));
else
    unsigned = 'i';
end

msb = downsample(inStream,nrBytes,0);

if strcmp(unsigned,'u')
    isNegative = 0;
else
    isNegative = (bitget(msb,8));
    msb = bitset(msb,8,0);
end

tmp = msb;
for i = 1:nrBytes-1
    lsb = downsample(inStream,nrBytes,i);
    tmp = tmp * 2^8 + lsb;
end

tmp = tmp + (-2^(nrBytes*8-1))*isNegative;

out = double(tmp);
