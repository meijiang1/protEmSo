#include <Smoothed.h>

float ledValue;
float sensorInput;
float inputSmoothed;
Smoothed <float> mySensor;

void setup() 
{
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  mySensor.begin(SMOOTHED_AVERAGE, 20);
}

void loop() 
{
  sensorInput = analogRead(5);
  mySensor.add(sensorInput);
  inputSmoothed = mySensor.get();
    
  if(inputSmoothed > 900)
  {
    ledValue = 255;
  }
  else if (inputSmoothed < 600)
  {
    ledValue = 0;
  }
  else
  {
    ledValue = map(inputSmoothed, 600, 900, 0, 125);;
  }
  analogWrite(10, ledValue);
  //smooth -> average van waarden nemen: tegen flicker (sensorwaarde verandert constant = zorgt voor licht flicker)
  //https://github.com/MattFryer/Smoothed

  Serial.print(sensorInput);
  Serial.print(" ");
  Serial.print(inputSmoothed);
  Serial.print(" ");
  Serial.println(ledValue);
}
