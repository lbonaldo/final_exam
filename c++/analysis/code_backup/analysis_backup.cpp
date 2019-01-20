#include "map.h"
#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <vector>
#include <map>


std::string random_string_generator(const int length);

std::default_random_engine generator(time(NULL));
std::uniform_int_distribution<int> ri(0,1000);
std::uniform_real_distribution<double> rd(0.0,1.0);

//n is the maximum dimension of the map

template <typename T1, typename T2>
void test(const int n, const int& iter, map<T1,T2>& map){

  std::chrono::high_resolution_clock::time_point t0, t1, total_time_unbalanced, total_time_balanced, total_time_std;

  std::map<T1,T2> map_std;
  
  std::vector<T1> keys = random_vec_gen(n, T1{});
  std::vector<T2> values = random_vec_gen(n, T2{});

  for(auto i=0; i<n; ++i){
    map.insert(std::make_pair(keys[i],values[i]));
    map_std.std::map::insert(std::make_pair(keys[i],values[i]));
  }
  
  for(auto i=0; i<iter; ++i){
    int wanted_key = ri(generator)%n;
    t0 = std::chrono::high_resolution_clock::now();
    map.find(keys[wanted_key]);
    t1 = std::chrono::high_resolution_clock::now();
    total_time_unbalanced += std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
  }

  map.balance();

  for(auto i=0; i<iter; ++i){
    int wanted_key = ri(generator)%n;
    t0 = std::chrono::high_resolution_clock::now();
    map.find(keys[wanted_key]);
    t1 = std::chrono::high_resolution_clock::now();
    total_time_balanced += std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
  }

  for(auto i=0; i<iter; i++){
    int wanted_key = ri(generator)%n;
    t0 = std::chrono::high_resolution_clock::now();
    map_std.std::map::find(keys[wanted_key]);
    t1 = std::chrono::high_resolution_clock::now();
    total_time_std += std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
  }
  
  std::cout << "Look-up time UNBALANCED MAP: " << total_time_unbalanced << "us\n";
  std::cout << "Look-up time BALANCED MAP: " << total_time_balanced << "us\n";
  std::cout << "Look-up time STD::MAP: " << total_time_std << "us\n";

 
  map_std = clear();
}

std::vector<int>& random_vec_gen(const int n, const int dummy){
  (void)dummy;

  std::vector<int> random_vec(n);
  for(auto i = 0; i<n; ++i)
    random_vec_int.push_back(ri(generator));

  return random_vec;
}

std::vector<double>& random_vec_gen(const int n, const double dummy){
  (void)dummy;

  std::vector<double> random_vec(n);
  for(auto i = 0; i<n; ++i)
    random_vec.push_back(rd(generator));

  return random_vec;
}

std::vector<std::string>& random_vec_gen(const int n, const std::string& dummy){
  (void)dummy;

  std::vector<std::string> random_vec(n);
  for(auto i = 0; i<n; ++i)
    random_vec.push_back(random_string_generator(5));
  
  return random_vec;
}

std::string random_string_generator(const int length){
  
  const char alphanum[] =
    "0123456789"
    "!@#$%^&*"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
  
  std::string random_string;
  int alpha_length = sizeof(alphanum);
  
  for(auto i = 0; i < length; ++i)
    {
      random_string += alphanum[ri(generator) % alpha_length];
    }
  
  return random_string;
}

int main(int argc, char *argv[]){

  const iter = argv[1];

  map<int,double> map_id;
  map<double,double> map_dd;  
  map<std::string,double> map_sd;
  map<std::string,std::string> map_ss;

  std::cout << "map<int,double>: " << std::endl;
  test(1000, iter, map_id);
  std::cout << "map<double,double>: " << std::endl;
  test(1000, iter, map_dd);
  std::cout << "map<string,double>: " << std::endl;
  test(1000, iter, map_sd);
  std::cout << "map<string,string>: " << std::endl;
  test(1000, iter, map_ss);

  map_id.clear();
  map_dd.clear();
  map_sd.clear();
  map_ss.clear();

  return 0;

}
