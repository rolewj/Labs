#include "stdio.h"

int main(int argc, char** argv){
	int n = 1;
	int a = 0;
	int b = 0;
	int i = 0;
	int k = 0;
	scanf("%d", &n);
	while(i < n){
		a = a + 1;
		k = a;
		while(k > 0){
			k = k / 10;
			i = i + 1;
		}
	}
	while(i >= n){
		b = a % 10;
		a = a / 10;
		i = i - 1;
	}
	printf("%d", b, a);
	return 0;
}
