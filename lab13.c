#include "stdio.h"
#include "malloc.h"
#include "string.h"
#include "math.h"

typedef struct{
	char* string;
	char size;
} String;

String construct (char* in, unsigned int size){
	String s;
	s.size = size;
	s.string = (char*)malloc(size*sizeof(char));
	strcpy(s.string, in);
	return s;
}

void destruct(String s){
	free(s.string);
}

void addN(String* s, char* in, unsigned int size){
	int rSize = strlen(s->string) + size;
	if (s->size <= rSize){
		while (s->size <= rSize){
			s->size *= 2;
		}
		s->string = (char*)realloc(s->string, s->size);
	}
	strcat(s->string, in);
}

void next_fibbonacci(unsigned long long int* x1, unsigned long long int* x2){
	unsigned long long int  c;
	c = *x1 + *x2;
	*x1 = *x2;
	*x2 = c;
}

void next_fibbonacci_string(int k, unsigned long long int* x1, unsigned long long int* x2, String* b){
	unsigned long long int size = 10;
	unsigned long long int fibbonacci;
	char buf[100];
	for (int i = 0; i < k; i++){
		next_fibbonacci(x1, x2);
		fibbonacci = *x2;
		snprintf(buf, 99, "%llu", fibbonacci);
		addN(b, buf, strlen(buf));
	}
}

int main(int argc, char** argv){
	char fibon[] = "1123";
	unsigned long long int x1 = 2;
	unsigned long long int x2 = 3;
	String s = construct(fibon, 5);
	printf("%s\n",s.string);
	int in = 1;
	while (in != 0){
		scanf("%d",&in);
		next_fibbonacci_string(in, &x1, &x2, &s);
		printf("%s\n",s.string);
	}
	destruct(s);
	return 0;
}
