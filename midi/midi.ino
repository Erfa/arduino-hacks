const int NOTE_OFF = 0x80;
const int NOTE_ON = 0x90;


void setup() {
  Serial.begin(31250);
  pinMode(13, OUTPUT);
}

void loop() {
  midiCommand(NOTE_ON, 60, 127);
  digitalWrite(13, HIGH);
  delay(1000);
  midiCommand(NOTE_OFF, 60, 0);
  digitalWrite(13, LOW);
  delay(1000);
}

void midiCommand(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
