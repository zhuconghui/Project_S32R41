@echo off
setlocal enabledelayedexpansion enableextensions

call ..\..\..\..\..\..\..\Tools\RFE2_Config\rfeConfigGenerator\bin\rfeConfigGenerator.bat --xml rfeConfig0.xml rfeConfig1.xml

move rfeConfig.c ../../../../src
move rfeConfig.h ../../../../include
move rfeDynamicTables.c ../../../../src
move rfeDynamicTables.h ../../../../include
del rfeConfig0.bin
del rfeConfig1.bin
del rfeDynamicTables0.bin
del rfeDynamicTables1.bin
pause
