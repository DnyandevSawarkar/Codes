/****************************************************
       Lesson  : 8
 	   Neme    : LCD Interface
	   Details : The LCD has two line and each line has 16 character
	   			 the lcd works here 4 bit mode 
				 the display show "welcome" on first line
				 and "have a nice day" on second line 
******************************************************/
#include<REG51.H>
//Fuction Prototypes
void delay(unsigned int);
void lcd_string(unsigned char *p);
void lcd_data(unsigned char );
void lcd_cmd(unsigned char );
void lcd_no(unsigned char );

sbit EN = P1^1;
sbit RS = P1^0;
sbit RW = P0^1;
sbit light = P0^3;

#define lcddata P2; 
// Program Starts Here
void main()
{

	
	lcd_cmd(0x38);    // Configuring settings to 8-bit 2 row 
delay(2);
lcd_cmd(0x0E); 
delay(2);
lcd_cmd(0x06);    //Display on
delay(2);
lcd_cmd(0x80);    //Set cursor to blink at line 1 positon 1
delay(2);
	 delay(1);
	 lcd_no(25);
//	 lcd_cmd(0x81);
/*	 lcd_string("  MANOJAA     ");
	 delay(25);							*/
	 lcd_cmd(0xc0);	 // LCD start 2nd line
	 delay(1);
     lcd_string("HAVE A NICE DAY ");             
	 while(1);
	
}

void lcd_string(unsigned char *p)
{
	while(*p != '\0')
	{
	lcd_data(*p);
	p++;
	delay(10);
	}
}

void lcd_data(unsigned char x)
{ 
  RW=0;
  RS=1;
  P2 = (P2 & 0x0F)|(x & 0xF0);
  EN=1;
  delay(1);
  EN=0;
  P2 = (P2 & 0x0F)|((x<<4) & 0xF0);
  EN =1;
  delay(1);
  EN=0;
}
void lcd_no(unsigned char t)
{ 
  RW=0;
  RS=1;
  while(t>0)
  {t=t/10;
  P2 =t + 0x30;
  t=t%10;
  }
  EN=1;
  delay(1);
  EN=0;
}
void lcd_cmd(unsigned char z)
{
  RW=0;
  RS=0;
  P2 = (P2 & 0x0F)|(z & 0xF0);
  EN =1;
  delay(1);
  EN=0;
  P2 = (P2 & 0x0F)|((z<<4) & 0xF0);
  EN =1;
  delay(1);
  EN=0;

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
