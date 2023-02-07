// Slave 
// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String readP_state() {
  int i = analogRead(26);
  Serial.println(i);
  return String("HI");
  /*if((2515<=i)&&(i>=2525)){
    return String("1");
  }
  else{
    return String("0");
  }*/
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  

  server.on("/P_state", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readP_state().c_str());
  });
  
  
  // Start server
  server.begin();
}
 
void loop(){
  
}