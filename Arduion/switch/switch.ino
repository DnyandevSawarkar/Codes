int buz=34;
void setup() 
{
DDRE=0x00;                                      //declares PORTE as input PORT
PORTE = 0x08;                                   //Activates Pull-up resistance on PORTE pin 7       
pinMode(buz, OUTPUT);
}

void loop() 
{

if((PINE&0x80)==0)                   //to check if the button is pressed or not 
  digitalWrite(buz,HIGH);              // buzzer on
  else
  digitalWrite(buz,LOW);              // buzzer off
}
