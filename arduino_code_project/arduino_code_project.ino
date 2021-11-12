#include <Servo.h>
Servo servoPaw;

const int servoPin = 4;
const int buttonPin = 6;
const int ledPinL = 2;
const int ledPinR = 3;
const int piezoPin = 5;

int buttonState = 1;

void setup() 
{
  Serial.begin(9600);
  servoPaw.attach(servoPin);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPinL, OUTPUT);
  pinMode(ledPinR, OUTPUT);
  pinMode(piezoPin, OUTPUT);
}

void loop() 
{
  buttonState = digitalRead(buttonPin);
  if(buttonState == 0)
  {
    //led
    digitalWrite(ledPinL, HIGH);
    digitalWrite(ledPinR, HIGH);
    delay(500);
    //piezo
    tone(piezoPin, 261);
    delay(100);
    tone(piezoPin, 294);
    delay(100);
    tone(piezoPin, 330);
    delay(100);
    tone(piezoPin, 349);
    delay(100);
    tone(piezoPin, 392);
    delay(100);
    tone(piezoPin, 440);
    delay(100);
    noTone(piezoPin);
    //servo
    servoPaw.write(180); 
    delay(2500);
  }
  else
  {
    digitalWrite(ledPinL, LOW);
    digitalWrite(ledPinR, LOW);
    noTone(piezoPin);
    servoPaw.write(0);
  }
}
