@echo off
setlocal enabledelayedexpansion enableextensions

call ..\..\..\..\..\..\..\Tools\RFE2_Config\rfeConfigGenerator\bin\rfeConfigGenerator.bat --xml rfeConfig0.xml rfeConfig1.xml

del rfeConfig.c
del rfeConfig.h
del rfeDynamicTables.c
del rfeDynamicTables.h

pause
