#!/bin/sh

PERF=`which perf`

if test "x$PERF" = x
then
    echo "'perf' command not found, please install the following ubuntu apt packages:"
    echo "  linux-perf-tools-common"
    echo "  linux-perf-tools-generic"
    echo "  linux-perf-tools-`uname -r`"
    exit 1
fi

echo "running cmake"
if ! cmake .
then
    echo "cmake failed"
    exit 1
fi

echo "running make"
if ! make
then
    echo "make failed"
fi

echo "running perf"
if ! perf record -o static.data ./tls_static $@
then
    echo "perf tls_static failed"
    exit 1
fi
if ! perf record -o shared.data ./tls_shared $@
then
    echo "perf tls_shared failed"
    exit 1
fi

perf report -i static.data | c++filt
perf report -i shared.data | c++filt

