#ifndef MAP_H
#define MAP_H

#include <memory>
#include <map>
#include <stack>

/*
	class map, declared here, is a binary tree
	where each node contains an std::pair<key,value>.
	Its public interface is mean to be similar to the std::map.
	
	note:
	The std::map requires the key_type to have a method 'operator<',
	which defines a partial (or total?) ordering.
	Therefore, do not assume that key_type has any of the following methods:
		'operator>'
		'operator=='
		'operator !='
*/

template<class key_type, class value_type>
class map
{
	/*
		todo:
		(ok) class map::node
		- class map::iterator
		- class map::const_iterator
		(ok) insert()
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
	class base_iterator; 
	
	std::shared_ptr<node> root;

	auto smallest_at(
		const std::shared_ptr<node>&) const noexcept;

	auto search_at(
		const key_type&,
		const std::shared_ptr<node>&) const noexcept;


	public:
	
	class iterator;
	class const_iterator;
	
	int check();
	void insert(const std::pair<const key_type,value_type>&);
};


#include "map.cpp"
#include "map_node.h"
#include "map_iterator.h"

#endif
