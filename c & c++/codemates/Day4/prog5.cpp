#include<stdio.h>
int main(){
	int a,c;
	int b=10;
	printf("enter number");
	scanf("%d",&a);
	while(b>0){
		c=a*b;
		printf("%dx%d 	= %d\n",a,b,c);	
		b--;
	}
}
