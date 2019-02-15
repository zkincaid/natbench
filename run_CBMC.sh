#!/bin/bash

cbmc="tools/cbmc/cbmc --32 --unwind 20"
benchmark=$1
err=`$cbmc $benchmark | grep VERIFICATION`
if [[ $err = "VERIFICATION SUCCESSFUL" ]]; then
    echo "safe"
elif [[ $err = "VERIFICATION FAILED" ]]; then
    echo "unsafe"
else
    echo "unknown"
fi
