#include "map.h"
#include "debug.h"
#include <bits/stdc++.h> // use all the std

using std::cout;
using std::endl;

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
