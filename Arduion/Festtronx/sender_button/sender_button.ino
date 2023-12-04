
/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp8266-nodemcu-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.


#include <ESP8266WiFi.h>
#include <espnow.h>

#define switch_id D1
int switch_state;

// REPLACE WITH RECEIVER MAC Address
uint8_t broadcastAddress1[] = {0xC4, 0x5B, 0xBE, 0x64, 0x58, 0x79};
uint8_t broadcastAddress2[] = {0x48, 0x3F, 0xDA, 0x9D, 0xE6, 0xDD};
uint8_t broadcastAddress3[] = {0x34, 0xAB, 0x95, 0x24, 0xA5, 0x4C};


// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  int a;
  int b;
  int c;
} struct_message;

// Create a struct_message called myData
struct_message myData;

unsigned long lastTime = 0;  
unsigned long timerDelay = 2000;  // send readings timer

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0){
    Serial.println("Delivery success");
  }
  else{
    Serial.println("Delivery fail");
  }
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);
   pinMode(switch_id, INPUT_PULLUP);
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  //motor
  esp_now_add_peer(broadcastAddress1, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  //neon
  esp_now_add_peer(broadcastAddress2, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  // hanging
  esp_now_add_peer(broadcastAddress3, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}
void send_signal(){
    esp_now_send(broadcastAddress1, (uint8_t *) &myData, sizeof(myData));
    delay(1000);
    esp_now_send(broadcastAddress2, (uint8_t *) &myData, sizeof(myData));
    delay(2000);
    esp_now_send(broadcastAddress3, (uint8_t *) &myData, sizeof(myData));
    delay(500);
}
 
void loop() {
  
    // Set values to send
    switch_state = digitalRead(switch_id);
    //Serial.println(switch_state);
    if (switch_state == LOW) {
      myData.a = 1;
      myData.b = 1;
      myData.c = 1;
      Serial.println("ESP-NOW");
      send_signal();
      }
    else{
      myData.a = 0;
      myData.b = 0;
      myData.c = 0;
      Serial.println("ESP");
    }
    // Send message via ESP-NOW
    
   
  }



/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp8266-nodemcu-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

*/


/*
 * ESP-NOW
 * 
 * Sender
*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <espnow.h>

#define switch_id D1
int switch_state;

// Mac address of the slave
uint8_t peer1[] = {0xC4, 0x5B, 0xBE, 0x64, 0x58, 0x79};
uint8_t peer2[] = {0x48, 0x3F, 0xDA, 0x9D, 0xE6, 0xDD};
uint8_t peer3[] = {0x34, 0xAB, 0x95, 0x24, 0xA5, 0x4C};

typedef struct message {
   int esp_1;
   int esp_2;
};
struct message myMessage;
void onSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.println("Status:");
  Serial.println(sendStatus);
}
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  // Get Mac Add
  Serial.print("Mac Address: ");
  Serial.print(WiFi.macAddress());
  Serial.println("ESP-Now Sender");
  // Initializing the ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Problem during ESP-NOW init");
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  // Register the peer
  Serial.println("Registering a peer");
  
  
  esp_now_add_peer(peer2, ESP_NOW_ROLE_SLAVE, 1, NULL, 0); ////hang

  esp_now_add_peer(peer1, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  
  //esp_now_add_peer(peer3, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  Serial.println("Registering send callback function");
  esp_now_register_send_cb(onSent);
}
void loop() {
  switch_state = digitalRead(switch_id);
    Serial.println(switch_state);
    if (switch_state == HIGH) {
      myMessage.esp_1 = 1;
      myMessage.esp_2 = 1;
      Serial.println("ESP-NOW");
      //send_signal();
      }
    else{
      myMessage.esp_1 = 0;
      myMessage.esp_2 = 0;
      Serial.println("ESP");
    }
  Serial.println("Send a new message");
  esp_now_send(NULL, (uint8_t *) &myMessage, sizeof(myMessage));
  delay(1900);
}

