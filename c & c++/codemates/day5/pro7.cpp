#include <stdio.h>
int main(){
	int a,b,c=0;
	for(a=1;a<=5;a++){
		for(b=1;b<=5;b++){
			printf("%d",c);
			c=!c;
		}
		printf("\n");	
	}
}
