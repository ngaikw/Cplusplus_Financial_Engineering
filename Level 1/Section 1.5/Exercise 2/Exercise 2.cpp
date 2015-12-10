#include<stdio.h>

int fact(int x){
	if (x==0) return 1;
	else if (x<0) return 0;
	else{
		return (x * fact(x-1));
	}

}

int main() {
	int x, ans;
	printf("enter an integer only \n");
	scanf("%d", &x);
	ans = fact(x);
	printf("%ld \n",ans);
	return 0;
}