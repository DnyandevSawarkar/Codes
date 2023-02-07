#include <esp_now.h>
#include <WiFi.h>

//s2
int SensorPIN = 23;
int State ;

uint8_t MasterAddress[]={0x0C, 0xB8, 0x15, 0xD8, 0xEB, 0x10};

typedef struct struct_message{
  int id;
  int Passing_State;
}struct_message;

struct_message myData;

esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t mesh_status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(mesh_status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  
  pinMode(SensorPIN,INPUT);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

  memcpy(peerInfo.peer_addr, MasterAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}

bool Detect_train()
{
  int i = digitalRead(SensorPIN);
  int j = i;
  delay(100);

  i = digitalRead(SensorPIN);

  if(i==j)
  {
    Serial.println("Train Detected");
    return true;
  }
  else
  {
    Serial.print("Train NOT Detected");
    return false;
  }
}

bool Passing()
{
  if((analogRead(SensorPIN)>=300) && Detect_train())
  {
    State = 1;
    return true;
  }
  else{
    State = 0;
    return false;
  }
}

void loop()
{
  myData.id = 2;
  while(Passing()){
    //send 1 to master
    myData.Passing_State = State;
    esp_err_t result = esp_now_send(MasterAddress, (uint8_t *) &myData, sizeof(myData));
    
    if (result == ESP_OK) {
    Serial.println("Sent with success");
    }
  }
}