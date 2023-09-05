#include<stdio.h>
int main(){
	int a,b,s;
	s=4;
	for(a=1;a<=5;a++){
		for(b=1;b<=s;b++){
			printf(" ");
		}
		s--;
		for(b=1;b<=2*a-1;b++){
			printf("*");
		}
		printf("\n");
	}
	
	s=1;
	for(a=4;a>=1;a--){
		for(b=1;b<=s;b++){
			printf(" ");
		}
		s++;
		for(b=1;b<=2*a-1;b++){
			printf("*");
		}
		printf("\n");
	}
}
