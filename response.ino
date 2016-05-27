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

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin[5] = {2,3,4,5,6};  // the number of the pushbutton pin
const int ledPin[5] = {13, 9, 10, 11, 12}; // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the Serial port:
  Serial.begin(9600);
  
  for (int i = 0; i < 5; i++) {
    // initialize the LED pin as an output:
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i], LOW);
    
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin[i], INPUT);
    pinMode(buttonPin[i], INPUT_PULLUP);
  }
  
  // initialize the random seed:
  randomSeed(analogRead(0));
}

void loop() {  
  for (int i = 0; i < 10; i++) {
    digitalWrite(ledPin[0], HIGH);
    delay(100);
    digitalWrite(ledPin[0], LOW);
    delay(700);
    digitalWrite(ledPin[0], HIGH);
    delay(100);
    digitalWrite(ledPin[0], LOW);
    delay(700);
    digitalWrite(ledPin[0], HIGH);
    delay(100);
    digitalWrite(ledPin[0], LOW);
    delay(700);
    
    int r = random(1,5);
    Serial.println(r);
    digitalWrite(ledPin[r], HIGH);
    
    unsigned long time1 = millis();    
    int n = 0;
    while (true) {
      if (digitalRead(buttonPin[n]) == LOW) break;
      n++;
      n %= 5;
    }
    digitalWrite(ledPin[r], LOW);
    unsigned long time2 = millis();
    Serial.println(n);
    Serial.println(time2-time1);
    delay(1000);
  }
  while (true);
}

