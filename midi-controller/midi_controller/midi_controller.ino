#include <Button.h>

const int NOTE_OFF = 0x80;
const int NOTE_ON = 0x90;

Button button1(2);
Button button2(4);
Button button3(7);

void setup() {
  button1.begin();
  button2.begin();
  button3.begin();

  Serial.begin(31250);
  pinMode(13, OUTPUT);
}

void loop() {
  if (button1.pressed()) {
    midiCommand(NOTE_ON, 60, 127);
  } else if (button1.released()) {
    midiCommand(NOTE_OFF, 60, 0);
  }
  if (button2.pressed()) {
    midiCommand(NOTE_ON, 62, 127);
  } else if (button2.released()) {
    midiCommand(NOTE_OFF, 62, 0);
  }
  if (button3.pressed()) {
    midiCommand(NOTE_ON, 64, 127);
  } else if (button3.released()) {
    midiCommand(NOTE_OFF, 64, 0);
  }
}

void blink(int n) {
  for (int i = 0; i < n; ++i) {
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
  }
}

void midiCommand(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
