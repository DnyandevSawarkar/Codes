#include <stdio.h>
void swap(int *,int *);
int main()
{
	int a=10,b=5;
	swap(&a,&b);
	printf("a=%d\tb=%d",a,b);
}
void swap(int *x,int *y){
	int t=*x;
	*x=*y;
	*y=t;
}
