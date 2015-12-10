#include "americanOption.hpp"
#include "global_functions.hpp"
#include "americanStruct.hpp"

#include <iostream>
#include "stdlib.h"
using namespace std;

americanOption::americanOption()					//default constructor
{ //default values
	o_K = 100.0;
	o_r = 0.1;
	o_sig = 0.1;
	o_b = 0.02;
}
americanOption::americanOption(double K, double r, double sig, double b) //constructor that takes in arguments
{
	o_K = K;
	o_r = r;
	o_sig = sig;
	o_b = b;
}
americanOption::americanOption(const americanOption& o)	//copy constructor
{
	o_K = o.o_K;
	o_r = o.o_r;
	o_sig = o.o_sig;
	o_b = o.o_b;
}

americanOption::~americanOption()			//destructor
{

}

americanOption& americanOption::operator = (const americanOption& a) //assignment operator
{
	if (this != &a)
	{
		o_K = a.o_K;
		o_r = a.o_r;
		o_sig = a.o_sig;
		o_b = a.o_b;
	}
	return *this;
}
//overloaded pricing functions
double americanOption::callPrice(double S)
{
	return call_Price(S, o_K, o_r, o_sig, o_b);
}

double americanOption::callPrice(americanOptionData o, double S)
{
	return call_Price(S, o.K, o.r, o.sig, o.b);
}

double americanOption::putPrice(double S)
{
	return put_Price(S, o_K, o_r, o_sig, o_b);
}

double americanOption::putPrice(americanOptionData o, double S)
{
	return put_Price(S, o.K, o.r, o.sig, o.b);
}

//pricing functions that return vector
//when S is changing
std::vector<double> americanOption::callPrice_S(double S_start, double S_end, double diff)
{
	std::vector<double> S = meshArray(S_start, S_end, diff);
	std::vector<double> price;
	for (int i = 0; i < S.size(); i++) {
		price.push_back(call_Price(S[i], o_K, o_r, o_sig, o_b));
	}
	return price;
}
std::vector<double> americanOption::putPrice_S(double S_start, double S_end, double diff)
{
	std::vector<double> S = meshArray(S_start, S_end, diff);
	std::vector<double> price;
	for (int i = 0; i < S.size(); i++) {
		price.push_back(put_Price(S[i], o_K, o_r, o_sig, o_b));
	}
	return price;
}
