#define LMotor_1 8
#define LMotor_2 7
#define LMotor_S 5
#define RMotor_1 2
#define RMotor_2 4
#define RMotor_S 3
#define ARP 0

void setup() {
  pinMode(LMotor_1,OUTPUT);
  pinMode(LMotor_2, OUTPUT);
  pinMode(LMotor_S, OUTPUT);
  pinMode(RMotor_1,OUTPUT);
  pinMode(RMotor_2, OUTPUT);
  pinMode(RMotor_S, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LMotor_1, HIGH);//both go forwards
  digitalWrite(LMotor_2, LOW);
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  for(int i = 70; i < 256; i++)
  {
    analogWrite(LMotor_S, i);
    analogWrite(RMotor_S, i);
    Serial.println(i);
    delay(250);
  }

}
