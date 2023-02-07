#include<REG51.H>
//Fuction Prototypes
void delay(unsigned int);
void lcd_data(unsigned char );
void lcd_cmd(unsigned char );



sbit RS = P3^7;
sbit RW = P3^6;
sbit EN = P3^5;
sbit sw1 = P1^7;



#define lcddata P2; 
// Program Starts Here
void main()
{


	 while(1);
}


void lcd_data(unsigned char x)	// data function 
{
  RW=0;		  // write mode on
  RS=1;
  P2 = x;
  EN=1;		  // enabled 1 active mode
  delay(1);
  EN=0;		  // enabled 0 deactive mode
}

void lcd_cmd(unsigned char z)   // commands function
{
  RW=0;
  RS=0;
  P2 = z;
  EN=1;		  // enabled 1 active mode
  delay(1);
  EN=0;		  // enabled 0 deactive mode
}


void delay(unsigned int tt)
{
 	unsigned int a,b;
 	for(a=0;a<tt;a++)
		{
			for(b=0;b<1275;b++)
			;
		}
}