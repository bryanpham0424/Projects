#include <LiquidCrystal.h>
#include <string.h>

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

void setup() {
  /*
  // put your setup code here, to run once:
  const int rs = 2,
            en = 3,
            d4 = 6,
            d5 = 7,
            d6 = 8,
            d7 = 9;
  
  LiquidCrystal lcd(rs, en, d4, d5 ,d6, d7);
  */
  Serial.begin(9600); // Generally you want the baud rate for all devices to be the same (parameter of the begin function)
  lcd.begin(16,2); // initializing the grid size of the lcd screens
  lcd.createChar(0,bot);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.blink();
  lcd.setCursor(0,0);

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
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  for(int col = 0; col < 2; col++){
    for(int row = 0; row < 16; row++){
      lcd.setCursor(row, col);
      lcd.write(byte(0));
      delay(100);
    }
  }
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
  lcd.noAutoscroll();
  lcd.noBlink();
  delay(3000);
  lcd.clear();
}
