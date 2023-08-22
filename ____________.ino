#include <Servo.h>

Servo dropServo;

#define S0 4
#define S1 5
#define S2 7
#define S3 6
#define sensorOut 8
#define in3 9
#define in4 10
#define en2 11
//#define FORWARD 3


//unsigned char Forward_Speed = 140;


int GetColor() {
  int frequency = 0;
  int sortColor = 0;
  int color = 0;

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  Serial.print("Red = ");
  Serial.print(frequency);
  Serial.print("   ");
  delay(50);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  Serial.print("Blue = ");
  Serial.print(frequency);
  Serial.println("   ");
  delay(50);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  Serial.print("Green = ");
  Serial.print(frequency);
  Serial.print("   ");
  delay(50);

  if (R < 60) {
    Serial.print("RRRRRRRRRRR");
//    dropServo.write(0);
  } else if (B < 60) {
      Serial.print("BBBBBBBBBBB");
//      dropServo.write(90);
  } else {
//    color = 0;
  }
  return color;
}

void setup()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en2, OUTPUT);
//  pinMode(FORWARD, OUTPUT);

  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

//  dropServo.attach(9);

  Serial.begin(9600);
}

void loop()
{
//  analogWrite(FORWARD, Forward_Speed);
  
  GetColor();
  
//  while (true) {
//   
//    while (Serial.available() == 0);
//    
//    char data = Serial.read();
//    if (data == '1') {
//      break;
//    } else if (data == '2') {
//      sortColor = RED;
//    } else {
//     
//    }
//  }
//
//  while (GetColor() == 0) {
//
//  }
//
//  if (GetColor() == sortColor) {
//    dropServo.write(20);
//  } else {
//    dropServo.write(0);
//  }


}
