int sensorAnalogPin = A0;
int sensorDigitalPin = 3;
int analogValue = 0;
int digitalValue;
int led13 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(sensorDigitalPin, INPUT);
  pinMode(led13, OUTPUT);
}

void loop() {
  analogValue = analogRead(sensorAnalogPin);
  digitalValue = digitalRead(sensorDigitalPin);
  Serial.println(analogValue);

  if (digitalValue == HIGH) {
    digitalWrite(led13, HIGH);
  } else {
    digitalWrite(led13, LOW);
  }

  delay(50);
}
