#include <stdio.h>
int main(){
	int m1[2][2]={3,1,5,6};
	int m2[2][2]={6,4,5,7};
	int m3[2][2];
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			m3[i][j]=m1[i][j]+m2[i][j];
		}
	}
	printf("\n-----------------\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",m1[i][j]);
		}
		printf("\n");
	}
	printf("\n-----------------\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",m2[i][j]);
		}
		printf("\n");
	}
	printf("\n-----------------\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",m3[i][j]);
		}
		printf("\n");
	}
}
