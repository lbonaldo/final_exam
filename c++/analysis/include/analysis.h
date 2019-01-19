#include "map.h"
#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <vector>
#include <map>

std::default_random_engine generator(time(NULL));

std::uniform_int_distribution<int> ri(0,1000);
std::uniform_real_distribution<double> rd(0.0,1.0);
std::string random_string_generator(const int length);

template <typename T1, typename T2>
void test(const int&, const int&, map<T1,T2>&);

std::vector<int> random_gen(const int n, const int dummy);
std::vector<double> random_gen(const int n, const double dummy);
std::vector<std::string> random_gen(const int n, const std::string& dummy);

double func(const int& i, const int& j);
double func(const double& d, const int& j);
double func(const std::string& s, const int& j);

double func2(const int& i, const int& j);
double func2(const double& d, const int& j);
double func2(const std::string& s, const int& j);
