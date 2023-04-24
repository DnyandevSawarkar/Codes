#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
/*
#include <DHT.h>

#define DHTPIN D3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
float hum; 
float temp; 
*/
#define WIFI_SSID "12345"
#define WIFI_PASS "Yash#1209"

#define MQTT_SERV "io.adafruit.com"
#define MQTT_PORT 1883
#define MQTT_NAME "Yash_0980"
#define MQTT_PASS "aio_omWU48TG75sW7nd4SbDL27oDCJd3"


//int led = D3;

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, MQTT_SERV, MQTT_PORT, MQTT_NAME, MQTT_PASS);

Adafruit_MQTT_Subscribe Control = Adafruit_MQTT_Subscribe(&mqtt, MQTT_NAME "/f/Control");
Adafruit_MQTT_Publish State = Adafruit_MQTT_Publish(&mqtt, MQTT_NAME "/f/State");

//Adafruit_MQTT_Publish Temp_State = Adafruit_MQTT_Publish(&mqtt, MQTT_NAME "/f/Temp");
//Adafruit_MQTT_Publish Hum_State = Adafruit_MQTT_Publish(&mqtt, MQTT_NAME "/f/Hum");


void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);


  //Connect to WiFi
  Serial.print("\n\nConnecting Wifi>");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  //digitalWrite(LED_BUILTIN, LOW);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(">");
    delay(50);
  }

  Serial.println("OK!");

  //Subscribe to the Control topic
  mqtt.subscribe(&Control);
  //dht.begin();

  //pinMode(led, OUTPUT);
  //digitalWrite(LED_BUILTIN, HIGH);
  //igitalWrite(led, LOW);

}

void loop()
{
  //Connect/Reconnect to MQTT
  MQTT_connect();
  
  //hum = dht.readHumidity();
  //temp= dht.readTemperature();

  //Read from our subscription queue until we run out, or
  //wait up to 5 seconds for subscription to update
  Adafruit_MQTT_Subscribe * subscription;
  while ((subscription = mqtt.readSubscription(5000)))
  {
    //If we're in here, a subscription updated...
    if (subscription == &Control)
    {
      /*
      Serial.println(hum);
      Serial.println(temp);
      Serial.println();
      Serial.println();

      Temp_State.publish(temp);
      Hum_State.publish(hum);
      */

      //Print the new value to the serial monitor
      Serial.print("Control: ");
      Serial.println((char*) Control.lastread);

      //If the new value is  "ON", turn the light on.
      //Otherwise, turn it off.
      if (!strcmp((char*) Control.lastread, "ON"))
      {
        //active low logic
        digitalWrite(LED_BUILTIN, HIGH);
        State.publish("ON");
      }
      else if (!strcmp((char*) Control.lastread, "OFF"))
      {
        digitalWrite(LED_BUILTIN, LOW);
        State.publish("OFF");

      }
      else
      {
        State.publish("ERROR");
      }
    }
    else
    {
      //State.publish("ERROR");
    }
  }
  //  if (!mqtt.ping())
  //  {
  //    mqtt.disconnect();
  //  }
}


void MQTT_connect()
{

  //  // Stop if already connected
  if (mqtt.connected() && mqtt.ping())
  {
    //    mqtt.disconnect();
    return;
  }

  int8_t ret;

  mqtt.disconnect();

  Serial.print("Connecting to MQTT... ");
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) // connect will return 0 for connected
  {
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0)
    {
      Serial.println("Retrying MQTT NOT connection ");
    }
  }
  Serial.println("MQTT Connected!");
}
