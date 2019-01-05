#ifndef MAP_H
#define MAP_H

#include <memory>
#include <map>
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <functional>

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
		(ok) class map::iterator
		(ok) class map::const_iterator
		(ok) insert()
		(ok) clear()
		(ok) begin()
		(ok) end()
		(ok) cbegin()
		(ok) cend()
		(ok) balance()
		(ok) find()
		- operator []
		- class map::exception
		- operator << 
		- copy constructor
		- copy assignment
		- move constructor
		- move assignment
		
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
	
	void insert(const std::pair<const key_type,value_type>&);
	
	iterator begin() const{
		return iterator(smallest_at(root));
	}

	iterator end() const {
		return iterator();
	}

	const_iterator cbegin() const noexcept {
	  return const_iterator(smallest_at(root));
	}

	const_iterator cend() const noexcept {
	  return const_iterator();
	}
  
	void clear(){
		root.reset();
	}
	
	void balance(); // O(N log N), very costly operation

	iterator find(const key_type&) const noexcept;

  auto& operator[](const key_type&);

  const auto& operator[](const key_type&) const noexcept;

  class exception {
    std::string message;
    exception(const std::string& s) : message{s} {}
  };

	#ifndef NDEBUG
	// debuggin functions
	int check();
	void print();
	bool is_balance();
	#endif
};


#include "map.cpp"
#include "map_node.h"
#include "map_iterator.h"

#endif
