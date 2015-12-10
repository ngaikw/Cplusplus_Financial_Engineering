*********************
DESCRIPTIONS OF FILES
*********************

this folder contains formulas for american options

AMERICAN OPTION CLASS
I didn't extend this from the option class because it uses and doesn't
use some variables, so I thought this would be easier

protected variables:
K, r, sig, b

1.americanOption();					//default constructor
2.americanOption(double K, double r, double sig, double b); //constructor that takes in arguments
3. americanOption(const americanOption& o);	//copy constructor
4.virtual ~americanOption();			//destructor
5. americanOption& operator = (const americanOption& a); //assignment operator

//getter and setter functions for variables
6.double K() const;
7.void K(double setK) {o_K = setK;}
8.double r() const;
9.void r(double setr) {o_r = setr;}
10.double sig() const;
11.void sig(double setsig) {o_sig = setsig;}
12.double b() const;
13.void b(double setb) {o_b = setb;}

//overloaded pricing functions
14.double callPrice(double S);
15.double callPrice(americanOptionData o, double S);
16.double putPrice(double S);
17.double putPrice(americanOptionData o, double S);

//pricing functions that return vector
//when S is changing
18.std::vector<double> callPrice_S(double S_start, double S_end, double diff);
19.std::vector<double> putPrice_S(double S_start, double S_end, double diff);

GLOBAL FUNCTIONS(global_functions.hpp, and "global_functions.cpp")

1.double call_Price(double S, double K,  double r, double sig, double b); //call price
2.double put_Price(double S, double K, double r, double sig, double b); //put price
3.std::vector<double> meshArray(double start, double end, double h); //mesh array with start and end, separated by h

STRUCT:
I defined the option struct in americanStruct.hpp
It consists of K, r, sig and b. 

**********
ANSWERS TO QUESTIONS:
**********

1b)call price = 18.5035
put price = 3.03106
call price with struct = 18.5035
put price with struct = 3.03106

1c)go from 100 to 110 in increments of 2.
call for S = 100 is 13.6174
put for S = 100 is 5.48192
call for S = 102 is 14.5131
put for S = 102 is 4.84691
call for S = 104 is 15.4486
put for S = 104 is 4.29572
call for S = 106 is 16.4249
put for S = 106 is 3.81598
call for S = 108 is 17.4429
put for S = 108 is 3.39733
call for S = 110 is 18.5035
put for S = 110 is 3.03106