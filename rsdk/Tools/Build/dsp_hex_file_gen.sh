#!/usr/bin/env bash

# Copyright 2019-2024 NXP
# NXP Confidential and Proprietary. This software is owned or controlled by NXP and
# may only be used strictly in accordance with the applicable license terms.  By
# expressly accepting such terms or by downloading, installing, activating and/or
# otherwise using the software, you are agreeing that you have read, and that you
# agree to comply with and are bound by, such license terms.  If you do not agree to
# be bound by the applicable license terms, then you may not retain, install, activate or
# otherwise use the software.

ELF_NAME=$1
STB_DIR=$2
OUT_NAME=$3
PLATFORM=$4
OUT_DIR=$5
CUR_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

SROM0_BASE_ADDR=0x0
DRAM0_BASE_ADDR=0x0
DRAM1_BASE_ADDR=0x0
IRAM0_BASE_ADDR=0x0
SRAM_BASE_ADDR=0x0

DRAM_SIZE=0x0
IRAM_SIZE=0x0
SROM_SIZE=0x0
SRAM_SIZE=0x0

if [ -z "${ELF_NAME}" ] || [ -z "${STB_DIR}" ] || [ -z "${OUT_NAME}" ] || [ -z "${PLATFORM}" ]; then
    echo "Error: too few arguments."
    echo "Usage: dsp_hex_file_gen.sh ELF_NAME STB_DIR OUT_NAME PLATFORM [OUT_DIR]"
    exit 1
fi

if [ -z "${OUT_DIR}" ] ; then
    OUT_DIR=.
fi

if [ $PLATFORM == "S32R45" ]; then
	SROM0_BASE_ADDR=0x0
	DRAM0_BASE_ADDR=0x24160000
	DRAM1_BASE_ADDR=0x24140000
	IRAM0_BASE_ADDR=0x24180000
	SRAM_BASE_ADDR=0x34000000

	DRAM_SIZE=0x20000
	IRAM_SIZE=0x20000
	SROM_SIZE=0x1000000
	SRAM_SIZE=0x800000
elif [ $PLATFORM == "S32R41" ]; then
	SROM0_BASE_ADDR=0x0
	DRAM0_BASE_ADDR=0x24100000
	DRAM1_BASE_ADDR=0x24120000
	IRAM0_BASE_ADDR=0x24140000
	SRAM_BASE_ADDR=0x33c00000

	DRAM_SIZE=0x20000
	IRAM_SIZE=0x40000
	SROM_SIZE=0x1000000
	SRAM_SIZE=0x800000
elif [ $PLATFORM == "SAF85XX" ]; then
	SROM0_BASE_ADDR=0x0
	DRAM0_BASE_ADDR=0x24100000
	DRAM1_BASE_ADDR=0x24120000
	IRAM0_BASE_ADDR=0x24140000
	SRAM_BASE_ADDR=0x33c00000

	DRAM_SIZE=0x20000
	IRAM_SIZE=0x40000
	SROM_SIZE=0x1000000
	SRAM_SIZE=0x800000
elif [ $PLATFORM == "SAF86XX" ]; then
	SROM0_BASE_ADDR=0x0
	DRAM0_BASE_ADDR=0x24100000
	DRAM1_BASE_ADDR=0x24110000
	IRAM0_BASE_ADDR=0x24120000
	SRAM_BASE_ADDR=0x33E80000

	DRAM_SIZE=0x10000
	IRAM_SIZE=0x10000
	SROM_SIZE=0x1000000
	SRAM_SIZE=0x200000
else
	echo "Wrong platform specified. Valid platforms: S32R45/S32R41/SAF85XX/SAF86XX"
	exit 1
fi

OUTPUT_FILE_NAME=${OUT_DIR}/${OUT_NAME}

