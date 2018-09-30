//Affan Farid UIN: 671455693
//Lab 3 - Scrolling output
//A program that displays a stationary message on the top line and scrolling message on the bottom line of an LCD
//Assumptions: Expected Arduino Uno, LCD was fucntional
//References: Arduino.com tutorial for setting up the board and base code

#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
#include <string.h> //includes the cstring library
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //defines the ports
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //initializes the lcd screen

String s = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";  //intializes the string s
int slength = 36; //gets string length
String name1 = "Affan Farid";

void setup() { 
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height)of the display } 
 lcd.print(name1); //prints name on the top row
 lcd.setCursor(0,1); //sets cursor to bottom row and prints the string
 lcd.print(s);
}
void loop() {

  //loops to 16 for each of the available spaces on the lcd 
  for(int i =0; i<= 16; i++){

    //displays the name each time on the top row
    lcd.setCursor(0,0);
    lcd.print(name1);

    //sets cursor to 2nd row and clears bottom row
    lcd.setCursor(0,1);
    lcd.print("                ");

    //calcutes substring that will fit in the spaces and displays that substring
    lcd.setCursor(0,1);
    String subS = s.substring(slength-16-i, slength-i);
    lcd.print(subS);
    
    delay(1000);
    
  }
}
