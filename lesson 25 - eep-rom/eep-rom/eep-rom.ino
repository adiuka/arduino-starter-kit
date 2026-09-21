#include <EEPROM.h>

void setup() {
  Serial.begin(9600);

  float a = 3.14, a2;
  // EEPROM.put(0, a);          // float uses addresses 0-3
  EEPROM.get(0, a2);
  Serial.print("float data:");
  Serial.println(a2);

  int b = 2000, b2;
  // EEPROM.put(10, b);         
  EEPROM.get(10, b2);
  Serial.print("int data:");
  Serial.println(b2);

  long c = 65539, c2;
  // EEPROM.put(20, c);
  EEPROM.get(20, c2);
  Serial.print("long data:");
  Serial.println(c2);

  char d[50] = __DATE__, d2[50];
  // EEPROM.put(30, d);
  EEPROM.get(30, d2);
  Serial.print("string data: ");
  Serial.println(d2);
}

void loop() {
  // leave empty to avoid overwritting or over deleting
}
