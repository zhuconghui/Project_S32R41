# Copyright 2024 NXP
# NXP Confidential and Proprietary. This software is owned or controlled by NXP and
# may only be used strictly in accordance with the applicable license terms.  By
# expressly accepting such terms or by downloading, installing, activating and/or
# otherwise using the software, you are agreeing that you have read, and that you
# agree to comply with and are bound by, such license terms.  If you do not agree to
# be bound by the applicable license terms, then you may not retain, install, activate or
# otherwise use the software.
#
#   Script to install the necessary files of the RadarSDK to S32DS IDE.
#

import os
import sys
import glob
import shutil

if(len(sys.argv) < 3):
    print("Usage : >python RadarSDK_install_to_DS.py <S32DS_path> <Radar_SDK_root>\n\
    where : S32DS_path     - the path to S32DS root path\n\
            Radar_SDK_root - path to the root of the installed RadarSDK package\n\
          the paths can be absolute or relative.")
    exit(1)

s32dsPath = sys.argv[1]
rsdkPath = sys.argv[2]

rsdkFiles = [
    ["Csi2", ["CDD_Csi2.c", "Csi2_Irq.c", "Csi2_Irq_Handlers.c"], ["CDD_Csi2.h", "Csi2_Cfg.h", "Csi2_Defs.h", "Csi2_Irq.h", "Csi2_Irq_Types.h", "Csi2_MemMap.h", "Csi2_Types.h", "SchM_Csi2.h"]],
    ["Spt", ["CDD_Spt.c", "Spt_Hw_Check.c", "Spt_Hw_Ctrl.c", "Spt_Internals.c", "Spt_Irq.c", "Spt_Irq_Config.c", "Spt_Seq_Ctrl.c"], ["CDD_Spt.h", "Spt_Cfg.h", "Spt_Hw_Check.h", "Spt_Hw_Ctrl.h", "Spt_Hw_Defs.h", "Spt_Internals.h", "Spt_Internals_Types.h", "Spt_Irq.h", "Spt_Irq_Config.h", "Spt_Seq_Ctrl.h" ,"Spt_Types.h", "SchM_Spt.h", "Spt_MemMap.h"]],
    ["Dsp", ["CDD_Dsphd.c"], ["CDD_Dsphd.h", "Dsphd_Cfg.h", "Dsphd_cmd_client.h", "Dsphd_Types.h", "SchM_Dsphd.h", "Dsphd_MemMap.h"]],
    ["Cte", ["CDD_Cte.c", "Cte_Irq.c"], ["CDD_Cte.h", "Cte_Cfg.h", "Cte_Irq.h", "Cte_MemMap.h", "Cte_Specific.h", "Cte_Types.h", "SchM_Cte.h"]],
]
print("Installing RadarSDK files from\n", rsdkPath, "\nfolder, to the S32DS install path :\n",  s32dsPath)

# check the specified S32DS path
eclipsePath = s32dsPath + "/eclipse"
if(os.path.exists(eclipsePath) == False):
    print("Wrong S32DS install path :", eclipsePath, " path not found")
    exit(2)

mcuPath = eclipsePath + "/mcu_data"
if(os.path.exists(mcuPath) == False):
    print("Wrong S32DS install path or wrong installation :", mcuPath, " path not found")
    exit(2)

swPath = s32dsPath + "/S32DS/software"
if(os.path.exists(swPath) == False):
    print("Wrong S32DS install path or wrong installation :", swPath, " path not found")
    exit(2)

# processing the RSDK files
xmlFiles = glob.glob(rsdkPath + "/autosar_plugins/*/S32DS/sdk_components_rsdk.xml")
for f in xmlFiles:
    fParts = os.path.split(f)
    # checking the components xml file
    fIn = open(f, "rt")
    sdkParams = ["", "", ""]
    inComment = False
    for line in fIn.readlines():
        if(inComment):
            if(line.find("-->") != -1):
                break
            lParts = line.strip().split(":")
            if(lParts[0].strip() == "Processor"):
                sdkParams[0] = lParts[1].strip().split(" ")
            elif(lParts[0].strip() == "Software Platform"):
                sdkParams[1] = lParts[1].strip()
            elif(lParts[0].strip() == "Tresos pair"):
                sdkParams[2] = lParts[1].strip()
        else:
            if(line.find("<!-- ") != -1):
                inComment = True
    fIn.close()
    if((sdkParams[0] == "") or (sdkParams[1] == "") or (sdkParams[2] == "")):
        print("Incorrect version for file :", f)
        exit(4)

    # copy S32DS manifest files and the other necessary files
    for p in sdkParams[0]:
        outPath = mcuPath + "/processors/" + p + "/" + sdkParams[1] + "/sdk/"
        inPath = f
        print(" - Copy file      : ", os.path.split(inPath)[1], " to : ", outPath)
        shutil.copy(inPath, outPath)
        stage2Files = glob.glob(fParts[0] + "/*")
        for f2 in stage2Files:
            if(f2 != f):
                fName = os.path.split(f2)[1]
                if(os.path.isdir(f2)):
                    outPath = mcuPath + "/components/" + sdkParams[1] + "/"
                    print(" - Copy directory : ", fName, " to : ", outPath)
                    shutil.copytree(f2, outPath + "/" + fName, dirs_exist_ok=True)

                    stage3Files = glob.glob(os.path.split(f2)[0] + "/../EBT/eclipse/plugins/" + fName + "_" + sdkParams[2])
                    for f3 in stage3Files:
                        if(os.path.isdir(f3)):
                            outPath =  swPath + "/" + sdkParams[1] + "/RSDK/" + os.path.split(f3)[1]
                            print(" - Copy plugin    : ", fName, " to : ", outPath)
                            shutil.copytree(f3, outPath, dirs_exist_ok=True)
                            for rf in rsdkFiles:
                                if(rf[0].lower() in fName.lower()):
                                    outPath1 = outPath + "/src"
                                    if(os.path.exists(outPath1) == False):
                                        os.mkdir(outPath1)
                                    for rf1 in rf[1]:
                                        rfc = glob.glob(rsdkPath + "/" + rf[0].upper() + "/**/*/" + rf1, recursive=True)
                                        print(" - Copy src file  : ", rfc[0], " to : ", outPath1)
                                        shutil.copy(rfc[0], outPath1)
                                    outPath1 = outPath + "/include"
                                    if(os.path.exists(outPath1) == False):
                                        os.mkdir(outPath1)
                                    for rf1 in rf[2]:
                                        rfc = glob.glob(rsdkPath + "/" + rf[0].upper() + "/**/*/" + rf1, recursive=True)
                                        print(" - Copy inc file  : ", rfc[0], " to : ", outPath1)
                                        shutil.copy(rfc[0], outPath1)
                                    break
                else:
                    if(fName[fName.find(".")+1:] == "xml"):
                        outPath = swPath + "/" + sdkParams[1] + "/"
                        print(" - Copy file      : ", fName, " to : ", outPath)
                        shutil.copy(f2, outPath)

