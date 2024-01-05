#include <TM1637Display.h>
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define CLK_PIN  D1 // define CLK pin (any digital pin)
#define DIO_PIN  D2 // define DIO pin (any digital pin)

TM1637Display display(CLK_PIN, DIO_PIN);

// Define your WiFi credentials
const char *ssid = "Airtel_Deltax21";
const char *password = "Yash#12098";

// Define NTP settings for Kolkata, India
const char *ntpServerName = "asia.pool.ntp.org";
const long gmtOffset_sec = 5 * 3600 + 30 * 60; // UTC+5:30 for India
const int daylightOffset_sec = 0;              // No daylight saving time for India

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServerName, gmtOffset_sec, daylightOffset_sec);

unsigned long lastDisplayUpdate = 0; // Variable to store the millis() value of the last display update
const unsigned long displayUpdateInterval = 1000; // Update display every 1000 milliseconds (1 second)

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Initialize the TM1637 display
  display.setBrightness(0x0f); // Set the brightness level (0x00 to 0x0f)

  // Initialize the NTP client
  timeClient.begin();
}

void loop() {
  // Update the current time
  timeClient.update();

  int hours = timeClient.getHours();
  int minutes = timeClient.getMinutes();

  // Combine hours and minutes into a single value for display
  int time = hours * 100 + minutes;

    display.showNumberDecEx(time, 0b11100000, true);
    Serial.println(time);
  //}

  // You can adjust the delay if needed, but it's not necessary for continuous display
  // delay(100);
}
