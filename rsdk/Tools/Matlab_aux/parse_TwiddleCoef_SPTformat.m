%{
    Copyright 2017,2020-2022 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only
    be used strictly in accordance with the applicable license terms. By
    expressly accepting such terms or by downloading, installing, activating
    and/or otherwise using the software, you are agreeing that you have read,
    and that you agree to comply with and are bound by, such license terms. If
    you do not agree to be bound by the applicable license terms, then you may
    not retain, install, activate or otherwise use the software.
%}

function Out = parse_TwiddleCoef_SPTformat(twiddle_coef)
global CONST;
reord_twiddle_coef = twiddle_coef;
reord_twiddle_coef(1:2:end) = twiddle_coef(2:2:end);
reord_twiddle_coef(2:2:end) = twiddle_coef(1:2:end);

outAux = reord_twiddle_coef(1:2:end) + 1i*reord_twiddle_coef(2:2:end);
switch(CONST.HW)
    case{'S32R294','S32R41','SAF85XX'}
       Out = outAux(1:8:end); 
    case('S32R45')
       Out = outAux(1:16:end); 
    otherwise
        disp('WRONG HARDWARE. APPLICATION WILL EXIT');
        return;
end
end
