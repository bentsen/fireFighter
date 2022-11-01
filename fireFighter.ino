const int flameSensor = D0;
const int pwmMotorA = D1;
const int pwmMotorB = D2;
const int dirMotorA = D3;
const int dirMotorB = D4;
const int waterPump = D5;
bool fire = false;
int Flame = HIGH;
int motorSpeed = 500;

void setup() {
  pinMode(waterPump, OUTPUT);
  pinMode(pwmMotorA, OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);
  pinMode(flameSensor, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}

void handle_fire() {
  delay(500);
  digitalWrite(pwmMotorA, 0);
  digitalWrite(pwmMotorB, 0);
  digitalWrite(dirMotorA, HIGH);
  digitalWrite(dirMotorB, HIGH);

  //kør pumpe
  delay(500);
  digitalWrite (waterPump, LOW);
  delay(2000);
  digitalWrite(waterPump, HIGH);

  fire == false;
}

void loop() {
  Flame = digitalRead(flameSensor);

  if(Flame == LOW) {
    digitalWrite(pwmMotorA, motorSpeed);
    digitalWrite(pwmMotorB, motorSpeed);
    digitalWrite(dirMotorA, LOW);
    digitalWrite(dirMotorB, LOW);  
    fire == true;
  }
  else{
    digitalWrite(pwmMotorA, 0);
    digitalWrite(pwmMotorB, 0);
    digitalWrite(dirMotorA, HIGH);
    digitalWrite(dirMotorB, HIGH);
    fire == false;
  }

  delay(300);
  while(fire == true){
     handle_fire();
  }
}
