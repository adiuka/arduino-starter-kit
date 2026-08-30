int ledPin = 9; // Tells Arduino to control Pin 9

void setup() {
  pinMode(ledPin, OUTPUT); // Configures Pin 9 as an output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Send power (turns LED ON)
  delay(1000);                // Wait 1 second
  digitalWrite(ledPin, LOW);  // Cut power (turns LED OFF)
  delay(1000);                // Wait 1 second
}
