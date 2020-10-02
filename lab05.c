#include "stdio.h"

int n;
int a[1024];
int main(int argc, char** argv){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
  	a[i] = i;
	}
	a[0] = 0;
  for(int s = 2; s < n; s++){
  	if(a[s] != 0){
      for(int j = s * 2; j < n; j = j + s){
        a[j] = 0;
      }
    }
  }
  for(int i = 0; i < n; i++){
    if(a[i] != 0){
      printf("%d ", a[i]);
    }
  }
	return 0;
}
