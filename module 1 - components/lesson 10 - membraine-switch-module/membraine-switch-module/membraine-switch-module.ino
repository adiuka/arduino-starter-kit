#include <Keypad.h>

const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns

// 2d buttons array
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //Row pinouts
byte colPins[COLS] = {5, 4, 3, 2}; // Column pinouts

// Keyboard class init
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Start the Serial Screen
  Serial.begin(9600);
}

void loop() {
  char customKey = myKeypad.getKey();

  if (customKey) {
    Serial.println(customKey);
  }
}
