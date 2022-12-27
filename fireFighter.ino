const int flame_sensor = D0;
const int pwmMotorA = D1;
const int pwmMotorB = D2;
const int dirMotorA = D3;
const int dirMotorB = D4;
const int waterPump = D5;
bool fire = false;
int flame_detected;
int motorSpeed = 500;

void setup() {
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT);
  pinMode(pwmMotorA, OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);
  pinMode(flame_sensor, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void handle_fire() {
  Serial.println("der sprøjtes");
  delay(500);
  digitalWrite(pwmMotorA, 0);
  digitalWrite(pwmMotorB, 0);
  digitalWrite(dirMotorA, HIGH);
  digitalWrite(dirMotorB, HIGH);

  //kør pumpe
  delay(500);
  digitalWrite (waterPump, HIGH);
  delay(2000);
  digitalWrite(waterPump, LOW);

  fire = false;
  delay(5000);
}

void loop() {
  Serial.println(fire);
  flame_detected = digitalRead(flame_sensor);

  if(flame_detected == 0) {
    Serial.println("der er ild bitches");
    digitalWrite(pwmMotorA, motorSpeed);
    digitalWrite(pwmMotorB, motorSpeed);
    digitalWrite(dirMotorA, LOW);
    digitalWrite(dirMotorB, LOW);
    fire = true;
  }  
  else if(flame_detected == 1){
    Serial.println("der er ikke ild");
    digitalWrite(pwmMotorA, 0);
    digitalWrite(pwmMotorB, 0);
    digitalWrite(dirMotorA, HIGH);
    digitalWrite(dirMotorB, HIGH);
    fire = false;
  }

  delay(300);
  while(fire == true){
     handle_fire();
  }
}
