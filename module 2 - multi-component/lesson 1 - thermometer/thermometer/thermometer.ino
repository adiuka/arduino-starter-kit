#include <LiquidCrystal.h>

int temperaturePin = 0;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int temperatureReading = analogRead(temperaturePin);

  double logR = log(10000.0 * ((1024.0 / temperatureReading - 1)));
  double temperatureKelvin = 1.0 / (0.001129148 + (0.000234125 + (0.0000000876741 * logR * logR)) * logR);

  float temperatureCelsius = temperatureKelvin - 273.15;
  float temperatureFahrenheit = (temperatureCelsius * 9.0) / 5.0 + 32.0;

  lcd.setCursor(0, 0);
  lcd.print("Temperature C: ");
  lcd.setCursor(0, 1);
  lcd.print(temperatureCelsius);
  delay(500);
}
