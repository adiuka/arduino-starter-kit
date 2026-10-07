#define DEBOUNCE_MS 200

void button_s_interrupt() {
  time_button_s = millis();
  if (time_button_s - last_time_button_s > DEBOUNCE_MS) {
    last_time_button_s = time_button_s;
    flag_begin = 0;
    number += 100;
    if (number >= 9900) number = 9959;
  }
}

void button_ms_interrupt() {
  time_button_ms = millis();
  if (time_button_ms - last_time_button_ms > DEBOUNCE_MS) {
    last_time_button_ms = time_button_ms;
    flag_begin = 0;
    number += 1;
    if (number % 100 == 60) number += 40;    // 0:60 -> 1:00
    if (number >= 9900)     number = 9959;
  }
}

void button_choose_interrupt() {
  time_button_choose = millis();
  if (time_button_choose - last_time_button_choose > DEBOUNCE_MS) {
    last_time_button_choose = time_button_choose;
    if (flag_begin) {
      flag_begin = 0;      // running (or alarming) -> stop and clear
      number = 0;
    } else if (number > 0) {
      flag_begin = 1;      // only start if there is something to count
    }
  }
}

void button_init(const uint8_t button_s, const uint8_t button_ms, const uint8_t button_choose) {
  pinMode(button_s, INPUT_PULLUP);
  pinMode(button_ms, INPUT_PULLUP);
  pinMode(button_choose, INPUT_PULLUP);
}

void button_interrupt_init(const uint8_t button_s, const uint8_t button_ms, const uint8_t button_choose) {
  attachPinChange(button_s, button_s_interrupt, FALLING);
  attachPinChange(button_ms, button_ms_interrupt, FALLING);
  attachPinChange(button_choose, button_choose_interrupt, FALLING);
}
