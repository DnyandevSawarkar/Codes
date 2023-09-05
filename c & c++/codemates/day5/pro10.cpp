#include <stdio.h>
int main(){
	
	int a1[]={52,33,14,5,6};
	int a2[5];
	int i,j=4;
	
	for ( i=0;i<5;i++){
		a2[j]=a1[i];
		j--;
	}
	printf("\na1\ta2\n");
	for( i=0;i<5;i++){
		printf("%d\t%d\n",a1[i],a2[i]);
	}
}
