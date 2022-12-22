#define RedLed 6
#define GreenLed 5
#define ModuleOne A5
#define ModuleTwo A3
long zero = 0;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 100; i++)
  {
    zero+=analogRead(ModuleOne);
  }
  zero/=100;
  zero-=50;
  Serial.begin(9600);
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(ModuleOne, INPUT);
  pinMode(ModuleTwo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int readingOne = analogRead(ModuleOne);
  int readingTwo = analogRead(ModuleTwo);
  int constrainedOne = constrain(readingOne, 0, zero);
  int constrainedTwo = constrain(readingTwo, 0, zero);
  int mappedOne = map(constrainedOne, 0, zero, 0, 255);
  int mappedTwo = map(constrainedTwo, 0, zero, 0, 255);
  analogWrite(RedLed, 255 - mappedOne);
  analogWrite(GreenLed, 255 - mappedTwo);
}
