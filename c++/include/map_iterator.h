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
	
	protected:
	
	std::shared_ptr<node> pnode;
	
	base_iterator(const std::shared_ptr<node>& p): 
		pnode(p){}
	
	
	
	public:
	
	// operator ++ (); 
	// operator == ();
	// operator != ();
};
