#include "stdio.h"

void swapInt(int* a, int* b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void swapPointers(void **a, void **b){
	void *t = *a;
	*a = *b;
	*b = t;
}

int main(int argc, char** argv){
	int x, y;
	scanf("%d %d", &x, &y);
	printf("Numbers before swapping: x = %d, y = %d", x, y);
	swapInt(&x, &y);
	printf("\nNumbers after swapping: x = %d, y = %d", x, y);

	char *a = "Apple";
	char *b = "Pineapple";
	printf("\nStrings before swapping: Str1 = %s, str2 = %s", a, b);
	swapPointers((void**)&a, (void**)&b);
	printf("\nStrings after swapping: Str1 = %s, str2 = %s", a, b);
	getchar();
	return 0;
}
