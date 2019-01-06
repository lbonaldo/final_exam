#include "map.h"
#include "debug.h"
#include <bits/stdc++.h> // use all the std


/*
	todo:
*/

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
	
	int n=10;
	
	while(n--)
		M.insert(
			make_pair(
				key_example(rn(G)),
				value_example()));

	for(auto& x: M) x.second = value_example();
	
	M.cbegin();
	M.cend();
	M.balance();
	M.find(key_example(rn(G)));
	M[key_example(rn(G))];
	
	auto f = [] (const map<key_example,value_example>& X){
		X[key_example(10)];
	}
	
	f(M);
	
	//std::stringstream s;
	//s << M ;
	//map<key_example,value_example> M1 = std::move(M);
	//M = std::move(M1);
	//M1 = M;
	//map<key_example,value_example> M2 = std::move(M1);
	
	M.clear();
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
	
	int N=100;
	std::uniform_int_distribution<int> rn(1,1000);
	
	map<int,int> M;
	std::map<int,int> sM;
	
	for(int i=0;i<N;i++){
		int k=rn(G),v=rn(G);
		 M.insert(make_pair(k,v));
		sM.insert(make_pair(k,v));
	}
	
	std::stringstream std_s, star_s,arrow_s,auto_s,const_arrow_s,const_star_s;
	
	for(auto x: sM)
		std_s << x.first << " " << x.second << "\n";
	
	for(auto x: M)
		auto_s << x.first << " " << x.second << "\n";
		
	for(auto x=M.begin();x!=M.end();++x)
		arrow_s << x->first << " " << x->second << "\n";
	
	for(auto x=M.begin();x!=M.end();++x)
		star_s << (*x).first << " " << (*x).second << "\n";
	
	for(auto x=M.cbegin();x!=M.cend();++x)
		const_arrow_s << x->first << " " << x->second << "\n";
	
	for(auto x=M.cbegin();x!=M.cend();++x)
		const_star_s << (*x).first << " " << (*x).second << "\n";
	
	if(auto_s.str() != std_s.str())return 1;	
	if(star_s.str() != std_s.str())return 1;	
	if(arrow_s.str()!= std_s.str())return 1;	
	
	if(const_star_s.str() != std_s.str())return 1;	
	if(const_arrow_s.str()!= std_s.str())return 1;	
	
	for(auto x=M.begin();x!=M.end();++x){
		//x->first = 0; // compile error: the key is const
		x->second = 0; 
		//(*x).first = 0; // compile error: the key is const
		(*x).second = 0; 
	}
	
	for(auto x=M.cbegin();x!=M.cend();++x){
	// 	x->first = 0; // compile error: x is a const_iterator
	//	x->second = 0;// compile error: x is a const_iterator
	// 	(*x).first = 0; // compile error: x is a const_iterator
	// 	(*x).second = 0; // compile error: x is a const_iterator
	}
	
	return 0;
}


int test_balance(){
	debug_call();
	
	int N=100;
	std::uniform_int_distribution<int> rn(1,1000);
	
	map<int,int> M;
	std::map<int,int> sM;
	
	for(int i=0;i<N;i++){
		int k=rn(G),v=rn(G);
		 M.insert(make_pair(k,v));
		sM.insert(make_pair(k,v));
	}
	M.balance();	
	std::stringstream std_s, my_s;
	
	for(auto x: sM)
		std_s << x.first << " " << x.second << "\n";
	
	for(auto x: M)
		my_s << x.first << " " << x.second << "\n";
	
		
	if(my_s.str() != std_s.str() or not M.is_balance())return 1;	

	return 0;
}

int test_find(){
	debug_call();
	int N = 100'000,Nmax=1000'000;
	std::uniform_int_distribution<int> rn(1,Nmax);
	map<int,int> M;
	std::map<int,int>sM;
	
//	sM.insert(make_pair(4,23));  //error
	
	for(int i=0;i<N;i++){
		int k=rn(G),v=rn(G);
		M.insert(make_pair(k,v));
		sM.insert(make_pair(k,v));
	}


	for(int k=1;k<=Nmax;k++){
		auto it = M.find(k);
		auto sit = sM.find(k);
		
		if( (it==M.end()) ^ (sit==sM.end()) ) // if and only if
			return 1; 
		
		if(it==M.end())continue;
		
		if( it->first!=sit->first or it->second!=sit->second  )return 1;
	}
	
	return 0;
}


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
		return 1;
	
	return 0;
}


int main(){
	
	try {
		
		cout << ( test_api()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_topology()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_iterator()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_balance()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_find()==0 ? "OK" : "ERROR" ) << endl;
		cout << ( test_brackets()==0 ? "OK" : "ERROR" ) << endl;
		
	}catch(const std::exception& E){
		cout<< E.what() << "\n";
	}
	
	
	return 0;
}
