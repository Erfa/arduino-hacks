const byte MIDI_CC_COMMAND = 0xB0;

// CC 16-19 Are "General Purpose"
const byte CC1 = 16;
const byte CC2 = 17;
const byte CC3 = 18;

const byte VELOCITY = 127;

const int BAUD_RATE = 31250;

const byte BUTTON_PIN1 = 2;
const byte BUTTON_PIN2 = 4;
const byte BUTTON_PIN3 = 6;

const byte DEBOUNCE = 50;

class Button {
public:
  Button()
    : m_previousState(HIGH)
    , m_currentState(HIGH)
  {
  }

  void begin(byte pin) {
    pinMode(pin, INPUT_PULLUP);
  }

  void update(byte pin) {
    m_previousState = m_currentState;
    m_currentState = digitalRead(pin);

    if (m_previousState != m_currentState) {
      delay(DEBOUNCE);
    }
  }

  bool isPressed() {
    return m_currentState == LOW && m_previousState == HIGH;
  }

private:
  int m_previousState;
  int m_currentState;
};

Button button1;
Button button2;
Button button3;

void setup() {
  Serial.begin(BAUD_RATE);

  button1.begin(BUTTON_PIN1);
  button2.begin(BUTTON_PIN2);
  button3.begin(BUTTON_PIN3);
}

void loop() {
  button1.update(BUTTON_PIN1);
  button2.update(BUTTON_PIN2);
  button3.update(BUTTON_PIN3);

  if (button1.isPressed()) {
    midiCommand(MIDI_CC_COMMAND, CC1, VELOCITY);
  }
  if (button2.isPressed()) {
    midiCommand(MIDI_CC_COMMAND, CC2, VELOCITY);
  }
  if (button3.isPressed()) {
    midiCommand(MIDI_CC_COMMAND, CC3, VELOCITY);
  }
}

void midiCommand(int cmd, int param1, int param2) {
  Serial.write(cmd);
  Serial.write(param1);
  Serial.write(param2);
}
