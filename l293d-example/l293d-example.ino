/****************************/
/*			L293 H-Bridge				*/
/****************************/

// EN1, EN2 with PWM -- speed
// IN1, IN2, IN3, IN4 -- direction
// (IN1, IN3) - backward
// (IN2, IN4) - forward

#define EN1 6
#define EN2 5
#define IN1 7
#define IN2 8
#define IN3 13
#define IN4 12

void setup() {
  pinMode (EN1, OUTPUT);
  pinMode (EN2, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

//  direction pins
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.begin(9600);
}

void loop(){
// test motor speeds

  // accelerate
  for (int i = 0; i < 256; i++) {
    Serial.println(i);
    // speed
    analogWrite(EN1, i);
    analogWrite(EN2, i);
    delay(100);
  }

  // deccelerate
  for (int i = 255; i >= 0; --i) {
    Serial.println(i);
    analogWrite(EN1, i);
    analogWrite(EN2, i);
  	delay(100);
  }
  delay(500);
}