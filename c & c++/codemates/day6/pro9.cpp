#include <stdio.h>
void test(int);
int main(){
	test(1);
}
void test(int a)
{
	if(a<21){
		if(a%2==0)
			printf("%d : even\n",a);
		else
			printf("%d : odd\n",a);
		a++;
		test(a);
	}	
}
