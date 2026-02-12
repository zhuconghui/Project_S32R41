@echo off
set JLINK_VM_OPTIONS=
set DIR=%~dp0
"%DIR%\java" %JLINK_VM_OPTIONS% -m RfeConfigGenerator/com.nxp.rfp.saf85xx.rfe.config.RfeConfigGenerator %*
