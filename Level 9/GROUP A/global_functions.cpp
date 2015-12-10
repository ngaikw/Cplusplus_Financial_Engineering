#include "global_functions.hpp"
#include <iostream>
#include <cmath>
#include <boost/math/distributions/normal.hpp>
using namespace std;
using namespace boost::math;

double N(double x) //function to return the cdf of x
{
	normal_distribution<>myNormal(0.0, 1.0);
	return cdf(myNormal, x);
}

double n(double x) //function to return derivative pdf of x
{
	normal_distribution<> myNormal(0.0, 1.0);
	return pdf(myNormal, x);
}

double call_Price(double S, double K, double T, double r, double sig) 
{
	double d1 = ( log(S / K) + ((r  + ( (sig * sig) / 2.0) ) * T ) ) / (sig * sqrt(T));
	double d2 = ( log(S / K) + ((r  - ( (sig * sig) / 2.0) ) * T ) ) / (sig * sqrt(T));
	return ((N(d1)) * S) - (K * exp(-r * T) * N(d2));
}
double put_Price(double S, double K, double T, double r, double sig)
{
	double d1 = ( log(S / K) + ((r  + ( (sig * sig) / 2.0) ) * T ) ) / (sig * sqrt(T));
	double d2 = ( log(S / K) + ((r  - ( (sig * sig) / 2.0) ) * T ) ) / (sig * sqrt(T));
	return (N(-d2) * K * exp(-r * T)) - (S * N(-d1));
}

std::vector<double> meshArray(double start, double end, double h)
{
	double temp = start;
	std::vector<double> v; //create the vector
	while(temp <= end){
		v.push_back(temp);
		temp +=h;
	}
	return v;
}

double delta_call(double S, double K, double T, double r, double sig)
{
	double d1 = ( log(S / K) + ((r  + ( (sig * sig) / 2.0) ) * T ) ) / (sig * sqrt(T));
	return N(d1);
}

double delta_put(double S, double K, double T, double r, double sig)
{
	double d1 = ( log(S / K) + ((r  + ( (sig * sig) / 2.0) ) * T ) ) / (sig * sqrt(T));
	return -N(-d1);
}

double gamma(double S, double K, double T, double r, double sig)
{
	double d1 = ( log(S / K) + ((r  + ( (sig * sig) / 2.0) ) * T ) ) / (sig * sqrt(T));
	return n(d1) * S * sqrt(T);
}

double dividedDifference_first(double (*pricingFormula)(double, double, double, double, double), double S, double K, double T, double r, double sig, double h)
{
	return ( (pricingFormula(S + h, K, T, r, sig)) - (pricingFormula(S - h, K, T, r, sig)) ) / (2 * h);
}

double dividedDifference_second(double (*pricingFormula)(double, double, double, double, double), double S, double K, double T, double r, double sig, double h)
{
	return (((pricingFormula(S + h, K, T, r, sig)) - 2 * (pricingFormula(S, K, T, r, sig)) + (pricingFormula(S - h, K, T, r, sig)))/ h * h);
}