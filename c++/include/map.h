#ifndef MAP_H
#define MAP_H

#include <memory>

/*
	class map, declared here, is a binary tree
	where each node contains an std::pair<key,value>.
	Its public interface is mean to be similar to the std::map.
*/

template<class key_type, class value_type>
class map
{
	/*
		todo:
		- class map::node
		- class map::iterator
		- class map::const_iterator
		- insert()
		- clear()
		- begin()
		- end()
		- cbegin()
		- cend()
		- balance()
		- find()
		- operator []
		- copy semantics
		- move semantics
		- class map::exception
		- operator << 
		
		test:
		- no memory leaks
		- the public interface
		- correctedness against std::map
		- performance of 'find()' in the following cases:
			- worst case unbalanced tree
			- balance after calling 'balance()'
		- compare the performance with std::map
		
		
	*/
	
	private:
	
	class node;
	std::shared_ptr<node> root;
	
	public:
	
	class iterator;
	class const_iterator;
};


#include "map.cpp"

#endif
