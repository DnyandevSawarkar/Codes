#include <stdio.h>
int IsPrime(int n);
int main(){
	int x;
	printf("Enter number : ");
	scanf("%d",&x);
	if(IsPrime(x)){
		printf("Prime number\n");
	}
	else{
		printf("Composite number\n");
	}
}
int IsPrime(int n){
	int result =1;
	for(int a=2;a<n;a++){
		if(n%a==0)
			result =0;
	}
	return result;
}
