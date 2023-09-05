#include<stdio.h>
int main(){
	char a;
	
	printf("Enter char :");
	scanf("%c",&a);
	int b =a;
	int small = (a=='a') || (a=='e') || (a=='i') || (a=='o') || (a=='u');
	int cap = (a=='A') || (a=='E') || (a=='I') || (a=='O') || (a=='U');
	if(small || cap ){
	 	printf("Vol\n");
	}
	else{
		printf("non VOL\n");
	}
	
	if (97 <= b && b <=122){
		printf("Small\n");
	}
	else if (65 <= b && b <=90)
	{
		printf("Cap\n");
	}
	else{
		printf("out of range");
	}
}
