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
	
	Complexity: O(H), where H is the height of the tree.
*/
template<class key_type, class value_type> 
class map<key_type,value_type>::iterator
       map<key_type,value_type>::insert(
	const std::pair<const key_type,value_type>& p)
{
	if(root==nullptr){ // the first insertion
		root.reset(new node(p));
		return iterator();
	}
	
	auto i = search_at(p.first,root);
	
	if( i==nullptr ) throw exception{"Error: unkwown key."};

	if( p.first < i->key() )
		i->left.reset( new node(p,i));
	
	else if(i->key() < p.first )
		i->right.reset( new node(p,i));

	return iterator(i);
	// else; do nothing
}

/*
	Complexity: O(N log N), where N is the number of 
	vertexes (nodes) in the tree.
*/
template<class key_type, class value_type> 
void map<key_type,value_type>::balance()
{
	if(root==nullptr) return ;
	
	std::vector<std::shared_ptr<node> > V;
	for(auto i=begin();i!=end();++i) V.emplace_back(i.pnode);
	
	clear();
	
	std::function< void (int,int) > 
		frec = [&](int a,int b) -> void {
			if(b <= a) return ;
			int m = (a+b)/2;
			insert(V[m]->data);	
			frec(a,m);
			frec(m+1,b);
		};
	frec(0,V.size());
}

/*
*/
template<class key_type, class value_type> 
class map<key_type,value_type>::iterator
	map<key_type,value_type>::find(const key_type& k) const noexcept 
{
	auto i = search_at(k,root);
	
	if(i==nullptr or i->key() < k or k < i->key())
		return iterator();
	
	return iterator(i);
}

#ifndef NDEBUG
/*
	This method is for debuging purposes.
	It tests if the topology of the tree satisfies 
	the rules of a binary search tree.
*/

template<class key_type, class value_type> 
int map<key_type,value_type>::check()
{
	std::map<key_type,bool> visited;
	std::stack< std::shared_ptr<node> > s;
	
	if(root!=nullptr) s.push(root);
	
	while(not s.empty()){
		auto r = s.top();
		s.pop();
		
		if(visited[r->key()])
			return 1; // backedge discovered! This is not a tree.
			
		visited[r->key()]=true;
		
		if(r->left != nullptr){
			if(not (r->left->key() < r->key()))
				return 1; // invalid left node
			
			s.push(r->left);
		}
		if(r->right != nullptr){
			if(not (r->key() < r->right->key()))
				return 1; // invalid right node
			
			s.push(r->right);
		}
	}
	
	return 0;
}
/*
	This method is for debuging purposes.
	It helps visualizing the tree by printing
	all of the edges.
*/

template<class key_type, class value_type> 
void map<key_type,value_type>::print() {
	std::stringstream print_v,print_e;
	
	std::function< void(std::shared_ptr<node>)  > 
		frec = [&](std::shared_ptr<node> x) -> void
		{
			if(x==nullptr) return;
			
			auto p = x->parent.lock();
			if(p!=nullptr)
				print_e << p->key() << " - " << x->key() << "\n";
			
			frec(x->left);
			frec(x->right);
			print_v << x->key() << ": " << x-> value() << "\n";
		};
	frec(root);

	
	std::cout 	<< "Vertexes:\n" << print_v.str() << "\n"
				<< "Edges:\n"	 << print_e.str() << "\n";
				
}

/*
	This method is for debuging purposes.
*/

template<class key_type, class value_type> 
bool map<key_type,value_type>::is_balance() {
	int diff=0;
	std::function< int(std::shared_ptr<node>)  > 
		frec = [&](std::shared_ptr<node> x) -> int 
		{
			if(x==nullptr) return 0;
			
			int n=1,l,r;
			n += l=frec(x->left);
			n += r=frec(x->right);
			diff=std::max(diff,abs(l-r));			
			return n;
		};
	frec(root);
	return diff <= 1 ;
}
#endif

template<class key_type, class value_type>
auto& map<key_type,value_type>::operator[](const key_type& k) {

  auto i = find(k);

  if( i == end() )
    i = insert(std::make_pair(k,value_type()));
  
  return i->second;
}

template<class key_type, class value_type>
const auto& map<key_type,value_type>::operator[](const key_type& k) const noexcept {

   auto i = find(k);
  
   if( i == end() ) throw exception{"Error: end of the binary tree."};
  
   return i->second;
 }

