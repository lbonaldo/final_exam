#!/bin/bash

for j in 50 100 200 500 1000 2000 3000 50000; do

    for k in 5000 10000 15000 20000 30000 50000 100000 150000 200000; do

 	touch ./python/ID_unbal_${k}_${j}.txt
	touch ./python/ID_bal_${k}_${j}.txt
	touch ./python/ID_std_${k}_${j}.txt
	
	touch ./python/DD_unbal_${k}_${j}.txt
	touch ./python/DD_bal_${k}_${j}.txt
	touch ./python/DD_std_${k}_${j}.txt
	
	touch ./python/SD_unbal_${k}_${j}.txt
	touch ./python/SD_bal_${k}_${j}.txt
	touch ./python/SD_std_${k}_${j}.txt

	touch ./python/SS_unbal_${k}_${j}.txt
	touch ./python/SS_bal_${k}_${j}.txt
	touch ./python/SS_std_${k}_${j}.txt
	
	awk ' /map<int,double>/ {getline; print $8, $5}' ./bst${k}_${j}.txt >> ./python/ID_unbal_${k}_${j}.txt

	awk ' /map<int,double>/ {getline; getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/ID_bal_${k}_${j}.txt

	awk ' /map<int,double>/ {getline; getline; getline; print $7, $4 }' ./bst${k}_${j}.txt >> ./python/ID_std_${k}_${j}.txt

	awk ' /map<double,double>/ {getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/DD_unbal_${k}_${j}.txt

	awk ' /map<double,double>/ {getline; getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/DD_bal_${k}_${j}.txt

	awk ' /map<double,double>/ {getline; getline; getline; print $7, $4 }' ./bst${k}_${j}.txt >> ./python/DD_std_${k}_${j}.txt
    
	awk ' /map<string,double>/ {getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/SD_unbal_${k}_${j}.txt

	awk ' /map<string,double>/ {getline; getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/SD_bal_${k}_${j}.txt

	awk ' /map<string,double>/ {getline; getline; getline; print $7, $4 }' ./bst${k}_${j}.txt >> ./python/SD_std_${k}_${j}.txt
	
	awk ' /map<string,string>/ {getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/SS_unbal_${k}_${j}.txt

	awk ' /map<string,string>/ {getline; getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/SS_bal_${k}_${j}.txt

	awk ' /map<string,string>/ {getline; getline; getline; print $7, $4  }' ./bst${k}_${j}.txt >> ./python/SS_std_${k}_${j}.txt

    done
done


for j in 3000 50000; do

    for k in 300000 500000 800000 1000000 2000000; do

 	touch ./python/ID_unbal_${k}_${j}.txt
	touch ./python/ID_bal_${k}_${j}.txt
	touch ./python/ID_std_${k}_${j}.txt
	
	touch ./python/DD_unbal_${k}_${j}.txt
	touch ./python/DD_bal_${k}_${j}.txt
	touch ./python/DD_std_${k}_${j}.txt
	
	touch ./python/SD_unbal_${k}_${j}.txt
	touch ./python/SD_bal_${k}_${j}.txt
	touch ./python/SD_std_${k}_${j}.txt

	touch ./python/SS_unbal_${k}_${j}.txt
	touch ./python/SS_bal_${k}_${j}.txt
	touch ./python/SS_std_${k}_${j}.txt

	awk ' /map<int,double>/ {getline; print $8, $5}' ./bst${k}_${j}.txt >> ./python/ID_unbal_${k}_${j}.txt

	awk ' /map<int,double>/ {getline; getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/ID_bal_${k}_${j}.txt

	awk ' /map<int,double>/ {getline; getline; getline; print $7, $4 }' ./bst${k}_${j}.txt >> ./python/ID_std_${k}_${j}.txt

	awk ' /map<double,double>/ {getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/DD_unbal_${k}_${j}.txt

	awk ' /map<double,double>/ {getline; getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/DD_bal_${k}_${j}.txt

	awk ' /map<double,double>/ {getline; getline; getline; print $7, $4 }' ./bst${k}_${j}.txt >> ./python/DD_std_${k}_${j}.txt
    
	awk ' /map<string,double>/ {getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/SD_unbal_${k}_${j}.txt

	awk ' /map<string,double>/ {getline; getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/SD_bal_${k}_${j}.txt

	awk ' /map<string,double>/ {getline; getline; getline; print $7, $4 }' ./bst${k}_${j}.txt >> ./python/SD_std_${k}_${j}.txt
	
	awk ' /map<string,string>/ {getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/SS_unbal_${k}_${j}.txt

	awk ' /map<string,string>/ {getline; getline; print $8, $5 }' ./bst${k}_${j}.txt >> ./python/SS_bal_${k}_${j}.txt

	awk ' /map<string,string>/ {getline; getline; getline; print $7, $4  }' ./bst${k}_${j}.txt >> ./python/SS_std_${k}_${j}.txt
	
    done
done
