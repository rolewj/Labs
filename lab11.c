#include "stdio.h"
#include "string.h"

int main(int argc, char** argv){
	char a[100];
	char s[256] = {0};
	char fw[100];
	fgets(a, 99, stdin);
	int i = 0;
	int cursor;
  for(;(a[i]!=' ')&&(a[i]!='\0'); i++){
    fw[i] = a[i];
		s[fw[i]] = 1;
  }
  fw[i] = '\0';
	int fwlen = i;
	cursor = fwlen+1;
	int x = 0;
	int ws = cursor;
	while(1){
		char c = a[cursor];
		if (c == ' ' || c == '\0'){
			if (x){
				x = 0;
			} 
			else{
				for(i = ws; i < cursor; i++){
					printf("%c", a[i]);
				}
				printf(" ");
			}
			if (c == '\0'){
				break;
			}
			cursor++;
			ws = cursor;
		} 
		else{
			if (s[c] == 1){
				x = 1;
			}
			cursor++;
		}
	}
	printf("\n");
	return 0;
}
