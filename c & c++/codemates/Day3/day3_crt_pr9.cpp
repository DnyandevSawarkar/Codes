#include<stdio.h>
int main(){
	int a;
	printf("Enter number");
	scanf("%d",&a);
	a>=0 ?( a==0? printf("zero"):printf("+ve") ):printf("-ve");
}
