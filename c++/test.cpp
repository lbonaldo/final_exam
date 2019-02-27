/*
	todo:
*/


#include "map.h"
#include "debug.h"
#include <bits/stdc++.h> // use all the std


class test_fail : public std::exception {
	std::string message;
	public:
	test_fail(const char* mes): message(mes) {}
	
	const char* what() const noexcept { return message.c_str();}
};


using std::cout;
using std::endl;

std::default_random_engine G(time(NULL));

class value_example {}; //minimum working class value

class key_example {
	int k;

  public:
	key_example(const int _k): k(_k){}
	
  bool operator < (const key_example& that) const {
		return k < that.k ;
	}
}; // minimum working class key



/*
	This function tests the public programming interface
	of the class map.
	It is meant to reveal errors at compile time.
*/
int test_api(){
	debug_call();
	
	
	map<key_example,value_example> M;
	std::uniform_int_distribution<int> rn(1,6);
	
	
	// private members:
	// map<int,int>::node X;
	// map<int,int>::base_iterator X;
	// M.root;
	//M.smallest_at(...);
	//M.search_at(...);
	auto it = M.begin();
	//it.next(key_example(1));
	//it.pnode;
	
	int n=10;

	// test insert
	while(n--)
		M.insert(
			{key_example(rn(G)),value_example()});

	// test iterator, begin(), end()
	for(auto& x: M) x.second = value_example();
	
	// test balance
	M.balance();
	
	// test find
	M.find(key_example(rn(G)));
	
	// test operator[]
	M[key_example(rn(G))] = value_example(); // use of map::operator[]
	
	
	// test const_iterator
	{
		const map<key_example,value_example>& X = M;
		
		// test operator[] const
		//X.find(key_example(10));
		
		// test begin() const
		X.begin();
		
		// test end() const
		X.end();
		
		// compilation error: X.begin() returns const_iterator
		// map<key_example,value_example>::iterator i = X.begin();
	}

	return 0;
}


