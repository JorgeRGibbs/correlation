#!/bin/bash
gcc pear.c -o corr
./corr
gnuplot commands.txt
eog salida.png &> /dev/null &
#eog x.png &> /dev/null &
#eog h.png &> /dev/null &
