//Affan Farid UIN: 671455693
//Lab 7 - Arduino to Arduino
//A program between 2 arduinos, when one button is pressed, the other LED lights up, and vice versa
//Assumptions: Expected Arduino Uno, LEDs,Buttons were all functional
//References: Arduino Serial Connection, arduino button LED example

int ledPin = 11;
int btnPin = 7;

int ledState = 0; //if LED is on or off
int prevState = 0; //buttons previous state

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); //initializes the LED to output
}

void loop(){

  int curState = digitalRead(btnPin);  // takes in button state
  if(curState != prevState){            // compares if there is a change aka button is pressed and released
    if(curState) Serial.write(1);       // sends the serial signal if it is
    prevState = curState;               // updates the previous state
  }

  if(Serial.available() > 0){           // check if there is actually serial input
    if(Serial.read()){                  // takes in information
      ledState = !ledState;                   // switches state of the LED
      if(ledState)   digitalWrite(ledPin, HIGH); //turns it on or off
      else        digitalWrite(ledPin, LOW);
    }
  }
  delay(1);
}
