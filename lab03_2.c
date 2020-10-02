#include "stdio.h"

int main(int argc, char** argv){
	unsigned int n, a = 0;
  	scanf("%d", &n);
  	while(n > 0){
    		a = a*10 + n%10;
    		n = n/10;
  	}
	printf("%d", a);
	return 0;
}	
