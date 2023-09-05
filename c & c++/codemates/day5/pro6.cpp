//char 		:	583
//int		:	580
//float 	:	580
//double	:	576
#include <stdio.h>
int main(){
	int a =10;
	int *p;
	int **q;
	
	p=&a;
	q=&p;
	
	printf("%u\n",a);
	printf("%u\n",&a);
	printf("%u\n",p);
	printf("%u\n",&p);
	printf("%u\n",*p);
	printf("%u\n",**q);
}
