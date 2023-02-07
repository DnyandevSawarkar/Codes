#include<reg52.h> //including sfr registers for ports of the controller
#include<lcd.h> // Can be download from bottom of this article

//LCD Module Connections
sbit RS = P3^0;
sbit EN = P3^2;

sbit D0 = P1^0;
sbit D1 = P1^1;
sbit D2 = P1^2;
sbit D3 = P1^3;
sbit D4 = P1^4;
sbit D5 = P1^5;
sbit D6 = P1^6;
sbit D7 = P1^7;

// #define ldata P2

//End LCD Module Connections

void Delay(int a)
{
  int j;
  int i;
  for(i=0;i<a;i++)
  {
    for(j=0;j<100;j++)
    {
    }
  }
}

void main()
{
  int i;
  Lcd8_Init();
  while(1)
  {
    Lcd8_Set_Cursor(1,1);
    Lcd8_Write_String(" e-yantra lab");
    
	Lcd8_Set_Cursor(2,1);
    Lcd8_Write_String(" SVPCET, Nagpur");
    
  }
}