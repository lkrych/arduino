/*
 * Simple Serial
 * 
 * Listens for incoming serial byte, adds one to tye byte and sends the result back out serially. 
 * Also blinks the built-in LED every second.
 */

int inByte = 0;                               //variable to hold incoming serial data
long blinkTimer = 0;                          // keeps trakc of howl ong sinc ethe LED was last turne doff

int blinkInterval = 1000;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); //set pin 13 to be an output
  Serial.begin(9600); //configure the serial port for 9600 bps
}

void loop() {
  // if there are any incoming serial bytes available to read
  if (Serial.available() > 0) {
    inByte = Serial.read();   //read the first available byte
    Serial.write(inByte + 1); // add one to it and send the result out
  }

  //meanwhile, keep the LED blinkng
  if (millis() - blinkTimer >= blinkInterval / 2) {
    digitalWrite(LED_BUILTIN, HIGH);  //turn the LED on
  }

  if (millis() - blinkTimer >= blinkInterval) {
    digitalWrite(LED_BUILTIN, LOW); //turn the LED Off
    blinkTimer = millis();          //reset the timer
  }

}
