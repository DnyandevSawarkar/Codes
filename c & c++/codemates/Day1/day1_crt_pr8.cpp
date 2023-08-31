#include<stdio.h>
int main(){
	int c,d;
	int a = 11;
	int b = -4;
	c=-9;
	d= a%c *b + a/c %b;

	printf("a=%d	b=%d	c=%d		d=%d",a,b,c,d);
}
