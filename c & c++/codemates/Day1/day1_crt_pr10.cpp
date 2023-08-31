#include<stdio.h>
int main(){

	int a = -5;
	int b = 1;
	a=a-- + b++;
	b=--a + ++b;


	printf("a=%d	b=%d",a,b);
}
