#ifndef option_HPP
#define option_HPP

#include "americanStruct.hpp"
#include <vector>

class americanOption
{
protected:
	double o_K;
	double o_r;
	double o_sig;
	double o_b;
public:
	americanOption();					//default constructor
	americanOption(double K, double r, double sig, double b); //constructor that takes in arguments
	americanOption(const americanOption& o);	//copy constructor
	virtual ~americanOption();			//destructor
	
	americanOption& operator = (const americanOption& a); //assignment operator
	//getter and setter functions for variables
	double K() const;
	void K(double setK) {o_K = setK;}
	double r() const;
	void r(double setr) {o_r = setr;}
	double sig() const;
	void sig(double setsig) {o_sig = setsig;}
	double b() const;
	void b(double setb) {o_b = setb;}
	//overloaded pricing functions
	double callPrice(double S);
	double callPrice(americanOptionData o, double S);
	double putPrice(double S);
	double putPrice(americanOptionData o, double S);

	//pricing functions that return vector
	//when S is changing
	std::vector<double> callPrice_S(double S_start, double S_end, double diff);
	std::vector<double> putPrice_S(double S_start, double S_end, double diff);
};

inline double americanOption::K() const{return o_K;}
inline double americanOption::r() const{return o_r;}
inline double americanOption::sig() const{return o_sig;}
inline double americanOption::b() const{return o_b;}



#endif