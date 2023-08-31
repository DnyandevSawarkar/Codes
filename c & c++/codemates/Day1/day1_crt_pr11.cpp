#include<stdio.h>
int main(){

	int a = -5;
	int b = -7;
	a= ++a - b--;
	// -4 - (-7) = 3
	b= a-- + --b;
	// 3 + -9 = -6
	//a = 2

	printf("a=%d	b=%d",a,b);
}
