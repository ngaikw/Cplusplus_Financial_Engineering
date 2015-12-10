// TestTwoCurve.cpp
//
// Displaying TWO curves on one Excel sheet.
//
// Modification dates:
//
// 2007-3-3 DD Kick-offs
// 2007-7-23 DD Some schemes (e.g. IE added)
// 2007-7-27 DD derivative-free scheme
// 2009-6-14 DD clean up
// 2012-1-17 DD for QN
//
// (C) Datasim Education BV 2005-2012
//


#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"
#include "option.hpp" //make an option object to print prices as function of S
#include "global_functions.hpp"

#include <cmath>
#include <list>
#include <string>

int main()
{
	// DON'T FORGET TO MODIFY EXCELIMPORTS.CPP for correct version of Excel.

	//long N = 40;

	//// Create abscissa x array
	//Vector<double, long> x(N,0.0);
	//double T = 10.0;
	//double h = T/double(N);
	//x[x.MinIndex()] = 0.0;
	//x[x.MaxIndex()] = T;
	//for (long j = x.MinIndex()+1; j <= x.MaxIndex()-1; ++j)
	//{
	//	x[j] = x[j-1] + h;
	//}

	//Vector<double, long> vec1(N,0.0);
	//for (long j = vec1.MinIndex(); j <= vec1.MaxIndex(); ++j)
	//{
	//	vec1[j] = pow(-1.0, j);
	//}

	//Vector<double, long> vec2 = vec1 + 2.0;
	
	option batch1_option(65.0, 0.25, 0.08, 0.3);
	double S = 60.0;
	Vector<double, long> vec1 = batch1_option.callPrice_withExcel(55.0, 75.0, 1.0);
	Vector<double, long> vec2 = batch1_option.putPrice_withExcel(55.0, 75.0, 1.0);
	Vector<double, long> x = meshArray_forExcel(55.0, 75.0, 1.0);
	std::cout << "Data has been created\n";

	try 
	{
		printPairExcel(x,vec1, vec2, 
						string("2 arrays"), string("S"), string("Price"));
	}
	catch(DatasimException& e)
	{
		e.print();
	}

	return 0;
}
