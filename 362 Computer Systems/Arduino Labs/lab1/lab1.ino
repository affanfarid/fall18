//Affan Farid UIN: 671455693
//Lab 1 - Get started with Arduino
//A program that flashes LEDs with no 2 LEDs being on at the same time
//Assumptions: Expected Arduino Uno, LEDs were functional
//References: Youtube tutorial on how to get started with arduino, using breadboard

//setting LED numbers to the pin numbers to make it easier
int LED0 = 13;
int LED1 = 12;
int LED2 = 11;

//int LED3 = 10;

//set a global delay value to easily change/edit
int delayvalue = 500;

void setup() {
  //initialize each pin to LED and set them to output
   pinMode(LED0, OUTPUT);
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   //pinMode(LED3, OUTPUT);

}


void loop() {
  //creates a loop where each LED is turned on for a specific delay then turned off before the next one

  digitalWrite(LED0,HIGH);
  delay(delayvalue);
  digitalWrite(LED0,LOW);

  digitalWrite(LED1,HIGH);
  delay(delayvalue);
  digitalWrite(LED1,LOW);

  digitalWrite(LED2,HIGH);
  delay(delayvalue);
  digitalWrite(LED2,LOW);

//  digitalWrite(LED3,HIGH);
//  delay(delayvalue);
//  digitalWrite(LED3,LOW);


}
