#include <stdio.h>
int main(){
	int a,b,c;
	printf("enter 2 number:\n");
	scanf("%d%d",&a,&b);
	printf("Select operation \n1. +\n2. -\n3. *\n4. /\n5. mod \nChoice :");
	scanf("%d",&c);
	switch(c){
		case 1:
			printf("%d",a+b);
			break;
		case 2:
			printf("%d",a-b);
			break;
		case 3:
			printf("%d",a*b);
			break;
		case 4:
			printf("%d",a/b);
			break;
		case 5:
			printf("%d",a%b);
			break;	
		
		default:
			printf("Invalid entry");
	}
}
