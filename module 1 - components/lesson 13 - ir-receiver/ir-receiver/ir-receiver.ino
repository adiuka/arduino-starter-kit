#include "IRremote.h"
#include "IR.h"

IRrecv irrecv(RECEIVER);
decode_results results;

void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
}

void loop() {
  int tempValue;
  if (irrecv.decode(&results)) { // checks if the signal was received
    for (int i = 0; i < 23; i++) {
      if ((keyValue[i] == results.value) && (i < KEY_NUM)) {
        Serial.println(keyBuf[i]);
        tempValue = results.value;
      } else if (REPEAT == i) {
        results.value = tempValue;
      }
    }
    irrecv.resume(); // receive the next value
  }

  /*  
    switch(results.value) { // Can be written with switch statements as well.
      case 0xFFA25D:
        Serial.println("POWER");
        break;
      case 0xFFFFFFFF:
        break;
      default:
        Serial.println("OTHER");
    }
  */
} 

