/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */
#include <SD.h>
#define BUFSIZ 100
// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  9;      // the number of the LED pin
const int outPin =  7;
const int chipSelect = 4;

// variables will change:
int buttonState = 1;         // variable for reading the pushbutton status
int lastButtonState = 0;

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  
  // initialize the LED pin
  pinMode(ledPin, OUTPUT); 
  pinMode(outPin, OUTPUT);   
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // enable the pullup resistor
  digitalWrite(buttonPin, HIGH);
}

void loop(){
  
  // read the state of the pushbutton value:
  lastButtonState = buttonState;
  if (digitalRead(buttonPin))
    buttonState = 0;
  else
    buttonState = 1;  
  
  record();
  //play();
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);
    digitalWrite(outPin, HIGH);   
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    digitalWrite(outPin, LOW); 
  }
}
  
void record()
{
  String dataString = "";
  
  if (buttonState != lastButtonState)
  {
    dataString += millis();
    dataString += ", ";
    dataString += buttonState;
    dataString += ";";
    
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile) {
      dataFile.println(dataString);
      dataFile.close();
      // print to the serial port too:
      Serial.println(dataString);
    }
    else {
      Serial.println("error opening datalog.txt");
    } 
  }
}

void play()
{
  char clientline[BUFSIZ];
  int index = 0; 
  
  File dataFile = SD.open("datalog.txt", FILE_READ);
   if (dataFile) {
      Serial.println("datalog.txt:");
      
      // read from the file until there's nothing else in it:
      while (dataFile.available())
      {
        char c = dataFile.read();
        // If it isn't a new line, add the character to the buffer
        if (c != '\n' && c != '\r')
        {
          clientline[index] = c;
          index++;
          // are we too big for the buffer? start tossing out data
          //if (index >= BUFSIZ) 
            //index = BUFSIZ -1;
 
          // continue to read more data!
          continue;
        }
        // got a \n or \r new line, which means the string is done
        clientline[index] = 0;
 
        // Print it out for debugging
        Serial.println(clientline);
        char clientline[BUFSIZ];

      }
      // close the file:
      dataFile.close();
    } else {
    	// if the file didn't open, print an error:
      Serial.println("error opening datalog.txt");
    }
}
