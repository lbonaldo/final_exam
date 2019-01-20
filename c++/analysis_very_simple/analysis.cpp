#include <bits/stdc++.h>
#include "map.h"

std::default_random_engine generator(time(NULL));

/*
	Test performance of map<T1,T2>::find() 
	
	n: size of the tree
	iter: repetitions
	vector_keys: sequence of keys to be inserted
*/
template <class T>
void test(const int iter,const std::vector<T>& vector_keys){

  std::map<T,T> map_std;
  map<T,T> map_hpc;

  for(auto x: vector_keys){
    map_hpc.insert({x,T{}});
    map_std.insert({x,T{}});
  }

  std::uniform_int_distribution<int> ri(0,vector_keys.size()-1);
  std::vector<T> query;
  
  for(int j=0;j<iter;++j)
  	query.push_back(vector_keys[ri(generator)]);

  auto t0 = std::chrono::high_resolution_clock::now();
  
  for(auto k: query)
    map_hpc.find(k);

  auto t1 = std::chrono::high_resolution_clock::now();
  
  map_hpc.balance();
  
  auto t2 = std::chrono::high_resolution_clock::now();
  
  for(auto k: query)
    map_hpc.find(k);

  auto t3 = std::chrono::high_resolution_clock::now();
  
  for(auto k: query)
    map_std.find(k);
    
  auto t4 = std::chrono::high_resolution_clock::now();
  
  std::cout<< vector_keys.size()
  << " "
  << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count()/double(iter) 
  << " "
  << std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count()/double(iter) 
  << " "
  << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count()/double(iter) 
  << std::endl;
  
}




int main(int argc, char *argv[]){

  if (argc < 4) {
    std::cerr << "Wrong number of argument. You must call ./analysis.x [DIMENSION] [NUMBER OF CHECKS] [sorted|random].\n";
    return 1;
  }

  const int n = atoi(argv[1]);
  const int iter = atoi(argv[2]);
  std::uniform_int_distribution<int> ri(0,1000'000'000);
	

	std::vector<int> keys(n);
	for(auto& x: keys)
		x = ri(generator);

  if(argv[3][0]=='r'){
    std::cout << "map<int,double>_random ";
    test(iter,keys);
  }
  else{
  	std::sort(keys.begin(),keys.end());
    std::cout << "map<int,double>_sorted ";
    test(iter,keys);
  }
  return 0;

}

