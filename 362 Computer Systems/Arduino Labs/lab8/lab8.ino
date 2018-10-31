//Affan Farid UIN: 671455693
//Lab 8 - Interrupts
//A program that displays a timer, and then stops it and resets it when 2 buttons are pressed
//Assumptions: Expected Arduino Uno, Potentiometer,LCD, and buttons were all functional
//References: Previous labs for button handling, LCD setup, and Time functionality, Interrupt Arduino Guide

#include <TimeLib.h>
#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#include <stdlib.h>
#include <string.h> //includes the cstring library
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4; //defines the ports
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //initializes the lcd screen

//initialize button yellow and red, as well as the flag
int btnPinR = 2;
int btnPinY = 3;
int flag = 0; 

void setup()  {
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height)of the display } 
  lcd.setCursor(0,0); //sets cursor to bottom row and prints the string
  
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  resetTime(); //sets the time to 0

  //connects button Red to an interrupt for func1, and the yellow button the same for func2
  attachInterrupt(digitalPinToInterrupt(btnPinR), func1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(btnPinY), func2, CHANGE);
}

void func1(){
  //sets the flag to 1 so the counter wont keep going
  //prints how the interrupt is received on the lcd
  flag = 1; 
  lcd.setCursor(0,0);
  lcd.print("IntReceived.Prs2");
  Serial.print("IntReceived.Prs2");
}

void func2(){
  //sets the time to 0, and changes the flag
  resetTime();
  flag = 0;
}

void loop(){

  //only displays the clock counter if the flag is 0
  if(!flag){
    digitalClockDisplay();      
  }
    
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
    //sets the time to 0
    setTime(0,0,0,0,0,0);
}
