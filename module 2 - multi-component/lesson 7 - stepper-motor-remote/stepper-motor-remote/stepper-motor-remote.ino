#include "Stepper.h"
#include "IRremote.h"

#define STEPS 32
int stepsToTake;
int receiver = 12;

Stepper myStepper(STEPS, 8, 10, 9 , 11);
IRrecv myReceiver(receiver);
decode_results results;

void setup() {
  myReceiver.enableIRIn();
}

void loop() {
  if (myReceiver.decode(&results)) {
    switch (results.value) {
      case 0xFFA857:
        myStepper.setSpeed(500);
        stepsToTake = 2048;
        myStepper.step(stepsToTake);
        delay(2000);
        break;

      case 0xFF629D:
        myStepper.setSpeed(500);
        stepsToTake = - 2048;
        myStepper.step(stepsToTake);
        delay(2000);
        break;
    }

    myReceiver.resume();
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
