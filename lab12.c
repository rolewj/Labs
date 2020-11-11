#include "stdio.h"
#include "string.h"

int main(int argc, char** argv){
	int b1, b2, f;
	char str1[100];
	char str2[100];
	char str3[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	printf("Initial base: ");
	scanf("%d", &b1);
	if (b1 < 2 || b1 > 16){
		printf("Error: Incorrect value of Initial base\n");
		return 0;
	}
	printf("Target base: ");
	scanf("%d", &b2);
	if (b2 < 2 || b2 > 16){
		printf("Error: Incorrect value of Target base\n");
		return 0;
	}
	printf("Length of fractional part: ");
	scanf("%d", &f);
	if (f < 1 || f > 10){
		printf("Error: Incorrect value of Fraction length\n");
		return 0;
	}
	printf("Number in initial base: ");
	scanf("%s",str1);
	
	int l1=strlen(str1);
	int s=0;
	int k=0;
	for (int i=0; i<l1; i++){ //Разделяет дробную и целую части. Проверяет правильность записи числа
		if (str1[i]>str3[b1-1] && str1[i]!='.' ){
			printf("Incorrect data");
			return 0;
		}
		if (s>0){
			str2[k]=str1[i];
			k++;
		}
		if (str1[i]=='.'){
			str1[i]='\0';
			s=i+1;
		}
	}
	str2[k]='\0';
	l1=strlen(str1);
	int l2=strlen(str2);
	int t1=0;
	double t2=0;
	int x1=1;
	k=0;
	for (int i=l1-1; i>=0; i--){ //перевод целой части в десятичную систему счисления
		if (str1[i]>=48 && str1[i]<=57){
			t1+=(str1[i]-48)*x1;
			x1*=b1;
		}
		if (str1[i]>=65 && str1[i]<=70){
			t1+=(str1[i]-55)*x1;
			x1*=b1;
		}
	}
	double x2=1.0/b1;
	for (int i=0; i<l2; i++){ //перевод дробной части в десятичную систему счисления
		if (str1[i]>=48 && str1[i]<=57){
			t2+=(str2[i]-48)*x2;
			x2/=b1;
		}
		if (str1[i]>=65 && str1[i]<=70){
			t2+=(str2[i]-55)*x2;
			x2/=b1;
		}
	}
	int q;
	for (int i=0; t1!=0; i++){ //перевод целой части в b2-нную систему счисления в обратном порядке
		q=t1%b2;
		if (q>=0 && q<=9){
			str1[i]=q+48;
		}
		if (q>=10 && q<=15){
			str1[i]=q+55;
		}
		t1/=b2;
		k=i;
	}
	str1[k+1]='\0';
	printf("Result: ");
	for (int i=k; i>=0; i--){ //перевод целой части в b2-нной систему счисления в правильном порядке
		printf("%c",str1[i]);
	}
	if (t2!=0){
		printf(".");
	}
	for (int i=0; t2>0; i++){ //перевод дробной части в b2-нную систему счисления в правильном порядке
		q=(t2*b2)/1;
		if (q>=0 && q<=9){
			str2[i]=q+48;
		}
		if (q>=10 && q<=15){
			str2[i]=q+55;
		}
		t2=(t2*b2)-q;
		k=i;
	}
	if (f<k+1){
		str2[f]='\0';
	}
	else{
		str2[k+1]='\0';
	}
	printf("%s ",str2);
}
