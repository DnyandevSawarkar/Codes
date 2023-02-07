/****************************************************
       Lesson  : 8
 	   Neme    : LCD Interface
	   Details : The LCD has two line and each line has 16 character
	   			 the lcd works here 4 bit mode 
				 the display show "welcome" on first line
				 and "have a nice day" on second line 
******************************************************/
#include<reg51.h>

sbit RS = P3^7;   //Register select (RS) pin
sbit RW = P3^1;   //Read write (RW) pin
sbit EN = P3^5;   //Enable (EN) pin
unsigned char c;
int num[10];	// array to save

void delay(int ms)    // Time delay function
{
int j,k;
for(j=0;j<=ms;j++)
  for(k=0;k<=300;k++);
}

void lcd_cmd(unsigned char z)   // Funtion to send command on LCD
{         
P2 = z;
EN = 1;
RS = 0;
RW = 0;
delay(1);
EN = 0;
return;
}
void lcd_data(unsigned char x)
{
  P2 = x;
  RW = 0;
  RS = 1;
  EN = 1;
  delay(1);
  EN = 0;
 }

void lcd_val(unsigned int i)     //Function to send data on LCD
{   
int p;
int k=0;
//seperate digits of number and store in array 
// 581 = 05    08    01
while(i>0)
{
  num[k]=i%10;	 // save a digit into array
  i=i/10;		 // remove same digit from number
  k++;
}
k--;
// send each digit to LCD
for (p=k;p>=0;p--)
{
  c=num[p]+48;		// to get ASCII code of digit
  P2 = c;
  RW = 0;
  RS = 1;
  EN = 1;
  delay(1);
  EN = 0;
}
return;
}

void main()
{
//Initialisation
unsigned int v=250,w;
lcd_cmd(0x38);    // Configuring settings to 8-bit 2 row 
delay(2);
lcd_cmd(0x0E); 
delay(2);
lcd_cmd(0x06);    //Display on
delay(2);
lcd_cmd(0x81);    //Set cursor to blink at line 1 positon 1
delay(2);

// loop to display table
for(w=0;w<50;w++)
{
lcd_cmd(0x81);
lcd_val(v);
delay(500);
v=v+5;
}
//while(1);
}