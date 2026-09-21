#include <Stepper.h>

const int stepsPerRevolution = 2048;
const int rolePerMinute = 15;

// stepper init
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(rolePerMinute);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Clockwise:");
  myStepper.step(stepsPerRevolution);
  delay(500);

  Serial.println("Counter-clockwise:");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
