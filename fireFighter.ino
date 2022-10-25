const int flameSensor = D0;
const int pwmMotorA = D1;
const int pwmMotorB = D2;
const int dirMotorA = D3;
const int dirMotorB = D4;
const int waterPump = D5;


void setup() {
  pinMode(waterPump, OUTPUT);
}

void loop() {
  digitalWrite(waterPump, LOW);
}
