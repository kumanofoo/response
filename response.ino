// set pin numbers:
const int buttonPin[5] = {2,3,4,5,6};  // the number of the pushbutton pin
const int ledPin[5] = {13, 9, 10, 11, 12}; // the number of the LED pin

int waitingTime = 30000;
int serial = 1000;

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
  Serial.print("\npush red button and start test #");
  Serial.println(serial);
  serial++;
  
  int n = 1;
  int cnt = 0;
  while (true) {
    digitalWrite(ledPin[n], HIGH);

    // wait
    for (cnt = 0; cnt < waitingTime; cnt++) {
      if (digitalRead(buttonPin[0]) == LOW) break;
    }
    // confirm if pressed
    if (cnt != waitingTime) {
      digitalWrite(ledPin[n], LOW);
      while (digitalRead(buttonPin[0]) == LOW);
      break;
    }
    
    digitalWrite(ledPin[n], LOW);
    n++;
    if (n == 5) n = 1;
  }

  // start test
  Serial.println("no,question,input,result,time[ms]");
  for (int i = 0; i < 11; i++) {
    Serial.print(i);
    Serial.print(',');
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
    Serial.print(r);
    Serial.print(',');
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
    Serial.print(n);
    Serial.print(',');
    if (n == r) {
      Serial.print('o');
      Serial.print(',');
    }
    else {
      Serial.print('x');
      Serial.print(',');
    }
    Serial.println(time2-time1);
    delay(1000);
  }
}

