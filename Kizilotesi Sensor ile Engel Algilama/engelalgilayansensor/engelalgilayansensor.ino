#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.print("   KIZILOTESI ");
  lcd.setCursor(4, 1);
  lcd.print(" SENSOR ");
  delay(1000);
  pinMode(7,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  
//Serial.print("ENGEL =  ");
//Serial.println(digitalRead(7));
   delay(500);
if(digitalRead(7)==0)
{
  digitalWrite(13,HIGH);
  Serial.println("ENGEL = VAR");
   delay(500);
    lcd.clear(); 
    lcd.print("  ENGEL = VAR");
 
  }
 else{
    digitalWrite(13,LOW);
    Serial.println("ENGEL = YOK");
     lcd.clear(); 
    lcd.print("  ENGEL = YOK");
    delay(500);
    }

}
