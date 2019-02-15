#!/bin/bash

ultimate="./tools/UAutomizer-linux/Ultimate.py --spec reach.prp --architecture 32bit simple --file "
OUT=$(mktemp /tmp/output.XXXXXXX.c)
gcc -E $1 > $OUT
err=`$ultimate $OUT | tail -1`
rm $OUT
if [[ $err = "TRUE" ]]; then
    echo "safe"
elif [[ $err = "FALSE" ]]; then
    echo "unsafe"
else
    echo "unknown"
fi
