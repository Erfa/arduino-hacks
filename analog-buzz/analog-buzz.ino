#include "notes.h"

#define HALF_NOTE (1.0/2.0)
#define QUARTER_NOTE (1.0/4.0)
#define EIGHT_NOTE (1.0/8.0)

int buzzPin = 3;

struct Note {
  bool pause;
  int pitch;
  float duration;
};

Note note(int pitch, float duration) {
  return { false, pitch, duration };
}

Note pause(float duration) {
  return { true, 0, duration };
}

void playMelody(float beatsPerMinute, int n, Note notes[]) {
  float msPerWholeNote = 4 * 60000.0 / beatsPerMinute;
  Serial.print("msPerWholeNote: ");
  Serial.println(msPerWholeNote);
  
  for (int i = 0; i < n; ++i) {
    Serial.print("notes[i].duration: ");
    Serial.println(notes[i].duration);
    float ms = msPerWholeNote * notes[i].duration;
    Serial.print("ms: ");
    Serial.println(ms);

    if (!notes[i].pause)
      tone(buzzPin, notes[i].pitch, ms);

     delay(ms);
  }
}

const Note test[] = {
  note(NOTE_C3, EIGHT_NOTE),
  note(NOTE_D3, EIGHT_NOTE),
  note(NOTE_E3, EIGHT_NOTE),
  note(NOTE_D3, EIGHT_NOTE),
  note(NOTE_C3, HALF_NOTE)
};
const int testLength = sizeof(test) / sizeof(Note);

const Note meow[] = {
  note(NOTE_C3, QUARTER_NOTE),
  pause(EIGHT_NOTE),

  note(NOTE_C3, EIGHT_NOTE),
  note(NOTE_DS3, QUARTER_NOTE),
  pause(EIGHT_NOTE),

  note(NOTE_DS3, EIGHT_NOTE),
  note(NOTE_F3, QUARTER_NOTE),
  pause(EIGHT_NOTE),

  note(NOTE_G3, EIGHT_NOTE),
  pause(EIGHT_NOTE),
  note(NOTE_G3, EIGHT_NOTE),
  pause(EIGHT_NOTE),
  note(NOTE_G3, EIGHT_NOTE),

  note(NOTE_C3, QUARTER_NOTE),
  pause(EIGHT_NOTE),

  note(NOTE_C3, EIGHT_NOTE),
  note(NOTE_DS3, QUARTER_NOTE),
  pause(EIGHT_NOTE),

  note(NOTE_DS3, EIGHT_NOTE),
  note(NOTE_F3, QUARTER_NOTE),
  pause(EIGHT_NOTE),

  note(NOTE_AS2, EIGHT_NOTE),
  pause(EIGHT_NOTE),
  note(NOTE_AS2, EIGHT_NOTE),
  pause(EIGHT_NOTE),
  note(NOTE_B2, EIGHT_NOTE),
};
const int meowLength = sizeof(meow) / sizeof(Note);

void setup() {
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);

  Serial.print("QUARTER_NOTE");
  Serial.println(QUARTER_NOTE);
}

void loop() {
  playMelody(200, meowLength, meow);
}
