#include "map.h"
#include "debug.h"
#include <bits/stdc++.h> // use all the std

using std::cout;
using std::endl;
using std::make_pair;

/*
	This function tests the public programming interface
	of the class map.
	It is meant to reveal errors at compile time.
*/
int test_api(){
	debug_call();
	
	map<int,int> M;

	/* todo: check that map works
		for any class key_type with operator< */
		
	M.insert(make_pair(1,1));

	return 0;
}


/*
	This function tests the topology of the tree.
	It reveals errors at runtime.
*/
int test_topology(){
	debug_call();
	
	map<int,int> M;
	
	// todo: make some test cases

	return M.check();
}

/*
	This function tests the iterators' interface.
*/
int test_iterator(){
	debug_call();
	// todo: test 'iterator' and 'const_iterator'
	return 0;
}

int main(){
	
	try {
		
		cout << ( test_api()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_topology()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_iterator()==0 ? "OK" : "ERROR" ) << endl;
		
	}catch(const std::exception& E){
		cout<< E.what() << "\n";
	}
	
	
	return 0;
}
