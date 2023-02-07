#include "lcd.c"

int motorPin1 = 23;
int motorPin2 = 22;
int motorPin3 = 24;
int motorPin4 = 25;
int pwm1=45;
int pwm2=46;

unsigned int value=10;
unsigned char x;
void setup()
{
 DDRC = DDRC | 0xF7; //all the LCD pin's direction set as output
 PORTC = PORTC & 0x80; // all the LCD pins are set to logic 0 except PORTC 7
 lcd_clear();
 delay(10);
 lcd_set_4bit();

 pinMode( motorPin1,OUTPUT);
pinMode( motorPin2,OUTPUT);
pinMode( motorPin3,OUTPUT);
pinMode( motorPin4,OUTPUT);
pinMode( pwm1,OUTPUT);
pinMode( pwm2,OUTPUT);

digitalWrite(pwm1, HIGH);
digitalWrite(pwm2, HIGH);
}
 
 void loop()
  {
    
    if((PINE&0x80)==0)
    {
      lcd_cursor(1,3);
      lcd_string("Forward");
      delay(1000);
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
      delay(2000);

      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
    }
  }


