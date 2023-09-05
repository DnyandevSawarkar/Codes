#include <stdio.h>
int main(){
	int a,b,c;
	printf("enter 3 number :");
	scanf("%d%d%d",&a,&b,&c);
	b=a>b?a:b;
	c=c>b?c:b;
	printf("%d\n",c);
	
}
