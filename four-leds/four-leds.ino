const byte ledPins[4] = {6, 9, 10, 11};

void setup() {
  for (int i = 0; i < 4; ++i) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j <= 255; ++j) {
      analogWrite(ledPins[i], j);
      delay(20);
    }
    delay(250);
  }

  for (int i = 0; i < 4; ++i) {
    for (int j = 255; j >= 0; --j) {
      analogWrite(ledPins[i], j);
      delay(20);
    }
    delay(250);
  }
}
