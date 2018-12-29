/*
	class map::iterator implemented here.
*/


/*
	This is private.
	It moves 'this' iterator inside the tree
	in search for the node with the lowest
	key greater than 'k'.
	
	This function is to be used by the operator++()
*/
template<class key_type,class value_type> 
auto& map<key_type,value_type>::base_iterator::next(
	const key_type& k) noexcept 
{
	if(pnode==nullptr)
		return *this;
	
	if(pnode->left != nullptr and k < pnode->left->key()){
		pnode=pnode->left;
		return next(k);
	}else if (k < pnode->key()){
		return *this;
	}else if(pnode->right != nullptr and k < pnode->right->key()){
		pnode = pnode->right;
		return next(k);
	}
	// else: the current subtree at pnode does not contain a key greater
	// than k, so we need to move upwards
	pnode = pnode->parent.lock();
	return next(k);
}


