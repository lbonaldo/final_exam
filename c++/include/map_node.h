/*
	class map::node declared here.
*/

template<class key_type,class value_type>
class map<key_type,value_type>::node
{

	/*
		In order to use iterator::operator++()
		each iterator must know either
			- the parent of the current node,
			- or map::root.
		We have decided (?) to use 'parent',
		so that the iterator knows only the local structure
		of the tree, and that iterator, in theory, remains
		valid after changing the topology of the tree.
	*/
	std::weak_ptr<node> parent; // the parent node owns the child, not the other way around, that's why we use weak_ptr here.
	std::shared_ptr<node> left,right;
	std::pair<const key_type,value_type> data;

	friend map<key_type,value_type>;

	public:

	node(	const std::pair<const key_type&,value_type>& kv,
			const std::shared_ptr<node>& p):
		parent(p), data(kv) {}
		
	node(	const std::pair<const key_type&,value_type>& kv):
		data(kv) {}
	
	const key_type& key() noexcept {
		return data.first;
	}
	
	value_type& value() noexcept {
		return data.second;
	}	
};

#include "map_node.cpp"
