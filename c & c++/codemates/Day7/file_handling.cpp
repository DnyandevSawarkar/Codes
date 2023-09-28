/*
file pointer
fopen
fcloce
fwrite
fread
fmode  -- 1. wb+ (write binary) 2.rb+ (write binary)
*/
#include <stdio.h>
int main(){
	int s=65;
	FILE * f;
	f=fopen("File_Handling.txt","wb+");
	fwrite(&s,4,1,f);
	fclose(f);
	printf("Done");
}
