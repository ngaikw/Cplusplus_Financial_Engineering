// TestBSPDE1.cpp
//
// Testing 1 factor BS model.
//
// (C) Datasim Education BV 2005-2011
//

#include "FdmDirector.hpp"

#include <iostream>
#include <string>
using namespace std;

#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"

namespace BS // Black Scholes
{
	////batch1:
	//double sig = 0.3;
	//double K = 65.0;
	//double T = 0.25;
	//double r = 0.08;
	//double D = 0.0; // aka q
	////batch 2:
	//double sig = 0.2;
	//double K = 100.0;
	//double T = 1.0;
	//double r = 0.0;
	//double D = 0.0; // aka q
	////batch 3:
	//double sig = 0.5;
	//double K = 10.0;
	//double T = 1.0;
	//double r = 0.12;
	//double D = 0.0; // aka q
	//batch 4:
	double sig = 0.3;
	double K = 100.0;
	double T = 30.0;
	double r = 0.08;
	double D = 0.0; // aka q

	double mySigma (double x, double t)
	{

		double sigmaS = sig*sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu (double x, double t)
	{
		
		return (r - D) * x;
	
	}

	double myB (double x, double t)
	{	
	
		return  -r;
	}

	double myF (double x, double t)
	{
		return 0.0;
	}

	double myBCL (double t)		
	{
		 //Put
		return K *exp(-r * t);
		////Call
		//return 0.0;
	}

	double myBCR (double t)
	{
			
		// Put
		return 0.0; // P
		////Call
		//return K * exp(-r * t);
		//return 5*BS::K;
		
	}

	double myIC (double x)
	{ // Payoff 
	
		// Put
		return max(K - x, 0.0);
		//Call
		//return max(x - K, 0.0);

	}

}


int main()
{
	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	int J= 5*BS::K; int N = 1000000; // k = O(h^2) !!!!!!!!!

	double Smax = 5*BS::K;			// Magix

	cout << "start FDM\n";
	FDMDirector fdir(Smax, BS::T, J, N);

	fdir.doit();
	
	cout << "Finished\n";
	//fdir.current() put price. get t from tarr (fdir.tarr )


	//Vector<double, long> callPrice(fdir.xarr.Size(), fdir.xarr.MinIndex()); // initialize call Price vector to be like put Price vector
	//for (int n = fdir.tarr.MinIndex(); n <= fdir.tarr.MaxIndex(); ++n)
	//{
	//	callPrice[n] = fdir.current()[n] + fdir.xarr[n] - BS::K * exp(-BS::r * fdir.tarr[n]); //put call parity formula
	//}

	// Have you Excel installed (ExcelImports.cpp)
	//printOneExcel(fdir.xarr, callPrice, string("Value"));
	printOneExcel(fdir.xarr, fdir.current(), string("Value"));
	//printPairExcel(fdir.xarr, fdir.current(), 

	return 0;
}
