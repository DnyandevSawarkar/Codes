#include <SPI.h>
#include <LoRa.h>
#define ss 18
#define rst 14
#define dio0 26

int sharp = 0;
int sound = 0;
 
void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender"); 
  LoRa.setPins(ss, rst, dio0);

  while (!LoRa.begin(433E6))
 
   {
 
      Serial.println(".");
 
      delay(500);
   }
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
 
}

void loop() {
  int sound = analogRead(37);
  int sharp = analogRead(36); 
  Serial.println("Sending packet: ");
  Serial.print("Audio value : "+String(sound)+"\t");
  Serial.println("sharp value : "+String(sharp));
 
 if(sound >250 && sharp >2200)
 
 {
   LoRa.beginPacket();
   LoRa.print("1");
  LoRa.endPacket();
  delay(100);
  }
 else
 
 { 
   LoRa.beginPacket();
  LoRa.print("0");
  LoRa.endPacket();
  delay(100);   
 
 }

 
}