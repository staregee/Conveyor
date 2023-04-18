#include <Servo.h>

Servo dropServo;
#define RED 1
#define GREEN 2
#define BLUE 3
#define S0 4
#define S1 5
#define S2 7
#define S3 6
#define sensorOut 8
#define in3 9
#define in4 10
#define en2 11

int frequency = 0;
int sortColor = 0;
int color = 0;


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
  delay(150);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  Serial.print("Blue = ");
  Serial.print(frequency);
  Serial.println("   ");
  delay(150);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  Serial.print("Green = ");
  Serial.print(frequency);
  Serial.print("   ");
  delay(150);

  if (B > 160) {
    color = BLUE;
  } else if (R > 400) {
    color = RED;
  } else {
    color = 0;
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


  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  dropServo.attach(9);

  Serial.begin(9600);
}

void loop()
{
  while (true) {
    // Условие пуска конвеера по Bt
    while (Serial.available() == 0);
    
    char data = Serial.read();
    if (data == '1') {
      // пуск конвеера
      break;
    } else if (data == '2') {
      // выбран красный цвет
      sortColor = RED;
    } else {
      // ошибка
    }
  }

  while (GetColor() == 0) {

  }

// конвейер стоп








  if (GetColor() == BLUE) {
    dropServo.write(90);
  } else {
    dropServo.write(0);
  }





}