ELF_EXE_SPLIT=(${ELF_NAME//// })
ELF_EXE=${ELF_EXE_SPLIT[-1]}

${STB_DIR}/xt-dumpelf.exe --base=${SRAM_BASE_ADDR}  --offset=${SRAM_BASE_ADDR}  --xtsc --width=128 --linesize=64 --size=${SRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_sram.data
${STB_DIR}/xt-dumpelf.exe --base=${SROM0_BASE_ADDR} --offset=${SROM0_BASE_ADDR} --xtsc --width=128 --linesize=64 --size=${SROM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_srom.data
if [ $PLATFORM == "S32R45" ]; then
	${STB_DIR}/xt-dumpelf.exe --base=${IRAM0_BASE_ADDR} --offset=${IRAM0_BASE_ADDR} --xtsc --width=128 				  --size=${IRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_iram0.data
	${STB_DIR}/xt-dumpelf.exe --base=${DRAM0_BASE_ADDR} --offset=${DRAM0_BASE_ADDR} --xtsc --width=512 				  --size=${DRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_dram0.data
	${STB_DIR}/xt-dumpelf.exe --base=${DRAM1_BASE_ADDR} --offset=${DRAM1_BASE_ADDR} --xtsc --width=512 				  --size=${DRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_dram1.data
elif [ $PLATFORM == "S32R41" ]; then
	${STB_DIR}/xt-dumpelf.exe --base=${IRAM0_BASE_ADDR} --offset=${IRAM0_BASE_ADDR} --xtsc --width=128 --linesize=128 --size=${IRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_iram0.data
	${STB_DIR}/xt-dumpelf.exe --base=${DRAM0_BASE_ADDR} --offset=${DRAM0_BASE_ADDR} --xtsc --width=512 --linesize=128 --size=${DRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_dram0.data
	${STB_DIR}/xt-dumpelf.exe --base=${DRAM1_BASE_ADDR} --offset=${DRAM1_BASE_ADDR} --xtsc --width=512 --linesize=128 --size=${DRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_dram1.data
elif [ $PLATFORM == "SAF85XX" ]; then
	${STB_DIR}/xt-dumpelf.exe --base=${IRAM0_BASE_ADDR} --offset=${IRAM0_BASE_ADDR} --xtsc --width=128 --linesize=128 --size=${IRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_iram0.data
	${STB_DIR}/xt-dumpelf.exe --base=${DRAM0_BASE_ADDR} --offset=${DRAM0_BASE_ADDR} --xtsc --width=512 --linesize=128 --size=${DRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_dram0.data
	${STB_DIR}/xt-dumpelf.exe --base=${DRAM1_BASE_ADDR} --offset=${DRAM1_BASE_ADDR} --xtsc --width=512 --linesize=128 --size=${DRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_dram1.data
elif [ $PLATFORM == "SAF86XX" ]; then
	${STB_DIR}/xt-dumpelf.exe --base=${IRAM0_BASE_ADDR} --offset=${IRAM0_BASE_ADDR} --xtsc --width=128 --linesize=128 --size=${IRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_iram0.data
	${STB_DIR}/xt-dumpelf.exe --base=${DRAM0_BASE_ADDR} --offset=${DRAM0_BASE_ADDR} --xtsc --width=512 --linesize=128 --size=${DRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_dram0.data
	${STB_DIR}/xt-dumpelf.exe --base=${DRAM1_BASE_ADDR} --offset=${DRAM1_BASE_ADDR} --xtsc --width=512 --linesize=128 --size=${DRAM_SIZE} ${ELF_NAME} > bbe32_${OUT_NAME}_${ELF_EXE}_dram1.data
else
	echo "Wrong platform specified. Valid platforms: S32R45/S32R41/SAF85XX"
	exit 1
fi


cat bbe32_${OUT_NAME}_${ELF_EXE}_*.data > bbe32_${OUT_NAME}_${ELF_EXE}_data.data

{
  echo ' /*****************************************************************************'
  echo ' *'
  echo ' * Copyright 2019-2024 NXP'
  echo ' * NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in accordance with the'
  echo ' * applicable license terms.  By expressly accepting such terms or by downloading, installing, activating and/or otherwise'
  echo ' * using the software, you are agreeing that you have read, and that you agree to comply with and are bound by, such'
  echo ' * license terms.  If you do not agree to be bound by the applicable license terms, then you may not retain, install,'
  echo ' * activate or otherwise use the software.'
  echo ' *'
  echo ' **************************************************************************************************/'
  echo ''
  echo '#include <stdint.h>'
  echo ''
  echo '#ifdef __cplusplus'
  echo 'extern "C" {'
  echo '#endif'
  echo ''
  echo '/* This is the DSP IRAM boot image, as specified in \"\Apps\DSP_Dispatcher_example\src\linker\<platform>\" BBE32 linker support package.*/'
  echo ''

#postprocess vps.data to produce plain text c-style data arrays intended to be included directly in the main CPU's source code:
  idx=0
  segAddresses=''
  while read curentLine; do
    if [[ $curentLine = '@'* ]]; then
  
  	  if [ -z ${IS_NOT_FIRST+x} ]; then
  	    IS_NOT_FIRST=false
  	  else 
  	    echo '};'
  	    echo '' 
  	  fi
      
#  	  echo "uint8_t dsp_img_segment_${curentLine:1:10}[] __attribute__((section("\".dsp_img_segment_${curentLine:1:10}\""))) = {"
	  segAddresses="${segAddresses}${curentLine:1:10}, "
  	  echo "uint8_t dsp_img_segment_$idx[] = {"
	  ((idx++));
    else
  	  CleanedCurentLine=${curentLine//[$'\r\n']}
  	  echo ${CleanedCurentLine// /,},
    fi
  done <bbe32_${OUT_NAME}_${ELF_EXE}_data.data

  echo '};'
  echo ''
  
  echo "#define RSDK_NUM_DSP_IMG_SEGMENTS ($idx)"
  echo ''

  echo "uintptr_t dspImgSegmentRunaddr[RSDK_NUM_DSP_IMG_SEGMENTS] = {$segAddresses};"
  echo ''

  ((idx--))
  echo "uint32_t dspImgSegmentSizes[RSDK_NUM_DSP_IMG_SEGMENTS] = {"
  for i in $(seq 0 $idx); do 
  echo "    sizeof(dsp_img_segment_$i)",
  done
  echo "};"
  echo ''

  echo "uint8_t* dspImgSegmentLoadAddr[RSDK_NUM_DSP_IMG_SEGMENTS] = {"
  for i in $(seq 0 $idx); do 
  echo "    dsp_img_segment_$i",
  done
  echo "};"
  echo ''

  echo '#ifdef __cplusplus'
  echo '}'
  echo '#endif'
  
} >${OUTPUT_FILE_NAME}

echo created file: ${OUTPUT_FILE_NAME}

#remove temp files:
rm -f bbe32_${OUT_NAME}_${ELF_EXE}_*.data
