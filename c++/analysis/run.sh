#!/bin/bash

#PBS -N BST
#PBS -l nodes=1:ppn=20
#PBS -l walltime=00:59:59
#PBS -q regular
#PBS -e /scratch/lbonaldo/MHPC/3.Adv/c++/analysis/data/BST.err
#PBS -o /scratch/lbonaldo/MHPC/3.Adv/c++/analysis/data/BST.out

cd $PBS_O_WORKDIR

for k in 5000 10000 15000 20000 30000 50000 100000 150000 200000; do
    for j in 50 100 200 500 1000 2000 3000; do
    touch ./data/bst${k}_${j}.txt
	for i in $(seq 1 10); do
	    ./analysis.x $k $j >> ./data/bst${k}_${j}.txt 
            sleep 3
	done
    done
done
