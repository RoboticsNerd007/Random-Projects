#include <LiquidCrystal.h>

#define buttonPIN_A 2 //count by 1000
#define buttonPIN_B 3 //count by 100
#define buttonPIN_C 4 //count by 10
#define buttonPIN_D 5 //count by 1
#define buttonPIN_E 13 //Secret TEXT!!!

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
lcd.begin(16 , 1);
lcd.print("Duel!!");
  pinMode(buttonPIN_A, INPUT_PULLUP);
  pinMode(buttonPIN_B, INPUT_PULLUP);
  pinMode(buttonPIN_C, INPUT_PULLUP);
  pinMode(buttonPIN_D, INPUT_PULLUP);
  pinMode(buttonPIN_E, INPUT_PULLUP);
}

void loop() {
 lcd.setCursor(0, 1);
  if (digitalRead(buttonPIN_A) == LOW) {
      lcd.write("LP: 4000");
} else if (digitalRead(buttonPIN_B) == LOW) {
      lcd.write("LP: 3000");
} else if (digitalRead(buttonPIN_C) == LOW){
      lcd.write("LP: 2000");
} else if (digitalRead(buttonPIN_D) == LOW){
      lcd.write("LP: 1000");
} else if (digitalRead(buttonPIN_E) == LOW){
      lcd.write("I Activate!!!");
}
}
