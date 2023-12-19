#include <Arduino.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);
Adafruit_DCMotor *motor3 = AFMS.getMotor(3);
Adafruit_DCMotor *motor4 = AFMS.getMotor(4);

int timer = 167;           // The higher the number, the slower the timing.
int ledPins[] = { 3, 2, 4, 1, 1, 2, 4, 3, 2, 4, 3, 1, 13, 13, 13, 13, 13, 13, 13, 13, 2, 4, 3, 1, 2, 1, 3, 4, 1, 3, 4, 2 };
// an array of pin numbers to which LEDs are attached Pin 13 is a pause
int pinCount = 32;           // the number of pins (i.e. the length of the array)
int speed = 191;

void setupMotors() {
  AFMS.begin();
  motor1->setSpeed(speed);
  motor2->setSpeed(speed);
  motor3->setSpeed(speed);
  motor4->setSpeed(speed);
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  motor3->run(RELEASE);
  motor4->run(RELEASE);
}

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");
  setupMotors();
}

void loop() {
for (int thisPin = 0; thisPin < pinCount; thisPin++) {

  switch (ledPins[thisPin]) { 
    case 1:
     motor1->run(FORWARD);
      motor1->setSpeed(speed);  
      delay(timer);
      motor1->run(RELEASE);
      break;
    case 2:
      motor2->run(FORWARD);
      motor2->setSpeed(speed);  
      delay(timer);
      motor2->run(RELEASE);
      break;
    case 3:
      motor3->run(FORWARD);
      motor3->setSpeed(speed);  
      delay(timer);
      motor3->run(RELEASE);
      break;
    case 4:
      motor4->run(FORWARD);
      motor4->setSpeed(speed);  
      delay(timer);
      motor4->run(RELEASE);
      break;
    case 13:
      digitalWrite(13, HIGH);
      delay(timer);
      digitalWrite(13, LOW);
      break;
  }
}
}