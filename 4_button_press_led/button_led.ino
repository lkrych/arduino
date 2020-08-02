const int LED = 12;   //the pin for the LED
const int BUTTON = 7; //the input pin where the pushbutton is connected

int val = 0; //val will be used to store the state of the input pin

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON);  //read the input value and store it

  if (val == HIGH) { //if button pressed
    digitalWrite(LED, HIGH); //turn the led on
  } else {
    digitalWrite(LED, LOW);
  }

}
