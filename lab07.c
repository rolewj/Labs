#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv){
	float arr[100];
	int n, i, j;
	float s;
	scanf("%d", &n);
	if (n > 100){
		printf("Length is too big.");
		return 1;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = (float) rand() / (float) RAND_MAX;
	}
	for(i = 0; i < n; i++){
  	printf("%f ", arr[i]);
	}
	printf("\n");
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j+1]){
				s = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = s;
			}
		}
	}
	for(i = 0; i < n; i++){
  	printf("%f ", arr[i]);
	}
	printf("\n");
	return 0;
}
