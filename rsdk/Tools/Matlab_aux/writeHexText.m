%{
    Copyright 2019,2021 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function writeHexText(fid, stream)

stream = stream(:);
nrVal = size(stream,1);
valPerLine = 16;
nrLines = round(nrVal/valPerLine);

hexStream = dec2hex(stream);

zX = '0x';
cM = ',';
zX = repmat(zX,nrVal,1);
cM = repmat(cM,nrVal,1);

strToWr = [zX, hexStream, cM];
strToWr = strToWr.';
strToWr(end,end) = ' ';

for line = 0:nrLines-2
    rng = line*valPerLine+1:(line+1)*valPerLine;
    fprintf(fid,strToWr(:,rng));
    fprintf(fid,'\n');
end
if(nrLines>1)
    rng = (line+1)*valPerLine+1:nrVal;
else
    rng = 1:nrVal;
end
fprintf(fid,strToWr(:,rng));
fprintf(fid,'\n');
