#include "stdio.h"

int main(int argc, char** argv){
	int days1;
	int days2;
	int y1;
	int y2;
	char m1;
	char m2;
	char d1;
	char d2;
	int i=0;
	char m[12]={
		31,
		28,
		31,
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31
	};
	int ans;
	printf("Write 1st date (dd mm yyyy)\n");
	scanf("%hhd %hhd %d", &d1, &m1, &y1);
	printf("Write 2nd date (dd mm yyyy)\n");
	scanf("%hhd %hhd %d", &d2, &m2, &y2);
	days1=d1+y1*365+y1/4-y1/100+y1/400;
	days2=d2+y2*365+y2/4-y2/100+y2/400;
	printf("%d\n", days1);
	printf("%d\n", days2);
	for (int i = 0; i<(m1-1); i++){
		char v = 0;
		if (y1 % 400 == 0) {
			v = 1;
		} else if (y1 % 100 == 0) {
			v = 0;
		} else if (y1 % 4 == 0) {
			v = 1;
		}
		if (i == 1) {
			days1 += 28+v;
		} else {
			days1=days1+m[i];
		}
	}
	i=0;
	while(i<(m2-1)){
		char v = 0;
		if (y2 % 400 == 0) {
			v = 1;
		} else if (y2 % 100 == 0) {
			v = 0;
		} else if (y2 % 4 == 0) {
			v = 1;
		}
		if (i == 1) {
			days2 += 28+v;
		} else {
			days2=days2+m[i];
		}
		i=i+1;
  }
	ans=days2-days1-2;
	printf("the number of days is: %d", ans);
	return 0;
}
