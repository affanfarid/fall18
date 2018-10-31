//Affan Farid UIN: 671455693
//Lab 6 - Communication
//A program that takes a time/date input and displays it counting up on an LCD
//Assumptions: Expected Arduino Uno, Potentiometer,LCD were all functional
//References: Arduino Example TimeSerial, arduino Time library

#include <TimeLib.h>
#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#include <stdlib.h>
#include <string.h> //includes the cstring library
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4; //defines the ports
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //initializes the lcd screen

int btnPinR = 2;
int prevStateR = 0;

int btnPinY = 3;
int prevStateY = 0;

int flag = 0; 

void setup()  {
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height)of the display } 
  lcd.setCursor(0,0); //sets cursor to bottom row and prints the string
  
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  resetTime();
  attachInterrupt(digitalPinToInterrupt(btnPinR), func1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(btnPinY), func2, CHANGE);
}

void func1(){
  flag = 1; 
  lcd.setCursor(0,0);
  lcd.print("IntReceived.Prs2");
  Serial.print("IntReceived.Prs2");
}

void func2(){
  resetTime();
  flag = 0;
}

void loop(){

  if(!flag){
    digitalClockDisplay();      
  }
//  else{
//    
//  }
  //displays time
    

  delay(1000);
}

void digitalClockDisplay(){
  // digital clock display of the time on LCD
  lcd.clear();
  
  lcd.setCursor(0,1);
  Serial.print(hour()); lcd.print(hour());
  printDigits(minute());
  printDigits(second());
  lcd.setCursor(0,0);
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  lcd.print(":");
  if(digits < 10){
    Serial.print('0');
    lcd.print('0');
  }

  Serial.print(digits);
  lcd.print(digits);
}

void resetTime(){
    setTime(0,0,0,0,0,0);
}
