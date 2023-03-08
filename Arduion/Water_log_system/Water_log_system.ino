const int trigPin = 26;
const int echoPin = 27;

const int Yellow_bulb = 5;
const int Red_bulb = 19;

const int float_pin = 4; //d4

bool Float_status;

long duration;
float distance;
int water_level;


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(115200); // Starts the serial communication
  pinMode(float_pin,INPUT_PULLUP);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(Red_bulb, OUTPUT); // Sets the trigPin as an Output
  pinMode(Yellow_bulb, OUTPUT); // Sets the trigPin as an Output
}

void water_level_moniter() {
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distance = duration *0.034/2;
  
  water_level = 74-distance;
  
  Serial.print("Water Level (cm): ");
  Serial.println(water_level);

  lcd.clear();

  if((10 <=water_level)&(water_level <=15)){
    Serial.println("warning L1");

    lcd.setCursor(0,0);
    lcd.print("Water Level:");
    lcd.setCursor(14,0);
    lcd.print(water_level);


    lcd.setCursor(0,1);
    lcd.print("Warning Level 1");
    digitalWrite(Yellow_bulb,HIGH);
  }
  else if((16 <=water_level)&(water_level <=21)){
    Serial.println("warning L2");
    
    lcd.setCursor(0,0);
    lcd.print("Water Level:");
    lcd.setCursor(14,0);
    lcd.print(water_level);

    lcd.setCursor(0,1);
    lcd.print("Warning Level 2");
    digitalWrite(Red_bulb,HIGH);
    digitalWrite(Yellow_bulb,LOW);
    delay(500);
    digitalWrite(Red_bulb,LOW);
    digitalWrite(Yellow_bulb,HIGH);
  }
  else if(22 <=water_level){
    Serial.println("Alert");
    
    lcd.setCursor(0,0);
    lcd.print("Water Level:");
    lcd.setCursor(14,0);
    lcd.print(water_level);

    lcd.setCursor(0,1);
    lcd.print("Alert !!!");
    digitalWrite(Red_bulb,HIGH);
  }
  else{
    Serial.println("No Warning");
  
    lcd.setCursor(0,0);
    lcd.print("Water Level:");
    lcd.setCursor(14,0);
    lcd.print(water_level);

    lcd.setCursor(0,1);
    lcd.print("No Warning");
  
    digitalWrite(Red_bulb,LOW);
    digitalWrite(Yellow_bulb,LOW);
  }

  delay(1000);
}

void loop(){
  Float_status = digitalRead(float_pin);
  if(Float_status == LOW){
    water_level_moniter();
  }
  else{
    Serial.println("no Water");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Water");
    
    digitalWrite(Red_bulb,LOW);
    digitalWrite(Yellow_bulb,LOW);
}
  delay(2000);
}