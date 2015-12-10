/*
Exercise 4: Random Number Generation.

Simulate dice throwing. use functionality in Random library by creating 
a discrete uniform random number generator whose
outcomes are in the closed range [1,6]
*/
#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>			// std::time
#include <boost/Random/detail/const_mod.hpp> // LCG class
#include <map>
#include <cmath>

using namespace std;

int main()
{
	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;
	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1,6);

	//create a map that holds the frequency of each outcome
	map<int, long> statistics; // Structure to hold outcome + frequencies
	int outcome; // Current outcome

	//an outcome is generated with
	//outcome = six(myRng);
	
	//cout << outcome << endl;

	//create an experiment
	long trials, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;
	cout << "How many trials?" << endl; //ask user for number of trials
	cin >> trials;

	for (int i = 0; i < trials; i++)
	{
		outcome = six(myRng);
		statistics[outcome]++;
	}

	for (int i = 1; i <=6; i++)
	{
		cout <<"roll " << i << " had outcome " << (double) statistics[i]/trials << endl;
	}
	return 0;
}