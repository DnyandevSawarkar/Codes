// CNC Shield Stepper Control Demo with Joystick, Deadzone, and Serial Print

const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;

const int JoyX = A0; // Analog pin for X-axis of joystick
const int JoyY = A1; // Analog pin for Y-axis of joystick

const int deadzone = 20; // Adjust this value based on your joystick's resting position

void setup() {
  pinMode(StepX, OUTPUT);
  pinMode(DirX, OUTPUT);
  pinMode(StepY, OUTPUT);
  pinMode(DirY, OUTPUT);
  pinMode(JoyX, INPUT);
  pinMode(JoyY, INPUT);

  Serial.begin(9600); // Initialize Serial Communication
}

void loop() {
  int joyXValue = analogRead(JoyX);
  int joyYValue = analogRead(JoyY);

  // Apply deadzone to joystick values
  if (abs(joyXValue - 512) < deadzone) {
    joyXValue = 512;
  }
  if (abs(joyYValue - 512) < deadzone) {
    joyYValue = 512;
  }

  // Map joystick values to motor speed
  int motorSpeedX = map(joyXValue, 0, 1023, -500, 500);
  int motorSpeedY = map(joyYValue, 0, 1023, -500, 500);

  // Set direction based on joystick position
  digitalWrite(DirX, motorSpeedX >= 0 ? HIGH : LOW);
  digitalWrite(DirY, motorSpeedY >= 0 ? HIGH : LOW);

  // Print motor speeds to Serial Monitor
  Serial.print("Motor Speed X: ");
  Serial.print(motorSpeedX);
  Serial.print("\t");

  Serial.print("Motor Speed Y: ");
  Serial.println(motorSpeedY);

  // Run motors based on joystick speed
  for (int x = 0; x < abs(motorSpeedX); x++) {
    digitalWrite(StepX, HIGH);
    delayMicroseconds(500);
    digitalWrite(StepX, LOW);
    delayMicroseconds(500);
  }

  for (int y = 0; y < abs(motorSpeedY); y++) {
    digitalWrite(StepY, HIGH);
    delayMicroseconds(500);
    digitalWrite(StepY, LOW);
    delayMicroseconds(500);
  }

  delay(100); // Add a small delay for stability
}
