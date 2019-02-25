map_dir=./include
FLAGS=-std=c++14 -Wall -Wextra -I./include -fmax-errors=1 -Werror $(NDEBUG)
map_files=$(map_dir)/map.h $(map_dir)/map.cpp $(map_dir)/map_node.h $(map_dir)/map_node.cpp $(map_dir)/map_iterator.h $(map_dir)/map_iterator.cpp

default: test.x print.x

%.x: %.cpp $(map_files)
	g++ $< -o $@ $(FLAGS)

test:
	./test.x

print:
	./print.x

clean:
	rm *.x

PHONY: clean default test print
