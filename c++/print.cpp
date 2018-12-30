#include "map.h"
#include "debug.h"
#include <bits/stdc++.h> // use all the std

using std::cout;
using std::endl;
using std::make_pair;


std::default_random_engine G(time(NULL));

/*
	This function tests the topology of the tree.
	It reveals errors at runtime.
*/
int test_topology(){
	
	map<int,int> M;
	
	if(M.check())
		return 1;
	
	M.insert(make_pair(8, 1));
	M.insert(make_pair(3, 2));
	M.insert(make_pair(10,3));
	M.insert(make_pair(1, 4));
	M.insert(make_pair(6, 5));
	M.insert(make_pair(14,6));
	M.insert(make_pair(4, 7));
	M.insert(make_pair(7, 8));
	M.insert(make_pair(13,9));
	M.print();
		
	return M.check();
}


int main(){
	
	try {
		
		test_topology();
		
	}catch(const std::exception& E){
		cout<< E.what() << "\n";
	}
	
	
	return 0;
}
