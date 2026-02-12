@echo off
setlocal enabledelayedexpansion enableextensions

call rfeConfigGenerator\bin\rfeConfigGenerator.bat --xml rfeConfig.xml rfeConfig.xml

call ..\..\RFE_abstract\RFE_driver2\CfgGen_RadarCycleSchedule\generateRadarCycleSchedule.exe rfeConfig0.bin rfeConfig1.bin

pause
