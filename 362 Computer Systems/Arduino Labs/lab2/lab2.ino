//Affan Farid UIN: 671455693
//Lab 2 - Input and Output
//A program that flashes LEDs with no 2 LEDs being on at the same time
//Assumptions: Expected Arduino Uno, LEDs were functional, buttons/switches
//References: prelab 2, tutorial on inputs on outputs to see how to communicate with I/O

//define pins to LEDs and buttons
int led2 = 12;
int led1 = 11;
int led0 = 10;

int buttonDPin = 3;
int buttonIPin = 2;

//declares the states and previous states to control repeated input on a butotn press

int buttonIState = 0;
int buttonDState = 0;

int iStateprev;
int dStateprev;

int i = 0;


void setup() {
  //declares pins to LEDS
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(buttonDPin, INPUT);
  pinMode(buttonIPin, INPUT);

  //allows printing to console
  Serial.begin(9600);

}

void loop() {

  //takes in inital output
  buttonIState = digitalRead(buttonIPin);
  buttonDState = digitalRead(buttonDPin);

  //delay waits for no repeated input
  delay (20);

  //takes in new input to sense if button was pressed or just held
  int btnI = digitalRead(buttonIPin);
  int btnD = digitalRead(buttonDPin);

  

    //checks if button was actually pressed and released
    if( ( (iStateprev == buttonIState) && (btnI != buttonIState) )  || ( (dStateprev == buttonDState) && (btnD != buttonDState) )   ){
        
        //converts the number to binary using signal functions
        signal( led2, ((i >> 2) % 2) == 1);
        signal( led1, ((i >> 1) % 2) == 1);
        signal( led0, ((i >> 0) % 2) == 1); 

      //reads current state of button
       buttonIState = digitalRead(buttonIPin);
       buttonDState = digitalRead(buttonDPin);

       //increments if red button is pressed
       if(buttonIState == HIGH){
          i++;
          Serial.print("RED IS PRESSED \n");
       }

      //decrements if yellow button is pressed
       if(buttonDState == HIGH){
          i--;
          Serial.print("YELLOW IS PRESSED \n");
       }
   }

  //saves previous state
  iStateprev = buttonIState;
  dStateprev = buttonDState;

}

//takes in led port and a boolean, if its true, it lights it up, if not, it turns it off
void signal(int led, bool on) {
  if(on) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
