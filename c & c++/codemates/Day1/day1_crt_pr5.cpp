#include<stdio.h>
int main(){
	int c,d;
	int a = 5;
	int b = 3;
	c=-4;
	d=a%b*c-c*b%a;

	printf("a=%d	b=%d	c=%d		d=%d",a,b,c,d);
}
