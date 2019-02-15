#!/bin/bash

cra="tools/duet/duet.native -cra -cra-split-loops"
benchmark=$1

err=`$cra $benchmark | grep "errors"`
if [[ $err = "0 errors total" ]]; then
    echo "safe"
else
    echo "unknown"
fi
