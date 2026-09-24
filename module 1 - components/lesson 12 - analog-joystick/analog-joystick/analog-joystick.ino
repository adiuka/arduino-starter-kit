const int swPin = 2;
const int xPin = 0;
const int yPin = 1;

void setup() {
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Switch: ");
  Serial.print(digitalRead(swPin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(xPin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.print(analogRead(yPin));
  Serial.print("\n\n");
  delay(1000);
}
