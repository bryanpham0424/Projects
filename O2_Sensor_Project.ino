#include <LiquidCrystal.h>

const int rs = 2,
          en = 3,
          d4 = 6,
          d5 = 7,
          d6 = 8,
          d7 = 9;
  
LiquidCrystal lcd(rs, en, d4, d5 ,d6, d7);

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
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("SkyZone Sucks");
  delay(2000);
}
