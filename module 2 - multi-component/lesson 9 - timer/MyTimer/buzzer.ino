void buzzer_init(const uint8_t buzzer) {
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void led_init(const uint8_t led) {
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
}

void time_out() {
  while (flag_begin && number == 0) {
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(BUZZER, LOW);
    digitalWrite(LED, LOW);
    delay(100);
  }
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED, HIGH);
}