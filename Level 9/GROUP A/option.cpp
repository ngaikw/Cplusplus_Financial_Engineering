#include "option.hpp"
#include "global_functions.hpp"

#include <iostream>
#include "stdlib.h"
using namespace std;

option::option()
{
	//default values
	o_r = 0.05;
	o_sig = 0.2;
	o_K = 110.0;
	o_T = 0.5;
}
option::option(double K, double T, double r, double sig) //constructor that takes in arguments
{
	o_K = K;
	o_T = T;
	o_r = r;
	o_sig = sig;
}
	//option(optionData option); //create an overloaded constructor?

option::option(const option& o)	//copy constructor
{
	o_K = o.o_K;
	o_T = o.o_T;
	o_r = o.o_r;
	o_sig = o.o_sig;
}
option::~option()			//destructor
{
}

option& option::operator = (const option& a)
{
	if (this != &a)
	{
		o_K = a.o_K;
		o_T = a.o_T;
		o_r = a.o_r;
		o_sig = a.o_sig;
	}
	return *this;
}

double option::callPrice(double S)
{
	return call_Price(S, o_K, o_T, o_r, o_sig);
}

double option::callPrice(optionData o, double S)
{
	return call_Price(S, o.K, o.T, o.r, o.sig);
}

double option::putPrice(double S)
{
	return put_Price(S, o_K, o_T, o_r, o_sig);
}

double option::putPrice(optionData o, double S)
{
	return put_Price(S, o.K, o.T, o.r, o.sig);
}

std::vector<double> option::callPrice_S(double S_start, double S_end, double diff)
{
	std::vector<double> S = meshArray(S_start, S_end, diff);
	std::vector<double> price;
	for (int i = 0; i < S.size(); i++) {
		price.push_back(call_Price(S[i], o_K, o_T, o_r, o_sig));
	}
	return price;
}

std::vector<double> option::putPrice_S(double S_start, double S_end, double diff)
{
	std::vector<double> S = meshArray(S_start, S_end, diff);
	std::vector<double> price;
	for (int i = 0; i < S.size(); i++) {
		price.push_back(put_Price(S[i], o_K, o_T, o_r, o_sig));

	}
	return price;
}

std::vector<double> option::callPrice_T(double S, double start, double end, double diff)
{
	std::vector<double> T = meshArray(start, end, diff);
	std::vector<double> price;
	for (int i = 0; i < T.size(); i++)
	{
		o_T = T[i];
		price.push_back(call_Price(S, o_K, o_T, o_r, o_sig));
	}
	return price;
}

std::vector<double> option::putPrice_T(double S, double start, double end, double diff)
{
	std::vector<double> T = meshArray(start, end, diff);
	std::vector<double> price;
	for (int i = 0; i < T.size(); i++)
	{
		o_T = T[i];
		price.push_back(put_Price(S, o_K, o_T, o_r, o_sig));
	}
	return price;
}

std::vector<double> option::callPrice_sig(double S, double start, double end, double diff)
{
	std::vector<double> sig = meshArray(start, end, diff);
	std::vector<double> price;
	for (int i = 0; i < sig.size(); i++)
	{
		o_sig = sig[i];
		price.push_back(call_Price(S, o_K, o_T, o_r, o_sig));
	}
	return price;

}

std::vector<double> option::putPrice_sig(double S, double start, double end, double diff)
{	
	std::vector<double> sig = meshArray(start, end, diff);
	std::vector<double> price;
	for (int i = 0; i < sig.size(); i++)
	{
		o_sig = sig[i];
		cout << o_sig << endl;
		price.push_back(put_Price(S, o_K, o_T, o_r, o_sig));
	}
	return price;
}

double option::put_Call_Parity_for_Call(double P, double S)
{
	return P + S - (o_K * exp(-o_r * o_T));
}
double option::put_Call_Parity_for_Put(double C, double S)
{
	return C + (o_K * exp(-o_r * o_T)) - S;
}

double option::deltaCall(double S)
{
	return delta_call(S, o_K, o_T, o_r, o_sig); 
}

std::vector<double> option::deltaCall(double S_start, double S_end, double diff)
{
	std::vector<double> S = meshArray(S_start, S_end, diff);
	std::vector<double> delta;
	for (int i = 0; i < S.size(); i++)
	{
		delta.push_back(delta_call(S[i], o_K, o_T, o_r, o_sig));
	}
	return delta;
}

double option::deltaPut(double S)
{
	return delta_put(S, o_K, o_T, o_r, o_sig); 
}

std::vector<double> option::deltaPut(double S_start, double S_end, double diff)
{
	std::vector<double> S = meshArray(S_start, S_end, diff);
	std::vector<double> delta;
	for (int i = 0; i < S.size(); i++)
	{
		delta.push_back(delta_put(S[i], o_K, o_T, o_r, o_sig));
	}
	return delta;
}

double option::gammaCall(double S)
{
	return gamma(S, o_K, o_T, o_r, o_sig); 
}

double option::gammaPut(double S)
{
	return gamma(S, o_K, o_T, o_r, o_sig); 
}

//divided difference formulas
double option::deltaCall_divided(double S, double h)
{
	return dividedDifference_first(&call_Price, S, o_K, o_T, o_r, o_sig, h);
}

double option::deltaPut_divided(double S, double h)
{
	return dividedDifference_first(&put_Price, S, o_K, o_T, o_r, o_sig, h);
}

double option::gammaCall_divided(double S, double h)
{
	return dividedDifference_second(&call_Price, S, o_K, o_T, o_r, o_sig, h);
}

double option::gammaPut_divided(double S, double h)
{
	return dividedDifference_second(&put_Price, S, o_K, o_T, o_r, o_sig, h);
}