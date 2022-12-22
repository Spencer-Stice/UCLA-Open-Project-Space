//Code written by Spencer Stice
//UCLA OPS Capstone 2021


//definitions of pins

//motor control pins

#define LMotor_1 8
#define LMotor_2 7
#define LMotor_S 3
#define RMotor_1 2
#define RMotor_2 4
#define RMotor_S 5
#define ModuleOne A1
#define ARP 0

//ultrasonic sensor pins

#define echoPin 12
#define trigPin 10

//declare globals

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int RSpeed = 230; //PWM for right motor, the left motor was naturally stronger
int LSpeed = 200; //PWM for left motor

//declare variables to keep track of time
double prevTime = 0;
double nextTime;

//declare variables to keep track of error
int prevError = 0;

void setup() {
  pinMode(LMotor_1,OUTPUT);
  pinMode(LMotor_2, OUTPUT);
  pinMode(LMotor_S, OUTPUT);
  pinMode(RMotor_1,OUTPUT);
  pinMode(RMotor_2, OUTPUT);
  pinMode(RMotor_S, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //start moving forward
  //I tried using IR to detect corners but my reading were just too inconsistent
  //So I put the ultrasonic sensor near the front and used to it detect walls and corners instead (approved by Ryeder)
  
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
  analogWrite(LMotor_S, LSpeed);
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  analogWrite(RMotor_S, RSpeed);  //start both motors at about 75% speed
  
  //read data from sensor

  int sumDistance = 0;
  int flag = 0;
  int badReading = 1;//throw away readings if they contain too few 'no object there' readings
while(badReading == 1)
{
  //average out distance readings
  flag = 0;
  sumDistance = 0;
  for(int i = 0; i < 10 ; i++)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = duration * 0.034 / 2;  //distance is in cm as duration is in microseconds
    Serial.println(distance);
    if(distance >1100)
      flag++;
    sumDistance+=distance;
  }
  if(flag < 1){//if there were no high readings
    badReading = 0;
  if(flag > 7)//if the high readings were legit and it needs to turn
    badReading = 0;
  }
}

  int avgReading = sumDistance/10;

  //process data from sensor with PID

  //I want the car to be 5 cm from the wall

  int error = avgReading - 5;

  int propTerm = (5)*error;//constant = 5
  
  nextTime = millis();//for calculating derivatives/integrals
  
  int derivTerm = ((error - prevError)/(nextTime - prevTime)) * (100);//constant = 100

  
  int intTerm = ((nextTime - prevTime) * (error)) * 0;//ended up not needing the integral term so constant is 0
  
  int totalPID = propTerm + derivTerm + intTerm;
  
  //use processed data to change the car direction/speed
  
  //car will be on the LEFT side of the wall
  
  if(error > 0){//too far from wall
    LSpeed +=  totalPID/2;
    RSpeed -= totalPID/2;
    if(LSpeed > 255)
    {
      RSpeed = 235;
      LSpeed = 200;
    }
  }
  else if(error < 0){
    RSpeed += totalPID/2;
    LSpeed -= totalPID/2;
    if(RSpeed > 255)
    {
      RSpeed = 230;
      LSpeed = 200;
    }
  }
  prevTime = nextTime;
  prevError = error;
  if(flag > 7){//wall detection
    analogWrite(LMotor_S, 255);
    analogWrite(RMotor_S, 0);
    delay(1000);
    analogWrite(LMotor_S, 200);
    analogWrite(RMotor_S, 230);
    delay(2000);
    LSpeed = 200;
    RSpeed = 230;
  }
  }
  
