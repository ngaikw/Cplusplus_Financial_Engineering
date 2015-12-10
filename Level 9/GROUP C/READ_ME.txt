I modified the TestMC code to print output to a text file. 
The text files contain the number of simulations in factors
of 10,000 and the prices associated with that many simulations.

text files:
"results batch1 call.txt", "results batch1 put.txt", 
"results batch2 call.txt", "results batch2 put.txt",
"results batch4 call.txt", "results batch4 put.txt"

the text files list the option properties, number of subintervals, and number of simulations in the beginning. the text file subsequently lists all the prices up untill the final number of simulations, of doing simulations in factors of 10,000.


i did simulations of 10,000,000 with subinterval of 1000 and 1500, but the only accuracy I could achieve was to the second decimal digit.
batch 4 results were not so good. I did 15,000,000 simulations with subinterval 1500 and didn't even get accuracy to the first decimal digit. For batch 4 put, I also did 15,000,000 simulations, with subinterval 1000 and got accuracy to the first decimal digit only.
I didn't repeat experiments to try and get better numbers due to time constraints.

Conclusion: Monte Carlo Simulations are not worth the time they take in achieving accuracy.