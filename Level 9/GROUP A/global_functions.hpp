#ifndef global_functions_HPP
#define global_functions_HPP

#include <vector>

double N(double x);
double n(double x);
double call_Price(double S, double K, double T, double r, double sig); 
double put_Price(double S, double K, double T, double r, double sig);
std::vector<double> meshArray(double start, double end, double h); //mesh array with start and end, separated by h
double delta_call(double S, double K, double T, double r, double sig);
double delta_put(double S, double K, double T, double r, double sig);
double gamma(double S, double K, double T, double r, double sig);
double dividedDifference_first(double (*pricingFormula)(double, double, double, double, double), double S, double K, double T, double r, double sig, double h);
double dividedDifference_second(double (*pricingFormula)(double, double, double, double, double), double S, double K, double T, double r, double sig, double h);


#endif