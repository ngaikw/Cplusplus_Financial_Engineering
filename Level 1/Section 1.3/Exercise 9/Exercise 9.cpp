#include <stdio.h>
int main()
{
int x=1;
int y=1;
int z=1;
x+=y+=x; //y = 1+1, x = 2+1
printf("%d\n\n", (x<y)?y:x); // Number 1 : x is NOT less than y so x will be printed. 3 will be printed.
//then a blank line will be printed because of the extra \n in line 8.
printf("%d\n", (x<y)?x++:y++); // Number 2: x is NOT less than y so y++ will be printed. 2 will be printed
//because the ++ operator is not executed until after y is printed.
printf("%d\n", x); // Number 3: x = 3. 3 will be printed.
printf("%d\n", y); // Number 4: y = 3 now because of the ++ in line 10. 3 will be printed
return 0;
}