// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//

#include "OptionData.hpp" 
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.cpp"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

#include "error.hpp"

template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors
	
	std::cout << std::endl << "Size of vector is " << l.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
			std::cout << *i << ",";

	}

	std::cout << "]\n";
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term
	
		return (data->r)*X; // r - D
	}

	
	double diffusion(double t, double X)
	{ // Diffusion term
	
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);
		
	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method
	
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace


int main()
{
	std::cout <<  "1 factor MC with explicit Euler\n";
	std::vector<double> priceVector; 
	OptionData myOption;
	////BATCH 1 PUT
	myOption.K = 65.0;
	myOption.T = 0.25;
	myOption.r = 0.08;
	myOption.sig = 0.3;
	myOption.type = -1;	// Put -1, Call +1
	double S_0 = 60;
	//BATCH 1 CALL
	//myOption.K = 65.0;
	//myOption.T = 0.25;
	//myOption.r = 0.08;
	//myOption.sig = 0.3;
	//myOption.type = 1;	// Put -1, Call +1
	//double S_0 = 60;
	//BATCH 2 PUT
	//myOption.K = 100.0;
	//myOption.T = 1.0;
	//myOption.r = 0.0;
	//myOption.sig = 0.2;
	//myOption.type = -1;	// Put -1, Call +1j
	//double S_0 = 100;
	////BATCH 2 CALL
	//myOption.K = 100.0;
	//myOption.T = 1.0;
	//myOption.r = 0.0;
	//myOption.sig = 0.2;
	//myOption.type = 1;	// Put -1, Call +1
	//double S_0 = 100;

	////BATCH 4 PUT
	//myOption.K = 100.0;
	//myOption.T = 30.0;
	//myOption.r = 0.08;
	//myOption.sig = 0.3;
	//myOption.type = -1;	// Put -1, Call +1
	//double S_0 = 100;

	//BATCH 4 CALL
	//myOption.K = 100.0;
	//myOption.T = 30.0;
	//myOption.r = 0.08;
	//myOption.sig = 0.3;
	//myOption.type = 1;	// Put -1, Call +1
	//double S_0 = 100;

	ofstream myfile;
	myfile.open("results.txt");
	myfile << "K = " << myOption.K << ".\n";
	myfile << "T = " << myOption.T << ".\n";
	myfile << "r = " << myOption.r << ".\n";
	myfile << "sig = " << myOption.sig << ".\n";
	myfile << "type = " << myOption.type << ".\n";
	myfile << "S = " << S_0 << ".\n";

	long N = 100;
	std::cout << "Number of subintervals in time: ";
	std::cin >> N;

	myfile << "number of subintervals = " << N << ".\n";

	// Create the basic SDE (Context class)
	Range<double> range (0.0, myOption.T);
	double VOld = S_0;
	double VNew;

	Vector<double, long> x = range.mesh(N);
	

	// V2 mediator stuff
	long NSim = 50000;
	std::cout << "Number of simulations: ";
	std::cin >> NSim;
	myfile << "number of simulations = " << NSim << ".\n";

	double k = myOption.T / double (N);
	double sqrk = sqrt(k);

	// Normal random number
	double dW;
	double price = 0.0;	// Option price
	double tempPrice = 0.0; //temp price to print option prices into file

	// NormalGenerator is a base class
	NormalGenerator* myNormal = new BoostNormal();

	using namespace SDEDefinition;
	data = &myOption;

	Vector<double> res;
	int coun = 0; // Number of times S hits origin

	// A.
	for (long i = 1; i <= NSim; ++i)
	{ // Calculate a path at each iteration

		VOld = S_0;
		for (long index = x.MinIndex()+1; index <= x.MaxIndex(); ++index)
		{

			// Create a random number
			dW = myNormal->getNormal();
				
			// The FDM (in this case explicit Euler)
			VNew = VOld  + (k * drift(x[index-1], VOld))
						+ (sqrk * diffusion(x[index-1], VOld) * dW);

			VOld = VNew;

			// Spurious values
			if (VNew <= 0.0) coun++;
		}
			
		double tmp = myOption.myPayOffFunction(VNew);
		price += (tmp)/double(NSim);

		tempPrice += tmp; //just get the running total of prices in temp price

		//priceVector.push_back(price *= exp(-myOption.r * myOption.T));
		if ((i/10000) * 10000 == i)
		{// Give status after each 1000th iteration

				std::cout << i << std::endl;
				myfile << "simulation number: " << i << ".\n";
				//after getting total of prices, divide by the simulation number to get the price
				myfile << "price = " << (tempPrice / double(i) )* exp(-myOption.r * myOption.T) << ".\n"; 
		}
		
	}
	
	// D. Finally, discounting the average price
	price *= exp(-myOption.r * myOption.T);

	// Cleanup; V2 use scoped pointer
	delete myNormal;

	myfile << "Final Price after discounting for " << NSim << " simulations = " << price << ".\n";
	myfile << "Number of times origin is hit: " << coun <<".\n";
	std::cout << "Price, after discounting: " << price << ", " << std::endl;
	std::cout << "Number of times origin is hit: " << coun << endl;

	myfile.close();
	return 0;
}