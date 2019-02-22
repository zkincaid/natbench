#!/bin/bash

pagai="./tools/pagai/build/pagai --svcomp -i"

err=`$pagai $1 | tail -1`
if [[ $err = "RESULT: TRUE" ]]; then
    echo "safe"
elif [[ $err = "RESULT: FALSE" ]]; then
    echo "unsafe"
else
    echo "unknown"
fi
