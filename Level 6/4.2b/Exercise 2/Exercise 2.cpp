#include"numericarray.cpp"
#include<iostream>
using namespace std;

int main()
{
	numericArray<double> iA(10);
	numericArray<double> iA2(10);
	numericArray<double> sum(10);
	numericArray<double> alpha(10);
	numericArray<double> bad(3);
	double dotAns;
	cout << iA.size() << endl;  //the following two lines print 10
	cout << iA2.size() <<endl;

	for (int i = 0; i < iA.size(); i++)
	{
		iA[i] = i;
		iA2[i] = i;
		/*cout << iA[i] << endl;
		cout << iA2[i] << endl;*/
	}
	sum = iA;					
	cout << "test" << sum[9] << endl;
	cout << "done" << endl;

	try
	{
		sum = (iA * 3.0);
		cout << "test multiplication: " << sum[1] << endl;
		sum = iA + iA2;				
		cout << "test sum: " << sum[1] << endl;
		alpha = bad + iA;									    //error
		cout << alpha[3] << endl;
		
	}
	catch(arrayException& out)
	{
		cout << out.getMessage() << endl;
	}
	catch(...)
	{
		cout << "an unhandled exception has occured" << endl;
	}
	try
	{
		cout << iA.dot(iA2) << endl;
		dotAns = iA.dot(iA2);
		cout << "dot product" << dotAns << endl;
		cout << "this shouldn't print" << iA.dot(bad) << endl; //error
	}
	catch(arrayException& out)
	{
		cout << out.getMessage() << endl;
	}
	catch(...)
	{
		cout << "an unhandled exception has occured" << endl;
	}

	
	return 0;
}