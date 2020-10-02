#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv){
	int a, a1, b, b1, c, lcm;
	scanf("%d %d", &a, &b);
	a = abs(a);
	b = abs(b);
	a1 = a;
	b1 = b;
	if (a == 0 && b == 0){
		printf("Undefined.");
		return 1;
	}
	while (a != b) {
		if (a > b) {
			a = a - b;
		} else {
			b = b - a;
		}
	}
	lcm = a1/a*b1;
	printf("Least common multiple of numbers: %d", lcm);
	return 0;
}
