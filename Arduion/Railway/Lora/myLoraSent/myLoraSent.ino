// Heltech

#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define ss 18
#define rst 14
#define dio0 26

/////////////////////////////////////////
int sharp_data = 0;
// int sound_data = 13;
/////////////////////////////////////////

// Sound PINS
const int OUT_PIN = 13;
const int SAMPLE_TIME = 10;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int sampleBufferValue = 0;

void setup() {
 
  Serial.begin(115200);
  pinMode(13, INPUT); // sound sensor
  while (!Serial);
  
  Serial.println("LoRa Sender");

  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);
  

  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America

  while (!LoRa.begin(433E6)) /// Wait for lora init
   {
      Serial.println(".");
      delay(500);
   }
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() {

  /// Sound Sampling
  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;
  ///

  // Read Sound data
  if (digitalRead(OUT_PIN) == LOW) {
    sampleBufferValue++;
  }

  // Sampling
  if (millisElapsed > SAMPLE_TIME) 
  {
    sharp_data = analogRead(36);    // Sharp sensro value
    Serial.println("sound value :"+String(sampleBufferValue));
    Serial.println("analog value : "+String(sharp_data));

    // Lora transmission start
    LoRa.beginPacket();

    //if(2505 <=sharp_data && sampleBufferValue<300)
    //{
      LoRa.print("1");
    //}
    //else
    //{
     // LoRa.print("0");
    //}

    // End transmission
    LoRa.endPacket();

    sampleBufferValue = 0;
    millisLast = millisCurrent;

  }
/*
  Serial.println("sound value :"+String(sampleBufferValue));
  Serial.println("analog value : "+String(sharp_data));
  counter = analogRead(36);
  Serial.print("Sending packet: ");
  Serial.println(counter);
  //Send LoRa packet to receiver
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();
*/
}