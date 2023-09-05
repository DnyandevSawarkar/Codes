#include <stdio.h>
int main(){
	int a[3][2] = {};
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			printf("Enter value for a[%d %d]:    ",i,j);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			printf("a[%d %d]: %d    ",i,j,a[i][j]);
		}
		printf("\n");
	}
}
