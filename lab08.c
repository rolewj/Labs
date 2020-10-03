#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv){
	int a, b, c;
	scanf("%d %d", &a, &b);
	a = abs(a);
	b = abs(b);
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
	printf("Greatest common devisor of numbers: %d", a);
	return a;
}
