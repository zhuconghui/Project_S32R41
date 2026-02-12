# Copyright 2022 NXP
# NXP Confidential. This software is owned or controlled by NXP and may only
# be used strictly in accordance with the applicable license terms. By
# expressly accepting such terms or by downloading, installing, activating
# and/or otherwise using the software, you are agreeing that you have read,
# and that you agree to comply with and are bound by, such license terms. If
# you do not agree to be bound by the applicable license terms, then you may
# not retain, install, activate or otherwise use the software.

import csv
import pandas as pd
import sys
import os
from collections import Counter


functions = {'Spt_Setup': 0, 'Spt_Run': 0, 'Spt_Command': 0, 'Spt_Stop': 0, 
            'Dsphd_Init': 0, 'Dsphd_SendMsg': 0, 'Dsphd_CreateJobList': 0, 'Csi2_Setup': 0, 'Cte_Setup': 0,
            'RsdkDspDispatcherInit': 0, 'RsdkDspDispatcherRun': 0}
execTime = [0, 0, 0, 0, 0, 0, 0]

if(len(sys.argv) != 3):
    print("Usage: py trace_create.py [excel_file] [excel_file_DSP]")
    exit(0)
else:
    excelPath = sys.argv[1]
    excelDspPath = sys.argv[2]

ex = pd.read_excel(open(excelPath, 'rb'), sheet_name='Sheet1')  
driverInfo = ex['Info1'].tolist()
evenType = ex['Event_Type'].tolist()
time = ex['Micros'].tolist()

k = 0
for curDrv in driverInfo:
    if("PROFILE_" in curDrv) and "_END" in evenType[k]:
        if (curDrv[curDrv.index("PROFILE_") + 8 ::] == 'SPT_SETUP'):
            if functions['Spt_Setup'] < time[k]:
                functions['Spt_Setup'] = time[k]
        if (curDrv[curDrv.index("PROFILE_") + 8 ::] == 'SPT_RUN'):
            if functions['Spt_Run'] < time[k]:
                functions['Spt_Run'] = time[k]
        if (curDrv[curDrv.index("PROFILE_") + 8 ::] == 'SPT_COMMAND'):
            if functions['Spt_Command'] < time[k]:
                functions['Spt_Command'] = time[k]
        if (curDrv[curDrv.index("PROFILE_") + 8 ::] == 'SPT_STOP'):
            if functions['Spt_Stop'] < time[k]:
                functions['Spt_Stop'] = time[k]
        if (curDrv[curDrv.index("PROFILE_") + 8 ::] == 'DSPHD_INIT'):
            if functions['Dsphd_Init'] < time[k]:
                functions['Dsphd_Init'] = time[k]
        if (curDrv[curDrv.index("PROFILE_") + 8 ::] == 'DSPHD_CREATEJOBLIST'):
            if functions['Dsphd_CreateJobList'] < time[k]:
                functions['Dsphd_CreateJobList'] = time[k]
        if (curDrv[curDrv.index("PROFILE_") + 8 ::] == 'DSPHD_SENDMSG'):
            if functions['Dsphd_SendMsg'] < time[k]:
                functions['Dsphd_SendMsg'] = time[k]
        if (curDrv[curDrv.index("PROFILE_") + 8 ::] == 'CSI2_SETUP'):
            if functions['Csi2_Setup'] < time[k]:
                functions['Csi2_Setup'] = time[k]
        if (curDrv[curDrv.index("PROFILE_") + 8 ::] == 'CTE_SETUP'):
            if functions['Cte_Setup'] < time[k]:
                functions['Cte_Setup'] = time[k]
                                   
    k = k + 1

ex = pd.read_excel(open(excelDspPath, 'rb'), sheet_name='Sheet1')  
dspInfo = ex['Info2'].tolist()

functions['RsdkDspDispatcherInit'] = dspInfo[0]/320;
functions['RsdkDspDispatcherRun'] = dspInfo[1]/320;

pd.DataFrame.from_dict(data=functions, orient='index').to_csv(os.path.splitext(excelPath)[0] + ".csv", header=False)
