#include <LiquidCrystal.h>
#include <MFRC522.h>
#include <SPI.h>


#define RST_PIN   13  
#define SS_PIN    53 
#define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF}
#define UNACCESS_PIN  6
#define ACCESS_PIN  5

MFRC522 mfrc522(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12 );

void setup() {
  lcd.begin(16, 1);
  Serial.begin(9600); 
  while (!Serial);
  SPI.begin();        
  mfrc522.PCD_Init(); 
  pinMode(UNACCESS_PIN, OUTPUT);
  pinMode(ACCESS_PIN, OUTPUT);
  digitalWrite(UNACCESS_PIN, HIGH);

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }

  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println();

  Serial.println(F("New UID and contents:"));
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  
  delay(2000);

  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial()){
       lcd.print("Access Granted!");
      digitalWrite(ACCESS_PIN, HIGH);
      digitalWrite(UNACCESS_PIN, LOW);

      delay(2000);

      digitalWrite(ACCESS_PIN, LOW);
      digitalWrite(UNACCESS_PIN, HIGH);
      lcd.clear();
    
  }  return;

 
}

