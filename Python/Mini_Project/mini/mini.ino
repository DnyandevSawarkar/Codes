#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

 //Specifying the SSID and Password of the AP//
 
const char* esp_ssid = "123450"; //Access Point SSID
const char* esp_password= "SoftAP@12"; //Access Point Password
uint8_t max_connections=8;//Maximum Connection Limit for AP
int current_stations=0, new_stations=0;
 
//Specifying the Webserver instance to connect with HTTP Port: 80
ESP8266WebServer server(80);
 
//Specifying the Pins connected from LED
const int led_blue=D1;
const int led_red=D2;

Servo myservo;                  // Create a servo object to control a servo
const int servo_pin = D4;

const int trigpin = D5;
const int echopin = D6;

//Specifying the boolean variables indicating the status of LED1 to LED4
bool gate_status=false;
 
long duration;
int distance;

void setup() {
  //Start the serial communication channel
  Serial.begin(115200);
  Serial.println();
 
  //Output mode for the LED Pins
  pinMode(servo_pin,OUTPUT);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin,INPUT);

  pinMode(led_blue,OUTPUT);
  pinMode(led_red,OUTPUT);

  myservo.attach(servo_pin);
   
  //Setting the AP Mode with SSID, Password, and Max Connection Limit

  //WiFi.softAP(ssid, pass, channel, hidden, max_connection)
  if(WiFi.softAP(esp_ssid,esp_password,1,false,max_connections)==true)
  {/*
    Serial.print("Access Point is Created with SSID: ");
    Serial.println(esp_ssid);
    Serial.print("Max Connections Allowed: ");
    Serial.println(max_connections);
    Serial.print("Access Point IP: ");
    Serial.println(WiFi.softAPIP());*/
  }
  else
  {
    //Serial.println("Unable to Create Access Point");
  }
 
  //Specifying the functions which will be executed upon corresponding GET request from the client
  server.on("/",handle_OnConnect);
  server.on("/open",handle_open);
  server.on("/close",handle_close);
  server.onNotFound(handle_NotFound);
   
  //Starting the Server
  server.begin();
  Serial.println("HTTP Server Started");
}
 
void loop() {
  //Assign the server to handle the clients
  server.handleClient();
     
  //Continuously check how many stations are connected to Soft AP and notify whenever a new station is connected or disconnected
  new_stations=WiFi.softAPgetStationNum();
   
  if(current_stations<new_stations)//Device is Connected
  {
    current_stations=new_stations;
    //Serial.print("New Device Connected to SoftAP... Total Connections: ");
    //Serial.println(current_stations);
  }
   
  if(current_stations>new_stations)//Device is Disconnected
  {
    current_stations=new_stations;
    //Serial.print("Device disconnected from SoftAP... Total Connections: ");
    //Serial.println(current_stations);
  }
 
  //Turn the LEDs ON/OFF as per their status set by the connected client
   
  //LED
  if(gate_status==false)
  {
    myservo.write(0);
    digitalWrite(led_red,HIGH);
    digitalWrite(led_blue,LOW);
    delay(200);
  }
  else
  {
    digitalWrite(led_blue,HIGH);
    digitalWrite(led_red,LOW);
    myservo.write(100);
    delay(5000);
  }

  digitalWrite(trigpin,LOW);
  delay(2);
  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration*0.034)/2;
  Serial.println(int(distance));
}
 
void handle_OnConnect()
{
  Serial.println("Client Connected");
  server.send(200, "text/html", HTML());  
}
 
void handle_open()
{
  //Serial.println("");
  gate_status=true;
  server.send(200, "text/html", HTML());
  delay(3000);
}
 
void handle_close()
{
  //Serial.println("LED OFF");
  gate_status=false;
  server.send(200, "text/html", HTML());
}
  
void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}
 
String HTML()
{
  String msg="<!DOCTYPE html> <html>\n";
  msg+="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  msg+="<title>Gate Control</title>\n";
  msg+="<style>html{font-family:Helvetica; display:inline-block; margin:0px auto; text-align:center;}\n";
  msg+="body{margin-top: 50px;} h1{color: #444444; margin: 50px auto 30px;} h3{color:#444444; margin-bottom: 50px;}\n";
  msg+=".button{display:block; width:80px; background-color:#f48100; border:none; color:white; padding: 13px 30px; text-decoration:none; font-size:25px; margin: 0px auto 35px; cursor:pointer; border-radius:4px;}\n";
  msg+=".button-on{background-color:#f48100;}\n";
  msg+=".button-on:active{background-color:#f48100;}\n";
  msg+=".button-off{background-color:#26282d;}\n";
  msg+=".button-off:active{background-color:#26282d;}\n";
  msg+="</style>\n";
  msg+="</head>\n";
  msg+="<body>\n";
  msg+="<h1>Automatic Garage Door</h1>\n";
  msg+="<h3>Using ESP8266 and opencv</h3>\n";
   
  if(gate_status==false)
  {
    msg+="<p>Gate Status: OFF</p><a class=\"button button-on\" href=\"/open\">ON</a>\n";    
  }
  else
  {
    msg+="<p>Gate Status: ON</p><a class=\"button button-off\" href=\"/close\">OFF</a>\n";
  }
  msg+="</body>\n";
  msg+="</html>\n";
  return msg;
}
