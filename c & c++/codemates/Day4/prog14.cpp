#include<stdio.h>
int main(){
	
	for(int a=1;a<=5;a++){
		printf("\n");
		for(int b=1;b<=5;b++){
			if(a==1||b==1||a==5||b==5)
				printf("*");
			else		
				printf(" ");
		}
		
	}
		
}
