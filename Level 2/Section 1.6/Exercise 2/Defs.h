#include<stdio.h>
#ifndef PRINT1
#define PRINT1(a) (printf("%d\n", a)) 
#endif
#ifndef PRINT2
#define PRINT2(a,b) (printf("%d %d", a, b)) 
#endif
#ifndef MAX2
#define MAX2(x,y) ((x>y)? x: y)
#endif
#ifndef MAX3
#define MAX3(x, y, z) (MAX2(MAX2(x,y), z))
#endif