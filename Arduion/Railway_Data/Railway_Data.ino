#include <WiFi.h>
#include "time.h"
#include <WiFiUdp.h>
#include "FS.h"
#include "SD.h"
#include "SPI.h"

#define SD_MOSI      23
#define SD_MISO      19
#define SD_SCK       14

#define SD_CS_PIN 15

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 18000; /*GMT OFFSET +5 HOURS(18000 SEC)*/
const int   daylightOffset_sec = 3600; /*1 hour daylight offset*/

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);


File myFile;
SPIClass SPISD(HSPI);

const int OUT_PIN = 18;
const int SAMPLE_TIME = 10;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int sampleBufferValue = 0;

void appendFile(fs::FS &fs, const char * path, char* message){
  Serial.printf("Appending to file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if(!file){
    Serial.println("Failed to open file for appending");
    return;
  }
  if(file.print(message)){
    Serial.println("Message appended");
  }
  else {
    Serial.println("Append failed");
  }
  file.close();
}


void setup() {
  // Init Serial Monitor
 // Serial.begin(9600);
  Serial.begin(115200);
  SPISD.begin(SD_SCK, SD_MISO, SD_MOSI);
  WiFi.begin("12345","Yash#1291");
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  timeClient.begin();
  Serial.begin(9600);
  if (!SD.begin(SD_CS_PIN,SPISD)){
    Serial.println("Card Mount Failed");
     return;
  }
  else 
    Serial.println(F("SD read!"));
}

String datastring ="";
void loop()
 {
  timeClient.update();
  String formattedTime = timeClient.getFormattedTime();

  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  if (digitalRead(OUT_PIN) == LOW) {
 
    sampleBufferValue++;
  }

  if (millisElapsed > SAMPLE_TIME) {   
  Serial.println(sampleBufferValue); 
  int val = analogRead(34);
  Serial.println("analog value"+String(val));
  datastring ="Time";
  datastring = formattedTime;
  datastring
  sampleBufferValue = 0;
  millisLast = millisCurrent;
  } 
 }