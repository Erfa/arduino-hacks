#include <Button.h>

Button button(2
);
bool on;

void setup() {
  button.begin();
  on = false;
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, on ? HIGH : LOW);

  if (button.released()) {
    on = !on;
  }
}
