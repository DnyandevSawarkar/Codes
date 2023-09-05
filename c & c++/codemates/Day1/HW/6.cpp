#include<stdio.h>
int main(){
	int a,b,c;
	a =3,b =15, c=-7;
	//a = a++ % ++b - c-;
	a = a++ % ++b - c--;
	//b = b++ * ++c + a-;
	b = b++ * ++c + a--;
	//c = c++ + ++a % b+;
	c = c++ + ++a % b++;
	printf("a = %d b =%d c=%d",a,b,c);
}
