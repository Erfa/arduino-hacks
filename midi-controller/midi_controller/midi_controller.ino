/*
 * This program is designed to run on an ATTiny 2313.
 * 
 * It handles three buttons that are wired to connect their pin to ground when
 * pressed. The IC's built in pull-up resistors are used to prevent the inputs
 * from floating. Sleeping is used to debounce the buttons, for a memory
 * efficient solution (the chip only has 128 bytes of dynamic memory).
 * 
 * Each button is assigned a MIDI CC message that is sent over serial when it is
 * pressed. For more information on the MIDI protocol:
 * https://ccrma.stanford.edu/~craig/articles/linuxmidi/misc/essenmidi.html
 * 
 * Author:  Erik Fahlén
 * Updated: 2021-01-23
 */

/******************************************************************************/

// The MIDI command for sending a CC (continous controller)
const byte MIDI_CC_COMMAND = 0xB0;

// The CC controller numbers to use for the buttons.
// CC 16-19 Are "General Purpose"
const byte CC1 = 16;
const byte CC2 = 17;
const byte CC3 = 18;

const byte VELOCITY = 127;

const int MIDI_BAUD_RATE = 31250;

const byte BUTTON_PIN1 = 4;
const byte BUTTON_PIN2 = 8;
const byte BUTTON_PIN3 = 12;

const byte DEBOUNCE_TIME_MS = 50;

/******************************************************************************/

// A very simple Button class to keep track of a button's state
class Button {
public:
  Button()
    : m_previousState(HIGH)
    , m_currentState(HIGH)
  {
  }

  // Checks the current state of the button. Returns true if the state
  // has changed and debouncing is needed.
  bool update(byte pin) {
    m_previousState = m_currentState;
    m_currentState = digitalRead(pin);

    return m_previousState != m_currentState;
  }

  // Returns true when the button has reached the LOW state
  // right after being in the HIGH state
  bool isPressed() {
    return m_currentState == LOW && m_previousState == HIGH;
  }

private:
  int m_previousState;
  int m_currentState;
};

/******************************************************************************/

// This sends a MIDI command, along with two parameters, through
// the TX pin of the chip.
void sendMidiCommand(byte cmd, byte param1, byte param2) {
  Serial.write(cmd);
  Serial.write(param1);
  Serial.write(param2);
}

/******************************************************************************/

// This project uses three buttons
Button button1;
Button button2;
Button button3;

/******************************************************************************/

// This method is ran at the start of the program to set everything up
void setup() {
  // Start the UART with the baud rate for MIDI
  Serial.begin(MIDI_BAUD_RATE);

  // Configure the pin modes for the three buttons,
  // using the built-in pull-up resistors
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
}

/******************************************************************************/

// This loop keeps running as long as the device is powered
void loop() {
  bool debounce = false;

  // Update the state of the three buttons
  debounce |= button1.update(BUTTON_PIN1);
  debounce |= button2.update(BUTTON_PIN2);
  debounce |= button3.update(BUTTON_PIN3);

  // If any button has been pressed, send the corresponding
  // MIDI command through the TX pin
  if (button1.isPressed()) {
    sendMidiCommand(MIDI_CC_COMMAND, CC1, VELOCITY);
  }
  if (button2.isPressed()) {
    sendMidiCommand(MIDI_CC_COMMAND, CC2, VELOCITY);
  }
  if (button3.isPressed()) {
    sendMidiCommand(MIDI_CC_COMMAND, CC3, VELOCITY);
  }

  // If any of the buttons require us to debounce,
  // simply sleep for a while
  if (debounce) {
    delay(DEBOUNCE_TIME_MS);
  }
}

/******************************************************************************/
