#!/bin/bash

gcc -g -O0 -o cavdet cav_det.c
echo `./cavdet; ./cavdet; ./cavdet` | grep -oh '\w[0-9]\+\.[0-9]\+\w' | awk ' { sum += $1; print $1 } END { print "Average: " sum/NR }'
./cmp
