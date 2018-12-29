/*
	class map::iterator declared here.
*/

/*
	This class contains all methods which are common
	to both classes 'iterator' and 'const_iterator'.
*/
template<class key_type,class value_type>
class map<key_type,value_type>::base_iterator :
	public std::iterator <
		std::forward_iterator_tag,
		std::pair< key_type, value_type> >
{
	friend map<key_type,value_type>;
	
	private:
	auto& next(const key_type&) noexcept ;
	
	protected:
	std::shared_ptr<node> pnode;
	base_iterator(const std::shared_ptr<node>& p): 
		pnode(p){}
	
	public:
	
	base_iterator() = default ;
	
	auto& operator ++ (){	
		// todo: if(pnode==nullptr) throw exception
		return next(pnode->key());
	} 
	bool operator == (const base_iterator& that) const noexcept {
		return pnode.get() == that.pnode.get();
	}
	bool operator != (const base_iterator& that) const noexcept {
		return not (*this == that);
	}
};


template<class key_type,class value_type>
class map<key_type,value_type>::iterator :
	public base_iterator 
{
	friend map<key_type,value_type>;
	using base_iterator::pnode;
	using base_iterator::base_iterator;

	public:
	auto& operator *() const {
		// todo: if(pnode==nullptr) throw exception
		return pnode->data;
	}
	auto  operator->() const {
		// todo: if(pnode==nullptr) throw exception
		return &(pnode->data);
	}
};

#include "map_iterator.cpp"
