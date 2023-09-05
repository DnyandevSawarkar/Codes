#include <stdio.h>
int main(){
	int a;
	for(a=1;a<=10;a++){
		if(a%2==1){
			continue;
		}
		printf("%d\n",a);
	}
}
