#include<stdio.h>

int printnumber(unsigned long int x) {
	/*if(x<0){
		x = -x;
	}*/

	if (x >= 10){
		 printnumber( x / 10);
		 printnumber(x % 10);
	}
	else {
		printf(" %ld", x);
	}

}



int main(){
	long int x, ans;
	printf("please enter the digit to be printed\n");
	scanf("%ld", &x);
	printnumber(x);
	
	return 0;
}