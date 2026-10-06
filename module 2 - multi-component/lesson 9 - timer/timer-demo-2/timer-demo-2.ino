const int buttonApin = A1;

unsigned long time_buttonApin = 0;
unsigned long last_time_buttonApin = 0;
int i = 0;

volatile bool buttonFlag = false;

ISR(PCINT1_vect) {                      // pin-change interrupt for A0-A5
  if (digitalRead(buttonApin) == LOW) {   // only react to the press
    buttonFlag = true;
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("DEMO 2 booted");

  pinMode(buttonApin, INPUT_PULLUP);
  PCICR  |= (1 << PCIE1);             // enable pin-change interrupts for A0-A5
  PCMSK1 |= (1 << PCINT9);            // A1 only
}

void loop() {
  if (buttonFlag) {
    buttonFlag = false;
    time_buttonApin = millis();
    if (time_buttonApin - last_time_buttonApin > 200) {   // ignore button bounce
      last_time_buttonApin = time_buttonApin;
      Serial.print("buttonApin have been pressed");
      Serial.println("              i:");
      Serial.println(i++);
    }
  }
}