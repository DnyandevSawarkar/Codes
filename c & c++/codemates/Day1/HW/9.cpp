#include<stdio.h>
int main(){
	int a,b,c;
	a = -5,b = -3, c = -8;
	
	//a = -a % ++b + c-;
	a = --a % ++b + c--;
	
	//b = b++ + ++c * a-;
	b = b++ + ++c * a--;
	
	//c = c- + ++a % b-;
	c = c-- + ++a % b--;
	
	a += b + c;
	c *= a + b;
	b -= a + c;
	printf("a = %d b =%d c=%d",a,b,c);
}
