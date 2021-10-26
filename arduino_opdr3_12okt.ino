unsigned int ledValue;

void setup() 
{
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(analogRead(5)>900)
  {
    ledValue = 255;
  }
  else if (analogRead(5)<600)
  {
    ledValue = 0;
  }
  else
  {
    ledValue = map(analogRead(5), 600, 900, 0, 125);
  }
  analogWrite(10, ledValue);
  //tegen flicker: gemiddelde waarde nemen van al de inputswaarde

  Serial.print(analogRead(5));
  Serial.print(" ");
  Serial.println(ledValue);

}
