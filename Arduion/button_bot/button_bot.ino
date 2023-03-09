int left_sw;
int right_sw;
int front_sw;
int back_sw;
int start_sw;
int i=0;
int motor1pin1;
int motor1pin2;

int motor2pin1;
int motor2pin2;

int cmd[]={};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(left_sw,INPUT);
  pinMode(right_sw,INPUT);
  pinMode(front_sw,INPUT);
  pinMode(back_sw,INPUT);
  pinMode(start_sw,INPUT);
  Serial.println("Switch Setup Done");

  pinMode(motor1pin1,OUTPUT);
  pinMode(motor1pin2,OUTPUT);
  pinMode(motor2pin1,OUTPUT);
  pinMode(motor2pin2,OUTPUT);
  Serial.println("Motor Setup Done");
}


void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(left_sw)== 1){
    Serial.println("Add left cmd");
    cmd[i] = 'l';
    i++;
    // cmd.push("1");
  }

  if(digitalRead(right_sw)== 1){
    Serial.println("Add right cmd");
    // cmd.push("2");
    cmd[i] = 'r';
    i++;
  }

  if(digitalRead(front_sw)== 1){
    Serial.println("Add front cmd");
    // cmd.push("3");
  }

  if(digitalRead( back_sw)== 1){
    Serial.println("Add back cmd");
    // cmd.push("4");
  }

  if(digitalRead(start_sw)== 1){
    Serial.println("Add start cmd");
    /*
    int i = 0;
    while(cmd[i]!="\n")
    {
      if(cmd[i]=="1")
      {
        motor1pin1 = low;
        motor1pin2 = high;

        motor2pin1 = high;
        motor2pin2 = low;
        delay(5);
        cmd.pop[i];
        Serial.println("removed left cmd");
      }

      if(cmd[i]=="2")
      {
        motor1pin1 = high;
        motor1pin2 = low;

        motor2pin1 = low;
        motor2pin2 = high;
        delay(5);
        cmd.pop[i];
        Serial.println("removed right cmd");
      }

      if(cmd[i]=="3")
      {
        motor1pin1 = high;
        motor1pin2 = low;

        motor2pin1 = high;
        motor2pin2 = low;
        delay(5);
        cmd.pop[i];
        Serial.println("removed front cmd");
      }

      if(cmd[i]=="4")
      {
        motor1pin1 = low;
        motor1pin2 = high;

        motor2pin1 = low;
        motor2pin2 = high;
        delay(5);
        cmd.pop[i];
        Serial.println("removed back cmd");
      }
      delay(100);
      Serial.println("running last cmd");
      motor1pin1 = low;
      motor1pin2 = low;

      motor2pin1 = low;
      motor2pin2 = low;
      Serial.println("waiting for next cmd");
      i++;
      Serial.println("");
    }
    */
  }

}
