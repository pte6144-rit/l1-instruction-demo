#!/bin/bash

taskset -c 1 ./busy &
taskset -c 5 ./spy
head -n 100 dat.txt > short_dat.txt
./parse_lats.py short_dat.txt
