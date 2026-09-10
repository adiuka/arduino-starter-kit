int timeDelay = 100;
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte leds = 0;

void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  leds = 0; // turns off all leds
  updateShiftRegister();
  delay(timeDelay);

  for (int i = 0; i < 8; i++) {
    bitSet(leds, i);
    updateShiftRegister();
    delay(timeDelay);
  }
}
