## Building the trace library

1. Set the environment variables
    ```bash
    # E.g. To build the trace library for Linux apps running on RRM
    $ export PLATFORM=S32R45
    $ export TARGET=a53
    $ export COMPILER=gcc
    $ export OSENV=linux

    ```

2. Compile
    ```bash
    $ cd <rsdk>/Tools/Trace/build
    $ make clean && make all

    ```

>**Trace library notes**
>
> This library can be used to log events from a standalone application or from the user space part of a Linux application.
>
> Some rsdk drivers and applications are instrumented to allow tracing.
>
> The trace can be enabled/disabled by defining/removing TRACE_ENABLE. This macro must be set by all the components that log events.
> E.g. Defining TRACE_ENABLE only at the application level will allow only application spcific events to be recorded. To also register events from a driver (e.g. SPT), TRACE_ENABLE must also be defined when building the corresponding driver.


## Building the trace module

1. Set the cross-compilation environment
    ```bash
    $ export KERNEL_DIR=<absolute path to kernel directory>
    $ export CROSS_COMPILE=<absolute path to required compiler>

2. Set other environment variables
    ```bash
    $ export PLATFORM=S32R45
    $ export TARGET=a53
    $ export COMPILER=gcc
    $ export OSENV=linux

    ```

3. Compile
    ```bash
    $ cd <rsdk>/Tools/Trace/build/linux_kernel
    $ make clean_module && make module

    ```

>**Trace module notes**
>
> The trace module can be used to log events from Linux drivers located in kernel space, while an application is running.
>
> The rsdk Linux drivers (the kernel space part) are not yet instrumented to allow logging kernel events.
