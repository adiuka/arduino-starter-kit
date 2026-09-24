#include "LedControl.h"

LedControl ledControl = LedControl(12,10,11,1);

// image switching time
unsigned long delayTime1 = 500;
unsigned long delayTime2 = 50;

void setup() {
  // module wakup from power saving mode
  ledControl.shutdown(0, false);
  ledControl.setIntensity(0, 8);
  ledControl.clearDisplay(0);
}

void displayLetter(byte letter[5]) {
  for (int row = 0; row < 5; row++) {
    ledControl.setRow(0, row, letter[row]);
  }
  delay(delayTime1);
}

void writeArduinoOnMatrix() {
  byte a[5] = {B01111110, B10001000, B10001000, B10001000, B01111110};
  byte r[5] = {B00010000, B00100000, B00100000, B00010000, B00111110};
  byte d[5] = {B11111110, B00010010, B00100010, B00100010, B00011100};
  byte u[5] = {B00111110, B00000100, B00000010, B00000010, B00111100};
  byte i[5] = {B00000000, B00000010, B10111110, B00100010, B00000000};
  byte n[5] = {B00011110, B00100000, B00100000, B00010000, B00111110};
  byte o[5] = {B00011100, B00100010, B00100010, B00100010, B00011100};
  byte blank[5] = {0, 0, 0, 0, 0};

  displayLetter(a);
  displayLetter(r);
  displayLetter(d);
  displayLetter(u);
  displayLetter(i);
  displayLetter(n);
  displayLetter(o);
  displayLetter(blank);
}

void writeRows() {
  for (int row = 0; row < 8; row++) {
    delay(delayTime2);
    ledControl.setRow(0, row, B10100000);
    delay(delayTime2);
    ledControl.setRow(0, row, (byte)0);

    for (int i = 0; i < row; i++) {
      delay(delayTime2);
      ledControl.setRow(0, row, B10100000);
      delay(delayTime2);
      ledControl.setRow(0, row, (byte)0);
    }
  }
}

void writeColumns() {
  for (int col = 0; col < 8; col++) {
    delay(delayTime2);
    ledControl.setColumn(0, col, B10100000);
    delay(delayTime2);
    ledControl.setColumn(0, col, (byte)0);

    for (int i = 0; i < col; i++) {
      delay(delayTime2);
      ledControl.setColumn(0, col, B10100000);
      delay(delayTime2);
      ledControl.setColumn(0, col, (byte)0);
    }
  }
}

void writeSingle() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      delay(delayTime2);
      ledControl.setLed(0, row, col, true);
      delay(delayTime2);

      for (int i = 0; i < col; i++) {
        ledControl.setLed(0, row, col, false);
        delay(delayTime2);
        ledControl.setLed(0, row, col, true);
        delay(delayTime2);
      }
    }
  }

  for (int row = 0; row < 8; row++) {
    ledControl.setRow(0, row, (byte)0);
  }
}

void loop() {
  writeArduinoOnMatrix();
  writeRows();
  writeColumns();
  writeSingle();
}
