#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

const char *ssid = "eYantra";
const char *password = "eyantra@bs15";

ESP8266WebServer server(80);
Servo servo1;
Servo servo2;
Servo servo3;

int sliderValue1 = 0; // Initial position for servo1
int sliderValue2 = 90; // Initial position for servo2
int sliderValue3 = 45; // Initial position for servo3

const char *htmlContent = R"=====(<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Servo Control</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
      margin-top: 50px;
    }
    input[type="range"] {
      width: 80%;
      margin-bottom: 20px;
    }
    #sliderValue1, #sliderValue2, #sliderValue3 {
      font-size: 18px;
    }
  </style>
</head>
<body>
  <h1>Finger Control</h1>
  <label for="slider1">Servo 1:</label>
  <input type="range" id="slider1" min="0" max="140" value="0" step="1" oninput="updateSliderValue(1)">
  <p id="sliderValue1">Slider Value 1: 0</p>

  <label for="slider2">Servo 2:</label>
  <input type="range" id="slider2" min="10" max="90" value="90" step="1" oninput="updateSliderValue(2)">
  <p id="sliderValue2">Slider Value 2: 90</p>

  <label for="slider3">Servo 3:</label>
  <input type="range" id="slider3" min="0" max="180" value="45" step="1" oninput="updateSliderValue(3)">
  <p id="sliderValue3">Slider Value 3: 45</p>

  <script>
    function updateSliderValue(servoNumber) {
      var sliderId = "slider" + servoNumber;
      var valueId = "sliderValue" + servoNumber;
      
      var slider = document.getElementById(sliderId);
      var sliderValueDisplay = document.getElementById(valueId);
      
      sliderValueDisplay.textContent = "Slider Value " + servoNumber + ": " + slider.value;
      sendSliderValue(servoNumber, slider.value);
    }

    function sendSliderValue(servoNumber, value) {
      var xhr = new XMLHttpRequest();
      xhr.open("GET", "/setSliderValue?servo=" + servoNumber + "&value=" + value, true);
      xhr.send();
    }
  </script>
</body>
</html>)=====";

void handleSlider() {
  if (server.hasArg("servo") && server.hasArg("value")) {
    int servoNumber = server.arg("servo").toInt();
    int sliderValue = server.arg("value").toInt();
    
    Serial.print("Slider Value Received for Servo ");
    Serial.print(servoNumber);
    Serial.print(": ");
    Serial.println(sliderValue);

    // Map the slider value to the servo angle
    int servoAngle = map(sliderValue, 0, (servoNumber == 1 ? 140 : (servoNumber == 2 ? 90 : 180)), 0, (servoNumber == 1 ? 140 : (servoNumber == 2 ? 90 : 180)));
    
    // Move the corresponding servo to the specified angle
    if (servoNumber == 1) {
      servo1.write(servoAngle);
      delay(15);
    } else if (servoNumber == 2) {
      servo2.write(servoAngle);
      delay(15);
    } else if (servoNumber == 3) {
      servo3.write(servoAngle);
      delay(15);
    }
  }
  server.send(200, "text/html", htmlContent);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Connecting to WiFi...");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Attach the servos to GPIO pins D1, D3, and D5
  servo1.attach(D1);
  servo2.attach(D3);
  servo3.attach(D5);

  // Define the endpoint for receiving slider values
  server.on("/setSliderValue", HTTP_GET, handleSlider);

  // Handle root endpoint
  server.on("/", HTTP_GET, [](){
    server.send(200, "text/html", htmlContent);
  });

  // Start the server
  server.begin();
}

void loop() {
  server.handleClient();
}
