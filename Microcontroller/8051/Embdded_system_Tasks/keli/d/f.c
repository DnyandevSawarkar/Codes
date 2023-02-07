#include<reg52.h>           
void delay (int ms)
{
int i; 
for(i=0;i<ms;i++);
}
void main()
{
	while (1)
	{
		P2=0x01;
		delay(1200);
		P2=0x02;
		delay(1200);
	}			   
}
