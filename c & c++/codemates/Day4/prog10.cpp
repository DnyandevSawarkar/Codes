#include<stdio.h>
int main(){
	int a,n1,n2,p=1;
	printf("enter number: ");
	scanf("%d",&n1);
	printf("enter Power: ");
	scanf("%d",&n2);
	
	for(a=1;a<=n2;a++){
		p=p*n1;
	
	}
	printf("%d to the power %d : %d\n",n1,n2,p);	
}
