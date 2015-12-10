#include "option.hpp"
#include "option_Pricing.hpp"
#include <iostream>

using namespace std;
//global variables
double T, K, sig, r, S;

//the following function sets the variables accordingly based on their batch
void batch_Test(double T_set, double K_set, double sig_set, double r_set, double S_set)
{
	T = T_set;
	K = K_set;
	sig = sig_set;
	r = r_set;
	S = S_set;
}


int main()
{
	//************
	//TEST PART A
	//************
	//create global functions for calls and puts
	//Batch Test 1
	cout.precision(10);
	cout << "Batch 1 Test:" << endl;
	batch_Test(0.25, 65, 0.3, 0.08, 60);
	option o_1(K, T, r, sig);
	cout << "call price: "<< fixed << o_1.callPrice(S) << endl;
	cout << "put price: " << o_1.putPrice(S) << endl;

	//Batch Test 2
	cout << "Batch 2 Test:" << endl;
	batch_Test(1.0, 100.0, 0.2, 0.0, 100.0);
	option o_2(K, T, r, sig);
	cout << "call price: " << o_2.callPrice(S) << endl;
	cout << "put price: " << o_2.putPrice(S) << endl;

	//Batch Test 3
	cout << "Batch 3 Test:" << endl;
	batch_Test(1.0, 10.0, 0.5, 0.12, 5.0);
	option o_3(K, T, r, sig);
	cout << "call price: " << o_3.callPrice(S) << endl;
	cout << "put price: " << o_3.putPrice(S) << endl;

	//Batch Test 4
	cout << "Batch 4 Test:" << endl;
	batch_Test(30.0, 100.0, 0.3, 0.08, 100.0);
	option o_4(K, T, r, sig);
	cout << "call price: " << o_4.callPrice(S) << endl;
	cout << "put price: " << o_4.putPrice(S) << endl;

	//************
	//TEST PART B
	//************
	//put call parity
	cout << "PART B:" << endl;

	//Batch Test 1
	cout << "Batch 1 Test:" << endl;
	batch_Test(0.25, 65, 0.3, 0.08, 60);
	cout << "Call " << o_1.put_Call_Parity_for_Call(o_1.putPrice(S), S) << endl;
	cout << "Put " << o_1.put_Call_Parity_for_Put(o_1.callPrice(S), S) << endl;

	//Batch Test 2
	cout << "Batch 2 Test:" << endl;
	batch_Test(1.0, 100.0, 0.2, 0.0, 100.0);
	cout << "Call " << o_2.put_Call_Parity_for_Call(o_2.putPrice(S), S) << endl;
	cout << "Put " << o_2.put_Call_Parity_for_Put(o_2.callPrice(S), S) << endl; 

	//Batch Test 3
	cout << "Batch 3 Test:" << endl;
	batch_Test(1.0, 10.0, 0.5, 0.12, 5.0);
	cout << "Call " << o_3.put_Call_Parity_for_Call(o_3.putPrice(S), S) << endl;
	cout << "Put " << o_3.put_Call_Parity_for_Put(o_3.callPrice(S), S) << endl;

	//Batch Test 4
	cout << "Batch 4 Test:" << endl;
	batch_Test(30.0, 100.0, 0.3, 0.08, 100.0);
	cout << "Call " << o_4.put_Call_Parity_for_Call(o_4.putPrice(S), S) << endl;
	cout << "Put " << o_4.put_Call_Parity_for_Put(o_4.callPrice(S), S) << endl;

	//************
	//TEST PART C
	//************
	//using struct
	optionData o;
	//Batch Test 1
	cout << "Batch 1 Test:" << endl;
	batch_Test(0.25, 65, 0.3, 0.08, 60);
	o.T = T;
	o.K = K;
	o.r = r;
	o.sig = sig;
	cout << "call " << o_1.callPrice(o, S) << endl;
	cout << "put " << o_1.putPrice(o, S) << endl;

	//Batch Test 2
	cout << "Batch 2 Test:" << endl;
	batch_Test(1.0, 100.0, 0.2, 0.0, 100.0);
	o.T = T;
	o.K = K;
	o.r = r;
	o.sig = sig;
	cout << "call " << o_2.callPrice(o, S) << endl;
	cout << "put " << o_2.putPrice(o, S) << endl;
	//Batch Test 3
	cout << "Batch 3 Test:" << endl;
	batch_Test(1.0, 10.0, 0.5, 0.12, 5.0);
	o.T = T;
	o.K = K;
	o.r = r;
	o.sig = sig;
	cout << "call " << o_3.callPrice(o, S) << endl;
	cout << "put " << o_3.putPrice(o, S) << endl;

	//Batch Test 4
	cout << "Batch 4 Test:" << endl;
	batch_Test(30.0, 100.0, 0.3, 0.08, 100.0);
	o.T = T;
	o.K = K;
	o.r = r;
	o.sig = sig;
	cout << "call " << o_4.callPrice(o, S) << endl;
	cout << "put " << o_4.putPrice(o, S) << endl;

	//************
	//TEST PART D
	//************
	//test mesher global function and new overrided pricing functions th
	cout << "PART D" << endl;
	//print S = 80 to 100 in increments of 2 using batch 4 data
	std::vector<double> temp  = o_4.callPrice_S(80, 100, 2);
	std::vector<double> temp2 = o_4.putPrice_S(80, 100, 2);
	std::vector<double> temp3 = o_4.callPrice_S(80, 100, 3);
	for (int i = 0; i <= ((100-80)/2); i++)
	{
		cout << "call for S: " << 80 + 2*i << " : " << temp[i] << endl;
		cout << "put for S: " << 80 + 2*i << " : " << temp2[i] << endl;
	}
	for (int i = 0; i <= ((100-80)/3); i++)
	{
		cout << "call for S: " << 80 + 3*i << " : " << temp3[i] << endl;
	}
	//************
	//TEST PART E
	//************
	//test overrided pricing functions where T and sig change instead of S
	//change T
	std::vector<double> temp5 = o_4.callPrice_sig(S, 0, 0.3, 0.05);
	for (int i = 0; i <= 6; i++)
	{
		cout << "call for sig: " << 0.05 * i << " : " << temp5[i] << endl;
		
	}
}