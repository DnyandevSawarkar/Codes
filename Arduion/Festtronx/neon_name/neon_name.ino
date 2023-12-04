/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp8266-nodemcu-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/
// neon ESP

#include <ESP8266WiFi.h>
#include <espnow.h>

#define led1Pin D1 // motor
#define led2Pin D2


#define Curtain_motor45er646dtt

// Structure example to receive data
// Must match the sender structure
typedef struct message {
  int esp_1;
  int esp_2;
} message;

// Create a struct_message called myData
message myMessage;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myMessage, incomingData, sizeof(myMessage));
  
  
  Serial.println(myMessage.esp_2);Serial.println("9999");
  if (myMessage.esp_2 == 1) {
    Serial.println("1");
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    delay(1500);
    digitalWrite(led1Pin, LOW);
  }
  Serial.println();
  
}



void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  pinMode(led1Pin,OUTPUT);
  pinMode(led2Pin,OUTPUT);
  digitalWrite(led1Pin,LOW);
  digitalWrite(led2Pin,LOW);
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  
}
