#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
 
const int buzzerPin = 13;
const int ledPinR = 12;
const int ledPinG = 11;
const int ldrPin = A0;

void setup () {

  Serial.begin(9600);
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  lcd.begin(16,2);
  lcd.backlight();
  
}

void loop() {

 
  int ldrStatus = analogRead(ldrPin);  //read the state of the LDR value
  lcd.setCursor(0,0);
  lcd.print("*ALARM SECURITY*");
  
  if (ldrStatus >= 400) {
    
    noTone(buzzerPin);
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinG, HIGH);

    lcd.setCursor(0,1);
    lcd.print(" Stop");
    
    
  }
  else {
    
    tone(buzzerPin, 100);
    digitalWrite(ledPinR, HIGH);
    digitalWrite(ledPinG, LOW);
    delay(100);

    noTone(buzzerPin);
    digitalWrite(ledPinR, LOW);
    delay(100);

    lcd.setCursor(0,1);
    lcd.print(" Move");
    
   
  
  }
}
