#!/bin/bash

file=result_sorted.dat
touch $file
rm $file

N=10 
iter=1000

while [ $N -le 5000  ]; do
	./analysis.x $N $iter sorted >> $file
	N=$(( N*2 ))
done
