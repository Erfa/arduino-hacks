void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(2);

  Serial.println(data);
  delay(100);
}
