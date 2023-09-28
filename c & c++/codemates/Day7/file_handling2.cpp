#include <stdio.h>
int main(){
	int s;
	FILE * f;
	f=fopen("File_Handling.txt","rb+");
	fread(&s,4,1,f);
	fclose(f);
	printf("s=%d",s);
}
