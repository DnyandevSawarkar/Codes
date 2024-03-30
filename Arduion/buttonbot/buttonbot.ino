// Load Wi-Fi library
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

void carforward();
void carbackward();
void carturnleft();
void carturnright();
void carStop();

void startloop();

#define speed 100
#define t_speed 50

#define del 1000
#define t_del 200

// Replace with your network credentials
const char *ssid = "yourAP";
const char *password = "yourPassword";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
int m1p1 = 18;
int m1p2 = 19;
int m2p1 = 23;
int m2p2 = 32;
int m1en = 5;
int m2en = 33;

int list[20];
int count = 0;
int f = 1;
int b = 2;
int l = 3; 
int r = 4;
int s = 0;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(m1en, OUTPUT);
  pinMode(m2en, OUTPUT);
  // Set outputs to LOW
  carStop();

  // Connect to Wi-Fi network with SSID and password
  Serial.println();
  Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  // a valid password must have more than 7 characters
  if (!WiFi.softAP(ssid, password)) {
    log_e("Soft AP creation failed.");
    while(1);
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /front") >= 0) {
              list[count] = f;
              count++;

            } else if (header.indexOf("GET /back") >= 0) {
              list[count] = b;
              count++;

            } else if (header.indexOf("GET /left") >= 0) {
              list[count] = l;
              count++;

            } else if (header.indexOf("GET /right") >= 0) {
              list[count] = r;
              count++;

            } else if (header.indexOf("GET /start") >= 0) {
              list[count] = s;
              startloop();

            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println("</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 26  
            //client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // If the output26State is off, it displays the ON button       
            client.println("<p><a href=\"/front\"><button class=\"button\">FRONT</button></a></p>");

               
            // Display current state, and ON/OFF buttons for GPIO 27  
            //client.println("<p>GPIO 27 - State " + output27State + "</p>");
            // If the output27State is off, it displays the ON button       
            client.println("<p><a href=\"/back\"><button class=\"button\">BACK</button></a></p>");

            client.println("<p><a href=\"/right\"><button class=\"button\">RIGHT</button></a></p>");
            client.println("<p><a href=\"/left\"><button class=\"button\">LEFT</button></a></p>");
            client.println("<p><a href=\"/start\"><button class=\"button\">START</button></a></p>");

            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

void carforward() {
  analogWrite(m1en, speed);
  analogWrite(m2en, speed);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  delay(del);
}
void carbackward() {
  analogWrite(m1en, speed);
  analogWrite(m2en, speed);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  delay(del);
}
void carturnleft() {
  analogWrite(m1en, t_speed);
  analogWrite(m2en, t_speed);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  delay(t_del);
}
void carturnright() {
  analogWrite(m1en, t_speed);
  analogWrite(m2en, t_speed);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  delay(t_del);
}
void carStop() {
  analogWrite(m1en, 0);
  analogWrite(m2en, 0);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, LOW);
}

void startloop() {
  for(int i = 0; i <= 20; i++)
  {
    if (list[i] == s)
      break;

    else if (list[i] == f) {
      carforward();
      carStop();
    }
    else if (list[i] == b) {
      carbackward();
      carStop();
    }
    else if (list[i] == l) {
      carturnleft();
      carforward();
      carStop();
    }
    else if (list[i] == r) {
      carturnright();
      carforward();
      carStop();
    }
  }
  list[0] = s;
  count = 0;
}
