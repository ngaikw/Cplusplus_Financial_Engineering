# include<stdio.h>
int main() {
	double base, height, area;
	printf("I will calculate the area of a right triangle for you. Please enter the base\n");
	scanf("%lf",  &base); //take in base and height
	printf("Now enter the height\n");
	scanf("%lf", &height);
	area = base * height * 0.5;
    if (area<0 || area==0) {
        printf("You will be seeing a negative area or 0 area because of your entries \n");
    }
	printf("The area is %lf", area);
	return 0;
}