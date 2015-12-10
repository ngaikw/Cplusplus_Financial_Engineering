#include<stdio.h>
#ifndef PRINT1
#define PRINT1(a) (printf("%d\n", a)) 
#endif
#ifndef PRINT2
#define PRINT2(a,b) (printf("%d %d", a, b)) 
#endif