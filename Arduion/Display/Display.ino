#include "lcd.c"

void setup()
{
 DDRC = DDRC | 0xF7;     //all the LCD pin's direction set as output
 PORTC = PORTC & 0x08;  // all the LCD pins are set to logic 0 except PORTC 7
 lcd_set_4bit();        // initialize LCD in 4 bit mode 
 lcd_clear();           // clear lcd screen
 delay(10);
 
}
 
 void loop()
  {
    lcd_cursor(1,4);   // set row 1 coloumn 4
    lcd_string("Firebird V");
    lcd_cursor(2,5);  // set row 2 coloumn 5
    lcd_string("e-Yantra");
  }


