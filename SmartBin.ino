#include<Servo.h>
Servo myservo;

int Red = 4;
int Yellow = 5;
int Green = 6;

//int UV_Led1 = 7;

const int trigPin_1 = A4;
const int echoPin_1 = A5;
const int speek_1 = A0;

const int trigPin_2 = A2;
const int echoPin_2 = A3;
const int speek_2 = A1;

long duration_1;
int distance_1;

long duration_2;
int distance_2;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(8);
  myservo.write(0);
  delay(1000);

  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  
  pinMode(speek_1, OUTPUT);
  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);

  pinMode(speek_2, OUTPUT);
  pinMode(trigPin_2, OUTPUT);
  pinMode(echoPin_2, INPUT);

  digitalWrite(Red, 0);
  digitalWrite(Yellow, 0);
  digitalWrite(Green, 1);

  //digitalWrite(UV_Led1, 1);
}

void loop() 
{
  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_1, LOW);
  duration_1 = pulseIn(echoPin_1, HIGH);
  distance_1 = duration_1 * 0.034 / 2;

  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_2, LOW);
  duration_2 = pulseIn(echoPin_2, HIGH);
  distance_2 = duration_2 * 0.034 / 2;
  
  if (distance_1 <= 15) {
    digitalWrite(speek_1, HIGH);
    delay(400);
    digitalWrite(speek_1, LOW);
    delay(400);

    //digitalWrite(UV_Led1, 0);
    
    digitalWrite(Red, 0);
    digitalWrite(Yellow, 1);
    digitalWrite(Green, 1);

    myservo.write(150);
    delay(5000);
    }else{
    myservo.write(0);
    digitalWrite(Red, 0);
    digitalWrite(Yellow, 0);
    digitalWrite(Green, 1);

    //digitalWrite(UV_Led1, 1);
   }

   if (distance_2 <= 6) {
    digitalWrite(Red, 1);
    digitalWrite(Yellow, 0);
    digitalWrite(Green, 0);
    
    digitalWrite(speek_2, HIGH);
    delay(400);
    digitalWrite(speek_2, LOW);
    delay(400);
    }else{
    digitalWrite(speek_2, LOW);
    delay(400);
   }
}
