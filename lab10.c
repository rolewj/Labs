#include "stdio.h"
#include "string.h"

int main(void){
	char a[100];
	char b[100];
	char c[100];
	scanf("%99s%99s", a, b);
	int alen = strlen(a);
	int blen = strlen(b);
	int x = 0;
	int s = 0;
	for(int i = 0; i < alen; i++){
		for(int j = 0; j < blen; j++){
			if (a[i] == b[j]){
				x = 1;
			}
		}
		if (x == 0){
			c[s] = a[i];
			s++;
		}
		x = 0;
	}
	c[s] = '\0';
	puts(c);
	return 0;
}
