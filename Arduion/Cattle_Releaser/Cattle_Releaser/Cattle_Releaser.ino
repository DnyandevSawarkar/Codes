#include "DHT.h"

#define soil_pin A0

#define DHTPIN D1
#define DHTTYPE DHT11

#define relay_pin1 D5
#define relay_pin2 D6

int value_status = 0;

DHT dht(DHTPIN,DHTTYPE);

void setup(){

  pinMode(relay_pin1,OUTPUT);

  pinMode(relay_pin2,OUTPUT);
  Serial.begin(115200);

  dht.begin();
  
  digitalWrite(relay_pin1, LOW);
  digitalWrite(relay_pin2, LOW);
}

void loop(){
  delay(1500);
  
  // Plant 1
  int value1 = analogRead(soil_pin);

   // Read Humidity 
  float Hum = dht.readHumidity();
  
  // Read temperature as Celsius (the default)
  float temp_c = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(Hum) || isnan(temp_c) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Moisture Value :");
  Serial.println(value1);

  Serial.print("\nHumidity : ");
  Serial.println(Hum);

  Serial.print("\nTemperature : ");
  Serial.println(temp_c);

  Serial.print("\nValve Status :");

  if((value1 <= 570) || (temp_c >= 32))
    value_status = 1;
  else 
   value_status = 0;

  if(value_status == 1)
  {
    digitalWrite(relay_pin1, LOW);
    digitalWrite(relay_pin2, HIGH);
    Serial.println("UP");
    delay(10000);
    digitalWrite(relay_pin1, HIGH);
    digitalWrite(relay_pin2, LOW);
    Serial.println("DOWN");
    delay(10000);
  }
  else 
  {
    digitalWrite(relay_pin1, LOW);
    digitalWrite(relay_pin2, LOW);
    Serial.println("PASS");
  }
  
}