#ifndef global_functions_HPP
#define global_functions_HPP

#include <vector>

double call_Price(double S, double K,  double r, double sig, double b); 
double put_Price(double S, double K, double r, double sig, double b);
std::vector<double> meshArray(double start, double end, double h); //mesh array with start and end, separated by h

#endif