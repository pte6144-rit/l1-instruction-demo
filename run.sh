#!/bin/bash

killall busy 2>/dev/null

taskset -c 23 ./busy 1>/dev/null &
sleep 1
taskset -c 11 ./spy
tail -n 199 dat.txt > short_udat.txt
