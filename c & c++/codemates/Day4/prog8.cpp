#include<stdio.h>
int main(){
	int a;
	int b=0;
	printf("enter number: ");
	scanf("%d",&a);
	for(b=0;a!=0;a=a/10){
		b=b+a%10;
		//a=a/10;
	}
	printf("Sum of digit : %d\n",b);	
}
