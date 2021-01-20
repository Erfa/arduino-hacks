#include <Button.h>

const int NOTE_OFF = 0x80;
const int NOTE_ON = 0x90;
const int CC = 0xB0;

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
  // CC 16-19 Are "General Purpose"

  if (button1.pressed()) {
    midiCommand(CC, 16, 127);
  }
  if (button2.pressed()) {
    midiCommand(CC, 17, 127);
  }
  if (button3.pressed()) {
    midiCommand(CC, 18, 127);
  }
}

void midiCommand(int cmd, int param1, int param2) {
  Serial.write(cmd);
  Serial.write(param1);
  Serial.write(param2);
}
