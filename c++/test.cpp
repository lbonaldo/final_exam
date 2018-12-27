#include "map.h"
#include "debug.h"
#include <bits/stdc++.h> // use all the std

using std::cout;
using std::endl;

/*
	This function tests the public programming interface
	of the class map.
	It is meant to reveal errors at compile time.
*/
int test_template(){
	debug_call();
	
	map<int,int> M;
	
	return 0;
}

int main(){
	
	try {
		
		cout << ( test_template()==0 ? "OK" : "ERROR" ) << endl;
		
	}catch(const std::exception& E){
		cout<< E.what() << "\n";
	}
	
	
	return 0;
}
