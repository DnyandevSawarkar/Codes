#include<stdio.h>
int main(){
	int a;
	int b=0;
	printf("enter number: ");
	scanf("%d",&a);
	while(a !=0){
		b=b*10+a%10;
		a=a/10;
	}
	printf("Reversed Number : %d\n",b);	
}
