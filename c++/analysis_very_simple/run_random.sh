#!/bin/bash

file=result_random.dat
touch $file
rm $file

N=10 
iter=1000

while [ $N -le 500000  ]; do
	./analysis.x $N $iter random >> $file
	N=$(( N*2 ))
done
