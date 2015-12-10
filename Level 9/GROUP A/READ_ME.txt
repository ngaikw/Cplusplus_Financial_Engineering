********
DESCRIPTIONS OF FILES
************
this folder contains formulas applicable to the Black-Scholes stock option model.
b = r.

OPTION CLASS (option.cpp, option.hpp)
option data paramaters are made protected (e.g. K, T, etc.) in the case i want to add derived 
classes and still use the member variables

1. option()				//default constructor
2. option(double K, double T, double r, double sig); //constructor that takes in arguments
3. option(const option& o);	//copy constructor
4. virtual ~option();			//destructor
5. option& operator = (const option& a); //assignment operator

-Getter and setter functions-
6. double K() const;
7. void K(double setK) {o_K = setK;}
8. double T() const;
9. void T(double setT) {o_T = setT;}
10. double r() const;
11. void r(double setr) {o_r = setr;}
12. double sig() const;
13. void sig(double setsig) {o_sig = setsig;}

-overloaded pricing functions-
14. double callPrice(double S);
15. double callPrice(optionData o, double S);
16. double putPrice(double S);
17. double putPrice(optionData o, double S);

//pricing functions that return vector
//when S is changing
18.	std::vector<double> callPrice_S(double S_start, double S_end, double diff) 
19.	std::vector<double> putPrice_S(double S_start, double S_end, double diff);
	
//pricing functions that return vector
// when any other factors are changing
20. std::vector<double> callPrice_T(double S, double start, double end, double diff); 
21. std::vector<double> putPrice_T(double S, double start, double end, double diff);
22. std::vector<double> callPrice_sig(double S, double start, double end, double diff); 
23. std::vector<double> putPrice_sig(double S, double start, double end, double diff);


//put call parity functions
24. double put_Call_Parity_for_Call(double P, double S);
25. double put_Call_Parity_for_Put(double C, double S);

//options sensitivities delta and gamma
26. double deltaCall(double S);
27. std::vector<double> deltaCall(double S_start, double S_end, double diff);
28. double deltaPut(double S);
29. std::vector<double> deltaPut(double S_start, double S_end, double diff);
30. double gammaCall(double S);
31. double gammaPut(double S);

//divided differences
//make a call to the Call and Put price functions, changing input to them.
double deltaCall_divided(double S, double h);
double deltaPut_divided(double S, double h);
double gammaCall_divided(double S, double h);
double gammaPut_divided(double S, double h);


GLOBAL FUNCTIONS:
 "global_function.hpp" and "global_function.cpp"
functions: all formulas taken from homework sheet
1. double N(double x) //to calculate cdf of normal distribution
2. double n(double x) //to calculate pdf of normal distribution
3. double call_Price(double S, double K, double T, double r, double sig) //calculates call_Price
double put_Price(double S, double K, double T, double r, double sig) //calculates put_Price
4. std::vector<double> meshArray(double start, double end, double h) //creates a mesh array with start and end, 
																	//separated by h.
5. double delta_call(double S, double K, double T, double r, double sig) //calculates delta of a call
6. double delta_put(double S, double K, double T, double r, double sig) // calculates delta of a put
7. double gamma(double S, double K, double T, double r, double sig) //calculates gamma of call and put (same formulae)
8. double dividedDifference_first(double (*pricingFormula)(double, double, double, double, double), double S, double K, double T, double r, double sig, double h)
//this calculates divided difference for a function to approximate its first derivative. It takes in the
//function as an argument. It takes in a pointer, then when I use it, I put in the address of the function
9.double dividedDifference_second(double (*pricingFormula)(double, double, double, double, double), double S, double K, double T, double r, double sig, double h);
//this calculates divided differences for a function to approximate its second derivative.
//it also takes in the function as an argument


STRUCT:
I defined the option struct in optionStruct.hpp
It consists of K, T, r, and sig. I assume in all my formulas that b = r, so we do not have a b variable 
inclded here.

**********
ANSWERS TO QUESTIONS:
**********
A.1 (from testA1.cpp)
a)
BATCH 1:
call price: 2.1333684449
put price: 5.8462822099
BATCH 2:
call price: 7.9655674554
put price: 7.9655674554
BATCH 3:
call price: 0.2040578815
put price: 4.0732622487
BATCH 4:
call price: 92.1757038422
put price: 1.2474991712

b)
Batch 1 Test:
Call 2.1333684449
Put 5.8462822099
Batch 2 Test:
Call 7.9655674554
Put 7.9655674554
Batch 3 Test:
Call 0.2040578815
Put 4.0732622487
Batch 4 Test:
Call 92.1757038422
Put 1.2474991712
Batch 1 Test:
call 2.1333684449
put 5.8462822099
Batch 2 Test:
call 7.9655674554
put 7.9655674554
Batch 3 Test:
call 0.2040578815
put 4.0732622487
Batch 4 Test:
call 92.1757038422
put 1.2474991712

c) same
d) using batch 4 data, increment S from 80 to 100 in increments of 2:
call for S: 80 : 72.4432356413
put for S: 80 : 1.5150309702
call for S: 82 : 74.4119876938
put for S: 82 : 1.4837830227
call for S: 84 : 76.3818857660
put for S: 84 : 1.4536810949
call for S: 86 : 78.3528675341
put for S: 86 : 1.4246628630
call for S: 88 : 80.3248752007
put for S: 88 : 1.3966705296
call for S: 90 : 82.2978550834
put for S: 90 : 1.3696504124
call for S: 92 : 84.2717572483
put for S: 92 : 1.3435525773
call for S: 94 : 86.2465351827
put for S: 94 : 1.3183305116
call for S: 96 : 88.2221455017
put for S: 96 : 1.2939408306
call for S: 98 : 90.1985476854
put for S: 98 : 1.2703430143
call for S: 100 : 92.1757038422
put for S: 100 : 1.2474991712

using batch 4 data, increment S from 80 to 100 in increments of 3
call for S: 80 : 72.4432356413
call for S: 83 : 75.3967974839
call for S: 86 : 78.3528675341
call for S: 89 : 81.3112468198
call for S: 92 : 84.2717572483
call for S: 95 : 87.2342388909
call for S: 98 : 90.1985476854

e) using batch 4 data, incrememnt sigma from 0 to 0.3 using intervals of 0.05:
call for sig: 0.0000000000 : 90.9282046711
call for sig: 0.0500000000 : 90.9282046711
call for sig: 0.1000000000 : 90.9282242756
call for sig: 0.1500000000 : 90.9397904577
call for sig: 0.2000000000 : 91.0748790818
call for sig: 0.2500000000 : 91.4834397175
call for sig: 0.3000000000 : 92.1757038422

A.2 (from testA2.cpp)
using data set: K = 100, S = 105, T = 0.5, r = 0.1, b = 0, sig = 0.36
a)
delta of call 'exact': 0.6968505313
delta of put 'exact': -0.3031494687
gamma 'exact': 25.9364259340
b)
call for S = 95.0000000000 is 0.5486291643
call for S = 100.0000000000 is 0.6269165707
call for S = 105.0000000000 is 0.6968505313
c)
aproximation with h = 0.0100000000 : delta for call =  0.6968505250
aproximation with h = 0.1000000000 : delta for call = 0.6968499038