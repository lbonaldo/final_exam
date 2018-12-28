#include "map.h"
#include "debug.h"
#include <bits/stdc++.h> // use all the std

using std::cout;
using std::endl;
using std::make_pair;

std::default_random_engine G(time(NULL));

class value_example {};

class key_example {
	double k;
	public:
	key_example(const double& _k): k(_k){}
	bool operator < (const key_example& that) const {
		return k < that.k ;
	}
};

/*
	This function tests the public programming interface
	of the class map.
	It is meant to reveal errors at compile time.
*/
int test_api(){
	debug_call();
	
	map<key_example,value_example> M;
	std::uniform_real_distribution<double> rn(0.0,1.0);
	
	int n=100;
	
	while(n--)
		M.insert(
			make_pair(
				key_example(rn(G)),
				value_example()));
	
	

	return 0;
}


/*
	This function tests the topology of the tree.
	It reveals errors at runtime.
*/
int test_topology(){
	debug_call();
	
	std::uniform_int_distribution<int> rn(1,1000'000'000);
	map<int,int> M;
	
	if(M.check())
		return 1;
	
	for(int i=0;i<100'000;i++)
		M.insert(make_pair(rn(G),rn(G)));

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
