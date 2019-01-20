map_dir=../include
FLAGS=-std=c++14 -Wall -Wextra -fmax-errors=1 -Werror -O3 -I../include
map_files=$(map_dir)/map.h $(map_dir)/map.cpp $(map_dir)/map_node.h $(map_dir)/map_node.cpp $(map_dir)/map_iterator.h $(map_dir)/map_iterator.cpp

default: analysis.x

analysis.x: analysis.cpp $(map_files)
	g++ $< -o $@ $(FLAGS)

result_random.dat: analysis.x run_random.sh
	./run_random.sh

result_sorted.dat: analysis.x run_sorted.sh
	./run_sorted.sh

plot_random.png: result_random.dat plot_random.py
	grep "map<int,double>" result_random.dat > map_int_random.dat
	./plot_random.py
	
plot_sorted.png: result_sorted.dat plot_sorted.py
	grep "map<int,double>" result_sorted.dat > map_int_sorted.dat
	./plot_sorted.py

plot: result_random.dat result_sorted.dat plot_random.png plot_sorted.png
	eog plot_random.png
	eog plot_sorted.png

clean:
	rm *.x

PHONY: clean default
