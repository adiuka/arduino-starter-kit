#define TIME 2     // ms each digit stays lit

void latch_init(const uint8_t latch, const uint8_t clock, const uint8_t data) {
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
}

void com_init(const uint8_t com1, const uint8_t com2, const uint8_t com3, const uint8_t com4) {
  pinMode(com1, OUTPUT);
  pinMode(com2, OUTPUT);
  pinMode(com3, OUTPUT);
  pinMode(com4, OUTPUT);
}

// Send one byte of segments to the 74HC595
void shift_segments(uint8_t value) {
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, value);
  digitalWrite(LATCH, HIGH);
}

void clear_bit_display() {
  shift_segments(0);
}

// com 1 = rightmost digit ... com 4 = leftmost digit (active LOW)
void choose_com(uint8_t com) {
  digitalWrite(COM1, com == 1 ? LOW : HIGH);
  digitalWrite(COM2, com == 2 ? LOW : HIGH);
  digitalWrite(COM3, com == 3 ? LOW : HIGH);
  digitalWrite(COM4, com == 4 ? LOW : HIGH);
}

void display(uint8_t num) {
  shift_segments(num_buf[num]);
}

void clear_display() {
  clear_bit_display();
  choose_com(0);           // nothing selected
}

// Shows num (0-9999) once through, leading zeros hidden. Call it from loop().
void display_num(uint16_t num) {
  if (num > 9999) num = 9999;

  uint8_t digits[4];
  digits[0] = num % 10;
  digits[1] = num / 10 % 10;
  digits[2] = num / 100 % 10;
  digits[3] = num / 1000;

  uint16_t limit = 1;                       // 1, 10, 100, 1000
  for (uint8_t i = 0; i < 4; i++) {
    if (i == 0 || num >= limit) {           // always show the last digit
      clear_bit_display();                  // blank first = no ghosting
      choose_com(i + 1);
      display(digits[i]);
      delay(TIME);
    }
    limit *= 10;
  }
  clear_bit_display();
}