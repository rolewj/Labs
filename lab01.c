#include "stdio.h"
#include "math.h"

int main(int argc, char** argv){
	float a, b, c, x1, x2, d;
	printf("Enter the value of variable a: ");
	scanf("%f", &a);
	printf("Enter the value of variable b: ");
	scanf("%f", &b);
	printf("Enter the value of variable c: ");
	scanf("%f", &c);
	d = b*b - 4*a*c;
	if (a != 0) {
		if (d==0) {
			x1 = (-b)/(2*a);
			printf("The root is %g", x1);
		}
		else if (d>0) {
			x1 = (-b + sqrt(d))/(2*a);
			x2 = (-b - sqrt(d))/(2*a);
			printf("First root: %g\nSecond root: %g", x1, x2);
		}
		else {
			printf("No roots");
		}	
	}
	else {
		x1 = -c/b;
		printf("The root is %g", x1);
	}
	return 0;
}
