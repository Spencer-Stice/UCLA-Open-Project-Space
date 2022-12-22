#include "pitches.h"
#include "basicpitches.h"
#define SPEAKER 7
#define B1AR 0
#define B1PWR 2
#define B2AR 1
#define B3AR 2
#define RED 3
#define GREEN 5
#define BLUE 6
int NOTE_DUR = 137/2;
void setup() {
  // put your setup code here, to run once:
      pinMode(SPEAKER, OUTPUT);
    pinMode(B1PWR, OUTPUT);
    pinMode(B1AR, INPUT);
    pinMode(B2AR, INPUT);
    pinMode(B3AR, INPUT);
    pinMode(8,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(8,HIGH);
  int b1 = analogRead(B1AR);
  int b2 = analogRead(B2AR);
  int b3 = analogRead(B3AR);
  Serial.println(b1);
  delay(250);
  Serial.println(b2);
  delay(250);
  Serial.println(b3);
  delay(250);
  if(b1>300)
    playSongOne();
  else if(b2>300)
    playSongTwo();
  else if(b3>300)
    playSongThree();
}

void play(int note, int duration)
{
  tone(SPEAKER, note);
  delay(duration * NOTE_DUR);
  noTone(SPEAKER);
  delay(duration * NOTE_DUR/3);
}

void playSongOne()
{
  analogWrite(RED,255);
    play(NOTE_C4,3);
  delay(NOTE_DUR/2);
  play(NOTE_C4,3);
  delay(NOTE_DUR);
  play(NOTE_D4,3);
  delay(NOTE_DUR/2);
  play(NOTE_D4,3);
  delay(NOTE_DUR);
  play(NOTE_E4,3);
  delay(NOTE_DUR/2);
  play(NOTE_E4,3);
  delay(NOTE_DUR);
   play(NOTE_D4,3);
  delay(NOTE_DUR/2);
  play(NOTE_D4,3);
  delay(NOTE_DUR);
  play(NOTE_C4,3);
  delay(NOTE_DUR/2);
  play(NOTE_C4,3);
  delay(NOTE_DUR);
   play(NOTE_D4,3);
  delay(NOTE_DUR/2);
  play(NOTE_D4,3);
  delay(NOTE_DUR);
play(NOTE_E4,3);
  delay(NOTE_DUR);
  play(NOTE_E4,3);
  delay(NOTE_DUR);
  play(NOTE_C4,6);
  delay(NOTE_DUR*10);
  analogWrite(RED,0);
}

void playSongTwo()
{
  analogWrite(GREEN,255);
    play(NOTE_E4,3);
  delay(NOTE_DUR/2);
play(NOTE_E4,3);
  delay(NOTE_DUR/2);
  play(NOTE_E4,3);
  delay(NOTE_DUR*3);
  play(NOTE_E4,3);
  delay(NOTE_DUR/2);
  play(NOTE_E4,3);
  delay(NOTE_DUR/2);
  play(NOTE_E4,3);
  delay(NOTE_DUR*3);
play(NOTE_E4,3);
  delay(NOTE_DUR/2);
  play(NOTE_G4,3);
  delay(NOTE_DUR/2);
  play(NOTE_C4,3);
  delay(NOTE_DUR/2);
  play(NOTE_D4,3);
  delay(NOTE_DUR/2);
  play(NOTE_E4,3);
  delay(NOTE_DUR/2);
  analogWrite(GREEN,0);
}

void playSongThree()
{
  analogWrite(BLUE,255);
   play(NOTE_E4,3);
  delay(NOTE_DUR);
    play(NOTE_D4,3);
  delay(NOTE_DUR/2);
    play(NOTE_C4,3);
  delay(NOTE_DUR*3);
  play(NOTE_E4,3);
  delay(NOTE_DUR);
    play(NOTE_D4,3);
  delay(NOTE_DUR/2);
    play(NOTE_C4,3);
  delay(NOTE_DUR*3);
    play(NOTE_C4,3);
  delay(NOTE_DUR/2);
  play(NOTE_C4,3);
  delay(NOTE_DUR);
  play(NOTE_C4,3);
  delay(NOTE_DUR/2);
  play(NOTE_C4,3);
  delay(NOTE_DUR);
    play(NOTE_D4,3);
  delay(NOTE_DUR/2);
  play(NOTE_D4,3);
  delay(NOTE_DUR);
  play(NOTE_D4,3);
  delay(NOTE_DUR/2);
  play(NOTE_D4,3);
  delay(NOTE_DUR);
    play(NOTE_E4,3);
  delay(NOTE_DUR);
    play(NOTE_D4,3);
  delay(NOTE_DUR/2);
    play(NOTE_C4,3);
  delay(NOTE_DUR*3);
analogWrite(BLUE,0);
}
