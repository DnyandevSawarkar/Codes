#include<REG51.H>
//Fuction Prototypes
void delay(unsigned int);
void lcd_data(unsigned char );
void lcd_cmd(unsigned char );



sbit RS = P3^7;
sbit RW = P3^6;
sbit EN = P3^5;


#define lcddata P2; 
// Program Starts Here
void main()
{

	 
	 lcd_cmd(0x38);
	 delay(1);
	 lcd_cmd(0x06);	// display move cursor to right	
	 delay(1);
	 lcd_cmd(0x0F);	// LCD On, & cursor	on
	 delay(1);
	 lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);

	 // 1st row
	 lcd_cmd(0x80);	// LCD start 1st ROW 1ST POSITION
	 delay(250);
	 lcd_data('D');
	 delay(250);

	 lcd_cmd(0x81);	 // LCD start NEXT POSITION
	 delay(250);
     lcd_data('N');
	 delay(50);

	 lcd_cmd(0x82);	 // cursor start NEXT POSITION
	 delay(250);
     lcd_data('Y');
	 delay(50);

	 lcd_cmd(0x83);	 // cursor start NEXT POSITION
	 delay(250);
     lcd_data('A');
	 delay(50);

	 lcd_cmd(0x84);	 // cursor start NEXT POSITION
	 delay(250);
	 lcd_data('N');
	 delay(50);

	 lcd_cmd(0x85);	 // cursor start NEXT POSITION
	 delay(250);
	 lcd_data('D');
	 delay(50);

	 lcd_cmd(0x86);	 // cursor start NEXT POSITION
	 delay(250);
	 lcd_data('E');
	 delay(50);

	 lcd_cmd(0x87);	 // cursor start NEXT POSITION
	 delay(250);
	 lcd_data('V');
	 delay(50);

	 // 2nd row 
	 lcd_cmd(0xC0);	// LCD start 1st ROW 1ST POSITION
	 delay(250);
	 lcd_data('S');
	 delay(250);

	 lcd_cmd(0xc1);	 // LCD start NEXT POSITION
	 delay(250);
     lcd_data('A');
	 delay(50);

	 lcd_cmd(0xc2);	 // cursor start NEXT POSITION
	 delay(250);
     lcd_data('W');
	 delay(50);

	 lcd_cmd(0xc3);	 // cursor start NEXT POSITION
	 delay(250);
     lcd_data('A');
	 delay(50);

	 lcd_cmd(0xc4);	 // cursor start NEXT POSITION
	 delay(250);
	 lcd_data('R');
	 delay(50);

	 lcd_cmd(0xc5);	 // cursor start NEXT POSITION
	 delay(250);
	 lcd_data('K');
	 delay(50);

	 lcd_cmd(0xc6);	 // cursor start NEXT POSITION
	 delay(250);
	 lcd_data('A');
	 delay(50);

	 lcd_cmd(0xc7);	 // cursor start NEXT POSITION
	 delay(250);
	 lcd_data('R');
	 delay(50);

	 //lcd_cmd(0x0F);

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