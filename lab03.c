#include "stdio.h"

int main(int argc, char** argv){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int a = 0;
		for(int d = 2; d <= i-1; d++){
			if(i % d == 0){
				a = 1;
			}
		}
		if (a == 0){
			printf("%d ", i);
		}
	}
}
