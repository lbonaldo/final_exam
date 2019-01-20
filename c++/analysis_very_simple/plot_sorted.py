#!/usr/bin/python3

import matplotlib.pyplot as plt

f = open("map_int_sorted.dat","r")

smax = 100

x = []
y_balance=[ ]
y_unbalance=[ ]
y_std=[]

for l in f:
	_,n,t1,t2,t3 = l.split()
	n = int(n)
	t1 = float(t1)
	t2 = float(t2)
	t3 = float(t3)
	
	x += [n]
	y_unbalance += [t1]	
	y_balance += [t2]	
	y_std += [t3]	


plt.figure(1)
plt.title("Performance of map::find() for sorted input.")


plt.plot(x,y_unbalance,label="Unbalanced tree")
plt.plot(x,y_balance,label="Balanced tree")
plt.plot(x,y_std,label="Std tree")

plt.ylabel("Time (us)")
plt.xlabel("Size")
plt.legend()
plt.savefig("plot_sorted.png")

