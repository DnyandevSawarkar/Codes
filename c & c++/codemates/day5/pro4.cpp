#include <stdio.h>
int main(){
	int a=1;
	x:
		printf("%d\n",a);
		a++;
	if(a<=10){
		goto x;
	}
}
