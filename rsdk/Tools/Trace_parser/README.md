## Trace parser features

1. The RSDK Trace Parser is a Matlab script. It reads and parses the trace binay file created by the CPU during RSDK application runtime. It gives the parsed content as output, in a cell array, and also writes it to a xlsx file located in the same path as the input binary file.

2. The way the input is interpreted (e.g. timer frequency used at runtime) and the way the output is displayed (e.g. xlsx file, plots) can be controlled using a configuration file.

3. For a Linux application that was run with both user space and kernel space trace enabled, the RSDK Trace Parser can also combine the 2 corresponding output files in a single complete trace report. Both files need to be in the same path.

4. The RSDK Trace Parser can display 2 figures:
* A timeline with all jobs (as intervals) and debug events (as individual timestamps) encountered. This figure can be adjusted to display details about any part of the execution by using the dedicated buttons implemented and the zoom and pan utilities located in the default Matlab figure toolbar.
* A statistic overview of the execution. This figure holds a piechart that represents the entire application execution and some tables which give additional information about the recorded events as a statistic.

## Trace parser usage

1. Set the wanted config in the dedicated file (<rsdk_path>\Tools\Trace_parser\platform_config.ini)

2. Open Matlab and set the working dir to <rsdk_path>\Tools\Trace_parser\src\

3. Call RsdkTraceParser('<relative_path>/<trace_file_name>', '<relative_path>/<app_header_name>')

>**Trace parser notes**
>
> In order to use this tool you need to have Matlab installed (preferably 2012a or more recent).
>
> The path to the application header file is required in order to decode application specific trace events. This header must contain these custom trace events. If there are no such events defined, this path can be omitted.
> E.g. If the events are recorded only from a RSDK driver, RsdkTraceParser('<relative_path>/<trace_file_name>', '') is a valid call.
>
> The feature of displaying figures can encounter errors for some inputs that have not yet been tested.
