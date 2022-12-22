#define PPN 8
#define ARP 0
void setup() {
  pinMode(PPN,OUTPUT);
  pinMode(ARP, INPUT);
  Serial.begin(9600);

}

void loop() {
  
  int x = analogRead(ARP);
  Serial.println(x);
  if(x > 690)
  {
    digitalWrite(PPN, HIGH);
  }
  else
  {
    digitalWrite(PPN, LOW);
  }
  delay(250);
  
}
