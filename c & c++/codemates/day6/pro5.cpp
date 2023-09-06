#include <stdio.h>
int add(int,int);
int sub(int,int);
int multi(int,int);
int repeat(){
	int a,x,y;
	printf("select operation 1.Add\t2.Sub\t3.multiply:\n");
	scanf("%d",&a);
	printf("enter 2 numbers:\n");
	scanf("%d %d",&x,&y);
	switch(a){
		case 1:
			add(x,y);
			break;
		case 2:
			sub(x,y);
			break;
		case 3:
			multi(x,y);
			break;
		default:
			repeat();
		}
}
int add(int x,int y){
	int ans=x+y;
	printf("Answer :%d",ans);
}
int sub(int x,int y){
	int ans=x-y;
	printf("Answer :%d",ans);
}
int multi(int x,int y){
	int ans=x-y;
	printf("Answer :%d",ans);
}
int main(){
	repeat();
}
