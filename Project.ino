//Right ir sensor
#define R_S A0

//Left ir sensor
#define L_S A1

//left motor Pins
#define EA 10
#define IN1 9
#define IN2 8

//right motor Pins
#define IN3 7
#define IN4 6
#define EB 5

void forward();
void right();
void left();
void stop();

void setup(){
Serial.begin(9600);

//IR Sensors
pinMode(R_S, INPUT);
pinMode(L_S, INPUT);

//Motors
pinMode(EA, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(EB, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);

delay(1000);
}

void loop(){
  
  Serial.println (analogRead(R_S));
  Serial.println (analogRead(L_S));
   
  //If both the right and left sensors are seeing white (0) then go forward  
  if((analogRead(R_S) <= 700)&&(analogRead(L_S) <= 700)){ 
    forward();
    Serial.println ("Forward");
   } 

  //If Right Sensor is seeing black (1) and the left sensor is seeing white (0) Then go left
  if((analogRead(R_S) >= 700)&&(analogRead(L_S) <= 700)){
    left();
    Serial.println ("Left");
    delay(1000);
  }
  
  //If Right Sensor is seeing white (0) and the left sensor is seeing black (1) Then go right
  else if((analogRead(R_S) <= 700)&&(analogRead(L_S) >= 700)){  
    right();
    delay(1000);
      Serial.println ("Right");
  }
  else{
    forward();
  }
  stop();
  delay(1000);
}

void forward()
{
  //left motor rotate clock wise
  digitalWrite(IN1,0);
  digitalWrite(IN2, 1);

  //right motor rotate clock wise
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  
  analogWrite(EA,75);
  analogWrite(EB, 90);
}


void right()
{
  //left motor rotate forward
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);

  //right motor rotate backward
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);


  analogWrite(EA, 60);
  analogWrite(EB, 62);
}


void left()
{
  //left motor rotate backward
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);

  //right motor rotate forward
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);


  analogWrite(EA, 60);
  analogWrite(EB,85);
}


void stop()
{
  //left motor stop rotation
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);

  //right motor stop rotation
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);

  analogWrite(EB, 0);
  analogWrite(EA, 0);
}
