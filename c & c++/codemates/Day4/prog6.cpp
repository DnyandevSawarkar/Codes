#include<stdio.h>
int main(){
	int a,c;
	int b=1;
	printf("enter number");
	scanf("%d",&a);
	while(b<=10){
		c=a*b;
		printf("%dx%d 	= %d\n",a,b,c);	
		b++;
	}
}
