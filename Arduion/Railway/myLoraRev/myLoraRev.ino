#include <SPI.h>
#include <LoRa.h>
#define ss 5
#define rst 14
#define dio0 2

void setup() {

  Serial.begin(115200);
  pinMode(33, OUTPUT);
  while (!Serial)
    ;
  Serial.println("LoRa Receiver");
  LoRa.setPins(ss, rst, dio0);
  while (!LoRa.begin(433E6)) {

    Serial.println(".");
    delay(500);
  }

  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() {

  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet '");
    while (LoRa.available()>0) {
      String LoRaData = LoRa.readString();
      Serial.println(LoRaData);
      if (LoRaData == "1")
      {
        digitalWrite(33, HIGH);
        Serial.println("detect");
        delay(2000);
      }
      else
      {
        digitalWrite(33, LOW);
        Serial.println("not detect");
      }

    }
  }
  // Serial.println("ajhjsc");
}