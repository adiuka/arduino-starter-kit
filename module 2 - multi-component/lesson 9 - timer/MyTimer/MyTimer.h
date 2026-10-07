#ifndef MYTIMER_H
#define MYTIMER_H

#include <Arduino.h>

void time_out();

// Shared with interrupts -> must be volatile
static volatile unsigned long time_button_ms = 0;
static volatile unsigned long time_button_s = 0;
static volatile unsigned long time_button_choose = 0;

static volatile unsigned long last_time_button_ms = 0;
static volatile unsigned long last_time_button_s = 0;
static volatile unsigned long last_time_button_choose = 0;

static volatile uint8_t  flag_begin = 0;   // 1 = counting down
static volatile uint16_t number = 0;       // MMSS, e.g. 130 = 1 min 30 s

const static uint8_t num_buf[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

// Read the 16 bit counter safely (an interrupt could change it mid-read)
static inline uint16_t get_number()
{
  uint8_t oldSREG = SREG;
  cli();
  uint16_t n = number;
  SREG = oldSREG;
  return n;
}

#define BUTTON_S 	  A3
#define BUTTON_MS 	  6
#define BUTTON_CHOOSE A1

#define COM4 5
#define COM3 4
#define COM2 3
#define COM1 2

#define LATCH 9
#define CLOCK 10
#define DATA  8

#define LED    A0
#define BUZZER A2

#endif