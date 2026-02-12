# Copyright 2022 NXP
# NXP Confidential and Proprietary. This software is owned or controlled by NXP and
# may only be used strictly in accordance with the applicable license terms.  By
# expressly accepting such terms or by downloading, installing, activating and/or
# otherwise using the software, you are agreeing that you have read, and that you
# agree to comply with and are bound by, such license terms.  If you do not agree to
# be bound by the applicable license terms, then you may not retain, install, activate or
# otherwise use the software.

import pandas as pd
import sys
import os

execTime = []
bbe32kernel = []
timePerChirp = []
samplesPerChirp = []
chirpsPerFrame = []
kernelNames = [];
SRAMOnly = 0
k = 0
j = 0
firstTime = 0
dspIndex = 0

def ignoreTest(currentLine):
    if(SRAMOnly == 1):
        if(int(currentLine.split()[6]) == 1):
            return 1
        else:
            return 0
    else:
        return 0

def returnSpaceAfterIndex(nameIndex, spaces):
    foundSpace = 0
    for i in spaces:
        if i > nameIndex:
            foundSpace = i
            break
    return foundSpace
    
def returnSamplesAndChirps(name):
    smpIndex = name.find("smp")
    chrpIndex = name.find("crp")
    chrpFactor = 1;
    if(name.find("TxTdMimo") != -1):
        mimoIndex = name.find("TxTdMimo")
        startMimoIndex = mimoIndex - 1
        while(name[startMimoIndex].isnumeric()):
            startMimoIndex = startMimoIndex - 1
        chrpFactor = name[startMimoIndex+1:mimoIndex]
    startOfSmpIndex = smpIndex - 1
    while(name[startOfSmpIndex].isnumeric()):
        startOfSmpIndex = startOfSmpIndex - 1
    samples = int(name[startOfSmpIndex+1:smpIndex])
    chirps = int(name[smpIndex+3:chrpIndex]) * int(chrpFactor)
    return [samples, chirps]
    
def pandasInsert(df, row):
    insert_loc = df.index.max()

    if pd.isna(insert_loc):
        df.loc[0] = row
    else:
        df.loc[insert_loc + 1] = row

if(len(sys.argv) != 4):
    print("Usage: py trace_create.py [excel_file] [ini file] [SRAMOnly]")
    exit(0)
else:
    excelPath = sys.argv[1]
    iniFilePath = sys.argv[2]
    SRAMOnly = int(sys.argv[3])

ex = pd.read_excel(open(excelPath, 'rb'), sheet_name='Sheet1')  
driverInfo = ex['Info1'].tolist()
time = ex['Micros'].tolist()

for i in driverInfo:
    if (i == 'RSDK_TRACE_DBG_SPT_KERNEL_END'):
        execTime.append(time[k])
    k = k + 1

print(len(execTime))
f = open(iniFilePath, 'r');
iniLines = f.read().splitlines()
f.close()

for i in range(len(iniLines)):
        currentLine = iniLines[i]
        nameIndex = currentLine.find("Rsdk")
        spaces = [k for k, ltr in enumerate(currentLine) if ltr == ' ']
        if (nameIndex != -1 and currentLine[0] != "#" and currentLine.find("RsdkBbe") == -1):
            if(ignoreTest(currentLine) == 1):
                #print(currentLine)
                continue
            else:
                name = currentLine[nameIndex:returnSpaceAfterIndex(nameIndex, spaces)]
                kernelNames.append(name)
                if (name.find("smp") != -1 and name.find("crp") != -1):
                    [samples, chirps] = returnSamplesAndChirps(name)
                    samplesPerChirp.append(samples)
                    chirpsPerFrame.append(chirps)
                else:
                    samplesPerChirp.append("-")
                    chirpsPerFrame.append("-")
                if(currentLine.find("Range") != -1):
                    timePerChirp.append(float(float(execTime[j])/chirps))
                else:
                    timePerChirp.append("-")
                if(currentLine.find("RsdkSptDsp") != -1 or currentLine.find("Cfar") != -1):
                    if (firstTime == 0):
                        dspIndex = j
                        firstTime = 1
                    if(currentLine.find("RsdkSptDspExampleDirectBlocking") != -1):
                        bbe32kernel.append(iniLines[i+2].split()[0])
                    elif (currentLine.find("RsdkSptDspExampleIndirectBlocking") != -1):
                        bbe32kernel.append(iniLines[i+2].split()[0])
                        samplesPerChirp[j] = iniLines[i+4].split()[0]
                        chirpsPerFrame[j] = iniLines[i+4].split()[1]
                        timePerChirp[j] = float(float(execTime[j])/float(samplesPerChirp[j]))
                    elif (currentLine.find("RsdkSptOsCfar") != -1):
                        bbe32kernel.append(iniLines[i+9].split()[0])
                        chirpsPerFrame[j] = iniLines[i+11].split()[0]
                        samplesPerChirp[j] = ((int(iniLines[i+7].split()[1]) * 8192) / int(chirpsPerFrame[j]) )
                        timePerChirp[j] = float(float(execTime[j])/float(samplesPerChirp[j]))
                else:
                    bbe32kernel.append("-")
                j = j + 1

df = pd.DataFrame(list(zip(kernelNames, execTime, timePerChirp, bbe32kernel, samplesPerChirp, chirpsPerFrame)), columns=['SPT Kernel Name', 'Microseconds', 'Microseconds/Chirp', 'DSP Kernel', 'Samples per Chirp', 'Chirps per Frame'])
df.loc[dspIndex-0.5] = 'SPT Kernel Name', 'Microseconds', 'Microseconds/Range Bin', 'DSP Kernel', 'Range Bins', 'Chirps per Frame'
df = df.sort_index().reset_index(drop=True)
df = df.drop_duplicates(subset=df.columns.difference(['Microseconds', 'Microseconds/Chirp']))
csvFile = df.to_html(os.path.splitext(excelPath)[0] + ".html", index=False, justify='center')
