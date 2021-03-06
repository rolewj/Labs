#include "stdio.h"
#include "malloc.h"
#include "string.h"

typedef struct{
	char* string;
	unsigned int size;
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
	int rSize = strlen(s->string) + size; // вычисляем необходимую длину 
	if (s->size <= rSize){ // если не хватает размера массива
		do{
  		s->size *= 2; // увеличиваем размер массива в 2 раза, пока не достигнем необходимого размера
		} while (s->size <= rSize);
		s->string = (char*)realloc(s->string, s->size); // изменяем размер динамического массива 
	}
	strcat(s->string, in); // добавляем к строке s строку in
}

void next_fibonacci(unsigned long long int* x1, unsigned long long int* x2){
	unsigned long long int  c;
	c = *x1 + *x2;
	*x1 = *x2;
	*x2 = c;
}

void next_fibonacci_string(int k, unsigned long long int* x1, unsigned long long int* x2, String* b){
	char buf[100]; // создаем буффер для хранения следующего числа Фибоначчи
	for (int i = 0; i < k; i++){ // перебираем следующие k чисел
		next_fibonacci(x1, x2); // вычисляем следующее число Фибоначчи
		snprintf(buf, 100, "%llu", *x2); // записываем число в строку
		addN(b, buf, strlen(buf)); // добавляем эту строку к строке b
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
		next_fibonacci_string(in, &x1, &x2, &s);
		printf("%s\n",s.string);
	}
	destruct(s);
	return 0;
}
