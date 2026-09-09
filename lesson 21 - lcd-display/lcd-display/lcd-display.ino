#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2); // set lcd number of rows and cols
  lcd.print("I love my pupa!");
}

void loop() {
  lcd.setCursor(0, 1); // sets cursor to second line
  lcd.print(millis() / 1000); // print number of seconds sonce reset
}
