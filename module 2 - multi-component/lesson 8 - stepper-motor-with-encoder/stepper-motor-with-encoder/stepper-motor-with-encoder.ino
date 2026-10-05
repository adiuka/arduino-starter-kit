#include "Stepper.h"
#define STEPS 32

const int pinCLK = 2;
const int pinDT = 3;
const int pinSW = 4; 

const int STEPS_PER_CLICK = 50;

volatile int pendingClicks = 0;
volatile unsigned long lastIsrTime = 0;

int rotaryPosition = 0;

Stepper myStepper(STEPS, 8, 10, 9, 11);

void isr() {
  unsigned long now = micros();
  if (now - lastIsrTime < 2000) return;
  lastIsrTime = now;

  if (digitalRead(pinDT) == digitalRead(pinCLK)) {
    pendingClicks--;
  } else {
    pendingClicks++;
  }
}

void setup() {
  pinMode(pinCLK, INPUT);
  pinMode(pinDT, INPUT);
  pinMode(pinSW, INPUT);
  digitalWrite(pinSW, HIGH);
  attachInterrupt(digitalPinToInterrupt(pinCLK), isr, FALLING);
  myStepper.setSpeed(700);
}

void loop() {
  if (!digitalRead(pinSW)) {
    noInterrupts();
    pendingClicks = 0;
    interrupts();

    if (rotaryPosition != 0) {
      myStepper.step(-rotaryPosition * STEPS_PER_CLICK);
      rotaryPosition = 0;
    }
  }

  noInterrupts();
  int clicks = pendingClicks;
  pendingClicks = 0;
  interrupts();

  if (clicks != 0) {
    rotaryPosition += clicks;
    myStepper.step(clicks * STEPS_PER_CLICK); // one move for all clicks
  }

  // Deenergize coils for heat management
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}










