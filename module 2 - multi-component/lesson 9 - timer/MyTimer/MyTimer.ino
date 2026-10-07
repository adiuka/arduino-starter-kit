#include "PinChange.h"   // our own pin change interrupt (replaces PinChangeInt)
#include "MyTimer.h"

/***********************************************************************
 *  My Timer - 4 digit countdown timer (MM:SS)
 *  Buttons : BUTTON_S      +1 minute  (+100)
 *            BUTTON_MS     +1 second  (+1)
 *            BUTTON_CHOOSE start / stop+clear
 *  Interrupts: pin change for the 3 buttons, Timer1 for the 1 s tick
 ***********************************************************************/

void setup() {
  latch_init(LATCH, CLOCK, DATA);          // 74HC595
  com_init(COM1, COM2, COM3, COM4);
  button_init(BUTTON_S, BUTTON_MS, BUTTON_CHOOSE);
  led_init(LED);
  buzzer_init(BUZZER);

  button_interrupt_init(BUTTON_S, BUTTON_MS, BUTTON_CHOOSE);
  MCU_timer_interrupt_init();              // Timer1 -> 1 second tick
}

void loop() {
  display_num(get_number());
  time_out();
}

