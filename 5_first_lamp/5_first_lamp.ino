const int LED = 12;   //the pin for the LED
const int BUTTON = 7; //the input pin where the pushbutton is connected

int val = 0; //val will be used to store the state of the input pin

int old_val = 0; 
int state = 0; // 0 = LED off and 1 = LED on

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON);  //read the input value and store it

  // check if there was a transition
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state; //tricky, think about it 1-1 = 0 && 1-0 = 1
    delay(10);  //debouncing
  }

  old_val = val; //val is now old, let's store it

  if (state == 1) { //if button pressed
    digitalWrite(LED, HIGH); //turn the led on
  } else {
    digitalWrite(LED, LOW);
  }

}
