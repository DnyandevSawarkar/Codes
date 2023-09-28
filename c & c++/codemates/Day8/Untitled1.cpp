#include <stdio.h>
#include <string.h>
struct Student{
	int roll;
	char name[20];
	int age;
	float marks;
	char addr[30];
};

int main(){
	struct Student[15];
	for(int ene=0;ene<15;ene++){
		printf("Entery Count:%d",ene);
		
		printf("Enter Roll Number: ");
		scanf("%d",&Student[ene].roll);
		
		printf("Name: ");
		scanf("%s",&Student[ene].name);
		
		printf("Age: ");
		scanf("%d",&Student[ene].age);
		
		printf("address: ");
		scanf("%s",&Student[ene].addr);
		
		printf("Makrs : ");
		scanf("%d",&Student[ene].marks);
	}
	
	for(int ene=0;ene<15;ene++){
		printf("Entery Count:%d",ene);
		
		printf("Enter Roll Number: %d",&Student[ene].roll);
		
		printf("Name: %s",&Student[ene].name);
		
		printf("Age: %d",&Student[ene].age);
		
		printf("address: %s",&Student[ene].addr);
		
		printf("Makrs : %d",&Student[ene].marks);
	}
}
