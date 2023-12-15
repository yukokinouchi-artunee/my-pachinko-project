#include <Servo.h>
Servo myservo;

int photoresister = A0;
int led1 = 2;
int led2 = 3;
int led3 = 4; 
int buzzer = 8;
int SV = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(SV);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(SV, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightValue = analogRead(photoresister); // assign sensor value to variable
  
  if(lightValue<500) {
  digitalWrite(led1,HIGH); //Turn on LED if value us lower then 500
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  tone(buzzer, 330);
  myservo.write(90);
  }
  else{
  digitalWrite(led1, LOW); 
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);//Turn off LED if otherwise
  noTone(buzzer);
  myservo.write(0);
  }
  Serial.println(lightValue); //print sensor value to console
}
