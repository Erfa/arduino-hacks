#include <Servo.h>

Servo servo;

const byte potPin = A0;
const byte servoPin = 9;

int pos;

void setup() {
  pinMode(potPin, INPUT);
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  int input = analogRead(potPin);
  //Serial.println(input);
  pos = map(input, 0, 1023, 4, 180);
  Serial.println(pos);
  servo.write(pos);
  delay(15);
}
