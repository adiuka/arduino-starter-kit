#define enable 5
#define dirA 3
#define dirB 4

int i;

void setup() {
  pinMode(enable, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Relay cycle: running, then stopped");
  digitalWrite(enable, HIGH);
  for (i = 0; i < 5; i++) {
    digitalWrite(dirA, HIGH);
    digitalWrite(dirB, LOW);
    delay(700);
    digitalWrite(dirA, LOW);
    digitalWrite(dirB, HIGH);
    delay(700);
  }

  digitalWrite(enable, LOW);
  delay(2000);
}
