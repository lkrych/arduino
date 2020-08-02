const int LED = 9;   //the pin for the LED
const int BUTTON = 2; //the input pin where the pushbutton is connected

int val = 0; //val will be used to store the state of the input pin

int old_val = 0; 
int state = 0; // 0 = LED off and 1 = LED on

int brightness = 128; //store the brightness value
int brightening = 1; //1 = brightening, 0 = dimming

unsigned long startTime = 0; // when did we begin pressing?

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON);  //read the input value and store it

  // check if there was a transition
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state; //tricky, think about it 1-1 = 0 && 1-0 = 1

    startTime = millis(); //arduino clock how many milliseconds have passed since the board has been reset
    brightening = 1; //always restart with brightening
    delay(10);  //debouncing
  }

  //check whether the button is being held down
  if ((val == HIGH) && (old_val == HIGH)) {
    if (state == 1 && (millis() - startTime) > 500) {
      if (brightening == 1) {
        brightness++;
        delay(10);
  
        if (brightness > 255) {
          brightening = 0; //start to dim 
        }
      } else {
        brightness--;
        delay(10);
  
        if (brightness <= 0) {
          brightening = 1; //start to brighten 
        }
      }
      
      
    }
  }

  old_val = val;

  if (state == 1) {
    analogWrite(LED, brightness); //turn LED on to the current brightness level  
  } else {
    analogWrite(LED, 0);  
  }
  

}
