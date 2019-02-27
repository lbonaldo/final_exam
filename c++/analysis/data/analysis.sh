#!/bin/bash

j=50000

    # touch ./mean/ID_unbal_mean_${j}.txt
    # touch ./mean/ID_bal_mean_${j}.txt
    # touch ./mean/ID_std_mean_${j}.txt

    # touch ./mean/DD_unbal_mean_${j}.txt
    # touch ./mean/DD_bal_mean_${j}.txt
    # touch ./mean/DD_std_mean_${j}.txt

    # touch ./mean/SD_unbal_mean_${j}.txt
    # touch ./mean/SD_bal_mean_${j}.txt
    # touch ./mean/SD_std_mean_${j}.txt

    # touch ./mean/SS_unbal_mean_${j}.txt
    # touch ./mean/SS_bal_mean_${j}.txt
    # touch ./mean/SS_std_mean_${j}.txt

for k in 5000 10000 15000 20000 30000 50000 100000 150000 200000; do
	
	awk ' /map<int,double>/ {getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/ID_unbal_mean_${j}.txt 

	awk ' /map<int,double>/ {getline; getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/ID_bal_mean_${j}.txt

	awk ' /map<int,double>/ {getline; getline; getline; dim=$7; sum1+=$4; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/ID_std_mean_${j}.txt

	awk ' /map<double,double>/ {getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/DD_unbal_mean_${j}.txt 

	awk ' /map<double,double>/ {getline; getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/DD_bal_mean_${j}.txt

	awk ' /map<double,double>/ {getline; getline; getline; dim=$7; sum1+=$4; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/DD_std_mean_${j}.txt
    
	awk ' /map<string,double>/ {getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/SD_unbal_mean_${j}.txt 

	awk ' /map<string,double>/ {getline; getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/SD_bal_mean_${j}.txt

	awk ' /map<string,double>/ {getline; getline; getline; dim=$7; sum1+=$4; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/SD_std_mean_${j}.txt
	
	awk ' /map<string,string>/ {getline; dim=$8; sum1+=$5; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/SS_unbal_mean_${j}.txt 

	awk ' /map<string,string>/ {getline; getline; dim=$8; sum1 += $5; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/SS_bal_mean_${j}.txt

	awk ' /map<string,string>/ {getline; getline; getline; dim=$7; sum1+=$4; n++ } END { if (n > 0) printf("%d %.7f\n", dim, sum1/n) ; }' ./bst${k}_${j}.txt >> ./mean/SS_std_mean_${j}.txt

done
