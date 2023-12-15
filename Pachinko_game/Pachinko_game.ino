//code music mario from tmekinyan 
//https://github.com/hibit-dev/buzzer/blob/master/src/games/mario_bros/mario_bros.ino



#include <Servo.h>
Servo myservo;

int photoresister = A0;
int led1 = 2;
int led2 = 3;
int led3 = 4; 
int led4 = 5;
int led5 = 6;

int buzzer = 8;
int SV = 9;

#include "pitches.h"

#define buzzer 8

int melody[] = {
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 

};

int durations[] = {
  8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4, 
  
};



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(SV);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(SV, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightValue = analogRead(photoresister); // assign sensor value to variable
  
  if(lightValue<300) {
    myservo.write(0); // Turn the servo and flag up
  digitalWrite(led1,HIGH); //Turn on LED if value us lower then 500
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  delay(1500);
  digitalWrite(led1,LOW); //Turn on LED if value us lower then 500
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  delay(500);

  tone(buzzer, 330);
 
int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(buzzer, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(buzzer);

  }
  }
  else{
  digitalWrite(led1, LOW); 
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);//Turn off LED if otherwise
  noTone(buzzer);
  myservo.write(90);//Turn down the flag
  }
  Serial.println(lightValue); //print sensor value to console
}
