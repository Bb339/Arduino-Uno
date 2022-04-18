//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int TrigPin = 9;
const int EchoPin = 8;
int mesafe ;
int sure;

void setup()
{
 // lcd.begin(16, 2);
lcd.begin();
   lcd.setBacklight(HIGH);
  pinMode(TrigPin , OUTPUT);
  pinMode(EchoPin , INPUT);
}

void loop()
{
  lcd.home();
  lcd.print("  xxxx  ");
  digitalWrite(TrigPin , HIGH);
  digitalWrite(TrigPin , LOW);
  sure = pulseIn (EchoPin , HIGH);
  mesafe = (sure / 2) / 28.5;
   lcd.setCursor(0, 1);
  lcd.print("Mesafe= ");
  lcd.print((float)mesafe,1);
  lcd.print(" cm ");
} 
