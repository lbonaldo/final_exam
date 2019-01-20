#!/bin/bash

for j in 50 100 200 500 1000 2000 3000; do
    touch ./data/ID_unbal_mean_${j}.txt
    touch ./data/ID_bal_mean_${j}.txt
    touch ./data/ID_std_mean_${j}.txt
    
for k in 5000 10000 15000 20000 30000 50000 100000 150000 200000; do

	awk ' /map<int,double>/ {getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/ID_unbal_mean_${j}.txt 

	awk ' /map<int,double>/ {getline; getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/ID_bal_mean_${j}.txt

	awk ' /map<int,double>/ {getline; getline; getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/ID_std_mean_${j}.txt

    done
done

for j in 50 100 200 500 1000 2000 3000; do
    touch ./data/DD_unbal_mean_${j}.txt
    touch ./data/DD_bal_mean_${j}.txt
    touch ./data/DD_std_mean_${j}.txt
    
for k in 5000 10000 15000 20000 30000 50000 100000 150000 200000; do

	awk ' /map<double,double>/ {getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/DD_unbal_mean_${j}.txt 

	awk ' /map<double,double>/ {getline; getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/DD_bal_mean_${j}.txt

	awk ' /map<double,double>/ {getline; getline; getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/DD_std_mean_${j}.txt

    done
done

for j in 50 100 200 500 1000 2000 3000; do
    touch ./data/SD_unbal_mean_${j}.txt
    touch ./data/SD_bal_mean_${j}.txt
    touch ./data/SD_std_mean_${j}.txt
    
for k in 5000 10000 15000 20000 30000 50000 100000 150000 200000; do

	awk ' /map<string,double>/ {getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/SD_unbal_mean_${j}.txt 

	awk ' /map<string,double>/ {getline; getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/SD_bal_mean_${j}.txt

	awk ' /map<string,double>/ {getline; getline; getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/SD_std_mean_${j}.txt

    done
done

for j in 50 100 200 500 1000 2000 3000; do
    touch ./data/SS_unbal_mean_${j}.txt
    touch ./data/SS_bal_mean_${j}.txt
    touch ./data/SS_std_mean_${j}.txt
    
for k in 5000 10000 15000 20000 30000 50000 100000 150000 200000; do

	awk ' /map<string,string>/ {getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/SS_unbal_mean_${j}.txt 

	awk ' /map<string,string>/ {getline; getline; dim=$8; sum1 += $5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/SS_bal_mean_${j}.txt

	awk ' /map<string,string>/ {getline; getline; getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./data/SS_std_mean_${j}.txt

    done
done
