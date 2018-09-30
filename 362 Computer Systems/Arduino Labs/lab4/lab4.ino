//Affan Farid UIN: 671455693
//Lab 4 - More complicated input
//A program that displays current light status on an LCD
//Assumptions: Expected Arduino Uno, LCD was functional, Photosensor was functional
//References: Ardumotive.com to set up board as well as introductory base code

#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
#include <string.h> //includes the cstring library
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //defines the ports
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //initializes the lcd screen
const int pResistor = A0; // Photoresistor at Arduino analog pin A0

//Variables
int value;          // Store value from photoresistor (0-1023)

void setup(){
  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input
  //sets up LCD on where to write
  lcd.begin(16,2);
  lcd.setCursor(0,0);

}

void loop(){
  //takes in numerical value and prints out respective light statement
  value = analogRead(pResistor);
  printLightStatus(value);

  delay(500); //Small delay
}

void printLightStatus(int value){
  //function that takes in current value of light and displays a message on the LCD
  lcd.clear();

  if(value>=400){lcd.print("Fully Lit"); return; }
  if(value>=100){lcd.print("Partially Lit"); return; }
  if(value>=30){lcd.print("Medium"); return; }
  if(value>=25){lcd.print("Partially Dark"); return; }
  if(value>=0){lcd.print("Dark"); return; }
    
  
}
