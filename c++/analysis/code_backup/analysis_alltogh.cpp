#include "map.h"
#include <iostream>
#include <string>

std::string random_string_generator(int length);

int main (){

  map<int,double> map_id;
  map<double,double> map_dd;  
  map<std::string,double> map_sd;
  map<std::string,std::string> map_ss;

  int n=1000;
  std::default_random_engine generator(time(NULL));
  std::uniform_int_distribution<int> ri(0,1000);
  std::uniform_real_distribution<double> rd(0.0,1.0);

  std::vector<int> key_int = (n);
  std::vector<double> key_double = (n);
  std::vector<std::string> key_string = (n);
  
  while(n--){

    int random_int = ri(generator);
    double random_double = rd(generator);
    std::string random_string = random_string_generator(5);

    key_int.push_back(random_int);
    key_double.push_back(random_double);
    key_string.push_back(random_string);
    
    map_id.insert(std::make_pair(random_int,rd(generator)));
    map_dd.insert(std::make_pair(random_double,rd(generator)));
    map_sd.insert(std::make_pair(random_string,rd(generator)));
    map_ss.insert(std::make_pair(random_string, random_string_generator(5)));
    
  }

  for(auto i = 0; i < 360; i++){
    int look_key = ri(generator)%n;
    map_id.find(key_int[look_key]);
    map_dd.find(key_double[look_key]);
    map_sd.find(key_string[look_key]);
    map_ss.find(key_string[look_key]);
  }
  
  map_id.balance();
  map_dd.balance();
  map_sd.balance();
  map_ss.balance();
    
  for(auto i = 0; i < 360; i++){
    int look_key = ri(generator)%n;
    map_id.find(key_int[look_key]);
    map_dd.find(key_double[look_key]);
    map_sd.find(key_string[look_key]);
    map_ss.find(key_string[look_key]);
  }

  map_id.clear();
  map_dd.clear();
  map_sd.clear();
  map_ss.clear();

  return 0;
}

std::string random_string_generator(int length){
  
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
