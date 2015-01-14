#!/bin/bash

gcc -O0 -o cavdet cav_det_init.c
echo `./cavdet; ./cavdet; ./cavdet; ./cavdet; ./cavdet` | grep -oh '\w[0-9]\+\.[0-9]\+\w' | awk ' { sum += $1; print $1 } END { print "Average: " sum/NR }'
./cmp

