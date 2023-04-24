#define BLYNK_TEMPLATE_ID "TMPL3TFXqKaHo"
#define BLYNK_TEMPLATE_NAME "EXPT7"
#define BLYNK_AUTH_TOKEN "pKaX0HJGi4fkQ-Ut_N0MoSf0CHLdT9ug"

#define BLYNK_PRINT Serial

#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "12345";
char pass[] = "Yash#1209";

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 0)
  {
    digitalWrite(D3, HIGH);  
  }
  if(value == 1)
  {
    digitalWrite(D3, LOW);
  }
}

void setup()
{
  pinMode(D3,OUTPUT);
  Serial.begin(115200);
  //digitalWrite(0,HIGH);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
