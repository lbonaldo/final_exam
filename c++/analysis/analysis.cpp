#include <analysis.h>

template <typename T1, typename T2>
void test(const int& n, const int& iter, map<T1,T2>& map){

  std::map<T1,T2> map_std;

  std::vector<T1> vector_keys = random_gen(n, T1{});
  std::vector<T2> vector_values = random_gen(n, T2{});

  for(auto i=0; i<n; ++i){
    map.insert(std::make_pair(vector_keys[i],vector_values[i]));
    map_std.insert({vector_keys[i],vector_values[i]});
  }

  double dummy{};
  
  auto t0 = std::chrono::high_resolution_clock::now();
  
  for(auto j=0; j<iter; ++j){
    int wanted_key = ri(generator)%n;  
    auto i = map.find(vector_keys[wanted_key]);
    dummy += func((*i).second, j);
  }

  auto t1 = std::chrono::high_resolution_clock::now();
  
  map.balance();
  
  auto t2 = std::chrono::high_resolution_clock::now();
    
  for(auto j=0; j<iter; ++j){
    int wanted_key = ri(generator)%n;
    auto i = map.find(vector_keys[wanted_key]);
    dummy += func((*i).second, j);
  }

  auto t3 = std::chrono::high_resolution_clock::now();
  
  for(auto j=0; j<iter; j++){
    int wanted_key = ri(generator)%n;
    auto i = map_std.find(vector_keys[wanted_key]);
    dummy += func2((*i).second, j);
  }
  auto t4 = std::chrono::high_resolution_clock::now();
  
  std::cout << "Look-up time UNBALANCED MAP: "
	    << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count()
	    << " us Dim: " 
	    << n << std::endl;

  std::cout << "Look-up time BALANCED MAP: "
      << std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count()
	    << " us Dim: "
	    << n << std::endl;

  std::cout << "Look-up time STD::MAP: "
	    << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count()
	    << " us Dim: "
	    << n << std::endl;

  std::cout << dummy << std::endl;
}

std::vector<int> random_gen(const int n, const int dummy){
  (void)dummy;

  std::vector<int> random_vec(n);
  for(auto i = 0; i<n; ++i)
    random_vec[i] = ri(generator);

  return random_vec;
}

std::vector<double> random_gen(const int n, const double dummy){
  (void)dummy;

  std::vector<double> random_vec(n);
  for(auto i = 0; i<n; ++i)
    random_vec[i] = rd(generator);

  return random_vec;
}

std::vector<std::string> random_gen(const int n, const std::string& dummy){
  (void)dummy;

  std::vector<std::string> random_vec(n);
  for(auto i = 0; i<n; ++i)
    random_vec[i] = random_string_generator(5);
  
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

  if (argc < 3) {
    std::cerr << "Wrong number of argument. You must call ./analysis.x [DIMENSION] [NUMBER OF CHECKS].\n";
    return 1;
  }

  const int n = atoi(argv[1]);
  const int iter = atoi(argv[2]);

  {
    map<int,double> map_id;
    std::cout << "map<int,double>: " << std::endl;
    test(n, iter, map_id);
  }
  
  {
    map<double,double> map_dd;  
    std::cout << "map<double,double>: " << std::endl;
    test(n, iter, map_dd);
  }
    
  {
    map<std::string,double> map_sd;
    std::cout << "map<string,double>: " << std::endl;
    test(n, iter, map_sd);
  }
  
  {
    map<std::string,std::string> map_ss;
    std::cout << "map<string,string>: " << std::endl;
    test(n, iter, map_ss);
  }
  
  return 0;

}

double func(const int& i, const int& j){
  return i + j;
}

double func(const double& d, const int& j){
  return d + j;
}

double func(const std::string& s, const int& j){
  std::string js = std::to_string(j) + s;
  return (int)js.back();
}

double func2(const int& i, const int& j){
  return i - j;
}

double func2(const double& d, const int& j){
  return d - j;
}

double func2(const std::string& s, const int& j){
  std::string js = std::to_string(j+j) + s;
  return (int)js.back();
}

