void setup() {
  pinMode(A5, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);

  for (int i = 0; i < 1023; i += 10) {
    Serial.print(i);
    Serial.print(" => ");
    Serial.println(func(i));
  }
}

float func(float i) {
  return 257.4 / (0.10 * i + 1.0) - 2.5;
}

void loop() {
  // put your main code here, to run repeatedly:
  int pot = analogRead(A5);

  analogWrite(3, func(pot));
  delay(100);
}
