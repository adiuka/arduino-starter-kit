int adcId = 0;
int oldValue = 0;
char printBuffer[128];

void setup() {
  Serial.begin(9600);
}

void loop() {
  int currentValue = analogRead(adcId);

  if (((oldValue >= currentValue) && ((oldValue - currentValue) > 10)) || ((oldValue < currentValue) && ((currentValue - oldValue) > 10))) {
    sprintf(printBuffer, "ADC %d level is %d\n", adcId, currentValue);

    Serial.print(printBuffer);
    oldValue = currentValue;
  }
}
