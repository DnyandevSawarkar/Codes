int motorPin1 = 23;
int motorPin2 = 22;
int motorPin3 = 24;
int motorPin4 = 25;
int pwm1=45;
int pwm2=46;

void setup() {
// DDRA=0xFF; 
// DDRL = DDRL | 0x18;   //Setting PL3 and PL4 pins as output for PWM generation
// PORTL = PORTL | 0x18; //PL3 and PL4 pins are for velocity control using PWM
pinMode( motorPin1,OUTPUT);
pinMode( motorPin2,OUTPUT);
pinMode( motorPin3,OUTPUT);
pinMode( motorPin4,OUTPUT);
pinMode( pwm1,OUTPUT);
pinMode( pwm2,OUTPUT);

digitalWrite(pwm1, HIGH);
digitalWrite(pwm2, HIGH);
}

void loop() {
   digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(2000);

     digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(2000);
}
