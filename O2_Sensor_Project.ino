#include <LiquidCrystal.h>
#include <string.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS 1000

//These const ints define the pins that are being used between the arduino and the lcd screen
const int rs = 2,
          en = 3,
          d4 = 6,
          d5 = 7,
          d6 = 8,
          d7 = 9;
  
LiquidCrystal lcd(rs, en, d4, d5 ,d6, d7);
String Hello = "Peace Be Upon You";
String Hate = "Joe Mama, Got 'em";
//The byte below represents one of indices of the lcd screen
/**
byte bot[8] = { 
  0b01110,
  0b01110,
  0b00100,
  0b11111,
  0b00100,
  0b00100,
  0b01010,
  0b10001
};
**/
byte smile[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};
byte mod[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000
};
byte sad[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B01110,
  B10001,
  B00000,
  B00000
};

PulseOximeter pox; //Define the oximeter object
uint32_t tsLastReport = 0;


void onBeatDetected(){
  Serial.println("Beat!!!");
}

void setup() {
  
  Serial.begin(115200); // Generally you want the baud rate for all devices to be the same (parameter of the begin function)
  lcd.begin(16,2); // initializing the grid size of the lcd screens
  lcd.createChar(1,smile);
  lcd.createChar(2, mod);
  lcd.createChar(3, sad);
  lcd.setCursor(0, 0);
  lcd.print("Pulse");
  lcd.setCursor(0, 1);
  lcd.print("Oximeter");
  Serial.println("test");
  delay(2000);

  //if-else statements to check if the initialization worked or not
  if(!pox.begin()){
    Serial.println("FAILED");
    for(;;);
  }
  else{
    Serial.println("SUCCESS");
  }
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  pox.update();
  //if the interval between reports has been too long
  if (millis() - tsLastReport > REPORTING_PERIOD_MS){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BPM : ");
    lcd.print(pox.getHeartRate());
    lcd.setCursor(0, 1);
    lcd.print("SpO2: ");
    lcd.print(pox.getSpO2());
    lcd.print("%");
    tsLastReport = millis();
    //If O2 reading is 96 or above (which is normal)
    if(pox.getSpO2() >= 96){
      lcd.setCursor(15, 1);
      lcd.write(1);
    }
    //If O2 reading is between 91 and 95 (a bit lower than normal)
    else if (pox.getSpO2() <= 95 && pox.getSpO2() >= 91){
      lcd.setCursor(15, 1);
      lcd.write(2);
    }
    //If O2 reading is below 90 (which is bad, should seek medical help/attention)
    else if (pox.getSpO2() <= 90){
      lcd.setCursor(15, 1);
      lcd.write(3);
    }
  }  

  // These 2 for loops scroll the text from the strings defined above from right to left, with the second string being printed on the second line//
  /**
  for (int i = 0; i < Hello.length(); i++){ // This for loop prints out the characters of the string one by one
    lcd.print(Hello.charAt(i));
    delay(200);
  }
  lcd.setCursor(16,1);
  lcd.autoscroll(); //This function by default scrolls the screen from right to left
  for (int i =0; i < Hate.length(); i++){
    lcd.print(Hate.charAt(i));
    delay(400);
  }
  **/
  ////////////////

  
  
  // These 2 for loops allow for the text to scroll either left or right, giving more control of the text scrolling (configured for the first string called Hello)
  /**
  for (int pos = 0; pos < 17; pos++){
    lcd.scrollDisplayLeft();
    delay(250);
  }
  for (int pos = 0; pos < 17; pos++){
    lcd.scrollDisplayRight();
    delay(250);
  }
  **/
  ////////////////


  //This section of the codes uses the byte pixel art defined above to draw the art in each index and then repeatedly draw it on all indices of the lcd screen using the nested for loop
  /**
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  for(int col = 0; col < 2; col++){
    for(int row = 0; row < 16; row++){
      lcd.setCursor(row, col);
      lcd.write(byte(0));
      delay(100);
    }
  }
  **/
  ////////////////


  //Miscellaneous functions
  /**
  lcd.rightToLeft(); This function essentially makes the cursor print words backwards
  lcd.leftToRight(); makes cursor print the words in the default direction
  lcd.home(); positions the cursor in the upper left corner of the lcd display (0,0)
  lcd.blink(); blinks the cursor
  lcd.noDisplay(); turns off the lcd display without removing the text that is currently on the lcd
  lcd.display(); turns the display back on
  **/
  
}
