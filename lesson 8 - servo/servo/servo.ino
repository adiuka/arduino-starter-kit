#include <Servo.h>

// Create class with Servo to access methods of the class
Servo servo1;

void setup() {
  servo1.attach(9); // Connecting servo to pin 9
  servo1.write(90); // Servo moves to center position
}

void loop() {
  servo1.write(90);
  delay(1000);
  servo1.write(60);
  delay(1000);
  servo1.write(90);
  delay(1000);
  servo1.write(150);
  delay(1000);
}
