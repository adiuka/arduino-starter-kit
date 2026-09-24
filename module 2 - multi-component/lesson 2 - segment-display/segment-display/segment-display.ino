byte digits[10] = {
  B11111100,  // = 0
  B01100000,  // = 1
  B11011010,  // = 2
  B11110010,  // = 3
  B01100110,  // = 4
  B10110110,  // = 5
  B10111110,  // = 6
  B11100000,  // = 7
  B11111110,  // = 8
  B11100110   // = 9
};

int latchPin = 3;
int clockPin = 4;
int dataPin = 2;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void segmentWrite(byte digit) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, digits[digit]);
  digitalWrite(latchPin, HIGH);
}

void loop() {
  for (byte digit = 10; digit > 0; --digit) {
    delay(1000);
    segmentWrite(digit - 1);
  }

  delay(4000);
}
