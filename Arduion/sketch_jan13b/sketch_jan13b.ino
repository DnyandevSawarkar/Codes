// Master
#include <WiFi.h>
#include <HTTPClient.h>

#define Green_led 22
#define White_led 21

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

//Your IP address or domain name with URL path
const char* serverNameP_state = "http://192.168.4.1/P_state";

String P_state;

unsigned long previousMillis = 0;
const long interval = 750; 

void setup() {
  Serial.begin(115200);
  pinMode(Green_led,OUTPUT);
  pinMode(White_led,OUTPUT);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED ){ 
      P_state = httpGETRequest(serverNameP_state);
      Serial.println("Analog Value: " + P_state );
      if(P_state=="1"){
        digitalWrite(Green_led,LOW);
        digitalWrite(White_led,HIGH);
      }
      else{
        digitalWrite(Green_led,HIGH);
        digitalWrite(White_led,LOW);
      }
      
      
      // save the last HTTP GET Request
      previousMillis = currentMillis;
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}