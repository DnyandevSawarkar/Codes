#include<stdio.h>
int main(){
	int a,b,c;
	printf("Enter 3 Numbers :");
	scanf("%d %d %d",&a,&b,&c);
	
	if(a>b && a>c){
		printf("a greater");
	}
		
	if(b>c && b>a){
		printf("b greater");
	}
	
	if(b<c && a<c){
		printf("c greater");
	}
}
