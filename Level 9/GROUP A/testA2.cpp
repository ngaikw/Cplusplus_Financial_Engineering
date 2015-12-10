#include"option.hpp"
#include"global_functions.hpp"
#include<iostream>

using namespace std;

int main()
{
	double K, S, T, r, sig;
	//*************
	//PART A
	cout.precision(10);
	K = 100;
	S = 105;
	T = 0.5;
	r = 0.1;
	sig = 0.36;
	cout<< "part a" << endl;
	option o_1(K, T, r, sig);
	cout << "delta of call 'exact': " << fixed << o_1.deltaCall(S) <<endl;
	cout << "delta of put 'exact': " << fixed << o_1.deltaPut(S) << endl;
	cout << "gamma 'exact': " << fixed << o_1.gammaCall(S) << endl;


	//**************
	//PART B
	//compute delta for increasing S
	cout << "part b" << endl;
	std::vector<double> answer = o_1.deltaCall(95.0, 105.0, 5.0);
	for (int i = 0; i <= 2; i++)
	{
		cout << "call for S: "<< 95.0 + i*5.0 << " = "<< answer[i] << endl;
	}

	//*************
	//PART C
	//divided difference forumals.
	cout << "PART C" << endl;
	double h = .01;
	cout << "aproximation with h = " << h << " : delta for call =  " << fixed << o_1.deltaCall_divided(S, h) << endl;
	h = .1;
	cout << "aproximation with h = " << h << " : delta for call = " << fixed << o_1.deltaCall_divided(S, h) << endl;
	return 0;
}