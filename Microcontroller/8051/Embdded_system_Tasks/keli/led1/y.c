#include<reg52.h>
void delay(int s)
{	int i,j;
	for(i=0;i<=s;i++)
	{
		for(j=0;j<1275;j++);
	}
	}
void main()
{
	while(1)
	 {
		int a;
		P1=0x00;
		P2=0x00;
		for(a=0;a<8;a++)
		{
			
			 P1=0x80>>a;
			delay(30);
			P1=0x00;
		
		
			P2=0x80>>a;
			delay(30);
			P2=0x00;
			

			
		}
	}
}