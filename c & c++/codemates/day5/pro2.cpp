#include<stdio.h>
int main(){
	int a,b,s;
	s=0;
	for(a=5;a>=1;a--){
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
