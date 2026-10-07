// Timer1 in CTC mode, fires exactly once per second (16 MHz Uno / Nano)
// 16,000,000 / 1024 prescaler = 15625 ticks per second -> OCR1A = 15625 - 1

void MCU_timer_interrupt_init() {
  uint8_t oldSREG = SREG;
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A  = 15624;
  TCCR1B |= (1 << WGM12);                  // CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10);     // prescaler 1024
  TIMSK1 |= (1 << OCIE1A);                 // enable compare match interrupt
  SREG = oldSREG;
}

ISR(TIMER1_COMPA_vect) {
  if (flag_begin && number > 0)
  {
    if (number % 100 == 0)
      number = number - 100 + 59;          // 2:00 -> 1:59
    else
      number--;
  }
}
