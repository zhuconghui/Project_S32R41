Running rfeConfigGenerator.bat, generates the configuration files from the [rfeConfig.xml] available in the folder.
For custom usage see the details below.

/*********************************************************************************************************************

The rfeConfigGenerator parses the configuration files passed as arguments to the command, as follows:

"call rfeConfigGenerator\bin\rfeConfigGenerator.bat --xml rfeConfig0.xml rfeConfig1.xml"

The resulting files are:

	GENERATED FILES: - rfeConfig.h 
			 - rfeConfig.c
			 - rfeConfig0.bin (+ "rfeConfig1.bin" depending on the case)
			 - rfeDynamicTables.h
 			 - rfeDynamicTables.c
			 - rfeDynamicTables0.bin (same as for the above *.bin file)

/*********************************************************************************************************************

After generating the above files, it will move on to generate the CSV files that contain timing data of a radar cycle:

"call ..\..\RFE_abstract\RFE_driver2\CfgGen_RadarCycleSchedule\generateRadarCycleSchedule.exe rfeConfig0.bin rfeConfig1.bin"

The executable required for the above call, must be generated, otherwise a error will occur ('generateRadarCycleSchedule.exe' is not recognized as an internal or external command).
To generate the executable, please check chapter 6 from the "TEF82xx RFE Config Generator User Manual" found in this folder.

If these CSV files are not required, simply remove this call from the script.

/*********************************************************************************************************************

Apart from what is present in the above script, the generator tool has a few other commands available, detailed below:

    --dir <dir>
    -d <dir>
        Sets the output directory to the value provided for <dir>.
        The default value is the current working directory.
    
    --prefix <prefix>
    -p <prefix>
        Sets the output file prefix to <prefix>.
        The default value is "rfe".
    
    --xml <xml>
    -x <xml>
        Sets the XML file(s) to parse to <xml>.

    --blobToXml <bin>
    -b2x <bin>
        Takes a *.bin config file and converts it back to XML.
        To add a Dynamic Table *.bin file, see --dynTbl option.

    --dynTbl <bin>
    -dt <bin>
        Takes a *.bin Dynamic Table file and appends it to the XML.
        Works only when using --blobToXML.

/*********************************************************************************************************************

When any of these command line options are absent, the corresponding default value will be used (except for "--xml" parameter. At least 1 XML file must be provided).

The following examples demonstrate the use of command line options:
    
    rfeConfigGenerator --xml input.xml input1.xml      (cascaded example -> has 2 xml inputs)
        The rfeConfigGenerator will parse the [input.xml + input1.xml] files and generate the output files as mentioned at the top of the document.
	There is no limit to how many XML files can be passed to the generator.
	It is worth noting that *.bin files are generated separately for each xml, while source + header pair contains all the xml files in separated data arrays.
	The generated files will be placed in the current working directory.
    
    rfeConfigGenerator --prefix demo_ --xml demo.xml      (standalone example)
	This option will add a prefix to the name of the output files.
        The rfeConfigGenerator will parse the [demo.xml] file and generate the following files: demo_Config.h, demo_Config.c, demo_Config0.bin, demo_DynamicTables.h, demo_DynamicTables.c, and demo_rfeDynamicTables0.bin files. The generated files will be placed in the current working directory.

    rfeConfigGenerator --dir out --prefix demo_ --xml demo.xml demo1.xml      (cascaded example -> has 2 xml inputs)
        The rfeConfigGenerator will parse the [demo.xml + demo1.xml] files and generate the following files: demo_Config.h, demo_Config.c, demo_Config0.bin, demo_Config1.bin, demo_DynamicTables.h, demo_DynamicTables.c, and demo_rfeDynamicTables0.bin, demo_rfeDynamicTables1.bin files. The generated files will be placed in the [out] directory, if it exists prior to running the command.

    rfeConfigGenerator --dir out --prefix demo_ --blobToXml demo.bin --dynTbl demoDynamicTable.bin 
        The rfeConfigGenerator take the [demo.bin] file and generate the XML file based it. The file will be placed in the "out" directory (if it exists prior to running the command) and
the "demo_" prefix will be added to the file name, resulting in the file "demo_Config.xml".

