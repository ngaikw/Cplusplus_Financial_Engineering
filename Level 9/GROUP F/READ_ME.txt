The FDM project takes the strike price, and estimates the put price 
using FDM for S = 1 to S = 5 * K. 

For call prices, I added a return 0 for call for lower bound, and return K*exp(-r*t) for upper bound (which is the wrong
upper bound), then changed the payoff function to that of a call. Then I made 8 separate excel files. These are in the folder
"wrong upper bound" 
Copied and pasted code below:
double myBCL (double t)		
{
	// Put
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
}

double myIC (double x)
{ // Payoff 
	
	// Put
	return max(K - x, 0.0);
	////Call
	//return max(x - K, 0.0);

}

Then, I read the notes on FDM and realized I have the wrong upper bound for the call. So I changed the upper bound to 5*BS::K.
The excel files that resulted are in the main folder.

********COMPARISONS*************
for all batches, the call price calculated matched the given call prices for the specified underlying assets from part A to 
two decimal places. This is very good compared to the Monte Carlo Simulations, where I would wait hours to get the same
accuracy.

batch 4 has an issue with N = 10,000. Thus I raised it to 1,000,000 but my call prices did not match remotely to what they
were supposed to be using my wrong upper bound.
After I changed the code so that the upper bound for the call was: 5*BS::K, I got the call price to be 97.12 instead of 92.17, 
but the graph doesn't look right.
For the put price, I got a ~1.20 instead of 1.25


I saved all excel files to this folder.
