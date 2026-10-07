// PinChange.h - tiny pin change interrupt helper for ATmega328P (Uno / Nano)
// Replaces the PinChangeInt library. Include it ONCE (it defines the ISRs).
//
// Usage:  attachPinChange(pin, myFunction, FALLING);   // FALLING, RISING or CHANGE
//         detachPinChange(pin);

#ifndef MY_PIN_CHANGE_H
#define MY_PIN_CHANGE_H

#include <Arduino.h>

typedef void (*PinChangeCallback)(void);

// 3 pin change groups on the Uno: 0 = PORTB (D8-D13), 1 = PORTC (A0-A5), 2 = PORTD (D0-D7)
static PinChangeCallback pc_callback[3][8];
static volatile uint8_t pc_rising[3]  = {0, 0, 0};
static volatile uint8_t pc_falling[3] = {0, 0, 0};
static volatile uint8_t pc_last[3]    = {0, 0, 0};

static inline uint8_t pc_readPort(uint8_t group) {
  switch (group) {
    case 0:  return PINB;
    case 1:  return PINC;
    default: return PIND;
  }
}

static void attachPinChange(uint8_t pin, PinChangeCallback fn, uint8_t mode) {
  if (digitalPinToPCICR(pin) == NULL || fn == NULL) return;   // pin has no pin change support

  uint8_t group = digitalPinToPCICRbit(pin);
  uint8_t bit   = digitalPinToPCMSKbit(pin);
  uint8_t mask  = (uint8_t)(1 << bit);

  uint8_t oldSREG = SREG;
  cli();

  pc_callback[group][bit] = fn;

  if (mode == RISING  || mode == CHANGE) pc_rising[group]  |= mask; else pc_rising[group]  &= ~mask;
  if (mode == FALLING || mode == CHANGE) pc_falling[group] |= mask; else pc_falling[group] &= ~mask;

  // remember the current level of this pin so we don't fire a false edge
  pc_last[group] = (pc_last[group] & ~mask) | (pc_readPort(group) & mask);

  *digitalPinToPCMSK(pin) |= mask;        // enable this pin
  *digitalPinToPCICR(pin) |= (1 << group); // enable this group

  SREG = oldSREG;
}

static void detachPinChange(uint8_t pin) {
  if (digitalPinToPCICR(pin) == NULL) return;

  uint8_t group = digitalPinToPCICRbit(pin);
  uint8_t bit   = digitalPinToPCMSKbit(pin);
  uint8_t mask  = (uint8_t)(1 << bit);

  uint8_t oldSREG = SREG;
  cli();
  *digitalPinToPCMSK(pin) &= ~mask;
  if (*digitalPinToPCMSK(pin) == 0) *digitalPinToPCICR(pin) &= ~(1 << group);
  pc_rising[group]  &= ~mask;
  pc_falling[group] &= ~mask;
  pc_callback[group][bit] = NULL;
  SREG = oldSREG;
}

// Works out which pin(s) changed in a group and calls their functions
static inline void pc_handle(uint8_t group) {
  uint8_t now     = pc_readPort(group);
  uint8_t changed = now ^ pc_last[group];
  pc_last[group]  = now;

  uint8_t fire = (changed &  now & pc_rising[group]) |
                 (changed & ~now & pc_falling[group]);

  for (uint8_t b = 0; b < 8; b++)
  {
    if ((fire & (1 << b)) && pc_callback[group][b])
      pc_callback[group][b]();
  }
}

ISR(PCINT0_vect) { pc_handle(0); }   // D8  - D13
ISR(PCINT1_vect) { pc_handle(1); }   // A0  - A5   (our BUTTON_S and BUTTON_CHOOSE)
ISR(PCINT2_vect) { pc_handle(2); }   // D0  - D7   (our BUTTON_MS)

#endif