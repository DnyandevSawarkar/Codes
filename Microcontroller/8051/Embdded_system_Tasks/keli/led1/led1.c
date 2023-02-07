#include<reg52.h>
sbit sw = P3^2;  // SWITCH  

// Delay Function
void delay(int ms)
{	int i,j;
	for(i=0;i<=ms;i++)
	{
		for(j=0;j<1275;j++);
	}
}

// Main Function
void main()
{
	int k;
	unsigned char dig[]={0x3F,0x6,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x6F};
	k=0;
 	sw = 1;
	while(1)
	{
	 	if(sw==0)
		{
			P2=dig[k];
			delay(50);
			k++;
			if(k==10)
			{
				k=0;
			}
		
		}
	}
}