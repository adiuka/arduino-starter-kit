#include "MsTimer2.h"
#include <avr/wdt.h>

int number = 0;
unsigned long lastCount = 0;
unsigned long lastPress = 0;

volatile bool timerFlag = false;
volatile bool buttonFlag = false;

void timer2_interrupt() {
  timerFlag = true;
}

ISR(PCINT1_vect) {                // pin-change interrupt for A0-A5
  if (digitalRead(A3) == LOW) {  // only react to the press, not the release
    buttonFlag = true;
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("DEMO v5 booted");

  MsTimer2::set(4000, timer2_interrupt);
  MsTimer2::start();

  pinMode(A3, INPUT_PULLUP);
  PCICR  |= (1 << PCIE1);        // enable pin-change interrupts for A0-A5
  PCMSK1 |= (1 << PCINT11);      // A3 only

  wdt_enable(WDTO_4S);           // reboot if loop() stalls for 4 seconds
}

void loop() {
  wdt_reset();                   // "feed the dog": proves loop() is still running

  if (millis() - lastCount >= 2000) {
    lastCount = millis();
    Serial.print("we begin to count:");
    Serial.println(number++);
  }

  if (timerFlag) {
    timerFlag = false;
    Serial.println("timer2_interrupt triggered");
  }

  if (buttonFlag) {
    buttonFlag = false;
    if (millis() - lastPress > 200) {   // ignore button bounce
      lastPress = millis();
      Serial.println("button_interrupt triggered");
    }
  }
}