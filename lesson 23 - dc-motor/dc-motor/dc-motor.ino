#define enable 5
#define directionA 3
#define directionB 4

int i;

void setup() {
  pinMode(enable, OUTPUT);
  pinMode(directionA, OUTPUT);
  pinMode(directionB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("One way, then reverse");
  digitalWrite(enable, HIGH);
  for (i = 0; i < 5; i++) {
    digitalWrite(directionA, HIGH);
    digitalWrite(directionB, LOW);
    delay(500);
    digitalWrite(directionA, LOW);
    digitalWrite(directionB, HIGH);
    delay(500);
  }

  digitalWrite(enable, LOW); // turn off
  delay(2000);

  Serial.println("Fast - Slow example:");
  digitalWrite(enable, HIGH);
  digitalWrite(directionA, HIGH);
  digitalWrite(directionB, LOW);
  delay(3000);
  digitalWrite(enable, LOW); // slow stop
  delay(1000);
  digitalWrite(enable, HIGH);
  digitalWrite(directionA, LOW);
  digitalWrite(directionB, HIGH); 
  delay(3000);
  digitalWrite(directionB, LOW); // fast stop
  delay(2000);

  Serial.println("PWM full then slow");
  digitalWrite(directionA, HIGH);
  digitalWrite(directionB, LOW);
  analogWrite(enable, 255);
  delay(2000);
  analogWrite(enable, 180);
  delay(2000);
  analogWrite(enable, 128);
  delay(2000);
  analogWrite(enable, 50);
  delay(2000);
  analogWrite(enable, 128);
  delay(2000);
  analogWrite(enable, 180);
  delay(2000);
  analogWrite(enable, 255);
  delay(2000);
  digitalWrite(enable, LOW);
  delay(10000);
}
