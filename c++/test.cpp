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

	M.insert(make_pair(1,1));

	return 0;
}

int main(){
	
	try {
		
		cout << ( test_api()==0 ? "OK" : "ERROR" ) << endl;
		
	}catch(const std::exception& E){
		cout<< E.what() << "\n";
	}
	
	
	return 0;
}
