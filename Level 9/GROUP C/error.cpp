  #include "error.hpp"
#include <iostream>
#include <cmath>
using namespace std;

double standardDev(std::vector<double> Ct, double r, double T)
{
	double M = Ct.size();
	double sum1 = 0;
	double sum2 = 0;
	for (int j = 1; j <= M; j++)
	{
		sum1 += (Ct[j-1] * Ct[j-1]);
		sum2 += Ct[j-1];
	}
	return ((sqrt(sum1 - ((1.0/M) * sum2)) * exp(-2.0 * r * T)) / (M - 1.0));
}

double standardErr(std::vector <double> Ct, double r, double T)
{
	double M = Ct.size();
	double stdDev = standardDev(Ct, r, T);
	return (stdDev / sqrt(M));
}