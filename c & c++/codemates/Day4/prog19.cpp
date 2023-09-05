#include<stdio.h>
int main(){
	
	for(int a=1;a<=5;a++){
				
		for(int b=1;b<=a;b++){
			printf("%c",64+a);
		}
		printf("\n");
	}
	printf("\n\n\n\n");
	for(int a=1;a<=5;a++){
				
		for(int b=1;b<=a;b++){
			printf("%c",64+b);
		}
		printf("\n");
	}
	
}
