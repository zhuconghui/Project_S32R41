# RFE Radar Cycle Schedule Generator

## Build
Install MINGW. Run the "buildExecutable.bat" script, or open a terminal and run 'make' command from this directory.
To enable the detail calibration duration uncomment the -DNXP_INTERNAL_CALIBRATION_CALCULATION_MODE .
This will generate the "generateRadarCycleSchedule.exe".

## Run
Open a command prompt and run the following command:

call [path_to_exe]/generateRadarCycleSchedule.exe [path_to_bin_0]/rfeConfig0.bin [path_to_bin_1]/rfeConfig1.bin

After the above command, the 'radarCycleSchedule.csv' will be generated in the folder where the *.bin files are located.

Open 'radarCycleSchedule.csv' with text editor or import in excel:
Data->From Text/Csv