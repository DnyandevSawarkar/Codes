#include<stdio.h>
int main(){

	int a = 1;
	int b = 1;
	a=a++ + b++;
	b=++a + ++b;


	printf("a=%d	b=%d",a,b);
}
