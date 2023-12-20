/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp8266-nodemcu-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*
// Hanging ESP

#include <ESP8266WiFi.h>
#include <espnow.h>

#define hanging1 D0
#define hanging2 D1
#define hanging3 D2
#define hanging4 D3

#define Curtain_motor45er646dtt

void Hanging(){
  
}
// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
  int a;
  int b;
  int c;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  
  
  if(myData.c==1){
    Serial.print("Salve 3 ");
  Serial.println(myData.c);
    digitalWrite(hanging1,HIGH);
  delay(2500);

  digitalWrite(hanging2,HIGH);
  delay(2500);
  
  digitalWrite(hanging3,HIGH);
  delay(2500);
  
  digitalWrite(hanging4,HIGH);
    delay(500);

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

  pinMode(hanging1,OUTPUT);
  pinMode(hanging2,OUTPUT);
  pinMode(hanging3,OUTPUT);
  pinMode(hanging4,OUTPUT);
  
  digitalWrite(hanging1,LOW);
  digitalWrite(hanging2,HIGH);
  digitalWrite(hanging3,LOW);
  digitalWrite(hanging4,HIGH);

  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  
}



#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <espnow.h>

#define hanging1 D0
#define hanging2 D1
#define hanging3 D2
#define hanging4 D5

typedef struct message {
   int red;
   int green;
   int blue;
} message;

message myMessage;
void onDataReceiver(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
   Serial.println("Message received.");
   // We don't use mac to verify the sender
   // Let us transform the incomingData into our message structure
  memcpy(&myMessage, incomingData, sizeof(myMessage));
  Serial.print("Red:");
  Serial.println(myMessage.red); 
  
}
void setup() {
  Serial.begin(115200);
   pinMode(hanging1,OUTPUT);
  pinMode(hanging2,OUTPUT);
  pinMode(hanging3,OUTPUT);
  pinMode(hanging4,OUTPUT);
  
  digitalWrite(hanging1,HIGH);
  digitalWrite(hanging2,HIGH);
  digitalWrite(hanging3,HIGH);
  digitalWrite(hanging4,HIGH);
  WiFi.disconnect();
  ESP.eraseConfig();
 
  // Wifi STA Mode
  WiFi.mode(WIFI_STA);
  // Get Mac Add
  Serial.print("Mac Address: ");
  Serial.print(WiFi.macAddress());
  Serial.println("\nESP-Now Receiver");
  
  // Initializing the ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Problem during ESP-NOW init");
    return;
  }
  
  //esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  // We can register the receiver callback function
  esp_now_register_recv_cb(onDataReceiver);
}

void loop(){
  if(myMessage.red == 0)
  {
    digitalWrite(hanging1,LOW);
    delay(2000);

    digitalWrite(hanging2,LOW);
    delay(2000);
    
    digitalWrite(hanging3,LOW);
    delay(2000);
  
    digitalWrite(hanging4,LOW);
 
  }
}**/

#include <ESP8266WiFi.h>
#include <espnow.h>

#define led1Pin D1
#define led2Pin D2
#define led3Pin D3
#define led4Pin D4

typedef struct message {
  int esp_1;
  int esp_2;
} message;

message myMessage;

void onDataReceiver(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myMessage, incomingData, sizeof(myMessage));
  Serial.println(myMessage.esp_1);
  Serial.println("8");
  if (myMessage.esp_1 == 1) {
    Serial.println("1");
    digitalWrite(led1Pin, LOW);
    delay(600);
    //digitalWrite(led1Pin, LOW);
    Serial.println("2");
    digitalWrite(led2Pin, LOW);
    delay(600);
    //digitalWrite(led2Pin, LOW);
    Serial.println("3");
    digitalWrite(led3Pin, LOW);
    delay(600);
    //digitalWrite(led3Pin, LOW);
    Serial.println(".............................");
    digitalWrite(led4Pin, LOW);
    //delay(2000);
    //digitalWrite(led4Pin, LOW);
  }
}

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  digitalWrite(led4Pin, HIGH);
  digitalWrite(led3Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  digitalWrite(led1Pin, HIGH);
  Serial.begin(115200);
  // Initialize ESP-NOW
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register the receiver callback function
  esp_now_register_recv_cb(onDataReceiver);
}

void loop() {
  // You can add non-blocking code here if needed.
}
