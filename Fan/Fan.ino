#define FAN 6
#define BR 1
void setup() {
  // put your setup code here, to run once:
  pinMode(FAN,OUTPUT);
  pinMode(BR, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int x =  analogRead(BR);
  Serial.println(x);
  delay(50);
  if(x>10 && x<250)
  {
    analogWrite(FAN, 150);
  }
  else if(x>=250 && x<600)
  {
    analogWrite(FAN, 200);
  }
  else if(x>=600)
  {
    analogWrite(FAN, 255);
  }
  else
  {
    analogWrite(FAN, 0);
  }
}
