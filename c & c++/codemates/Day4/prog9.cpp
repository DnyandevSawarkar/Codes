#include<stdio.h>
int main(){
	int a,n;
	int f=1;
	printf("enter number: ");
	scanf("%d",&n);
	for(a=2;a<=n;a++){
		f=f*a;
	
	}
	printf("Factorial of %d : %d\n",n,f);	
}
