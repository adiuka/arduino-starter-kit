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
  updateShiftRegister();
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Enter LED Number 0 to 7 or 'x' to clear.");
}

void loop() {
  if (Serial.available()) {
    char x = Serial.read();

    if (x >= '0' && x <= '7') {
      int led = x - '0'; // convert string to binary numbers
      bitSet(leds, led);
      updateShiftRegister();
      Serial.print("Turned on led ");
      Serial.println(led);
    }

    if (x == 'x') {
      leds = 0;
      updateShiftRegister();
      Serial.println("Cleared");
    }
  }
}
