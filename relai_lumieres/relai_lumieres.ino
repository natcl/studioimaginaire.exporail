/* Blink without Delay
 
 Turns on and off a light emitting diode(LED) connected to a digital  
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.
 
 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.
 
 
 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 
 This example code is in the public domain.

 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to 
// set pin numbers:
const int relayPin1 =  7;      // the number of the LED pin
const int relayPin2 =  8;

// Variables will change:
int relayState1 = LOW;  // ledState used to set the LED
int relayState2 = LOW;
long previousMillis1 = 0;        // will store last time LED was updated
long previousMillis2 = 0;

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval1 = random(10000,40000);           // interval at which to blink (milliseconds)
long interval2 = random(10000,40000);

void setup() {
  // set the digital pin as output:
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);    
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the 
  // difference between the current time and last time you blinked 
  // the LED is bigger than the interval at which you want to 
  // blink the LED.
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis1 > interval1) {
    // save the last time you blinked the LED 
    previousMillis1 = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (relayState1 == LOW)
      relayState1 = HIGH;
    else
      relayState1 = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(relayPin1, relayState1);
    interval1 = random(10000,40000);           // interval at which to blink (milliseconds)
  }
  
    if(currentMillis - previousMillis2 > interval2) {
    // save the last time you blinked the LED 
    previousMillis2 = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (relayState2 == LOW)
      relayState2 = HIGH;
    else
      relayState2 = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(relayPin2, relayState2);
    interval2 = random(10000,40000);
  }
}

