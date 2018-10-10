//Affan Farid UIN: 671455693
//Lab 5 - Multiple Inputs and outputs
//A program that buzzes a tone based on a potentiometer input, as well as an amount of lights based on photoresistor input
//Assumptions: Expected Arduino Uno, Potentiometer,LEDs, Buzzer, and Photosensor were all functional
//References: Arduino website to help set up buzzer, and LEDs, as well as potentiometer invididually

const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int buzzer = 9; //buzzer to arduino pin 9
const int potPin = A2; //potentiometer at analog pin A2
//intialize lightValue and potentiometerValue
int lightVal;
int potVal = 0;

//LED output pins initialization
const int LED1 = 4;
const int LED2 = 5;
const int LED3 = 6;
const int LED4 = 7;


//function to display lights based on photosensor input amount
void displayLights(int x){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

  
  if(x < 59){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    return;
  }
  else if ( x < 65){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    return;
  }
  else if( x < 80 ){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  }
  else if( x < 150){
    digitalWrite(LED1, HIGH);
  }
  
}


//initializes inputs and outputs
void setup(){
  Serial.begin(9600);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}


void loop(){
  //reads the values of the analog inputs
  lightVal = analogRead(pResistor);
  potVal = analogRead(potPin);

  //displays the amount of lights based on inputs
  displayLights(lightVal);

  Serial.print(potVal);
  //Serial.print(lightVal);
  Serial.print("\n");

  //sounds buzzer tone based on input
  tone(buzzer, potVal);
  //tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(500);        // ...for 1 sec
//  noTone(buzzer);     // Stop sound...

  
}
