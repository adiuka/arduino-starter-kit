int latchPin = 9;
int clockPin = 10;
int dataPin = 8;

unsigned char table[] = {
  0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x00
};

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void displayChar(unsigned char num) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, table[num]);
  digitalWrite(latchPin, HIGH);
}

void loop() {
  displayChar(1);
  delay(500);
  displayChar(2);
  delay(500);
  displayChar(3);
  delay(500);
  displayChar(4);
  delay(500);
  displayChar(5);
  delay(500);
  displayChar(6);
  delay(500);
  displayChar(7);
  delay(500);
  displayChar(8);
  delay(500);
  displayChar(9);
  delay(500);
  displayChar(10);
  delay(500);
  displayChar(11);
  delay(500);
  displayChar(12);
  delay(500);
  displayChar(13);
  delay(500);
  displayChar(14);
  delay(500);
  displayChar(15);
  delay(500);
}
