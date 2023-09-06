#include <stdio.h>
void test(int *);
int main(){
	int n=10;
	printf("n=%d\n",n);
	test(&n);
	printf("n=%d\n",n);
}
void test(int *a){
	*a= *a+100;
	printf("a=%d\n",*a);
}
