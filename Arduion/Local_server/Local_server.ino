#include <ESP8266WiFi.h>
 
const char* ssid = "1234";
const char* password = "Yash@Test";

WiFiServer server(80);
 
void setup() 
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("\n");
  WiFi.softAP(ssid, password);
  Serial.println("WiFi initialized  ");
 
 /*-------- server started---------*/ 
  server.begin();
  Serial.println("Server started");
 
  /*------printing ip address--------*/
  Serial.print("IP Address of network: ");
  Serial.println(WiFi.softAPIP());
  Serial.print("Copy and paste the following URL: http://");
  Serial.print(WiFi.softAPIP());
  Serial.println("/");
  Serial.println();
}
 
void loop() 
{
  WiFiClient client = server.available();    
  if (!client) 
  {
    return;
  }
  Serial.println("Waiting for new client");   
  while(!client.available())
  {
    delay(1);
  }
 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush(); // wait till buffering end
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Turn ON Led");
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  
  {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Turn OFF Led");
    value = LOW;
  }
 
/*------------------Creating html page---------------------*/
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>"); // starting
 
  client.print("LED is: ");
 
  if(value == HIGH) 
  {
    client.print("ON");
  } 
  else 
  {
    client.print("OFF");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>OFF</button></a><br />");  
  client.println("</html>"); // ending
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
