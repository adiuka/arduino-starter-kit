#include "pitches.h"


int melody[] = {
  NOTE_C5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};
int duration = 500;

void setup() {

}

void loop() {
  for (int note = 0; note < 8; note++) {
    tone(8, melody[note], duration);

    delay(1000);
  }

  // restart after 2 seconds
  delay(2000);
}
