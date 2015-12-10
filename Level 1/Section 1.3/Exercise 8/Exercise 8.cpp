#include <stdio.h>
int main()
{
int x=2;
int y;
int z;
x*=3+2; //x = x * (3+2) = 10
printf("x=%d\n", x); //x=10 will be printed
x*=y=z=4; //x= 10 *4
printf("x=%d\n", x); //x=40 will be printed
x=y==z; //y==z is true so x=1
printf("x=%d\n", x); //x=1 will be printed
return 0;
}