*******************PART A****************************

I integrated the standard deviation and standard error formulas given in the homework in the files 
"error.hpp" and "error.cpp"

I save all j prices in a priceVector, and then use this priceVector as an input to the forumlas for standard
deviation and standard error.

Some examples of output I get:
Number of subintervals in time: 1000
Number of simulations: 10000
10000
Price, after discounting: 8.09396,
Number of times origin is hit: 0
K = 100.
T = 1.
r = 0.
sig = 0.2.
type = -1.
S = 100.
standard deviation is: 0.0820479
error is: 0.000820479

increasing simulations to 20000, I get
standard deviation is: 0.05742
error is: 0.000406021

*****************************PART B*******************************
I printed results in group c .txt files already. I used 10,000,000 simulations and still could only get accuracy to the second digit.
