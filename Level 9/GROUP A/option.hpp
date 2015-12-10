#ifndef option_HPP
#define option_HPP

#include "optionStruct.hpp"
#include <vector>

class option
{
protected:
	double o_K;
	double o_T;
	double o_r;
	double o_sig;
public:
	option();					//default constructor
	option(double K, double T, double r, double sig); //constructor that takes in arguments
	//option(optionData option); //create an overloaded constructor?
	option(const option& o);	//copy constructor
	virtual ~option();			//destructor
	
	option& operator = (const option& a); //assignment operator
	//getter and setter functions for variables
	double K() const;
	void K(double setK) {o_K = setK;}
	double T() const;
	void T(double setT) {o_T = setT;}
	double r() const;
	void r(double setr) {o_r = setr;}
	double sig() const;
	void sig(double setsig) {o_sig = setsig;}

	//overloaded pricing functions
	double callPrice(double S);
	double callPrice(optionData o, double S);
	double putPrice(double S);
	double putPrice(optionData o, double S);

	//pricing functions that return vector
	//when S is changing
	std::vector<double> callPrice_S(double S_start, double S_end, double diff);
	std::vector<double> putPrice_S(double S_start, double S_end, double diff);
	//when any other factors are changing
	std::vector<double> callPrice_T(double S, double start, double end, double diff); 
	std::vector<double> putPrice_T(double S, double start, double end, double diff);
	std::vector<double> callPrice_sig(double S, double start, double end, double diff); 
	std::vector<double> putPrice_sig(double S, double start, double end, double diff);


	//put call parity functions
	double put_Call_Parity_for_Call(double P, double S);
	double put_Call_Parity_for_Put(double C, double S);

	//options sensitivities delta and gamma
	double deltaCall(double S);
	std::vector<double> deltaCall(double S_start, double S_end, double diff);
	double deltaPut(double S);
	std::vector<double> deltaPut(double S_start, double S_end, double diff);

	double gammaCall(double S);
	double gammaPut(double S);

	//divided differences
	//make a call to the Call and Put price functions, changing input to them.
	double deltaCall_divided(double S, double h);
	double deltaPut_divided(double S, double h);

	double gammaCall_divided(double S, double h);
	double gammaPut_divided(double S, double h);

};

inline double option::K() const{return o_K;}
inline double option::T() const{return o_T;}
inline double option::r() const{return o_r;}
inline double option::sig() const{return o_sig;}



#endif