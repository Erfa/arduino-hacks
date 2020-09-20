const byte rgbPins[3] = {9, 10, 11};

void setup() {
  for (int i = 0; i < 3; ++i)
    pinMode(rgbPins[i], OUTPUT);
}

void loop() {
  int r = 0;
  int g = 0;
  int b = 0;

  for (g = 0, r = 255; r > 0; ++g, --r) {
    analogWrite(rgbPins[0], r);
    analogWrite(rgbPins[1], g);
    analogWrite(rgbPins[2], b);
    delay(1);
  }

  delay(250);

  for (b = 0, g = 255; g > 0; ++b, --g) {
    analogWrite(rgbPins[0], r);
    analogWrite(rgbPins[1], g);
    analogWrite(rgbPins[2], b);
    delay(1);
  }

  delay(250);

  for (r = 0, b = 255; b > 0; ++r, --b) {
    analogWrite(rgbPins[0], r);
    analogWrite(rgbPins[1], g);
    analogWrite(rgbPins[2], b);
    delay(1);
  }

  delay(250);
}