/*
	This function tests the topology of the tree.
	It reveals errors at runtime.
	
*/
#ifndef NDEBUG
int test_topology(){
	debug_call();
	
	std::uniform_int_distribution<int> rn(1,1000'000'000);
	map<int,int> M;
	
	if(M.check())
		throw test_fail("topology fail after default constructor");
	
	for(int i=0;i<100'000;i++)
		M.insert({rn(G),rn(G)});

	if(M.check())
		throw test_fail(" topology fail after insert");
	
	return 0;
}
#endif
/*
	This function tests the iterators' interface.
*/
int test_iterator(){
	debug_call();
	
	int N=100;
	std::uniform_int_distribution<int> rn(1,1000);
	
	map<int,int> M;
	std::map<int,int> sM;
	
	
	for(int i=0;i<N;i++){
		int k=rn(G),v=rn(G);
		 M.insert({k,v});
		sM.insert({k,v});
	}
	
	{
		auto it=M.begin();
		int k = it->first;
		auto it2=M.find(k);
		
		if(it != it2)
			throw test_fail("comparison of iterator fails");
		
	}

	std::stringstream std_s, star_s,arrow_s,auto_s,const_arrow_s,const_star_s;
	
	for(auto x: sM)
		std_s << x.first << " " << x.second << "\n";
	
	for(auto x: M)
		auto_s << x.first << " " << x.second << "\n";
		
	for(map<int,int>::iterator x=M.begin();x!=M.end();++x)
		arrow_s << x->first << " " << x->second << "\n";
	
	for(map<int,int>::iterator x=M.begin();x!=M.end();++x)
		star_s << (*x).first << " " << (*x).second << "\n";
	
	{
	  const map<int,int>& cM = M;
	  for(map<int,int>::const_iterator x=cM.begin();x!=cM.end();++x)
	    const_arrow_s << x->first << " " << x->second << "\n";
	  
	  for(map<int,int>::const_iterator x=cM.begin();x!=cM.end();++x)
	    const_star_s << (*x).first << " " << (*x).second << "\n";
	  
	  for(auto x=cM.begin();x!=cM.end();++x){
	    // 	x->first = 0; // compile error: x is a const_iterator
	    //	x->second = 0;// compile error: x is a const_iterator
	    // 	(*x).first = 0; // compile error: x is a const_iterator
	    // 	(*x).second = 0; // compile error: x is a const_iterator
	  }
	}
	
	if(auto_s.str() != std_s.str())
		throw test_fail("auto iterator fail");
		
	if(star_s.str() != std_s.str())
		throw test_fail("iterator::operator*() fail");
		
	if(arrow_s.str()!= std_s.str())	
		throw test_fail("iterator::operator->() fail");
	
	if(const_star_s.str() != std_s.str())
		throw test_fail("const_iterator::operator*() fail");
		
	if(const_arrow_s.str()!= std_s.str())	
		throw test_fail("const_iterator::operator->() fail");
	
	for(auto x=M.begin();x!=M.end();++x){
		// x->first = 0; // compile error: the key is const
		x->second = 0; 
		//(*x).first = 0; // compile error: the key is const
		(*x).second = 0; 
	}	
	
	return 0;
}

/*
	This function checks if the tree is balanced
	after calling 'balance()'.
*/
#ifndef NDEBUG
int test_balance(){
	debug_call();
	
	int N=100'000;
	std::uniform_int_distribution<int> rn(1,1000'000);
	
	map<int,int> M;
	
	for(int i=0;i<N;i++){
		int k=rn(G),v=rn(G);
		 M.insert({k,v});
	}
	M.balance();	
		
	if(not M.is_balance())
		throw test_fail("tree not balanced");

	return 0;
}
#endif

/*
	Test 'find()' function
*/
int test_find(){
	debug_call();
	int N = 100'000,Nmax=1000'000;
	std::uniform_int_distribution<int> rn(1,Nmax);
	map<int,int> M;
	std::map<int,int>sM;
	
	for(int i=0;i<N;i++){
		int k=rn(G),v=rn(G);
		M.insert({k,v});
		sM.insert({k,v});
	}

	for(int k=1;k<=Nmax;k++){
		auto it = M.find(k);
		auto sit = sM.find(k);
		
		if( (it==M.end()) ^ (sit==sM.end()) ) // if and only if
			throw test_fail("one found and the other one not");
		
		if(it==M.end())continue;
		
		if( it->first!=sit->first or it->second!=sit->second  )
			throw test_fail("keys or values different");
	}
	
	return 0;
}

/*
	Test 'operator[]'
*/
int test_brackets(){
	debug_call();
	int N = 100,Nmax=1000;
	std::uniform_int_distribution<int> rn(1,Nmax);
	map<int,int> M;
	std::map<int,int>sM;
	
	for(int i=0;i<N;i++){
		int k=rn(G),v=rn(G);
		M[k]=v;
		sM[k]=v;
	}
	
	std::stringstream std_s, my_s;
	
	for(auto x: sM)
		std_s << x.first << " " << x.second << "\n";
	
	for(auto x: M)
		my_s << x.first << " " << x.second << "\n";
	
	if(std_s.str() != my_s.str())
		throw test_fail("contents of map is wrong.");


	return 0;
}



bool operator == (const map<int,int>& A,const map<int,int>& B){
	std::stringstream sa,sb;
	sa << A;
	sb << B;	
	return sa.str()==sb.str();
}

/*
	Test move and copy semantics.
*/

int test_move_copy(){
	debug_call();
	int N = 100,Nmax=1000;
	std::uniform_int_distribution<int> rn(1,Nmax);
	
	map<int,int> M_orig;
	
	for(int i=0;i<N;i++)
		M_orig[ rn(G) ] = rn(G);
	
	
	map<int,int> M_copy = M_orig;

	if(not (M_orig == M_copy))
		throw test_fail("copy ctor did not copy");
	
	M_orig[ rn(G)  ] = rn(G);
	
	if(M_orig == M_copy)
		throw test_fail("copy ctor did a shallow copy");
	
	M_copy.clear();
	
	if( not (M_copy.begin()==M_copy.end()))
		throw test_fail("clear() did not clear");
	
	M_copy = M_orig;
	
	if(not (M_orig == M_copy))
		throw test_fail("copy assignment did not copy");
	
	M_orig[ rn(G)  ] = rn(G);
	
	if(M_orig == M_copy)
		throw test_fail("copy assignment did a shallow copy");

	M_copy = M_orig;
	map<int,int> M_move = std::move(M_orig);
	
	if(not (M_orig.begin()==M_orig.end()))
		throw test_fail("move ctor did not release M_orig");
		
	if(not (M_move==M_copy))
		throw test_fail("move ctor did not populate M_move");
	
	M_move.clear();
	M_orig = M_copy;
	
	M_move = std::move(M_orig);
	
	if(not (M_orig.begin()==M_orig.end()))	
		throw test_fail("move assignment did not release M_orig");
		
	if(not (M_move==M_copy))
		throw test_fail("move assignment did not populate M_move");
	

	return 0;
}

int main(){
	
	try {
		
		cout << ( test_api()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_iterator()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_find()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_brackets()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_move_copy()==0 ? "OK" : "ERROR" ) << endl;
		
		#ifndef NDEBUG
		cout << ( test_topology()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_balance()==0 ? "OK" : "ERROR" ) << endl;
		#endif
		
	}catch(const std::exception& E){
		cout<< E.what() << "\n";
	}
	
	
	return 0;
}
 
