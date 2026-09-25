int lightPin = 0;
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

int leds = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void loop() {
  int reading = analogRead(lightPin);
  int numberLedsLit = reading / 57;
  if (numberLedsLit > 8) {
    numberLedsLit = 8;
  }
  leds = 0;
  for (int i = 0; i < numberLedsLit; i++) {
    leds = leds + (1 << i);
  }
  updateShiftRegister();
}
