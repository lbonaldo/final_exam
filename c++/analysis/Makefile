map_dir=../include
FLAGS=-std=c++14 -Wall -Wextra -I../include -fmax-errors=1 -Werror -I./include -O3
map_files=$(map_dir)/map.h $(map_dir)/map.cpp $(map_dir)/map_node.h $(map_dir)/map_node.cpp $(map_dir)/map_iterator.h $(map_dir)/map_iterator.cpp ./include/analysis.h

default: analysis.x

%.x: %.cpp $(map_files)
	g++ $< -o $@ $(FLAGS)

analysis:
	./analysis.x

clean:
	rm *.x

PHONY: clean default analysis
