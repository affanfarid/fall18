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
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //defines the ports
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //initializes the lcd screen

int a1[7]; //array of times
int i; //counter variable for loop

void setup()  {
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height)of the display } 
  lcd.setCursor(0,0); //sets cursor to bottom row and prints the string
  
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  setSyncProvider( requestSync);  //set function to call when sync required
  Serial.println("Waiting for sync message");
  lcd.print("Enter Date/Time");
}

void loop(){    
  //takes in message
  if (Serial.available()) {
    processSyncMessage();
  }
  //displays time
  if (timeStatus()!= timeNotSet) {
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
  Serial.print(" "); //lcd.print(" ");
  Serial.print(month()); lcd.print(month());
  Serial.print("/"); lcd.print("/");
  Serial.print(day()); lcd.print(day());
  Serial.print("/"); lcd.print("/");

  Serial.print(year()); lcd.print(year());
  Serial.println();
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


void processSyncMessage() {

//format MM/DD/YYYY HH:MM:SS

  while(Serial.available() > 0){
    //parses input and adds it to a time array a1
    int a = Serial.parseInt();
    a1[i] = a;
    Serial.println(a);
    i++;
    if(i == 6) break;
  }

  bool valid = 1;

  //checks if day/month combo is valid
  if(a1[0] > 12 || a1[0] < 1){
    valid = 0;
  }
  else{
    //checks if specific day is in specific month
    if(a1[0] == 1 || a1[0] == 3 || a1[0] == 5 || a1[0] == 7 || a1[0] == 8 || a1[0] == 10 || a1[0] == 12){
      if(a1[1] > 31 || a1[1] < 1){
        valid = 0;
      }
    }
    if(a1[0] == 4 || a1[0] == 6 || a1[0] == 9 || a1[0] == 11){
      if(a1[1] > 30 || a1[1] < 1){
        valid = 0;
      }
    }
    if(a1[0] == 2 ){
      if(a1[1] > 29 || a1[1] < 1){
        valid = 0;
      }
    }
    
  }

  //check if inputted time is valid
  if(a1[3] > 24 ||  a1[4] > 60 || a1[5] > 60 || a1[3] < 0 || a1[4] < 0 || a1[5] < 0){
    valid = 0;
  }

   //example inputs
  //2/31/1999 23:59:55
  // 
  //   0  / 1 / 2    3  : 4 : 5
  // Month/Day/Year Hour:min:Second

  //if its valid, set the time and count
  if(valid){
    setTime(a1[3],a1[4],a1[5],a1[1],a1[0],a1[2]);
  }
  //otherwise tell user input is invalid
  else{
    lcd.clear();
    Serial.println("invalid input");
    lcd.print("invalid input");
  }
  
}

// the time will be sent later in response to serial mesg
time_t requestSync()
{
  Serial.write(TIME_REQUEST);  
  return 0; 
}
