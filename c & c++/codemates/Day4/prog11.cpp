#include<stdio.h>
int main(){
	int n1,n2;
	
	printf("enter outer number: ");
	scanf("%d",&n1);
	printf("enter inner number: ");
	scanf("%d",&n2);
	
	for(int a=0;a<=n1;a++){
		//printf("\n----------------------------------------------\n");
	//	printf("%d\n",n1);
		for(int b=0;b<=n2;b++){
			printf("%d\t",n2);		
		}
		printf("\n----------------------------------------------\n");
	}
		
}
