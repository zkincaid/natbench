#!/bin/bash

sea="tools/seahorn/build/run/bin/sea_svcomp"
benchmark=$1
OUT=$(mktemp /tmp/output.XXXXXXX.c)
gcc -E $1 > $OUT
err=`$sea $OUT | grep "sat"`
rm $OUT
if [[ $err = "unsat" ]]; then
    echo "safe"
elif [[ $err = "sat" ]]; then
    echo "unsafe"
else
    echo "unknown"
fi
