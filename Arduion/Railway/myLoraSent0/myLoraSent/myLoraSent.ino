#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define ss 18
#define rst 14
#define dio0 26
/////////////////////////////////////////
int sharp = 0;
int sound = 0;
////////////////////////////////////////


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
  //int sound = analogRead(37);
  int sharp = analogRead(36);
  Serial.println("Sending packet: ");
  //Serial.print("Audio value : "+String(sound)+"\t");
  Serial.println("sharp value : "+String(sharp));
  int sound_add =0;

  for(int i=0;i<10;i++){
    int sound = analogRead(37);
    int sound_new = 167.5 - sound;
    if(sound_new <0){
      sound = sound_new*(-1);
    }
    else{
      sound = sound_new;
    }
    Serial.println(sound);
    sound_add = sound_add+sound;
  }
  Serial.println(sound_add);
  Serial.println(sound_add/10);
delay(2000);
 if((250 << sharp <2500))// && (sound >15) )
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
































  
  // Serial.println("sound value :"+String(sampleBufferValue));
  //   Serial.println("analog value : "+String(sharp_data));
  // counter = analogRead(36);
  // Serial.print("Sending packet: ");
  // Serial.println(counter);

  // //Send LoRa packet to receiver
  // LoRa.beginPacket();
  // LoRa.print("hello ");
  // LoRa.print(counter);
  // LoRa.endPacket();
