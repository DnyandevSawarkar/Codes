#include<stdio.h>
int main(){

	int a = -5;
	int b = -7;
	int c = 4;
	a= ++a * c % ++b;

	b= ++a % --c / --b;
	
	c= a-- * --c % ++b;


	printf("a=%d	b=%d	c=%d",a,b,c);
}