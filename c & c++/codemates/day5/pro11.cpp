#include<stdio.h>
int main()
{
	int bin[100],n,c,i;
	c=0;
	printf("Enter any number ");
	scanf("%d",&n);
	while(n!= 0){
		bin[c]=n%2;
		n=n/2;
		c++;
	}
	c--;
	for(i=c;i>=0;i--)
	{
		printf("%d",bin[i]);
	}
}
