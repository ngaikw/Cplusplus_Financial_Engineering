#include "global_functions.hpp"
#include <iostream>
#include <cmath>
using namespace std;


double call_Price(double S, double K, double r, double sig, double b) 
{
	double y1 = 0.5 - (b / (sig * sig)) + sqrt( ((b/(sig * sig)) - 0.5)* ((b/(sig * sig)) - 0.5)  + (2 * r)/(sig * sig) );
	return (K / (y1 - 1.0)) * pow( ( ((y1 - 1.0) * S)/(y1 * K) ), y1 );
}
double put_Price(double S, double K, double r, double sig, double b)
{
	double y2 = 0.5 - (b / (sig * sig)) - sqrt( ((b/(sig * sig)) - 0.5)* ((b/(sig * sig)) - 0.5)  + (2 * r)/(sig * sig) );
	return (K / (1.0 - y2)) * pow( ( ((y2 - 1.0) * S)/(y2 * K) ), y2 );
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

