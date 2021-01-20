#include <Button.h>

Button button1(4);
Button button2(7);
Button button3(8);

void setup() {
  button1.begin();
  button2.begin();
  button3.begin();
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, LOW);
  if (button1.pressed()) {
    blink(1);
  }
  if (button2.pressed()) {
    blink(2);
  }
  if (button3.pressed()) {
    blink(3);
  }
}

void blink(int n) {
  for (int i = 0; i < n; ++i) {
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(100);
  }
}
