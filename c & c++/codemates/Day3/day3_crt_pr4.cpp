#include<stdio.h>
int main(){
	int a,b,c;
	printf("Enter A and B :");
	scanf("%f %f",&a,&b);
	c = (a!=b);
	printf("%d\n",c);
	
	c = (a == b);
	printf("(a == b) : %d\n",c);
	
	c = (a >= b);
	printf("(a >= b) : %d\n",c);
	
	c = (a <= b);
	printf("(a <= b) : %d\n",c);
	
	c = (a > b);
	printf("(a > b) : %d\n",c);
	
	c = (a < b);
	printf("(a < b) : %d\n",c);
}
