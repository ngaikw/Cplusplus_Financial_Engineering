// TestMultiCurve.cpp
//
// Displaying multple curves on one Excel sheet.
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
	option batch1_option(65.0, 0.25, 0.08, 0.3);
	option batch2_option(100.0, 1.0, 0.0, 0.2);
	option batch3_option(10.0, 1.0, 0.12, 0.5);
	option batch4_option(100.0, 30.0, 0.08, 0.3);
	//set S_Start to 65, S_end to 75, increment by 1
	Vector<double, long> vec1 = batch1_option.callPrice_withExcel(50.0, 100.0, 1.0);
	//create mesh array value array
	Vector<double, long> x = meshArray_forExcel(50.0, 100.0, 1.0);

	Vector<double, long> vec2 = batch2_option.callPrice_withExcel(50.0, 100.0, 1.0);
	Vector<double, long> vec3 = batch3_option.callPrice_withExcel(50.0, 100.0, 1.0);
	Vector<double, long> vec4 = batch4_option.callPrice_withExcel(50.0, 100.0, 1.0);

	// Now Excel output in one sheet for comparison purpposes
	std::list<std::string> labels;							// Names of each vector
	std::list<Vector<double, long > > functionResult;	// The list of Y values

	labels.push_back("call from batch 1");
	labels.push_back("call from batch 2");
	labels.push_back("call from batch 3");
	labels.push_back("call from batch 4");

	functionResult.push_back(vec1);
	functionResult.push_back(vec2);
	functionResult.push_back(vec3);
	functionResult.push_back(vec4); 
	
	std::cout << "Data has been created\n";

	try 
	{
		printInExcel(x,labels, functionResult, 
						string("All In One"), string("S"), string("Value"));
	}
	catch(DatasimException& e)
	{
		e.print();
	}

	return 0;
}
