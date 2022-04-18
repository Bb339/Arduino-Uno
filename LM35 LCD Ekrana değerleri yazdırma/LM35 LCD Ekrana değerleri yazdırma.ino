#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int lm35 = A5;
int okunanVoltaj;
float sicaklik;
 
void setup(){
 lcd.begin(16, 2);
 // lcd.backlight();
    lcd.print("  Sıcaklık ");
  lcd.setCursor(4, 1);
  lcd.print("olcer");
analogReference(INTERNAL);
Serial.begin(9600);
}
 
void loop(){
    lcd.clear(); 
  okunanVoltaj = analogRead(lm35);
  sicaklik = okunanVoltaj / 9.31; 
  Serial.print("Sıcaklık: ");
   lcd.print("Sıcaklık: ");
   lcd.print(sicaklik);
  Serial.println(sicaklik);
  delay(1000);
}
