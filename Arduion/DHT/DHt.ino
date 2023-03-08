//Libraries
#include <DHT.h>
//Constants
#define DHTPIN 3
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
float hum; 
float temp; 
void setup()
{
  Serial.begin(9600);
	dht.begin();   
}

void loop()
{
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(2000); //Delay 2 sec.
}

   