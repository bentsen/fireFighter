const int flameSensor = D0;
const int pwmMotorA = D1;
const int pwmMotorB = D2;
const int dirMotorA = D3;
const int dirMotorB = D4;
const int waterPump = D5;


void setup() {
  pinMode(waterPump, OUTPUT);
  pinMode(pwnMotorA, OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);
  pinMode(flameSensor, INPUT);
}

void handle_fire() {
  digitialWrite()
}

void loop() {
  digitalWrite(waterPump, LOW);
}
