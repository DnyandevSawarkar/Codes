#include <stdio.h>
enum Number{
	No,
	Yes
};
enum Number isprime(int);
int main(){
	int x;
	printf("Enter any number: ");
	scanf("%d",&x);
	if(isprime(x))
		printf("Prime");
	else
		printf("Non Prime");
}
enum Number isprime(int n){
	enum Number result=Yes;
	int a;
	for(a=2;a<n;a++){
		if(n%a==0){
			result=No;
			break;
		}
	}
	return result;
}
