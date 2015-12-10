#include "global_functions.hpp"
#include "americanStruct.hpp"
#include "americanOption.hpp"
#include <iostream>

using namespace std;

int main()
{
	//********
	//PART B
	cout << "part b" << endl;
	double K, sig, r, b, S;
	K = 100.0;
	sig = 0.1;
	r = 0.1;
	b = 0.02;
	S = 110;
	americanOption a_1(K, r, sig, b);
	cout << "call price = " << a_1.callPrice(S) << endl;
	cout << "put price = " << a_1.putPrice(S) << endl;
	americanOptionData struct_1;
	struct_1.K = K;
	struct_1.sig = sig;
	struct_1.r = r;
	struct_1.b = b;
	cout << "call price with struct = " << a_1.callPrice(struct_1, S) << endl;
	cout << "put price with struct = " << a_1.putPrice(struct_1, S) << endl;

	//**********
	//PART C
	cout << "part c: " << endl;
	std::vector<double> temp = a_1.callPrice_S(100.0, 110.0, 2.0);
	std::vector<double> temp2 = a_1.putPrice_S(100.0, 110.0, 2.0);
	for (int i = 0; i <= (10/2); i++)
	{
		cout << "call for S = " << 100 + 2.0 * i << " is " << temp[i] << endl;
		cout << "put for S = " << 100 + 2.0 * i << " is " << temp2[i] << endl;
	}
	return 0;
}