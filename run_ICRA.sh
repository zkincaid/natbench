#!/bin/bash

icra="tools/icra/icra -cra-split-loops"
benchmark=$1

fail=`$icra $benchmark | grep FAILED`
if [[ $fail = "" ]]; then
    echo "safe"
else
    echo "unknown"
fi
