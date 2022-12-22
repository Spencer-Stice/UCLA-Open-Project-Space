#define LED 6
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  analogWrite(LED, 0);
}

void loop() {
  if(Serial.available()){
  int currByte = Serial.read();
if(currByte == 2)
{
  analogWrite(LED, 250);
  Serial.println("BRIGHT");
}
else if(currByte == 1)
{
  analogWrite(LED, 50);
  Serial.println("DIM");
}
else if(currByte == 0)
{
  analogWrite(LED, 0);
  Serial.println("OFF");
}
  }
}
