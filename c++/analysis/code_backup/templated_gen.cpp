enum class method { integer, floating_point, string };

std::default_random_engine generator(time(NULL));

std::uniform_int_distribution<int> ri(0,1000);
std::uniform_real_distribution<double> rd(0.0,1.0);
std::string random_string_generator(const int length);

template<typename T>
std::vector<T>& random_vec_gen(const int n){
  
  std::vector<T> random_vec = (n);
  
  method m = 0;
  if (std::is_same<T, int>::value>) { m = method::integer; }
  else if (std::is_same<T, double>::value) { m = method::floating_point; }
  else if (std::is_same<T, std::string>::value) { m = method::string; }
  
  switch (m) {
  case method::integer:
    for(auto i = 0; i<n; ++i)
      random_vec.push_back(ri(generator));
    break;
    
  case method::floating_point:
    for(auto i = 0; i<n; ++i)
      random_vec.push_back(rd(generator));
    break;
    
  case method::integer:
    for(auto i = 0; i<n; ++i)
      random_vec.push_back(random_string_generator(5));
    break;

  default:
    throw std::runtime_error{"Unknown method.\n"};
  };
  
  return random_vec;
}
