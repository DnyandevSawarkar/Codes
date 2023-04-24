
#include <esp_now.h>
#include <WiFi.h>

//
int SensorPIN = 2;

// Master MAC Address
uint8_t broadcastAddress[] = {0x0C, 0xB8, 0x15, 0xD8, 0xEB, 0x10};

// Structure  to send data
typedef struct struct_message {
    int id; // Slave ID
    int x;  // Train Passing Status
} struct_message;

// Create a struct_message called myData
struct_message myData;

// Create peer interface
esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  //Serial.print("\r\nLast Packet Send Status:\t");
  //Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    //Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    //Serial.println("Failed to add peer");
    return;
  }
}
int in1 = 1;
int in2 = 0;
void loop() {
  int i = analogRead(26);
  Serial.println(i);
  
  // Set values to send
  myData.id = 1;
  
  //if((2515<=i)&&(i>=2525)){

    //myData.x = in1;
  //}
  //else{
    //myData.x = in2;
  //}
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    //Serial.println("Sent with success");
  }
  else {
    //Serial.println("Error sending the data");
  }
  delay(1000);
}