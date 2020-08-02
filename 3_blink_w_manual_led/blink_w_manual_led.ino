
const int LED = 12; //LED connecting to digital pin 12

void setup() {
  pinMode(LED, OUTPUT);

}

void loop() {
  digitalWrite(LED, HIGH); //sends voltage to LED, the LED is now an actuator
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);

}
