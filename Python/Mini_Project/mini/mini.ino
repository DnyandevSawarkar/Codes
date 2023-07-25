#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
 
const char* esp_ssid = "123450"; 
const char* esp_password= "SoftAP@12"; 
uint8_t max_connections=8;
int current_stations=0, new_stations=0;

ESP8266WebServer server(80);

const int led_blue=D1;
const int led_red=D2;

Servo myservo;         
const int servo_pin = D4;

const int trigpin = D5;
const int echopin = D6;

bool gate_status=false;
 
long duration;
int distance;

void setup() {
  
  Serial.begin(115200);
  Serial.println();
 
  pinMode(servo_pin,OUTPUT);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin,INPUT);

  pinMode(led_blue,OUTPUT);
  pinMode(led_red,OUTPUT);

  myservo.attach(servo_pin);

  if(WiFi.softAP(esp_ssid,esp_password,1,false,max_connections)==true)
  {
    //Serial.println("Created Access Point");
  }
  else
  {
    //Serial.println("Unable to Create Access Point");
  }
  server.on("/",handle_OnConnect);
  server.on("/open",handle_open);
  server.on("/close",handle_close);

  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP Server Started");
}
 
void loop() {
  server.handleClient();
  new_stations=WiFi.softAPgetStationNum();
  
  if(current_stations<new_stations)//Device is Connected
  {
    current_stations=new_stations;
  }
  if(current_stations>new_stations)//Device is Disconnected
  {
    current_stations=new_stations;
  }

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
  gate_status=true;
  server.send(200, "text/html", HTML());
  delay(3000);
}
 
void handle_close()
{
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
  msg+="</body></html>\n";
  return msg;
}
