#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dateTime;

void setup() {
  Serial.begin(9600);

  Serial.println("init RTC module");
  clock.begin(); // start the clock module

  // clock.setDateTime(__DATE__, __TIME__); // Sets the RTC clock to my computers clock IMPORTANT: need to comment out after first init
}

void loop() {
  dateTime = clock.getDateTime();

  Serial.print("Raw data: ");
  Serial.print(dateTime.year);    Serial.print("-");
  Serial.print(dateTime.month);   Serial.print("-");
  Serial.print(dateTime.day);     Serial.print(" | ");
  Serial.print(dateTime.hour);    Serial.print(":");
  Serial.print(dateTime.minute);  Serial.print(":");
  Serial.print(dateTime.second);  Serial.println("");;

  delay(1000);
}
