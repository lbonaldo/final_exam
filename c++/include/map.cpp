/*
	Map class implemented here.
*/



/*
	This is private.
	It returns a pointer to the smallest element
	in a subtree rooted at 'r'.
	Complexity O(H), where H is the height of the tree.
	
	This method must be used in 'begin()'
*/
template<class key_type, class value_type> 
auto map<key_type,value_type>::smallest_at(
	const std::shared_ptr<node>& r) const noexcept
{
	if(r==nullptr) return r; // don't throw exceptions
	
	auto p=r;
	while( p->left != nullptr)
		p = p -> left;
		
	return p;
}


/*
	This is private.
	It returns a pointer to the unique node 'p'
	in a subtree rooted at 'r', where the key 'k'
	can be inserted. 
	Possible cases: 
		- 'k' goes into 'p',
		- 'k' goes to the left of 'p', but the left is null,
		- 'k' goes to the right of 'p', but the right is null.
	Complexity O(H), where H is the height of the tree.
	
	This method must be used in 'find()' and 'insert()'.
*/
template<class key_type, class value_type> 
auto map<key_type,value_type>::search_at(
	const key_type& k,
	const std::shared_ptr<node>& r) const noexcept
{
	if(r==nullptr) return r; // don't throw exceptions
	
	if( k < r->key() and r->left != nullptr )
		return search_at(k,r->left);
	if( r->key() < k and r->right != nullptr )
		return search_at(k,r->right);
		
	return r;
}

/*
	The input pair 'p' contains the key k=p.first 
	and the value v=p.second to be inserted.
	
	If the input key 'k' is not present, it creates a new node
	with value 'v'. 
	Otherwise (if there is already a node with 'k') 
	do not change anything (its value).
*/
template<class key_type, class value_type> 
void map<key_type,value_type>::insert(
	const std::pair<const key_type,value_type>& p)
{
	if(root==nullptr){ // the first insertion
		root.reset(new node(p));
		return ;
	}
	auto i = search_at(p.first,root);
	// todo: if i==nullptr 	throw an exception

	if( p.first < i->key() )
		i->left.reset( new node(p,i));
	else if(i -> key() < p.first )
		i->right.reset( new node(p,i));
	// else; do nothing
}
