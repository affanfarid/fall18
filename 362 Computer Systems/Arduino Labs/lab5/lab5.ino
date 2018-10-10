
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int buzzer = 9; //buzzer to arduino pin 9
const int potPin = A2;
int lightVal;
int potVal = 0;

const int LED1 = 4;
const int LED2 = 5;
const int LED3 = 6;
const int LED4 = 7;

void displayLights(int x){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

  
  if(x < 20){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    return;
  }
  else if ( x < 40){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    return;
  }
  else if( x < 65 ){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  }
  else if( x < 100){
    digitalWrite(LED1, HIGH);
  }
  
}



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

//  digitalWrite(LED1, HIGH);
//  digitalWrite(LED2, HIGH);
//  digitalWrite(LED3, HIGH);
//  digitalWrite(LED4, HIGH);

  
  lightVal = analogRead(pResistor);
  potVal = analogRead(potPin);

  displayLights(lightVal);
  
  Serial.print(lightVal);
  Serial.print("\n");
  tone(buzzer, potVal);
  //tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(500);        // ...for 1 sec
//  noTone(buzzer);     // Stop sound...
//  delay(1000);        // ...for 1sec
  
}
