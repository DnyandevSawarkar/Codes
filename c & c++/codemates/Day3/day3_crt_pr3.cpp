#include<stdio.h>
int main(){
	int p,time;
	float rate,SI;
	printf("Enter Princple amount :");
	scanf("%d",&p);
	
	printf("Enter Rate of intrest :");
	scanf("%f",&rate);

	printf("Time in Days :");
	scanf("%d",&time);
	
	SI = (p*rate*time)/100;
	printf("Simple Intrest : %f",SI);
}
