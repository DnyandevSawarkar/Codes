#include<stdio.h>
int main(){
	
	for(int a=1;a<=11;a++){
		printf("\n");
		for(int b=1;b<=11;b++){
			if(a==1||a==11||a==b||a==12-b)
				printf("*");
			else		
				printf(" ");
		}
		
	}
		
}
