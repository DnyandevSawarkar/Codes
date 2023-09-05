#include <stdio.h>
int main(){
	int a[3][2] = {8,6,9,3,4,5};
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			printf("a[%d %d]: %d    ",i,j,a[i][j]);
		}
		printf("\n");
	}
}
